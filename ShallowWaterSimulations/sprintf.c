/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprintf.c
 *
 * Code generation for function 'sprintf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "GaussianFcn.h"
#include "GeostrophicFcn.h"
#include "GradientFcn.h"
#include "ShallowWaterModel.h"
#include "sprintf.h"
#include "GaussianFcn_emxutil.h"
#include <stdio.h>

/* Function Definitions */
void b_sprintf(double varargin_1, emxArray_char_T *str)
{
  int nbytes;
  int i25;
  nbytes = (int)snprintf(NULL, 0, "Time step size: %1.2f seconds\n", varargin_1);
  i25 = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = nbytes + 1;
  emxEnsureCapacity_char_T(str, i25);
  snprintf(&str->data[0], (size_t)(nbytes + 1),
           "Time step size: %1.2f seconds\n", varargin_1);
  if (1 > nbytes) {
    str->size[1] = 0;
  } else {
    i25 = str->size[0] * str->size[1];
    str->size[1] = nbytes;
    emxEnsureCapacity_char_T(str, i25);
  }
}

void c_sprintf(double varargin_1, emxArray_char_T *str)
{
  int nbytes;
  int i26;
  nbytes = (int)snprintf(NULL, 0, "Number of time steps: %1.2f\n", varargin_1);
  i26 = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = nbytes + 1;
  emxEnsureCapacity_char_T(str, i26);
  snprintf(&str->data[0], (size_t)(nbytes + 1), "Number of time steps: %1.2f\n",
           varargin_1);
  if (1 > nbytes) {
    str->size[1] = 0;
  } else {
    i26 = str->size[0] * str->size[1];
    str->size[1] = nbytes;
    emxEnsureCapacity_char_T(str, i26);
  }
}

/* End of code generation (sprintf.c) */
