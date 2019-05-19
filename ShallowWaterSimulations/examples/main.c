/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include files */
#include "rt_nonfinite.h"
#include "GaussianFcn.h"
#include "GeostrophicFcn.h"
#include "GradientFcn.h"
#include "ShallowWaterModel.h"
#include "main.h"
#include "GaussianFcn_terminate.h"
#include "GaussianFcn_emxAPI.h"
#include "GaussianFcn_initialize.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);
static double argInit_real_T(void);
static void main_GaussianFcn(void);
static void main_GeostrophicFcn(void);
static void main_GradientFcn(void);
static void main_ShallowWaterModel(void);

/* Function Definitions */
static void argInit_1x2_real_T(double result[2])
{
  double result_tmp;

  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result[0] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[1] = result_tmp;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_GaussianFcn(void)
{
  double h;
  double u;
  double v;

  /* Initialize function 'GaussianFcn' input arguments. */
  /* Call the entry-point 'GaussianFcn'. */
  GaussianFcn(argInit_real_T(), argInit_real_T(), &h, &u, &v);
}

static void main_GeostrophicFcn(void)
{
  double h;
  double u;
  double v;

  /* Initialize function 'GeostrophicFcn' input arguments. */
  /* Call the entry-point 'GeostrophicFcn'. */
  GeostrophicFcn(argInit_real_T(), argInit_real_T(), &h, &u, &v);
}

static void main_GradientFcn(void)
{
  double h;
  double u;
  double v;

  /* Initialize function 'GradientFcn' input arguments. */
  /* Call the entry-point 'GradientFcn'. */
  GradientFcn(argInit_real_T(), argInit_real_T(), &h, &u, &v);
}

static void main_ShallowWaterModel(void)
{
  emxArray_real_T *X;
  emxArray_real_T *Y;
  emxArray_real_T *T;
  emxArray_real_T *M;
  emxArray_real_T *Minit;
  double fcnnum_tmp;
  double n_res;
  double x_domain_tmp[2];
  emxInitArray_real_T(&X, 2);
  emxInitArray_real_T(&Y, 2);
  emxInitArray_real_T(&T, 1);
  emxInitArray_real_T(&M, 4);
  emxInitArray_real_T(&Minit, 3);

  /* Initialize function 'ShallowWaterModel' input arguments. */
  fcnnum_tmp = argInit_real_T();
  n_res = argInit_real_T();

  /* Initialize function input argument 'x_domain'. */
  argInit_1x2_real_T(x_domain_tmp);

  /* Initialize function input argument 'y_domain'. */
  /* Call the entry-point 'ShallowWaterModel'. */
  ShallowWaterModel(fcnnum_tmp, fcnnum_tmp, n_res, x_domain_tmp, x_domain_tmp, X,
                    Y, T, M, Minit);
  emxDestroyArray_real_T(Minit);
  emxDestroyArray_real_T(M);
  emxDestroyArray_real_T(T);
  emxDestroyArray_real_T(Y);
  emxDestroyArray_real_T(X);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  GaussianFcn_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_GaussianFcn();
  main_GeostrophicFcn();
  main_GradientFcn();
  main_ShallowWaterModel();

  /* Terminate the application.
     You do not need to do this more than one time. */
  GaussianFcn_terminate();
  return 0;
}

/* End of code generation (main.c) */
