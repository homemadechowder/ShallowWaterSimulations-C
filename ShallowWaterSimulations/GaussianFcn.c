/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * GaussianFcn.c
 *
 * Code generation for function 'GaussianFcn'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "GaussianFcn.h"
#include "GeostrophicFcn.h"
#include "GradientFcn.h"
#include "ShallowWaterModel.h"

/* Function Definitions */
void GaussianFcn(double x, double y, double *h, double *u, double *v)
{
  double a;

  /*  Radius from the center of the hill */
  a = sqrt(x * x + y * y);

  /*  Half-width of the hill */
  /*  Fluid height perturbation */
  /*  Height of the hill at this point */
  *h = 500.0 + 5.0 * exp(-(a * a) / 1.6E+11);

  /*  Zero velocity */
  *u = 0.0;
  *v = 0.0;
}

/* End of code generation (GaussianFcn.c) */
