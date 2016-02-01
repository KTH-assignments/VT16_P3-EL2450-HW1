/*
 * tanks_acc.h
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
#ifndef RTW_HEADER_tanks_acc_h_
#define RTW_HEADER_tanks_acc_h_
#include <math.h>
#include <stddef.h>
#ifndef tanks_acc_COMMON_INCLUDES_
# define tanks_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                simulink_only_sfcn
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* tanks_acc_COMMON_INCLUDES_ */

#include "tanks_acc_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"

/* Block signals (auto storage) */
typedef struct {
  real_T Sum;                          /* '<S1>/Sum' */
  real_T Sum_o;                        /* '<Root>/Sum' */
  real_T Continouscontroller;          /* '<Root>/Continous controller' */
  real_T Gain;                         /* '<S3>/Gain' */
  real_T Sum_e;                        /* '<S3>/Sum' */
  real_T Sum_el;                       /* '<S4>/Sum' */
  real_T Scaling3;                     /* '<S2>/Scaling3' */
} B_tanks_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Tank1level_PWORK;                  /* '<Root>/Tank1 level' */

  struct {
    void *LoggedData;
  } Tank2level_PWORK;                  /* '<Root>/Tank2 level' */

  int_T Integrator_MODE;               /* '<S3>/Integrator' */
  int_T Integrator_MODE_f;             /* '<S4>/Integrator' */
  int_T Step_MODE;                     /* '<S1>/Step' */
  char pad_Step_MODE[4];
} DW_tanks_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S4>/Integrator' */
  real_T Continouscontroller_CSTATE[2];/* '<Root>/Continous controller' */
} X_tanks_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S4>/Integrator' */
  real_T Continouscontroller_CSTATE[2];/* '<Root>/Continous controller' */
} XDot_tanks_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S3>/Integrator' */
  boolean_T Integrator_CSTATE_c;       /* '<S4>/Integrator' */
  boolean_T Continouscontroller_CSTATE[2];/* '<Root>/Continous controller' */
} XDis_tanks_T;

/* Continuous State Absolute Tolerance  */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S4>/Integrator' */
  real_T Continouscontroller_CSTATE[2];/* '<Root>/Continous controller' */
} CStateAbsTol_tanks_T;

/* Zero-crossing (trigger) state */
typedef struct {
  real_T Integrator_IntgUpLimit_ZC;    /* '<S3>/Integrator' */
  real_T Integrator_IntgLoLimit_ZC;    /* '<S3>/Integrator' */
  real_T Integrator_LeaveSaturate_ZC;  /* '<S3>/Integrator' */
  real_T Integrator_IntgUpLimit_ZC_h;  /* '<S4>/Integrator' */
  real_T Integrator_IntgLoLimit_ZC_i;  /* '<S4>/Integrator' */
  real_T Integrator_LeaveSaturate_ZC_d;/* '<S4>/Integrator' */
  real_T Step_StepTime_ZC;             /* '<S1>/Step' */
} ZCV_tanks_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_IntgUpLimit_ZCE;/* '<S3>/Integrator' */
  ZCSigState Integrator_IntgLoLimit_ZCE;/* '<S3>/Integrator' */
  ZCSigState Integrator_LeaveSaturate_ZCE;/* '<S3>/Integrator' */
  ZCSigState Integrator_IntgUpLimit_ZCE_i;/* '<S4>/Integrator' */
  ZCSigState Integrator_IntgLoLimit_ZCE_j;/* '<S4>/Integrator' */
  ZCSigState Integrator_LeaveSaturate_ZCE_h;/* '<S4>/Integrator' */
  ZCSigState Step_StepTime_ZCE;        /* '<S1>/Step' */
} PrevZCX_tanks_T;

/* Parameters (auto storage) */
struct P_tanks_T_ {
  real_T Integrator_IC;                /* Expression: tank_init_h1*tank_A1
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: tank_H1*tank_A1
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/tank_A1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Scaling2_Gain;                /* Expression: 100/tank_H1
                                        * Referenced by: '<S2>/Scaling2'
                                        */
  real_T Integrator_IC_i;              /* Expression: tank_init_h2*tank_A2
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Integrator_UpperSat_f;        /* Expression: tank_H2*tank_A2
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Integrator_LowerSat_p;        /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 1/tank_A2
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Scaling3_Gain;                /* Expression: 100/tank_H2
                                        * Referenced by: '<S2>/Scaling3'
                                        */
  real_T Step_Time;                    /* Expression: 100
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 10
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Constant_Value;               /* Expression: 40
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Continouscontroller_A[2];     /* Computed Parameter: Continouscontroller_A
                                        * Referenced by: '<Root>/Continous controller'
                                        */
  real_T Continouscontroller_C[2];     /* Computed Parameter: Continouscontroller_C
                                        * Referenced by: '<Root>/Continous controller'
                                        */
  real_T Continouscontroller_D;        /* Computed Parameter: Continouscontroller_D
                                        * Referenced by: '<Root>/Continous controller'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Scaling1_Gain;                /* Expression: 15/100
                                        * Referenced by: '<S2>/Scaling1'
                                        */
  real_T Gain_Gain;                    /* Expression: tank_Kpump
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Tap_Gain;                     /* Expression: 0
                                        * Referenced by: '<S3>/Tap'
                                        */
};

extern P_tanks_T tanks_rtDefaultP;     /* parameters */

#endif                                 /* RTW_HEADER_tanks_acc_h_ */
