#include "cv.h"
#include "highgui.h"
#include "jl.h"

typedef struct{
	jl_t* jlc;
	CvCapture* camera;
	IplImage* image;
	IplImage* image_hsv;
	IplImage* gray_image;
	IplImage* disp_image;
}jl_cv_t;

// Make & Destroy
jl_cv_t* jl_cv_init(jl_t* jlc);
void jl_cv_kill(jl_cv_t* jl_cv);
// Use the webcam
void jl_cv_init_webcam(jl_cv_t* jl_cv);
void jl_cv_loop_webcam(jl_cv_t* jl_cv);
// Apply Filters
void jl_cv_loop_filter(jl_cv_t* jl_cv, u8_t* hsv);
u32_t jl_cv_loop_detect_circle(jl_cv_t* jl_cv, u32_t max,
	jl_rect_t* rtn_circles);
// Export Ending Image to texture.
double jl_cv_loop_maketx(jl_cv_t* jl_cv);

// - draw -

void jl_cv_draw_circle(jl_cv_t* jl_cv, jl_rect_t circle);
