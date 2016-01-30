#include "jl_cv.h"

/* Static Functions */

static void jl_cv_img_crop(jl_cv_t* jl_cv, IplImage* image_to_disp) {
	cvSetImageROI(image_to_disp, cvRect(0, 0, image_to_disp->height,
		image_to_disp->height));
	jl_cv->disp_image = cvCreateImage(cvGetSize(image_to_disp),
		image_to_disp->depth,
		image_to_disp->nChannels);
	cvCopy(image_to_disp, jl_cv->disp_image, NULL);
	cvResetImageROI(image_to_disp);
}

static void jl_cv_webcam_get__(jl_cv_t* jl_cv) {
	jl_cv->image = cvQueryFrame(jl_cv->camera);
	cvResize(jl_cv->image, jl_cv->image, CV_INTER_LINEAR);
	if( jl_cv->image == NULL ) {
		fprintf(stderr, "couldn't retrieve frame\n" );
		exit(1);
	}
}

static void jl_cv_hsv_init__(jl_cv_t* jl_cv) {
	jl_cv->image_hsv=cvCreateImage(cvGetSize(jl_cv->image),8,3);
	jl_cv->gray_image=cvCreateImage(cvGetSize(jl_cv->image),8,1);
}

static void jl_cv_conv__(jl_cv_t* jl_cv) {
	cvCvtColor(jl_cv->image, jl_cv->image_hsv, CV_RGBA2BGR);
	cvCvtColor(jl_cv->image, jl_cv->gray_image, CV_RGBA2GRAY);
}

void jl_cv_disp_gray_(jl_cv_t* jl_cv) {
	cvCvtColor(jl_cv->gray_image, jl_cv->image_hsv, CV_GRAY2BGR );
}

static void jl_cv_hsv_filter__(jl_cv_t* jl_cv, u8_t* hsv) {
	cvInRangeS(jl_cv->image_hsv, cvScalar(hsv[0], hsv[1], hsv[2], 255),
		cvScalar(hsv[3], hsv[4], hsv[5], 255), jl_cv->gray_image);
	jl_cv_disp_gray_(jl_cv);
}

/* Export Functions */

jl_cv_t* jl_cv_init(jl_t* jlc) {
	jl_cv_t* jl_cv = NULL;
	jl_me_alloc(jlc, (void**)&jl_cv, sizeof(jl_cv_t), 0);
	jl_cv->jlc = jlc;
	return jl_cv;
}

void jl_cv_kill(jl_cv_t* jl_cv) {
	cvReleaseCapture(&(jl_cv->camera));
}

void jl_cv_init_webcam(jl_cv_t* jl_cv) {
	jl_cv->camera = cvCaptureFromCAM(0); // open the default camera id == 0
	// If webcam can't be opened, then fail
	if( jl_cv->camera == NULL ) {
		fprintf(stderr, " Failed to open a Camera\n" );
		exit(1);
	}
	jl_cv_webcam_get__(jl_cv);
	jl_cv_hsv_init__(jl_cv);
}

void jl_cv_loop_webcam(jl_cv_t* jl_cv) {
	// Retrieve the image from camera ID:0 then store in CamImage
	jl_cv_webcam_get__(jl_cv);
}

void jl_cv_loop_filter(jl_cv_t* jl_cv, u8_t* hsv) {
	jl_cv_conv__(jl_cv);
	jl_cv_hsv_filter__(jl_cv, hsv);
}

/**
 * Detect circles.
 * @param jl_cv: JL_CV context.
 * @param max_rtn: The number of jl_rect_t's in the array. jl_rect_t circles['x'];
 * @param rtn_circles: The rectangle array that is where the circles are output.
 * @returns number of circles
**/
u32_t jl_cv_loop_detect_circle(jl_cv_t* jl_cv, u32_t max_rtn,
	jl_rect_t* rtn_circles)
{
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* circles;
	int i, count;

	jl_cv_conv__(jl_cv);
	cvSmooth(jl_cv->gray_image, jl_cv->gray_image, CV_GAUSSIAN, 15,15,0,0);
	circles = cvHoughCircles(
		jl_cv->gray_image,		// The image
		storage,			// Output of found circles
		CV_HOUGH_GRADIENT,		// Only option
		4,				// image:accumulator resolution
		jl_cv->gray_image->width/4,	// Min. dist. between circles
		200,				// 2nd threshold in canny()
		100,				// Smaller for more(bad)circles.
		0,				// Minimum circle radius
		jl_cv->gray_image->height/4	// Maximum circle radius
	);
	count = circles->total >= max_rtn ? max_rtn : circles->total;
	for(i = 0; i < count; i++){
		float* p = (float*)cvGetSeqElem(circles, i);
		rtn_circles[i] = (jl_rect_t){ p[0], p[1], p[2], p[2] };
	}
	jl_cv_disp_gray_(jl_cv);
	return count;
}

/**
 * Detect lines.
 * @param jl_cv: JL_CV context.
 * @param filter_out: The higher this number, the less lines are outputed.
 * @param minlen: The minimum length the outputed lines may be.
 * @returns number of lines.
**/
u32_t jl_cv_loop_detect_lines(jl_cv_t* jl_cv, i32_t filter_out, u32_t minlen, jl_line_t* rtn_lines) {
	CvMemStorage* line_storage = cvCreateMemStorage(0);
	CvSeq* lines;
	int i, count;

	jl_cv_conv__(jl_cv);
	lines = cvHoughLines2(
		jl_cv->gray_image,	// The image
		line_storage,		// Output of found line segments
		CV_HOUGH_PROBABILISTIC, // Find line segments, not lines
		10.,			// Distance resolution (in pixels)
		.00001,			// Angle resolution (in radians)
		filter_out,		// Accumulator threshold parameter
		minlen,			// Minimum line length
		.005,			// Max gap between line seg.s to join.
		0, CV_PI		// Default Range in C++
	);
	count = lines->total;
	jl_cv_disp_gray_(jl_cv);
	return count;
}

/**
 * Make a texture from the image in the opencv buffer.
 * @param jl_cv: JL_CV context.
 * @returns: The y aspect ratio of the image ( y / x).
**/
double jl_cv_loop_maketx(jl_cv_t* jl_cv) {
	jl_cv_img_crop(jl_cv, jl_cv->image_hsv);
	// Displays the image in the specified window name
	jl_gl_maketexture(jl_cv->jlc, 1, 0,
		jl_cv->disp_image->imageData, jl_cv->disp_image->width,
		jl_cv->disp_image->height, 3);
	return ((double)jl_cv->disp_image->height) / ((double)jl_cv->disp_image->width);
}
