/*
 * tanks_acc_data.c
 *
 * Code generation for model "tanks_acc".
 *
 * Model version              : 1.87
 * Simulink Coder version : 8.7 (R2014b) 08-Sep-2014
 * C source code generated on : Mon Feb  1 00:16:05 2016
 *
 * Target selection: accel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "tanks_acc.h"
#include "tanks_acc_private.h"

/* Block parameters (auto storage) */
P_tanks_T tanks_rtDefaultP = {
  0.00015517916547360872,              /* Expression: tank_init_h1*tank_A1
                                        * Referenced by: '<S3>/Integrator'
                                        */
  0.00038794791368402176,              /* Expression: tank_H1*tank_A1
                                        * Referenced by: '<S3>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  644.41640535183171,                  /* Expression: 1/tank_A1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  400.0,                               /* Expression: 100/tank_H1
                                        * Referenced by: '<S2>/Scaling2'
                                        */
  0.00015517916547360872,              /* Expression: tank_init_h2*tank_A2
                                        * Referenced by: '<S4>/Integrator'
                                        */
  0.00038794791368402176,              /* Expression: tank_H2*tank_A2
                                        * Referenced by: '<S4>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  644.41640535183171,                  /* Expression: 1/tank_A2
                                        * Referenced by: '<S4>/Gain1'
                                        */
  400.0,                               /* Expression: 100/tank_H2
                                        * Referenced by: '<S2>/Scaling3'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S1>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S1>/Step'
                                        */
  40.0,                                /* Expression: 40
                                        * Referenced by: '<S1>/Constant'
                                        */

  /*  Computed Parameter: Continouscontroller_A
   * Referenced by: '<Root>/Continous controller'
   */
  { -1.1591218037018434, -0.0 },

  /*  Computed Parameter: Continouscontroller_C
   * Referenced by: '<Root>/Continous controller'
   */
  { -26.210607795225691, 0.70664871266733986 },
  29.470934824954753,                  /* Computed Parameter: Continouscontroller_D
                                        * Referenced by: '<Root>/Continous controller'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -0.0,                                /* Expression: -0
                                        * Referenced by: '<S2>/Saturation'
                                        */
  0.15,                                /* Expression: 15/100
                                        * Referenced by: '<S2>/Scaling1'
                                        */
  4.55E-6,                             /* Expression: tank_Kpump
                                        * Referenced by: '<S3>/Gain'
                                        */
  0.0                                  /* Expression: 0
                                        * Referenced by: '<S3>/Tap'
                                        */
};
