/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ShallowWaterModel.c
 *
 * Code generation for function 'ShallowWaterModel'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "GaussianFcn.h"
#include "GeostrophicFcn.h"
#include "GradientFcn.h"
#include "ShallowWaterModel.h"
#include "ShallowWaterModel_emxutil.h"
#include "rdivide_helper.h"
#include "sprintf.h"
#include "sqrt.h"
#include "ShallowWaterModel_data.h"

/* Function Declarations */
static void ApplyBoundaryConditions(emxArray_real_T *x, double n_res);
static void CalculateXFluxes(const emxArray_real_T *h, const emxArray_real_T *hu,
  const emxArray_real_T *hv, double n_res, emxArray_real_T *F);
static void CalculateYFluxes(const emxArray_real_T *h, const emxArray_real_T *hu,
  const emxArray_real_T *hv, double n_res, emxArray_real_T *F);
static void UpdateXFluxes(emxArray_real_T *h, emxArray_real_T *hu,
  emxArray_real_T *hv, const emxArray_real_T *XFlux, double n_res, double dx,
  double dt);
static void UpdateYFluxes(emxArray_real_T *h, emxArray_real_T *hu,
  emxArray_real_T *hv, const emxArray_real_T *YFlux, double n_res, double dx,
  double dt);

/* Function Definitions */
static void ApplyBoundaryConditions(emxArray_real_T *x, double n_res)
{
  emxArray_real_T *b_x;
  int loop_ub;
  int i31;
  int i32;
  int b_loop_ub;
  int i33;
  int i34;
  emxArray_real_T *c_x;

  /*  Apply boundary conditions to variable x */
  emxInit_real_T(&b_x, 2);
  loop_ub = x->size[1] - 1;
  i31 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 2;
  b_x->size[1] = loop_ub + 1;
  emxEnsureCapacity_real_T(b_x, i31);
  for (i31 = 0; i31 <= loop_ub; i31++) {
    i32 = i31 << 1;
    b_x->data[i32] = x->data[((int)(n_res + 1.0) + x->size[0] * i31) - 1];
    b_x->data[1 + i32] = x->data[((int)(n_res + 2.0) + x->size[0] * i31) - 1];
  }

  loop_ub = b_x->size[1];
  for (i31 = 0; i31 < loop_ub; i31++) {
    i32 = i31 << 1;
    x->data[x->size[0] * i31] = b_x->data[i32];
    x->data[1 + x->size[0] * i31] = b_x->data[1 + i32];
  }

  if ((n_res + 2.0) + 1.0 > n_res + 4.0) {
    i31 = -1;
    i32 = 0;
  } else {
    i31 = (int)((n_res + 2.0) + 1.0) - 2;
    i32 = (int)(n_res + 4.0);
  }

  loop_ub = x->size[1];
  b_loop_ub = x->size[1] - 1;
  i33 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 2;
  b_x->size[1] = b_loop_ub + 1;
  emxEnsureCapacity_real_T(b_x, i33);
  for (i33 = 0; i33 <= b_loop_ub; i33++) {
    i34 = i33 << 1;
    b_x->data[i34] = x->data[x->size[0] * i33 + 2];
    b_x->data[1 + i34] = x->data[x->size[0] * i33 + 3];
  }

  b_loop_ub = (i32 - i31) - 1;
  for (i32 = 0; i32 < loop_ub; i32++) {
    for (i33 = 0; i33 < b_loop_ub; i33++) {
      x->data[((i31 + i33) + x->size[0] * i32) + 1] = b_x->data[i33 + b_loop_ub *
        i32];
    }
  }

  emxFree_real_T(&b_x);
  emxInit_real_T(&c_x, 2);
  loop_ub = x->size[0] - 1;
  i31 = c_x->size[0] * c_x->size[1];
  c_x->size[0] = loop_ub + 1;
  c_x->size[1] = 2;
  emxEnsureCapacity_real_T(c_x, i31);
  for (i31 = 0; i31 <= loop_ub; i31++) {
    c_x->data[i31] = x->data[i31 + x->size[0] * ((int)(n_res + 1.0) - 1)];
  }

  for (i31 = 0; i31 <= loop_ub; i31++) {
    c_x->data[i31 + c_x->size[0]] = x->data[i31 + x->size[0] * ((int)(n_res +
      2.0) - 1)];
  }

  loop_ub = c_x->size[0];
  for (i31 = 0; i31 < loop_ub; i31++) {
    x->data[i31] = c_x->data[i31];
  }

  loop_ub = c_x->size[0];
  for (i31 = 0; i31 < loop_ub; i31++) {
    x->data[i31 + x->size[0]] = c_x->data[i31 + c_x->size[0]];
  }

  if ((n_res + 2.0) + 1.0 > n_res + 4.0) {
    i31 = -1;
    i32 = 0;
  } else {
    i31 = (int)((n_res + 2.0) + 1.0) - 2;
    i32 = (int)(n_res + 4.0);
  }

  loop_ub = x->size[0];
  b_loop_ub = x->size[0] - 1;
  i33 = c_x->size[0] * c_x->size[1];
  c_x->size[0] = b_loop_ub + 1;
  c_x->size[1] = 2;
  emxEnsureCapacity_real_T(c_x, i33);
  for (i33 = 0; i33 <= b_loop_ub; i33++) {
    c_x->data[i33] = x->data[i33 + x->size[0] * 2];
  }

  for (i33 = 0; i33 <= b_loop_ub; i33++) {
    c_x->data[i33 + c_x->size[0]] = x->data[i33 + x->size[0] * 3];
  }

  b_loop_ub = (i32 - i31) - 1;
  for (i32 = 0; i32 < b_loop_ub; i32++) {
    for (i33 = 0; i33 < loop_ub; i33++) {
      x->data[i33 + x->size[0] * ((i31 + i32) + 1)] = c_x->data[i33 + loop_ub *
        i32];
    }
  }

  emxFree_real_T(&c_x);
}

