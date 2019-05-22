/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * GeostrophicFcn.c
 *
 * Code generation for function 'GeostrophicFcn'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "GaussianFcn.h"
#include "GeostrophicFcn.h"
#include "GradientFcn.h"
#include "ShallowWaterModel.h"
#include "ShallowWaterModel_data.h"

/* Function Definitions */
void GeostrophicFcn(double x, double y, double *h, double *u, double *v)
{
  double h_tmp;
  (void)x;

  /*  Background height */
  /*  Background velocity */
  /*  Latitude (override) */
  /*  Coriolis parameter (override) */
  /*  Wavelength */
  /*  Height of the hill at this point */
  h_tmp = 6.2831853071795862 * y / 1.0E+6;
  *h = 500.0 + 30.0 * (2.0 * omega * 0.70710678118654746) / gravity * 1.0E+6 /
    6.2831853071795862 * cos(h_tmp);

  /*  Fixed zonal velocity */
  *u = 30.0 * sin(h_tmp);

  /*  Zero meridional velocity */
  *v = 0.0;
}

/* End of code generation (GeostrophicFcn.c) */
