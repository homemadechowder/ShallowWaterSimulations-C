/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_GaussianFcn_api.h
 *
 * Code generation for function '_coder_GaussianFcn_api'
 *
 */

#ifndef _CODER_GAUSSIANFCN_API_H
#define _CODER_GAUSSIANFCN_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_GaussianFcn_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void GaussianFcn(real_T x, real_T y, real_T *h, real_T *u, real_T *v);
extern void GaussianFcn_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[3]);
extern void GaussianFcn_atexit(void);
extern void GaussianFcn_initialize(void);
extern void GaussianFcn_terminate(void);
extern void GaussianFcn_xil_shutdown(void);
extern void GaussianFcn_xil_terminate(void);
extern void GeostrophicFcn(real_T x, real_T y, real_T *h, real_T *u, real_T *v);
extern void GeostrophicFcn_api(const mxArray * const prhs[2], int32_T nlhs,
  const mxArray *plhs[3]);
extern void GradientFcn(real_T x, real_T y, real_T *h, real_T *u, real_T *v);
extern void GradientFcn_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[3]);
extern void ShallowWaterModel(real_T fcnnum, real_T t_final, real_T n_res,
  real_T x_domain[2], real_T y_domain[2], emxArray_real_T *X, emxArray_real_T *Y,
  emxArray_real_T *T, emxArray_real_T *M, emxArray_real_T *Minit);
extern void ShallowWaterModel_api(const mxArray * const prhs[5], int32_T nlhs,
  const mxArray *plhs[5]);

#endif

/* End of code generation (_coder_GaussianFcn_api.h) */
