/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ShallowWaterModel_initialize.c
 *
 * Code generation for function 'ShallowWaterModel_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "GaussianFcn.h"
#include "GeostrophicFcn.h"
#include "GradientFcn.h"
#include "ShallowWaterModel.h"
#include "ShallowWaterModel_initialize.h"
#include "ShallowWaterModel_data.h"

/* Function Definitions */
void ShallowWaterModel_initialize(void)
{
  rt_InitInfAndNaN(8U);
  phi0 = 0.78539816339744828;
  gravity = 9.80616;
  omega = 7.292E-5;
}

/* End of code generation (ShallowWaterModel_initialize.c) */
