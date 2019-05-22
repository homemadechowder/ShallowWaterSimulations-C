/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_ShallowWaterModel_api.c
 *
 * Code generation for function '_coder_ShallowWaterModel_api'
 *
 */

/* Include files */
#include "tmwtypes.h"
#include "_coder_ShallowWaterModel_api.h"
#include "_coder_ShallowWaterModel_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131482U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "ShallowWaterModel",                 /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x_domain,
  const char_T *identifier))[2];
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2];
static const mxArray *d_emlrt_marshallOut(const emxArray_real_T *u);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static const mxArray *e_emlrt_marshallOut(const emxArray_real_T *u);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const real_T u);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2];

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv0[2] = { 0, 0 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m1, &u->data[0]);
  emlrtSetDimensions((mxArray *)m1, u->size, 2);
  emlrtAssign(&y, m1);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x_domain,
  const char_T *identifier))[2]
{
  real_T (*y)[2];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(x_domain), &thisId);
  emlrtDestroyArray(&x_domain);
  return y;
}
  static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv1[1] = { 0 };

  y = NULL;
  m2 = emlrtCreateNumericArray(1, iv1, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m2, &u->data[0]);
  emlrtSetDimensions((mxArray *)m2, u->size, 1);
  emlrtAssign(&y, m2);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2]
{
  real_T (*y)[2];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *d_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv2[4] = { 0, 0, 0, 0 };

  y = NULL;
  m3 = emlrtCreateNumericArray(4, iv2, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m3, &u->data[0]);
  emlrtSetDimensions((mxArray *)m3, u->size, 4);
  emlrtAssign(&y, m3);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static const mxArray *e_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv3[3] = { 0, 0, 0 };

  y = NULL;
  m4 = emlrtCreateNumericArray(3, iv3, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m4, &u->data[0]);
  emlrtSetDimensions((mxArray *)m4, u->size, 3);
  emlrtAssign(&y, m4);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(x), &thisId);
  emlrtDestroyArray(&x);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m0);
  return y;
}

static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2]
{
  real_T (*ret)[2];
  static const int32_T dims[2] = { 1, 2 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  void GaussianFcn_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[3])
{
  real_T x;
  real_T y;
  real_T h;
  real_T u;
  real_T v;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  x = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "x");
  y = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "y");

  /* Invoke the target function */
  GaussianFcn(x, y, &h, &u, &v);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(h);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(u);
  }

  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(v);
  }
}

void GeostrophicFcn_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[3])
{
  real_T x;
  real_T y;
  real_T h;
  real_T u;
  real_T v;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  x = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "x");
  y = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "y");

  /* Invoke the target function */
  GeostrophicFcn(x, y, &h, &u, &v);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(h);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(u);
  }

  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(v);
  }
}

void GradientFcn_api(const mxArray * const prhs[2], int32_T nlhs, const mxArray *
                     plhs[3])
{
  real_T x;
  real_T y;
  real_T h;
  real_T u;
  real_T v;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  x = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "x");
  y = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "y");

  /* Invoke the target function */
  GradientFcn(x, y, &h, &u, &v);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(h);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(u);
  }

  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(v);
  }
}

void ShallowWaterModel_api(const mxArray * const prhs[5], int32_T nlhs, const
  mxArray *plhs[5])
{
  emxArray_real_T *X;
  emxArray_real_T *Y;
  emxArray_real_T *T;
  emxArray_real_T *M;
  emxArray_real_T *Minit;
  real_T fcnnum;
  real_T t_final;
  real_T n_res;
  real_T (*x_domain)[2];
  real_T (*y_domain)[2];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &X, 2, true);
  emxInit_real_T(&st, &Y, 2, true);
  emxInit_real_T(&st, &T, 1, true);
  emxInit_real_T(&st, &M, 4, true);
  emxInit_real_T(&st, &Minit, 3, true);

  /* Marshall function inputs */
  fcnnum = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "fcnnum");
  t_final = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "t_final");
  n_res = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "n_res");
  x_domain = c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "x_domain");
  y_domain = c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "y_domain");

  /* Invoke the target function */
  ShallowWaterModel(fcnnum, t_final, n_res, *x_domain, *y_domain, X, Y, T, M,
                    Minit);

  /* Marshall function outputs */
  X->canFreeData = false;
  plhs[0] = b_emlrt_marshallOut(X);
  emxFree_real_T(&X);
  if (nlhs > 1) {
    Y->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(Y);
  }

  emxFree_real_T(&Y);
  if (nlhs > 2) {
    T->canFreeData = false;
    plhs[2] = c_emlrt_marshallOut(T);
  }

  emxFree_real_T(&T);
  if (nlhs > 3) {
    M->canFreeData = false;
    plhs[3] = d_emlrt_marshallOut(M);
  }

  emxFree_real_T(&M);
  if (nlhs > 4) {
    Minit->canFreeData = false;
    plhs[4] = e_emlrt_marshallOut(Minit);
  }

  emxFree_real_T(&Minit);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void ShallowWaterModel_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  ShallowWaterModel_xil_terminate();
  ShallowWaterModel_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void ShallowWaterModel_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void ShallowWaterModel_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_ShallowWaterModel_api.c) */
