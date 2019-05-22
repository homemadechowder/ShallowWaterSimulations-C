/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * GradientFcn.c
 *
 * Code generation for function 'GradientFcn'
 *
 */

/* Include files */
#include <math.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "GaussianFcn.h"
#include "GeostrophicFcn.h"
#include "GradientFcn.h"
#include "ShallowWaterModel.h"
#include "ShallowWaterModel_data.h"

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

void GradientFcn(double x, double y, double *h, double *u, double *v)
{
  double r;
  double theta;
  double uphi;
  double h_tmp;

  /*  Radius from the center of the hill */
  r = sqrt(x * x + y * y);

  /*  Angle from the center of the hill */
  theta = rt_atan2d_snf(y, x);

  /*  Half-width of the hill */
  /*  Fluid height perturbation */
  /*  Background fluid height */
  /*  Calculate fluid height */
  uphi = r * r;
  h_tmp = exp(-uphi / 4.0E+10);
  *h = 500.0 - 20.0 * h_tmp;

  /*  Rotational velocity */
  uphi = sqrt(gravity * 20.0 * (2.0 * uphi / 4.0E+10) * h_tmp);
  if (r == 0.0) {
    *u = 0.0;
    *v = 0.0;
  } else {
    *u = -sin(theta) * uphi;
    *v = cos(theta) * uphi;
  }
}

/* End of code generation (GradientFcn.c) */
