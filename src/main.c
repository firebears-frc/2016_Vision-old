#include "header/main.h"

int oldtbiu = 0;

void memtesterer(jl_t* jlc, str_t name) {
	int diff = jl_me_tbiu() - oldtbiu;
	printf("%s %d\n", name, diff);
	oldtbiu = jl_me_tbiu();
}

static void ex_redraw(jl_t* jlc) {
	ctx_t* ctx = jlc->uctx;

	jl_gr_draw_vo(jlc, &(ctx->vos[0]), NULL);
	jl_gr_draw_int(jlc, ctx->circle.x,
		(jl_vec3_t) { 0., 0., 0. },
		(jl_font_t) { 0, JL_IMGI_ICON, 0, jlc->fontcolor, .0625f });
	jl_gr_draw_int(jlc, ctx->circle.y,
		(jl_vec3_t) { .5, 0., 0. },
		(jl_font_t) { 0, JL_IMGI_ICON, 0, jlc->fontcolor, .0625f });
}

void ex_down(jl_t* jlc) {
	if(jlc->ctrl.h == 1) jl_gr_togglemenubar(jlc);
}

void ex_loop(jl_t* jlc) {
	ctx_t* ctx = jlc->uctx;
	double ar;
	int i;
	jl_rect_t circles[10];

	memtesterer(jlc, "run loop");
	jl_ct_run_event(jlc,
		JL_CT_ALLP(JL_CT_GAME_STRT, JL_CT_COMP_MENU, JL_CT_ANDR_MENU),
		ex_down, jl_dont);
	memtesterer(jlc, "run ev");
	jl_cv_loop_webcam(ctx->jl_cv);
	memtesterer(jlc, "run cam");
	ctx->circle.x = jl_cv_loop_detect_circle(ctx->jl_cv, 10, circles);
	for(i = 0; i < ctx->circle.x; i++) {
		jl_cv_draw_circle(ctx->jl_cv, circles[i]);
	}
//	jl_cv_loop_filter(ctx->jl_cv, (uint8_t[]) {0, 100, 100, 100, 255, 255});
	memtesterer(jlc, "run filter");
	ar = jl_cv_loop_maketx(ctx->jl_cv);
	memtesterer(jlc, "run mktex");
	jl_gr_vos_image(jlc, &(ctx->vos[0]),
		(jl_rect_t) { 0.f, 0.f, 1.f, ar }, 1, 0, 0, 255);
	memtesterer(jlc, "vos image");
}

void ex_wdns(jl_t* jlc) {
	ex_loop(jlc);
	ex_redraw(jlc);
}

// Called when window is made/resized.
static void ex_resz(jl_t* jlc) {
	ctx_t* ctx = jlc->uctx;
	jl_rect_t rc1 = { 0.f, 0.f, 1.f, jl_gl_ar(jlc) };
	u8_t colors[] = { 255, 85, 0, 127 };

//	jl_gr_vos_image(jlc, &(ctx->vos[0]), rc1, 1, 0, 0, 255);
	jl_gr_vos_rec(jlc, &(ctx->vos[1]), rc1, colors, 0);
}

static void ex_exit(jl_t* jlc) {
	ctx_t* ctx = jlc->uctx;

	jl_cv_kill(ctx->jl_cv);
	jl_sg_exit(jlc);
}

static inline void ex_init_modes(jl_t* jlc) {
	//Set mode data
	jl_sg_mode_set(jlc,EX_MODE_EDIT, JL_SG_WM_DN, ex_wdns);
	jl_sg_mode_set(jlc,EX_MODE_EDIT, JL_SG_WM_UP, jl_dont);
	jl_sg_mode_set(jlc,EX_MODE_EDIT, JL_SG_WM_RESZ, ex_resz);
	jl_sg_mode_set(jlc,EX_MODE_EDIT, JL_SG_WM_EXIT, ex_exit);
	jl_sg_mode_switch(jlc, EX_MODE_EDIT, JL_SG_WM_DN); //Leave terminal mode
}

static inline void ex_init_tasks(jl_t* jlc) {
	jl_gr_addicon_slow(jlc);
}

static inline void ex_init_ctx(jl_t* jlc) {
	jlc->uctx = NULL;
	jl_me_alloc(jlc, &jlc->uctx, sizeof(ctx_t), 0);
	ctx_t* ctx = jlc->uctx;
	ctx->jl_cv = jl_cv_init(jlc);
}

static inline void ex_init_vos(jl_t* jlc) {
	ctx_t* ctx = jlc->uctx;

	ctx->vos = jl_gl_vo_make(jlc, 2);
}

static inline void ex_init_cv(jl_t* jlc) {
	ctx_t* ctx = jlc->uctx;

	jl_cv_init_webcam(ctx->jl_cv);
}

void hack_user_init(jl_t* jlc) {
	jl_io_tag_set(jlc, 0, 1, NULL);
	jl_io_offset(jlc, 0, "EXMP");
	jl_gr_draw_msge(jlc, "Initializing", 0, JL_IMGI_ICON, 1);
	jl_io_printc(jlc,"Initializing....\n");
	ex_init_modes(jlc);
	ex_init_tasks(jlc);
	ex_init_ctx(jlc);
	ex_init_vos(jlc);
	ex_init_cv(jlc);
	jl_io_close_block(jlc);
}
