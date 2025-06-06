/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1110
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jun  6 13:51:52 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller.h"
#include "Controller_private.h"

/* Invariant block signals (default storage) */
const ConstB_Controller_T Controller_ConstB = {
  0.0F,                                /* '<S42>/Zero1' */

  { 0.0F, 0.0F, 0.0F },                /* '<S16>/Constant' */
  0.0F                                 /* '<S45>/Zero' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {
  /* Computed Parameter: Disarm_Value
   * Referenced by: '<S31>/Disarm'
   */
  { 1000U, 1000U, 1500U, 1500U, 1500U, 1500U },

  /* Computed Parameter: Standby_Value
   * Referenced by: '<S31>/Standby'
   */
  { 1050U, 1050U, 1500U, 1500U, 1500U, 1500U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
