/* Include files */

#include "step2_compression_simulation_sfun.h"
#include "c2_step2_compression_simulation.h"
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c2_emlrtMCI = { 87, /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c2_b_emlrtMCI = { 53,/* lineNo */
  15,                                  /* colNo */
  "bsxfun",                            /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"/* pName */
};

static emlrtMCInfo c2_c_emlrtMCI = { 28,/* lineNo */
  19,                                  /* colNo */
  "sub2ind",                           /* fName */
  "E:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtMCInfo c2_d_emlrtMCI = { 48,/* lineNo */
  15,                                  /* colNo */
  "mean",                              /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"/* pName */
};

static emlrtMCInfo c2_e_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "E:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtRSInfo c2_emlrtRSI = { 53, /* lineNo */
  "H.264 Simulator",                   /* fcnName */
  "#step2_compression_simulation:16"   /* pathName */
};

static emlrtRSInfo c2_b_emlrtRSI = { 61,/* lineNo */
  "H.264 Simulator",                   /* fcnName */
  "#step2_compression_simulation:16"   /* pathName */
};

static emlrtRSInfo c2_c_emlrtRSI = { 72,/* lineNo */
  "H.264 Simulator",                   /* fcnName */
  "#step2_compression_simulation:16"   /* pathName */
};

static emlrtRSInfo c2_d_emlrtRSI = { 79,/* lineNo */
  "H.264 Simulator",                   /* fcnName */
  "#step2_compression_simulation:16"   /* pathName */
};

static emlrtRSInfo c2_e_emlrtRSI = { 80,/* lineNo */
  "H.264 Simulator",                   /* fcnName */
  "#step2_compression_simulation:16"   /* pathName */
};

static emlrtRSInfo c2_f_emlrtRSI = { 375,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_g_emlrtRSI = { 378,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_h_emlrtRSI = { 382,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_i_emlrtRSI = { 385,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_j_emlrtRSI = { 388,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_k_emlrtRSI = { 391,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_l_emlrtRSI = { 395,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_m_emlrtRSI = { 398,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_n_emlrtRSI = { 535,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_o_emlrtRSI = { 538,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_p_emlrtRSI = { 579,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_q_emlrtRSI = { 16,/* lineNo */
  "any",                               /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\any.m"/* pathName */
};

static emlrtRSInfo c2_r_emlrtRSI = { 143,/* lineNo */
  "allOrAny",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pathName */
};

static emlrtRSInfo c2_s_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c2_t_emlrtRSI = { 439,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_u_emlrtRSI = { 457,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_v_emlrtRSI = { 16,/* lineNo */
  "sub2ind",                           /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c2_w_emlrtRSI = { 470,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_x_emlrtRSI = { 479,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_y_emlrtRSI = { 102,/* lineNo */
  "fspecial",                          /* fcnName */
  "E:\\matlab\\toolbox\\images\\images\\eml\\fspecial.m"/* pathName */
};

static emlrtRSInfo c2_ab_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c2_bb_emlrtRSI = { 115,/* lineNo */
  "imfilter",                          /* fcnName */
  "E:\\matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c2_cb_emlrtRSI = { 127,/* lineNo */
  "imfilter",                          /* fcnName */
  "E:\\matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c2_db_emlrtRSI = { 814,/* lineNo */
  "imfilter",                          /* fcnName */
  "E:\\matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c2_eb_emlrtRSI = { 888,/* lineNo */
  "imfilter",                          /* fcnName */
  "E:\\matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c2_fb_emlrtRSI = { 962,/* lineNo */
  "imfilter",                          /* fcnName */
  "E:\\matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c2_gb_emlrtRSI = { 990,/* lineNo */
  "imfilter",                          /* fcnName */
  "E:\\matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c2_hb_emlrtRSI = { 1002,/* lineNo */
  "imfilter",                          /* fcnName */
  "E:\\matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRTEInfo c2_emlrtRTEI = { 71,/* lineNo */
  21,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16"   /* pName */
};

static emlrtRTEInfo c2_b_emlrtRTEI = { 72,/* lineNo */
  39,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16"   /* pName */
};

static emlrtRTEInfo c2_c_emlrtRTEI = { 73,/* lineNo */
  35,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16"   /* pName */
};

static emlrtRTEInfo c2_d_emlrtRTEI = { 73,/* lineNo */
  53,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16"   /* pName */
};

static emlrtRTEInfo c2_e_emlrtRTEI = { 74,/* lineNo */
  25,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16"   /* pName */
};

static emlrtRTEInfo c2_f_emlrtRTEI = { 388,/* lineNo */
  10,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_g_emlrtRTEI = { 388,/* lineNo */
  19,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_h_emlrtRTEI = { 395,/* lineNo */
  10,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_i_emlrtRTEI = { 395,/* lineNo */
  19,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_j_emlrtRTEI = { 375,/* lineNo */
  10,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_k_emlrtRTEI = { 375,/* lineNo */
  19,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_l_emlrtRTEI = { 382,/* lineNo */
  10,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_m_emlrtRTEI = { 382,/* lineNo */
  19,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_n_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c2_o_emlrtRTEI = { 513,/* lineNo */
  1,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_p_emlrtRTEI = { 521,/* lineNo */
  38,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_q_emlrtRTEI = { 521,/* lineNo */
  1,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_r_emlrtRTEI = { 172,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c2_s_emlrtRTEI = { 531,/* lineNo */
  1,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_t_emlrtRTEI = { 535,/* lineNo */
  43,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_u_emlrtRTEI = { 617,/* lineNo */
  24,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_v_emlrtRTEI = { 617,/* lineNo */
  36,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_w_emlrtRTEI = { 617,/* lineNo */
  57,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_x_emlrtRTEI = { 617,/* lineNo */
  68,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_y_emlrtRTEI = { 617,/* lineNo */
  13,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_ab_emlrtRTEI = { 535,/* lineNo */
  1,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_bb_emlrtRTEI = { 538,/* lineNo */
  1,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_cb_emlrtRTEI = { 497,/* lineNo */
  31,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_db_emlrtRTEI = { 580,/* lineNo */
  1,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_eb_emlrtRTEI = { 581,/* lineNo */
  1,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_fb_emlrtRTEI = { 584,/* lineNo */
  1,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_gb_emlrtRTEI = { 585,/* lineNo */
  1,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_hb_emlrtRTEI = { 60,/* lineNo */
  20,                                  /* colNo */
  "bsxfun",                            /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"/* pName */
};

static emlrtRTEInfo c2_ib_emlrtRTEI = { 146,/* lineNo */
  24,                                  /* colNo */
  "blockedSummation",                  /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blockedSummation.m"/* pName */
};

static emlrtRTEInfo c2_jb_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "any",                               /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\any.m"/* pName */
};

static emlrtRTEInfo c2_kb_emlrtRTEI = { 422,/* lineNo */
  22,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_lb_emlrtRTEI = { 596,/* lineNo */
  5,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_mb_emlrtRTEI = { 617,/* lineNo */
  23,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_nb_emlrtRTEI = { 617,/* lineNo */
  56,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_ob_emlrtRTEI = { 617,/* lineNo */
  46,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_pb_emlrtRTEI = { 617,/* lineNo */
  9,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_qb_emlrtRTEI = { 538,/* lineNo */
  28,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_rb_emlrtRTEI = { 549,/* lineNo */
  22,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_sb_emlrtRTEI = { 579,/* lineNo */
  1,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_tb_emlrtRTEI = { 450,/* lineNo */
  9,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_ub_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "imfilter",                          /* fName */
  "E:\\matlab\\toolbox\\images\\images\\eml\\imfilter.m"/* pName */
};

static emlrtRTEInfo c2_vb_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16"   /* pName */
};

static emlrtRTEInfo c2_wb_emlrtRTEI = { 378,/* lineNo */
  9,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_xb_emlrtRTEI = { 1,/* lineNo */
  17,                                  /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtRTEInfo c2_yb_emlrtRTEI = { 611,/* lineNo */
  9,                                   /* colNo */
  "imresize",                          /* fName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pName */
};

static emlrtDCInfo c2_emlrtDCI = { 46, /* lineNo */
  36,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_emlrtBCI = { 1,  /* iFirst */
  3,                                   /* iLast */
  46,                                  /* lineNo */
  36,                                  /* colNo */
  "frame_double",                      /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_b_emlrtDCI = { 71,/* lineNo */
  43,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_b_emlrtBCI = { 1,/* iFirst */
  720,                                 /* iLast */
  71,                                  /* lineNo */
  43,                                  /* colNo */
  "reconstructed",                     /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_c_emlrtDCI = { 71,/* lineNo */
  45,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_c_emlrtBCI = { 1,/* iFirst */
  720,                                 /* iLast */
  71,                                  /* lineNo */
  45,                                  /* colNo */
  "reconstructed",                     /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_d_emlrtDCI = { 71,/* lineNo */
  61,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_d_emlrtBCI = { 1,/* iFirst */
  1280,                                /* iLast */
  71,                                  /* lineNo */
  61,                                  /* colNo */
  "reconstructed",                     /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_e_emlrtDCI = { 71,/* lineNo */
  63,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_e_emlrtBCI = { 1,/* iFirst */
  1280,                                /* iLast */
  71,                                  /* lineNo */
  63,                                  /* colNo */
  "reconstructed",                     /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_f_emlrtDCI = { 74,/* lineNo */
  39,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_f_emlrtBCI = { 1,/* iFirst */
  720,                                 /* iLast */
  74,                                  /* lineNo */
  39,                                  /* colNo */
  "reconstructed",                     /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_g_emlrtDCI = { 74,/* lineNo */
  41,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_g_emlrtBCI = { 1,/* iFirst */
  720,                                 /* iLast */
  74,                                  /* lineNo */
  41,                                  /* colNo */
  "reconstructed",                     /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_h_emlrtDCI = { 74,/* lineNo */
  57,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_h_emlrtBCI = { 1,/* iFirst */
  1280,                                /* iLast */
  74,                                  /* lineNo */
  57,                                  /* colNo */
  "reconstructed",                     /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_i_emlrtDCI = { 74,/* lineNo */
  59,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_i_emlrtBCI = { 1,/* iFirst */
  1280,                                /* iLast */
  74,                                  /* lineNo */
  59,                                  /* colNo */
  "reconstructed",                     /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_j_emlrtDCI = { 73,/* lineNo */
  35,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_j_emlrtBCI = { 1,/* iFirst */
  720,                                 /* iLast */
  73,                                  /* lineNo */
  35,                                  /* colNo */
  "reconstructed",                     /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_k_emlrtDCI = { 73,/* lineNo */
  37,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_k_emlrtBCI = { 1,/* iFirst */
  720,                                 /* iLast */
  73,                                  /* lineNo */
  37,                                  /* colNo */
  "reconstructed",                     /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_l_emlrtDCI = { 73,/* lineNo */
  53,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_l_emlrtBCI = { 1,/* iFirst */
  1280,                                /* iLast */
  73,                                  /* lineNo */
  53,                                  /* colNo */
  "reconstructed",                     /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c2_m_emlrtDCI = { 73,/* lineNo */
  55,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_m_emlrtBCI = { 1,/* iFirst */
  1280,                                /* iLast */
  73,                                  /* lineNo */
  55,                                  /* colNo */
  "reconstructed",                     /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c2_emlrtECI = { -1, /* nDims */
  73,                                  /* lineNo */
  21,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16"   /* pName */
};

static emlrtDCInfo c2_n_emlrtDCI = { 84,/* lineNo */
  31,                                  /* colNo */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c2_n_emlrtBCI = { 1,/* iFirst */
  3,                                   /* iLast */
  84,                                  /* lineNo */
  31,                                  /* colNo */
  "compressed_double",                 /* aName */
  "H.264 Simulator",                   /* fName */
  "#step2_compression_simulation:16",  /* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c2_o_emlrtBCI = { 1,/* iFirst */
  720,                                 /* iLast */
  156,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "E:\\matlab\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c2_p_emlrtBCI = { 1,/* iFirst */
  1280,                                /* iLast */
  156,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "E:\\matlab\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo c2_ib_emlrtRSI = { 422,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_jb_emlrtRSI = { 584,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_kb_emlrtRSI = { 580,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_lb_emlrtRSI = { 60,/* lineNo */
  "bsxfun",                            /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"/* pathName */
};

static emlrtRSInfo c2_mb_emlrtRSI = { 585,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static emlrtRSInfo c2_nb_emlrtRSI = { 531,/* lineNo */
  "imresize",                          /* fcnName */
  "E:\\matlab\\toolbox\\eml\\lib\\matlab\\images\\imresize.m"/* pathName */
};

static char_T c2_cv[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 's', 'x',
  'f', 'u', 'n', ':', 'a', 'r', 'r', 'a', 'y', 'D', 'i', 'm', 'e', 'n', 's', 'i',
  'o', 'n', 's', 'M', 'u', 's', 't', 'M', 'a', 't', 'c', 'h' };

static char_T c2_cv1[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
  '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f', 'R',
  'a', 'n', 'g', 'e' };

/* Function Declarations */
static void initialize_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void initialize_params_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void mdl_start_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void mdl_terminate_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void enable_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void disable_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void sf_gateway_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void ext_mode_exec_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void c2_update_jit_animation_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void c2_do_animation_call_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void set_sim_state_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void c2_imresize(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_c_Ain[921600], real_T
  c2_varargin_1, c2_coder_array_real_T_2D *c2_Bout);
static void c2_contributions(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_out_length, real_T c2_scale,
  real_T c2_kernel_width, c2_coder_array_real_T_2D *c2_weights,
  c2_coder_array_int32_T_2D *c2_indices);
static void c2_check_forloop_overflow_error
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const
   emlrtStack *c2_sp);
static void c2_bsxfun(SFc2_step2_compression_simulationInstanceStruct
                      *chartInstance, int32_T c2_a_data[], int32_T c2_a_size[1],
                      int32_T c2_b_data[], int32_T c2_b_size[2], int32_T
                      c2_c_data[], int32_T c2_c_size[2]);
static void c2_b_bsxfun(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_a_data[], int32_T
  c2_a_size[1], c2_coder_array_real_T_2D *c2_b, c2_coder_array_real_T_2D *c2_c);
static void c2_sum(SFc2_step2_compression_simulationInstanceStruct
                   *chartInstance, c2_coder_array_real_T_2D *c2_x, real_T
                   c2_y_data[], int32_T c2_y_size[1]);
static void c2_c_bsxfun(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_a,
  real_T c2_b_data[], int32_T c2_b_size[1], c2_coder_array_real_T_2D *c2_c);
static void c2_any(SFc2_step2_compression_simulationInstanceStruct
                   *chartInstance, const emlrtStack *c2_sp,
                   c2_coder_array_real_T_2D *c2_x, boolean_T c2_y_data[],
                   int32_T c2_y_size[2]);
static void c2_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_in_[921600],
  c2_coder_array_real_T_2D *c2_weights, int32_T c2_indices_data[],
  c2_coder_array_real_T_2D *c2_out_);
static int32_T c2_sub2ind(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, int32_T c2_siz[2], real_T
  c2_varargin_2);
static void c2_b_contributions(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_out_length, real_T c2_scale,
  real_T c2_kernel_width, c2_coder_array_real_T_2D *c2_weights,
  c2_coder_array_int32_T_2D *c2_indices);
static void c2_b_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_in_,
  c2_coder_array_real_T_2D *c2_weights, int32_T c2_indices_data[],
  c2_coder_array_real_T_2D *c2_out_);
static int32_T c2_b_sub2ind(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, int32_T c2_siz[2], real_T
  c2_varargin_1);
static void c2_c_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, real_T c2_in_[921600],
  c2_coder_array_real_T_2D *c2_weights, int32_T c2_indices_data[],
  c2_coder_array_real_T_2D *c2_out_);
static void c2_d_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_in_,
  c2_coder_array_real_T_2D *c2_weights, int32_T c2_indices_data[],
  c2_coder_array_real_T_2D *c2_out_);
static void c2_b_imresize(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_c_Ain,
  real_T c2_Bout[921600]);
static void c2_c_contributions(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, int32_T c2_in_length, real_T c2_scale,
  real_T c2_kernel_width, real_T c2_c_weights_data[], int32_T c2_weights_size[2],
  int32_T c2_indices_data[], int32_T c2_indices_size[2]);
static real_T c2_mod(SFc2_step2_compression_simulationInstanceStruct
                     *chartInstance, real_T c2_x, real_T c2_y);
static void c2_e_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_in_,
  real_T c2_c_weights_data[], int32_T c2_weights_size[2], int32_T
  c2_indices_data[], c2_coder_array_real_T_2D *c2_out_);
static void c2_d_contributions(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, int32_T c2_in_length, real_T c2_scale,
  real_T c2_kernel_width, real_T c2_c_weights_data[], int32_T c2_weights_size[2],
  int32_T c2_indices_data[], int32_T c2_indices_size[2]);
static void c2_f_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_in_,
  real_T c2_c_weights_data[], int32_T c2_weights_size[2], int32_T
  c2_indices_data[], real_T c2_out_[921600]);
static void c2_g_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_in_,
  real_T c2_c_weights_data[], int32_T c2_weights_size[2], int32_T
  c2_indices_data[], c2_coder_array_real_T_2D *c2_out_);
static void c2_h_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_in_,
  real_T c2_c_weights_data[], int32_T c2_weights_size[2], int32_T
  c2_indices_data[], real_T c2_out_[921600]);
static real_T c2_sumColumnB(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, c2_coder_array_real_T *c2_x, int32_T c2_vlen);
static real_T c2_sumColumnB4(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, c2_coder_array_real_T *c2_x, int32_T c2_vstart);
static real_T c2_b_sumColumnB(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, c2_coder_array_real_T *c2_x, int32_T c2_vlen, int32_T
  c2_vstart);
static void c2_fspecial(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_varargin_3, real_T c2_h[25]);
static real_T c2_c_sumColumnB(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, real_T c2_x[25]);
static void c2_imfilter(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_varargin_1[921600], real_T
  c2_varargin_2[25], real_T c2_b[921600]);
static void c2_padImage(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_a_tmp[921600], real_T c2_a
  [929616]);
static real_T c2_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_nullptr, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_nullptr, const char_T *c2_identifier, uint8_T c2_y[2764800]);
static void c2_d_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId, uint8_T c2_y[2764800]);
static real_T c2_e_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_nullptr, const char_T *c2_identifier, boolean_T *c2_svPtr);
static real_T c2_f_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T *c2_svPtr);
static void c2_g_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_nullptr, const char_T *c2_identifier, boolean_T *c2_svPtr, uint8_T c2_y
   [2764800]);
static void c2_h_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T *c2_svPtr, uint8_T
   c2_y[2764800]);
static void c2_slStringInitializeDynamicBuffers
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void c2_array_real_T_2D_SetSize
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const
   emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_coderArray, const
   emlrtRTEInfo *c2_srcLocation, int32_T c2_size0, int32_T c2_size1);
static void c2_array_real_T_SetSize
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const
   emlrtStack *c2_sp, c2_coder_array_real_T *c2_coderArray, const emlrtRTEInfo
   *c2_srcLocation, int32_T c2_size0);
static void c2_array_int32_T_2D_SetSize
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const
   emlrtStack *c2_sp, c2_coder_array_int32_T_2D *c2_coderArray, const
   emlrtRTEInfo *c2_srcLocation, int32_T c2_size0, int32_T c2_size1);
static void c2_array_real_T_2D_Constructor
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance,
   c2_coder_array_real_T_2D *c2_coderArray);
static void c2_array_real_T_Constructor
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance,
   c2_coder_array_real_T *c2_coderArray);
static void c2_array_real_T_2D_Destructor
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance,
   c2_coder_array_real_T_2D *c2_coderArray);
static void c2_array_real_T_Destructor
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance,
   c2_coder_array_real_T *c2_coderArray);
static void c2_array_int32_T_2D_Constructor
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance,
   c2_coder_array_int32_T_2D *c2_coderArray);
static void c2_array_int32_T_2D_Destructor
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance,
   c2_coder_array_int32_T_2D *c2_coderArray);
static int32_T c2__s32_s64_(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, int64_T c2_b, int32_T c2_EMLOvCount_src_loc, uint32_T
  c2_ssid_src_loc, int32_T c2_offset_src_loc, int32_T c2_length_src_loc);
static void init_dsm_address_info
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  emlrtStack c2_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c2_st.tls = chartInstance->c2_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c2_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c2_frame_count_not_empty = false;
  chartInstance->c2_total_bits_not_empty = false;
  chartInstance->c2_last_valid_frame_not_empty = false;
  chartInstance->c2_doneDoubleBufferReInit = false;
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  static const int32_T c2_postfixPredicateTree[5] = { 0, 1, -2, 2, -2 };

  static const int32_T c2_condTxtEndIdx[3] = { 571, 585, 602 };

  static const int32_T c2_condTxtStartIdx[3] = { 560, 575, 589 };

  static const uint32_T c2_decisionTxtEndIdx = 0U;
  static const uint32_T c2_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c2_JITStateAnimation[0],
                        &chartInstance->c2_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c2_covrtInstance, 1U, 0U, 1U,
    14U);
  covrtChartInitFcn(chartInstance->c2_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c2_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c2_decisionTxtStartIdx, &c2_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c2_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance, "", 4U, 0U, 1U, 0U, 5U, 0U,
                  1U, 0U, 3U, 0U, 3U, 1U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U,
                     "c2_step2_compression_simulation", 0, -1, 3912);
  covrtEmlSaturationInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 3136,
    -1, 3178);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 286, 309, -1,
                    440, false);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 1U, 557, 602, 1379,
                    3082, false);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 2U, 2221, 2247, -1,
                    2991, false);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 3U, 3552, 3571,
                    3636, 3676, false);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 4U, 3709, 3731,
                    3797, 3840, false);
  covrtEmlForInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 1379, 1397,
                     3082);
  covrtEmlForInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 1U, 2339, 2379,
                     2775);
  covrtEmlForInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 2U, 2396, 2435,
                     2759);
  covrtEmlMCDCInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 560, 602, 3U,
                      0U, &c2_condTxtStartIdx[0], &c2_condTxtEndIdx[0], 5U,
                      &c2_postfixPredicateTree[0], false);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 560,
    571, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 1U, 575,
    585, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 2U, 589,
    602, -1, 1U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 3U, 2224,
    2247, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 4U, 3555,
    3571, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 5U, 3712,
    3731, -1, 4U);
}

static void mdl_cleanup_runtime_resources_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c2_covrtInstance);
}

static void enable_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  static char_T c2_b_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  c2_coder_array_real_T c2_x;
  c2_coder_array_real_T_2D c2_b_block;
  c2_coder_array_real_T_2D c2_block;
  c2_coder_array_real_T_2D c2_small;
  emlrtStack c2_b_st;
  emlrtStack c2_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c2_p_y = NULL;
  const mxArray *c2_q_y = NULL;
  real_T c2_h_blur[25];
  real_T c2_accumulatedData;
  real_T c2_accumulatedWeights;
  real_T c2_artifact_strength;
  real_T c2_b;
  real_T c2_b_actual_bitrate;
  real_T c2_b_b;
  real_T c2_b_block_mean;
  real_T c2_b_c;
  real_T c2_b_compression_ratio;
  real_T c2_b_ex;
  real_T c2_b_j;
  real_T c2_b_target_bitrate_mbps;
  real_T c2_b_varargin_2;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_block_mean;
  real_T c2_c_b;
  real_T c2_c_i;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_compressed_bits;
  real_T c2_compression_efficiency;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d2;
  real_T c2_d3;
  real_T c2_d4;
  real_T c2_d5;
  real_T c2_d6;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_e_x;
  real_T c2_e_y;
  real_T c2_elapsed_time;
  real_T c2_ex;
  real_T c2_f_y;
  real_T c2_g_y;
  real_T c2_h_y;
  real_T c2_i_y;
  real_T c2_j_y;
  real_T c2_k_y;
  real_T c2_l_y;
  real_T c2_m_y;
  real_T c2_maxval;
  real_T c2_n_y;
  real_T c2_o_y;
  real_T c2_quality_factor;
  real_T c2_quant_step;
  real_T c2_s;
  real_T c2_scale_factor;
  real_T c2_varargin_2;
  real_T c2_y;
  int32_T c2_b_tmp_data[1280];
  int32_T c2_tmp_data[720];
  int32_T c2_iv[2];
  int32_T c2_iv1[2];
  int32_T c2_b_tmp_size[1];
  int32_T c2_tmp_size[1];
  int32_T c2_a;
  int32_T c2_b_i;
  int32_T c2_b_k;
  int32_T c2_b_loop_ub;
  int32_T c2_b_vlen;
  int32_T c2_c;
  int32_T c2_c_c;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_c_vlen;
  int32_T c2_d_c;
  int32_T c2_d_k;
  int32_T c2_d_loop_ub;
  int32_T c2_d_vlen;
  int32_T c2_e_k;
  int32_T c2_e_loop_ub;
  int32_T c2_f_k;
  int32_T c2_f_loop_ub;
  int32_T c2_g_loop_ub;
  int32_T c2_h_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i5;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i_loop_ub;
  int32_T c2_ib;
  int32_T c2_inb;
  int32_T c2_j;
  int32_T c2_j_loop_ub;
  int32_T c2_k;
  int32_T c2_k_loop_ub;
  int32_T c2_l_loop_ub;
  int32_T c2_lidx;
  int32_T c2_loop_ub;
  int32_T c2_m_loop_ub;
  int32_T c2_n_loop_ub;
  int32_T c2_nfb;
  int32_T c2_nleft;
  int32_T c2_nx;
  int32_T c2_vlen;
  uint8_T c2_u;
  boolean_T c2_b1;
  boolean_T c2_b10;
  boolean_T c2_b11;
  boolean_T c2_b12;
  boolean_T c2_b13;
  boolean_T c2_b14;
  boolean_T c2_b15;
  boolean_T c2_b16;
  boolean_T c2_b17;
  boolean_T c2_b18;
  boolean_T c2_b19;
  boolean_T c2_b2;
  boolean_T c2_b20;
  boolean_T c2_b21;
  boolean_T c2_b22;
  boolean_T c2_b23;
  boolean_T c2_b24;
  boolean_T c2_b3;
  boolean_T c2_b4;
  boolean_T c2_b5;
  boolean_T c2_b6;
  boolean_T c2_b7;
  boolean_T c2_b8;
  boolean_T c2_b9;
  boolean_T c2_covSaturation = false;
  boolean_T c2_d_b;
  c2_st.tls = chartInstance->c2_fEmlrtCtx;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 1U,
                    *chartInstance->c2_target_bitrate_mbps);
  for (c2_i = 0; c2_i < 2764800; c2_i++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 0U, (real_T)
                      (*chartInstance->c2_b_frame)[c2_i]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_JITTransitionAnimation[0] = 0U;
  chartInstance->c2_sfEvent = CALL_EVENT;
  for (c2_i1 = 0; c2_i1 < 2764800; c2_i1++) {
    chartInstance->c2_frame[c2_i1] = (*chartInstance->c2_b_frame)[c2_i1];
  }

  c2_b_target_bitrate_mbps = *chartInstance->c2_target_bitrate_mbps;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 4U, 0, 0);
  if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 0,
                     !chartInstance->c2_frame_count_not_empty)) {
    chartInstance->c2_frame_count = 0.0;
    chartInstance->c2_frame_count_not_empty = true;
    chartInstance->c2_total_bits = 0.0;
    chartInstance->c2_total_bits_not_empty = true;
    memset(&chartInstance->c2_last_valid_frame[0], 0, 2764800U * sizeof(uint8_T));
    chartInstance->c2_last_valid_frame_not_empty = true;
  }

  covrtEmlCondEval(chartInstance->c2_covrtInstance, 4U, 0, 0,
                   covrtRelationalopUpdateFcn(chartInstance->c2_covrtInstance,
    4U, 0U, 0U, 720.0, 10.0, -1, 2U, 0));
  covrtEmlCondEval(chartInstance->c2_covrtInstance, 4U, 0, 1,
                   covrtRelationalopUpdateFcn(chartInstance->c2_covrtInstance,
    4U, 0U, 1U, 1280.0, 10.0, -1, 2U, 0));
  covrtEmlCondEval(chartInstance->c2_covrtInstance, 4U, 0, 2,
                   covrtRelationalopUpdateFcn(chartInstance->c2_covrtInstance,
    4U, 0U, 2U, 3.0, 3.0, -1, 1U, 0));
  covrtEmlMcdcEval(chartInstance->c2_covrtInstance, 4U, 0, 0, false);
  covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 1, false);
  chartInstance->c2_frame_count++;
  c2_varargin_2 = c2_b_target_bitrate_mbps / 8.0;
  c2_y = c2_varargin_2;
  c2_b_y = c2_y;
  c2_c_y = c2_b_y;
  c2_b = c2_c_y;
  c2_d_y = c2_b;
  c2_e_y = c2_d_y;
  c2_maxval = muDoubleScalarMax(0.1, c2_e_y);
  c2_b_varargin_2 = c2_maxval;
  c2_f_y = c2_b_varargin_2;
  c2_g_y = c2_f_y;
  c2_h_y = c2_g_y;
  c2_b_b = c2_h_y;
  c2_i_y = c2_b_b;
  c2_j_y = c2_i_y;
  c2_quality_factor = muDoubleScalarMin(1.0, c2_j_y);
  for (c2_i2 = 0; c2_i2 < 2764800; c2_i2++) {
    chartInstance->c2_frame_double[c2_i2] = chartInstance->c2_frame[c2_i2];
  }

  c2_array_real_T_2D_Constructor(chartInstance, &c2_small);
  c2_array_real_T_2D_Constructor(chartInstance, &c2_block);
  c2_array_real_T_Constructor(chartInstance, &c2_x);
  c2_array_real_T_2D_Constructor(chartInstance, &c2_b_block);
  for (c2_c = 0; c2_c < 3; c2_c++) {
    c2_b_c = 1.0 + (real_T)c2_c;
    covrtEmlForEval(chartInstance->c2_covrtInstance, 4U, 0, 0, 1);
    if (c2_b_c != (real_T)(int32_T)muDoubleScalarFloor(c2_b_c)) {
      emlrtIntegerCheckR2012b(c2_b_c, &c2_emlrtDCI, &c2_st);
    }

    c2_i3 = (int32_T)c2_b_c;
    if ((c2_i3 < 1) || (c2_i3 > 3)) {
      emlrtDynamicBoundsCheckR2012b(c2_i3, 1, 3, &c2_emlrtBCI, &c2_st);
    }

    c2_c_c = c2_i3 - 1;
    for (c2_i4 = 0; c2_i4 < 1280; c2_i4++) {
      for (c2_i6 = 0; c2_i6 < 720; c2_i6++) {
        chartInstance->c2_channel[c2_i6 + 720 * c2_i4] =
          chartInstance->c2_frame_double[(c2_i6 + 720 * c2_i4) + 921600 * c2_c_c];
      }
    }

    c2_scale_factor = 0.25 + 0.75 * c2_quality_factor;
    c2_b_st.site = &c2_emlrtRSI;
    c2_imresize(chartInstance, &c2_b_st, chartInstance->c2_channel,
                c2_scale_factor, &c2_small);
    c2_b_x = 64.0 * (1.0 - c2_quality_factor);
    c2_c_x = c2_b_x;
    c2_o_y = c2_c_x;
    c2_o_y = muDoubleScalarRound(c2_o_y);
    c2_quant_step = c2_o_y + 1.0;
    c2_i7 = c2_small.size[0] * c2_small.size[1];
    c2_i8 = c2_i7;
    c2_loop_ub = c2_i8 - 1;
    for (c2_i10 = 0; c2_i10 <= c2_loop_ub; c2_i10++) {
      c2_small.vector.data[c2_i10] /= c2_quant_step;
    }

    c2_nx = c2_small.size[0] * c2_small.size[1];
    for (c2_e_k = 0; c2_e_k < c2_nx; c2_e_k++) {
      c2_f_k = c2_e_k;
      c2_d_x = c2_small.vector.data[c2_f_k];
      c2_e_x = c2_d_x;
      c2_e_x = muDoubleScalarRound(c2_e_x);
      c2_small.vector.data[c2_f_k] = c2_e_x;
    }

    c2_c_b = c2_quant_step;
    c2_i13 = c2_small.size[0] * c2_small.size[1];
    c2_i14 = c2_i13;
    c2_b_loop_ub = c2_i14 - 1;
    for (c2_i15 = 0; c2_i15 <= c2_b_loop_ub; c2_i15++) {
      c2_small.vector.data[c2_i15] *= c2_c_b;
    }

    c2_b_st.site = &c2_b_emlrtRSI;
    c2_b_imresize(chartInstance, &c2_b_st, &c2_small, chartInstance->c2_channel);
    c2_artifact_strength = 3.0 * (1.0 - c2_quality_factor);
    if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 2,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c2_covrtInstance, 4U, 0U, 3U,
                        c2_artifact_strength, 0.1, -1, 4U, c2_artifact_strength >
                        0.1))) {
      for (c2_b_i = 0; c2_b_i < 90; c2_b_i++) {
        c2_c_i = 1.0 + (real_T)c2_b_i * 8.0;
        covrtEmlForEval(chartInstance->c2_covrtInstance, 4U, 0, 1, 1);
        for (c2_j = 0; c2_j < 160; c2_j++) {
          c2_b_j = 1.0 + (real_T)c2_j * 8.0;
          covrtEmlForEval(chartInstance->c2_covrtInstance, 4U, 0, 2, 1);
          c2_d1 = (c2_c_i + 8.0) - 1.0;
          c2_d_b = (c2_c_i > c2_d1);
          c2_b1 = c2_d_b;
          c2_b2 = false;
          c2_b3 = (c2_b1 || c2_b2);
          if (c2_b3) {
            c2_i20 = 1;
            c2_i21 = 0;
          } else {
            if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
              emlrtIntegerCheckR2012b(c2_c_i, &c2_b_emlrtDCI, &c2_st);
            }

            c2_i22 = (int32_T)c2_c_i;
            if ((c2_i22 < 1) || (c2_i22 > 720)) {
              emlrtDynamicBoundsCheckR2012b(c2_i22, 1, 720, &c2_b_emlrtBCI,
                &c2_st);
            }

            c2_i20 = c2_i22;
            if (c2_d1 != (real_T)(int32_T)muDoubleScalarFloor(c2_d1)) {
              emlrtIntegerCheckR2012b(c2_d1, &c2_c_emlrtDCI, &c2_st);
            }

            c2_i23 = (int32_T)c2_d1;
            if ((c2_i23 < 1) || (c2_i23 > 720)) {
              emlrtDynamicBoundsCheckR2012b(c2_i23, 1, 720, &c2_c_emlrtBCI,
                &c2_st);
            }

            c2_i21 = c2_i23;
          }

          c2_d2 = (c2_b_j + 8.0) - 1.0;
          c2_b4 = (c2_b_j > c2_d2);
          c2_b5 = c2_b4;
          c2_b6 = false;
          c2_b7 = (c2_b5 || c2_b6);
          if (c2_b7) {
            c2_i24 = 1;
            c2_i25 = 0;
          } else {
            if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
              emlrtIntegerCheckR2012b(c2_b_j, &c2_d_emlrtDCI, &c2_st);
            }

            c2_i26 = (int32_T)c2_b_j;
            if ((c2_i26 < 1) || (c2_i26 > 1280)) {
              emlrtDynamicBoundsCheckR2012b(c2_i26, 1, 1280, &c2_d_emlrtBCI,
                &c2_st);
            }

            c2_i24 = c2_i26;
            if (c2_d2 != (real_T)(int32_T)muDoubleScalarFloor(c2_d2)) {
              emlrtIntegerCheckR2012b(c2_d2, &c2_e_emlrtDCI, &c2_st);
            }

            c2_i28 = (int32_T)c2_d2;
            if ((c2_i28 < 1) || (c2_i28 > 1280)) {
              emlrtDynamicBoundsCheckR2012b(c2_i28, 1, 1280, &c2_e_emlrtBCI,
                &c2_st);
            }

            c2_i25 = c2_i28;
          }

          c2_array_real_T_2D_SetSize(chartInstance, &c2_st, &c2_block,
            &c2_emlrtRTEI, (c2_i21 - c2_i20) + 1, (c2_i25 - c2_i24) + 1);
          c2_c_loop_ub = c2_i25 - c2_i24;
          for (c2_i27 = 0; c2_i27 <= c2_c_loop_ub; c2_i27++) {
            c2_d_loop_ub = c2_i21 - c2_i20;
            for (c2_i29 = 0; c2_i29 <= c2_d_loop_ub; c2_i29++) {
              c2_block.vector.data[c2_i29 + c2_block.size[0] * c2_i27] =
                chartInstance->c2_channel[((c2_i20 + c2_i29) + 720 * ((c2_i24 +
                c2_i27) - 1)) - 1];
            }
          }

          c2_b_st.site = &c2_c_emlrtRSI;
          c2_array_real_T_SetSize(chartInstance, &c2_b_st, &c2_x,
            &c2_b_emlrtRTEI, c2__s32_s64_(chartInstance, (int64_T)c2_block.size
            [0] * (int64_T)c2_block.size[1], 0, 1U, 2553, 8));
          c2_e_loop_ub = c2__s32_s64_(chartInstance, (int64_T)c2_block.size[0] *
            (int64_T)c2_block.size[1], 0, 1U, 2553, 8) - 1;
          for (c2_i30 = 0; c2_i30 <= c2_e_loop_ub; c2_i30++) {
            c2_x.vector.data[c2_i30] = c2_block.vector.data[c2_i30];
          }

          if ((c2_x.size[0] == 1) || (c2_x.size[0] != 1)) {
            c2_b8 = true;
          } else {
            c2_b8 = false;
          }

          if (!c2_b8) {
            c2_p_y = NULL;
            sf_mex_assign(&c2_p_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1, 0U, 2,
              1, 36), false);
            c2_q_y = NULL;
            sf_mex_assign(&c2_q_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1, 0U, 2,
              1, 36), false);
            sf_mex_call(&c2_b_st, &c2_d_emlrtMCI, "error", 0U, 2U, 14, c2_p_y,
                        14, sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c2_b_st, NULL, "message", 1U, 1U, 14, c2_q_y)));
          }

          c2_vlen = c2_x.size[0];
          c2_b_vlen = c2_vlen;
          if ((c2_x.size[0] == 0) || (c2_b_vlen == 0)) {
            c2_accumulatedData = 0.0;
          } else {
            c2_c_vlen = c2_b_vlen;
            c2_d_vlen = c2_c_vlen;
            if (c2_d_vlen < 4096) {
              c2_accumulatedData = c2_sumColumnB(chartInstance, &c2_x, c2_d_vlen);
            } else {
              c2_a = c2_d_vlen;
              c2_nfb = (int32_T)((uint32_T)c2_a >> 12);
              c2_inb = c2_nfb << 12;
              c2_lidx = c2_inb;
              c2_nleft = c2_d_vlen - c2_inb;
              c2_s = c2_sumColumnB4(chartInstance, &c2_x, 1);
              for (c2_ib = 2; c2_ib <= c2_nfb; c2_ib++) {
                c2_s += c2_sumColumnB4(chartInstance, &c2_x, 1 + ((c2_ib - 1) <<
                  12));
              }

              if (c2_nleft > 0) {
                c2_s += c2_b_sumColumnB(chartInstance, &c2_x, c2_nleft, c2_lidx
                  + 1);
              }

              c2_accumulatedData = c2_s;
            }
          }

          c2_accumulatedWeights = (real_T)c2_x.size[0];
          c2_block_mean = c2_accumulatedData / c2_accumulatedWeights;
          c2_d3 = (c2_c_i + 8.0) - 1.0;
          c2_b9 = (c2_c_i > c2_d3);
          c2_b10 = c2_b9;
          c2_b11 = false;
          c2_b12 = (c2_b10 || c2_b11);
          if (c2_b12) {
            c2_i31 = 1;
            c2_i32 = 0;
          } else {
            if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
              emlrtIntegerCheckR2012b(c2_c_i, &c2_f_emlrtDCI, &c2_st);
            }

            c2_i33 = (int32_T)c2_c_i;
            if ((c2_i33 < 1) || (c2_i33 > 720)) {
              emlrtDynamicBoundsCheckR2012b(c2_i33, 1, 720, &c2_f_emlrtBCI,
                &c2_st);
            }

            c2_i31 = c2_i33;
            if (c2_d3 != (real_T)(int32_T)muDoubleScalarFloor(c2_d3)) {
              emlrtIntegerCheckR2012b(c2_d3, &c2_g_emlrtDCI, &c2_st);
            }

            c2_i34 = (int32_T)c2_d3;
            if ((c2_i34 < 1) || (c2_i34 > 720)) {
              emlrtDynamicBoundsCheckR2012b(c2_i34, 1, 720, &c2_g_emlrtBCI,
                &c2_st);
            }

            c2_i32 = c2_i34;
          }

          c2_d4 = (c2_b_j + 8.0) - 1.0;
          c2_b13 = (c2_b_j > c2_d4);
          c2_b14 = c2_b13;
          c2_b15 = false;
          c2_b16 = (c2_b14 || c2_b15);
          if (c2_b16) {
            c2_i35 = 1;
            c2_i36 = 0;
          } else {
            if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
              emlrtIntegerCheckR2012b(c2_b_j, &c2_h_emlrtDCI, &c2_st);
            }

            c2_i37 = (int32_T)c2_b_j;
            if ((c2_i37 < 1) || (c2_i37 > 1280)) {
              emlrtDynamicBoundsCheckR2012b(c2_i37, 1, 1280, &c2_h_emlrtBCI,
                &c2_st);
            }

            c2_i35 = c2_i37;
            if (c2_d4 != (real_T)(int32_T)muDoubleScalarFloor(c2_d4)) {
              emlrtIntegerCheckR2012b(c2_d4, &c2_i_emlrtDCI, &c2_st);
            }

            c2_i38 = (int32_T)c2_d4;
            if ((c2_i38 < 1) || (c2_i38 > 1280)) {
              emlrtDynamicBoundsCheckR2012b(c2_i38, 1, 1280, &c2_i_emlrtBCI,
                &c2_st);
            }

            c2_i36 = c2_i38;
          }

          c2_d5 = (c2_c_i + 8.0) - 1.0;
          c2_b17 = (c2_c_i > c2_d5);
          c2_b18 = c2_b17;
          c2_b19 = false;
          c2_b20 = (c2_b18 || c2_b19);
          if (c2_b20) {
            c2_i39 = 1;
            c2_i40 = 0;
          } else {
            if (c2_c_i != (real_T)(int32_T)muDoubleScalarFloor(c2_c_i)) {
              emlrtIntegerCheckR2012b(c2_c_i, &c2_j_emlrtDCI, &c2_st);
            }

            c2_i41 = (int32_T)c2_c_i;
            if ((c2_i41 < 1) || (c2_i41 > 720)) {
              emlrtDynamicBoundsCheckR2012b(c2_i41, 1, 720, &c2_j_emlrtBCI,
                &c2_st);
            }

            c2_i39 = c2_i41;
            if (c2_d5 != (real_T)(int32_T)muDoubleScalarFloor(c2_d5)) {
              emlrtIntegerCheckR2012b(c2_d5, &c2_k_emlrtDCI, &c2_st);
            }

            c2_i42 = (int32_T)c2_d5;
            if ((c2_i42 < 1) || (c2_i42 > 720)) {
              emlrtDynamicBoundsCheckR2012b(c2_i42, 1, 720, &c2_k_emlrtBCI,
                &c2_st);
            }

            c2_i40 = c2_i42;
          }

          c2_d6 = (c2_b_j + 8.0) - 1.0;
          c2_b21 = (c2_b_j > c2_d6);
          c2_b22 = c2_b21;
          c2_b23 = false;
          c2_b24 = (c2_b22 || c2_b23);
          if (c2_b24) {
            c2_i43 = 1;
            c2_i44 = 0;
          } else {
            if (c2_b_j != (real_T)(int32_T)muDoubleScalarFloor(c2_b_j)) {
              emlrtIntegerCheckR2012b(c2_b_j, &c2_l_emlrtDCI, &c2_st);
            }

            c2_i45 = (int32_T)c2_b_j;
            if ((c2_i45 < 1) || (c2_i45 > 1280)) {
              emlrtDynamicBoundsCheckR2012b(c2_i45, 1, 1280, &c2_l_emlrtBCI,
                &c2_st);
            }

            c2_i43 = c2_i45;
            if (c2_d6 != (real_T)(int32_T)muDoubleScalarFloor(c2_d6)) {
              emlrtIntegerCheckR2012b(c2_d6, &c2_m_emlrtDCI, &c2_st);
            }

            c2_i47 = (int32_T)c2_d6;
            if ((c2_i47 < 1) || (c2_i47 > 1280)) {
              emlrtDynamicBoundsCheckR2012b(c2_i47, 1, 1280, &c2_m_emlrtBCI,
                &c2_st);
            }

            c2_i44 = c2_i47;
          }

          c2_tmp_size[0] = (c2_i40 - c2_i39) + 1;
          c2_f_loop_ub = c2_i40 - c2_i39;
          for (c2_i46 = 0; c2_i46 <= c2_f_loop_ub; c2_i46++) {
            c2_tmp_data[c2_i46] = (c2_i39 + c2_i46) - 1;
          }

          c2_b_tmp_size[0] = (c2_i44 - c2_i43) + 1;
          c2_g_loop_ub = c2_i44 - c2_i43;
          for (c2_i48 = 0; c2_i48 <= c2_g_loop_ub; c2_i48++) {
            c2_b_tmp_data[c2_i48] = (c2_i43 + c2_i48) - 1;
          }

          c2_array_real_T_2D_SetSize(chartInstance, &c2_st, &c2_small,
            &c2_e_emlrtRTEI, (c2_i32 - c2_i31) + 1, (c2_i36 - c2_i35) + 1);
          c2_h_loop_ub = c2_i36 - c2_i35;
          for (c2_i49 = 0; c2_i49 <= c2_h_loop_ub; c2_i49++) {
            c2_i_loop_ub = c2_i32 - c2_i31;
            for (c2_i52 = 0; c2_i52 <= c2_i_loop_ub; c2_i52++) {
              c2_small.vector.data[c2_i52 + c2_small.size[0] * c2_i49] =
                chartInstance->c2_channel[((c2_i31 + c2_i52) + 720 * ((c2_i35 +
                c2_i49) - 1)) - 1];
            }
          }

          c2_i50 = c2_small.size[0] * c2_small.size[1];
          c2_i51 = c2_i50;
          c2_j_loop_ub = c2_i51 - 1;
          for (c2_i53 = 0; c2_i53 <= c2_j_loop_ub; c2_i53++) {
            c2_small.vector.data[c2_i53] *= 0.7;
          }

          c2_array_real_T_2D_SetSize(chartInstance, &c2_st, &c2_block,
            &c2_e_emlrtRTEI, c2_small.size[0], c2_small.size[1]);
          c2_k_loop_ub = c2_small.size[0] * c2_small.size[1] - 1;
          for (c2_i54 = 0; c2_i54 <= c2_k_loop_ub; c2_i54++) {
            c2_block.vector.data[c2_i54] = c2_small.vector.data[c2_i54];
          }

          c2_iv[0] = c2_tmp_size[0];
          c2_iv[1] = c2_b_tmp_size[0];
          emlrtSubAssignSizeCheckR2012b(&c2_iv[0], 2, &c2_block.size[0], 2,
            &c2_emlrtECI, &c2_st);
          c2_b_block_mean = c2_block_mean * 0.3;
          c2_array_real_T_2D_SetSize(chartInstance, &c2_st, &c2_b_block,
            &c2_e_emlrtRTEI, c2_block.size[0], c2_block.size[1]);
          c2_l_loop_ub = c2_block.size[0] * c2_block.size[1] - 1;
          for (c2_i55 = 0; c2_i55 <= c2_l_loop_ub; c2_i55++) {
            c2_b_block.vector.data[c2_i55] = c2_block.vector.data[c2_i55] +
              c2_b_block_mean;
          }

          c2_iv1[0] = c2_tmp_size[0];
          c2_iv1[1] = c2_b_tmp_size[0];
          c2_m_loop_ub = c2_iv1[1] - 1;
          for (c2_i56 = 0; c2_i56 <= c2_m_loop_ub; c2_i56++) {
            c2_n_loop_ub = c2_iv1[0] - 1;
            for (c2_i57 = 0; c2_i57 <= c2_n_loop_ub; c2_i57++) {
              chartInstance->c2_channel[c2_tmp_data[c2_i57] + 720 *
                c2_b_tmp_data[c2_i56]] = c2_b_block.vector.data[c2_i57 + c2_iv1
                [0] * c2_i56];
            }
          }

          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        covrtEmlForEval(chartInstance->c2_covrtInstance, 4U, 0, 2, 0);
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      covrtEmlForEval(chartInstance->c2_covrtInstance, 4U, 0, 1, 0);
      c2_b_st.site = &c2_d_emlrtRSI;
      c2_fspecial(chartInstance, &c2_b_st, 0.5 + c2_artifact_strength, c2_h_blur);
      for (c2_i17 = 0; c2_i17 < 921600; c2_i17++) {
        chartInstance->c2_b_channel[c2_i17] = chartInstance->c2_channel[c2_i17];
      }

      c2_b_st.site = &c2_e_emlrtRSI;
      c2_imfilter(chartInstance, &c2_b_st, chartInstance->c2_b_channel,
                  c2_h_blur, chartInstance->c2_channel);
    }

    if (c2_b_c != (real_T)(int32_T)muDoubleScalarFloor(c2_b_c)) {
      emlrtIntegerCheckR2012b(c2_b_c, &c2_n_emlrtDCI, &c2_st);
    }

    c2_i16 = (int32_T)c2_b_c;
    if ((c2_i16 < 1) || (c2_i16 > 3)) {
      emlrtDynamicBoundsCheckR2012b(c2_i16, 1, 3, &c2_n_emlrtBCI, &c2_st);
    }

    c2_d_c = c2_i16 - 1;
    for (c2_i18 = 0; c2_i18 < 1280; c2_i18++) {
      for (c2_i19 = 0; c2_i19 < 720; c2_i19++) {
        chartInstance->c2_compressed_double[(c2_i19 + 720 * c2_i18) + 921600 *
          c2_d_c] = chartInstance->c2_channel[c2_i19 + 720 * c2_i18];
      }
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c2_array_real_T_2D_Destructor(chartInstance, &c2_b_block);
  c2_array_real_T_Destructor(chartInstance, &c2_x);
  c2_array_real_T_2D_Destructor(chartInstance, &c2_block);
  c2_array_real_T_2D_Destructor(chartInstance, &c2_small);
  covrtEmlForEval(chartInstance->c2_covrtInstance, 4U, 0, 0, 0);
  for (c2_k = 0; c2_k < 2764800; c2_k++) {
    c2_c_k = c2_k;
    c2_k_y = chartInstance->c2_compressed_double[c2_c_k];
    c2_l_y = c2_k_y;
    c2_ex = muDoubleScalarMin(255.0, c2_l_y);
    chartInstance->c2_minval[c2_c_k] = c2_ex;
  }

  for (c2_b_k = 0; c2_b_k < 2764800; c2_b_k++) {
    c2_d_k = c2_b_k;
    c2_m_y = chartInstance->c2_minval[c2_d_k];
    c2_n_y = c2_m_y;
    c2_b_ex = muDoubleScalarMax(0.0, c2_n_y);
    chartInstance->c2_frame_double[c2_d_k] = c2_b_ex;
  }

  for (c2_i5 = 0; c2_i5 < 2764800; c2_i5++) {
    c2_d = muDoubleScalarRound(chartInstance->c2_frame_double[c2_i5]);
    c2_covSaturation = false;
    if (c2_d < 256.0) {
      if (c2_d >= 0.0) {
        c2_u = (uint8_T)c2_d;
      } else {
        c2_covSaturation = true;
        c2_u = 0U;
        sf_data_saturate_error(chartInstance->S, 1U, 3136, 42);
      }
    } else if (c2_d >= 256.0) {
      c2_covSaturation = true;
      c2_u = MAX_uint8_T;
      sf_data_saturate_error(chartInstance->S, 1U, 3136, 42);
    } else {
      c2_u = 0U;
    }

    covrtSaturationUpdateFcn(chartInstance->c2_covrtInstance, 4, 0, 0, 0,
      c2_covSaturation);
    chartInstance->c2_compressed[c2_i5] = c2_u;
  }

  c2_compression_efficiency = 0.85 + 0.13 * c2_quality_factor;
  c2_compressed_bits = 2.21184E+7 * (1.0 - c2_compression_efficiency);
  chartInstance->c2_total_bits += c2_compressed_bits;
  c2_elapsed_time = chartInstance->c2_frame_count / 30.0;
  if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 3,
                     covrtRelationalopUpdateFcn(chartInstance->c2_covrtInstance,
        4U, 0U, 4U, c2_elapsed_time, 0.0, -1, 4U, c2_elapsed_time > 0.0))) {
    c2_b_actual_bitrate = chartInstance->c2_total_bits / c2_elapsed_time /
      1.0E+6;
  } else {
    c2_b_actual_bitrate = 0.0;
  }

  if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 4,
                     covrtRelationalopUpdateFcn(chartInstance->c2_covrtInstance,
        4U, 0U, 5U, c2_compressed_bits, 0.0, -1, 4U, c2_compressed_bits > 0.0)))
  {
    c2_b_compression_ratio = 2.21184E+7 / c2_compressed_bits;
  } else {
    c2_b_compression_ratio = 1.0;
  }

  for (c2_i9 = 0; c2_i9 < 2764800; c2_i9++) {
    chartInstance->c2_last_valid_frame[c2_i9] = chartInstance->
      c2_compressed[c2_i9];
  }

  for (c2_i11 = 0; c2_i11 < 2764800; c2_i11++) {
    (*chartInstance->c2_b_compressed)[c2_i11] = chartInstance->
      c2_compressed[c2_i11];
  }

  *chartInstance->c2_actual_bitrate = c2_b_actual_bitrate;
  *chartInstance->c2_compression_ratio = c2_b_compression_ratio;
  for (c2_i12 = 0; c2_i12 < 2764800; c2_i12++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 2U, (real_T)
                      (*chartInstance->c2_b_compressed)[c2_i12]);
  }

  covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 3U,
                    *chartInstance->c2_actual_bitrate);
  covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 4U,
                    *chartInstance->c2_compression_ratio);
}

static void ext_mode_exec_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_update_jit_animation_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_do_animation_call_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(6, 1), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", chartInstance->c2_actual_bitrate, 0,
    0U, 0, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", *chartInstance->c2_b_compressed, 3,
    0U, 1, 0U, 3, 720, 1280, 3), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", chartInstance->c2_compression_ratio,
    0, 0U, 0, 0U, 0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_e_y = NULL;
  if (!chartInstance->c2_frame_count_not_empty) {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", &chartInstance->c2_frame_count, 0,
      0U, 0, 0U, 0), false);
  }

  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_f_y = NULL;
  if (!chartInstance->c2_last_valid_frame_not_empty) {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", chartInstance->c2_last_valid_frame,
      3, 0U, 1, 0U, 3, 720, 1280, 3), false);
  }

  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_g_y = NULL;
  if (!chartInstance->c2_frame_count_not_empty) {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", &chartInstance->c2_total_bits, 0,
      0U, 0, 0U, 0), false);
  }

  sf_mex_setcell(c2_y, 5, c2_g_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_step2_compression_simulation
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  int32_T c2_i;
  int32_T c2_i1;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *chartInstance->c2_actual_bitrate = c2_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 0)), "actual_bitrate");
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                        "compressed", chartInstance->c2_uv);
  for (c2_i = 0; c2_i < 2764800; c2_i++) {
    (*chartInstance->c2_b_compressed)[c2_i] = chartInstance->c2_uv[c2_i];
  }

  *chartInstance->c2_compression_ratio = c2_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 2)), "compression_ratio");
  chartInstance->c2_frame_count = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 3)), "frame_count",
    &chartInstance->c2_frame_count_not_empty);
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
                        "last_valid_frame",
                        &chartInstance->c2_last_valid_frame_not_empty,
                        chartInstance->c2_uv1);
  for (c2_i1 = 0; c2_i1 < 2764800; c2_i1++) {
    chartInstance->c2_last_valid_frame[c2_i1] = chartInstance->c2_uv1[c2_i1];
  }

  chartInstance->c2_total_bits = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 5)), "total_bits",
    &chartInstance->c2_total_bits_not_empty);
  sf_mex_destroy(&c2_u);
  sf_mex_destroy(&c2_st);
}

