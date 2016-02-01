/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) product.
 */

/*
 * tanks_acc.c
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
#include <math.h>
#include "tanks_acc.h"
#include "tanks_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat                     S-Function
#define AccDefine1                     Accelerator_S-Function

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  /* local block i/o variables */
  real_T rtb_Gain1;
  real_T rtb_a1sqrt1962h1;
  real_T tmp;
  real_T tmp_0;
  B_tanks_T *_rtB;
  P_tanks_T *_rtP;
  X_tanks_T *_rtX;
  DW_tanks_T *_rtDW;
  _rtDW = ((DW_tanks_T *) ssGetRootDWork(S));
  _rtX = ((X_tanks_T *) ssGetContStates(S));
  _rtP = ((P_tanks_T *) ssGetDefaultParam(S));
  _rtB = ((B_tanks_T *) _ssGetBlockIO(S));

  /* Integrator: '<S3>/Integrator'
   *
   * Regarding '<S3>/Integrator':
   *  Limited Integrator
   */
  if (ssIsMajorTimeStep(S)) {
    if (((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE >=
        _rtP->Integrator_UpperSat ) {
      ((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE =
        _rtP->Integrator_UpperSat;
    } else if (((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE <=
               _rtP->Integrator_LowerSat ) {
      ((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE =
        _rtP->Integrator_LowerSat;
    }
  }

  rtb_a1sqrt1962h1 = ((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE;
  rtb_a1sqrt1962h1 *= _rtP->Gain1_Gain;
  _rtB->Scaling3 = _rtP->Scaling2_Gain * rtb_a1sqrt1962h1;

  /* Scope: '<Root>/Tank1 level' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 0, 3, SS_CALL_MDL_OUTPUTS);

  /* Integrator: '<S4>/Integrator'
   *
   * Regarding '<S4>/Integrator':
   *  Limited Integrator
   */
  if (ssIsMajorTimeStep(S)) {
    if (((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE_c >=
        _rtP->Integrator_UpperSat_f ) {
      ((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE_c =
        _rtP->Integrator_UpperSat_f;
    } else if (((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE_c <=
               _rtP->Integrator_LowerSat_p ) {
      ((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE_c =
        _rtP->Integrator_LowerSat_p;
    }
  }

  rtb_Gain1 = ((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE_c;
  rtb_Gain1 *= _rtP->Gain1_Gain_o;
  _rtB->Scaling3 = _rtP->Scaling3_Gain * rtb_Gain1;

  /* Scope: '<Root>/Tank2 level' */

  /* Call into Simulink for Scope */
  ssCallAccelRunBlock(S, 0, 7, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    _rtDW->Step_MODE = (ssGetTaskTime(S,1) >= _rtP->Step_Time);
    if (_rtDW->Step_MODE == 1) {
      tmp_0 = _rtP->Step_YFinal;
    } else {
      tmp_0 = _rtP->Step_Y0;
    }

    _rtB->Sum = tmp_0 + _rtP->Constant_Value;
  }

  _rtB->Sum_o = _rtB->Sum - _rtB->Scaling3;
  _rtB->Continouscontroller = 0.0;
  _rtB->Continouscontroller += _rtP->Continouscontroller_C[0] *
    _rtX->Continouscontroller_CSTATE[0];
  _rtB->Continouscontroller += _rtP->Continouscontroller_C[1] *
    _rtX->Continouscontroller_CSTATE[1];
  _rtB->Continouscontroller += _rtP->Continouscontroller_D * _rtB->Sum_o;
  if (ssIsSampleHit(S, 2, 0)) {
    if (_rtB->Continouscontroller > _rtP->Saturation_UpperSat) {
      tmp_0 = _rtP->Saturation_UpperSat;
    } else if (_rtB->Continouscontroller < _rtP->Saturation_LowerSat) {
      tmp_0 = _rtP->Saturation_LowerSat;
    } else {
      tmp_0 = _rtB->Continouscontroller;
    }

    _rtB->Gain = _rtP->Scaling1_Gain * tmp_0 * _rtP->Gain_Gain;
  }

  tmp_0 = _rtP->Tap_Gain * rtb_a1sqrt1962h1 * 19.62;
  tmp = 19.62 * rtb_a1sqrt1962h1;
  if (tmp < 0.0) {
    tmp = -sqrt(-tmp);
  } else {
    tmp = sqrt(tmp);
  }

  rtb_a1sqrt1962h1 = 1.7813934812021405e-5 * tmp;
  if (tmp_0 < 0.0) {
    tmp_0 = -sqrt(-tmp_0);
  } else {
    tmp_0 = sqrt(tmp_0);
  }

  _rtB->Sum_e = _rtB->Gain - (1.7813934812021405e-5 * tmp_0 + rtb_a1sqrt1962h1);
  tmp_0 = 19.62 * rtb_Gain1;
  if (tmp_0 < 0.0) {
    tmp_0 = -sqrt(-tmp_0);
  } else {
    tmp_0 = sqrt(tmp_0);
  }

  _rtB->Sum_el = rtb_a1sqrt1962h1 - 1.7813934812021405e-5 * tmp_0;
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  B_tanks_T *_rtB;
  P_tanks_T *_rtP;
  DW_tanks_T *_rtDW;
  _rtDW = ((DW_tanks_T *) ssGetRootDWork(S));
  _rtP = ((P_tanks_T *) ssGetDefaultParam(S));
  _rtB = ((B_tanks_T *) _ssGetBlockIO(S));

  /* Update for Integrator: '<S3>/Integrator' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE ==
        _rtP->Integrator_UpperSat) {
      switch (_rtDW->Integrator_MODE) {
       case INTG_UPPER_SAT:
        if (_rtB->Sum_e < 0.0) {
          ssSetSolverNeedsReset(S);
          _rtDW->Integrator_MODE = INTG_LEAVING_UPPER_SAT;
        }
        break;

       case INTG_LEAVING_UPPER_SAT:
        if (_rtB->Sum_e >= 0.0) {
          _rtDW->Integrator_MODE = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(S);
        }
        break;

       default:
        ssSetSolverNeedsReset(S);
        if (_rtB->Sum_e < 0.0) {
          _rtDW->Integrator_MODE = INTG_LEAVING_UPPER_SAT;
        } else {
          _rtDW->Integrator_MODE = INTG_UPPER_SAT;
        }
        break;
      }
    } else if (((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE ==
               _rtP->Integrator_LowerSat) {
      switch (_rtDW->Integrator_MODE) {
       case INTG_LOWER_SAT:
        if (_rtB->Sum_e > 0.0) {
          ssSetSolverNeedsReset(S);
          _rtDW->Integrator_MODE = INTG_LEAVING_LOWER_SAT;
        }
        break;

       case INTG_LEAVING_LOWER_SAT:
        if (_rtB->Sum_e <= 0.0) {
          _rtDW->Integrator_MODE = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(S);
        }
        break;

       default:
        ssSetSolverNeedsReset(S);
        if (_rtB->Sum_e > 0.0) {
          _rtDW->Integrator_MODE = INTG_LEAVING_LOWER_SAT;
        } else {
          _rtDW->Integrator_MODE = INTG_LOWER_SAT;
        }
        break;
      }
    } else {
      _rtDW->Integrator_MODE = INTG_NORMAL;
    }
  }

  /* Update for Integrator: '<S4>/Integrator' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE_c ==
        _rtP->Integrator_UpperSat_f) {
      switch (_rtDW->Integrator_MODE_f) {
       case INTG_UPPER_SAT:
        if (_rtB->Sum_el < 0.0) {
          ssSetSolverNeedsReset(S);
          _rtDW->Integrator_MODE_f = INTG_LEAVING_UPPER_SAT;
        }
        break;

       case INTG_LEAVING_UPPER_SAT:
        if (_rtB->Sum_el >= 0.0) {
          _rtDW->Integrator_MODE_f = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(S);
        }
        break;

       default:
        ssSetSolverNeedsReset(S);
        if (_rtB->Sum_el < 0.0) {
          _rtDW->Integrator_MODE_f = INTG_LEAVING_UPPER_SAT;
        } else {
          _rtDW->Integrator_MODE_f = INTG_UPPER_SAT;
        }
        break;
      }
    } else if (((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE_c ==
               _rtP->Integrator_LowerSat_p) {
      switch (_rtDW->Integrator_MODE_f) {
       case INTG_LOWER_SAT:
        if (_rtB->Sum_el > 0.0) {
          ssSetSolverNeedsReset(S);
          _rtDW->Integrator_MODE_f = INTG_LEAVING_LOWER_SAT;
        }
        break;

       case INTG_LEAVING_LOWER_SAT:
        if (_rtB->Sum_el <= 0.0) {
          _rtDW->Integrator_MODE_f = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(S);
        }
        break;

       default:
        ssSetSolverNeedsReset(S);
        if (_rtB->Sum_el > 0.0) {
          _rtDW->Integrator_MODE_f = INTG_LEAVING_LOWER_SAT;
        } else {
          _rtDW->Integrator_MODE_f = INTG_LOWER_SAT;
        }
        break;
      }
    } else {
      _rtDW->Integrator_MODE_f = INTG_NORMAL;
    }
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *S)
{
  B_tanks_T *_rtB;
  P_tanks_T *_rtP;
  X_tanks_T *_rtX;
  XDot_tanks_T *_rtXdot;
  DW_tanks_T *_rtDW;
  _rtDW = ((DW_tanks_T *) ssGetRootDWork(S));
  _rtXdot = ((XDot_tanks_T *) ssGetdX(S));
  _rtX = ((X_tanks_T *) ssGetContStates(S));
  _rtP = ((P_tanks_T *) ssGetDefaultParam(S));
  _rtB = ((B_tanks_T *) _ssGetBlockIO(S));

  /* Derivatives for Integrator: '<S3>/Integrator' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((_rtDW->Integrator_MODE != INTG_UPPER_SAT)
        && (_rtDW->Integrator_MODE != INTG_LOWER_SAT) ) {
      ((XDot_tanks_T *) ssGetdX(S))->Integrator_CSTATE = _rtB->Sum_e;
      ((XDis_tanks_T *) ssGetContStateDisabled(S))->Integrator_CSTATE = false;
    } else {
      /* in saturation */
      ((XDot_tanks_T *) ssGetdX(S))->Integrator_CSTATE = 0.0;
      if ((_rtDW->Integrator_MODE == INTG_UPPER_SAT) || (_rtDW->Integrator_MODE ==
           INTG_LOWER_SAT)) {
        ((XDis_tanks_T *) ssGetContStateDisabled(S))->Integrator_CSTATE = true;
      }
    }
  }

  /* Derivatives for Integrator: '<S4>/Integrator' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((_rtDW->Integrator_MODE_f != INTG_UPPER_SAT)
        && (_rtDW->Integrator_MODE_f != INTG_LOWER_SAT) ) {
      ((XDot_tanks_T *) ssGetdX(S))->Integrator_CSTATE_c = _rtB->Sum_el;
      ((XDis_tanks_T *) ssGetContStateDisabled(S))->Integrator_CSTATE_c = false;
    } else {
      /* in saturation */
      ((XDot_tanks_T *) ssGetdX(S))->Integrator_CSTATE_c = 0.0;
      if ((_rtDW->Integrator_MODE_f == INTG_UPPER_SAT) ||
          (_rtDW->Integrator_MODE_f == INTG_LOWER_SAT)) {
        ((XDis_tanks_T *) ssGetContStateDisabled(S))->Integrator_CSTATE_c = true;
      }
    }
  }

  _rtXdot->Continouscontroller_CSTATE[0] = 0.0;
  _rtXdot->Continouscontroller_CSTATE[1] = 0.0;
  _rtXdot->Continouscontroller_CSTATE[0] += _rtP->Continouscontroller_A[0] *
    _rtX->Continouscontroller_CSTATE[0];
  _rtXdot->Continouscontroller_CSTATE[0] += _rtP->Continouscontroller_A[1] *
    _rtX->Continouscontroller_CSTATE[1];
  _rtXdot->Continouscontroller_CSTATE[1] += _rtX->Continouscontroller_CSTATE[0];
  _rtXdot->Continouscontroller_CSTATE[0] += _rtB->Sum_o;
}

/* ZeroCrossings for root system: '<Root>' */
#define MDL_ZERO_CROSSINGS

static void mdlZeroCrossings(SimStruct *S)
{
  B_tanks_T *_rtB;
  P_tanks_T *_rtP;
  ZCV_tanks_T *_rtZCSV;
  DW_tanks_T *_rtDW;
  _rtDW = ((DW_tanks_T *) ssGetRootDWork(S));
  _rtZCSV = ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S));
  _rtP = ((P_tanks_T *) ssGetDefaultParam(S));
  _rtB = ((B_tanks_T *) _ssGetBlockIO(S));

  /* ZeroCrossings for Integrator: '<S3>/Integrator' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for enter into limited region */
    if (_rtDW->Integrator_MODE == INTG_LEAVING_UPPER_SAT && ((X_tanks_T *)
         ssGetContStates(S))->Integrator_CSTATE >= _rtP->Integrator_UpperSat) {
      ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S))->Integrator_IntgUpLimit_ZC =
        0.0;
    } else {
      ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S))->Integrator_IntgUpLimit_ZC =
        ((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE -
        _rtP->Integrator_UpperSat;
    }

    if (_rtDW->Integrator_MODE == INTG_LEAVING_LOWER_SAT &&((X_tanks_T *)
         ssGetContStates(S))->Integrator_CSTATE <= _rtP->Integrator_LowerSat) {
      ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S))->Integrator_IntgLoLimit_ZC =
        0.0;
    } else {
      ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S))->Integrator_IntgLoLimit_ZC =
        ((X_tanks_T *) ssGetContStates(S))->Integrator_CSTATE -
        _rtP->Integrator_LowerSat;
    }

    /* zero crossings for leaving limited region */
    {
      boolean_T anyStateSaturated = false;
      if ((_rtDW->Integrator_MODE == INTG_UPPER_SAT) ||
          (_rtDW->Integrator_MODE == INTG_LOWER_SAT)) {
        anyStateSaturated = true;
      }

      if (anyStateSaturated) {
        ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S))
          ->Integrator_LeaveSaturate_ZC = _rtB->Sum_e;
      } else {
        ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S))
          ->Integrator_LeaveSaturate_ZC = 0.0;
      }
    }
  }

  /* ZeroCrossings for Integrator: '<S4>/Integrator' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for enter into limited region */
    if (_rtDW->Integrator_MODE_f == INTG_LEAVING_UPPER_SAT && ((X_tanks_T *)
         ssGetContStates(S))->Integrator_CSTATE_c >= _rtP->Integrator_UpperSat_f)
    {
      ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S))
        ->Integrator_IntgUpLimit_ZC_h = 0.0;
    } else {
      ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S))
        ->Integrator_IntgUpLimit_ZC_h = ((X_tanks_T *) ssGetContStates(S))
        ->Integrator_CSTATE_c - _rtP->Integrator_UpperSat_f;
    }

    if (_rtDW->Integrator_MODE_f == INTG_LEAVING_LOWER_SAT &&((X_tanks_T *)
         ssGetContStates(S))->Integrator_CSTATE_c <= _rtP->Integrator_LowerSat_p)
    {
      ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S))
        ->Integrator_IntgLoLimit_ZC_i = 0.0;
    } else {
      ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S))
        ->Integrator_IntgLoLimit_ZC_i = ((X_tanks_T *) ssGetContStates(S))
        ->Integrator_CSTATE_c - _rtP->Integrator_LowerSat_p;
    }

    /* zero crossings for leaving limited region */
    {
      boolean_T anyStateSaturated = false;
      if ((_rtDW->Integrator_MODE_f == INTG_UPPER_SAT) ||
          (_rtDW->Integrator_MODE_f == INTG_LOWER_SAT)) {
        anyStateSaturated = true;
      }

      if (anyStateSaturated) {
        ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S))
          ->Integrator_LeaveSaturate_ZC_d = _rtB->Sum_el;
      } else {
        ((ZCV_tanks_T *) ssGetSolverZcSignalVector(S))
          ->Integrator_LeaveSaturate_ZC_d = 0.0;
      }
    }
  }

  _rtZCSV->Step_StepTime_ZC = ssGetT(S) - _rtP->Step_Time;
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{
  /* checksum */
  ssSetChecksumVal(S, 0, 794167962U);
  ssSetChecksumVal(S, 1, 3793363511U);
  ssSetChecksumVal(S, 2, 2978612393U);
  ssSetChecksumVal(S, 3, 1961566532U);

  {
    /* First check to see if this is the sample verion of Simulink used
     * to generate this file. If not force a rebuild and return. */
    mxArray *slVerStructMat = NULL;
    mxArray *slStrMat = mxCreateString("simulink");
    char slVerChar[10];
    int status = mexCallMATLAB(1,&slVerStructMat,
      1,&slStrMat,
      "ver");
    if (status == 0) {
      mxArray * slVerMat = mxGetField(slVerStructMat,0,"Version");
      if (slVerMat == NULL) {
        status = 1;
      } else {
        status = mxGetString(slVerMat, slVerChar, 10);
      }
    }

    mxDestroyArray(slStrMat);
    mxDestroyArray(slVerStructMat);
    if ((status == 1) || (strcmp(slVerChar,"8.4") != 0)) {
      return;
    }
  }

  /* options */
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);

  /* Accelerator check memory map size match for DWork */
  if (ssGetSizeofDWork(S) != sizeof(DW_tanks_T)) {
    ssSetErrorStatus(S,"Unexpected error: Internal DWork sizes do "
                     "not match for accelerator mex file.");
  }

  /* Accelerator check memory map size match for BlockIO */
  if (ssGetSizeofGlobalBlockIO(S) != sizeof(B_tanks_T)) {
    ssSetErrorStatus(S,"Unexpected error: Internal BlockIO sizes do "
                     "not match for accelerator mex file.");
  }

  /* Accelerator check memory map size match for Parameters */
  {
    int ssSizeofParams;
    ssGetSizeofParams(S,&ssSizeofParams);
    if (ssSizeofParams != sizeof(P_tanks_T)) {
      static char msg[256];
      sprintf(msg,"Unexpected error: Internal Parameters sizes do "
              "not match for accelerator mex file.");
    }
  }

  /* model parameters */
  _ssSetDefaultParam(S, (real_T *) &tanks_rtDefaultP);
}

/* mdlInitializeSampleTimes function (used to set up function-call connections) */
static void mdlInitializeSampleTimes(SimStruct *S)
{
}

/* Empty mdlTerminate function (never called) */
static void mdlTerminate(SimStruct *S)
{
}

/* MATLAB MEX Glue */
#include "simulink.c"
