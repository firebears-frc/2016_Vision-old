#include "jl_cv.h"

void jl_cv_getoutput(jl_cv_t* jl_cv);
void jl_cv_disp_gray_(jl_cv_t* jl_cv);

void jl_cv_draw_circle(jl_cv_t* jl_cv, jl_rect_t circle) {
	jl_cv_getoutput(jl_cv);
	cvCircle(jl_cv->disp_image,
		cvPoint(cvRound(circle.x), cvRound(circle.y)),
		cvRound(circle.w), CV_RGB(0x00,0xFF,0x00), 1, 8, 0);
	jl_cv_disp_gray_(jl_cv);
}

void jl_cv_draw_line(jl_cv_t* jl_cv, jl_cv_line_t line) {
	jl_cv_getoutput(jl_cv);
	cvLine(jl_cv->disp_image, line.p1, line.p2, CV_RGB(0xFF,0x00,0xFF),
		1, 8, 0);
	jl_cv_disp_gray_(jl_cv);
}