static void c2_imresize(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_c_Ain[921600], real_T
  c2_varargin_1, c2_coder_array_real_T_2D *c2_Bout)
{
  c2_coder_array_int32_T_2D c2_indices;
  c2_coder_array_real_T_2D c2_APartialResize;
  c2_coder_array_real_T_2D c2_b_APartialResize;
  c2_coder_array_real_T_2D c2_b_weights;
  c2_coder_array_real_T_2D c2_weights;
  emlrtStack c2_st;
  real_T c2_scale[2];
  real_T c2_scaleOrSize[2];
  real_T c2_b_x;
  real_T c2_x;
  int32_T c2_indices_data[11520];
  int32_T c2_b_k;
  int32_T c2_b_loop_ub;
  int32_T c2_c_loop_ub;
  int32_T c2_d_loop_ub;
  int32_T c2_e_loop_ub;
  int32_T c2_f_loop_ub;
  int32_T c2_g_loop_ub;
  int32_T c2_h_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_k;
  int32_T c2_loop_ub;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_scaleOrSize[0] = c2_varargin_1;
  c2_scale[0] = c2_scaleOrSize[0];
  c2_scale[1] = c2_scaleOrSize[0];
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_scaleOrSize[c2_i] = (720.0 + 560.0 * (real_T)c2_i) * c2_scale[c2_i];
  }

  for (c2_k = 0; c2_k < 2; c2_k++) {
    c2_b_k = c2_k;
    c2_x = c2_scaleOrSize[c2_b_k];
    c2_b_x = c2_x;
    c2_b_x = muDoubleScalarCeil(c2_b_x);
    c2_scaleOrSize[c2_b_k] = c2_b_x;
  }

  c2_array_real_T_2D_Constructor(chartInstance, &c2_weights);
  c2_array_real_T_2D_Constructor(chartInstance, &c2_b_weights);
  c2_array_int32_T_2D_Constructor(chartInstance, &c2_indices);
  if (c2_scale[0] <= c2_scale[1]) {
    c2_st.site = &c2_f_emlrtRSI;
    c2_contributions(chartInstance, &c2_st, c2_scaleOrSize[0], c2_scale[0], 2.0,
                     &c2_b_weights, &c2_indices);
    c2_st.site = &c2_f_emlrtRSI;
    c2_array_real_T_2D_SetSize(chartInstance, &c2_st, &c2_weights,
      &c2_j_emlrtRTEI, c2_b_weights.size[0], c2_b_weights.size[1]);
    c2_b_loop_ub = c2_b_weights.size[0] * c2_b_weights.size[1] - 1;
    for (c2_i2 = 0; c2_i2 <= c2_b_loop_ub; c2_i2++) {
      c2_weights.vector.data[c2_i2] = c2_b_weights.vector.data[c2_i2];
    }

    c2_d_loop_ub = c2_indices.size[0] * c2_indices.size[1] - 1;
    for (c2_i4 = 0; c2_i4 <= c2_d_loop_ub; c2_i4++) {
      c2_indices_data[c2_i4] = c2_indices.vector.data[c2_i4];
    }

    c2_array_real_T_2D_Constructor(chartInstance, &c2_b_APartialResize);
    c2_st.site = &c2_g_emlrtRSI;
    for (c2_i6 = 0; c2_i6 < 921600; c2_i6++) {
      chartInstance->c2_b_Ain[c2_i6] = c2_c_Ain[c2_i6];
    }

    c2_resizeAlongDim(chartInstance, &c2_st, chartInstance->c2_b_Ain,
                      &c2_weights, c2_indices_data, &c2_b_APartialResize);
    c2_st.site = &c2_h_emlrtRSI;
    c2_b_contributions(chartInstance, &c2_st, c2_scaleOrSize[1], c2_scale[1],
                       2.0, &c2_b_weights, &c2_indices);
    c2_st.site = &c2_h_emlrtRSI;
    c2_array_real_T_2D_SetSize(chartInstance, &c2_st, &c2_weights,
      &c2_l_emlrtRTEI, c2_b_weights.size[0], c2_b_weights.size[1]);
    c2_f_loop_ub = c2_b_weights.size[0] * c2_b_weights.size[1] - 1;
    for (c2_i8 = 0; c2_i8 <= c2_f_loop_ub; c2_i8++) {
      c2_weights.vector.data[c2_i8] = c2_b_weights.vector.data[c2_i8];
    }

    c2_h_loop_ub = c2_indices.size[0] * c2_indices.size[1] - 1;
    for (c2_i10 = 0; c2_i10 <= c2_h_loop_ub; c2_i10++) {
      c2_indices_data[c2_i10] = c2_indices.vector.data[c2_i10];
    }

    c2_st.site = &c2_i_emlrtRSI;
    c2_b_resizeAlongDim(chartInstance, &c2_st, &c2_b_APartialResize, &c2_weights,
                        c2_indices_data, c2_Bout);
    c2_array_real_T_2D_Destructor(chartInstance, &c2_b_APartialResize);
  } else {
    c2_st.site = &c2_j_emlrtRSI;
    c2_b_contributions(chartInstance, &c2_st, c2_scaleOrSize[1], c2_scale[1],
                       2.0, &c2_b_weights, &c2_indices);
    c2_st.site = &c2_j_emlrtRSI;
    c2_array_real_T_2D_SetSize(chartInstance, &c2_st, &c2_weights,
      &c2_f_emlrtRTEI, c2_b_weights.size[0], c2_b_weights.size[1]);
    c2_loop_ub = c2_b_weights.size[0] * c2_b_weights.size[1] - 1;
    for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
      c2_weights.vector.data[c2_i1] = c2_b_weights.vector.data[c2_i1];
    }

    c2_c_loop_ub = c2_indices.size[0] * c2_indices.size[1] - 1;
    for (c2_i3 = 0; c2_i3 <= c2_c_loop_ub; c2_i3++) {
      c2_indices_data[c2_i3] = c2_indices.vector.data[c2_i3];
    }

    c2_array_real_T_2D_Constructor(chartInstance, &c2_APartialResize);
    c2_st.site = &c2_k_emlrtRSI;
    for (c2_i5 = 0; c2_i5 < 921600; c2_i5++) {
      chartInstance->c2_Ain[c2_i5] = c2_c_Ain[c2_i5];
    }

    c2_c_resizeAlongDim(chartInstance, &c2_st, chartInstance->c2_Ain,
                        &c2_weights, c2_indices_data, &c2_APartialResize);
    c2_st.site = &c2_l_emlrtRSI;
    c2_contributions(chartInstance, &c2_st, c2_scaleOrSize[0], c2_scale[0], 2.0,
                     &c2_b_weights, &c2_indices);
    c2_st.site = &c2_l_emlrtRSI;
    c2_array_real_T_2D_SetSize(chartInstance, &c2_st, &c2_weights,
      &c2_h_emlrtRTEI, c2_b_weights.size[0], c2_b_weights.size[1]);
    c2_e_loop_ub = c2_b_weights.size[0] * c2_b_weights.size[1] - 1;
    for (c2_i7 = 0; c2_i7 <= c2_e_loop_ub; c2_i7++) {
      c2_weights.vector.data[c2_i7] = c2_b_weights.vector.data[c2_i7];
    }

    c2_g_loop_ub = c2_indices.size[0] * c2_indices.size[1] - 1;
    for (c2_i9 = 0; c2_i9 <= c2_g_loop_ub; c2_i9++) {
      c2_indices_data[c2_i9] = c2_indices.vector.data[c2_i9];
    }

    c2_st.site = &c2_m_emlrtRSI;
    c2_d_resizeAlongDim(chartInstance, &c2_st, &c2_APartialResize, &c2_weights,
                        c2_indices_data, c2_Bout);
    c2_array_real_T_2D_Destructor(chartInstance, &c2_APartialResize);
  }

  c2_array_int32_T_2D_Destructor(chartInstance, &c2_indices);
  c2_array_real_T_2D_Destructor(chartInstance, &c2_b_weights);
  c2_array_real_T_2D_Destructor(chartInstance, &c2_weights);
}

