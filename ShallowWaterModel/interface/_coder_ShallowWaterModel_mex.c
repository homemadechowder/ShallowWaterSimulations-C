/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_ShallowWaterModel_mex.c
 *
 * Code generation for function '_coder_ShallowWaterModel_mex'
 *
 */

/* Include files */
#include "_coder_ShallowWaterModel_api.h"
#include "_coder_ShallowWaterModel_mex.h"

/* Variable Definitions */
static const char * emlrtEntryPoints[4] = { "GaussianFcn", "GeostrophicFcn",
  "GradientFcn", "ShallowWaterModel" };

/* Function Declarations */
static void GaussianFcn_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[2]);
static void GeostrophicFcn_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T
  nrhs, const mxArray *prhs[2]);
static void GradientFcn_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[2]);
static void ShallowWaterModel_mexFunction(int32_T nlhs, mxArray *plhs[5],
  int32_T nrhs, const mxArray *prhs[5]);

/* Function Definitions */
static void GaussianFcn_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[2])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        11, "GaussianFcn");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "GaussianFcn");
  }

  /* Call the function. */
  GaussianFcn_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

static void GeostrophicFcn_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T
  nrhs, const mxArray *prhs[2])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        14, "GeostrophicFcn");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "GeostrophicFcn");
  }

  /* Call the function. */
  GeostrophicFcn_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

static void GradientFcn_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[2])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        11, "GradientFcn");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "GradientFcn");
  }

  /* Call the function. */
  GradientFcn_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

static void ShallowWaterModel_mexFunction(int32_T nlhs, mxArray *plhs[5],
  int32_T nrhs, const mxArray *prhs[5])
{
  const mxArray *outputs[5];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        17, "ShallowWaterModel");
  }

  if (nlhs > 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "ShallowWaterModel");
  }

  /* Call the function. */
  ShallowWaterModel_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexAtExit(ShallowWaterModel_atexit);

  /* Module initialization. */
  ShallowWaterModel_initialize();
  st.tls = emlrtRootTLSGlobal;

  /* Dispatch the entry-point. */
  switch (emlrtGetEntryPointIndexR2016a(&st, nrhs, prhs, emlrtEntryPoints, 4)) {
   case 0:
    GaussianFcn_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[2])&prhs
      [1]);
    break;

   case 1:
    GeostrophicFcn_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[2])&
      prhs[1]);
    break;

   case 2:
    GradientFcn_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[2])&prhs
      [1]);
    break;

   case 3:
    ShallowWaterModel_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[5])
      &prhs[1]);
    break;
  }

  /* Module termination. */
  ShallowWaterModel_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_ShallowWaterModel_mex.c) */
