/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rdivide_helper.c
 *
 * Code generation for function 'rdivide_helper'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "GaussianFcn.h"
#include "GeostrophicFcn.h"
#include "GradientFcn.h"
#include "ShallowWaterModel.h"
#include "rdivide_helper.h"
#include "ShallowWaterModel_emxutil.h"

/* Function Definitions */
void rdivide_helper(const emxArray_real_T *x, const emxArray_real_T *y,
                    emxArray_real_T *z)
{
  int i24;
  int loop_ub;
  i24 = z->size[0] * z->size[1];
  z->size[0] = x->size[0];
  z->size[1] = x->size[1];
  emxEnsureCapacity_real_T(z, i24);
  loop_ub = x->size[0] * x->size[1];
  for (i24 = 0; i24 < loop_ub; i24++) {
    z->data[i24] = x->data[i24] / y->data[i24];
  }
}

/* End of code generation (rdivide_helper.c) */