static void c2_contributions(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_out_length, real_T c2_scale,
  real_T c2_kernel_width, c2_coder_array_real_T_2D *c2_weights,
  c2_coder_array_int32_T_2D *c2_indices)
{
  c2_coder_array_real_T_2D c2_b_indices;
  c2_coder_array_real_T_2D c2_e_x;
  c2_coder_array_real_T_2D c2_f;
  emlrtStack c2_st;
  real_T c2_b_x_data[1280];
  real_T c2_c_x_data[1280];
  real_T c2_y_data[1280];
  real_T c2_b;
  real_T c2_b_d;
  real_T c2_b_kernel_width;
  real_T c2_b_scale;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d_i;
  real_T c2_d_k;
  real_T c2_d_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_a;
  real_T c2_h_x;
  real_T c2_i_a;
  real_T c2_j_a;
  real_T c2_k_a;
  real_T c2_oldIdx;
  real_T c2_x;
  real_T c2_y;
  int32_T c2_indicesNonZeroCols_data[11520];
  int32_T c2_aux[1440];
  int32_T c2_left_data[1280];
  int32_T c2_b_y_data[9];
  int32_T c2_d_tmp_data[9];
  int32_T c2_e_tmp_data[9];
  int32_T c2_b_tmp_size[2];
  int32_T c2_b_y_size[2];
  int32_T c2_c_tmp_size[2];
  int32_T c2_copyCols_size[2];
  int32_T c2_d_tmp_size[2];
  int32_T c2_indicesNonZeroCols_size[2];
  int32_T c2_tmp_size[2];
  int32_T c2_y_size[2];
  int32_T c2_b_x_size[1];
  int32_T c2_left_size[1];
  int32_T c2_x_size[1];
  int32_T c2_P;
  int32_T c2_a;
  int32_T c2_ab_loop_ub;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_end;
  int32_T c2_b_i;
  int32_T c2_b_k;
  int32_T c2_b_loop_ub;
  int32_T c2_b_partialTrueCount;
  int32_T c2_b_trueCount;
  int32_T c2_bb_loop_ub;
  int32_T c2_bi;
  int32_T c2_bma;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_c_d;
  int32_T c2_c_i;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_cb_loop_ub;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_loop_ub;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_e_i;
  int32_T c2_e_loop_ub;
  int32_T c2_end;
  int32_T c2_f_a;
  int32_T c2_f_b;
  int32_T c2_f_i;
  int32_T c2_f_loop_ub;
  int32_T c2_g_a;
  int32_T c2_g_b;
  int32_T c2_g_i;
  int32_T c2_g_loop_ub;
  int32_T c2_h_i;
  int32_T c2_h_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i_loop_ub;
  int32_T c2_j_loop_ub;
  int32_T c2_k;
  int32_T c2_k_loop_ub;
  int32_T c2_l_loop_ub;
  int32_T c2_loop_ub;
  int32_T c2_m_loop_ub;
  int32_T c2_n;
  int32_T c2_n_loop_ub;
  int32_T c2_nm1;
  int32_T c2_nx;
  int32_T c2_o_loop_ub;
  int32_T c2_p_loop_ub;
  int32_T c2_partialTrueCount;
  int32_T c2_q_loop_ub;
  int32_T c2_r_loop_ub;
  int32_T c2_s_loop_ub;
  int32_T c2_span;
  int32_T c2_t_loop_ub;
  int32_T c2_trueCount;
  int32_T c2_u_loop_ub;
  int32_T c2_v_loop_ub;
  int32_T c2_w_loop_ub;
  int32_T c2_x_loop_ub;
  int32_T c2_y_loop_ub;
  int32_T c2_yk;
  boolean_T c2_b_tmp_data[11520];
  boolean_T c2_c_tmp_data[11520];
  boolean_T c2_tmp_data[11520];
  boolean_T c2_copyCols_data[9];
  boolean_T c2_rEQ0;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  if (c2_scale < 1.0) {
    c2_kernel_width = 2.0 / c2_scale;
  }

  c2_d = c2_out_length;
  c2_b = c2_d;
  c2_y_size[1] = (int32_T)(c2_b - 1.0) + 1;
  c2_loop_ub = (int32_T)(c2_b - 1.0);
  for (c2_i = 0; c2_i <= c2_loop_ub; c2_i++) {
    c2_y_data[c2_i] = 1.0 + (real_T)c2_i;
  }

  c2_x_size[0] = c2_y_size[1];
  c2_b_loop_ub = c2_y_size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_b_loop_ub; c2_i1++) {
    c2_b_x_data[c2_i1] = c2_y_data[c2_i1];
  }

  c2_b_d = 0.5 * (1.0 - 1.0 / c2_scale);
  c2_c_loop_ub = c2_x_size[0] - 1;
  for (c2_i2 = 0; c2_i2 <= c2_c_loop_ub; c2_i2++) {
    c2_b_x_data[c2_i2] = c2_b_x_data[c2_i2] / c2_scale + c2_b_d;
  }

  c2_b_kernel_width = c2_kernel_width / 2.0;
  c2_b_x_size[0] = c2_x_size[0];
  c2_d_loop_ub = c2_x_size[0] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_d_loop_ub; c2_i3++) {
    c2_c_x_data[c2_i3] = c2_b_x_data[c2_i3] - c2_b_kernel_width;
  }

  c2_nx = c2_b_x_size[0];
  c2_i4 = (uint16_T)c2_nx;
  for (c2_k = 0; c2_k < c2_i4; c2_k++) {
    c2_b_k = c2_k;
    c2_x = c2_c_x_data[c2_b_k];
    c2_b_x = c2_x;
    c2_b_x = muDoubleScalarFloor(c2_b_x);
    c2_c_x_data[c2_b_k] = c2_b_x;
  }

  c2_left_size[0] = c2_b_x_size[0];
  c2_e_loop_ub = c2_b_x_size[0] - 1;
  for (c2_i5 = 0; c2_i5 <= c2_e_loop_ub; c2_i5++) {
    c2_left_data[c2_i5] = (int32_T)c2_c_x_data[c2_i5];
  }

  c2_c_x = c2_kernel_width;
  c2_d_x = c2_c_x;
  c2_y = c2_d_x;
  c2_y = muDoubleScalarCeil(c2_y);
  c2_P = (int32_T)(c2_y + 2.0) - 1;
  c2_c_d = c2_P;
  c2_b_b = c2_c_d;
  c2_c_b = c2_b_b;
  c2_a = c2_c_b;
  c2_bi = c2_a;
  c2_d_b = c2_bi;
  c2_e_b = c2_d_b;
  c2_f_b = c2_e_b;
  c2_b_a = c2_f_b;
  c2_bma = c2_b_a;
  c2_c_a = c2_bma;
  c2_span = c2_c_a;
  c2_d_a = c2_span;
  c2_nm1 = (uint8_T)c2_d_a;
  c2_e_a = c2_nm1;
  c2_g_b = c2_e_a;
  c2_f_a = c2_g_b + 1;
  c2_n = c2_f_a;
  c2_b_y_size[0] = 1;
  c2_b_y_size[1] = c2_n;
  c2_b_y_data[0] = 0;
  c2_yk = 0;
  for (c2_c_k = 2; c2_c_k <= c2_n; c2_c_k++) {
    c2_g_a = c2_yk + 1;
    c2_yk = c2_g_a;
    c2_b_y_data[c2_c_k - 1] = c2_yk;
  }

  c2_bsxfun(chartInstance, c2_left_data, c2_left_size, c2_b_y_data, c2_b_y_size,
            c2_indicesNonZeroCols_data, c2_indicesNonZeroCols_size);
  c2_st.site = &c2_nb_emlrtRSI;
  c2_array_int32_T_2D_SetSize(chartInstance, &c2_st, c2_indices, &c2_s_emlrtRTEI,
    c2_indicesNonZeroCols_size[0], c2_indicesNonZeroCols_size[1]);
  c2_f_loop_ub = c2_indicesNonZeroCols_size[0] * c2_indicesNonZeroCols_size[1] -
    1;
  for (c2_i6 = 0; c2_i6 <= c2_f_loop_ub; c2_i6++) {
    c2_indices->vector.data[c2_i6] = c2_indicesNonZeroCols_data[c2_i6];
  }

  c2_array_real_T_2D_Constructor(chartInstance, &c2_f);
  c2_array_real_T_2D_Constructor(chartInstance, &c2_b_indices);
  c2_st.site = &c2_n_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, &c2_b_indices,
    &c2_t_emlrtRTEI, c2_indices->size[0], c2_indices->size[1]);
  c2_g_loop_ub = c2_indices->size[0] * c2_indices->size[1] - 1;
  for (c2_i7 = 0; c2_i7 <= c2_g_loop_ub; c2_i7++) {
    c2_b_indices.vector.data[c2_i7] = (real_T)c2_indices->vector.data[c2_i7];
  }

  c2_array_real_T_2D_Constructor(chartInstance, &c2_e_x);
  c2_st.site = &c2_n_emlrtRSI;
  c2_b_bsxfun(chartInstance, &c2_st, c2_b_x_data, c2_x_size, &c2_b_indices,
              &c2_e_x);
  c2_array_real_T_2D_Destructor(chartInstance, &c2_b_indices);
  c2_b_scale = c2_scale;
  if (c2_b_scale < 1.0) {
    c2_h_a = c2_b_scale;
    c2_i8 = c2_e_x.size[0] * c2_e_x.size[1];
    c2_i9 = c2_i8;
    c2_i_loop_ub = c2_i9 - 1;
    for (c2_i11 = 0; c2_i11 <= c2_i_loop_ub; c2_i11++) {
      c2_e_x.vector.data[c2_i11] *= c2_h_a;
    }
  }

  c2_tmp_size[0] = c2_e_x.size[0];
  c2_tmp_size[1] = c2_e_x.size[1];
  c2_h_loop_ub = c2_e_x.size[0] * c2_e_x.size[1] - 1;
  for (c2_i10 = 0; c2_i10 <= c2_h_loop_ub; c2_i10++) {
    c2_tmp_data[c2_i10] = (c2_e_x.vector.data[c2_i10] >= -1.0);
  }

  c2_j_loop_ub = c2_e_x.size[0] * c2_e_x.size[1] - 1;
  for (c2_i12 = 0; c2_i12 <= c2_j_loop_ub; c2_i12++) {
    c2_b_tmp_data[c2_i12] = (c2_e_x.vector.data[c2_i12] < 0.0);
  }

  c2_i13 = c2_tmp_size[0] * c2_tmp_size[1];
  c2_i14 = c2_i13;
  c2_k_loop_ub = c2_i14 - 1;
  for (c2_i15 = 0; c2_i15 <= c2_k_loop_ub; c2_i15++) {
    c2_tmp_data[c2_i15] = (c2_tmp_data[c2_i15] && c2_b_tmp_data[c2_i15]);
  }

  c2_b_tmp_size[0] = c2_e_x.size[0];
  c2_b_tmp_size[1] = c2_e_x.size[1];
  c2_l_loop_ub = c2_e_x.size[0] * c2_e_x.size[1] - 1;
  for (c2_i16 = 0; c2_i16 <= c2_l_loop_ub; c2_i16++) {
    c2_b_tmp_data[c2_i16] = (c2_e_x.vector.data[c2_i16] >= 0.0);
  }

  c2_m_loop_ub = c2_e_x.size[0] * c2_e_x.size[1] - 1;
  for (c2_i17 = 0; c2_i17 <= c2_m_loop_ub; c2_i17++) {
    c2_c_tmp_data[c2_i17] = (c2_e_x.vector.data[c2_i17] <= 1.0);
  }

  c2_i18 = c2_b_tmp_size[0] * c2_b_tmp_size[1];
  c2_i19 = c2_i18;
  c2_n_loop_ub = c2_i19 - 1;
  for (c2_i20 = 0; c2_i20 <= c2_n_loop_ub; c2_i20++) {
    c2_b_tmp_data[c2_i20] = (c2_b_tmp_data[c2_i20] && c2_c_tmp_data[c2_i20]);
  }

  c2_array_real_T_2D_SetSize(chartInstance, c2_sp, &c2_f, &c2_y_emlrtRTEI,
    c2_e_x.size[0], c2_e_x.size[1]);
  c2_o_loop_ub = c2_e_x.size[0] * c2_e_x.size[1] - 1;
  for (c2_i21 = 0; c2_i21 <= c2_o_loop_ub; c2_i21++) {
    c2_f.vector.data[c2_i21] = (c2_e_x.vector.data[c2_i21] + 1.0) * (real_T)
      c2_tmp_data[c2_i21];
  }

  c2_i22 = c2_e_x.size[0] * c2_e_x.size[1];
  c2_i23 = c2_i22;
  c2_p_loop_ub = c2_i23 - 1;
  for (c2_i24 = 0; c2_i24 <= c2_p_loop_ub; c2_i24++) {
    c2_e_x.vector.data[c2_i24] = (1.0 - c2_e_x.vector.data[c2_i24]) * (real_T)
      c2_b_tmp_data[c2_i24];
  }

  c2_i25 = c2_f.size[0] * c2_f.size[1];
  c2_i26 = c2_i25;
  c2_q_loop_ub = c2_i26 - 1;
  for (c2_i27 = 0; c2_i27 <= c2_q_loop_ub; c2_i27++) {
    c2_f.vector.data[c2_i27] += c2_e_x.vector.data[c2_i27];
  }

  if (c2_b_scale < 1.0) {
    c2_i_a = c2_b_scale;
    c2_i28 = c2_f.size[0] * c2_f.size[1];
    c2_i29 = c2_i28;
    c2_s_loop_ub = c2_i29 - 1;
    for (c2_i31 = 0; c2_i31 <= c2_s_loop_ub; c2_i31++) {
      c2_f.vector.data[c2_i31] *= c2_i_a;
    }
  }

  c2_st.site = &c2_n_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_weights, &c2_ab_emlrtRTEI,
    c2_f.size[0], c2_f.size[1]);
  c2_r_loop_ub = c2_f.size[0] * c2_f.size[1] - 1;
  for (c2_i30 = 0; c2_i30 <= c2_r_loop_ub; c2_i30++) {
    c2_weights->vector.data[c2_i30] = c2_f.vector.data[c2_i30];
  }

  c2_array_real_T_2D_Destructor(chartInstance, &c2_f);
  c2_sum(chartInstance, c2_weights, c2_b_x_data, c2_x_size);
  c2_st.site = &c2_o_emlrtRSI;
  c2_c_bsxfun(chartInstance, &c2_st, c2_weights, c2_b_x_data, c2_x_size, &c2_e_x);
  c2_st.site = &c2_o_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_weights, &c2_bb_emlrtRTEI,
    c2_e_x.size[0], c2_e_x.size[1]);
  c2_t_loop_ub = c2_e_x.size[0] * c2_e_x.size[1] - 1;
  for (c2_i32 = 0; c2_i32 <= c2_t_loop_ub; c2_i32++) {
    c2_weights->vector.data[c2_i32] = c2_e_x.vector.data[c2_i32];
  }

  c2_aux[0] = 1;
  c2_aux[720] = 720;
  for (c2_b_i = 0; c2_b_i < 719; c2_b_i++) {
    c2_aux[c2_b_i + 1] = c2_aux[c2_b_i] + 1;
    c2_aux[c2_b_i + 721] = c2_aux[c2_b_i + 720] - 1;
  }

  c2_d1 = (real_T)(c2_indices->size[0] * c2_indices->size[1]);
  c2_i33 = (int32_T)c2_d1;
  for (c2_c_i = 0; c2_c_i < c2_i33; c2_c_i++) {
    c2_d_i = (real_T)c2_c_i + 1.0;
    c2_oldIdx = (real_T)c2_indices->vector.data[(int32_T)c2_d_i - 1];
    c2_f_x = c2_oldIdx - 1.0;
    c2_j_a = c2_f_x;
    c2_g_x = c2_j_a;
    c2_h_x = c2_g_x;
    if (c2_h_x == 0.0) {
      c2_d_k = 0.0;
    } else {
      c2_d_k = muDoubleScalarRem(c2_h_x, 1440.0);
      c2_rEQ0 = (c2_d_k == 0.0);
      if (c2_rEQ0) {
        c2_d_k = 0.0;
      } else if (c2_d_k < 0.0) {
        c2_d_k += 1440.0;
      }
    }

    c2_k_a = c2_d_k;
    c2_c = (int32_T)c2_k_a;
    c2_indices->vector.data[(int32_T)c2_d_i - 1] = c2_aux[c2_c];
  }

  c2_st.site = &c2_p_emlrtRSI;
  c2_any(chartInstance, &c2_st, c2_weights, c2_copyCols_data, c2_copyCols_size);
  c2_end = c2_copyCols_size[1];
  c2_trueCount = 0;
  for (c2_e_i = 0; c2_e_i < c2_end; c2_e_i++) {
    if (c2_copyCols_data[c2_e_i]) {
      c2_trueCount++;
    }
  }

  c2_c_tmp_size[1] = c2_trueCount;
  c2_partialTrueCount = 0;
  for (c2_f_i = 0; c2_f_i < c2_end; c2_f_i++) {
    if (c2_copyCols_data[c2_f_i]) {
      c2_d_tmp_data[c2_partialTrueCount] = c2_f_i;
      c2_partialTrueCount++;
    }
  }

  c2_st.site = &c2_kb_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, &c2_e_x, &c2_db_emlrtRTEI,
    c2_weights->size[0], c2_c_tmp_size[1]);
  c2_u_loop_ub = c2_c_tmp_size[1] - 1;
  for (c2_i34 = 0; c2_i34 <= c2_u_loop_ub; c2_i34++) {
    c2_v_loop_ub = c2_weights->size[0] - 1;
    for (c2_i35 = 0; c2_i35 <= c2_v_loop_ub; c2_i35++) {
      c2_e_x.vector.data[c2_i35 + c2_e_x.size[0] * c2_i34] =
        c2_weights->vector.data[c2_i35 + c2_weights->size[0] *
        c2_d_tmp_data[c2_i34]];
    }
  }

  c2_b_end = c2_copyCols_size[1];
  c2_b_trueCount = 0;
  for (c2_g_i = 0; c2_g_i < c2_b_end; c2_g_i++) {
    if (c2_copyCols_data[c2_g_i]) {
      c2_b_trueCount++;
    }
  }

  c2_d_tmp_size[1] = c2_b_trueCount;
  c2_b_partialTrueCount = 0;
  for (c2_h_i = 0; c2_h_i < c2_b_end; c2_h_i++) {
    if (c2_copyCols_data[c2_h_i]) {
      c2_e_tmp_data[c2_b_partialTrueCount] = c2_h_i;
      c2_b_partialTrueCount++;
    }
  }

  c2_indicesNonZeroCols_size[0] = c2_indices->size[0];
  c2_indicesNonZeroCols_size[1] = c2_d_tmp_size[1];
  c2_w_loop_ub = c2_d_tmp_size[1] - 1;
  for (c2_i36 = 0; c2_i36 <= c2_w_loop_ub; c2_i36++) {
    c2_x_loop_ub = c2_indices->size[0] - 1;
    for (c2_i37 = 0; c2_i37 <= c2_x_loop_ub; c2_i37++) {
      c2_indicesNonZeroCols_data[c2_i37 + c2_indicesNonZeroCols_size[0] * c2_i36]
        = c2_indices->vector.data[c2_i37 + c2_indices->size[0] *
        c2_e_tmp_data[c2_i36]];
    }
  }

  c2_st.site = &c2_jb_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_weights, &c2_fb_emlrtRTEI,
    c2_e_x.size[1], c2_e_x.size[0]);
  c2_y_loop_ub = c2_e_x.size[0] - 1;
  for (c2_i38 = 0; c2_i38 <= c2_y_loop_ub; c2_i38++) {
    c2_ab_loop_ub = c2_e_x.size[1] - 1;
    for (c2_i39 = 0; c2_i39 <= c2_ab_loop_ub; c2_i39++) {
      c2_weights->vector.data[c2_i39 + c2_weights->size[0] * c2_i38] =
        c2_e_x.vector.data[c2_i38 + c2_e_x.size[0] * c2_i39];
    }
  }

  c2_array_real_T_2D_Destructor(chartInstance, &c2_e_x);
  c2_st.site = &c2_mb_emlrtRSI;
  c2_array_int32_T_2D_SetSize(chartInstance, &c2_st, c2_indices,
    &c2_gb_emlrtRTEI, c2_indicesNonZeroCols_size[1], c2_indicesNonZeroCols_size
    [0]);
  c2_bb_loop_ub = c2_indicesNonZeroCols_size[0] - 1;
  for (c2_i40 = 0; c2_i40 <= c2_bb_loop_ub; c2_i40++) {
    c2_cb_loop_ub = c2_indicesNonZeroCols_size[1] - 1;
    for (c2_i41 = 0; c2_i41 <= c2_cb_loop_ub; c2_i41++) {
      c2_indices->vector.data[c2_i41 + c2_indices->size[0] * c2_i40] =
        c2_indicesNonZeroCols_data[c2_i40 + c2_indicesNonZeroCols_size[0] *
        c2_i41];
    }
  }
}

static void c2_check_forloop_overflow_error
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const
   emlrtStack *c2_sp)
{
  static char_T c2_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c2_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                false);
  sf_mex_call(c2_sp, &c2_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14, sf_mex_call
              (c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c2_sp, NULL,
    "message", 1U, 2U, 14, c2_b_y, 14, c2_c_y)));
}

static void c2_bsxfun(SFc2_step2_compression_simulationInstanceStruct
                      *chartInstance, int32_T c2_a_data[], int32_T c2_a_size[1],
                      int32_T c2_b_data[], int32_T c2_b_size[2], int32_T
                      c2_c_data[], int32_T c2_c_size[2])
{
  int32_T c2_csz[2];
  int32_T c2_a;
  int32_T c2_b;
  int32_T c2_b_ic;
  int32_T c2_b_k;
  int32_T c2_b_szc;
  int32_T c2_b_varargin_1;
  int32_T c2_b_varargin_3;
  int32_T c2_c;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_ia;
  int32_T c2_ib;
  int32_T c2_ic;
  int32_T c2_k;
  int32_T c2_sak;
  int32_T c2_sbk;
  int32_T c2_szc;
  int32_T c2_varargin_1;
  int32_T c2_varargin_2;
  int32_T c2_varargin_3;
  int32_T c2_varargin_6;
  (void)chartInstance;
  c2_sak = c2_a_size[0];
  c2_csz[0] = c2_sak;
  c2_sbk = c2_b_size[1];
  c2_csz[1] = c2_sbk;
  c2_c_size[0] = c2_csz[0];
  c2_c_size[1] = c2_csz[1];
  c2_szc = c2_c_size[1] - 1;
  c2_i = c2_szc;
  for (c2_k = 0; c2_k <= c2_i; c2_k++) {
    c2_ib = c2_k;
    c2_ic = c2_k;
    c2_varargin_1 = c2_ic + 1;
    c2_varargin_3 = c2_ib + 1;
    c2_b_szc = c2_c_size[0] - 1;
    c2_i1 = c2_b_szc;
    for (c2_b_k = 0; c2_b_k <= c2_i1; c2_b_k++) {
      c2_ia = c2_b_k;
      c2_b_ic = c2_b_k;
      c2_b_varargin_1 = c2_b_ic;
      c2_varargin_2 = c2_varargin_1 - 1;
      c2_b_varargin_3 = c2_ia;
      c2_varargin_6 = c2_varargin_3 - 1;
      c2_a = c2_a_data[c2_b_varargin_3];
      c2_b = c2_b_data[c2_varargin_6];
      c2_c = c2_a + c2_b;
      c2_c_data[c2_b_varargin_1 + c2_c_size[0] * c2_varargin_2] = c2_c;
    }
  }
}

static void c2_b_bsxfun(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_a_data[], int32_T
  c2_a_size[1], c2_coder_array_real_T_2D *c2_b, c2_coder_array_real_T_2D *c2_c)
{
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_y = NULL;
  int32_T c2_csz[2];
  int32_T c2_b_ib;
  int32_T c2_b_ic;
  int32_T c2_b_k;
  int32_T c2_b_szc;
  int32_T c2_b_varargin_1;
  int32_T c2_b_varargin_3;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_ia;
  int32_T c2_ib;
  int32_T c2_ic;
  int32_T c2_k;
  int32_T c2_sak;
  int32_T c2_sbk;
  int32_T c2_sck;
  int32_T c2_szc;
  int32_T c2_varargin_1;
  int32_T c2_varargin_2;
  int32_T c2_varargin_3;
  int32_T c2_varargin_5;
  int32_T c2_varargin_6;
  boolean_T c2_iscompatible;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_iscompatible = true;
  c2_sak = c2_a_size[0];
  c2_sbk = c2_b->size[0];
  if (c2_sak == c2_sbk) {
    c2_sck = c2_sak;
  } else {
    c2_iscompatible = false;
    if (c2_sbk < c2_sak) {
      c2_sck = c2_sbk;
    } else {
      c2_sck = c2_sak;
    }
  }

  c2_csz[0] = c2_sck;
  c2_sbk = c2_b->size[1];
  c2_csz[1] = c2_sbk;
  if (!c2_iscompatible) {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    sf_mex_call(c2_sp, &c2_b_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c2_sp, NULL, "message", 1U, 1U, 14, c2_b_y)));
  }

  c2_st.site = &c2_lb_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_c, &c2_hb_emlrtRTEI,
    c2_csz[0], c2_csz[1]);
  c2_szc = c2_c->size[1] - 1;
  c2_i = c2_szc;
  for (c2_k = 0; c2_k <= c2_i; c2_k++) {
    c2_ib = c2_k;
    c2_ic = c2_k;
    c2_varargin_1 = c2_ic + 1;
    c2_varargin_3 = c2_ib + 1;
    c2_b_szc = c2_c->size[0] - 1;
    c2_i1 = c2_b_szc;
    for (c2_b_k = 0; c2_b_k <= c2_i1; c2_b_k++) {
      c2_ia = c2_b_k;
      c2_b_ib = c2_b_k;
      c2_b_ic = c2_b_k;
      c2_b_varargin_1 = c2_b_ic;
      c2_varargin_2 = c2_varargin_1 - 1;
      c2_b_varargin_3 = c2_ia;
      c2_varargin_5 = c2_b_ib;
      c2_varargin_6 = c2_varargin_3 - 1;
      c2_c->vector.data[c2_b_varargin_1 + c2_c->size[0] * c2_varargin_2] =
        c2_a_data[c2_b_varargin_3] - c2_b->vector.data[c2_varargin_5 +
        c2_b->size[0] * c2_varargin_6];
    }
  }
}

static void c2_sum(SFc2_step2_compression_simulationInstanceStruct
                   *chartInstance, c2_coder_array_real_T_2D *c2_x, real_T
                   c2_y_data[], int32_T c2_y_size[1])
{
  real_T c2_sz[2];
  int32_T c2_b_vlen;
  int32_T c2_b_xj;
  int32_T c2_c_vlen;
  int32_T c2_c_xj;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_ix;
  int32_T c2_k;
  int32_T c2_vlen;
  int32_T c2_vstride;
  int32_T c2_xj;
  int32_T c2_xoffset;
  (void)chartInstance;
  c2_vlen = c2_x->size[1];
  c2_b_vlen = c2_vlen;
  c2_c_vlen = c2_b_vlen;
  c2_vstride = c2_x->size[0];
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_sz[c2_i] = (real_T)c2_x->size[c2_i];
  }

  c2_y_size[0] = (int32_T)c2_sz[0];
  c2_i1 = (uint16_T)c2_vstride;
  for (c2_xj = 0; c2_xj < c2_i1; c2_xj++) {
    c2_b_xj = c2_xj;
    c2_y_data[c2_b_xj] = c2_x->vector.data[c2_b_xj];
  }

  for (c2_k = 2; c2_k <= c2_c_vlen; c2_k++) {
    c2_xoffset = (c2_k - 1) * c2_vstride;
    c2_i2 = (uint16_T)c2_vstride;
    for (c2_c_xj = 0; c2_c_xj < c2_i2; c2_c_xj++) {
      c2_b_xj = c2_c_xj;
      c2_ix = c2_xoffset + c2_b_xj;
      c2_y_data[c2_b_xj] += c2_x->vector.data[c2_ix];
    }
  }
}

