/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ShallowWaterModel.h
 *
 * Code generation for function 'ShallowWaterModel'
 *
 */

#ifndef SHALLOWWATERMODEL_H
#define SHALLOWWATERMODEL_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "ShallowWaterModel_types.h"

/* Function Declarations */
extern void ShallowWaterModel(double fcnnum, double t_final, double n_res, const
  double x_domain[2], const double y_domain[2], emxArray_real_T *X,
  emxArray_real_T *Y, emxArray_real_T *T, emxArray_real_T *M, emxArray_real_T
  *Minit);

#endif

/* End of code generation (ShallowWaterModel.h) */