static void CalculateXFluxes(const emxArray_real_T *h, const emxArray_real_T *hu,
  const emxArray_real_T *hv, double n_res, emxArray_real_T *F)
{
  int i;
  int i27;
  int i28;
  int loop_ub;
  double h_left;
  double hu_left;
  double hv_left;
  double h_right;
  double hu_right;
  double hv_right;
  double max_wave_speed;

  /*  Calculate fluxes in the X direction */
  /*  Allocate fluxes */
  i = F->size[0] * F->size[1] * F->size[2];
  i27 = (int)(n_res + 1.0);
  F->size[0] = i27;
  i28 = (int)n_res;
  F->size[1] = i28;
  F->size[2] = 3;
  emxEnsureCapacity_real_T(F, i);
  loop_ub = i27 * i28 * 3;
  for (i = 0; i < loop_ub; i++) {
    F->data[i] = 0.0;
  }

  /*  Loop through all edges of constant X */
  for (i = 0; i < i27; i++) {
    for (loop_ub = 0; loop_ub < i28; loop_ub++) {
      /*  Calculate left state (to 2nd order accuracy) */
      h_left = (0.25 * h->data[(i + h->size[0] * (loop_ub + 2)) + 2] + h->data
                [(i + h->size[0] * (loop_ub + 2)) + 1]) - 0.25 * h->data[i +
        h->size[0] * (loop_ub + 2)];
      hu_left = (0.25 * hu->data[(i + hu->size[0] * (loop_ub + 2)) + 2] +
                 hu->data[(i + hu->size[0] * (loop_ub + 2)) + 1]) - 0.25 *
        hu->data[i + hu->size[0] * (loop_ub + 2)];
      hv_left = (0.25 * hv->data[(i + hv->size[0] * (loop_ub + 2)) + 2] +
                 hv->data[(i + hv->size[0] * (loop_ub + 2)) + 1]) - 0.25 *
        hv->data[i + hv->size[0] * (loop_ub + 2)];

      /*  Calculate right state (to 2nd order accuracy) */
      h_right = (0.25 * h->data[(i + h->size[0] * (loop_ub + 2)) + 1] + h->data
                 [(i + h->size[0] * (loop_ub + 2)) + 2]) - 0.25 * h->data[(i +
        h->size[0] * (loop_ub + 2)) + 3];
      hu_right = (0.25 * hu->data[(i + hu->size[0] * (loop_ub + 2)) + 1] +
                  hu->data[(i + hu->size[0] * (loop_ub + 2)) + 2]) - 0.25 *
        hu->data[(i + hu->size[0] * (loop_ub + 2)) + 3];
      hv_right = (0.25 * hv->data[(i + hv->size[0] * (loop_ub + 2)) + 1] +
                  hv->data[(i + hv->size[0] * (loop_ub + 2)) + 2]) - 0.25 *
        hv->data[(i + hv->size[0] * (loop_ub + 2)) + 3];

      /*  Left flux */
      /*  Max wave speed */
      max_wave_speed = fabs(0.5 * (hu_left / h_left + hu_right / h_right)) +
        sqrt(gravity * 0.5 * (h_left + h_right));

      /*  Calculate flux */
      F->data[i + F->size[0] * loop_ub] = 0.5 * (hu_left + hu_right) - 0.5 *
        max_wave_speed * (h_right - h_left);
      F->data[(i + F->size[0] * loop_ub) + F->size[0] * F->size[1]] = 0.5 *
        ((hu_left * hu_left / h_left + 0.5 * gravity * h_left * h_left) +
         (hu_right * hu_right / h_right + 0.5 * gravity * h_right * h_right)) -
        0.5 * max_wave_speed * (hu_right - hu_left);
      F->data[(i + F->size[0] * loop_ub) + ((F->size[0] * F->size[1]) << 1)] =
        0.5 * (hu_left * hv_left / h_left + hu_right * hv_right / h_right) - 0.5
        * max_wave_speed * (hv_right - hv_left);
    }
  }
}