static void c2_c_bsxfun(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_a,
  real_T c2_b_data[], int32_T c2_b_size[1], c2_coder_array_real_T_2D *c2_c)
{
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_y = NULL;
  int32_T c2_csz[2];
  int32_T c2_b_ia;
  int32_T c2_b_ic;
  int32_T c2_b_k;
  int32_T c2_b_szc;
  int32_T c2_b_varargin_1;
  int32_T c2_b_varargin_2;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_ia;
  int32_T c2_ib;
  int32_T c2_ic;
  int32_T c2_k;
  int32_T c2_sak;
  int32_T c2_sbk;
  int32_T c2_sck;
  int32_T c2_szc;
  int32_T c2_varargin_1;
  int32_T c2_varargin_2;
  int32_T c2_varargin_3;
  int32_T c2_varargin_4;
  int32_T c2_varargin_5;
  boolean_T c2_iscompatible;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_iscompatible = true;
  c2_sak = c2_a->size[0];
  c2_sbk = c2_b_size[0];
  if (c2_sak == c2_sbk) {
    c2_sck = c2_sak;
  } else {
    c2_iscompatible = false;
    if (c2_sbk < c2_sak) {
      c2_sck = c2_sbk;
    } else {
      c2_sck = c2_sak;
    }
  }

  c2_csz[0] = c2_sck;
  c2_sak = c2_a->size[1];
  c2_csz[1] = c2_sak;
  if (!c2_iscompatible) {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    sf_mex_call(c2_sp, &c2_b_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c2_sp, NULL, "message", 1U, 1U, 14, c2_b_y)));
  }

  c2_st.site = &c2_lb_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_c, &c2_hb_emlrtRTEI,
    c2_csz[0], c2_csz[1]);
  c2_szc = c2_c->size[1] - 1;
  c2_i = c2_szc;
  for (c2_k = 0; c2_k <= c2_i; c2_k++) {
    c2_ia = c2_k;
    c2_ic = c2_k;
    c2_varargin_1 = c2_ic + 1;
    c2_varargin_2 = c2_ia + 1;
    c2_b_szc = c2_c->size[0] - 1;
    c2_i1 = c2_b_szc;
    for (c2_b_k = 0; c2_b_k <= c2_i1; c2_b_k++) {
      c2_b_ia = c2_b_k;
      c2_ib = c2_b_k;
      c2_b_ic = c2_b_k;
      c2_b_varargin_1 = c2_b_ic;
      c2_b_varargin_2 = c2_varargin_1 - 1;
      c2_varargin_3 = c2_b_ia;
      c2_varargin_4 = c2_varargin_2 - 1;
      c2_varargin_5 = c2_ib;
      c2_c->vector.data[c2_b_varargin_1 + c2_c->size[0] * c2_b_varargin_2] =
        c2_a->vector.data[c2_varargin_3 + c2_a->size[0] * c2_varargin_4] /
        c2_b_data[c2_varargin_5];
    }
  }
}

static void c2_any(SFc2_step2_compression_simulationInstanceStruct
                   *chartInstance, const emlrtStack *c2_sp,
                   c2_coder_array_real_T_2D *c2_x, boolean_T c2_y_data[],
                   int32_T c2_y_size[2])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_outsize[2];
  real_T c2_a;
  real_T c2_b_x;
  real_T c2_vlen;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_i;
  int32_T c2_b_i1;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_d_a;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_g_a;
  int32_T c2_h_a;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_loop_ub;
  int32_T c2_npages;
  int32_T c2_vspread;
  boolean_T c2_d_b;
  boolean_T c2_e_b;
  boolean_T c2_exitg1;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_q_emlrtRSI;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_outsize[c2_i] = (real_T)c2_x->size[c2_i];
  }

  c2_y_size[0] = 1;
  c2_y_size[1] = (int32_T)c2_outsize[1];
  c2_loop_ub = (int32_T)c2_outsize[1] - 1;
  if (c2_loop_ub >= 0) {
    memset(&c2_y_data[0], 0, (uint32_T)(c2_loop_ub + 1) * sizeof(boolean_T));
  }

  c2_vlen = (real_T)c2_x->size[0];
  c2_a = c2_vlen;
  c2_c = (int32_T)c2_a;
  c2_b_a = c2_c - 1;
  c2_vspread = c2_b_a;
  c2_npages = c2_x->size[1];
  c2_i2 = 0;
  c2_iy = -1;
  c2_i1 = (uint8_T)c2_npages;
  for (c2_b_i = 0; c2_b_i < c2_i1; c2_b_i++) {
    c2_b_i1 = c2_i2;
    c2_c_a = c2_i2;
    c2_b = c2_vspread;
    c2_i2 = c2_c_a + c2_b;
    c2_d_a = c2_b_i1 + 1;
    c2_b_i1 = c2_d_a;
    c2_e_a = c2_i2 + 1;
    c2_i2 = c2_e_a;
    c2_f_a = c2_iy + 1;
    c2_iy = c2_f_a;
    c2_b_st.site = &c2_r_emlrtRSI;
    c2_g_a = c2_b_i1;
    c2_b_b = c2_i2;
    c2_h_a = c2_g_a;
    c2_c_b = c2_b_b;
    if (c2_h_a > c2_c_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_c_b > 2147483646);
    }

    if (c2_overflow) {
      c2_c_st.site = &c2_s_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_c_st);
    }

    c2_ix = c2_b_i1 - 1;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_ix + 1 <= c2_i2)) {
      if (c2_x->vector.data[c2_ix] == 0.0) {
        c2_d_b = true;
      } else {
        c2_b_x = c2_x->vector.data[c2_ix];
        c2_e_b = muDoubleScalarIsNaN(c2_b_x);
        if (c2_e_b) {
          c2_d_b = true;
        } else {
          c2_d_b = false;
        }
      }

      if (!c2_d_b) {
        c2_y_data[c2_iy] = true;
        c2_exitg1 = true;
      } else {
        c2_ix++;
      }
    }
  }
}

static void c2_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_in_[921600],
  c2_coder_array_real_T_2D *c2_weights, int32_T c2_indices_data[],
  c2_coder_array_real_T_2D *c2_out_)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_inCol[720];
  real_T c2_outSize[2];
  real_T c2_b_inCInd;
  real_T c2_b_outRInd;
  real_T c2_b_out_length;
  real_T c2_d;
  real_T c2_ndx;
  real_T c2_out_length;
  real_T c2_sumVal1;
  real_T c2_varargin_2;
  real_T c2_x;
  real_T c2_y;
  int32_T c2_b_outSize[2];
  int32_T c2_a;
  int32_T c2_c_inCInd;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_inCInd;
  int32_T c2_k;
  int32_T c2_linearInds;
  int32_T c2_outRInd;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_out_length = (real_T)c2_weights->size[1];
  c2_outSize[0] = c2_out_length;
  c2_st.site = &c2_ib_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_out_, &c2_kb_emlrtRTEI,
    (int32_T)c2_outSize[0], 1280);
  c2_st.site = &c2_t_emlrtRSI;
  c2_b_out_length = c2_out_length;
  for (c2_inCInd = 0; c2_inCInd < 1280; c2_inCInd++) {
    c2_b_inCInd = (real_T)c2_inCInd + 1.0;
    c2_c_inCInd = (int32_T)c2_b_inCInd - 1;
    for (c2_i = 0; c2_i < 720; c2_i++) {
      c2_inCol[c2_i] = c2_in_[c2_i + 720 * c2_c_inCInd];
    }

    c2_i1 = (int32_T)c2_b_out_length;
    for (c2_outRInd = 0; c2_outRInd < c2_i1; c2_outRInd++) {
      c2_b_outRInd = (real_T)c2_outRInd + 1.0;
      c2_sumVal1 = 0.0;
      c2_b_st.site = &c2_u_emlrtRSI;
      for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
        c2_outSize[c2_i2] = (real_T)c2_weights->size[c2_i2];
      }

      c2_varargin_2 = c2_b_outRInd;
      for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
        c2_b_outSize[c2_i3] = (int32_T)c2_outSize[c2_i3];
      }

      c2_c_st.site = &c2_v_emlrtRSI;
      c2_ndx = (real_T)c2_sub2ind(chartInstance, &c2_c_st, c2_b_outSize,
        c2_varargin_2);
      c2_linearInds = (int32_T)c2_ndx - 1;
      c2_d = (real_T)c2_weights->size[0];
      c2_i4 = (int32_T)c2_d;
      for (c2_k = 0; c2_k < c2_i4; c2_k++) {
        c2_sumVal1 += c2_weights->vector.data[c2_linearInds] *
          c2_inCol[c2_indices_data[c2_linearInds] - 1];
        c2_a = c2_linearInds + 1;
        c2_linearInds = c2_a;
      }

      c2_x = c2_sumVal1;
      c2_y = c2_x;
      c2_out_->vector.data[((int32_T)c2_b_outRInd + c2_out_->size[0] * ((int32_T)
        c2_b_inCInd - 1)) - 1] = c2_y;
    }
  }
}

static int32_T c2_sub2ind(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, int32_T c2_siz[2], real_T
  c2_varargin_2)
{
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_x;
  int32_T c2_b_hi;
  int32_T c2_c_hi;
  int32_T c2_hi;
  int32_T c2_psiz;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b_p;
  boolean_T c2_p;
  (void)chartInstance;
  c2_hi = c2_siz[0];
  c2_b_hi = c2_hi;
  if (c2_b_hi >= 1) {
    c2_b = true;
  } else {
    c2_b = false;
  }

  if (!c2_b) {
    c2_p = false;
  } else {
    c2_p = true;
  }

  if (!c2_p) {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c2_sp, &c2_c_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c2_sp, NULL, "message", 1U, 1U, 14, c2_b_y)));
  }

  c2_hi = c2_siz[1];
  c2_x = c2_varargin_2;
  c2_c_hi = c2_hi;
  if (c2_x <= (real_T)c2_c_hi) {
    c2_b1 = true;
  } else {
    c2_b1 = false;
  }

  if (!c2_b1) {
    c2_b_p = false;
  } else {
    c2_b_p = true;
  }

  if (!c2_b_p) {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c2_sp, &c2_c_emlrtMCI, "error", 0U, 2U, 14, c2_c_y, 14,
                sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c2_sp, NULL, "message", 1U, 1U, 14, c2_d_y)));
  }

  c2_psiz = c2_siz[0];
  return 1 + c2_psiz * ((int32_T)c2_varargin_2 - 1);
}

static void c2_b_contributions(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_out_length, real_T c2_scale,
  real_T c2_kernel_width, c2_coder_array_real_T_2D *c2_weights,
  c2_coder_array_int32_T_2D *c2_indices)
{
  c2_coder_array_real_T_2D c2_b_indices;
  c2_coder_array_real_T_2D c2_e_x;
  c2_coder_array_real_T_2D c2_f;
  emlrtStack c2_st;
  real_T c2_b_x_data[1280];
  real_T c2_c_x_data[1280];
  real_T c2_y_data[1280];
  real_T c2_b;
  real_T c2_b_d;
  real_T c2_b_kernel_width;
  real_T c2_b_scale;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d_i;
  real_T c2_d_k;
  real_T c2_d_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_a;
  real_T c2_h_x;
  real_T c2_i_a;
  real_T c2_i_x;
  real_T c2_j_a;
  real_T c2_k_a;
  real_T c2_oldIdx;
  real_T c2_x;
  real_T c2_y;
  int32_T c2_indicesNonZeroCols_data[11520];
  int32_T c2_aux[2560];
  int32_T c2_left_data[1280];
  int32_T c2_b_y_data[9];
  int32_T c2_d_tmp_data[9];
  int32_T c2_e_tmp_data[9];
  int32_T c2_b_tmp_size[2];
  int32_T c2_b_y_size[2];
  int32_T c2_c_tmp_size[2];
  int32_T c2_copyCols_size[2];
  int32_T c2_d_tmp_size[2];
  int32_T c2_indicesNonZeroCols_size[2];
  int32_T c2_tmp_size[2];
  int32_T c2_y_size[2];
  int32_T c2_b_x_size[1];
  int32_T c2_left_size[1];
  int32_T c2_x_size[1];
  int32_T c2_P;
  int32_T c2_a;
  int32_T c2_ab_loop_ub;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_end;
  int32_T c2_b_i;
  int32_T c2_b_k;
  int32_T c2_b_loop_ub;
  int32_T c2_b_partialTrueCount;
  int32_T c2_b_trueCount;
  int32_T c2_bb_loop_ub;
  int32_T c2_bi;
  int32_T c2_bma;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_c_d;
  int32_T c2_c_i;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_cb_loop_ub;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_loop_ub;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_e_i;
  int32_T c2_e_loop_ub;
  int32_T c2_end;
  int32_T c2_f_a;
  int32_T c2_f_b;
  int32_T c2_f_i;
  int32_T c2_f_loop_ub;
  int32_T c2_g_a;
  int32_T c2_g_b;
  int32_T c2_g_i;
  int32_T c2_g_loop_ub;
  int32_T c2_h_i;
  int32_T c2_h_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i_loop_ub;
  int32_T c2_j_loop_ub;
  int32_T c2_k;
  int32_T c2_k_loop_ub;
  int32_T c2_l_loop_ub;
  int32_T c2_loop_ub;
  int32_T c2_m_loop_ub;
  int32_T c2_n;
  int32_T c2_n_loop_ub;
  int32_T c2_nm1;
  int32_T c2_nx;
  int32_T c2_o_loop_ub;
  int32_T c2_p_loop_ub;
  int32_T c2_partialTrueCount;
  int32_T c2_q_loop_ub;
  int32_T c2_r_loop_ub;
  int32_T c2_s_loop_ub;
  int32_T c2_span;
  int32_T c2_t_loop_ub;
  int32_T c2_trueCount;
  int32_T c2_u_loop_ub;
  int32_T c2_v_loop_ub;
  int32_T c2_w_loop_ub;
  int32_T c2_x_loop_ub;
  int32_T c2_y_loop_ub;
  int32_T c2_yk;
  boolean_T c2_b_tmp_data[11520];
  boolean_T c2_c_tmp_data[11520];
  boolean_T c2_tmp_data[11520];
  boolean_T c2_copyCols_data[9];
  boolean_T c2_h_b;
  boolean_T c2_rEQ0;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  if (c2_scale < 1.0) {
    c2_kernel_width = 2.0 / c2_scale;
  }

  c2_d = c2_out_length;
  c2_b = c2_d;
  c2_y_size[1] = (int32_T)(c2_b - 1.0) + 1;
  c2_loop_ub = (int32_T)(c2_b - 1.0);
  for (c2_i = 0; c2_i <= c2_loop_ub; c2_i++) {
    c2_y_data[c2_i] = 1.0 + (real_T)c2_i;
  }

  c2_x_size[0] = c2_y_size[1];
  c2_b_loop_ub = c2_y_size[1] - 1;
  for (c2_i1 = 0; c2_i1 <= c2_b_loop_ub; c2_i1++) {
    c2_b_x_data[c2_i1] = c2_y_data[c2_i1];
  }

  c2_b_d = 0.5 * (1.0 - 1.0 / c2_scale);
  c2_c_loop_ub = c2_x_size[0] - 1;
  for (c2_i2 = 0; c2_i2 <= c2_c_loop_ub; c2_i2++) {
    c2_b_x_data[c2_i2] = c2_b_x_data[c2_i2] / c2_scale + c2_b_d;
  }

  c2_b_kernel_width = c2_kernel_width / 2.0;
  c2_b_x_size[0] = c2_x_size[0];
  c2_d_loop_ub = c2_x_size[0] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_d_loop_ub; c2_i3++) {
    c2_c_x_data[c2_i3] = c2_b_x_data[c2_i3] - c2_b_kernel_width;
  }

  c2_nx = c2_b_x_size[0];
  c2_i4 = (uint16_T)c2_nx;
  for (c2_k = 0; c2_k < c2_i4; c2_k++) {
    c2_b_k = c2_k;
    c2_x = c2_c_x_data[c2_b_k];
    c2_b_x = c2_x;
    c2_b_x = muDoubleScalarFloor(c2_b_x);
    c2_c_x_data[c2_b_k] = c2_b_x;
  }

  c2_left_size[0] = c2_b_x_size[0];
  c2_e_loop_ub = c2_b_x_size[0] - 1;
  for (c2_i5 = 0; c2_i5 <= c2_e_loop_ub; c2_i5++) {
    c2_left_data[c2_i5] = (int32_T)c2_c_x_data[c2_i5];
  }

  c2_c_x = c2_kernel_width;
  c2_d_x = c2_c_x;
  c2_y = c2_d_x;
  c2_y = muDoubleScalarCeil(c2_y);
  c2_P = (int32_T)(c2_y + 2.0) - 1;
  c2_c_d = c2_P;
  c2_b_b = c2_c_d;
  c2_c_b = c2_b_b;
  c2_a = c2_c_b;
  c2_bi = c2_a;
  c2_d_b = c2_bi;
  c2_e_b = c2_d_b;
  c2_f_b = c2_e_b;
  c2_b_a = c2_f_b;
  c2_bma = c2_b_a;
  c2_c_a = c2_bma;
  c2_span = c2_c_a;
  c2_d_a = c2_span;
  c2_nm1 = (uint8_T)c2_d_a;
  c2_e_a = c2_nm1;
  c2_g_b = c2_e_a;
  c2_f_a = c2_g_b + 1;
  c2_n = c2_f_a;
  c2_b_y_size[0] = 1;
  c2_b_y_size[1] = c2_n;
  c2_b_y_data[0] = 0;
  c2_yk = 0;
  for (c2_c_k = 2; c2_c_k <= c2_n; c2_c_k++) {
    c2_g_a = c2_yk + 1;
    c2_yk = c2_g_a;
    c2_b_y_data[c2_c_k - 1] = c2_yk;
  }

  c2_bsxfun(chartInstance, c2_left_data, c2_left_size, c2_b_y_data, c2_b_y_size,
            c2_indicesNonZeroCols_data, c2_indicesNonZeroCols_size);
  c2_st.site = &c2_nb_emlrtRSI;
  c2_array_int32_T_2D_SetSize(chartInstance, &c2_st, c2_indices, &c2_s_emlrtRTEI,
    c2_indicesNonZeroCols_size[0], c2_indicesNonZeroCols_size[1]);
  c2_f_loop_ub = c2_indicesNonZeroCols_size[0] * c2_indicesNonZeroCols_size[1] -
    1;
  for (c2_i6 = 0; c2_i6 <= c2_f_loop_ub; c2_i6++) {
    c2_indices->vector.data[c2_i6] = c2_indicesNonZeroCols_data[c2_i6];
  }

  c2_array_real_T_2D_Constructor(chartInstance, &c2_f);
  c2_array_real_T_2D_Constructor(chartInstance, &c2_b_indices);
  c2_st.site = &c2_n_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, &c2_b_indices,
    &c2_t_emlrtRTEI, c2_indices->size[0], c2_indices->size[1]);
  c2_g_loop_ub = c2_indices->size[0] * c2_indices->size[1] - 1;
  for (c2_i7 = 0; c2_i7 <= c2_g_loop_ub; c2_i7++) {
    c2_b_indices.vector.data[c2_i7] = (real_T)c2_indices->vector.data[c2_i7];
  }

  c2_array_real_T_2D_Constructor(chartInstance, &c2_e_x);
  c2_st.site = &c2_n_emlrtRSI;
  c2_b_bsxfun(chartInstance, &c2_st, c2_b_x_data, c2_x_size, &c2_b_indices,
              &c2_e_x);
  c2_array_real_T_2D_Destructor(chartInstance, &c2_b_indices);
  c2_b_scale = c2_scale;
  if (c2_b_scale < 1.0) {
    c2_h_a = c2_b_scale;
    c2_i8 = c2_e_x.size[0] * c2_e_x.size[1];
    c2_i9 = c2_i8;
    c2_i_loop_ub = c2_i9 - 1;
    for (c2_i11 = 0; c2_i11 <= c2_i_loop_ub; c2_i11++) {
      c2_e_x.vector.data[c2_i11] *= c2_h_a;
    }
  }

  c2_tmp_size[0] = c2_e_x.size[0];
  c2_tmp_size[1] = c2_e_x.size[1];
  c2_h_loop_ub = c2_e_x.size[0] * c2_e_x.size[1] - 1;
  for (c2_i10 = 0; c2_i10 <= c2_h_loop_ub; c2_i10++) {
    c2_tmp_data[c2_i10] = (c2_e_x.vector.data[c2_i10] >= -1.0);
  }

  c2_j_loop_ub = c2_e_x.size[0] * c2_e_x.size[1] - 1;
  for (c2_i12 = 0; c2_i12 <= c2_j_loop_ub; c2_i12++) {
    c2_b_tmp_data[c2_i12] = (c2_e_x.vector.data[c2_i12] < 0.0);
  }

  c2_i13 = c2_tmp_size[0] * c2_tmp_size[1];
  c2_i14 = c2_i13;
  c2_k_loop_ub = c2_i14 - 1;
  for (c2_i15 = 0; c2_i15 <= c2_k_loop_ub; c2_i15++) {
    c2_tmp_data[c2_i15] = (c2_tmp_data[c2_i15] && c2_b_tmp_data[c2_i15]);
  }

  c2_b_tmp_size[0] = c2_e_x.size[0];
  c2_b_tmp_size[1] = c2_e_x.size[1];
  c2_l_loop_ub = c2_e_x.size[0] * c2_e_x.size[1] - 1;
  for (c2_i16 = 0; c2_i16 <= c2_l_loop_ub; c2_i16++) {
    c2_b_tmp_data[c2_i16] = (c2_e_x.vector.data[c2_i16] >= 0.0);
  }

  c2_m_loop_ub = c2_e_x.size[0] * c2_e_x.size[1] - 1;
  for (c2_i17 = 0; c2_i17 <= c2_m_loop_ub; c2_i17++) {
    c2_c_tmp_data[c2_i17] = (c2_e_x.vector.data[c2_i17] <= 1.0);
  }

  c2_i18 = c2_b_tmp_size[0] * c2_b_tmp_size[1];
  c2_i19 = c2_i18;
  c2_n_loop_ub = c2_i19 - 1;
  for (c2_i20 = 0; c2_i20 <= c2_n_loop_ub; c2_i20++) {
    c2_b_tmp_data[c2_i20] = (c2_b_tmp_data[c2_i20] && c2_c_tmp_data[c2_i20]);
  }

  c2_array_real_T_2D_SetSize(chartInstance, c2_sp, &c2_f, &c2_y_emlrtRTEI,
    c2_e_x.size[0], c2_e_x.size[1]);
  c2_o_loop_ub = c2_e_x.size[0] * c2_e_x.size[1] - 1;
  for (c2_i21 = 0; c2_i21 <= c2_o_loop_ub; c2_i21++) {
    c2_f.vector.data[c2_i21] = (c2_e_x.vector.data[c2_i21] + 1.0) * (real_T)
      c2_tmp_data[c2_i21];
  }

  c2_i22 = c2_e_x.size[0] * c2_e_x.size[1];
  c2_i23 = c2_i22;
  c2_p_loop_ub = c2_i23 - 1;
  for (c2_i24 = 0; c2_i24 <= c2_p_loop_ub; c2_i24++) {
    c2_e_x.vector.data[c2_i24] = (1.0 - c2_e_x.vector.data[c2_i24]) * (real_T)
      c2_b_tmp_data[c2_i24];
  }

  c2_i25 = c2_f.size[0] * c2_f.size[1];
  c2_i26 = c2_i25;
  c2_q_loop_ub = c2_i26 - 1;
  for (c2_i27 = 0; c2_i27 <= c2_q_loop_ub; c2_i27++) {
    c2_f.vector.data[c2_i27] += c2_e_x.vector.data[c2_i27];
  }

  if (c2_b_scale < 1.0) {
    c2_i_a = c2_b_scale;
    c2_i28 = c2_f.size[0] * c2_f.size[1];
    c2_i29 = c2_i28;
    c2_s_loop_ub = c2_i29 - 1;
    for (c2_i31 = 0; c2_i31 <= c2_s_loop_ub; c2_i31++) {
      c2_f.vector.data[c2_i31] *= c2_i_a;
    }
  }

  c2_st.site = &c2_n_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_weights, &c2_ab_emlrtRTEI,
    c2_f.size[0], c2_f.size[1]);
  c2_r_loop_ub = c2_f.size[0] * c2_f.size[1] - 1;
  for (c2_i30 = 0; c2_i30 <= c2_r_loop_ub; c2_i30++) {
    c2_weights->vector.data[c2_i30] = c2_f.vector.data[c2_i30];
  }

  c2_array_real_T_2D_Destructor(chartInstance, &c2_f);
  c2_sum(chartInstance, c2_weights, c2_b_x_data, c2_x_size);
  c2_st.site = &c2_o_emlrtRSI;
  c2_c_bsxfun(chartInstance, &c2_st, c2_weights, c2_b_x_data, c2_x_size, &c2_e_x);
  c2_st.site = &c2_o_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_weights, &c2_bb_emlrtRTEI,
    c2_e_x.size[0], c2_e_x.size[1]);
  c2_t_loop_ub = c2_e_x.size[0] * c2_e_x.size[1] - 1;
  for (c2_i32 = 0; c2_i32 <= c2_t_loop_ub; c2_i32++) {
    c2_weights->vector.data[c2_i32] = c2_e_x.vector.data[c2_i32];
  }

  c2_aux[0] = 1;
  c2_aux[1280] = 1280;
  for (c2_b_i = 0; c2_b_i < 1279; c2_b_i++) {
    c2_aux[c2_b_i + 1] = c2_aux[c2_b_i] + 1;
    c2_aux[c2_b_i + 1281] = c2_aux[c2_b_i + 1280] - 1;
  }

  c2_d1 = (real_T)(c2_indices->size[0] * c2_indices->size[1]);
  c2_i33 = (int32_T)c2_d1;
  for (c2_c_i = 0; c2_c_i < c2_i33; c2_c_i++) {
    c2_d_i = (real_T)c2_c_i + 1.0;
    c2_oldIdx = (real_T)c2_indices->vector.data[(int32_T)c2_d_i - 1];
    c2_f_x = c2_oldIdx - 1.0;
    c2_j_a = c2_f_x;
    c2_g_x = c2_j_a;
    c2_h_x = c2_g_x;
    c2_i_x = c2_h_x;
    c2_h_b = muDoubleScalarIsNaN(c2_i_x);
    if (c2_h_b) {
      c2_d_k = rtNaN;
    } else if (c2_h_x == 0.0) {
      c2_d_k = 0.0;
    } else {
      c2_d_k = muDoubleScalarRem(c2_h_x, 2560.0);
      c2_rEQ0 = (c2_d_k == 0.0);
      if (c2_rEQ0) {
        c2_d_k = 0.0;
      } else if (c2_d_k < 0.0) {
        c2_d_k += 2560.0;
      }
    }

    c2_k_a = c2_d_k;
    c2_c = (int32_T)c2_k_a;
    c2_indices->vector.data[(int32_T)c2_d_i - 1] = c2_aux[c2_c];
  }

  c2_st.site = &c2_p_emlrtRSI;
  c2_any(chartInstance, &c2_st, c2_weights, c2_copyCols_data, c2_copyCols_size);
  c2_end = c2_copyCols_size[1];
  c2_trueCount = 0;
  for (c2_e_i = 0; c2_e_i < c2_end; c2_e_i++) {
    if (c2_copyCols_data[c2_e_i]) {
      c2_trueCount++;
    }
  }

  c2_c_tmp_size[1] = c2_trueCount;
  c2_partialTrueCount = 0;
  for (c2_f_i = 0; c2_f_i < c2_end; c2_f_i++) {
    if (c2_copyCols_data[c2_f_i]) {
      c2_d_tmp_data[c2_partialTrueCount] = c2_f_i;
      c2_partialTrueCount++;
    }
  }

  c2_st.site = &c2_kb_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, &c2_e_x, &c2_db_emlrtRTEI,
    c2_weights->size[0], c2_c_tmp_size[1]);
  c2_u_loop_ub = c2_c_tmp_size[1] - 1;
  for (c2_i34 = 0; c2_i34 <= c2_u_loop_ub; c2_i34++) {
    c2_v_loop_ub = c2_weights->size[0] - 1;
    for (c2_i35 = 0; c2_i35 <= c2_v_loop_ub; c2_i35++) {
      c2_e_x.vector.data[c2_i35 + c2_e_x.size[0] * c2_i34] =
        c2_weights->vector.data[c2_i35 + c2_weights->size[0] *
        c2_d_tmp_data[c2_i34]];
    }
  }

  c2_b_end = c2_copyCols_size[1];
  c2_b_trueCount = 0;
  for (c2_g_i = 0; c2_g_i < c2_b_end; c2_g_i++) {
    if (c2_copyCols_data[c2_g_i]) {
      c2_b_trueCount++;
    }
  }

  c2_d_tmp_size[1] = c2_b_trueCount;
  c2_b_partialTrueCount = 0;
  for (c2_h_i = 0; c2_h_i < c2_b_end; c2_h_i++) {
    if (c2_copyCols_data[c2_h_i]) {
      c2_e_tmp_data[c2_b_partialTrueCount] = c2_h_i;
      c2_b_partialTrueCount++;
    }
  }

  c2_indicesNonZeroCols_size[0] = c2_indices->size[0];
  c2_indicesNonZeroCols_size[1] = c2_d_tmp_size[1];
  c2_w_loop_ub = c2_d_tmp_size[1] - 1;
  for (c2_i36 = 0; c2_i36 <= c2_w_loop_ub; c2_i36++) {
    c2_x_loop_ub = c2_indices->size[0] - 1;
    for (c2_i37 = 0; c2_i37 <= c2_x_loop_ub; c2_i37++) {
      c2_indicesNonZeroCols_data[c2_i37 + c2_indicesNonZeroCols_size[0] * c2_i36]
        = c2_indices->vector.data[c2_i37 + c2_indices->size[0] *
        c2_e_tmp_data[c2_i36]];
    }
  }

  c2_st.site = &c2_jb_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_weights, &c2_fb_emlrtRTEI,
    c2_e_x.size[1], c2_e_x.size[0]);
  c2_y_loop_ub = c2_e_x.size[0] - 1;
  for (c2_i38 = 0; c2_i38 <= c2_y_loop_ub; c2_i38++) {
    c2_ab_loop_ub = c2_e_x.size[1] - 1;
    for (c2_i39 = 0; c2_i39 <= c2_ab_loop_ub; c2_i39++) {
      c2_weights->vector.data[c2_i39 + c2_weights->size[0] * c2_i38] =
        c2_e_x.vector.data[c2_i38 + c2_e_x.size[0] * c2_i39];
    }
  }

  c2_array_real_T_2D_Destructor(chartInstance, &c2_e_x);
  c2_st.site = &c2_mb_emlrtRSI;
  c2_array_int32_T_2D_SetSize(chartInstance, &c2_st, c2_indices,
    &c2_gb_emlrtRTEI, c2_indicesNonZeroCols_size[1], c2_indicesNonZeroCols_size
    [0]);
  c2_bb_loop_ub = c2_indicesNonZeroCols_size[0] - 1;
  for (c2_i40 = 0; c2_i40 <= c2_bb_loop_ub; c2_i40++) {
    c2_cb_loop_ub = c2_indicesNonZeroCols_size[1] - 1;
    for (c2_i41 = 0; c2_i41 <= c2_cb_loop_ub; c2_i41++) {
      c2_indices->vector.data[c2_i41 + c2_indices->size[0] * c2_i40] =
        c2_indicesNonZeroCols_data[c2_i40 + c2_indicesNonZeroCols_size[0] *
        c2_i41];
    }
  }
}

