#include "jl_cv.h"

void jl_cv_disp_gray_(jl_cv_t* jl_cv);

void jl_cv_draw_circle(jl_cv_t* jl_cv, jl_rect_t circle) {
	cvCircle(jl_cv->image_hsv,
		cvPoint(cvRound(circle.x), cvRound(circle.y)),
		cvRound(circle.w), CV_RGB(0x00,0xFF,0x00), 1, 8, 0);
}