static void CalculateYFluxes(const emxArray_real_T *h, const emxArray_real_T *hu,
  const emxArray_real_T *hv, double n_res, emxArray_real_T *F)
{
  int i;
  int i29;
  int i30;
  int loop_ub;
  double h_left;
  double hu_left;
  double hv_left;
  double h_right;
  double hu_right;
  double hv_right;
  double max_wave_speed;

  /*  Calculate fluxes in the Y direction */
  /*  Allocate fluxes */
  i = F->size[0] * F->size[1] * F->size[2];
  i29 = (int)n_res;
  F->size[0] = i29;
  i30 = (int)(n_res + 1.0);
  F->size[1] = i30;
  F->size[2] = 3;
  emxEnsureCapacity_real_T(F, i);
  loop_ub = i29 * i30 * 3;
  for (i = 0; i < loop_ub; i++) {
    F->data[i] = 0.0;
  }

  /*  Loop through all edges of constant Y */
  for (i = 0; i < i29; i++) {
    for (loop_ub = 0; loop_ub < i30; loop_ub++) {
      /*  Calculate left state (to 2nd order accuracy) */
      h_left = (0.25 * h->data[(i + h->size[0] * (loop_ub + 2)) + 2] + h->data
                [(i + h->size[0] * (loop_ub + 1)) + 2]) - 0.25 * h->data[(i +
        h->size[0] * loop_ub) + 2];
      hu_left = (0.25 * hu->data[(i + hu->size[0] * (loop_ub + 2)) + 2] +
                 hu->data[(i + hu->size[0] * (loop_ub + 1)) + 2]) - 0.25 *
        hu->data[(i + hu->size[0] * loop_ub) + 2];
      hv_left = (0.25 * hv->data[(i + hv->size[0] * (loop_ub + 2)) + 2] +
                 hv->data[(i + hv->size[0] * (loop_ub + 1)) + 2]) - 0.25 *
        hv->data[(i + hv->size[0] * loop_ub) + 2];

      /*  Calculate right state (to 2nd order accuracy) */
      h_right = (0.25 * h->data[(i + h->size[0] * (loop_ub + 1)) + 2] + h->data
                 [(i + h->size[0] * (loop_ub + 2)) + 2]) - 0.25 * h->data[(i +
        h->size[0] * (loop_ub + 3)) + 2];
      hu_right = (0.25 * hu->data[(i + hu->size[0] * (loop_ub + 1)) + 2] +
                  hu->data[(i + hu->size[0] * (loop_ub + 2)) + 2]) - 0.25 *
        hu->data[(i + hu->size[0] * (loop_ub + 3)) + 2];
      hv_right = (0.25 * hv->data[(i + hv->size[0] * (loop_ub + 1)) + 2] +
                  hv->data[(i + hv->size[0] * (loop_ub + 2)) + 2]) - 0.25 *
        hv->data[(i + hv->size[0] * (loop_ub + 3)) + 2];

      /*  Left flux */
      /*  Max wave speed */
      max_wave_speed = fabs(0.5 * (hv_left / h_left + hv_right / h_right)) +
        sqrt(gravity * 0.5 * (h_left + h_right));

      /*  Calculate flux */
      F->data[i + F->size[0] * loop_ub] = 0.5 * (hv_left + hv_right) - 0.5 *
        max_wave_speed * (h_right - h_left);
      F->data[(i + F->size[0] * loop_ub) + F->size[0] * F->size[1]] = 0.5 *
        (hu_left * hv_left / h_left + hu_right * hv_right / h_right) - 0.5 *
        max_wave_speed * (hu_right - hu_left);
      F->data[(i + F->size[0] * loop_ub) + ((F->size[0] * F->size[1]) << 1)] =
        0.5 * ((hv_left * hv_left / h_left + 0.5 * gravity * h_left * h_left) +
               (hv_right * hv_right / h_right + 0.5 * gravity * h_right *
                h_right)) - 0.5 * max_wave_speed * (hv_right - hv_left);
    }
  }
}

static void UpdateXFluxes(emxArray_real_T *h, emxArray_real_T *hu,
  emxArray_real_T *hv, const emxArray_real_T *XFlux, double n_res, double dx,
  double dt)
{
  int i35;
  int i;
  int i36;
  int j;
  double d1;

  /*  Update X fluxes */
  i35 = (int)(n_res + 1.0);
  for (i = 0; i < i35; i++) {
    i36 = (int)n_res;
    for (j = 0; j < i36; j++) {
      d1 = dt / dx;
      h->data[(i + h->size[0] * (j + 2)) + 2] += d1 * XFlux->data[i +
        XFlux->size[0] * j];
      h->data[(i + h->size[0] * (j + 2)) + 1] -= dt / dx * XFlux->data[i +
        XFlux->size[0] * j];
      hu->data[(i + hu->size[0] * (j + 2)) + 2] += d1 * XFlux->data[(i +
        XFlux->size[0] * j) + XFlux->size[0] * XFlux->size[1]];
      hu->data[(i + hu->size[0] * (j + 2)) + 1] -= dt / dx * XFlux->data[(i +
        XFlux->size[0] * j) + XFlux->size[0] * XFlux->size[1]];
      hv->data[(i + hv->size[0] * (j + 2)) + 2] += d1 * XFlux->data[(i +
        XFlux->size[0] * j) + ((XFlux->size[0] * XFlux->size[1]) << 1)];
      hv->data[(i + hv->size[0] * (j + 2)) + 1] -= dt / dx * XFlux->data[(i +
        XFlux->size[0] * j) + ((XFlux->size[0] * XFlux->size[1]) << 1)];
    }
  }
}

static void UpdateYFluxes(emxArray_real_T *h, emxArray_real_T *hu,
  emxArray_real_T *hv, const emxArray_real_T *YFlux, double n_res, double dx,
  double dt)
{
  int i37;
  int i;
  int i38;
  int j;
  double d2;

  /*  Update Y fluxes */
  i37 = (int)n_res;
  for (i = 0; i < i37; i++) {
    i38 = (int)(n_res + 1.0);
    for (j = 0; j < i38; j++) {
      d2 = dt / dx;
      h->data[(i + h->size[0] * (j + 2)) + 2] += d2 * YFlux->data[i +
        YFlux->size[0] * j];
      h->data[(i + h->size[0] * (j + 1)) + 2] -= dt / dx * YFlux->data[i +
        YFlux->size[0] * j];
      hu->data[(i + hu->size[0] * (j + 2)) + 2] += d2 * YFlux->data[(i +
        YFlux->size[0] * j) + YFlux->size[0] * YFlux->size[1]];
      hu->data[(i + hu->size[0] * (j + 1)) + 2] -= dt / dx * YFlux->data[(i +
        YFlux->size[0] * j) + YFlux->size[0] * YFlux->size[1]];
      hv->data[(i + hv->size[0] * (j + 2)) + 2] += d2 * YFlux->data[(i +
        YFlux->size[0] * j) + ((YFlux->size[0] * YFlux->size[1]) << 1)];
      hv->data[(i + hv->size[0] * (j + 1)) + 2] -= dt / dx * YFlux->data[(i +
        YFlux->size[0] * j) + ((YFlux->size[0] * YFlux->size[1]) << 1)];
    }
  }
}