static void c2_b_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_in_,
  c2_coder_array_real_T_2D *c2_weights, int32_T c2_indices_data[],
  c2_coder_array_real_T_2D *c2_out_)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_outSize[2];
  real_T c2_b;
  real_T c2_b_inRInd;
  real_T c2_b_outCInd;
  real_T c2_b_out_length;
  real_T c2_c_a;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_ndx;
  real_T c2_out_length;
  real_T c2_pixelValue;
  real_T c2_rowStart;
  real_T c2_sumVal1;
  real_T c2_varargin_1;
  real_T c2_varargin_2;
  real_T c2_x;
  real_T c2_y;
  int32_T c2_b_outSize[2];
  int32_T c2_c_outSize[2];
  int32_T c2_a;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_c;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_inRInd;
  int32_T c2_k;
  int32_T c2_linearInds;
  int32_T c2_outCInd;
  int32_T c2_pixelIndex;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_out_length = (real_T)c2_weights->size[1];
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_outSize[c2_i] = (real_T)c2_in_->size[c2_i];
  }

  c2_outSize[1] = c2_out_length;
  c2_st.site = &c2_ib_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_out_, &c2_kb_emlrtRTEI,
    (int32_T)c2_outSize[0], (int32_T)c2_outSize[1]);
  c2_st.site = &c2_t_emlrtRSI;
  c2_b_out_length = c2_out_length;
  c2_d = (real_T)c2_in_->size[0];
  c2_i1 = (int32_T)c2_d;
  for (c2_inRInd = 0; c2_inRInd < c2_i1; c2_inRInd++) {
    c2_b_inRInd = (real_T)c2_inRInd + 1.0;
    c2_b_st.site = &c2_w_emlrtRSI;
    for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
      c2_outSize[c2_i2] = (real_T)c2_in_->size[c2_i2];
    }

    c2_varargin_1 = c2_b_inRInd;
    for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
      c2_b_outSize[c2_i3] = (int32_T)c2_outSize[c2_i3];
    }

    c2_c_st.site = &c2_v_emlrtRSI;
    c2_rowStart = (real_T)c2_b_sub2ind(chartInstance, &c2_c_st, c2_b_outSize,
      c2_varargin_1);
    c2_i4 = (int32_T)c2_b_out_length;
    for (c2_outCInd = 0; c2_outCInd < c2_i4; c2_outCInd++) {
      c2_b_outCInd = (real_T)c2_outCInd + 1.0;
      c2_sumVal1 = 0.0;
      c2_b_st.site = &c2_x_emlrtRSI;
      for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
        c2_outSize[c2_i5] = (real_T)c2_weights->size[c2_i5];
      }

      c2_varargin_2 = c2_b_outCInd;
      for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
        c2_c_outSize[c2_i6] = (int32_T)c2_outSize[c2_i6];
      }

      c2_c_st.site = &c2_v_emlrtRSI;
      c2_ndx = (real_T)c2_sub2ind(chartInstance, &c2_c_st, c2_c_outSize,
        c2_varargin_2);
      c2_linearInds = (int32_T)c2_ndx - 1;
      c2_d1 = (real_T)c2_weights->size[0];
      c2_i7 = (int32_T)c2_d1;
      for (c2_k = 0; c2_k < c2_i7; c2_k++) {
        c2_a = c2_indices_data[c2_linearInds] - 1;
        c2_c = c2_a;
        c2_b_a = c2_c;
        c2_b = (real_T)c2_in_->size[0];
        c2_b_c = c2_b_a * (int32_T)c2_b;
        c2_c_a = c2_rowStart;
        c2_b_b = c2_b_c;
        c2_pixelIndex = ((int32_T)c2_c_a + c2_b_b) - 1;
        c2_pixelValue = c2_in_->vector.data[c2_pixelIndex];
        c2_sumVal1 += c2_weights->vector.data[c2_linearInds] * c2_pixelValue;
        c2_linearInds++;
      }

      c2_x = c2_sumVal1;
      c2_y = c2_x;
      c2_out_->vector.data[((int32_T)c2_b_inRInd + c2_out_->size[0] * ((int32_T)
        c2_b_outCInd - 1)) - 1] = c2_y;
    }
  }
}

static int32_T c2_b_sub2ind(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, int32_T c2_siz[2], real_T
  c2_varargin_1)
{
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_x;
  int32_T c2_b_hi;
  int32_T c2_c_hi;
  int32_T c2_hi;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b_p;
  boolean_T c2_p;
  (void)chartInstance;
  c2_hi = c2_siz[0];
  c2_x = c2_varargin_1;
  c2_b_hi = c2_hi;
  if (c2_x <= (real_T)c2_b_hi) {
    c2_b = true;
  } else {
    c2_b = false;
  }

  if (!c2_b) {
    c2_p = false;
  } else {
    c2_p = true;
  }

  if (!c2_p) {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c2_sp, &c2_c_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c2_sp, NULL, "message", 1U, 1U, 14, c2_b_y)));
  }

  c2_hi = c2_siz[1];
  c2_c_hi = c2_hi;
  if (c2_c_hi >= 1) {
    c2_b1 = true;
  } else {
    c2_b1 = false;
  }

  if (!c2_b1) {
    c2_b_p = false;
  } else {
    c2_b_p = true;
  }

  if (!c2_b_p) {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c2_sp, &c2_c_emlrtMCI, "error", 0U, 2U, 14, c2_c_y, 14,
                sf_mex_call(c2_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c2_sp, NULL, "message", 1U, 1U, 14, c2_d_y)));
  }

  return (int32_T)c2_varargin_1;
}

static void c2_c_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, real_T c2_in_[921600],
  c2_coder_array_real_T_2D *c2_weights, int32_T c2_indices_data[],
  c2_coder_array_real_T_2D *c2_out_)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_outSize[2];
  real_T c2_b_inRInd;
  real_T c2_b_outCInd;
  real_T c2_b_out_length;
  real_T c2_b_varargin_1;
  real_T c2_b_x;
  real_T c2_c_a;
  real_T c2_c_y;
  real_T c2_d;
  real_T c2_ndx;
  real_T c2_out_length;
  real_T c2_pixelValue;
  real_T c2_rowStart;
  real_T c2_sumVal1;
  real_T c2_varargin_1;
  real_T c2_varargin_2;
  real_T c2_x;
  int32_T c2_b_outSize[2];
  int32_T c2_a;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_c;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_idx;
  int32_T c2_inRInd;
  int32_T c2_k;
  int32_T c2_linearInds;
  int32_T c2_outCInd;
  int32_T c2_pixelIndex;
  boolean_T c2_b;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_out_length = (real_T)c2_weights->size[1];
  c2_outSize[1] = c2_out_length;
  c2_st.site = &c2_ib_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_out_, &c2_kb_emlrtRTEI,
    720, (int32_T)c2_outSize[1]);
  c2_st.site = &c2_t_emlrtRSI;
  c2_b_out_length = c2_out_length;
  for (c2_inRInd = 0; c2_inRInd < 720; c2_inRInd++) {
    c2_b_inRInd = (real_T)c2_inRInd + 1.0;
    c2_b_st.site = &c2_w_emlrtRSI;
    c2_varargin_1 = c2_b_inRInd;
    c2_c_st.site = &c2_v_emlrtRSI;
    c2_b_varargin_1 = c2_varargin_1;
    c2_x = c2_b_varargin_1;
    if (c2_x <= 720.0) {
      c2_b = true;
    } else {
      c2_b = false;
    }

    if (!c2_b) {
      c2_p = false;
    } else {
      c2_p = true;
    }

    if (!c2_p) {
      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(&c2_c_st, &c2_c_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                  sf_mex_call(&c2_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c2_c_st, NULL, "message", 1U, 1U, 14, c2_b_y)));
    }

    c2_idx = (int32_T)c2_b_varargin_1;
    c2_rowStart = (real_T)c2_idx;
    c2_i = (int32_T)c2_b_out_length;
    for (c2_outCInd = 0; c2_outCInd < c2_i; c2_outCInd++) {
      c2_b_outCInd = (real_T)c2_outCInd + 1.0;
      c2_sumVal1 = 0.0;
      c2_b_st.site = &c2_x_emlrtRSI;
      for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
        c2_outSize[c2_i1] = (real_T)c2_weights->size[c2_i1];
      }

      c2_varargin_2 = c2_b_outCInd;
      for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
        c2_b_outSize[c2_i2] = (int32_T)c2_outSize[c2_i2];
      }

      c2_c_st.site = &c2_v_emlrtRSI;
      c2_ndx = (real_T)c2_sub2ind(chartInstance, &c2_c_st, c2_b_outSize,
        c2_varargin_2);
      c2_linearInds = (int32_T)c2_ndx - 1;
      c2_d = (real_T)c2_weights->size[0];
      c2_i3 = (int32_T)c2_d;
      for (c2_k = 0; c2_k < c2_i3; c2_k++) {
        c2_a = c2_indices_data[c2_linearInds] - 1;
        c2_c = c2_a;
        c2_b_a = c2_c;
        c2_b_c = c2_b_a * 720;
        c2_c_a = c2_rowStart;
        c2_b_b = c2_b_c;
        c2_pixelIndex = ((int32_T)c2_c_a + c2_b_b) - 1;
        c2_pixelValue = c2_in_[c2_pixelIndex];
        c2_sumVal1 += c2_weights->vector.data[c2_linearInds] * c2_pixelValue;
        c2_linearInds++;
      }

      c2_b_x = c2_sumVal1;
      c2_c_y = c2_b_x;
      c2_out_->vector.data[((int32_T)c2_b_inRInd + 720 * ((int32_T)c2_b_outCInd
        - 1)) - 1] = c2_c_y;
    }
  }
}

static void c2_d_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_in_,
  c2_coder_array_real_T_2D *c2_weights, int32_T c2_indices_data[],
  c2_coder_array_real_T_2D *c2_out_)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_inCol[720];
  real_T c2_outSize[2];
  real_T c2_b_inCInd;
  real_T c2_b_outRInd;
  real_T c2_b_out_length;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_ndx;
  real_T c2_out_length;
  real_T c2_sumVal1;
  real_T c2_varargin_2;
  real_T c2_x;
  real_T c2_y;
  int32_T c2_b_outSize[2];
  int32_T c2_a;
  int32_T c2_c_inCInd;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_inCInd;
  int32_T c2_k;
  int32_T c2_linearInds;
  int32_T c2_outRInd;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_out_length = (real_T)c2_weights->size[1];
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_outSize[c2_i] = (real_T)c2_in_->size[c2_i];
  }

  c2_outSize[0] = c2_out_length;
  c2_st.site = &c2_ib_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_out_, &c2_kb_emlrtRTEI,
    (int32_T)c2_outSize[0], (int32_T)c2_outSize[1]);
  c2_st.site = &c2_t_emlrtRSI;
  c2_b_out_length = c2_out_length;
  c2_d = (real_T)(720 * c2_in_->size[1]) / 720.0;
  c2_i1 = (int32_T)c2_d;
  for (c2_inCInd = 0; c2_inCInd < c2_i1; c2_inCInd++) {
    c2_b_inCInd = (real_T)c2_inCInd + 1.0;
    c2_c_inCInd = (int32_T)c2_b_inCInd - 1;
    for (c2_i2 = 0; c2_i2 < 720; c2_i2++) {
      c2_inCol[c2_i2] = c2_in_->vector.data[c2_i2 + 720 * c2_c_inCInd];
    }

    c2_i3 = (int32_T)c2_b_out_length;
    for (c2_outRInd = 0; c2_outRInd < c2_i3; c2_outRInd++) {
      c2_b_outRInd = (real_T)c2_outRInd + 1.0;
      c2_sumVal1 = 0.0;
      c2_b_st.site = &c2_u_emlrtRSI;
      for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
        c2_outSize[c2_i4] = (real_T)c2_weights->size[c2_i4];
      }

      c2_varargin_2 = c2_b_outRInd;
      for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
        c2_b_outSize[c2_i5] = (int32_T)c2_outSize[c2_i5];
      }

      c2_c_st.site = &c2_v_emlrtRSI;
      c2_ndx = (real_T)c2_sub2ind(chartInstance, &c2_c_st, c2_b_outSize,
        c2_varargin_2);
      c2_linearInds = (int32_T)c2_ndx - 1;
      c2_d1 = (real_T)c2_weights->size[0];
      c2_i6 = (int32_T)c2_d1;
      for (c2_k = 0; c2_k < c2_i6; c2_k++) {
        c2_sumVal1 += c2_weights->vector.data[c2_linearInds] *
          c2_inCol[c2_indices_data[c2_linearInds] - 1];
        c2_a = c2_linearInds + 1;
        c2_linearInds = c2_a;
      }

      c2_x = c2_sumVal1;
      c2_y = c2_x;
      c2_out_->vector.data[((int32_T)c2_b_outRInd + c2_out_->size[0] * ((int32_T)
        c2_b_inCInd - 1)) - 1] = c2_y;
    }
  }
}

static void c2_b_imresize(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_c_Ain,
  real_T c2_Bout[921600])
{
  c2_coder_array_real_T_2D c2_APartialResize;
  c2_coder_array_real_T_2D c2_b_APartialResize;
  emlrtStack c2_st;
  real_T c2_scale[2];
  real_T c2_d_Ain;
  real_T c2_e_Ain;
  int32_T c2_indices_data[7680];
  int32_T c2_b_indices_data[4320];
  int32_T c2_b_indices_size[2];
  int32_T c2_b_weights_size[2];
  int32_T c2_indices_size[2];
  int32_T c2_weights_size[2];
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_d_Ain = (real_T)c2_c_Ain->size[0];
  c2_e_Ain = (real_T)c2_c_Ain->size[1];
  c2_scale[0] = 720.0 / c2_d_Ain;
  c2_scale[1] = 1280.0 / c2_e_Ain;
  if (c2_scale[0] <= c2_scale[1]) {
    c2_st.site = &c2_f_emlrtRSI;
    c2_c_contributions(chartInstance, &c2_st, c2_c_Ain->size[0], c2_scale[0],
                       2.0, chartInstance->c2_b_weights_data, c2_b_weights_size,
                       c2_b_indices_data, c2_b_indices_size);
    c2_array_real_T_2D_Constructor(chartInstance, &c2_b_APartialResize);
    c2_st.site = &c2_g_emlrtRSI;
    c2_e_resizeAlongDim(chartInstance, &c2_st, c2_c_Ain,
                        chartInstance->c2_b_weights_data, c2_b_weights_size,
                        c2_b_indices_data, &c2_b_APartialResize);
    c2_st.site = &c2_h_emlrtRSI;
    c2_d_contributions(chartInstance, &c2_st, c2_c_Ain->size[1], c2_scale[1],
                       2.0, chartInstance->c2_weights_data, c2_weights_size,
                       c2_indices_data, c2_indices_size);
    c2_st.site = &c2_i_emlrtRSI;
    c2_f_resizeAlongDim(chartInstance, &c2_st, &c2_b_APartialResize,
                        chartInstance->c2_weights_data, c2_weights_size,
                        c2_indices_data, c2_Bout);
    c2_array_real_T_2D_Destructor(chartInstance, &c2_b_APartialResize);
  } else {
    c2_st.site = &c2_j_emlrtRSI;
    c2_d_contributions(chartInstance, &c2_st, c2_c_Ain->size[1], c2_scale[1],
                       2.0, chartInstance->c2_weights_data, c2_weights_size,
                       c2_indices_data, c2_indices_size);
    c2_array_real_T_2D_Constructor(chartInstance, &c2_APartialResize);
    c2_st.site = &c2_k_emlrtRSI;
    c2_g_resizeAlongDim(chartInstance, &c2_st, c2_c_Ain,
                        chartInstance->c2_weights_data, c2_weights_size,
                        c2_indices_data, &c2_APartialResize);
    c2_st.site = &c2_l_emlrtRSI;
    c2_c_contributions(chartInstance, &c2_st, c2_c_Ain->size[0], c2_scale[0],
                       2.0, chartInstance->c2_b_weights_data, c2_b_weights_size,
                       c2_b_indices_data, c2_b_indices_size);
    c2_st.site = &c2_m_emlrtRSI;
    c2_h_resizeAlongDim(chartInstance, &c2_st, &c2_APartialResize,
                        chartInstance->c2_b_weights_data, c2_b_weights_size,
                        c2_b_indices_data, c2_Bout);
    c2_array_real_T_2D_Destructor(chartInstance, &c2_APartialResize);
  }
}

static void c2_c_contributions(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, int32_T c2_in_length, real_T c2_scale,
  real_T c2_kernel_width, real_T c2_c_weights_data[], int32_T c2_weights_size[2],
  int32_T c2_indices_data[], int32_T c2_indices_size[2])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_st;
  real_T c2_b_f_data[4320];
  real_T c2_b_x_data[4320];
  real_T c2_u[720];
  real_T c2_x[720];
  real_T c2_outsize[2];
  real_T c2_b_kernel_width;
  real_T c2_b_scale;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d_i;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_i_a;
  real_T c2_j_a;
  real_T c2_k_k;
  real_T c2_l_a;
  real_T c2_oldIdx;
  real_T c2_y;
  int32_T c2_b_indices_data[4320];
  int32_T c2_indicesNonZeroCols_data[4320];
  int32_T c2_aux_data[2560];
  int32_T c2_left[720];
  int32_T c2_y_data[9];
  int32_T c2_b_data[6];
  int32_T c2_d_tmp_data[6];
  int32_T c2_e_tmp_data[6];
  int32_T c2_b_csz[2];
  int32_T c2_b_indices_size[2];
  int32_T c2_b_size[2];
  int32_T c2_b_tmp_size[2];
  int32_T c2_c_csz[2];
  int32_T c2_c_tmp_size[2];
  int32_T c2_copyCols_size[2];
  int32_T c2_csz[2];
  int32_T c2_d_tmp_size[2];
  int32_T c2_f_size[2];
  int32_T c2_indicesNonZeroCols_size[2];
  int32_T c2_tmp_size[2];
  int32_T c2_weightsNonZeroCols_size[2];
  int32_T c2_x_size[2];
  int32_T c2_y_size[2];
  int32_T c2_P;
  int32_T c2_a;
  int32_T c2_auxLength;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_d;
  int32_T c2_b_end;
  int32_T c2_b_i;
  int32_T c2_b_i1;
  int32_T c2_b_i2;
  int32_T c2_b_ia;
  int32_T c2_b_ib;
  int32_T c2_b_ic;
  int32_T c2_b_ix;
  int32_T c2_b_k;
  int32_T c2_b_loop_ub;
  int32_T c2_b_partialTrueCount;
  int32_T c2_b_sbk;
  int32_T c2_b_szc;
  int32_T c2_b_trueCount;
  int32_T c2_b_varargin_1;
  int32_T c2_b_varargin_2;
  int32_T c2_b_varargin_3;
  int32_T c2_b_varargin_5;
  int32_T c2_b_varargin_6;
  int32_T c2_b_vlen;
  int32_T c2_b_xj;
  int32_T c2_bi;
  int32_T c2_bma;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_c_i;
  int32_T c2_c_ia;
  int32_T c2_c_ib;
  int32_T c2_c_ic;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_c_szc;
  int32_T c2_c_varargin_1;
  int32_T c2_c_varargin_2;
  int32_T c2_c_varargin_3;
  int32_T c2_c_vlen;
  int32_T c2_c_xj;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_ia;
  int32_T c2_d_ib;
  int32_T c2_d_ic;
  int32_T c2_d_k;
  int32_T c2_d_loop_ub;
  int32_T c2_d_varargin_1;
  int32_T c2_d_varargin_2;
  int32_T c2_d_varargin_3;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_e_i;
  int32_T c2_e_ic;
  int32_T c2_e_k;
  int32_T c2_e_loop_ub;
  int32_T c2_e_varargin_1;
  int32_T c2_e_varargin_3;
  int32_T c2_end;
  int32_T c2_f_a;
  int32_T c2_f_b;
  int32_T c2_f_i;
  int32_T c2_f_ic;
  int32_T c2_f_k;
  int32_T c2_f_loop_ub;
  int32_T c2_f_varargin_1;
  int32_T c2_g_a;
  int32_T c2_g_b;
  int32_T c2_g_i;
  int32_T c2_g_k;
  int32_T c2_g_loop_ub;
  int32_T c2_h_a;
  int32_T c2_h_b;
  int32_T c2_h_i;
  int32_T c2_h_k;
  int32_T c2_h_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i_b;
  int32_T c2_i_i;
  int32_T c2_i_k;
  int32_T c2_i_loop_ub;
  int32_T c2_ia;
  int32_T c2_ib;
  int32_T c2_ic;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_j_k;
  int32_T c2_j_loop_ub;
  int32_T c2_k;
  int32_T c2_k_a;
  int32_T c2_k_loop_ub;
  int32_T c2_l_loop_ub;
  int32_T c2_loop_ub;
  int32_T c2_m_a;
  int32_T c2_m_loop_ub;
  int32_T c2_n;
  int32_T c2_n_a;
  int32_T c2_n_loop_ub;
  int32_T c2_nm1;
  int32_T c2_npages;
  int32_T c2_o_a;
  int32_T c2_o_loop_ub;
  int32_T c2_p_a;
  int32_T c2_p_loop_ub;
  int32_T c2_partialTrueCount;
  int32_T c2_q_a;
  int32_T c2_q_loop_ub;
  int32_T c2_r_a;
  int32_T c2_r_loop_ub;
  int32_T c2_s_loop_ub;
  int32_T c2_sak;
  int32_T c2_sbk;
  int32_T c2_span;
  int32_T c2_szc;
  int32_T c2_trueCount;
  int32_T c2_varargin_1;
  int32_T c2_varargin_2;
  int32_T c2_varargin_3;
  int32_T c2_varargin_4;
  int32_T c2_varargin_5;
  int32_T c2_varargin_6;
  int32_T c2_vlen;
  int32_T c2_xj;
  int32_T c2_xoffset;
  int32_T c2_yk;
  boolean_T c2_b_tmp_data[4320];
  boolean_T c2_c_tmp_data[4320];
  boolean_T c2_tmp_data[4320];
  boolean_T c2_copyCols_data[6];
  boolean_T c2_exitg1;
  boolean_T c2_j_b;
  boolean_T c2_k_b;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  if (c2_scale < 1.0) {
    c2_kernel_width = 2.0 / c2_scale;
  }

  c2_d = 0.5 * (1.0 - 1.0 / c2_scale);
  for (c2_i = 0; c2_i < 720; c2_i++) {
    c2_u[c2_i] = (1.0 + (real_T)c2_i) / c2_scale + c2_d;
  }

  c2_b_kernel_width = c2_kernel_width / 2.0;
  for (c2_i1 = 0; c2_i1 < 720; c2_i1++) {
    c2_x[c2_i1] = c2_u[c2_i1] - c2_b_kernel_width;
  }

  for (c2_k = 0; c2_k < 720; c2_k++) {
    c2_b_k = c2_k;
    c2_b_x = c2_x[c2_b_k];
    c2_d_x = c2_b_x;
    c2_d_x = muDoubleScalarFloor(c2_d_x);
    c2_x[c2_b_k] = c2_d_x;
  }

  for (c2_i2 = 0; c2_i2 < 720; c2_i2++) {
    c2_left[c2_i2] = (int32_T)c2_x[c2_i2];
  }

  c2_c_x = c2_kernel_width;
  c2_e_x = c2_c_x;
  c2_y = c2_e_x;
  c2_y = muDoubleScalarCeil(c2_y);
  c2_P = (int32_T)(c2_y + 2.0) - 1;
  c2_b_d = c2_P;
  c2_b = c2_b_d;
  c2_b_b = c2_b;
  c2_a = c2_b_b;
  c2_bi = c2_a;
  c2_c_b = c2_bi;
  c2_d_b = c2_c_b;
  c2_e_b = c2_d_b;
  c2_b_a = c2_e_b;
  c2_bma = c2_b_a;
  c2_c_a = c2_bma;
  c2_span = c2_c_a;
  c2_d_a = c2_span;
  c2_nm1 = (uint8_T)c2_d_a;
  c2_e_a = c2_nm1;
  c2_f_b = c2_e_a;
  c2_f_a = c2_f_b + 1;
  c2_n = c2_f_a;
  c2_y_size[1] = c2_n;
  c2_y_data[0] = 0;
  c2_yk = 0;
  for (c2_c_k = 2; c2_c_k <= c2_n; c2_c_k++) {
    c2_g_a = c2_yk + 1;
    c2_yk = c2_g_a;
    c2_y_data[c2_c_k - 1] = c2_yk;
  }

  c2_b_size[1] = c2_y_size[1];
  c2_loop_ub = c2_y_size[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_loop_ub; c2_i3++) {
    c2_b_data[c2_i3] = c2_y_data[c2_i3];
  }

  c2_sbk = c2_b_size[1];
  c2_csz[1] = c2_sbk;
  c2_b_indices_size[1] = c2_csz[1];
  c2_szc = c2_b_indices_size[1] - 1;
  c2_i4 = c2_szc;
  for (c2_d_k = 0; c2_d_k <= c2_i4; c2_d_k++) {
    c2_ib = c2_d_k;
    c2_ic = c2_d_k;
    c2_varargin_1 = c2_ic + 1;
    c2_varargin_3 = c2_ib + 1;
    for (c2_e_k = 0; c2_e_k < 720; c2_e_k++) {
      c2_ia = c2_e_k;
      c2_b_ic = c2_e_k;
      c2_b_varargin_1 = c2_b_ic;
      c2_varargin_2 = c2_varargin_1 - 1;
      c2_b_varargin_3 = c2_ia;
      c2_varargin_6 = c2_varargin_3 - 1;
      c2_h_a = c2_left[c2_b_varargin_3];
      c2_g_b = c2_b_data[c2_varargin_6];
      c2_c = c2_h_a + c2_g_b;
      c2_b_indices_data[c2_b_varargin_1 + 720 * c2_varargin_2] = c2_c;
    }
  }

  c2_weightsNonZeroCols_size[1] = c2_b_indices_size[1];
  c2_b_loop_ub = 720 * c2_b_indices_size[1] - 1;
  for (c2_i5 = 0; c2_i5 <= c2_b_loop_ub; c2_i5++) {
    chartInstance->c2_b_weightsNonZeroCols_data[c2_i5] = (real_T)
      c2_b_indices_data[c2_i5];
  }

  c2_b_sbk = c2_weightsNonZeroCols_size[1];
  c2_b_csz[1] = c2_b_sbk;
  c2_x_size[1] = c2_b_csz[1];
  c2_b_szc = c2_x_size[1] - 1;
  c2_i6 = c2_b_szc;
  for (c2_f_k = 0; c2_f_k <= c2_i6; c2_f_k++) {
    c2_b_ib = c2_f_k;
    c2_c_ic = c2_f_k;
    c2_c_varargin_1 = c2_c_ic + 1;
    c2_c_varargin_3 = c2_b_ib + 1;
    for (c2_g_k = 0; c2_g_k < 720; c2_g_k++) {
      c2_b_ia = c2_g_k;
      c2_c_ib = c2_g_k;
      c2_d_ic = c2_g_k;
      c2_d_varargin_1 = c2_d_ic;
      c2_b_varargin_2 = c2_c_varargin_1 - 1;
      c2_d_varargin_3 = c2_b_ia;
      c2_varargin_5 = c2_c_ib;
      c2_b_varargin_6 = c2_c_varargin_3 - 1;
      c2_b_x_data[c2_d_varargin_1 + 720 * c2_b_varargin_2] =
        c2_u[c2_d_varargin_3] - chartInstance->
        c2_b_weightsNonZeroCols_data[c2_varargin_5 + 720 * c2_b_varargin_6];
    }
  }

  c2_b_scale = c2_scale;
  if (c2_b_scale < 1.0) {
    c2_i_a = c2_b_scale;
    c2_i7 = 720 * c2_x_size[1];
    c2_i8 = c2_i7;
    c2_d_loop_ub = c2_i8 - 1;
    for (c2_i10 = 0; c2_i10 <= c2_d_loop_ub; c2_i10++) {
      c2_b_x_data[c2_i10] *= c2_i_a;
    }
  }

  c2_tmp_size[1] = c2_x_size[1];
  c2_c_loop_ub = 720 * c2_x_size[1] - 1;
  for (c2_i9 = 0; c2_i9 <= c2_c_loop_ub; c2_i9++) {
    c2_tmp_data[c2_i9] = (c2_b_x_data[c2_i9] >= -1.0);
  }

  c2_e_loop_ub = 720 * c2_x_size[1] - 1;
  for (c2_i11 = 0; c2_i11 <= c2_e_loop_ub; c2_i11++) {
    c2_b_tmp_data[c2_i11] = (c2_b_x_data[c2_i11] < 0.0);
  }

  c2_i12 = 720 * c2_tmp_size[1];
  c2_i13 = c2_i12;
  c2_f_loop_ub = c2_i13 - 1;
  for (c2_i14 = 0; c2_i14 <= c2_f_loop_ub; c2_i14++) {
    c2_tmp_data[c2_i14] = (c2_tmp_data[c2_i14] && c2_b_tmp_data[c2_i14]);
  }

  c2_b_tmp_size[1] = c2_x_size[1];
  c2_g_loop_ub = 720 * c2_x_size[1] - 1;
  for (c2_i15 = 0; c2_i15 <= c2_g_loop_ub; c2_i15++) {
    c2_b_tmp_data[c2_i15] = (c2_b_x_data[c2_i15] >= 0.0);
  }

  c2_h_loop_ub = 720 * c2_x_size[1] - 1;
  for (c2_i16 = 0; c2_i16 <= c2_h_loop_ub; c2_i16++) {
    c2_c_tmp_data[c2_i16] = (c2_b_x_data[c2_i16] <= 1.0);
  }

  c2_i17 = 720 * c2_b_tmp_size[1];
  c2_i18 = c2_i17;
  c2_i_loop_ub = c2_i18 - 1;
  for (c2_i19 = 0; c2_i19 <= c2_i_loop_ub; c2_i19++) {
    c2_b_tmp_data[c2_i19] = (c2_b_tmp_data[c2_i19] && c2_c_tmp_data[c2_i19]);
  }

  c2_f_size[1] = c2_x_size[1];
  c2_j_loop_ub = 720 * c2_x_size[1] - 1;
  for (c2_i20 = 0; c2_i20 <= c2_j_loop_ub; c2_i20++) {
    c2_b_f_data[c2_i20] = (c2_b_x_data[c2_i20] + 1.0) * (real_T)
      c2_tmp_data[c2_i20];
  }

  c2_i21 = 720 * c2_x_size[1];
  c2_i22 = c2_i21;
  c2_k_loop_ub = c2_i22 - 1;
  for (c2_i23 = 0; c2_i23 <= c2_k_loop_ub; c2_i23++) {
    c2_b_x_data[c2_i23] = (1.0 - c2_b_x_data[c2_i23]) * (real_T)
      c2_b_tmp_data[c2_i23];
  }

  c2_i24 = 720 * c2_f_size[1];
  c2_i25 = c2_i24;
  c2_l_loop_ub = c2_i25 - 1;
  for (c2_i26 = 0; c2_i26 <= c2_l_loop_ub; c2_i26++) {
    c2_b_f_data[c2_i26] += c2_b_x_data[c2_i26];
  }

  if (c2_b_scale < 1.0) {
    c2_j_a = c2_b_scale;
    c2_i27 = 720 * c2_f_size[1];
    c2_i28 = c2_i27;
    c2_m_loop_ub = c2_i28 - 1;
    for (c2_i29 = 0; c2_i29 <= c2_m_loop_ub; c2_i29++) {
      c2_b_f_data[c2_i29] *= c2_j_a;
    }
  }

  c2_vlen = c2_f_size[1];
  c2_b_vlen = c2_vlen;
  c2_c_vlen = c2_b_vlen;
  for (c2_xj = 0; c2_xj < 720; c2_xj++) {
    c2_b_xj = c2_xj;
    c2_u[c2_b_xj] = c2_b_f_data[c2_b_xj];
  }

  for (c2_h_k = 2; c2_h_k <= c2_c_vlen; c2_h_k++) {
    c2_xoffset = (c2_h_k - 1) * 720;
    for (c2_c_xj = 0; c2_c_xj < 720; c2_c_xj++) {
      c2_b_xj = c2_c_xj;
      c2_ix = c2_xoffset + c2_b_xj;
      c2_u[c2_b_xj] += c2_b_f_data[c2_ix];
    }
  }

  c2_weightsNonZeroCols_size[1] = c2_f_size[1];
  c2_n_loop_ub = 720 * c2_f_size[1] - 1;
  for (c2_i30 = 0; c2_i30 <= c2_n_loop_ub; c2_i30++) {
    chartInstance->c2_b_weightsNonZeroCols_data[c2_i30] = c2_b_f_data[c2_i30];
  }

  c2_sak = c2_weightsNonZeroCols_size[1];
  c2_c_csz[1] = c2_sak;
  c2_f_size[0] = 720;
  c2_f_size[1] = c2_c_csz[1];
  c2_c_szc = c2_f_size[1] - 1;
  c2_i31 = c2_c_szc;
  for (c2_i_k = 0; c2_i_k <= c2_i31; c2_i_k++) {
    c2_c_ia = c2_i_k;
    c2_e_ic = c2_i_k;
    c2_e_varargin_1 = c2_e_ic + 1;
    c2_c_varargin_2 = c2_c_ia + 1;
    for (c2_j_k = 0; c2_j_k < 720; c2_j_k++) {
      c2_d_ia = c2_j_k;
      c2_d_ib = c2_j_k;
      c2_f_ic = c2_j_k;
      c2_f_varargin_1 = c2_f_ic;
      c2_d_varargin_2 = c2_e_varargin_1 - 1;
      c2_e_varargin_3 = c2_d_ia;
      c2_varargin_4 = c2_c_varargin_2 - 1;
      c2_b_varargin_5 = c2_d_ib;
      c2_b_f_data[c2_f_varargin_1 + 720 * c2_d_varargin_2] =
        chartInstance->c2_b_weightsNonZeroCols_data[c2_e_varargin_3 + 720 *
        c2_varargin_4] / c2_u[c2_b_varargin_5];
    }
  }

  c2_k_a = c2_in_length;
  c2_auxLength = c2_k_a << 1;
  c2_aux_data[0] = 1;
  c2_aux_data[c2_in_length] = c2_in_length;
  for (c2_b_i = 2; c2_b_i <= c2_in_length; c2_b_i++) {
    c2_aux_data[c2_b_i - 1] = c2_aux_data[c2_b_i - 2] + 1;
    c2_aux_data[(c2_in_length + c2_b_i) - 1] = c2_aux_data[(c2_in_length +
      c2_b_i) - 2] - 1;
  }

  c2_d1 = (real_T)(720 * c2_b_indices_size[1]);
  c2_i32 = (int32_T)c2_d1;
  for (c2_c_i = 0; c2_c_i < c2_i32; c2_c_i++) {
    c2_d_i = (real_T)c2_c_i + 1.0;
    c2_oldIdx = (real_T)c2_b_indices_data[(int32_T)c2_d_i - 1];
    c2_k_k = c2_mod(chartInstance, c2_oldIdx - 1.0, (real_T)c2_auxLength);
    c2_l_a = c2_k_k;
    c2_b_c = (int32_T)c2_l_a;
    c2_b_indices_data[(int32_T)c2_d_i - 1] = c2_aux_data[c2_b_c];
  }

  c2_st.site = &c2_p_emlrtRSI;
  c2_b_st.site = &c2_q_emlrtRSI;
  for (c2_i33 = 0; c2_i33 < 2; c2_i33++) {
    c2_outsize[c2_i33] = (real_T)c2_f_size[c2_i33];
  }

  c2_copyCols_size[1] = (int32_T)c2_outsize[1];
  c2_o_loop_ub = (int32_T)c2_outsize[1] - 1;
  if (c2_o_loop_ub >= 0) {
    memset(&c2_copyCols_data[0], 0, (uint32_T)(c2_o_loop_ub + 1) * sizeof
           (boolean_T));
  }

  c2_npages = c2_f_size[1];
  c2_b_i2 = 0;
  c2_iy = -1;
  c2_i34 = (uint8_T)c2_npages;
  for (c2_e_i = 0; c2_e_i < c2_i34; c2_e_i++) {
    c2_b_i1 = c2_b_i2;
    c2_m_a = c2_b_i2 + 719;
    c2_b_i2 = c2_m_a;
    c2_n_a = c2_b_i1 + 1;
    c2_b_i1 = c2_n_a;
    c2_o_a = c2_b_i2 + 1;
    c2_b_i2 = c2_o_a;
    c2_p_a = c2_iy + 1;
    c2_iy = c2_p_a;
    c2_c_st.site = &c2_r_emlrtRSI;
    c2_q_a = c2_b_i1;
    c2_h_b = c2_b_i2;
    c2_r_a = c2_q_a;
    c2_i_b = c2_h_b;
    if (c2_r_a > c2_i_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_i_b > 2147483646);
    }

    if (c2_overflow) {
      c2_d_st.site = &c2_s_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_d_st);
    }

    c2_b_ix = c2_b_i1 - 1;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_b_ix + 1 <= c2_b_i2)) {
      if (c2_b_f_data[c2_b_ix] == 0.0) {
        c2_j_b = true;
      } else {
        c2_f_x = c2_b_f_data[c2_b_ix];
        c2_k_b = muDoubleScalarIsNaN(c2_f_x);
        if (c2_k_b) {
          c2_j_b = true;
        } else {
          c2_j_b = false;
        }
      }

      if (!c2_j_b) {
        c2_copyCols_data[c2_iy] = true;
        c2_exitg1 = true;
      } else {
        c2_b_ix++;
      }
    }
  }

  c2_end = c2_copyCols_size[1];
  c2_trueCount = 0;
  for (c2_f_i = 0; c2_f_i < c2_end; c2_f_i++) {
    if (c2_copyCols_data[c2_f_i]) {
      c2_trueCount++;
    }
  }

  c2_c_tmp_size[1] = c2_trueCount;
  c2_partialTrueCount = 0;
  for (c2_g_i = 0; c2_g_i < c2_end; c2_g_i++) {
    if (c2_copyCols_data[c2_g_i]) {
      c2_d_tmp_data[c2_partialTrueCount] = c2_g_i;
      c2_partialTrueCount++;
    }
  }

  c2_weightsNonZeroCols_size[1] = c2_c_tmp_size[1];
  c2_p_loop_ub = c2_c_tmp_size[1] - 1;
  for (c2_i35 = 0; c2_i35 <= c2_p_loop_ub; c2_i35++) {
    for (c2_i36 = 0; c2_i36 < 720; c2_i36++) {
      chartInstance->c2_b_weightsNonZeroCols_data[c2_i36 + 720 * c2_i35] =
        c2_b_f_data[c2_i36 + 720 * c2_d_tmp_data[c2_i35]];
    }
  }

  c2_b_end = c2_copyCols_size[1];
  c2_b_trueCount = 0;
  for (c2_h_i = 0; c2_h_i < c2_b_end; c2_h_i++) {
    if (c2_copyCols_data[c2_h_i]) {
      c2_b_trueCount++;
    }
  }

  c2_d_tmp_size[1] = c2_b_trueCount;
  c2_b_partialTrueCount = 0;
  for (c2_i_i = 0; c2_i_i < c2_b_end; c2_i_i++) {
    if (c2_copyCols_data[c2_i_i]) {
      c2_e_tmp_data[c2_b_partialTrueCount] = c2_i_i;
      c2_b_partialTrueCount++;
    }
  }

  c2_indicesNonZeroCols_size[1] = c2_d_tmp_size[1];
  c2_q_loop_ub = c2_d_tmp_size[1] - 1;
  for (c2_i37 = 0; c2_i37 <= c2_q_loop_ub; c2_i37++) {
    for (c2_i38 = 0; c2_i38 < 720; c2_i38++) {
      c2_indicesNonZeroCols_data[c2_i38 + 720 * c2_i37] =
        c2_b_indices_data[c2_i38 + 720 * c2_e_tmp_data[c2_i37]];
    }
  }

  c2_weights_size[0] = c2_weightsNonZeroCols_size[1];
  c2_weights_size[1] = 720;
  for (c2_i39 = 0; c2_i39 < 720; c2_i39++) {
    c2_r_loop_ub = c2_weightsNonZeroCols_size[1] - 1;
    for (c2_i40 = 0; c2_i40 <= c2_r_loop_ub; c2_i40++) {
      c2_c_weights_data[c2_i40 + c2_weights_size[0] * c2_i39] =
        chartInstance->c2_b_weightsNonZeroCols_data[c2_i39 + 720 * c2_i40];
    }
  }

  c2_indices_size[0] = c2_indicesNonZeroCols_size[1];
  c2_indices_size[1] = 720;
  for (c2_i41 = 0; c2_i41 < 720; c2_i41++) {
    c2_s_loop_ub = c2_indicesNonZeroCols_size[1] - 1;
    for (c2_i42 = 0; c2_i42 <= c2_s_loop_ub; c2_i42++) {
      c2_indices_data[c2_i42 + c2_indices_size[0] * c2_i41] =
        c2_indicesNonZeroCols_data[c2_i41 + 720 * c2_i42];
    }
  }
}

static real_T c2_mod(SFc2_step2_compression_simulationInstanceStruct
                     *chartInstance, real_T c2_x, real_T c2_y)
{
  real_T c2_a;
  real_T c2_b;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_r;
  boolean_T c2_b_b;
  boolean_T c2_c_b;
  boolean_T c2_rEQ0;
  (void)chartInstance;
  c2_a = c2_x;
  c2_b = c2_y;
  c2_b_x = c2_a;
  c2_b_y = c2_b;
  c2_c_x = c2_b_x;
  c2_c_y = c2_b_y;
  c2_d_x = c2_c_x;
  c2_b_b = muDoubleScalarIsNaN(c2_d_x);
  if (c2_b_b) {
    c2_r = rtNaN;
  } else {
    c2_e_x = c2_c_y;
    c2_c_b = muDoubleScalarIsNaN(c2_e_x);
    if (c2_c_b) {
      c2_r = rtNaN;
    } else if (c2_c_x == 0.0) {
      c2_r = 0.0;
    } else {
      c2_r = muDoubleScalarRem(c2_c_x, c2_c_y);
      c2_rEQ0 = (c2_r == 0.0);
      if (c2_rEQ0) {
        c2_r = 0.0;
      } else if (c2_r < 0.0) {
        c2_r += c2_c_y;
      }
    }
  }

  return c2_r;
}

static void c2_e_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_in_,
  real_T c2_c_weights_data[], int32_T c2_weights_size[2], int32_T
  c2_indices_data[], c2_coder_array_real_T_2D *c2_out_)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_inCol_data[1280];
  real_T c2_outSize[2];
  real_T c2_b_inCInd;
  real_T c2_b_outRInd;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_ndx;
  real_T c2_sumVal1;
  real_T c2_varargin_2;
  real_T c2_x;
  real_T c2_y;
  int32_T c2_b_outSize[2];
  int32_T c2_a;
  int32_T c2_c_inCInd;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_inCInd;
  int32_T c2_k;
  int32_T c2_linearInds;
  int32_T c2_loop_ub;
  int32_T c2_outRInd;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_outSize[c2_i] = (real_T)c2_in_->size[c2_i];
  }

  c2_st.site = &c2_ib_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_out_, &c2_kb_emlrtRTEI,
    720, (int32_T)c2_outSize[1]);
  c2_st.site = &c2_t_emlrtRSI;
  c2_d = (real_T)(c2_in_->size[0] * c2_in_->size[1]) / (real_T)c2_in_->size[0];
  c2_i1 = (int32_T)c2_d;
  for (c2_inCInd = 0; c2_inCInd < c2_i1; c2_inCInd++) {
    c2_b_inCInd = (real_T)c2_inCInd + 1.0;
    c2_c_inCInd = (int32_T)c2_b_inCInd - 1;
    c2_loop_ub = c2_in_->size[0] - 1;
    for (c2_i2 = 0; c2_i2 <= c2_loop_ub; c2_i2++) {
      c2_inCol_data[c2_i2] = c2_in_->vector.data[c2_i2 + c2_in_->size[0] *
        c2_c_inCInd];
    }

    for (c2_outRInd = 0; c2_outRInd < 720; c2_outRInd++) {
      c2_b_outRInd = (real_T)c2_outRInd + 1.0;
      c2_sumVal1 = 0.0;
      c2_b_st.site = &c2_u_emlrtRSI;
      for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
        c2_outSize[c2_i3] = (real_T)c2_weights_size[c2_i3];
      }

      c2_varargin_2 = c2_b_outRInd;
      for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
        c2_b_outSize[c2_i4] = (int32_T)c2_outSize[c2_i4];
      }

      c2_c_st.site = &c2_v_emlrtRSI;
      c2_ndx = (real_T)c2_sub2ind(chartInstance, &c2_c_st, c2_b_outSize,
        c2_varargin_2);
      c2_linearInds = (int32_T)c2_ndx - 1;
      c2_d1 = (real_T)c2_weights_size[0];
      c2_i5 = (int32_T)c2_d1;
      for (c2_k = 0; c2_k < c2_i5; c2_k++) {
        c2_sumVal1 += c2_c_weights_data[c2_linearInds] *
          c2_inCol_data[c2_indices_data[c2_linearInds] - 1];
        c2_a = c2_linearInds + 1;
        c2_linearInds = c2_a;
      }

      c2_x = c2_sumVal1;
      c2_y = c2_x;
      c2_out_->vector.data[((int32_T)c2_b_outRInd + 720 * ((int32_T)c2_b_inCInd
        - 1)) - 1] = c2_y;
    }
  }
}

static void c2_d_contributions(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, int32_T c2_in_length, real_T c2_scale,
  real_T c2_kernel_width, real_T c2_c_weights_data[], int32_T c2_weights_size[2],
  int32_T c2_indices_data[], int32_T c2_indices_size[2])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_st;
  real_T c2_u[1280];
  real_T c2_x[1280];
  real_T c2_outsize[2];
  real_T c2_b_kernel_width;
  real_T c2_b_scale;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d_i;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_i_a;
  real_T c2_j_a;
  real_T c2_k_k;
  real_T c2_l_a;
  real_T c2_oldIdx;
  real_T c2_y;
  int32_T c2_b_indices_data[7680];
  int32_T c2_indicesNonZeroCols_data[7680];
  int32_T c2_aux_data[2560];
  int32_T c2_left[1280];
  int32_T c2_y_data[9];
  int32_T c2_b_data[6];
  int32_T c2_d_tmp_data[6];
  int32_T c2_e_tmp_data[6];
  int32_T c2_b_csz[2];
  int32_T c2_b_indices_size[2];
  int32_T c2_b_size[2];
  int32_T c2_b_tmp_size[2];
  int32_T c2_c_csz[2];
  int32_T c2_c_tmp_size[2];
  int32_T c2_copyCols_size[2];
  int32_T c2_csz[2];
  int32_T c2_d_tmp_size[2];
  int32_T c2_f_size[2];
  int32_T c2_indicesNonZeroCols_size[2];
  int32_T c2_tmp_size[2];
  int32_T c2_weightsNonZeroCols_size[2];
  int32_T c2_x_size[2];
  int32_T c2_y_size[2];
  int32_T c2_P;
  int32_T c2_a;
  int32_T c2_auxLength;
  int32_T c2_b;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_d;
  int32_T c2_b_end;
  int32_T c2_b_i;
  int32_T c2_b_i1;
  int32_T c2_b_i2;
  int32_T c2_b_ia;
  int32_T c2_b_ib;
  int32_T c2_b_ic;
  int32_T c2_b_ix;
  int32_T c2_b_k;
  int32_T c2_b_loop_ub;
  int32_T c2_b_partialTrueCount;
  int32_T c2_b_sbk;
  int32_T c2_b_szc;
  int32_T c2_b_trueCount;
  int32_T c2_b_varargin_1;
  int32_T c2_b_varargin_2;
  int32_T c2_b_varargin_3;
  int32_T c2_b_varargin_5;
  int32_T c2_b_varargin_6;
  int32_T c2_b_vlen;
  int32_T c2_b_xj;
  int32_T c2_bi;
  int32_T c2_bma;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_c_i;
  int32_T c2_c_ia;
  int32_T c2_c_ib;
  int32_T c2_c_ic;
  int32_T c2_c_k;
  int32_T c2_c_loop_ub;
  int32_T c2_c_szc;
  int32_T c2_c_varargin_1;
  int32_T c2_c_varargin_2;
  int32_T c2_c_varargin_3;
  int32_T c2_c_vlen;
  int32_T c2_c_xj;
  int32_T c2_d_a;
  int32_T c2_d_b;
  int32_T c2_d_ia;
  int32_T c2_d_ib;
  int32_T c2_d_ic;
  int32_T c2_d_k;
  int32_T c2_d_loop_ub;
  int32_T c2_d_varargin_1;
  int32_T c2_d_varargin_2;
  int32_T c2_d_varargin_3;
  int32_T c2_e_a;
  int32_T c2_e_b;
  int32_T c2_e_i;
  int32_T c2_e_ic;
  int32_T c2_e_k;
  int32_T c2_e_loop_ub;
  int32_T c2_e_varargin_1;
  int32_T c2_e_varargin_3;
  int32_T c2_end;
  int32_T c2_f_a;
  int32_T c2_f_b;
  int32_T c2_f_i;
  int32_T c2_f_ic;
  int32_T c2_f_k;
  int32_T c2_f_loop_ub;
  int32_T c2_f_varargin_1;
  int32_T c2_g_a;
  int32_T c2_g_b;
  int32_T c2_g_i;
  int32_T c2_g_k;
  int32_T c2_g_loop_ub;
  int32_T c2_h_a;
  int32_T c2_h_b;
  int32_T c2_h_i;
  int32_T c2_h_k;
  int32_T c2_h_loop_ub;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i2;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i3;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i4;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i_b;
  int32_T c2_i_i;
  int32_T c2_i_k;
  int32_T c2_i_loop_ub;
  int32_T c2_ia;
  int32_T c2_ib;
  int32_T c2_ic;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_j_k;
  int32_T c2_j_loop_ub;
  int32_T c2_k;
  int32_T c2_k_a;
  int32_T c2_k_loop_ub;
  int32_T c2_l_loop_ub;
  int32_T c2_loop_ub;
  int32_T c2_m_a;
  int32_T c2_m_loop_ub;
  int32_T c2_n;
  int32_T c2_n_a;
  int32_T c2_n_loop_ub;
  int32_T c2_nm1;
  int32_T c2_npages;
  int32_T c2_o_a;
  int32_T c2_o_loop_ub;
  int32_T c2_p_a;
  int32_T c2_p_loop_ub;
  int32_T c2_partialTrueCount;
  int32_T c2_q_a;
  int32_T c2_q_loop_ub;
  int32_T c2_r_a;
  int32_T c2_r_loop_ub;
  int32_T c2_s_loop_ub;
  int32_T c2_sak;
  int32_T c2_sbk;
  int32_T c2_span;
  int32_T c2_szc;
  int32_T c2_trueCount;
  int32_T c2_varargin_1;
  int32_T c2_varargin_2;
  int32_T c2_varargin_3;
  int32_T c2_varargin_4;
  int32_T c2_varargin_5;
  int32_T c2_varargin_6;
  int32_T c2_vlen;
  int32_T c2_xj;
  int32_T c2_xoffset;
  int32_T c2_yk;
  boolean_T c2_b_tmp_data[7680];
  boolean_T c2_c_tmp_data[7680];
  boolean_T c2_tmp_data[7680];
  boolean_T c2_copyCols_data[6];
  boolean_T c2_exitg1;
  boolean_T c2_j_b;
  boolean_T c2_k_b;
  boolean_T c2_overflow;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  if (c2_scale < 1.0) {
    c2_kernel_width = 2.0 / c2_scale;
  }

  c2_d = 0.5 * (1.0 - 1.0 / c2_scale);
  for (c2_i = 0; c2_i < 1280; c2_i++) {
    c2_u[c2_i] = (1.0 + (real_T)c2_i) / c2_scale + c2_d;
  }

  c2_b_kernel_width = c2_kernel_width / 2.0;
  for (c2_i1 = 0; c2_i1 < 1280; c2_i1++) {
    c2_x[c2_i1] = c2_u[c2_i1] - c2_b_kernel_width;
  }

  for (c2_k = 0; c2_k < 1280; c2_k++) {
    c2_b_k = c2_k;
    c2_b_x = c2_x[c2_b_k];
    c2_d_x = c2_b_x;
    c2_d_x = muDoubleScalarFloor(c2_d_x);
    c2_x[c2_b_k] = c2_d_x;
  }

  for (c2_i2 = 0; c2_i2 < 1280; c2_i2++) {
    c2_left[c2_i2] = (int32_T)c2_x[c2_i2];
  }

  c2_c_x = c2_kernel_width;
  c2_e_x = c2_c_x;
  c2_y = c2_e_x;
  c2_y = muDoubleScalarCeil(c2_y);
  c2_P = (int32_T)(c2_y + 2.0) - 1;
  c2_b_d = c2_P;
  c2_b = c2_b_d;
  c2_b_b = c2_b;
  c2_a = c2_b_b;
  c2_bi = c2_a;
  c2_c_b = c2_bi;
  c2_d_b = c2_c_b;
  c2_e_b = c2_d_b;
  c2_b_a = c2_e_b;
  c2_bma = c2_b_a;
  c2_c_a = c2_bma;
  c2_span = c2_c_a;
  c2_d_a = c2_span;
  c2_nm1 = (uint8_T)c2_d_a;
  c2_e_a = c2_nm1;
  c2_f_b = c2_e_a;
  c2_f_a = c2_f_b + 1;
  c2_n = c2_f_a;
  c2_y_size[1] = c2_n;
  c2_y_data[0] = 0;
  c2_yk = 0;
  for (c2_c_k = 2; c2_c_k <= c2_n; c2_c_k++) {
    c2_g_a = c2_yk + 1;
    c2_yk = c2_g_a;
    c2_y_data[c2_c_k - 1] = c2_yk;
  }

  c2_b_size[1] = c2_y_size[1];
  c2_loop_ub = c2_y_size[1] - 1;
  for (c2_i3 = 0; c2_i3 <= c2_loop_ub; c2_i3++) {
    c2_b_data[c2_i3] = c2_y_data[c2_i3];
  }

  c2_sbk = c2_b_size[1];
  c2_csz[1] = c2_sbk;
  c2_b_indices_size[1] = c2_csz[1];
  c2_szc = c2_b_indices_size[1] - 1;
  c2_i4 = c2_szc;
  for (c2_d_k = 0; c2_d_k <= c2_i4; c2_d_k++) {
    c2_ib = c2_d_k;
    c2_ic = c2_d_k;
    c2_varargin_1 = c2_ic + 1;
    c2_varargin_3 = c2_ib + 1;
    for (c2_e_k = 0; c2_e_k < 1280; c2_e_k++) {
      c2_ia = c2_e_k;
      c2_b_ic = c2_e_k;
      c2_b_varargin_1 = c2_b_ic;
      c2_varargin_2 = c2_varargin_1 - 1;
      c2_b_varargin_3 = c2_ia;
      c2_varargin_6 = c2_varargin_3 - 1;
      c2_h_a = c2_left[c2_b_varargin_3];
      c2_g_b = c2_b_data[c2_varargin_6];
      c2_c = c2_h_a + c2_g_b;
      c2_b_indices_data[c2_b_varargin_1 + 1280 * c2_varargin_2] = c2_c;
    }
  }

  c2_weightsNonZeroCols_size[1] = c2_b_indices_size[1];
  c2_b_loop_ub = 1280 * c2_b_indices_size[1] - 1;
  for (c2_i5 = 0; c2_i5 <= c2_b_loop_ub; c2_i5++) {
    chartInstance->c2_weightsNonZeroCols_data[c2_i5] = (real_T)
      c2_b_indices_data[c2_i5];
  }

  c2_b_sbk = c2_weightsNonZeroCols_size[1];
  c2_b_csz[1] = c2_b_sbk;
  c2_x_size[1] = c2_b_csz[1];
  c2_b_szc = c2_x_size[1] - 1;
  c2_i6 = c2_b_szc;
  for (c2_f_k = 0; c2_f_k <= c2_i6; c2_f_k++) {
    c2_b_ib = c2_f_k;
    c2_c_ic = c2_f_k;
    c2_c_varargin_1 = c2_c_ic + 1;
    c2_c_varargin_3 = c2_b_ib + 1;
    for (c2_g_k = 0; c2_g_k < 1280; c2_g_k++) {
      c2_b_ia = c2_g_k;
      c2_c_ib = c2_g_k;
      c2_d_ic = c2_g_k;
      c2_d_varargin_1 = c2_d_ic;
      c2_b_varargin_2 = c2_c_varargin_1 - 1;
      c2_d_varargin_3 = c2_b_ia;
      c2_varargin_5 = c2_c_ib;
      c2_b_varargin_6 = c2_c_varargin_3 - 1;
      chartInstance->c2_x_data[c2_d_varargin_1 + 1280 * c2_b_varargin_2] =
        c2_u[c2_d_varargin_3] - chartInstance->
        c2_weightsNonZeroCols_data[c2_varargin_5 + 1280 * c2_b_varargin_6];
    }
  }

  c2_b_scale = c2_scale;
  if (c2_b_scale < 1.0) {
    c2_i_a = c2_b_scale;
    c2_i7 = 1280 * c2_x_size[1];
    c2_i8 = c2_i7;
    c2_d_loop_ub = c2_i8 - 1;
    for (c2_i10 = 0; c2_i10 <= c2_d_loop_ub; c2_i10++) {
      chartInstance->c2_x_data[c2_i10] *= c2_i_a;
    }
  }

  c2_tmp_size[1] = c2_x_size[1];
  c2_c_loop_ub = 1280 * c2_x_size[1] - 1;
  for (c2_i9 = 0; c2_i9 <= c2_c_loop_ub; c2_i9++) {
    c2_tmp_data[c2_i9] = (chartInstance->c2_x_data[c2_i9] >= -1.0);
  }

  c2_e_loop_ub = 1280 * c2_x_size[1] - 1;
  for (c2_i11 = 0; c2_i11 <= c2_e_loop_ub; c2_i11++) {
    c2_b_tmp_data[c2_i11] = (chartInstance->c2_x_data[c2_i11] < 0.0);
  }

  c2_i12 = 1280 * c2_tmp_size[1];
  c2_i13 = c2_i12;
  c2_f_loop_ub = c2_i13 - 1;
  for (c2_i14 = 0; c2_i14 <= c2_f_loop_ub; c2_i14++) {
    c2_tmp_data[c2_i14] = (c2_tmp_data[c2_i14] && c2_b_tmp_data[c2_i14]);
  }

  c2_b_tmp_size[1] = c2_x_size[1];
  c2_g_loop_ub = 1280 * c2_x_size[1] - 1;
  for (c2_i15 = 0; c2_i15 <= c2_g_loop_ub; c2_i15++) {
    c2_b_tmp_data[c2_i15] = (chartInstance->c2_x_data[c2_i15] >= 0.0);
  }

  c2_h_loop_ub = 1280 * c2_x_size[1] - 1;
  for (c2_i16 = 0; c2_i16 <= c2_h_loop_ub; c2_i16++) {
    c2_c_tmp_data[c2_i16] = (chartInstance->c2_x_data[c2_i16] <= 1.0);
  }

  c2_i17 = 1280 * c2_b_tmp_size[1];
  c2_i18 = c2_i17;
  c2_i_loop_ub = c2_i18 - 1;
  for (c2_i19 = 0; c2_i19 <= c2_i_loop_ub; c2_i19++) {
    c2_b_tmp_data[c2_i19] = (c2_b_tmp_data[c2_i19] && c2_c_tmp_data[c2_i19]);
  }

  c2_f_size[1] = c2_x_size[1];
  c2_j_loop_ub = 1280 * c2_x_size[1] - 1;
  for (c2_i20 = 0; c2_i20 <= c2_j_loop_ub; c2_i20++) {
    chartInstance->c2_f_data[c2_i20] = (chartInstance->c2_x_data[c2_i20] + 1.0) *
      (real_T)c2_tmp_data[c2_i20];
  }

  c2_i21 = 1280 * c2_x_size[1];
  c2_i22 = c2_i21;
  c2_k_loop_ub = c2_i22 - 1;
  for (c2_i23 = 0; c2_i23 <= c2_k_loop_ub; c2_i23++) {
    chartInstance->c2_x_data[c2_i23] = (1.0 - chartInstance->c2_x_data[c2_i23]) *
      (real_T)c2_b_tmp_data[c2_i23];
  }

  c2_i24 = 1280 * c2_f_size[1];
  c2_i25 = c2_i24;
  c2_l_loop_ub = c2_i25 - 1;
  for (c2_i26 = 0; c2_i26 <= c2_l_loop_ub; c2_i26++) {
    chartInstance->c2_f_data[c2_i26] += chartInstance->c2_x_data[c2_i26];
  }

  if (c2_b_scale < 1.0) {
    c2_j_a = c2_b_scale;
    c2_i27 = 1280 * c2_f_size[1];
    c2_i28 = c2_i27;
    c2_m_loop_ub = c2_i28 - 1;
    for (c2_i29 = 0; c2_i29 <= c2_m_loop_ub; c2_i29++) {
      chartInstance->c2_f_data[c2_i29] *= c2_j_a;
    }
  }

  c2_vlen = c2_f_size[1];
  c2_b_vlen = c2_vlen;
  c2_c_vlen = c2_b_vlen;
  for (c2_xj = 0; c2_xj < 1280; c2_xj++) {
    c2_b_xj = c2_xj;
    c2_u[c2_b_xj] = chartInstance->c2_f_data[c2_b_xj];
  }

  for (c2_h_k = 2; c2_h_k <= c2_c_vlen; c2_h_k++) {
    c2_xoffset = (c2_h_k - 1) * 1280;
    for (c2_c_xj = 0; c2_c_xj < 1280; c2_c_xj++) {
      c2_b_xj = c2_c_xj;
      c2_ix = c2_xoffset + c2_b_xj;
      c2_u[c2_b_xj] += chartInstance->c2_f_data[c2_ix];
    }
  }

  c2_weightsNonZeroCols_size[1] = c2_f_size[1];
  c2_n_loop_ub = 1280 * c2_f_size[1] - 1;
  for (c2_i30 = 0; c2_i30 <= c2_n_loop_ub; c2_i30++) {
    chartInstance->c2_weightsNonZeroCols_data[c2_i30] = chartInstance->
      c2_f_data[c2_i30];
  }

  c2_sak = c2_weightsNonZeroCols_size[1];
  c2_c_csz[1] = c2_sak;
  c2_f_size[0] = 1280;
  c2_f_size[1] = c2_c_csz[1];
  c2_c_szc = c2_f_size[1] - 1;
  c2_i31 = c2_c_szc;
  for (c2_i_k = 0; c2_i_k <= c2_i31; c2_i_k++) {
    c2_c_ia = c2_i_k;
    c2_e_ic = c2_i_k;
    c2_e_varargin_1 = c2_e_ic + 1;
    c2_c_varargin_2 = c2_c_ia + 1;
    for (c2_j_k = 0; c2_j_k < 1280; c2_j_k++) {
      c2_d_ia = c2_j_k;
      c2_d_ib = c2_j_k;
      c2_f_ic = c2_j_k;
      c2_f_varargin_1 = c2_f_ic;
      c2_d_varargin_2 = c2_e_varargin_1 - 1;
      c2_e_varargin_3 = c2_d_ia;
      c2_varargin_4 = c2_c_varargin_2 - 1;
      c2_b_varargin_5 = c2_d_ib;
      chartInstance->c2_f_data[c2_f_varargin_1 + 1280 * c2_d_varargin_2] =
        chartInstance->c2_weightsNonZeroCols_data[c2_e_varargin_3 + 1280 *
        c2_varargin_4] / c2_u[c2_b_varargin_5];
    }
  }

  c2_k_a = c2_in_length;
  c2_auxLength = c2_k_a << 1;
  c2_aux_data[0] = 1;
  c2_aux_data[c2_in_length] = c2_in_length;
  for (c2_b_i = 2; c2_b_i <= c2_in_length; c2_b_i++) {
    c2_aux_data[c2_b_i - 1] = c2_aux_data[c2_b_i - 2] + 1;
    c2_aux_data[(c2_in_length + c2_b_i) - 1] = c2_aux_data[(c2_in_length +
      c2_b_i) - 2] - 1;
  }

  c2_d1 = (real_T)(1280 * c2_b_indices_size[1]);
  c2_i32 = (int32_T)c2_d1;
  for (c2_c_i = 0; c2_c_i < c2_i32; c2_c_i++) {
    c2_d_i = (real_T)c2_c_i + 1.0;
    c2_oldIdx = (real_T)c2_b_indices_data[(int32_T)c2_d_i - 1];
    c2_k_k = c2_mod(chartInstance, c2_oldIdx - 1.0, (real_T)c2_auxLength);
    c2_l_a = c2_k_k;
    c2_b_c = (int32_T)c2_l_a;
    c2_b_indices_data[(int32_T)c2_d_i - 1] = c2_aux_data[c2_b_c];
  }

  c2_st.site = &c2_p_emlrtRSI;
  c2_b_st.site = &c2_q_emlrtRSI;
  for (c2_i33 = 0; c2_i33 < 2; c2_i33++) {
    c2_outsize[c2_i33] = (real_T)c2_f_size[c2_i33];
  }

  c2_copyCols_size[1] = (int32_T)c2_outsize[1];
  c2_o_loop_ub = (int32_T)c2_outsize[1] - 1;
  if (c2_o_loop_ub >= 0) {
    memset(&c2_copyCols_data[0], 0, (uint32_T)(c2_o_loop_ub + 1) * sizeof
           (boolean_T));
  }

  c2_npages = c2_f_size[1];
  c2_b_i2 = 0;
  c2_iy = -1;
  c2_i34 = (uint8_T)c2_npages;
  for (c2_e_i = 0; c2_e_i < c2_i34; c2_e_i++) {
    c2_b_i1 = c2_b_i2;
    c2_m_a = c2_b_i2 + 1279;
    c2_b_i2 = c2_m_a;
    c2_n_a = c2_b_i1 + 1;
    c2_b_i1 = c2_n_a;
    c2_o_a = c2_b_i2 + 1;
    c2_b_i2 = c2_o_a;
    c2_p_a = c2_iy + 1;
    c2_iy = c2_p_a;
    c2_c_st.site = &c2_r_emlrtRSI;
    c2_q_a = c2_b_i1;
    c2_h_b = c2_b_i2;
    c2_r_a = c2_q_a;
    c2_i_b = c2_h_b;
    if (c2_r_a > c2_i_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_i_b > 2147483646);
    }

    if (c2_overflow) {
      c2_d_st.site = &c2_s_emlrtRSI;
      c2_check_forloop_overflow_error(chartInstance, &c2_d_st);
    }

    c2_b_ix = c2_b_i1 - 1;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_b_ix + 1 <= c2_b_i2)) {
      if (chartInstance->c2_f_data[c2_b_ix] == 0.0) {
        c2_j_b = true;
      } else {
        c2_f_x = chartInstance->c2_f_data[c2_b_ix];
        c2_k_b = muDoubleScalarIsNaN(c2_f_x);
        if (c2_k_b) {
          c2_j_b = true;
        } else {
          c2_j_b = false;
        }
      }

      if (!c2_j_b) {
        c2_copyCols_data[c2_iy] = true;
        c2_exitg1 = true;
      } else {
        c2_b_ix++;
      }
    }
  }

  c2_end = c2_copyCols_size[1];
  c2_trueCount = 0;
  for (c2_f_i = 0; c2_f_i < c2_end; c2_f_i++) {
    if (c2_copyCols_data[c2_f_i]) {
      c2_trueCount++;
    }
  }

  c2_c_tmp_size[1] = c2_trueCount;
  c2_partialTrueCount = 0;
  for (c2_g_i = 0; c2_g_i < c2_end; c2_g_i++) {
    if (c2_copyCols_data[c2_g_i]) {
      c2_d_tmp_data[c2_partialTrueCount] = c2_g_i;
      c2_partialTrueCount++;
    }
  }

  c2_weightsNonZeroCols_size[1] = c2_c_tmp_size[1];
  c2_p_loop_ub = c2_c_tmp_size[1] - 1;
  for (c2_i35 = 0; c2_i35 <= c2_p_loop_ub; c2_i35++) {
    for (c2_i36 = 0; c2_i36 < 1280; c2_i36++) {
      chartInstance->c2_weightsNonZeroCols_data[c2_i36 + 1280 * c2_i35] =
        chartInstance->c2_f_data[c2_i36 + 1280 * c2_d_tmp_data[c2_i35]];
    }
  }

  c2_b_end = c2_copyCols_size[1];
  c2_b_trueCount = 0;
  for (c2_h_i = 0; c2_h_i < c2_b_end; c2_h_i++) {
    if (c2_copyCols_data[c2_h_i]) {
      c2_b_trueCount++;
    }
  }

  c2_d_tmp_size[1] = c2_b_trueCount;
  c2_b_partialTrueCount = 0;
  for (c2_i_i = 0; c2_i_i < c2_b_end; c2_i_i++) {
    if (c2_copyCols_data[c2_i_i]) {
      c2_e_tmp_data[c2_b_partialTrueCount] = c2_i_i;
      c2_b_partialTrueCount++;
    }
  }

  c2_indicesNonZeroCols_size[1] = c2_d_tmp_size[1];
  c2_q_loop_ub = c2_d_tmp_size[1] - 1;
  for (c2_i37 = 0; c2_i37 <= c2_q_loop_ub; c2_i37++) {
    for (c2_i38 = 0; c2_i38 < 1280; c2_i38++) {
      c2_indicesNonZeroCols_data[c2_i38 + 1280 * c2_i37] =
        c2_b_indices_data[c2_i38 + 1280 * c2_e_tmp_data[c2_i37]];
    }
  }

  c2_weights_size[0] = c2_weightsNonZeroCols_size[1];
  c2_weights_size[1] = 1280;
  for (c2_i39 = 0; c2_i39 < 1280; c2_i39++) {
    c2_r_loop_ub = c2_weightsNonZeroCols_size[1] - 1;
    for (c2_i40 = 0; c2_i40 <= c2_r_loop_ub; c2_i40++) {
      c2_c_weights_data[c2_i40 + c2_weights_size[0] * c2_i39] =
        chartInstance->c2_weightsNonZeroCols_data[c2_i39 + 1280 * c2_i40];
    }
  }

  c2_indices_size[0] = c2_indicesNonZeroCols_size[1];
  c2_indices_size[1] = 1280;
  for (c2_i41 = 0; c2_i41 < 1280; c2_i41++) {
    c2_s_loop_ub = c2_indicesNonZeroCols_size[1] - 1;
    for (c2_i42 = 0; c2_i42 <= c2_s_loop_ub; c2_i42++) {
      c2_indices_data[c2_i42 + c2_indices_size[0] * c2_i41] =
        c2_indicesNonZeroCols_data[c2_i41 + 1280 * c2_i42];
    }
  }
}