void ShallowWaterModel(double fcnnum, double t_final, double n_res, const double
  x_domain[2], const double y_domain[2], emxArray_real_T *X, emxArray_real_T *Y,
  emxArray_real_T *T, emxArray_real_T *M, emxArray_real_T *Minit)
{
  double f;
  double dx;
  double wave_speed;
  emxArray_real_T *YEdge;
  int i0;
  int loop_ub;
  emxArray_real_T *XEdge;
  int i1;
  emxArray_real_T *h;
  int loop_ub_tmp;
  emxArray_real_T *hu;
  emxArray_real_T *hv;
  int i;
  int j;
  double d0;
  int i2;
  int i3;
  int b_loop_ub;
  emxArray_real_T *b_hu;
  int c_loop_ub;
  int d_loop_ub;
  emxArray_real_T *b_Minit;
  emxArray_real_T *r0;
  double max_wave_speed;
  emxArray_char_T *dt;
  emxArray_char_T *nt;
  double b_nt;
  emxArray_real_T *h_old;
  emxArray_real_T *hu_old;
  emxArray_real_T *hv_old;
  emxArray_real_T *XFlux;
  emxArray_real_T *YFlux;
  int i4;
  int i5;
  int i6;
  int i7;
  int e_loop_ub;
  int i8;
  int i9;
  int i10;
  int i11;
  int i12;
  int i13;
  int i14;
  int i15;
  int f_loop_ub;
  int g_loop_ub;
  int i16;
  int i17;
  int i18;
  int i19;
  int i20;
  int i21;
  int i22;
  int i23;
  int h_loop_ub;
  int i_loop_ub;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  ONLY MODIFY THESE PARAMETERS */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Constant of gravity */
  gravity = 9.80616;

  /*  Rotation rate */
  omega = 7.292E-5;

  /*  Latitude */
  phi0 = 0.78539816339744828;

  /*  CFL number */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Coriolis parameter */
  f = 2.0 * omega * sin(phi0);

  /*  Halo size */
  /*  Grid spacing */
  dx = (x_domain[1] - x_domain[0]) / n_res;
  wave_speed = (y_domain[1] - y_domain[0]) / n_res;

  /*  Initialize the grid */
  emxInit_real_T(&YEdge, 2);
  if (rtIsNaN(n_res + 1.0)) {
    i0 = YEdge->size[0] * YEdge->size[1];
    YEdge->size[0] = 1;
    YEdge->size[1] = 1;
    emxEnsureCapacity_real_T(YEdge, i0);
    YEdge->data[0] = rtNaN;
  } else if (n_res + 1.0 < 0.0) {
    YEdge->size[0] = 1;
    YEdge->size[1] = 0;
  } else if (rtIsInf(n_res + 1.0) && (0.0 == n_res + 1.0)) {
    i0 = YEdge->size[0] * YEdge->size[1];
    YEdge->size[0] = 1;
    YEdge->size[1] = 1;
    emxEnsureCapacity_real_T(YEdge, i0);
    YEdge->data[0] = rtNaN;
  } else {
    i0 = YEdge->size[0] * YEdge->size[1];
    YEdge->size[0] = 1;
    loop_ub = (int)floor(n_res + 1.0);
    YEdge->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(YEdge, i0);
    for (i0 = 0; i0 <= loop_ub; i0++) {
      YEdge->data[i0] = i0;
    }
  }

  emxInit_real_T(&XEdge, 2);
  i0 = XEdge->size[0] * XEdge->size[1];
  XEdge->size[0] = 1;
  XEdge->size[1] = YEdge->size[1];
  emxEnsureCapacity_real_T(XEdge, i0);
  loop_ub = YEdge->size[0] * YEdge->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    XEdge->data[i0] = YEdge->data[i0] * dx + x_domain[0];
  }

  i0 = YEdge->size[0] * YEdge->size[1];
  i1 = YEdge->size[0] * YEdge->size[1];
  YEdge->size[0] = 1;
  emxEnsureCapacity_real_T(YEdge, i1);
  loop_ub = i0 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    YEdge->data[i0] = YEdge->data[i0] * wave_speed + y_domain[0];
  }

  if (1.0 > n_res) {
    loop_ub = 0;
  } else {
    loop_ub = (int)n_res;
  }

  i0 = X->size[0] * X->size[1];
  X->size[0] = 1;
  X->size[1] = loop_ub;
  emxEnsureCapacity_real_T(X, i0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    X->data[i0] = 0.5 * (XEdge->data[i0] + XEdge->data[i0]);
  }

  emxFree_real_T(&XEdge);
  if (1.0 > n_res) {
    loop_ub = 0;
  } else {
    loop_ub = (int)n_res;
  }

  i0 = Y->size[0] * Y->size[1];
  Y->size[0] = 1;
  Y->size[1] = loop_ub;
  emxEnsureCapacity_real_T(Y, i0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Y->data[i0] = 0.5 * (YEdge->data[i0] + YEdge->data[i0]);
  }

  emxFree_real_T(&YEdge);
  emxInit_real_T(&h, 2);

  /*  Initialize the variables */
  i0 = h->size[0] * h->size[1];
  i1 = (int)(n_res + 4.0);
  h->size[0] = i1;
  h->size[1] = i1;
  emxEnsureCapacity_real_T(h, i0);
  loop_ub_tmp = i1 * i1;
  for (i0 = 0; i0 < loop_ub_tmp; i0++) {
    h->data[i0] = 0.0;
  }

  emxInit_real_T(&hu, 2);
  i0 = hu->size[0] * hu->size[1];
  hu->size[0] = i1;
  hu->size[1] = i1;
  emxEnsureCapacity_real_T(hu, i0);
  for (i0 = 0; i0 < loop_ub_tmp; i0++) {
    hu->data[i0] = 0.0;
  }

  emxInit_real_T(&hv, 2);
  i0 = hv->size[0] * hv->size[1];
  hv->size[0] = i1;
  hv->size[1] = i1;
  emxEnsureCapacity_real_T(hv, i0);
  for (i0 = 0; i0 < loop_ub_tmp; i0++) {
    hv->data[i0] = 0.0;
  }

  i0 = (int)n_res;
  for (i = 0; i < i0; i++) {
    for (j = 0; j < i0; j++) {
      if (fcnnum == 1.0) {
        GaussianFcn(X->data[i], Y->data[j], &h->data[(i + h->size[0] * (j + 2))
                    + 2], &d0, &wave_speed);
        hu->data[(i + hu->size[0] * (j + 2)) + 2] = 0.0;
        hv->data[(i + hv->size[0] * (j + 2)) + 2] = 0.0;
      }

      if (fcnnum == 2.0) {
        GeostrophicFcn(X->data[i], Y->data[j], &h->data[(i + h->size[0] * (j + 2))
                       + 2], &hu->data[(i + hu->size[0] * (j + 2)) + 2], &d0);
        hv->data[(i + hv->size[0] * (j + 2)) + 2] = 0.0;
      }

      if (fcnnum == 3.0) {
        GradientFcn(X->data[i], Y->data[j], &h->data[(i + h->size[0] * (j + 2))
                    + 2], &hu->data[(i + hu->size[0] * (j + 2)) + 2], &hv->data
                    [(i + hv->size[0] * (j + 2)) + 2]);
      }

      /* [h(io,jo) hu(io,jo) hv(io,jo)] = init_fcn(XCentroid(i), YCentroid(j)); */
      hu->data[(i + hu->size[0] * (j + 2)) + 2] *= h->data[(i + h->size[0] * (j
        + 2)) + 2];
      hv->data[(i + hv->size[0] * (j + 2)) + 2] *= h->data[(i + h->size[0] * (j
        + 2)) + 2];
    }
  }

  /*  Store initial state */
  i1 = Minit->size[0] * Minit->size[1] * Minit->size[2];
  Minit->size[0] = i0;
  Minit->size[1] = i0;
  Minit->size[2] = 3;
  emxEnsureCapacity_real_T(Minit, i1);
  loop_ub_tmp = i0 * i0 * 3;
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    Minit->data[i1] = 0.0;
  }

  if (3.0 > n_res + 2.0) {
    i1 = -1;
    i2 = -2;
    i3 = -1;
    i = -2;
  } else {
    i1 = 1;
    i2 = (int)(unsigned int)n_res;
    i3 = 1;
    i = i2;
  }

  loop_ub = i - i3;
  for (i = 0; i <= loop_ub; i++) {
    b_loop_ub = i2 - i1;
    for (j = 0; j <= b_loop_ub; j++) {
      Minit->data[j + Minit->size[0] * i] = h->data[((i1 + j) + h->size[0] *
        ((i3 + i) + 1)) + 1];
    }
  }

  if (3.0 > n_res + 2.0) {
    i1 = -2;
    i2 = -2;
    i3 = -2;
    i = -2;
  } else {
    i1 = 0;
    i2 = (int)(unsigned int)n_res;
    i3 = 0;
    i = (int)(unsigned int)n_res;
  }

  emxInit_real_T(&b_hu, 2);
  loop_ub = Minit->size[0] - 1;
  b_loop_ub = Minit->size[1] - 1;
  j = b_hu->size[0] * b_hu->size[1];
  c_loop_ub = i2 - i1;
  b_hu->size[0] = c_loop_ub;
  d_loop_ub = i - i3;
  b_hu->size[1] = d_loop_ub;
  emxEnsureCapacity_real_T(b_hu, j);
  for (i2 = 0; i2 < d_loop_ub; i2++) {
    for (i = 0; i < c_loop_ub; i++) {
      b_hu->data[i + b_hu->size[0] * i2] = hu->data[((i1 + i) + hu->size[0] *
        ((i3 + i2) + 2)) + 2];
    }
  }

  emxInit_real_T(&b_Minit, 2);
  i1 = b_Minit->size[0] * b_Minit->size[1];
  b_Minit->size[0] = loop_ub + 1;
  b_Minit->size[1] = b_loop_ub + 1;
  emxEnsureCapacity_real_T(b_Minit, i1);
  for (i1 = 0; i1 <= b_loop_ub; i1++) {
    for (i2 = 0; i2 <= loop_ub; i2++) {
      b_Minit->data[i2 + b_Minit->size[0] * i1] = Minit->data[i2 + Minit->size[0]
        * i1];
    }
  }

  emxInit_real_T(&r0, 2);
  rdivide_helper(b_hu, b_Minit, r0);
  loop_ub = r0->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_loop_ub = r0->size[0];
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      Minit->data[(i2 + Minit->size[0] * i1) + Minit->size[0] * Minit->size[1]] =
        r0->data[i2 + r0->size[0] * i1];
    }
  }

  if (3.0 > n_res + 2.0) {
    i1 = -2;
    i2 = -2;
    i3 = -2;
    i = -2;
  } else {
    i1 = 0;
    i2 = (int)(unsigned int)n_res;
    i3 = 0;
    i = (int)(unsigned int)n_res;
  }

  loop_ub = Minit->size[0] - 1;
  b_loop_ub = Minit->size[1] - 1;
  j = b_hu->size[0] * b_hu->size[1];
  c_loop_ub = i2 - i1;
  b_hu->size[0] = c_loop_ub;
  d_loop_ub = i - i3;
  b_hu->size[1] = d_loop_ub;
  emxEnsureCapacity_real_T(b_hu, j);
  for (i2 = 0; i2 < d_loop_ub; i2++) {
    for (i = 0; i < c_loop_ub; i++) {
      b_hu->data[i + b_hu->size[0] * i2] = hv->data[((i1 + i) + hv->size[0] *
        ((i3 + i2) + 2)) + 2];
    }
  }

  i1 = b_Minit->size[0] * b_Minit->size[1];
  b_Minit->size[0] = loop_ub + 1;
  b_Minit->size[1] = b_loop_ub + 1;
  emxEnsureCapacity_real_T(b_Minit, i1);
  for (i1 = 0; i1 <= b_loop_ub; i1++) {
    for (i2 = 0; i2 <= loop_ub; i2++) {
      b_Minit->data[i2 + b_Minit->size[0] * i1] = Minit->data[i2 + Minit->size[0]
        * i1];
    }
  }

  rdivide_helper(b_hu, b_Minit, r0);
  loop_ub = r0->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_loop_ub = r0->size[0];
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      Minit->data[(i2 + Minit->size[0] * i1) + ((Minit->size[0] * Minit->size[1])
        << 1)] = r0->data[i2 + r0->size[0] * i1];
    }
  }

  /*  Calculate initial timestep */
  max_wave_speed = 0.0;
  for (i = 0; i < i0; i++) {
    for (j = 0; j < i0; j++) {
      wave_speed = hu->data[i + hu->size[0] * j];
      b_nt = hv->data[i + hv->size[0] * j];
      d0 = wave_speed * wave_speed + b_nt * b_nt;
      b_sqrt(&d0);
      wave_speed = gravity * h->data[i + h->size[0] * j];
      b_sqrt(&wave_speed);
      wave_speed += d0 / h->data[i + h->size[0] * j];
      if (wave_speed > max_wave_speed) {
        max_wave_speed = wave_speed;
      }
    }
  }

  emxInit_char_T(&dt, 2);
  emxInit_char_T(&nt, 2);
  wave_speed = 0.5 * dx / max_wave_speed;

  /*  Number of timesteps */
  b_nt = ceil(t_final / wave_speed);

  /*  Output timestep information */
  b_sprintf(wave_speed, dt);
  c_sprintf(b_nt, nt);

  /*  Time at each timestep */
  /*  Allocate space for intermediate steps */
  i1 = M->size[0] * M->size[1] * M->size[2] * M->size[3];
  M->size[0] = i0;
  M->size[1] = i0;
  M->size[2] = 3;
  i2 = (int)b_nt;
  M->size[3] = i2;
  emxEnsureCapacity_real_T(M, i1);
  loop_ub = loop_ub_tmp * i2;
  emxFree_char_T(&nt);
  emxFree_char_T(&dt);
  for (i1 = 0; i1 < loop_ub; i1++) {
    M->data[i1] = 0.0;
  }

  /*  Loop through all timesteps */
  max_wave_speed = 0.0;
  i1 = T->size[0];
  T->size[0] = i2;
  emxEnsureCapacity_real_T(T, i1);
  emxInit_real_T(&h_old, 2);
  emxInit_real_T(&hu_old, 2);
  emxInit_real_T(&hv_old, 2);
  emxInit_real_T(&XFlux, 3);
  emxInit_real_T(&YFlux, 3);
  if (0 <= i2 - 1) {
    i4 = i0;
    if (3.0 > n_res + 2.0) {
      i5 = -1;
      i6 = -2;
      i7 = -1;
      i1 = -2;
    } else {
      i5 = 1;
      i6 = (int)(unsigned int)n_res;
      i7 = 1;
      i1 = (int)(unsigned int)n_res;
    }

    e_loop_ub = i1 - i7;
    if (3.0 > n_res + 2.0) {
      i8 = -2;
      i9 = -2;
      i10 = -2;
      i11 = -2;
      i12 = -2;
      i13 = -2;
      i14 = -2;
      i15 = -2;
    } else {
      i8 = 0;
      i9 = (int)(unsigned int)n_res;
      i10 = 0;
      i11 = (int)(unsigned int)n_res;
      i12 = 0;
      i13 = (int)(unsigned int)n_res;
      i14 = 0;
      i15 = (int)(unsigned int)n_res;
    }

    f_loop_ub = i11 - i10;
    g_loop_ub = i15 - i14;
    if (3.0 > n_res + 2.0) {
      i16 = -2;
      i17 = -2;
      i18 = -2;
      i19 = -2;
      i20 = -2;
      i21 = -2;
      i22 = -2;
      i23 = -2;
    } else {
      i16 = 0;
      i17 = (int)(unsigned int)n_res;
      i18 = 0;
      i19 = (int)(unsigned int)n_res;
      i20 = 0;
      i21 = (int)(unsigned int)n_res;
      i22 = 0;
      i23 = (int)(unsigned int)n_res;
    }

    h_loop_ub = i19 - i18;
    i_loop_ub = i23 - i22;
  }

  for (c_loop_ub = 0; c_loop_ub < i2; c_loop_ub++) {
    /*  Special handling of final timestep */
    if (1.0 + (double)c_loop_ub == b_nt) {
      wave_speed = t_final - max_wave_speed;
    }

    /*  Apply boundary conditions */
    ApplyBoundaryConditions(h, n_res);
    ApplyBoundaryConditions(hu, n_res);
    ApplyBoundaryConditions(hv, n_res);

    /*  Store old variables */
    i1 = h_old->size[0] * h_old->size[1];
    h_old->size[0] = h->size[0];
    h_old->size[1] = h->size[1];
    emxEnsureCapacity_real_T(h_old, i1);
    loop_ub = h->size[0] * h->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      h_old->data[i1] = h->data[i1];
    }

    i1 = hu_old->size[0] * hu_old->size[1];
    hu_old->size[0] = hu->size[0];
    hu_old->size[1] = hu->size[1];
    emxEnsureCapacity_real_T(hu_old, i1);
    loop_ub = hu->size[0] * hu->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      hu_old->data[i1] = hu->data[i1];
    }

    i1 = hv_old->size[0] * hv_old->size[1];
    hv_old->size[0] = hv->size[0];
    hv_old->size[1] = hv->size[1];
    emxEnsureCapacity_real_T(hv_old, i1);
    loop_ub = hv->size[0] * hv->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      hv_old->data[i1] = hv->data[i1];
    }

    /*  Calculate X fluxes (predictor step) */
    CalculateXFluxes(h, hu, hv, n_res, XFlux);
    CalculateYFluxes(h, hu, hv, n_res, YFlux);

    /*  Update half a timestep */
    UpdateXFluxes(h, hu, hv, XFlux, n_res, dx, 0.5 * wave_speed);
    UpdateYFluxes(h, hu, hv, YFlux, n_res, dx, 0.5 * wave_speed);

    /*  Apply source terms */
    for (i = 0; i < i4; i++) {
      for (j = 0; j < i0; j++) {
        d0 = 0.5 * wave_speed * f;
        hu->data[(i + hu->size[0] * (j + 2)) + 2] += d0 * hv_old->data[(i +
          hv_old->size[0] * (j + 2)) + 2];
        hv->data[(i + hv->size[0] * (j + 2)) + 2] -= d0 * hu_old->data[(i +
          hu_old->size[0] * (j + 2)) + 2];
      }
    }

    /*  Apply boundary conditions */
    ApplyBoundaryConditions(h, n_res);
    ApplyBoundaryConditions(hu, n_res);
    ApplyBoundaryConditions(hv, n_res);

    /*  Calculate new X fluxes */
    CalculateXFluxes(h, hu, hv, n_res, XFlux);
    CalculateYFluxes(h, hu, hv, n_res, YFlux);

    /*  Update a full timestep (corrector step) */
    i1 = hu->size[0] * hu->size[1];
    hu->size[0] = hu_old->size[0];
    hu->size[1] = hu_old->size[1];
    emxEnsureCapacity_real_T(hu, i1);
    loop_ub = hu_old->size[0] * hu_old->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      hu->data[i1] = hu_old->data[i1];
    }

    i1 = hv->size[0] * hv->size[1];
    hv->size[0] = hv_old->size[0];
    hv->size[1] = hv_old->size[1];
    emxEnsureCapacity_real_T(hv, i1);
    loop_ub = hv_old->size[0] * hv_old->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      hv->data[i1] = hv_old->data[i1];
    }

    UpdateXFluxes(h_old, hu, hv, XFlux, n_res, dx, wave_speed);
    i1 = h->size[0] * h->size[1];
    h->size[0] = h_old->size[0];
    h->size[1] = h_old->size[1];
    emxEnsureCapacity_real_T(h, i1);
    loop_ub = h_old->size[0] * h_old->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      h->data[i1] = h_old->data[i1];
    }

    UpdateYFluxes(h, hu, hv, YFlux, n_res, dx, wave_speed);

    /*  Apply source terms */
    for (i = 0; i < i4; i++) {
      for (j = 0; j < i0; j++) {
        d0 = wave_speed * f;
        hu->data[(i + hu->size[0] * (j + 2)) + 2] += d0 * hv_old->data[(i +
          hv_old->size[0] * (j + 2)) + 2];
        hv->data[(i + hv->size[0] * (j + 2)) + 2] -= d0 * hu_old->data[(i +
          hu_old->size[0] * (j + 2)) + 2];
      }
    }

    /*  Update current time */
    max_wave_speed += wave_speed;

    /*  Store current time */
    T->data[c_loop_ub] = max_wave_speed;

    /*  Store updated data */
    for (i1 = 0; i1 <= e_loop_ub; i1++) {
      loop_ub = i6 - i5;
      for (i3 = 0; i3 <= loop_ub; i3++) {
        M->data[(i3 + M->size[0] * i1) + M->size[0] * M->size[1] * 3 * c_loop_ub]
          = h->data[((i5 + i3) + h->size[0] * ((i7 + i1) + 1)) + 1];
      }
    }

    i1 = b_hu->size[0] * b_hu->size[1];
    loop_ub = i9 - i8;
    b_hu->size[0] = loop_ub;
    b_hu->size[1] = i11 - i10;
    emxEnsureCapacity_real_T(b_hu, i1);
    for (i1 = 0; i1 < f_loop_ub; i1++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        b_hu->data[i3 + b_hu->size[0] * i1] = hu->data[((i8 + i3) + hu->size[0] *
          ((i10 + i1) + 2)) + 2];
      }
    }

    i1 = b_Minit->size[0] * b_Minit->size[1];
    loop_ub = i13 - i12;
    b_Minit->size[0] = loop_ub;
    b_Minit->size[1] = i15 - i14;
    emxEnsureCapacity_real_T(b_Minit, i1);
    for (i1 = 0; i1 < g_loop_ub; i1++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        b_Minit->data[i3 + b_Minit->size[0] * i1] = h->data[((i12 + i3) +
          h->size[0] * ((i14 + i1) + 2)) + 2];
      }
    }

    rdivide_helper(b_hu, b_Minit, r0);
    loop_ub = r0->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = r0->size[0];
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        M->data[((i3 + M->size[0] * i1) + M->size[0] * M->size[1]) + M->size[0] *
          M->size[1] * 3 * c_loop_ub] = r0->data[i3 + r0->size[0] * i1];
      }
    }

    i1 = b_hu->size[0] * b_hu->size[1];
    loop_ub = i17 - i16;
    b_hu->size[0] = loop_ub;
    b_hu->size[1] = i19 - i18;
    emxEnsureCapacity_real_T(b_hu, i1);
    for (i1 = 0; i1 < h_loop_ub; i1++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        b_hu->data[i3 + b_hu->size[0] * i1] = hv->data[((i16 + i3) + hv->size[0]
          * ((i18 + i1) + 2)) + 2];
      }
    }

    i1 = b_Minit->size[0] * b_Minit->size[1];
    loop_ub = i21 - i20;
    b_Minit->size[0] = loop_ub;
    b_Minit->size[1] = i23 - i22;
    emxEnsureCapacity_real_T(b_Minit, i1);
    for (i1 = 0; i1 < i_loop_ub; i1++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        b_Minit->data[i3 + b_Minit->size[0] * i1] = h->data[((i20 + i3) +
          h->size[0] * ((i22 + i1) + 2)) + 2];
      }
    }

    rdivide_helper(b_hu, b_Minit, r0);
    loop_ub = r0->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = r0->size[0];
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        M->data[((i3 + M->size[0] * i1) + ((M->size[0] * M->size[1]) << 1)) +
          M->size[0] * M->size[1] * 3 * c_loop_ub] = r0->data[i3 + r0->size[0] *
          i1];
      }
    }

    loop_ub = M->size[0] - 1;
    b_loop_ub = M->size[1] - 1;
    i1 = b_hu->size[0] * b_hu->size[1];
    b_hu->size[0] = b_loop_ub + 1;
    b_hu->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(b_hu, i1);
    for (i1 = 0; i1 <= loop_ub; i1++) {
      for (i3 = 0; i3 <= b_loop_ub; i3++) {
        b_hu->data[i3 + b_hu->size[0] * i1] = M->data[(i1 + M->size[0] * i3) +
          M->size[0] * M->size[1] * 3 * c_loop_ub];
      }
    }

    loop_ub = b_hu->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = b_hu->size[0];
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        M->data[(i3 + M->size[0] * i1) + M->size[0] * M->size[1] * 3 * c_loop_ub]
          = b_hu->data[i3 + b_hu->size[0] * i1];
      }
    }

    loop_ub = M->size[0] - 1;
    b_loop_ub = M->size[1] - 1;
    i1 = b_hu->size[0] * b_hu->size[1];
    b_hu->size[0] = b_loop_ub + 1;
    b_hu->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(b_hu, i1);
    for (i1 = 0; i1 <= loop_ub; i1++) {
      for (i3 = 0; i3 <= b_loop_ub; i3++) {
        b_hu->data[i3 + b_hu->size[0] * i1] = M->data[((i1 + M->size[0] * i3) +
          M->size[0] * M->size[1]) + M->size[0] * M->size[1] * 3 * c_loop_ub];
      }
    }

    loop_ub = b_hu->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = b_hu->size[0];
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        M->data[((i3 + M->size[0] * i1) + M->size[0] * M->size[1]) + M->size[0] *
          M->size[1] * 3 * c_loop_ub] = b_hu->data[i3 + b_hu->size[0] * i1];
      }
    }

    loop_ub = M->size[0] - 1;
    b_loop_ub = M->size[1] - 1;
    i1 = b_hu->size[0] * b_hu->size[1];
    b_hu->size[0] = b_loop_ub + 1;
    b_hu->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(b_hu, i1);
    for (i1 = 0; i1 <= loop_ub; i1++) {
      for (i3 = 0; i3 <= b_loop_ub; i3++) {
        b_hu->data[i3 + b_hu->size[0] * i1] = M->data[((i1 + M->size[0] * i3) +
          ((M->size[0] * M->size[1]) << 1)) + M->size[0] * M->size[1] * 3 *
          c_loop_ub];
      }
    }

    loop_ub = b_hu->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = b_hu->size[0];
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        M->data[((i3 + M->size[0] * i1) + ((M->size[0] * M->size[1]) << 1)) +
          M->size[0] * M->size[1] * 3 * c_loop_ub] = b_hu->data[i3 + b_hu->size
          [0] * i1];
      }
    }
  }

  emxFree_real_T(&r0);
  emxFree_real_T(&b_Minit);
  emxFree_real_T(&b_hu);
  emxFree_real_T(&YFlux);
  emxFree_real_T(&XFlux);
  emxFree_real_T(&hv_old);
  emxFree_real_T(&hu_old);
  emxFree_real_T(&h_old);
  emxFree_real_T(&hv);
  emxFree_real_T(&hu);
  emxFree_real_T(&h);
}

/* End of code generation (ShallowWaterModel.c) */