static void c2_f_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_in_,
  real_T c2_c_weights_data[], int32_T c2_weights_size[2], int32_T
  c2_indices_data[], real_T c2_out_[921600])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_siz[2];
  real_T c2_b_inRInd;
  real_T c2_b_outCInd;
  real_T c2_b_varargin_1;
  real_T c2_b_x;
  real_T c2_c_a;
  real_T c2_d;
  real_T c2_e_y;
  real_T c2_ndx;
  real_T c2_pixelValue;
  real_T c2_rowStart;
  real_T c2_sumVal1;
  real_T c2_varargin_1;
  real_T c2_varargin_2;
  real_T c2_x;
  int32_T c2_b_siz[2];
  int32_T c2_c_siz[2];
  int32_T c2_a;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_b_hi;
  int32_T c2_c;
  int32_T c2_hi;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_idx;
  int32_T c2_inRInd;
  int32_T c2_k;
  int32_T c2_linearInds;
  int32_T c2_outCInd;
  int32_T c2_pixelIndex;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b_p;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_st.site = &c2_t_emlrtRSI;
  for (c2_inRInd = 0; c2_inRInd < 720; c2_inRInd++) {
    c2_b_inRInd = (real_T)c2_inRInd + 1.0;
    c2_b_st.site = &c2_w_emlrtRSI;
    for (c2_i = 0; c2_i < 2; c2_i++) {
      c2_siz[c2_i] = (real_T)c2_in_->size[c2_i];
    }

    c2_varargin_1 = c2_b_inRInd;
    c2_c_st.site = &c2_v_emlrtRSI;
    for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
      c2_b_siz[c2_i1] = (int32_T)c2_siz[c2_i1];
    }

    c2_b_varargin_1 = c2_varargin_1;
    c2_x = c2_b_varargin_1;
    if (c2_x <= 720.0) {
      c2_b = true;
    } else {
      c2_b = false;
    }

    if (!c2_b) {
      c2_p = false;
    } else {
      c2_p = true;
    }

    if (!c2_p) {
      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(&c2_c_st, &c2_c_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                  sf_mex_call(&c2_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c2_c_st, NULL, "message", 1U, 1U, 14, c2_b_y)));
    }

    c2_hi = c2_b_siz[1];
    c2_b_hi = c2_hi;
    if (c2_b_hi >= 1) {
      c2_b1 = true;
    } else {
      c2_b1 = false;
    }

    if (!c2_b1) {
      c2_b_p = false;
    } else {
      c2_b_p = true;
    }

    if (!c2_b_p) {
      c2_c_y = NULL;
      sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(&c2_c_st, &c2_c_emlrtMCI, "error", 0U, 2U, 14, c2_c_y, 14,
                  sf_mex_call(&c2_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c2_c_st, NULL, "message", 1U, 1U, 14, c2_d_y)));
    }

    c2_idx = (int32_T)c2_b_varargin_1;
    c2_rowStart = (real_T)c2_idx;
    for (c2_outCInd = 0; c2_outCInd < 1280; c2_outCInd++) {
      c2_b_outCInd = (real_T)c2_outCInd + 1.0;
      c2_sumVal1 = 0.0;
      c2_b_st.site = &c2_x_emlrtRSI;
      for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
        c2_siz[c2_i2] = (real_T)c2_weights_size[c2_i2];
      }

      c2_varargin_2 = c2_b_outCInd;
      for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
        c2_c_siz[c2_i3] = (int32_T)c2_siz[c2_i3];
      }

      c2_c_st.site = &c2_v_emlrtRSI;
      c2_ndx = (real_T)c2_sub2ind(chartInstance, &c2_c_st, c2_c_siz,
        c2_varargin_2);
      c2_linearInds = (int32_T)c2_ndx - 1;
      c2_d = (real_T)c2_weights_size[0];
      c2_i4 = (int32_T)c2_d;
      for (c2_k = 0; c2_k < c2_i4; c2_k++) {
        c2_a = c2_indices_data[c2_linearInds] - 1;
        c2_c = c2_a;
        c2_b_a = c2_c;
        c2_b_c = c2_b_a * 720;
        c2_c_a = c2_rowStart;
        c2_b_b = c2_b_c;
        c2_pixelIndex = ((int32_T)c2_c_a + c2_b_b) - 1;
        c2_pixelValue = c2_in_->vector.data[c2_pixelIndex];
        c2_sumVal1 += c2_c_weights_data[c2_linearInds] * c2_pixelValue;
        c2_linearInds++;
      }

      c2_b_x = c2_sumVal1;
      c2_e_y = c2_b_x;
      c2_out_[((int32_T)c2_b_inRInd + 720 * ((int32_T)c2_b_outCInd - 1)) - 1] =
        c2_e_y;
    }
  }
}

static void c2_g_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_in_,
  real_T c2_c_weights_data[], int32_T c2_weights_size[2], int32_T
  c2_indices_data[], c2_coder_array_real_T_2D *c2_out_)
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_outSize[2];
  real_T c2_b;
  real_T c2_b_inRInd;
  real_T c2_b_outCInd;
  real_T c2_c_a;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_ndx;
  real_T c2_pixelValue;
  real_T c2_rowStart;
  real_T c2_sumVal1;
  real_T c2_varargin_1;
  real_T c2_varargin_2;
  real_T c2_x;
  real_T c2_y;
  int32_T c2_b_outSize[2];
  int32_T c2_c_outSize[2];
  int32_T c2_a;
  int32_T c2_b_a;
  int32_T c2_b_b;
  int32_T c2_b_c;
  int32_T c2_c;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_inRInd;
  int32_T c2_k;
  int32_T c2_linearInds;
  int32_T c2_outCInd;
  int32_T c2_pixelIndex;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_outSize[c2_i] = (real_T)c2_in_->size[c2_i];
  }

  c2_st.site = &c2_ib_emlrtRSI;
  c2_array_real_T_2D_SetSize(chartInstance, &c2_st, c2_out_, &c2_kb_emlrtRTEI,
    (int32_T)c2_outSize[0], 1280);
  c2_st.site = &c2_t_emlrtRSI;
  c2_d = (real_T)c2_in_->size[0];
  c2_i1 = (int32_T)c2_d;
  for (c2_inRInd = 0; c2_inRInd < c2_i1; c2_inRInd++) {
    c2_b_inRInd = (real_T)c2_inRInd + 1.0;
    c2_b_st.site = &c2_w_emlrtRSI;
    for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
      c2_outSize[c2_i2] = (real_T)c2_in_->size[c2_i2];
    }

    c2_varargin_1 = c2_b_inRInd;
    for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
      c2_b_outSize[c2_i3] = (int32_T)c2_outSize[c2_i3];
    }

    c2_c_st.site = &c2_v_emlrtRSI;
    c2_rowStart = (real_T)c2_b_sub2ind(chartInstance, &c2_c_st, c2_b_outSize,
      c2_varargin_1);
    for (c2_outCInd = 0; c2_outCInd < 1280; c2_outCInd++) {
      c2_b_outCInd = (real_T)c2_outCInd + 1.0;
      c2_sumVal1 = 0.0;
      c2_b_st.site = &c2_x_emlrtRSI;
      for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
        c2_outSize[c2_i4] = (real_T)c2_weights_size[c2_i4];
      }

      c2_varargin_2 = c2_b_outCInd;
      for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
        c2_c_outSize[c2_i5] = (int32_T)c2_outSize[c2_i5];
      }

      c2_c_st.site = &c2_v_emlrtRSI;
      c2_ndx = (real_T)c2_sub2ind(chartInstance, &c2_c_st, c2_c_outSize,
        c2_varargin_2);
      c2_linearInds = (int32_T)c2_ndx - 1;
      c2_d1 = (real_T)c2_weights_size[0];
      c2_i6 = (int32_T)c2_d1;
      for (c2_k = 0; c2_k < c2_i6; c2_k++) {
        c2_a = c2_indices_data[c2_linearInds] - 1;
        c2_c = c2_a;
        c2_b_a = c2_c;
        c2_b = (real_T)c2_in_->size[0];
        c2_b_c = c2_b_a * (int32_T)c2_b;
        c2_c_a = c2_rowStart;
        c2_b_b = c2_b_c;
        c2_pixelIndex = ((int32_T)c2_c_a + c2_b_b) - 1;
        c2_pixelValue = c2_in_->vector.data[c2_pixelIndex];
        c2_sumVal1 += c2_c_weights_data[c2_linearInds] * c2_pixelValue;
        c2_linearInds++;
      }

      c2_x = c2_sumVal1;
      c2_y = c2_x;
      c2_out_->vector.data[((int32_T)c2_b_inRInd + c2_out_->size[0] * ((int32_T)
        c2_b_outCInd - 1)) - 1] = c2_y;
    }
  }
}

static void c2_h_resizeAlongDim(SFc2_step2_compression_simulationInstanceStruct *
  chartInstance, const emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_in_,
  real_T c2_c_weights_data[], int32_T c2_weights_size[2], int32_T
  c2_indices_data[], real_T c2_out_[921600])
{
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st;
  real_T c2_inCol_data[1280];
  real_T c2_siz[2];
  real_T c2_b_inCInd;
  real_T c2_b_outRInd;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_ndx;
  real_T c2_sumVal1;
  real_T c2_varargin_2;
  real_T c2_x;
  real_T c2_y;
  int32_T c2_b_siz[2];
  int32_T c2_a;
  int32_T c2_c_inCInd;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_inCInd;
  int32_T c2_k;
  int32_T c2_linearInds;
  int32_T c2_loop_ub;
  int32_T c2_outRInd;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_st.site = &c2_t_emlrtRSI;
  c2_d = (real_T)(c2_in_->size[0] * 1280) / (real_T)c2_in_->size[0];
  c2_i = (int32_T)c2_d;
  for (c2_inCInd = 0; c2_inCInd < c2_i; c2_inCInd++) {
    c2_b_inCInd = (real_T)c2_inCInd + 1.0;
    c2_c_inCInd = (int32_T)c2_b_inCInd - 1;
    c2_loop_ub = c2_in_->size[0] - 1;
    for (c2_i1 = 0; c2_i1 <= c2_loop_ub; c2_i1++) {
      c2_inCol_data[c2_i1] = c2_in_->vector.data[c2_i1 + c2_in_->size[0] *
        c2_c_inCInd];
    }

    for (c2_outRInd = 0; c2_outRInd < 720; c2_outRInd++) {
      c2_b_outRInd = (real_T)c2_outRInd + 1.0;
      c2_sumVal1 = 0.0;
      c2_b_st.site = &c2_u_emlrtRSI;
      for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
        c2_siz[c2_i2] = (real_T)c2_weights_size[c2_i2];
      }

      c2_varargin_2 = c2_b_outRInd;
      for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
        c2_b_siz[c2_i3] = (int32_T)c2_siz[c2_i3];
      }

      c2_c_st.site = &c2_v_emlrtRSI;
      c2_ndx = (real_T)c2_sub2ind(chartInstance, &c2_c_st, c2_b_siz,
        c2_varargin_2);
      c2_linearInds = (int32_T)c2_ndx - 1;
      c2_d1 = (real_T)c2_weights_size[0];
      c2_i4 = (int32_T)c2_d1;
      for (c2_k = 0; c2_k < c2_i4; c2_k++) {
        c2_sumVal1 += c2_c_weights_data[c2_linearInds] *
          c2_inCol_data[c2_indices_data[c2_linearInds] - 1];
        c2_a = c2_linearInds + 1;
        c2_linearInds = c2_a;
      }

      c2_x = c2_sumVal1;
      c2_y = c2_x;
      c2_out_[((int32_T)c2_b_outRInd + 720 * ((int32_T)c2_b_inCInd - 1)) - 1] =
        c2_y;
    }
  }
}

static real_T c2_sumColumnB(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, c2_coder_array_real_T *c2_x, int32_T c2_vlen)
{
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_y;
  int32_T c2_a;
  int32_T c2_b_k;
  int32_T c2_b_vlen;
  int32_T c2_b_vstart;
  int32_T c2_c_k;
  int32_T c2_c_vlen;
  int32_T c2_d_k;
  int32_T c2_e_k;
  int32_T c2_f_k;
  int32_T c2_g_k;
  int32_T c2_h_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i_k;
  int32_T c2_inb;
  int32_T c2_k;
  int32_T c2_lidx;
  int32_T c2_nfb;
  int32_T c2_nleft;
  int32_T c2_vstart;
  (void)chartInstance;
  if (c2_vlen <= 1024) {
    c2_b_vlen = c2_vlen - 1;
    c2_y = c2_x->vector.data[0];
    c2_i = c2_b_vlen;
    c2_i1 = (uint16_T)c2_i;
    for (c2_b_k = 0; c2_b_k < c2_i1; c2_b_k++) {
      c2_e_k = c2_b_k;
      c2_y += c2_x->vector.data[c2_e_k + 1];
    }
  } else {
    c2_a = c2_vlen;
    c2_nfb = (int32_T)((uint32_T)c2_a >> 10);
    c2_inb = c2_nfb << 10;
    c2_y = c2_x->vector.data[0];
    for (c2_k = 0; c2_k < 1023; c2_k++) {
      c2_d_k = c2_k;
      c2_y += c2_x->vector.data[c2_d_k + 1];
    }

    for (c2_c_k = 2; c2_c_k <= c2_nfb; c2_c_k++) {
      c2_vstart = (c2_c_k - 1) << 10;
      c2_b_y = c2_x->vector.data[c2_vstart];
      for (c2_f_k = 0; c2_f_k < 1023; c2_f_k++) {
        c2_g_k = c2_f_k;
        c2_b_y += c2_x->vector.data[(c2_vstart + c2_g_k) + 1];
      }

      c2_y += c2_b_y;
    }

    if (c2_vlen > c2_inb) {
      c2_nleft = c2_vlen - c2_inb;
      c2_lidx = c2_inb;
      c2_c_vlen = c2_nleft - 1;
      c2_b_vstart = c2_lidx;
      c2_c_y = c2_x->vector.data[c2_b_vstart];
      c2_i2 = c2_c_vlen;
      for (c2_h_k = 0; c2_h_k < c2_i2; c2_h_k++) {
        c2_i_k = c2_h_k;
        c2_c_y += c2_x->vector.data[(c2_b_vstart + c2_i_k) + 1];
      }

      c2_y += c2_c_y;
    }
  }

  return c2_y;
}

static real_T c2_sumColumnB4(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, c2_coder_array_real_T *c2_x, int32_T c2_vstart)
{
  real_T c2_psum1;
  real_T c2_psum2;
  real_T c2_psum3;
  real_T c2_psum4;
  int32_T c2_b_k;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_k;
  (void)chartInstance;
  c2_i2 = c2_vstart + 1023;
  c2_i3 = c2_vstart + 2047;
  c2_i4 = c2_vstart + 3071;
  c2_psum1 = c2_x->vector.data[c2_vstart - 1];
  c2_psum2 = c2_x->vector.data[c2_i2];
  c2_psum3 = c2_x->vector.data[c2_i3];
  c2_psum4 = c2_x->vector.data[c2_i4];
  for (c2_k = 0; c2_k < 1023; c2_k++) {
    c2_b_k = c2_k + 1;
    c2_psum1 += c2_x->vector.data[(c2_vstart + c2_b_k) - 1];
    c2_psum2 += c2_x->vector.data[c2_i2 + c2_b_k];
    c2_psum3 += c2_x->vector.data[c2_i3 + c2_b_k];
    c2_psum4 += c2_x->vector.data[c2_i4 + c2_b_k];
  }

  return (c2_psum1 + c2_psum2) + (c2_psum3 + c2_psum4);
}

static real_T c2_b_sumColumnB(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, c2_coder_array_real_T *c2_x, int32_T c2_vlen, int32_T
  c2_vstart)
{
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_y;
  int32_T c2_a;
  int32_T c2_b_k;
  int32_T c2_b_vlen;
  int32_T c2_b_vstart;
  int32_T c2_c_k;
  int32_T c2_c_vlen;
  int32_T c2_c_vstart;
  int32_T c2_d_k;
  int32_T c2_d_vstart;
  int32_T c2_e_k;
  int32_T c2_e_vstart;
  int32_T c2_f_k;
  int32_T c2_g_k;
  int32_T c2_h_k;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i_k;
  int32_T c2_inb;
  int32_T c2_k;
  int32_T c2_lidx;
  int32_T c2_nfb;
  int32_T c2_nleft;
  (void)chartInstance;
  if (c2_vlen <= 1024) {
    c2_b_vlen = c2_vlen - 1;
    c2_b_vstart = c2_vstart - 1;
    c2_y = c2_x->vector.data[c2_b_vstart];
    c2_i = c2_b_vlen;
    for (c2_k = 0; c2_k < c2_i; c2_k++) {
      c2_c_k = c2_k;
      c2_y += c2_x->vector.data[(c2_b_vstart + c2_c_k) + 1];
    }
  } else {
    c2_a = c2_vlen;
    c2_nfb = (int32_T)((uint32_T)c2_a >> 10);
    c2_inb = c2_nfb << 10;
    c2_c_vstart = c2_vstart - 1;
    c2_y = c2_x->vector.data[c2_c_vstart];
    for (c2_b_k = 0; c2_b_k < 1023; c2_b_k++) {
      c2_e_k = c2_b_k;
      c2_y += c2_x->vector.data[(c2_c_vstart + c2_e_k) + 1];
    }

    for (c2_d_k = 2; c2_d_k <= c2_nfb; c2_d_k++) {
      c2_d_vstart = (c2_vstart + ((c2_d_k - 1) << 10)) - 1;
      c2_b_y = c2_x->vector.data[c2_d_vstart];
      for (c2_f_k = 0; c2_f_k < 1023; c2_f_k++) {
        c2_g_k = c2_f_k;
        c2_b_y += c2_x->vector.data[(c2_d_vstart + c2_g_k) + 1];
      }

      c2_y += c2_b_y;
    }

    if (c2_vlen > c2_inb) {
      c2_nleft = c2_vlen - c2_inb;
      c2_lidx = c2_vstart + c2_inb;
      c2_c_vlen = c2_nleft - 1;
      c2_e_vstart = c2_lidx - 1;
      c2_c_y = c2_x->vector.data[c2_e_vstart];
      c2_i1 = c2_c_vlen;
      for (c2_h_k = 0; c2_h_k < c2_i1; c2_h_k++) {
        c2_i_k = c2_h_k;
        c2_c_y += c2_x->vector.data[(c2_e_vstart + c2_i_k) + 1];
      }

      c2_y += c2_c_y;
    }
  }

  return c2_y;
}

static void c2_fspecial(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_varargin_3, real_T c2_h[25])
{
  static real_T c2_dv[25] = { -8.0, -5.0, -4.0, -5.0, -8.0, -5.0, -2.0, -1.0,
    -2.0, -5.0, -4.0, -1.0, -0.0, -1.0, -4.0, -5.0, -2.0, -1.0, -2.0, -5.0, -8.0,
    -5.0, -4.0, -5.0, -8.0 };

  static char_T c2_b_cv1[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c2_b_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'f', 's', 'p',
    'e', 'c', 'i', 'a', 'l', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F',
    'i', 'n', 'i', 't', 'e' };

  static char_T c2_cv2[22] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '3', ',', ' ', 'S', 'I', 'G', 'M', 'A', ',' };

  emlrtStack c2_b_st;
  emlrtStack c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_varargin_1[25];
  real_T c2_a;
  real_T c2_b_a;
  real_T c2_b_x;
  real_T c2_c_a;
  real_T c2_c_x;
  real_T c2_d;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_ex;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_maxval;
  real_T c2_sumh;
  real_T c2_x;
  int32_T c2_b_i;
  int32_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_end;
  int32_T c2_first;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_idx;
  int32_T c2_k;
  boolean_T c2_b;
  boolean_T c2_b1;
  boolean_T c2_b_b;
  boolean_T c2_b_p;
  boolean_T c2_c_b;
  boolean_T c2_c_p;
  boolean_T c2_d_b;
  boolean_T c2_e_b;
  boolean_T c2_exitg1;
  boolean_T c2_p;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_st.site = &c2_y_emlrtRSI;
  c2_a = c2_varargin_3;
  c2_b_st.site = &c2_ab_emlrtRSI;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_p = true;
  c2_x = c2_c_a;
  c2_b_x = c2_x;
  c2_b = muDoubleScalarIsNaN(c2_b_x);
  c2_b_b = !c2_b;
  c2_c_b = c2_b_b;
  if (!c2_c_b) {
    c2_p = false;
  }

  if (c2_p) {
    c2_b1 = true;
  } else {
    c2_b1 = false;
  }

  if (!c2_b1) {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_cv1, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv2, 10, 0U, 1, 0U, 2, 1, 22),
                  false);
    sf_mex_call(&c2_b_st, &c2_e_emlrtMCI, "error", 0U, 2U, 14, c2_y, 14,
                sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c2_b_st, NULL, "message", 1U, 2U, 14, c2_b_y, 14, c2_c_y)));
  }

  c2_d = 2.0 * c2_varargin_3 * c2_varargin_3;
  for (c2_i = 0; c2_i < 25; c2_i++) {
    c2_h[c2_i] = c2_dv[c2_i] / c2_d;
  }

  for (c2_k = 0; c2_k < 25; c2_k++) {
    c2_b_k = c2_k;
    c2_c_x = c2_h[c2_b_k];
    c2_e_x = c2_c_x;
    c2_e_x = muDoubleScalarExp(c2_e_x);
    c2_h[c2_b_k] = c2_e_x;
  }

  for (c2_i1 = 0; c2_i1 < 25; c2_i1++) {
    c2_varargin_1[c2_i1] = c2_h[c2_i1];
  }

  c2_d_x = c2_varargin_1[0];
  c2_f_x = c2_d_x;
  c2_d_b = muDoubleScalarIsNaN(c2_f_x);
  c2_b_p = !c2_d_b;
  if (c2_b_p) {
    c2_idx = 1;
  } else {
    c2_idx = 0;
    c2_c_k = 2;
    c2_exitg1 = false;
    while ((!c2_exitg1) && (c2_c_k < 26)) {
      c2_g_x = c2_varargin_1[c2_c_k - 1];
      c2_h_x = c2_g_x;
      c2_e_b = muDoubleScalarIsNaN(c2_h_x);
      c2_c_p = !c2_e_b;
      if (c2_c_p) {
        c2_idx = c2_c_k;
        c2_exitg1 = true;
      } else {
        c2_c_k++;
      }
    }
  }

  if (c2_idx == 0) {
    c2_maxval = c2_varargin_1[0];
  } else {
    c2_first = c2_idx - 1;
    c2_ex = c2_varargin_1[c2_first];
    c2_i2 = c2_first;
    for (c2_d_k = c2_i2 + 2; c2_d_k < 26; c2_d_k++) {
      if (c2_ex < c2_varargin_1[c2_d_k - 1]) {
        c2_ex = c2_varargin_1[c2_d_k - 1];
      }
    }

    c2_maxval = c2_ex;
  }

  c2_end = 25;
  for (c2_b_i = 0; c2_b_i < c2_end; c2_b_i++) {
    if (c2_h[c2_b_i] < 2.2204460492503131E-16 * c2_maxval) {
      c2_h[c2_b_i] = 0.0;
    }
  }

  for (c2_i3 = 0; c2_i3 < 25; c2_i3++) {
    c2_varargin_1[c2_i3] = c2_h[c2_i3];
  }

  c2_sumh = c2_c_sumColumnB(chartInstance, c2_varargin_1);
  if (c2_sumh != 0.0) {
    for (c2_i4 = 0; c2_i4 < 25; c2_i4++) {
      c2_h[c2_i4] /= c2_sumh;
    }
  }
}

static real_T c2_c_sumColumnB(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, real_T c2_x[25])
{
  real_T c2_y;
  int32_T c2_b_k;
  int32_T c2_k;
  (void)chartInstance;
  c2_y = c2_x[0];
  for (c2_k = 0; c2_k < 24; c2_k++) {
    c2_b_k = c2_k;
    c2_y += c2_x[c2_b_k + 1];
  }

  return c2_y;
}

static void c2_imfilter(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_varargin_1[921600], real_T
  c2_varargin_2[25], real_T c2_b[921600])
{
  emlrtStack c2_st;
  real_T c2_nonzero_h_data[25];
  real_T c2_connDimsT[2];
  real_T c2_outSizeT[2];
  real_T c2_padSizeT[2];
  real_T c2_startT[2];
  real_T c2_numKernElem;
  int32_T c2_nonzero_h_size[1];
  int32_T c2_b_i;
  int32_T c2_c_i;
  int32_T c2_d_i;
  int32_T c2_end;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_partialTrueCount;
  int32_T c2_trueCount;
  boolean_T c2_conn[25];
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  boolean_T c2_densityFlag;
  boolean_T c2_modeFlag;
  boolean_T c2_tooBig;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_bb_emlrtRSI;
  c2_padImage(chartInstance, &c2_st, c2_varargin_1, chartInstance->c2_aTmp);
  for (c2_i = 0; c2_i < 25; c2_i++) {
    c2_conn[c2_i] = (c2_varargin_2[c2_i] != 0.0);
  }

  c2_end = 25;
  c2_trueCount = 0;
  for (c2_b_i = 0; c2_b_i < c2_end; c2_b_i++) {
    if (c2_conn[c2_b_i]) {
      c2_trueCount++;
    }
  }

  c2_nonzero_h_size[0] = c2_trueCount;
  c2_partialTrueCount = 0;
  for (c2_c_i = 0; c2_c_i < c2_end; c2_c_i++) {
    if (c2_conn[c2_c_i]) {
      c2_nonzero_h_data[c2_partialTrueCount] = c2_varargin_2[c2_c_i];
      c2_partialTrueCount++;
    }
  }

  c2_densityFlag = false;
  if ((real_T)c2_nonzero_h_size[0] / 25.0 > 0.05) {
    c2_densityFlag = true;
  }

  c2_tooBig = true;
  for (c2_d_i = 0; c2_d_i < 2; c2_d_i++) {
    c2_tooBig = false;
  }

  if (c2_densityFlag && (!c2_tooBig)) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
      c2_padSizeT[c2_i1] = 724.0 + 560.0 * (real_T)c2_i1;
    }

    for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
      c2_outSizeT[c2_i3] = 720.0 + 560.0 * (real_T)c2_i3;
    }

    for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
      c2_connDimsT[c2_i5] = 5.0;
    }

    ippfilter_real64(&chartInstance->c2_aTmp[0], &c2_b[0], &c2_outSizeT[0], 2.0,
                     &c2_padSizeT[0], &c2_varargin_2[0], &c2_connDimsT[0], false);
  } else {
    c2_numKernElem = (real_T)c2_nonzero_h_size[0];
    for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
      c2_padSizeT[c2_i2] = 724.0 + 560.0 * (real_T)c2_i2;
    }

    for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
      c2_outSizeT[c2_i4] = 720.0 + 560.0 * (real_T)c2_i4;
    }

    for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
      c2_connDimsT[c2_i6] = 5.0;
    }

    for (c2_i7 = 0; c2_i7 < 2; c2_i7++) {
      c2_startT[c2_i7] = 2.0;
    }

    imfilter_real64(&chartInstance->c2_aTmp[0], &c2_b[0], 2.0, &c2_outSizeT[0],
                    2.0, &c2_padSizeT[0], &c2_nonzero_h_data[0], c2_numKernElem,
                    &c2_conn[0], 2.0, &c2_connDimsT[0], &c2_startT[0], 2.0, true,
                    false);
  }
}

static void c2_padImage(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, const emlrtStack *c2_sp, real_T c2_a_tmp[921600], real_T c2_a
  [929616])
{
  static int32_T c2_idxA[2568] = { 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,
    89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135,
    136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150,
    151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165,
    166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180,
    181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195,
    196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210,
    211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225,
    226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240,
    241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255,
    256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270,
    271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285,
    286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300,
    301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315,
    316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330,
    331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345,
    346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360,
    361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375,
    376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390,
    391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405,
    406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420,
    421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435,
    436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450,
    451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465,
    466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480,
    481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495,
    496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510,
    511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525,
    526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540,
    541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555,
    556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570,
    571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585,
    586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600,
    601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613, 614, 615,
    616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630,
    631, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645,
    646, 647, 648, 649, 650, 651, 652, 653, 654, 655, 656, 657, 658, 659, 660,
    661, 662, 663, 664, 665, 666, 667, 668, 669, 670, 671, 672, 673, 674, 675,
    676, 677, 678, 679, 680, 681, 682, 683, 684, 685, 686, 687, 688, 689, 690,
    691, 692, 693, 694, 695, 696, 697, 698, 699, 700, 701, 702, 703, 704, 705,
    706, 707, 708, 709, 710, 711, 712, 713, 714, 715, 716, 717, 718, 719, 720,
    720, 720, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
    46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
    65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
    84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101,
    102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
    117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131,
    132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
    147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161,
    162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176,
    177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191,
    192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206,
    207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221,
    222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236,
    237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251,
    252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266,
    267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281,
    282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296,
    297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311,
    312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326,
    327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341,
    342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356,
    357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371,
    372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386,
    387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401,
    402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416,
    417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431,
    432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446,
    447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461,
    462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476,
    477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491,
    492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506,
    507, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521,
    522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536,
    537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551,
    552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566,
    567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581,
    582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596,
    597, 598, 599, 600, 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611,
    612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626,
    627, 628, 629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641,
    642, 643, 644, 645, 646, 647, 648, 649, 650, 651, 652, 653, 654, 655, 656,
    657, 658, 659, 660, 661, 662, 663, 664, 665, 666, 667, 668, 669, 670, 671,
    672, 673, 674, 675, 676, 677, 678, 679, 680, 681, 682, 683, 684, 685, 686,
    687, 688, 689, 690, 691, 692, 693, 694, 695, 696, 697, 698, 699, 700, 701,
    702, 703, 704, 705, 706, 707, 708, 709, 710, 711, 712, 713, 714, 715, 716,
    717, 718, 719, 720, 721, 722, 723, 724, 725, 726, 727, 728, 729, 730, 731,
    732, 733, 734, 735, 736, 737, 738, 739, 740, 741, 742, 743, 744, 745, 746,
    747, 748, 749, 750, 751, 752, 753, 754, 755, 756, 757, 758, 759, 760, 761,
    762, 763, 764, 765, 766, 767, 768, 769, 770, 771, 772, 773, 774, 775, 776,
    777, 778, 779, 780, 781, 782, 783, 784, 785, 786, 787, 788, 789, 790, 791,
    792, 793, 794, 795, 796, 797, 798, 799, 800, 801, 802, 803, 804, 805, 806,
    807, 808, 809, 810, 811, 812, 813, 814, 815, 816, 817, 818, 819, 820, 821,
    822, 823, 824, 825, 826, 827, 828, 829, 830, 831, 832, 833, 834, 835, 836,
    837, 838, 839, 840, 841, 842, 843, 844, 845, 846, 847, 848, 849, 850, 851,
    852, 853, 854, 855, 856, 857, 858, 859, 860, 861, 862, 863, 864, 865, 866,
    867, 868, 869, 870, 871, 872, 873, 874, 875, 876, 877, 878, 879, 880, 881,
    882, 883, 884, 885, 886, 887, 888, 889, 890, 891, 892, 893, 894, 895, 896,
    897, 898, 899, 900, 901, 902, 903, 904, 905, 906, 907, 908, 909, 910, 911,
    912, 913, 914, 915, 916, 917, 918, 919, 920, 921, 922, 923, 924, 925, 926,
    927, 928, 929, 930, 931, 932, 933, 934, 935, 936, 937, 938, 939, 940, 941,
    942, 943, 944, 945, 946, 947, 948, 949, 950, 951, 952, 953, 954, 955, 956,
    957, 958, 959, 960, 961, 962, 963, 964, 965, 966, 967, 968, 969, 970, 971,
    972, 973, 974, 975, 976, 977, 978, 979, 980, 981, 982, 983, 984, 985, 986,
    987, 988, 989, 990, 991, 992, 993, 994, 995, 996, 997, 998, 999, 1000, 1001,
    1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014,
    1015, 1016, 1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026, 1027,
    1028, 1029, 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037, 1038, 1039, 1040,
    1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052, 1053,
    1054, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1065, 1066,
    1067, 1068, 1069, 1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079,
    1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 1089, 1090, 1091, 1092,
    1093, 1094, 1095, 1096, 1097, 1098, 1099, 1100, 1101, 1102, 1103, 1104, 1105,
    1106, 1107, 1108, 1109, 1110, 1111, 1112, 1113, 1114, 1115, 1116, 1117, 1118,
    1119, 1120, 1121, 1122, 1123, 1124, 1125, 1126, 1127, 1128, 1129, 1130, 1131,
    1132, 1133, 1134, 1135, 1136, 1137, 1138, 1139, 1140, 1141, 1142, 1143, 1144,
    1145, 1146, 1147, 1148, 1149, 1150, 1151, 1152, 1153, 1154, 1155, 1156, 1157,
    1158, 1159, 1160, 1161, 1162, 1163, 1164, 1165, 1166, 1167, 1168, 1169, 1170,
    1171, 1172, 1173, 1174, 1175, 1176, 1177, 1178, 1179, 1180, 1181, 1182, 1183,
    1184, 1185, 1186, 1187, 1188, 1189, 1190, 1191, 1192, 1193, 1194, 1195, 1196,
    1197, 1198, 1199, 1200, 1201, 1202, 1203, 1204, 1205, 1206, 1207, 1208, 1209,
    1210, 1211, 1212, 1213, 1214, 1215, 1216, 1217, 1218, 1219, 1220, 1221, 1222,
    1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231, 1232, 1233, 1234, 1235,
    1236, 1237, 1238, 1239, 1240, 1241, 1242, 1243, 1244, 1245, 1246, 1247, 1248,
    1249, 1250, 1251, 1252, 1253, 1254, 1255, 1256, 1257, 1258, 1259, 1260, 1261,
    1262, 1263, 1264, 1265, 1266, 1267, 1268, 1269, 1270, 1271, 1272, 1273, 1274,
    1275, 1276, 1277, 1278, 1279, 1280, 1280, 1280 };

  emlrtStack c2_st;
  real_T c2_b_i;
  real_T c2_b_j;
  int32_T c2_c_i;
  int32_T c2_i;
  int32_T c2_j;
  (void)chartInstance;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_st.site = &c2_db_emlrtRSI;
  for (c2_j = 0; c2_j < 1284; c2_j++) {
    c2_b_j = (real_T)c2_j + 1.0;
    for (c2_i = 0; c2_i < 724; c2_i++) {
      c2_b_i = (real_T)c2_i + 1.0;
      if ((c2_idxA[(int32_T)c2_b_i - 1] < 1) || (c2_idxA[(int32_T)c2_b_i - 1] >
           720)) {
        emlrtDynamicBoundsCheckR2012b(c2_idxA[(int32_T)c2_b_i - 1], 1, 720,
          &c2_o_emlrtBCI, &c2_st);
      }

      c2_c_i = c2_idxA[(int32_T)c2_b_j + 1283];
      if ((c2_c_i < 1) || (c2_c_i > 1280)) {
        emlrtDynamicBoundsCheckR2012b(c2_c_i, 1, 1280, &c2_p_emlrtBCI, &c2_st);
      }

      c2_a[((int32_T)c2_b_i + 724 * ((int32_T)c2_b_j - 1)) - 1] = c2_a_tmp
        [(c2_idxA[(int32_T)c2_b_i - 1] + 720 * (c2_c_i - 1)) - 1];
    }
  }
}

const mxArray
  *sf_c2_step2_compression_simulation_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static real_T c2_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_nullptr, const char_T *c2_identifier)
{
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nullptr), &c2_thisId);
  sf_mex_destroy(&c2_nullptr);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_d;
  real_T c2_y;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_nullptr, const char_T *c2_identifier, uint8_T c2_y[2764800])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nullptr), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_nullptr);
}

static void c2_d_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId, uint8_T c2_y[2764800])
{
  int32_T c2_i;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), chartInstance->c2_c_uv, 1, 3, 0U,
                1, 0U, 3, 720, 1280, 3);
  for (c2_i = 0; c2_i < 2764800; c2_i++) {
    c2_y[c2_i] = chartInstance->c2_c_uv[c2_i];
  }

  sf_mex_destroy(&c2_u);
}

static real_T c2_e_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_nullptr, const char_T *c2_identifier, boolean_T *c2_svPtr)
{
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nullptr), &c2_thisId,
    c2_svPtr);
  sf_mex_destroy(&c2_nullptr);
  return c2_y;
}

static real_T c2_f_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T *c2_svPtr)
{
  real_T c2_d;
  real_T c2_y;
  (void)chartInstance;
  if (mxIsEmpty(c2_u)) {
    *c2_svPtr = false;
  } else {
    *c2_svPtr = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_g_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_nullptr, const char_T *c2_identifier, boolean_T *c2_svPtr, uint8_T c2_y
   [2764800])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nullptr), &c2_thisId,
                        c2_svPtr, c2_y);
  sf_mex_destroy(&c2_nullptr);
}

static void c2_h_emlrt_marshallIn
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T *c2_svPtr, uint8_T
   c2_y[2764800])
{
  int32_T c2_i;
  if (mxIsEmpty(c2_u)) {
    *c2_svPtr = false;
  } else {
    *c2_svPtr = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), chartInstance->c2_b_uv, 1, 3,
                  0U, 1, 0U, 3, 720, 1280, 3);
    for (c2_i = 0; c2_i < 2764800; c2_i++) {
      c2_y[c2_i] = chartInstance->c2_b_uv[c2_i];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_slStringInitializeDynamicBuffers
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_array_real_T_2D_SetSize
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const
   emlrtStack *c2_sp, c2_coder_array_real_T_2D *c2_coderArray, const
   emlrtRTEInfo *c2_srcLocation, int32_T c2_size0, int32_T c2_size1)
{
  real_T *c2_newData;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  (void)chartInstance;
  c2_coderArray->size[0] = c2_size0;
  c2_coderArray->size[1] = c2_size1;
  c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c2_coderArray->size[0],
                       c2_srcLocation, (void *)c2_sp), (size_t)(uint32_T)
    c2_coderArray->size[1], c2_srcLocation, (void *)c2_sp);
  if (c2_newNumel > c2_coderArray->vector.allocated) {
    c2_newCapacity = c2_coderArray->vector.allocated;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c2_newCapacity);
    if ((void *)c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if ((void *)c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_coderArray->vector.data != NULL) {
      memcpy(c2_newData, c2_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c2_coderArray->vector.numel);
      if (c2_coderArray->vector.owner) {
        emlrtFreeMex(c2_coderArray->vector.data);
      }
    }

    c2_coderArray->vector.data = c2_newData;
    c2_coderArray->vector.allocated = c2_newCapacity;
    c2_coderArray->vector.owner = true;
  }

  c2_coderArray->vector.numel = c2_newNumel;
}

static void c2_array_real_T_SetSize
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const
   emlrtStack *c2_sp, c2_coder_array_real_T *c2_coderArray, const emlrtRTEInfo
   *c2_srcLocation, int32_T c2_size0)
{
  real_T *c2_newData;
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  (void)chartInstance;
  c2_coderArray->size[0] = c2_size0;
  c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c2_coderArray->size[0], c2_srcLocation, (void *)c2_sp);
  if (c2_newNumel > c2_coderArray->vector.allocated) {
    c2_newCapacity = c2_coderArray->vector.allocated;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c2_newCapacity);
    if ((void *)c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if ((void *)c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_coderArray->vector.data != NULL) {
      memcpy(c2_newData, c2_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c2_coderArray->vector.numel);
      if (c2_coderArray->vector.owner) {
        emlrtFreeMex(c2_coderArray->vector.data);
      }
    }

    c2_coderArray->vector.data = c2_newData;
    c2_coderArray->vector.allocated = c2_newCapacity;
    c2_coderArray->vector.owner = true;
  }

  c2_coderArray->vector.numel = c2_newNumel;
}

static void c2_array_int32_T_2D_SetSize
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance, const
   emlrtStack *c2_sp, c2_coder_array_int32_T_2D *c2_coderArray, const
   emlrtRTEInfo *c2_srcLocation, int32_T c2_size0, int32_T c2_size1)
{
  int32_T c2_newCapacity;
  int32_T c2_newNumel;
  int32_T *c2_newData;
  (void)chartInstance;
  c2_coderArray->size[0] = c2_size0;
  c2_coderArray->size[1] = c2_size1;
  c2_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c2_coderArray->size[0],
                       c2_srcLocation, (void *)c2_sp), (size_t)(uint32_T)
    c2_coderArray->size[1], c2_srcLocation, (void *)c2_sp);
  if (c2_newNumel > c2_coderArray->vector.allocated) {
    c2_newCapacity = c2_coderArray->vector.allocated;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c2_newCapacity);
    if ((void *)c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if ((void *)c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, (void *)c2_sp);
    }

    if (c2_coderArray->vector.data != NULL) {
      memcpy(c2_newData, c2_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c2_coderArray->vector.numel);
      if (c2_coderArray->vector.owner) {
        emlrtFreeMex(c2_coderArray->vector.data);
      }
    }

    c2_coderArray->vector.data = c2_newData;
    c2_coderArray->vector.allocated = c2_newCapacity;
    c2_coderArray->vector.owner = true;
  }

  c2_coderArray->vector.numel = c2_newNumel;
}

static void c2_array_real_T_2D_Constructor
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance,
   c2_coder_array_real_T_2D *c2_coderArray)
{
  (void)chartInstance;
  c2_coderArray->vector.data = (real_T *)NULL;
  c2_coderArray->vector.numel = 0;
  c2_coderArray->vector.allocated = 0;
  c2_coderArray->vector.owner = true;
  c2_coderArray->size[0] = 0;
  c2_coderArray->size[1] = 0;
}

static void c2_array_real_T_Constructor
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance,
   c2_coder_array_real_T *c2_coderArray)
{
  (void)chartInstance;
  c2_coderArray->vector.data = (real_T *)NULL;
  c2_coderArray->vector.numel = 0;
  c2_coderArray->vector.allocated = 0;
  c2_coderArray->vector.owner = true;
  c2_coderArray->size[0] = 0;
}

static void c2_array_real_T_2D_Destructor
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance,
   c2_coder_array_real_T_2D *c2_coderArray)
{
  (void)chartInstance;
  if (c2_coderArray->vector.owner && (c2_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c2_coderArray->vector.data);
  }
}

static void c2_array_real_T_Destructor
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance,
   c2_coder_array_real_T *c2_coderArray)
{
  (void)chartInstance;
  if (c2_coderArray->vector.owner && (c2_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c2_coderArray->vector.data);
  }
}

static void c2_array_int32_T_2D_Constructor
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance,
   c2_coder_array_int32_T_2D *c2_coderArray)
{
  (void)chartInstance;
  c2_coderArray->vector.data = (int32_T *)NULL;
  c2_coderArray->vector.numel = 0;
  c2_coderArray->vector.allocated = 0;
  c2_coderArray->vector.owner = true;
  c2_coderArray->size[0] = 0;
  c2_coderArray->size[1] = 0;
}

static void c2_array_int32_T_2D_Destructor
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance,
   c2_coder_array_int32_T_2D *c2_coderArray)
{
  (void)chartInstance;
  if (c2_coderArray->vector.owner && (c2_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c2_coderArray->vector.data);
  }
}

static int32_T c2__s32_s64_(SFc2_step2_compression_simulationInstanceStruct
  *chartInstance, int64_T c2_b, int32_T c2_EMLOvCount_src_loc, uint32_T
  c2_ssid_src_loc, int32_T c2_offset_src_loc, int32_T c2_length_src_loc)
{
  int32_T c2_a;
  (void)c2_EMLOvCount_src_loc;
  c2_a = (int32_T)c2_b;
  if ((int64_T)c2_a != c2_b) {
    sf_data_overflow_error(chartInstance->S, c2_ssid_src_loc, c2_offset_src_loc,
      c2_length_src_loc);
  }

  return c2_a;
}

static void init_dsm_address_info
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc2_step2_compression_simulationInstanceStruct *chartInstance)
{
  chartInstance->c2_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_b_frame = (real32_T (*)[2764800])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c2_b_compressed = (uint8_T (*)[2764800])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c2_target_bitrate_mbps = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_actual_bitrate = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_compression_ratio = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c2_step2_compression_simulation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4088655040U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2755030368U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2170022776U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1143026551U);
}

mxArray *sf_c2_step2_compression_simulation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,2);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  return(mxcell3p);
}

mxArray *sf_c2_step2_compression_simulation_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("ippfilter_real64");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_step2_compression_simulation_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_step2_compression_simulation(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDewM7AwAakOYCYiQECWKF8RgaIHCNcnAUurgDEJZUFqSDx4qJkzxQgnZeYC+Y"
    "nllZ45qXlg823YECYz4bFfEYk8zmh4hDwwZ4y/TIOIP0OSPpZsOjnQ9IvAOUnJpeUJubEJ2WWFC"
    "WWpELEYOE1cP4RIco/XGj+AfGT83MLilKLi1NTEP4YeP8ogP3jQcA/gmj+EUTyT2Z+XjwwhjLzG"
    "ajpLwEHyvRD7CcUT9xo/gLx04qAGSg+Ob80rwRuzgUG/PmTES1/MiHl2xyGTIYCLO7B5h8mNP8I"
    "wKMpwwFMN2RSJVyGSvwIoMUPCOckFpfElyXmZKbEg6NqUMQPQzYkfhhyR1T8YCvnSvJLIMV2McP"
    "gyT8LMiHx8yCLavEDAFunSdc="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_step2_compression_simulation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sUyeaEDwL6oHPW8URPHdqVF";
}

static void sf_opaque_initialize_c2_step2_compression_simulation(void
  *chartInstanceVar)
{
  initialize_params_c2_step2_compression_simulation
    ((SFc2_step2_compression_simulationInstanceStruct*) chartInstanceVar);
  initialize_c2_step2_compression_simulation
    ((SFc2_step2_compression_simulationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_step2_compression_simulation(void
  *chartInstanceVar)
{
  enable_c2_step2_compression_simulation
    ((SFc2_step2_compression_simulationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_step2_compression_simulation(void
  *chartInstanceVar)
{
  disable_c2_step2_compression_simulation
    ((SFc2_step2_compression_simulationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_step2_compression_simulation(void
  *chartInstanceVar)
{
  sf_gateway_c2_step2_compression_simulation
    ((SFc2_step2_compression_simulationInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_step2_compression_simulation
  (SimStruct* S)
{
  return get_sim_state_c2_step2_compression_simulation
    ((SFc2_step2_compression_simulationInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_step2_compression_simulation(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c2_step2_compression_simulation
    ((SFc2_step2_compression_simulationInstanceStruct*)sf_get_chart_instance_ptr
     (S), st);
}

static void sf_opaque_cleanup_runtime_resources_c2_step2_compression_simulation
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_step2_compression_simulationInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_step2_compression_simulation_optimization_info();
    }

    mdl_cleanup_runtime_resources_c2_step2_compression_simulation
      ((SFc2_step2_compression_simulationInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c2_step2_compression_simulation(void
  *chartInstanceVar)
{
  mdl_start_c2_step2_compression_simulation
    ((SFc2_step2_compression_simulationInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo
      (((SFc2_step2_compression_simulationInstanceStruct*)chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c2_step2_compression_simulation(void
  *chartInstanceVar)
{
  mdl_terminate_c2_step2_compression_simulation
    ((SFc2_step2_compression_simulationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_step2_compression_simulation(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_step2_compression_simulation
      ((SFc2_step2_compression_simulationInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c2_step2_compression_simulation_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [24] = {
    "eNrlWU1v40QYnoRSdktZtRISHBaxx70glS6glUCQbj5oUEujTdqVuISJ/SaZ7XjszkfSwIUzR04",
    "cuSJx4BfwB7hw5MhP4MiRd2wnDY5JbafatmDJdSfJM++8zzzvxySk1DwkeN3D+8+3CFnH5x28yy",
    "S6Xo7Hpbk7en2NfBSPWxuEOEMqdVP0fZL/cnwXBiDapt9n5zmxwngtKqmnCtgV1IOnoHxuNPNFv",
    "sUz0QcJwsEJAl/qXHYV8wxn4rRhhGMtq2dD5gzbQ99w9wlOSN0jwSf/ZjcwuoUWa0yCoxsArh5K",
    "3wyGDU4Hy1mQelwdgnOqjJebKwW6bQLrqjo0XLOAQ/0cnKZQmiIL6hJ/25pqqOrz3Aphqj1F+17",
    "AGRXZuR5S1YYA1aHhOHDx75HRyF5Gu2ivxwTVvmSU1z1etQrPiG1xXOchyprn5ll7ugY9MxgwMb",
    "DsSuOBQP9RJxm46lf9EUg6gCORMwatd/XzcINnusweg00ry0IxaLxoV1QhbGi3PkKGVEG7DUdUK",
    "ecqH7bjBwcwAh7ar1FNC2Aj+znASjG3459QaaMgZyQZwc4MxNiqL1yWfYdHCVSYcD/H5JkBzjwr",
    "KXCR5tnSZxNdpkmjtO9VMYxqBwcZ7S1im0KD7FMHMuc+SZkCXHCoq5x2XaZoj1s0sqRDLzPPAKI",
    "wlKi+EbWxL0+R47xJ9oIrGwn50OAOoAYawoRRR3WfUG4yrtlTmOGsPI4VZqx8dhFr46cQ2KHOEF",
    "xbTxiHQ1B2ApU5P2Md2UNvR0xPaqAcyYKskWQUuFhILEudSQDH4lT4Y9GQvteOO4IlugLArEGlw",
    "LLwBMuSnDRw8dlWLeGsY5VVpD3zqOa0Z7XxKQisLNZXWwmpg1FVF9i64YJWwbbZV1jahWJKYzs1",
    "qYcx4Ib96JulfP3odjx+NIulpupI3CmKZVhgp7TXC5s96DAPwhfaFHuKaBhf1u4OubB7t7zcbhn",
    "/KxXEkRVxrTncWgo/b8/htuKxs9tFooPdroPyl6h93JNu2JBGLUZyPZsZeE/zI4kjC7gLvqfPh3",
    "P4UopdMve8jLfyAm/IXCnCVeZwryXsrCVw6zF3P332/LuNh99+/+HO5q/rX//y4yo6+fJOPl3fi",
    "8f3p33arJKNFpK9/ez+Jbp4I6ELO1bHE6D12vjgA3+/9ezx8dPWvnt20gjn+/mV5etdT6x3+voD",
    "vDUmujBvSqfpxmcuO6YmOgvY+R/PrXf9Ej7uzukJT6yfrIa/X0nqIY2vewm+7BhzmKG822PaHi/",
    "+qePr8+f1TP5sJPzZCM/gUToAdzEur8+fB5Uset5O+LM9549Nb2HlIVfp11ZlNfxiHkrz69WEX3",
    "bcx9YbMHmb+Bxs5/mN5Msn5bm45YSRIGU9af6UE/5szbZpWAmf37Ar4eW27M9WYn/szanS3RHlz",
    "O2GW3Uj9oecVuKO7H+1P2l5Tvs6StuK3Jz4+YFF+/PH8yvdn9vSx9503FXysplRX0VwLxXEkReM",
    "W9W/vOeE2/75nSV5jiQ+v3WD/ViWn/KcF2+aX7/nrB/Tc/nHs+90q0PG3ZRvleK3D4D20979j+j",
    "7r5z8Tc+vdctf/KPUF4/2BOUTxaK6Pn25Je3vIbO3JFCV/l3dddShrH3MZiK+7XjMhOuP1Tvv7r",
    "7/3ip17W/L0kBg",
    ""
  };

  static char newstr [1665] = "";
  newstr[0] = '\0';
  for (i = 0; i < 24; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c2_step2_compression_simulation(SimStruct *S)
{
  const char* newstr = sf_c2_step2_compression_simulation_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2456439468U));
  ssSetChecksum1(S,(2559191050U));
  ssSetChecksum2(S,(3406573627U));
  ssSetChecksum3(S,(2847832838U));
}

static void mdlRTW_c2_step2_compression_simulation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c2_step2_compression_simulation(SimStruct
  *S)
{
  SFc2_step2_compression_simulationInstanceStruct *chartInstance;
  chartInstance = (SFc2_step2_compression_simulationInstanceStruct *)utMalloc
    (sizeof(SFc2_step2_compression_simulationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc2_step2_compression_simulationInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && sfHasContStates(S)> 0 &&
      !supportsLegacyBehaviorForPersistentVarInContinuousTime(S)) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_step2_compression_simulation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_step2_compression_simulation;
  chartInstance->chartInfo.mdlStart =
    sf_opaque_mdl_start_c2_step2_compression_simulation;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c2_step2_compression_simulation;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c2_step2_compression_simulation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_step2_compression_simulation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_step2_compression_simulation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_step2_compression_simulation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_step2_compression_simulation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_step2_compression_simulation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_step2_compression_simulation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_step2_compression_simulation;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c2_step2_compression_simulation(chartInstance);
}

void c2_step2_compression_simulation_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c2_step2_compression_simulation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_step2_compression_simulation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_step2_compression_simulation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_step2_compression_simulation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
