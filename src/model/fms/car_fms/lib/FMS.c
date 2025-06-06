/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2049
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jun  6 14:18:01 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S37>/Motion State' */
#define FMS_IN_Hold                    ((uint8_T)1U)
#define FMS_IN_Move                    ((uint8_T)2U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Idle                    ((uint8_T)3U)
#define FMS_IN_InValidManualMode       ((uint8_T)1U)
#define FMS_IN_InvalidArmMode          ((uint8_T)3U)
#define FMS_IN_InvalidAssistMode       ((uint8_T)1U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)1U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_g                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_NextWP                  ((uint8_T)2U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)2U)
#define FMS_IN_Return                  ((uint8_T)2U)
#define FMS_IN_Return_h                ((uint8_T)3U)
#define FMS_IN_Run                     ((uint8_T)2U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_Stabilize               ((uint8_T)3U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Waypoint                ((uint8_T)4U)
#define FMS_event_DisarmEvent          (0)

/* Named constants for Chart: '<Root>/SafeMode' */
#define FMS_IN_Manual_e                ((uint8_T)1U)
#define FMS_IN_Other                   ((uint8_T)4U)
#define FMS_IN_Position_f              ((uint8_T)5U)
#define FMS_IN_Stabilize_j             ((uint8_T)6U)

const FMS_Out_Bus FMS_rtZFMS_Out_Bus = {
  0U,                                  /* timestamp */
  0.0F,                                /* p_cmd */
  0.0F,                                /* q_cmd */
  0.0F,                                /* r_cmd */
  0.0F,                                /* phi_cmd */
  0.0F,                                /* theta_cmd */
  0.0F,                                /* psi_rate_cmd */
  0.0F,                                /* u_cmd */
  0.0F,                                /* v_cmd */
  0.0F,                                /* w_cmd */
  0.0F,                                /* ax_cmd */
  0.0F,                                /* ay_cmd */
  0.0F,                                /* az_cmd */

  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
  ,                                    /* actuator_cmd */
  0U,                                  /* throttle_cmd */
  0U,                                  /* cmd_mask */
  0U,                                  /* status */
  0U,                                  /* state */
  0U,                                  /* ctrl_mode */
  0U,                                  /* mode */
  0U,                                  /* reset */
  0U,                                  /* wp_consume */
  0U,                                  /* wp_current */
  0U,                                  /* reserved */

  {
    0.0F, 0.0F, 0.0F, 0.0F }
  ,                                    /* home */
  0U                                   /* error */
} ;                                    /* FMS_Out_Bus ground */

/* Exported block parameters */
struct_LVGChNcHeHKlRRwAVwv2dD FMS_PARAM = {
  { 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F },

  { 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F },
  10.0F,
  3.0F,
  5.0F,
  1.0F,
  4.0F,
  0.52359879F,
  0.5F,
  5.0F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S24>/Constant6'
                                        *   '<S25>/Constant6'
                                        *   '<S32>/Gain'
                                        *   '<S32>/Gain1'
                                        *   '<S146>/L1'
                                        *   '<S146>/vel'
                                        *   '<S35>/Gain'
                                        *   '<S67>/L1'
                                        *   '<S67>/vel'
                                        *   '<S86>/L1'
                                        *   '<S87>/vel'
                                        *   '<S148>/AccToRate'
                                        *   '<S68>/AccToRate'
                                        *   '<S92>/Gain2'
                                        *   '<S94>/AccToRate'
                                        *   '<S38>/L1'
                                        *   '<S38>/AccToRate'
                                        *   '<S39>/Gain6'
                                        */

struct_jgVLU9PsiazymsYzo6u6IH FMS_EXPORT = {
  10U,

  { 67, 97, 114, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S10>/Constant1'
                                        *   '<S165>/Constant'
                                        */

/* Block signals (default storage) */
B_FMS_T FMS_B;

/* Block states (default storage) */
DW_FMS_T FMS_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_FMS_T FMS_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_FMS_T FMS_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FMS_T FMS_Y;

/* Real-time model */
RT_MODEL_FMS_T FMS_M_;
RT_MODEL_FMS_T *const FMS_M = &FMS_M_;

/* Forward declaration for local functions */
static void FMS_sf_msg_send_M(void);
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag);
static boolean_T FMS_BottomRight(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_BottomLeft(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_sf_msg_pop_M(void);
static real32_T FMS_norm(const real32_T x[2]);
static void FMS_exit_internal_Auto(void);
static real_T FMS_getArmMode(PilotMode pilotMode);
static void FMS_enter_internal_Auto(void);
static void FMS_enter_internal_Arm(void);
static void FMS_SubMode(void);
static void FMS_exit_internal_Arm(void);
static void FMS_Arm(void);
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode);
static void FMS_Vehicle(void);
static void FMS_c11_FMS(void);
static void FMS_sf_msg_discard_M(void);
static void initialize_msg_local_queues_for(void);

/*
 * Output and update for atomic system:
 *    '<S150>/NearbyRefWP'
 *    '<S70>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_k, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S154>/TmpSignal ConversionAt SFunction Inport2' */
  P3P2_idx_0 = rtu_P2[0] - rtu_P3;
  P3P2_idx_1 = rtu_P2[1] - rtu_P3_k;
  P3P2_idx_0 = sqrtf(P3P2_idx_0 * P3P2_idx_0 + P3P2_idx_1 * P3P2_idx_1);
  if (P3P2_idx_0 <= rtu_L1) {
    *rty_d = P3P2_idx_0;
    rty_P[0] = rtu_P2[0];
    rty_P[1] = rtu_P2[1];
  } else {
    *rty_d = -1.0F;
    rty_P[0] = 0.0F;
    rty_P[1] = 0.0F;
  }
}

/*
 * Output and update for action system:
 *    '<S29>/Unknown'
 *    '<S27>/Unknown'
 *    '<S26>/Unknown'
 *    '<S22>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S147>/Bus Assignment' incorporates:
   *  Constant: '<S147>/Constant'
   *  Constant: '<S147>/Constant2'
   *  SignalConversion: '<S147>/TmpHiddenBufferAtBus AssignmentInport1'
   */
  *rty_FMS_Out = FMS_rtZFMS_Out_Bus;
  rty_FMS_Out->reset = 1U;
  rty_FMS_Out->status = localC->DataTypeConversion;
  rty_FMS_Out->state = localC->DataTypeConversion1;
  rty_FMS_Out->actuator_cmd[0] = 1000U;
  rty_FMS_Out->actuator_cmd[1] = 1000U;
  rty_FMS_Out->actuator_cmd[2] = 1000U;
  rty_FMS_Out->actuator_cmd[3] = 1000U;
  for (i = 0; i < 12; i++) {
    rty_FMS_Out->actuator_cmd[i + 4] = 0U;
  }

  /* End of BusAssignment: '<S147>/Bus Assignment' */
}

int32_T FMS_emplace(Queue_FMS_Cmd *q, const FMS_Cmd *dataIn)
{
  int32_T isEmplaced;
  int32_T newTail;
  Msg_FMS_Cmd *msg;
  newTail = (q->fTail + 1) % q->fCapacity;
  if (q->fHead == newTail) {
    isEmplaced = 0;
  } else {
    q->fTail = newTail;
    msg = &q->fArray[newTail];
    msg->fData = *dataIn;
    if (q->fHead == -1) {
      q->fHead = q->fTail;
    }

    isEmplaced = 1;
  }

  return isEmplaced;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_sf_msg_send_M(void)
{
  FMS_emplace(&FMS_DW.Queue_FMS_Cmd_k, &FMS_DW.M_msgReservedData);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag)
{
  boolean_T valid;
  valid = false;
  if ((ins_flag & 1U) != 0U) {
    switch (cmd_in) {
     case FMS_Cmd_Return:
     case FMS_Cmd_Pause:
      if (((ins_flag & 8U) != 0U) && ((ins_flag & 16U) != 0U) && ((ins_flag &
            64U) != 0U)) {
        valid = true;
      }
      break;

     case FMS_Cmd_PreArm:
      switch (mode_in) {
       case PilotMode_Position:
       case PilotMode_Offboard:
        if (((ins_flag & 8U) != 0U) && ((ins_flag & 16U) != 0U) && ((ins_flag &
              64U) != 0U)) {
          valid = true;
        }
        break;

       case PilotMode_Mission:
        if (((ins_flag & 8U) != 0U) && ((ins_flag & 16U) != 0U) && ((ins_flag &
              32U) != 0U) && ((ins_flag & 64U) != 0U)) {
          valid = true;
        }
        break;

       case PilotMode_Stabilize:
        valid = true;
        break;

       case PilotMode_Manual:
        valid = true;
        break;
      }
      break;

     case FMS_Cmd_Continue:
      if ((mode_in == PilotMode_Offboard) || (mode_in == PilotMode_Mission)) {
        valid = true;
      }
      break;

     case FMS_Cmd_Disarm:
      valid = true;
      break;
    }
  }

  return valid;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_BottomRight(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle)
{
  return (pilot_cmd_stick_throttle < -0.8) && (pilot_cmd_stick_yaw > 0.8);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_BottomLeft(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle)
{
  return (pilot_cmd_stick_throttle < -0.8) && (pilot_cmd_stick_yaw < -0.8);
}

int32_T FMS_pop(Queue_FMS_Cmd *q, Msg_FMS_Cmd *elementOut)
{
  int32_T isPop;
  if (q->fHead == -1) {
    isPop = 0;
  } else {
    *elementOut = q->fArray[q->fHead];
    isPop = 1;
    if (q->fHead == q->fTail) {
      q->fHead = -1;
      q->fTail = -1;
    } else {
      q->fHead = (q->fHead + 1) % q->fCapacity;
    }
  }

  return isPop;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_sf_msg_pop_M(void)
{
  boolean_T isPresent;
  if (FMS_DW.M_isValid) {
    isPresent = true;
  } else {
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_k, &FMS_DW.Msg_FMS_Cmd_d
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_d[0] : NULL;
    if (FMS_DW.M_msgHandle != NULL) {
      FMS_DW.M_msgDataPtr = &((Msg_FMS_Cmd *)FMS_DW.M_msgHandle)->fData;
      isPresent = true;
      FMS_DW.M_msgReservedData = *(FMS_Cmd *)FMS_DW.M_msgDataPtr;
      FMS_DW.M_isValid = true;
    } else {
      isPresent = false;
      FMS_DW.M_isValid = false;
    }
  }

  return isPresent;
}

real_T rt_modd(real_T u0, real_T u1)
{
  real_T y;
  boolean_T yEq;
  real_T q;
  y = u0;
  if (u0 == 0.0) {
    y = 0.0;
  } else {
    if (u1 != 0.0) {
      y = fmod(u0, u1);
      yEq = (y == 0.0);
      if ((!yEq) && (u1 > floor(u1))) {
        q = fabs(u0 / u1);
        yEq = (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q);
      }

      if (yEq) {
        y = 0.0;
      } else {
        if ((u0 < 0.0) != (u1 < 0.0)) {
          y += u1;
        }
      }
    }
  }

  return y;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static real32_T FMS_norm(const real32_T x[2])
{
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  scale = 1.29246971E-26F;
  absxk = fabsf(x[0]);
  if (absxk > 1.29246971E-26F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    y = t * t;
  }

  absxk = fabsf(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrtf(y);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_exit_internal_Auto(void)
{
  if (FMS_DW.is_Auto == FMS_IN_Mission) {
    FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD;
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD;
  } else {
    FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD;
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static real_T FMS_getArmMode(PilotMode pilotMode)
{
  real_T armMode;
  switch (pilotMode) {
   case PilotMode_Manual:
    armMode = 1.0;
    break;

   case PilotMode_Acro:
    armMode = 2.0;
    break;

   case PilotMode_Stabilize:
    armMode = 2.0;
    break;

   case PilotMode_Altitude:
    armMode = 2.0;
    break;

   case PilotMode_Position:
    armMode = 2.0;
    break;

   case PilotMode_Mission:
    armMode = 3.0;
    break;

   case PilotMode_Offboard:
    armMode = 3.0;
    break;

   default:
    armMode = 0.0;
    break;
  }

  return armMode;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_enter_internal_Auto(void)
{
  uint32_T qY;
  switch (FMS_B.target_mode) {
   case PilotMode_Offboard:
    FMS_DW.is_Auto = FMS_IN_Offboard;
    if (FMS_B.LogicalOperator) {
      FMS_DW.is_Offboard = FMS_IN_Run;
      FMS_B.state = VehicleState_Offboard;
    } else {
      FMS_DW.is_Offboard = FMS_IN_Loiter;
      FMS_B.state = VehicleState_Hold;
    }
    break;

   case PilotMode_Mission:
    FMS_DW.is_Auto = FMS_IN_Mission;
    FMS_DW.llo[0] = FMS_B.BusConversion_InsertedFor_FMSSt.lat_0 *
      57.295779513082323;
    FMS_DW.llo[1] = FMS_B.BusConversion_InsertedFor_FMSSt.lon_0 *
      57.295779513082323;
    FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
    FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
    FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
    FMS_DW.is_Mission = FMS_IN_NextWP;

    /* Inport: '<Root>/Mission_Data' */
    if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
      FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
    } else {
      FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
      qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
      if (qY > FMS_B.wp_index) {
        qY = 0U;
      }

      FMS_B.wp_consume = (uint8_T)qY;
    }

    /* End of Inport: '<Root>/Mission_Data' */
    break;

   default:
    FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
    break;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_enter_internal_Arm(void)
{
  real_T tmp;
  tmp = FMS_getArmMode(FMS_B.target_mode);
  if (tmp == 3.0) {
    FMS_DW.is_Arm = FMS_IN_Auto;
    FMS_enter_internal_Auto();
  } else if (tmp == 2.0) {
    FMS_DW.is_Arm = FMS_IN_Assist;
    switch (FMS_B.target_mode) {
     case PilotMode_Stabilize:
      FMS_DW.is_Assist = FMS_IN_Stabilize;
      FMS_B.state = VehicleState_Stabilize;
      break;

     case PilotMode_Position:
      FMS_DW.is_Assist = FMS_IN_Position;
      FMS_B.state = VehicleState_Position;
      break;

     default:
      FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
      break;
    }
  } else if (tmp == 1.0) {
    FMS_DW.is_Arm = FMS_IN_Manual;
    if (FMS_B.target_mode == PilotMode_Manual) {
      FMS_DW.is_Manual = FMS_IN_Manual_g;
      FMS_B.state = VehicleState_Manual;
    } else {
      FMS_DW.is_Manual = FMS_IN_InValidManualMode;
    }
  } else {
    FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_SubMode(void)
{
  boolean_T b_sf_internal_predicateOutput;
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  real_T tmp;
  FMS_B.stick_val[0] = FMS_DW.stick_val[0];
  FMS_B.stick_val[1] = FMS_DW.stick_val[1];
  FMS_B.stick_val[2] = FMS_DW.stick_val[2];
  FMS_B.stick_val[3] = FMS_DW.stick_val[3];
  FMS_B.pilot_cmd = FMS_B.BusConversion_InsertedFor_FMS_f;

  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S178>/Compare' incorporates:
   *  Abs: '<S167>/Abs'
   *  Constant: '<S178>/Constant'
   *  MinMax: '<S167>/Max'
   *  Sum: '<S167>/Sum'
   */
  FMS_B.Compare = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S4>/Vehicle.StickMoved' */
  if (FMS_B.Compare && (FMS_B.target_mode != PilotMode_None)) {
    tmp = FMS_getArmMode(FMS_B.target_mode);
    if (tmp == 3.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (tmp == 2.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
      FMS_DW.is_Arm = FMS_IN_Assist;
      switch (FMS_B.target_mode) {
       case PilotMode_Stabilize:
        FMS_DW.is_Assist = FMS_IN_Stabilize;
        FMS_B.state = VehicleState_Stabilize;
        break;

       case PilotMode_Position:
        FMS_DW.is_Assist = FMS_IN_Position;
        FMS_B.state = VehicleState_Position;
        break;

       default:
        FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
        break;
      }
    } else if (tmp == 1.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
      FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
    }
  } else {
    if (FMS_sf_msg_pop_M()) {
      b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Pause);
    } else {
      b_sf_internal_predicateOutput = false;
    }

    if (b_sf_internal_predicateOutput) {
      FMS_DW.is_SubMode = FMS_IN_Hold;
      FMS_B.state = VehicleState_Hold;
    } else {
      switch (FMS_DW.is_SubMode) {
       case FMS_IN_Hold:
        if (FMS_sf_msg_pop_M()) {
          b_sf_internal_predicateOutput = ((FMS_DW.M_msgReservedData ==
            FMS_Cmd_Continue) && (FMS_B.target_mode != PilotMode_None));
        } else {
          b_sf_internal_predicateOutput = false;
        }

        if (b_sf_internal_predicateOutput) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
          FMS_enter_internal_Arm();
        }
        break;

       case FMS_IN_Return:
        scale = 1.29246971E-26F;
        absxk = fabsf(FMS_B.BusConversion_InsertedFor_FMSSt.x_R - FMS_DW.home[0]);
        if (absxk > 1.29246971E-26F) {
          y = 1.0F;
          scale = absxk;
        } else {
          t = absxk / 1.29246971E-26F;
          y = t * t;
        }

        absxk = fabsf(FMS_B.BusConversion_InsertedFor_FMSSt.y_R - FMS_DW.home[1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0F;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }

        y = scale * sqrtf(y);

        /* Constant: '<Root>/ACCEPT_R' */
        if (y <= FMS_PARAM.ACCEPT_R) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
        }

        /* End of Constant: '<Root>/ACCEPT_R' */
        break;
      }
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_exit_internal_Arm(void)
{
  if (FMS_DW.is_Arm == FMS_IN_Auto) {
    FMS_exit_internal_Auto();
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD;
    FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Arm(void)
{
  boolean_T b_sf_internal_predicateOutput;
  real_T rtb_Multiply2;
  real_T rtb_Sum2_m;
  real_T rtb_Gain;
  real_T rtb_Sum_d;
  real32_T tmp[2];
  real_T rtb_Sum_idx_0;
  uint32_T qY;
  int32_T lla_tmp;
  if ((FMS_DW.mode_prev != FMS_DW.mode_start) && (FMS_B.target_mode !=
       PilotMode_None)) {
    rtb_Sum_idx_0 = FMS_getArmMode(FMS_B.target_mode);
    if (rtb_Sum_idx_0 == 3.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (rtb_Sum_idx_0 == 2.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Assist;
      switch (FMS_B.target_mode) {
       case PilotMode_Stabilize:
        FMS_DW.is_Assist = FMS_IN_Stabilize;
        FMS_B.state = VehicleState_Stabilize;
        break;

       case PilotMode_Position:
        FMS_DW.is_Assist = FMS_IN_Position;
        FMS_B.state = VehicleState_Position;
        break;

       default:
        FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
        break;
      }
    } else if (rtb_Sum_idx_0 == 1.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
    }
  } else {
    if (FMS_sf_msg_pop_M()) {
      b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
        FMS_Cmd_Return);
    } else {
      b_sf_internal_predicateOutput = false;
    }

    if (b_sf_internal_predicateOutput) {
      FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
      FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
      FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
      FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
      FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
      FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
      FMS_DW.is_SubMode = FMS_IN_Return;
      FMS_B.state = VehicleState_Return;
    } else {
      switch (FMS_DW.is_Arm) {
       case FMS_IN_Assist:
        if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
          FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
        }
        break;

       case FMS_IN_Auto:
        if (FMS_sf_msg_pop_M()) {
          b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
            FMS_Cmd_Pause);
        } else {
          b_sf_internal_predicateOutput = false;
        }

        if (b_sf_internal_predicateOutput) {
          FMS_exit_internal_Auto();
          FMS_DW.is_Arm = FMS_IN_SubMode;
          FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
          FMS_DW.stick_val[1] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
          FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
          FMS_DW.stick_val[3] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
          FMS_DW.is_SubMode = FMS_IN_Hold;
          FMS_B.state = VehicleState_Hold;
        } else {
          switch (FMS_DW.is_Auto) {
           case FMS_IN_InvalidAutoMode:
            FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
            FMS_DW.is_Vehicle = FMS_IN_Disarm;
            FMS_B.state = VehicleState_Disarm;
            break;

           case FMS_IN_Mission:
            if (FMS_DW.mission_timestamp_prev != FMS_DW.mission_timestamp_start)
            {
              FMS_DW.is_Mission = FMS_IN_NextWP;

              /* Inport: '<Root>/Mission_Data' */
              if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
                FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
              } else {
                FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
                qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
                if (qY > FMS_B.wp_index) {
                  qY = 0U;
                }

                FMS_B.wp_consume = (uint8_T)qY;
              }
            } else {
              switch (FMS_DW.is_Mission) {
               case FMS_IN_Loiter:
                break;

               case FMS_IN_NextWP:
                if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Waypoint) {
                  FMS_DW.is_Mission = FMS_IN_Waypoint;
                  lla_tmp = FMS_B.wp_index - 1;

                  /* Inport: '<Root>/Mission_Data' */
                  FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[lla_tmp] * 1.0E-7;
                  FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[lla_tmp] * 1.0E-7;
                  FMS_B.lla[2] = -(FMS_U.Mission_Data.z[lla_tmp] + FMS_DW.home[2]);
                  FMS_B.href = 0.0;
                  FMS_B.psio = 0.0;
                  FMS_B.llo[0] = FMS_DW.llo[0];

                  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  /* Sum: '<S168>/Sum' */
                  rtb_Sum_idx_0 = FMS_B.lla[0] - FMS_B.llo[0];

                  /* End of Outputs for SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  FMS_B.llo[1] = FMS_DW.llo[1];

                  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  /* Gain: '<S168>/deg2rad' */
                  rtb_Multiply2 = 0.017453292519943295 * FMS_B.llo[0];

                  /* Trigonometry: '<S169>/Sin' */
                  rtb_Sum2_m = sin(rtb_Multiply2);

                  /* Math: '<S169>/Square1' */
                  rtb_Sum2_m *= rtb_Sum2_m;

                  /* Product: '<S169>/Multiply1' incorporates:
                   *  Product: '<S169>/Multiply'
                   */
                  rtb_Gain = FMS_ConstB.ff * rtb_Sum2_m;

                  /* Product: '<S169>/Divide' incorporates:
                   *  Constant: '<S169>/Constant'
                   *  Constant: '<S169>/R'
                   *  Sqrt: '<S169>/Sqrt'
                   *  Sum: '<S169>/Sum1'
                   */
                  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain);

                  /* Product: '<S169>/Product3' incorporates:
                   *  Constant: '<S169>/Constant1'
                   *  Product: '<S169>/Multiply1'
                   *  Sum: '<S169>/Sum2'
                   */
                  rtb_Gain = 1.0 / (1.0 - rtb_Gain) * FMS_ConstB.Sum4 *
                    rtb_Sum2_m;

                  /* Product: '<S169>/Multiply2' incorporates:
                   *  Trigonometry: '<S169>/Cos'
                   */
                  rtb_Sum2_m *= cos(rtb_Multiply2);

                  /* Abs: '<S173>/Abs' incorporates:
                   *  Abs: '<S176>/Abs1'
                   *  Switch: '<S173>/Switch1'
                   */
                  rtb_Multiply2 = fabs(rtb_Sum_idx_0);

                  /* Switch: '<S173>/Switch1' incorporates:
                   *  Abs: '<S173>/Abs'
                   *  Bias: '<S173>/Bias2'
                   *  Bias: '<S173>/Bias3'
                   *  Constant: '<S170>/Constant'
                   *  Constant: '<S170>/Constant1'
                   *  Constant: '<S175>/Constant'
                   *  Gain: '<S173>/Gain1'
                   *  Product: '<S173>/Multiply'
                   *  RelationalOperator: '<S175>/Compare'
                   *  Switch: '<S170>/Switch'
                   */
                  if (rtb_Multiply2 > 90.0) {
                    /* Switch: '<S176>/Switch1' incorporates:
                     *  Bias: '<S176>/Bias2'
                     *  Bias: '<S176>/Bias3'
                     *  Constant: '<S176>/Constant'
                     *  Constant: '<S177>/Constant'
                     *  Math: '<S176>/Math Function'
                     *  RelationalOperator: '<S177>/Compare'
                     */
                    if (rtb_Multiply2 > 180.0) {
                      rtb_Sum_idx_0 = rt_modd(rtb_Sum_idx_0 + 180.0, 360.0) +
                        -180.0;
                    }

                    /* End of Switch: '<S176>/Switch1' */

                    /* Signum: '<S173>/Sign' */
                    if (rtb_Sum_idx_0 < 0.0) {
                      rtb_Sum_idx_0 = -1.0;
                    } else {
                      if (rtb_Sum_idx_0 > 0.0) {
                        rtb_Sum_idx_0 = 1.0;
                      }
                    }

                    /* End of Signum: '<S173>/Sign' */
                    rtb_Multiply2 = (-(rtb_Multiply2 + -90.0) + 90.0) *
                      rtb_Sum_idx_0;
                    lla_tmp = 180;
                  } else {
                    rtb_Multiply2 = rtb_Sum_idx_0;
                    lla_tmp = 0;
                  }

                  /* Sum: '<S170>/Sum' incorporates:
                   *  Sum: '<S168>/Sum'
                   */
                  rtb_Sum_d = (FMS_B.lla[1] - FMS_B.llo[1]) + (real_T)lla_tmp;

                  /* Product: '<S168>/Multiply' incorporates:
                   *  Gain: '<S168>/deg2rad1'
                   */
                  rtb_Sum_idx_0 = 0.017453292519943295 * rtb_Multiply2 *
                    rtb_Gain;

                  /* Switch: '<S172>/Switch1' incorporates:
                   *  Abs: '<S172>/Abs1'
                   *  Bias: '<S172>/Bias2'
                   *  Bias: '<S172>/Bias3'
                   *  Constant: '<S172>/Constant'
                   *  Constant: '<S174>/Constant'
                   *  Math: '<S172>/Math Function'
                   *  RelationalOperator: '<S174>/Compare'
                   */
                  if (fabs(rtb_Sum_d) > 180.0) {
                    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
                  }

                  /* End of Switch: '<S172>/Switch1' */

                  /* Product: '<S168>/Multiply' incorporates:
                   *  Gain: '<S168>/deg2rad1'
                   */
                  rtb_Multiply2 = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

                  /* Gain: '<S168>/deg2rad2' */
                  rtb_Sum2_m = 0.017453292519943295 * FMS_B.psio;

                  /* Trigonometry: '<S171>/SinCos' */
                  rtb_Sum_d = sin(rtb_Sum2_m);
                  rtb_Gain = cos(rtb_Sum2_m);

                  /* Sum: '<S171>/Sum2' incorporates:
                   *  Product: '<S171>/Multiply1'
                   *  Product: '<S171>/Multiply2'
                   */
                  rtb_Sum2_m = rtb_Sum_idx_0 * rtb_Gain + rtb_Multiply2 *
                    rtb_Sum_d;

                  /* Product: '<S171>/Multiply3' */
                  rtb_Sum_d *= rtb_Sum_idx_0;

                  /* Product: '<S171>/Multiply4' */
                  rtb_Gain *= rtb_Multiply2;

                  /* Sum: '<S171>/Sum3' */
                  rtb_Sum_d = rtb_Gain - rtb_Sum_d;

                  /* DataTypeConversion: '<S166>/Data Type Conversion' incorporates:
                   *  Gain: '<S168>/Gain'
                   *  Sum: '<S168>/Sum1'
                   */
                  FMS_B.DataTypeConversion[0] = (real32_T)rtb_Sum2_m;
                  FMS_B.DataTypeConversion[1] = (real32_T)rtb_Sum_d;
                  FMS_B.DataTypeConversion[2] = (real32_T)-(FMS_B.lla[2] +
                    FMS_B.href);

                  /* End of Outputs for SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                  FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
                  FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
                  FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
                  FMS_B.state = VehicleState_Mission;
                } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
                  FMS_DW.is_Mission = FMS_IN_Return_h;
                  FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
                  FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
                  FMS_B.Cmd_In.sp_waypoint[2] =
                    FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
                  FMS_B.state = VehicleState_Return;
                } else {
                  FMS_DW.is_Mission = FMS_IN_Loiter;
                  FMS_B.state = VehicleState_Hold;
                }
                break;

               case FMS_IN_Return_h:
                tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
                  FMS_B.Cmd_In.sp_waypoint[0];
                tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
                  FMS_B.Cmd_In.sp_waypoint[1];
                if (FMS_norm(tmp) < 0.5F) {
                  lla_tmp = (int32_T)(FMS_B.wp_index + 1U);
                  if ((uint32_T)lla_tmp > 255U) {
                    lla_tmp = 255;
                  }

                  FMS_B.wp_index = (uint8_T)lla_tmp;
                  FMS_DW.is_Mission = FMS_IN_NextWP;

                  /* Inport: '<Root>/Mission_Data' */
                  if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
                    FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index -
                      1];
                  } else {
                    FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
                    qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
                    if (qY > FMS_B.wp_index) {
                      qY = 0U;
                    }

                    FMS_B.wp_consume = (uint8_T)qY;
                  }
                }
                break;

               case FMS_IN_Waypoint:
                tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
                  FMS_B.Cmd_In.sp_waypoint[0];
                tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
                  FMS_B.Cmd_In.sp_waypoint[1];

                /* Constant: '<Root>/ACCEPT_R' */
                if (FMS_norm(tmp) <= FMS_PARAM.ACCEPT_R) {
                  FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
                  FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
                  FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
                  lla_tmp = (int32_T)(FMS_B.wp_index + 1U);
                  if ((uint32_T)lla_tmp > 255U) {
                    lla_tmp = 255;
                  }

                  FMS_B.wp_index = (uint8_T)lla_tmp;
                  FMS_DW.is_Mission = FMS_IN_NextWP;

                  /* Inport: '<Root>/Mission_Data' */
                  if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
                    FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index -
                      1];
                  } else {
                    FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
                    qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
                    if (qY > FMS_B.wp_index) {
                      qY = 0U;
                    }

                    FMS_B.wp_consume = (uint8_T)qY;
                  }
                }

                /* End of Constant: '<Root>/ACCEPT_R' */
                break;
              }
            }
            break;

           case FMS_IN_Offboard:
            switch (FMS_DW.is_Offboard) {
             case FMS_IN_Loiter:
              if (FMS_B.LogicalOperator) {
                FMS_DW.is_Offboard = FMS_IN_Run;
                FMS_B.state = VehicleState_Offboard;
              }
              break;

             case FMS_IN_Run:
              if (!FMS_B.LogicalOperator) {
                FMS_DW.is_Offboard = FMS_IN_Loiter;
                FMS_B.state = VehicleState_Hold;
              }
              break;
            }
            break;
          }
        }
        break;

       case FMS_IN_InvalidArmMode:
        FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
        FMS_DW.is_Vehicle = FMS_IN_Disarm;
        FMS_B.state = VehicleState_Disarm;
        break;

       case FMS_IN_Manual:
        if (FMS_DW.is_Manual == FMS_IN_InValidManualMode) {
          FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
        }
        break;

       case FMS_IN_SubMode:
        FMS_SubMode();
        break;
      }
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode)
{
  real_T trigger;
  trigger = 0.0;
  switch (pilot_cmd_mode) {
   case PilotMode_Manual:
   case PilotMode_Stabilize:
   case PilotMode_Position:
    if (pilot_cmd_stick_throttle > 0.0F) {
      trigger = 1.0;
    }
    break;
  }

  return trigger;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Vehicle(void)
{
  boolean_T sf_internal_predicateOutput;
  int32_T b_previousEvent;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  if (FMS_DW.mission_timestamp_prev != FMS_DW.mission_timestamp_start) {
    FMS_B.wp_consume = 0U;
    FMS_B.wp_index = 1U;
  }

  if (FMS_sf_msg_pop_M()) {
    sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Disarm);
  } else {
    sf_internal_predicateOutput = false;
  }

  if (sf_internal_predicateOutput) {
    switch (FMS_DW.is_Vehicle) {
     case FMS_IN_Arm:
      FMS_exit_internal_Arm();
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD;
      break;

     case FMS_IN_Standby:
      FMS_DW.prep_mission = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_1))
      {
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1 = sf_internal_predicateOutput;
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD;
      break;

     default:
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD;
      break;
    }

    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else {
    guard1 = false;
    switch (FMS_DW.is_Vehicle) {
     case FMS_IN_Arm:
      FMS_Arm();
      break;

     case FMS_IN_Disarm:
      if (FMS_sf_msg_pop_M()) {
        sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
          FMS_Cmd_PreArm);
      } else {
        sf_internal_predicateOutput = false;
      }

      if (sf_internal_predicateOutput) {
        FMS_DW.condWasTrueAtLastTimeStep_1 = false;
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
        FMS_DW.is_Vehicle = FMS_IN_Standby;
        FMS_DW.temporalCounter_i1 = 0U;
        guard2 = false;
        if (FMS_B.target_mode == PilotMode_Mission) {
          if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
            FMS_DW.prep_mission = 1.0;
            FMS_DW.condWasTrueAtLastTimeStep_1 = (FMS_DW.prep_mission == 1.0);
            guard2 = true;
          } else {
            b_previousEvent = FMS_DW.sfEvent;
            FMS_DW.sfEvent = FMS_event_DisarmEvent;

            /* Chart: '<Root>/FMS State Machine' */
            FMS_c11_FMS();
            FMS_DW.sfEvent = b_previousEvent;
            if (FMS_DW.is_Vehicle != FMS_IN_Standby) {
            } else {
              guard2 = true;
            }
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          FMS_DW.home[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
          FMS_DW.home[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
          FMS_DW.home[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
          FMS_DW.home[3] = FMS_B.BusConversion_InsertedFor_FMSSt.psi;
          FMS_B.state = VehicleState_Standby;
        }

        if (FMS_DW.is_Vehicle == FMS_IN_Standby) {
          sf_internal_predicateOutput = (FMS_DW.prep_mission == 1.0);
          if ((!sf_internal_predicateOutput) ||
              (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
            FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1 = sf_internal_predicateOutput;
        }
      }
      break;

     case FMS_IN_Standby:
      if ((FMS_ManualArmEvent
           (FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
            FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
          (FMS_B.target_mode != PilotMode_None)) {
        guard1 = true;
      } else if ((FMS_DW.temporalCounter_i1 >= 1000U) || (FMS_DW.sfEvent ==
                  FMS_event_DisarmEvent)) {
        FMS_DW.prep_mission = 0.0;
        sf_internal_predicateOutput = (FMS_DW.prep_mission == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
          FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1 = sf_internal_predicateOutput;
        FMS_DW.is_Vehicle = FMS_IN_Disarm;
        FMS_B.state = VehicleState_Disarm;
      } else {
        sf_internal_predicateOutput = (FMS_DW.prep_mission == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
          FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1 = sf_internal_predicateOutput;
        if ((FMS_DW.chartAbsoluteTimeCounter -
             FMS_DW.durationLastReferenceTick_1 >= 200) || ((FMS_B.target_mode ==
              PilotMode_Offboard) && FMS_B.LogicalOperator)) {
          guard1 = true;
        }
      }
      break;
    }

    if (guard1) {
      FMS_DW.prep_mission = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_1))
      {
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1 = sf_internal_predicateOutput;
      FMS_DW.is_Vehicle = FMS_IN_Arm;
      FMS_enter_internal_Arm();
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_c11_FMS(void)
{
  int32_T b_previousEvent;

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  if (FMS_DW.is_active_c11_FMS == 0U) {
    FMS_DW.mission_timestamp_prev = FMS_U.Mission_Data.timestamp;
    FMS_DW.mission_timestamp_start = FMS_U.Mission_Data.timestamp;
    FMS_DW.cmd_prev = FMS_B.Switch1;
    FMS_DW.cmd_start = FMS_B.Switch1;
    FMS_DW.mode_prev = FMS_B.target_mode;
    FMS_DW.mode_start = FMS_B.target_mode;
    FMS_DW.chartAbsoluteTimeCounter = 0;
    FMS_DW.is_active_c11_FMS = 1U;
    FMS_DW.is_active_Command_Listener = 1U;
    FMS_DW.is_Command_Listener = FMS_IN_Listen;
    FMS_DW.is_active_Combo_Stick = 1U;
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
    FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
    FMS_DW.is_active_Vehicle = 1U;
    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else {
    if (FMS_DW.is_active_Command_Listener != 0U) {
      switch (FMS_DW.is_Command_Listener) {
       case FMS_IN_Check:
        if (FMS_DW.valid_cmd) {
          FMS_DW.is_Command_Listener = FMS_IN_Send;
          FMS_DW.M_msgReservedData = FMS_DW.save_cmd;
          FMS_sf_msg_send_M();
        } else {
          FMS_DW.is_Command_Listener = FMS_IN_Listen;
        }
        break;

       case FMS_IN_Listen:
        if ((FMS_DW.cmd_prev != FMS_DW.cmd_start) && (FMS_B.Switch1 !=
             FMS_Cmd_None)) {
          FMS_DW.save_cmd = FMS_B.Switch1;
          FMS_DW.is_Command_Listener = FMS_IN_Check;
          FMS_DW.valid_cmd = FMS_CheckCmdValid(FMS_DW.save_cmd,
            FMS_B.target_mode, FMS_B.BusConversion_InsertedFor_FMSSt.flag);
        }
        break;

       case FMS_IN_Send:
        FMS_DW.is_Command_Listener = FMS_IN_Listen;
        break;
      }
    }

    if (FMS_DW.is_active_Combo_Stick != 0U) {
      switch (FMS_DW.is_Combo_Stick) {
       case FMS_IN_Arm:
        if (!FMS_BottomRight(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                             FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_c)) {
          FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_h > 150) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
            FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
          if (FMS_DW.chartAbsoluteTimeCounter -
              FMS_DW.durationLastReferenceTick_2 > 150) {
            FMS_DW.is_Combo_Stick = FMS_IN_Disarm;
            b_previousEvent = FMS_DW.sfEvent;
            FMS_DW.sfEvent = FMS_event_DisarmEvent;
            if (FMS_DW.is_active_Vehicle != 0U) {
              FMS_Vehicle();
            }

            FMS_DW.sfEvent = b_previousEvent;
          } else {
            FMS_DW.bl = FMS_BottomLeft
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
              FMS_DW.durationLastReferenceTick_2 =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
            FMS_DW.br = FMS_BottomRight
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_c)) {
              FMS_DW.durationLastReferenceTick_1_h =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
          }
        }
        break;
      }
    }

    if (FMS_DW.is_active_Vehicle != 0U) {
      FMS_Vehicle();
    }
  }

  /* End of Chart: '<Root>/FMS State Machine' */
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_sf_msg_discard_M(void)
{
  if (FMS_DW.M_isValid) {
    FMS_DW.M_isValid = false;
  }
}

void FMS_initQueue(Queue_FMS_Cmd *q, QueuePolicy_T policy, int32_T capacity,
                   Msg_FMS_Cmd *qPool)
{
  q->fPolicy = policy;
  q->fCapacity = capacity;
  q->fHead = -1;
  q->fTail = -1;
  q->fArray = qPool;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void initialize_msg_local_queues_for(void)
{
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_k, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_d[1]);
}

/* Model step function */
void FMS_step(void)
{
  real32_T A;
  real32_T D;
  uint8_T rtb_Switch_b5;
  int8_T rtPrevAction;
  real32_T rtb_Saturation_gm;
  real32_T rtb_Divide_g[2];
  real32_T rtb_MathFunction_k[2];
  real32_T rtb_AccToRate_c;
  real32_T rtb_Switch_bq[3];
  real32_T rtb_Gain;
  real_T rtb_Switch1_l;
  real_T rtb_Gain_b;
  real_T rtb_Sum3;
  boolean_T rtb_Compare_m;
  MotionState rtb_state;
  real32_T rtb_VectorConcatenate_e[9];
  int32_T i;
  boolean_T u;
  real_T rtb_Multiply_c_idx_0;
  real32_T rtb_Switch_f_idx_0;
  real32_T rtb_Switch_f_idx_1;
  real32_T rtb_Switch_f_idx_2;
  real32_T rtb_TmpSignalConversionAtMath_0;
  real32_T rtb_P_f_idx_0;
  real32_T rtb_P_f_idx_1;
  real32_T a_tmp;
  real32_T b_a_tmp;
  real32_T u1_tmp;
  boolean_T guard1 = false;

  /* Outputs for Atomic SubSystem: '<Root>/CommandProcess' */
  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S14>/FixPt Relational Operator'
   *  UnitDelay: '<S14>/Delay Input1'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_a) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0U;
  }

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  DataTypeConversion: '<S12>/Data Type Conversion2'
   *  Delay: '<S12>/Delay'
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S12>/Logical Operator'
   *  Logic: '<S12>/Logical Operator1'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S18>/Compare'
   *  RelationalOperator: '<S19>/FixPt Relational Operator'
   *  Switch: '<S12>/Switch1'
   *  UnitDelay: '<S19>/Delay Input1'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTATE <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_fz) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S12>/Switch1' incorporates:
       *  DataTypeConversion: '<S12>/Data Type Conversion1'
       *  Delay: '<S12>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S12>/Switch' */

  /* Switch: '<S11>/Switch1' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S15>/FixPt Relational Operator'
   *  RelationalOperator: '<S16>/FixPt Relational Operator'
   *  Switch: '<S11>/Switch2'
   *  UnitDelay: '<S15>/Delay Input1'
   *  UnitDelay: '<S16>/Delay Input1'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S11>/Switch2' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion1'
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;
  } else {
    /* Switch: '<S11>/Switch2' incorporates:
     *  Constant: '<S11>/Constant1'
     */
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S11>/Switch1' */

  /* Update for UnitDelay: '<S14>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_a = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  rtb_Gain = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Gain < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_Gain;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S19>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_fz = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S16>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S15>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* End of Outputs for SubSystem: '<Root>/CommandProcess' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S12>/Delay'
   *  Inport: '<Root>/INS_Out'
   */
  if (FMS_DW.is_active_c3_FMS == 0U) {
    FMS_DW.is_active_c3_FMS = 1U;
    switch (FMS_DW.Delay_DSTATE_c) {
     case PilotMode_Stabilize:
      FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      break;

     case PilotMode_Position:
      FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      break;

     case PilotMode_Mission:
      FMS_DW.is_c3_FMS = FMS_IN_Mission;
      break;

     case PilotMode_Offboard:
      FMS_DW.is_c3_FMS = FMS_IN_Offboard;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }
  } else {
    switch (FMS_DW.is_c3_FMS) {
     case FMS_IN_Manual_e:
      FMS_B.target_mode = PilotMode_Manual;
      switch (FMS_DW.Delay_DSTATE_c) {
       case PilotMode_Stabilize:
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
        break;

       case PilotMode_Position:
        FMS_DW.is_c3_FMS = FMS_IN_Position_f;
        break;

       case PilotMode_Mission:
        FMS_DW.is_c3_FMS = FMS_IN_Mission;
        break;

       case PilotMode_Offboard:
        FMS_DW.is_c3_FMS = FMS_IN_Offboard;
        break;

       default:
        FMS_DW.is_c3_FMS = FMS_IN_Other;
        break;
      }
      break;

     case FMS_IN_Mission:
      if (((FMS_U.INS_Out.flag & 8U) != 0U) && ((FMS_U.INS_Out.flag & 32U) != 0U))
      {
        FMS_B.target_mode = PilotMode_Mission;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      }
      break;

     case FMS_IN_Offboard:
      if (((FMS_U.INS_Out.flag & 8U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U))
      {
        FMS_B.target_mode = PilotMode_Offboard;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      }
      break;

     case FMS_IN_Other:
      FMS_B.target_mode = FMS_DW.Delay_DSTATE_c;
      switch (FMS_DW.Delay_DSTATE_c) {
       case PilotMode_Stabilize:
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
        break;

       case PilotMode_Position:
        FMS_DW.is_c3_FMS = FMS_IN_Position_f;
        break;

       case PilotMode_Mission:
        FMS_DW.is_c3_FMS = FMS_IN_Mission;
        break;

       case PilotMode_Offboard:
        FMS_DW.is_c3_FMS = FMS_IN_Offboard;
        break;

       default:
        FMS_DW.is_c3_FMS = FMS_IN_Other;
        break;
      }
      break;

     case FMS_IN_Position_f:
      if (((FMS_U.INS_Out.flag & 8U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U))
      {
        FMS_B.target_mode = PilotMode_Position;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      }
      break;

     default:
      if ((FMS_U.INS_Out.flag & 8U) != 0U) {
        FMS_B.target_mode = PilotMode_Stabilize;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/SafeMode' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_3' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Delay: '<S8>/Delay'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S7>/FixPt Relational Operator'
   *  Switch: '<S8>/Switch'
   *  UnitDelay: '<S7>/Delay Input1'
   *
   * Block description for '<S7>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Auto_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_f) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 0U;
    rtb_Switch_b5 = 1U;
  } else {
    rtb_Switch_b5 = FMS_DW.Delay_DSTATE_m;
  }

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S9>/Upper Limit'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S9>/Upper Test'
   */
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE < 1000U) &&
    (rtb_Switch_b5 != 0) && (FMS_U.Auto_Cmd.frame <= 2));

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  rtb_Compare_m = (FMS_DW.prep_mission == 1.0);
  if ((!rtb_Compare_m) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = rtb_Compare_m;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_c)) {
    FMS_DW.durationLastReferenceTick_1_h = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_c = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
  if (FMS_DW.temporalCounter_i1 < 1023U) {
    FMS_DW.temporalCounter_i1++;
  }

  FMS_DW.sfEvent = -1;
  FMS_DW.mission_timestamp_prev = FMS_DW.mission_timestamp_start;
  FMS_DW.mission_timestamp_start = FMS_U.Mission_Data.timestamp;
  FMS_DW.cmd_prev = FMS_DW.cmd_start;
  FMS_DW.cmd_start = FMS_B.Switch1;
  FMS_DW.mode_prev = FMS_DW.mode_start;
  FMS_DW.mode_start = FMS_B.target_mode;
  FMS_DW.M_isValid = false;
  FMS_c11_FMS();
  FMS_sf_msg_discard_M();

  /* End of Chart: '<Root>/FMS State Machine' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  /* SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_bq[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_bq[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_bq[2] = FMS_B.Cmd_In.sp_waypoint[2];

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

  /* SwitchCase: '<S20>/Switch Case' incorporates:
   *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy6Inport1'
   */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;

  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  switch (FMS_B.state) {
   case VehicleState_Disarm:
   case VehicleState_None:
    FMS_DW.SwitchCase_ActiveSubsystem = 0;
    break;

   case VehicleState_Standby:
    FMS_DW.SwitchCase_ActiveSubsystem = 1;
    break;

   default:
    FMS_DW.SwitchCase_ActiveSubsystem = 2;
    break;
  }

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S22>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S29>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S27>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S26>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
        /* Disable for SwitchCase: '<S36>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
      break;

     case 3:
     case 4:
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S22>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S20>/Disarm' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S23>/Bus Assignment'
     *  BusAssignment: '<S24>/Bus Assignment'
     *  Constant: '<S24>/Constant'
     *  SignalConversion: '<S24>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S24>/Bus Assignment' incorporates:
     *  BusAssignment: '<S23>/Bus Assignment'
     *  Constant: '<S24>/Constant2'
     *  DataTypeConversion: '<S24>/Data Type Conversion2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S24>/Data Type Conversion2' incorporates:
       *  Constant: '<S24>/Constant6'
       */
      rtb_Gain = fmodf(floorf(FMS_PARAM.DISARM_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Gain < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (int32_T)(uint16_T)rtb_Gain);
    }

    /* End of Outputs for SubSystem: '<S20>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S20>/Standby' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S23>/Bus Assignment'
     *  BusAssignment: '<S25>/Bus Assignment'
     *  Constant: '<S25>/Constant'
     *  SignalConversion: '<S25>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S25>/Bus Assignment' incorporates:
     *  BusAssignment: '<S23>/Bus Assignment'
     *  Constant: '<S25>/Constant2'
     *  DataTypeConversion: '<S25>/Data Type Conversion3'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S25>/Data Type Conversion3' incorporates:
       *  Constant: '<S25>/Constant6'
       */
      rtb_Gain = fmodf(floorf(FMS_PARAM.STANDBY_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Gain < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (int32_T)(uint16_T)rtb_Gain);
    }

    /* End of Outputs for SubSystem: '<S20>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S20>/Arm' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    /* SwitchCase: '<S22>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;

    /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
    switch (FMS_B.state) {
     case VehicleState_Land:
     case VehicleState_Return:
     case VehicleState_Takeoff:
     case VehicleState_Hold:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 0;
      break;

     case VehicleState_Offboard:
     case VehicleState_Mission:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 1;
      break;

     case VehicleState_Acro:
     case VehicleState_Stabilize:
     case VehicleState_Altitude:
     case VehicleState_Position:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 2;
      break;

     case VehicleState_Manual:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 3;
      break;

     default:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 4;
      break;
    }

    /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S29>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S27>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S26>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for SwitchCase: '<S36>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 3:
       case 4:
        break;
      }
    }

    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S22>/SubMode' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      /* SwitchCase: '<S29>/Switch Case' incorporates:
       *  Product: '<S163>/Divide'
       *  Sum: '<S151>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Return:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 0;
        break;

       case VehicleState_Hold:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 1;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 2;
        break;
      }

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S29>/Return' incorporates:
           *  ActionPort: '<S146>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S29>/Switch Case' incorporates:
           *  Delay: '<S149>/Delay'
           */
          FMS_DW.icLoad_c = 1U;

          /* End of InitializeConditions for SubSystem: '<S29>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S29>/Return' incorporates:
         *  ActionPort: '<S146>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S160>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S160>/Math Function'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  Sum: '<S158>/Sum of Elements'
         */
        rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S160>/Math Function1' incorporates:
         *  Sum: '<S160>/Sum of Elements'
         *
         * About '<S160>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain < 0.0F) {
          rtb_Saturation_gm = -sqrtf(fabsf(rtb_Gain));
        } else {
          rtb_Saturation_gm = sqrtf(rtb_Gain);
        }

        /* End of Math: '<S160>/Math Function1' */

        /* Switch: '<S160>/Switch' incorporates:
         *  Constant: '<S160>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S160>/Product'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        if (rtb_Saturation_gm > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_2 = rtb_Saturation_gm;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S160>/Switch' */

        /* Product: '<S160>/Divide' */
        rtb_Divide_g[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
        rtb_Divide_g[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Sum: '<S163>/Sum of Elements' incorporates:
         *  Math: '<S163>/Math Function'
         *  SignalConversion: '<S163>/TmpSignal ConversionAtMath FunctionInport1'
         */
        A = rtb_Divide_g[1] * rtb_Divide_g[1] + rtb_Divide_g[0] * rtb_Divide_g[0];

        /* Math: '<S163>/Math Function1' incorporates:
         *  Sum: '<S163>/Sum of Elements'
         *
         * About '<S163>/Math Function1':
         *  Operator: sqrt
         */
        if (A < 0.0F) {
          rtb_Saturation_gm = -sqrtf(fabsf(A));
        } else {
          rtb_Saturation_gm = sqrtf(A);
        }

        /* End of Math: '<S163>/Math Function1' */

        /* Switch: '<S163>/Switch' incorporates:
         *  Constant: '<S163>/Constant'
         *  Product: '<S163>/Product'
         */
        if (rtb_Saturation_gm > 0.0F) {
          rtb_Switch_f_idx_0 = rtb_Divide_g[1];
          rtb_Switch_f_idx_1 = rtb_Divide_g[0];
          rtb_Switch_f_idx_2 = rtb_Saturation_gm;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S163>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S150>/NearbyRefWP' incorporates:
         *  Constant: '<S146>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_bq[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_g, &rtb_AccToRate_c);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Delay: '<S149>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S150>/SearchL1RefWP' incorporates:
         *  Constant: '<S146>/L1'
         *  Delay: '<S149>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S150>/OutRegionRegWP'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        a_tmp = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE[0];
        b_a_tmp = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        A = a_tmp * a_tmp + b_a_tmp * b_a_tmp;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        rtb_Saturation_gm = (a_tmp * (FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R)
                             + b_a_tmp * (FMS_DW.Delay_DSTATE[1] -
          FMS_U.INS_Out.y_R)) * 2.0F;
        D = rtb_Saturation_gm * rtb_Saturation_gm - (((((FMS_U.INS_Out.x_R *
          FMS_U.INS_Out.x_R + FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
          FMS_DW.Delay_DSTATE[0] * FMS_DW.Delay_DSTATE[0]) +
          FMS_DW.Delay_DSTATE[1] * FMS_DW.Delay_DSTATE[1]) - (FMS_U.INS_Out.x_R *
          FMS_DW.Delay_DSTATE[0] + FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE[1]) *
          2.0F) - FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_TmpSignalConversionAtMath_0 = -1.0F;
        rtb_P_f_idx_0 = 0.0F;
        rtb_P_f_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-rtb_Saturation_gm + u1_tmp) / (2.0F * A);
          A = (-rtb_Saturation_gm - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (A >= 0.0F) && (A <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = fmaxf(D, A);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = D;
            guard1 = true;
          } else {
            if ((A >= 0.0F) && (A <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = A;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -rtb_Saturation_gm / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_P_f_idx_0 = a_tmp * rtb_TmpSignalConversionAtMath_0 +
            FMS_DW.Delay_DSTATE[0];
          rtb_P_f_idx_1 = b_a_tmp * rtb_TmpSignalConversionAtMath_0 +
            FMS_DW.Delay_DSTATE[1];
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S150>/OutRegionRegWP' incorporates:
         *  Delay: '<S149>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_gm = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE[1]) *
                             b_a_tmp + (FMS_U.INS_Out.x_R - FMS_DW.Delay_DSTATE
          [0]) * a_tmp) / (a_tmp * a_tmp + b_a_tmp * b_a_tmp);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Compare_m = (rtb_Saturation_gm <= 0.0F);
        u = (rtb_Saturation_gm >= 1.0F);
        if (rtb_Compare_m) {
          A = FMS_DW.Delay_DSTATE[0];
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          A = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        } else {
          A = rtb_Saturation_gm * a_tmp + FMS_DW.Delay_DSTATE[0];
        }

        /* Switch: '<S150>/Switch1' incorporates:
         *  Constant: '<S153>/Constant'
         *  RelationalOperator: '<S153>/Compare'
         */
        if (rtb_AccToRate_c <= 0.0F) {
          /* Switch: '<S150>/Switch' incorporates:
           *  Constant: '<S152>/Constant'
           *  MATLAB Function: '<S150>/SearchL1RefWP'
           *  RelationalOperator: '<S152>/Compare'
           */
          if (rtb_TmpSignalConversionAtMath_0 >= 0.0F) {
            rtb_Divide_g[0] = rtb_P_f_idx_0;
            rtb_Divide_g[1] = rtb_P_f_idx_1;
          } else {
            rtb_Divide_g[0] = A;

            /* MATLAB Function: '<S150>/OutRegionRegWP' incorporates:
             *  Delay: '<S149>/Delay'
             *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_Compare_m) {
              rtb_Divide_g[1] = FMS_DW.Delay_DSTATE[1];
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_Divide_g[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            } else {
              rtb_Divide_g[1] = rtb_Saturation_gm * b_a_tmp +
                FMS_DW.Delay_DSTATE[1];
            }
          }

          /* End of Switch: '<S150>/Switch' */
        }

        /* End of Switch: '<S150>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S151>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_P_f_idx_0 = rtb_Divide_g[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S161>/Math Function' */
        rtb_P_f_idx_1 = rtb_P_f_idx_0 * rtb_P_f_idx_0;
        rtb_Divide_g[0] = rtb_P_f_idx_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S151>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_P_f_idx_0 = rtb_Divide_g[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S161>/Math Function' incorporates:
         *  Math: '<S159>/Square'
         */
        A = rtb_P_f_idx_0 * rtb_P_f_idx_0;

        /* Sum: '<S161>/Sum of Elements' incorporates:
         *  Math: '<S161>/Math Function'
         */
        rtb_Saturation_gm = A + rtb_P_f_idx_1;

        /* Math: '<S161>/Math Function1' incorporates:
         *  Sum: '<S161>/Sum of Elements'
         *
         * About '<S161>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_gm < 0.0F) {
          rtb_Saturation_gm = -sqrtf(fabsf(rtb_Saturation_gm));
        } else {
          rtb_Saturation_gm = sqrtf(rtb_Saturation_gm);
        }

        /* End of Math: '<S161>/Math Function1' */

        /* Switch: '<S161>/Switch' incorporates:
         *  Constant: '<S161>/Constant'
         *  Product: '<S161>/Product'
         */
        if (rtb_Saturation_gm > 0.0F) {
          rtb_Switch_bq[0] = rtb_Divide_g[0];
          rtb_Switch_bq[1] = rtb_P_f_idx_0;
          rtb_Switch_bq[2] = rtb_Saturation_gm;
        } else {
          rtb_Switch_bq[0] = 0.0F;
          rtb_Switch_bq[1] = 0.0F;
          rtb_Switch_bq[2] = 1.0F;
        }

        /* End of Switch: '<S161>/Switch' */

        /* Product: '<S161>/Divide' */
        rtb_P_f_idx_1 = rtb_Switch_bq[0] / rtb_Switch_bq[2];
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_bq[1] / rtb_Switch_bq[2];

        /* Sum: '<S164>/Sum of Elements' incorporates:
         *  Math: '<S164>/Math Function'
         *  SignalConversion: '<S164>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_gm = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_P_f_idx_1 * rtb_P_f_idx_1;

        /* Math: '<S164>/Math Function1' incorporates:
         *  Sum: '<S164>/Sum of Elements'
         *
         * About '<S164>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_gm < 0.0F) {
          rtb_Saturation_gm = -sqrtf(fabsf(rtb_Saturation_gm));
        } else {
          rtb_Saturation_gm = sqrtf(rtb_Saturation_gm);
        }

        /* End of Math: '<S164>/Math Function1' */

        /* Switch: '<S164>/Switch' incorporates:
         *  Constant: '<S164>/Constant'
         *  Product: '<S164>/Product'
         */
        if (rtb_Saturation_gm > 0.0F) {
          rtb_Switch_bq[0] = rtb_TmpSignalConversionAtMath_0;
          rtb_Switch_bq[1] = rtb_P_f_idx_1;
          rtb_Switch_bq[2] = rtb_Saturation_gm;
        } else {
          rtb_Switch_bq[0] = 0.0F;
          rtb_Switch_bq[1] = 0.0F;
          rtb_Switch_bq[2] = 1.0F;
        }

        /* End of Switch: '<S164>/Switch' */

        /* Product: '<S164>/Divide' */
        rtb_P_f_idx_1 = rtb_Switch_bq[0] / rtb_Switch_bq[2];

        /* Math: '<S159>/Square' */
        rtb_MathFunction_k[0] = rtb_Divide_g[0] * rtb_Divide_g[0];
        rtb_Divide_g[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

        /* Product: '<S164>/Divide' incorporates:
         *  Product: '<S163>/Divide'
         */
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_bq[1] / rtb_Switch_bq[2];

        /* Product: '<S163>/Divide' */
        rtb_P_f_idx_0 = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Sqrt: '<S158>/Sqrt' */
        rtb_Saturation_gm = sqrtf(rtb_Gain);

        /* Gain: '<S151>/Gain' incorporates:
         *  Math: '<S151>/Square'
         */
        rtb_Gain = rtb_Saturation_gm * rtb_Saturation_gm * 2.0F;

        /* Sum: '<S162>/Subtract' incorporates:
         *  Product: '<S162>/Multiply'
         *  Product: '<S162>/Multiply1'
         */
        rtb_Saturation_gm = rtb_P_f_idx_1 * rtb_P_f_idx_0 -
          rtb_TmpSignalConversionAtMath_0 * rtb_Divide_g[0];

        /* Signum: '<S157>/Sign1' */
        if (rtb_Saturation_gm < 0.0F) {
          rtb_Saturation_gm = -1.0F;
        } else {
          if (rtb_Saturation_gm > 0.0F) {
            rtb_Saturation_gm = 1.0F;
          }
        }

        /* End of Signum: '<S157>/Sign1' */

        /* Switch: '<S157>/Switch2' incorporates:
         *  Constant: '<S157>/Constant4'
         */
        if (rtb_Saturation_gm == 0.0F) {
          rtb_Saturation_gm = 1.0F;
        }

        /* End of Switch: '<S157>/Switch2' */

        /* DotProduct: '<S157>/Dot Product' */
        rtb_P_f_idx_0 = rtb_Divide_g[0] * rtb_P_f_idx_1 + rtb_P_f_idx_0 *
          rtb_TmpSignalConversionAtMath_0;

        /* Trigonometry: '<S157>/Acos' incorporates:
         *  DotProduct: '<S157>/Dot Product'
         */
        if (rtb_P_f_idx_0 > 1.0F) {
          rtb_P_f_idx_0 = 1.0F;
        } else {
          if (rtb_P_f_idx_0 < -1.0F) {
            rtb_P_f_idx_0 = -1.0F;
          }
        }

        /* Product: '<S157>/Multiply' incorporates:
         *  Trigonometry: '<S157>/Acos'
         */
        rtb_Saturation_gm *= acosf(rtb_P_f_idx_0);

        /* Saturate: '<S151>/Saturation' */
        if (rtb_Saturation_gm > 1.57079637F) {
          rtb_Saturation_gm = 1.57079637F;
        } else {
          if (rtb_Saturation_gm < -1.57079637F) {
            rtb_Saturation_gm = -1.57079637F;
          }
        }

        /* End of Saturate: '<S151>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S146>/Bus Assignment1'
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S146>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S146>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S146>/L1'
         *  Constant: '<S146>/vel'
         *  Constant: '<S151>/Constant'
         *  Gain: '<S148>/AccToRate'
         *  MinMax: '<S151>/Max'
         *  MinMax: '<S151>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S151>/Divide'
         *  Product: '<S151>/Multiply1'
         *  Sqrt: '<S159>/Sqrt'
         *  Sum: '<S159>/Sum of Elements'
         *  Trigonometry: '<S151>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m0;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        FMS_Y.FMS_Out.r_cmd = arm_sin_f32(rtb_Saturation_gm) * rtb_Gain / fminf
          (FMS_PARAM.L1, fmaxf(sqrtf(A + rtb_MathFunction_k[0]), 0.5F)) *
          FMS_PARAM.ACC2RATE;

        /* Update for Delay: '<S149>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* End of Outputs for SubSystem: '<S29>/Return' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S29>/Hold' incorporates:
         *  ActionPort: '<S145>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S145>/Bus Assignment'
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S145>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S145>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S145>/Constant3'
         *  Constant: '<S145>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_h;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_k;
        FMS_Y.FMS_Out.u_cmd = 0.0F;
        FMS_Y.FMS_Out.r_cmd = 0.0F;

        /* End of Outputs for SubSystem: '<S29>/Hold' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S29>/Unknown' incorporates:
         *  ActionPort: '<S147>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S29>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S29>/Switch Case' */
      /* End of Outputs for SubSystem: '<S22>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S22>/Auto' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      /* SwitchCase: '<S27>/Switch Case' incorporates:
       *  RelationalOperator: '<S66>/FixPt Relational Operator'
       *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy5Inport1'
       *  UnitDelay: '<S66>/Delay Input1'
       *
       * Block description for '<S66>/Delay Input1':
       *
       *  Store in Global RAM
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Offboard:
        FMS_DW.SwitchCase_ActiveSubsystem_i = 0;
        break;

       case VehicleState_Mission:
        FMS_DW.SwitchCase_ActiveSubsystem_i = 1;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_i = 2;
        break;
      }

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S27>/Offboard' incorporates:
         *  ActionPort: '<S64>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S128>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_Multiply_c_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S131>/deg2rad' */
        rtb_Switch1_l = 0.017453292519943295 * rtb_Multiply_c_idx_0;

        /* Trigonometry: '<S132>/Sin' */
        rtb_Gain_b = sin(rtb_Switch1_l);

        /* Math: '<S132>/Square1' */
        rtb_Gain_b *= rtb_Gain_b;

        /* Product: '<S132>/Multiply1' incorporates:
         *  Product: '<S132>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff_j * rtb_Gain_b;

        /* Product: '<S132>/Divide' incorporates:
         *  Constant: '<S132>/Constant'
         *  Constant: '<S132>/R'
         *  Sqrt: '<S132>/Sqrt'
         *  Sum: '<S132>/Sum1'
         */
        rtb_Gain_b = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S132>/Product3' incorporates:
         *  Constant: '<S132>/Constant1'
         *  Product: '<S132>/Multiply1'
         *  Sum: '<S132>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4_m * rtb_Gain_b;

        /* Product: '<S132>/Multiply2' incorporates:
         *  Trigonometry: '<S132>/Cos'
         */
        rtb_Gain_b *= cos(rtb_Switch1_l);

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S131>/Sum' incorporates:
         *  Gain: '<S128>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S21>/Signal Copy'
         */
        rtb_Multiply_c_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_c_idx_0;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Abs: '<S136>/Abs' incorporates:
         *  Abs: '<S139>/Abs1'
         *  Switch: '<S136>/Switch1'
         */
        rtb_Switch1_l = fabs(rtb_Multiply_c_idx_0);

        /* Switch: '<S136>/Switch1' incorporates:
         *  Abs: '<S136>/Abs'
         *  Bias: '<S136>/Bias2'
         *  Bias: '<S136>/Bias3'
         *  Constant: '<S133>/Constant'
         *  Constant: '<S133>/Constant1'
         *  Constant: '<S138>/Constant'
         *  Gain: '<S136>/Gain1'
         *  Product: '<S136>/Multiply'
         *  RelationalOperator: '<S138>/Compare'
         *  Switch: '<S133>/Switch'
         */
        if (rtb_Switch1_l > 90.0) {
          /* Switch: '<S139>/Switch1' incorporates:
           *  Bias: '<S139>/Bias2'
           *  Bias: '<S139>/Bias3'
           *  Constant: '<S139>/Constant'
           *  Constant: '<S140>/Constant'
           *  Math: '<S139>/Math Function'
           *  RelationalOperator: '<S140>/Compare'
           */
          if (rtb_Switch1_l > 180.0) {
            rtb_Multiply_c_idx_0 = rt_modd(rtb_Multiply_c_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S139>/Switch1' */

          /* Signum: '<S136>/Sign' */
          if (rtb_Multiply_c_idx_0 < 0.0) {
            rtb_Multiply_c_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_c_idx_0 > 0.0) {
              rtb_Multiply_c_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S136>/Sign' */
          rtb_Multiply_c_idx_0 *= -(rtb_Switch1_l + -90.0) + 90.0;
          i = 180;
        } else {
          i = 0;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S133>/Sum' incorporates:
         *  Gain: '<S128>/Gain1'
         *  Gain: '<S128>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  Sum: '<S131>/Sum'
         */
        rtb_Switch1_l = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)i;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S131>/Multiply' incorporates:
         *  Gain: '<S131>/deg2rad1'
         */
        rtb_Multiply_c_idx_0 = 0.017453292519943295 * rtb_Multiply_c_idx_0 *
          rtb_Sum3;

        /* Switch: '<S135>/Switch1' incorporates:
         *  Abs: '<S135>/Abs1'
         *  Bias: '<S135>/Bias2'
         *  Bias: '<S135>/Bias3'
         *  Constant: '<S135>/Constant'
         *  Constant: '<S137>/Constant'
         *  Math: '<S135>/Math Function'
         *  RelationalOperator: '<S137>/Compare'
         */
        if (fabs(rtb_Switch1_l) > 180.0) {
          rtb_Switch1_l = rt_modd(rtb_Switch1_l + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S135>/Switch1' */

        /* Product: '<S131>/Multiply' incorporates:
         *  Gain: '<S131>/deg2rad1'
         */
        rtb_Gain_b *= 0.017453292519943295 * rtb_Switch1_l;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MultiPortSwitch: '<S113>/Index Vector' incorporates:
         *  Constant: '<S121>/Constant'
         *  Constant: '<S122>/Constant'
         *  Constant: '<S130>/Constant'
         *  DataStoreRead: '<S114>/Data Store Read'
         *  DataStoreRead: '<S117>/Data Store Read'
         *  DataTypeConversion: '<S128>/Data Type Conversion1'
         *  Inport: '<Root>/Auto_Cmd'
         *  Logic: '<S115>/Logical Operator'
         *  Math: '<S114>/Transpose'
         *  Math: '<S117>/Transpose'
         *  Product: '<S114>/Multiply1'
         *  Product: '<S116>/Multiply'
         *  Product: '<S117>/Multiply3'
         *  Product: '<S134>/Multiply1'
         *  Product: '<S134>/Multiply2'
         *  Product: '<S134>/Multiply3'
         *  Product: '<S134>/Multiply4'
         *  RelationalOperator: '<S121>/Compare'
         *  RelationalOperator: '<S122>/Compare'
         *  RelationalOperator: '<S130>/Compare'
         *  S-Function (sfix_bitop): '<S115>/lat_cmd valid'
         *  S-Function (sfix_bitop): '<S115>/lon_cmd valid'
         *  S-Function (sfix_bitop): '<S115>/x_cmd valid'
         *  S-Function (sfix_bitop): '<S115>/y_cmd valid'
         *  S-Function (sfix_bitop): '<S127>/lat_cmd valid'
         *  S-Function (sfix_bitop): '<S127>/lon_cmd valid'
         *  SignalConversion: '<S21>/Signal Copy'
         *  Sum: '<S114>/Sum'
         *  Sum: '<S117>/Sum'
         *  Sum: '<S134>/Sum2'
         *  Sum: '<S134>/Sum3'
         *  Switch: '<S118>/Switch'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          rtb_Switch_bq[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? (FMS_U.Auto_Cmd.cmd_mask
            & 1024U) > 0U ? (real32_T)(rtb_Multiply_c_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain_b * FMS_ConstB.SinCos_o1) :
            FMS_U.Auto_Cmd.x_cmd : 0.0F;
          rtb_Switch_bq[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? (FMS_U.Auto_Cmd.cmd_mask
            & 2048U) > 0U ? (real32_T)(rtb_Gain_b * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_c_idx_0 * FMS_ConstB.SinCos_o1) : FMS_U.Auto_Cmd.y_cmd :
            0.0F;
          break;

         case 1:
          /* SignalConversion: '<S126>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S126>/Constant4'
           */
          rtb_VectorConcatenate_e[5] = 0.0F;

          /* Trigonometry: '<S126>/Trigonometric Function3' incorporates:
           *  DataStoreRead: '<S117>/Data Store Read'
           *  Gain: '<S125>/Gain'
           *  Trigonometry: '<S126>/Trigonometric Function1'
           */
          rtb_Gain = arm_cos_f32(-FMS_DW.home[3]);
          rtb_VectorConcatenate_e[4] = rtb_Gain;

          /* Trigonometry: '<S126>/Trigonometric Function2' incorporates:
           *  DataStoreRead: '<S117>/Data Store Read'
           *  Gain: '<S125>/Gain'
           *  Trigonometry: '<S126>/Trigonometric Function'
           */
          rtb_Switch_f_idx_1 = arm_sin_f32(-FMS_DW.home[3]);

          /* Gain: '<S126>/Gain' incorporates:
           *  Trigonometry: '<S126>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_e[3] = -rtb_Switch_f_idx_1;

          /* SignalConversion: '<S126>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S126>/Constant3'
           */
          rtb_VectorConcatenate_e[2] = 0.0F;

          /* Trigonometry: '<S126>/Trigonometric Function' */
          rtb_VectorConcatenate_e[1] = rtb_Switch_f_idx_1;

          /* Trigonometry: '<S126>/Trigonometric Function1' */
          rtb_VectorConcatenate_e[0] = rtb_Gain;

          /* SignalConversion: '<S126>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[6] = FMS_ConstB.VectorConcatenate3_b[0];

          /* Product: '<S117>/Multiply' incorporates:
           *  Constant: '<S121>/Constant'
           *  Constant: '<S122>/Constant'
           *  Constant: '<S130>/Constant'
           *  DataTypeConversion: '<S128>/Data Type Conversion1'
           *  Logic: '<S115>/Logical Operator'
           *  Product: '<S134>/Multiply1'
           *  Product: '<S134>/Multiply2'
           *  RelationalOperator: '<S121>/Compare'
           *  RelationalOperator: '<S122>/Compare'
           *  RelationalOperator: '<S130>/Compare'
           *  S-Function (sfix_bitop): '<S115>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S115>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S127>/lat_cmd valid'
           *  Sum: '<S134>/Sum2'
           *  Switch: '<S118>/Switch'
           */
          rtb_Gain = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? (FMS_U.Auto_Cmd.cmd_mask
            & 1024U) > 0U ? (real32_T)(rtb_Multiply_c_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain_b * FMS_ConstB.SinCos_o1) :
            FMS_U.Auto_Cmd.x_cmd : 0.0F;

          /* SignalConversion: '<S126>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[7] = FMS_ConstB.VectorConcatenate3_b[1];

          /* Product: '<S117>/Multiply' incorporates:
           *  Constant: '<S121>/Constant'
           *  Constant: '<S122>/Constant'
           *  Constant: '<S130>/Constant'
           *  DataTypeConversion: '<S128>/Data Type Conversion1'
           *  Logic: '<S115>/Logical Operator'
           *  Product: '<S134>/Multiply3'
           *  Product: '<S134>/Multiply4'
           *  RelationalOperator: '<S121>/Compare'
           *  RelationalOperator: '<S122>/Compare'
           *  RelationalOperator: '<S130>/Compare'
           *  S-Function (sfix_bitop): '<S115>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S115>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S127>/lon_cmd valid'
           *  Sum: '<S134>/Sum3'
           *  Switch: '<S118>/Switch'
           */
          rtb_Switch_f_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? (FMS_U.Auto_Cmd.cmd_mask
            & 2048U) > 0U ? (real32_T)(rtb_Gain_b * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_c_idx_0 * FMS_ConstB.SinCos_o1) : FMS_U.Auto_Cmd.y_cmd :
            0.0F;

          /* SignalConversion: '<S126>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[8] = FMS_ConstB.VectorConcatenate3_b[2];

          /* Product: '<S117>/Multiply' incorporates:
           *  Constant: '<S121>/Constant'
           *  Constant: '<S122>/Constant'
           *  Constant: '<S130>/Constant'
           *  DataTypeConversion: '<S128>/Data Type Conversion'
           *  DataTypeConversion: '<S128>/Data Type Conversion1'
           *  Gain: '<S128>/Gain2'
           *  Gain: '<S131>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S115>/Logical Operator'
           *  RelationalOperator: '<S121>/Compare'
           *  RelationalOperator: '<S122>/Compare'
           *  RelationalOperator: '<S130>/Compare'
           *  S-Function (sfix_bitop): '<S115>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S115>/z_cmd valid'
           *  S-Function (sfix_bitop): '<S127>/alt_cmd valid'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Sum: '<S131>/Sum1'
           *  Switch: '<S118>/Switch'
           */
          rtb_Switch_f_idx_2 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? (FMS_U.Auto_Cmd.cmd_mask
            & 4096U) > 0U ? (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0) : FMS_U.Auto_Cmd.z_cmd : 0.0F;
          for (i = 0; i < 3; i++) {
            rtb_Switch_bq[i] = ((rtb_VectorConcatenate_e[3 * i + 1] *
                                 rtb_Switch_f_idx_1 + rtb_VectorConcatenate_e[3 *
                                 i] * rtb_Gain) + rtb_VectorConcatenate_e[3 * i
                                + 2] * rtb_Switch_f_idx_2) + FMS_DW.home[i];
          }
          break;

         default:
          /* SignalConversion: '<S120>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S120>/Constant4'
           */
          rtb_VectorConcatenate_e[5] = 0.0F;

          /* Trigonometry: '<S120>/Trigonometric Function3' incorporates:
           *  Gain: '<S119>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Trigonometry: '<S120>/Trigonometric Function1'
           */
          rtb_Gain = arm_cos_f32(-FMS_U.INS_Out.psi);
          rtb_VectorConcatenate_e[4] = rtb_Gain;

          /* Trigonometry: '<S120>/Trigonometric Function2' incorporates:
           *  Gain: '<S119>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Trigonometry: '<S120>/Trigonometric Function'
           */
          rtb_Switch_f_idx_1 = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S120>/Gain' incorporates:
           *  Trigonometry: '<S120>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_e[3] = -rtb_Switch_f_idx_1;

          /* SignalConversion: '<S120>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S120>/Constant3'
           */
          rtb_VectorConcatenate_e[2] = 0.0F;

          /* Trigonometry: '<S120>/Trigonometric Function' */
          rtb_VectorConcatenate_e[1] = rtb_Switch_f_idx_1;

          /* Trigonometry: '<S120>/Trigonometric Function1' */
          rtb_VectorConcatenate_e[0] = rtb_Gain;

          /* SignalConversion: '<S120>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[6] = FMS_ConstB.VectorConcatenate3[0];

          /* Product: '<S114>/Multiply' incorporates:
           *  Constant: '<S121>/Constant'
           *  Constant: '<S122>/Constant'
           *  Constant: '<S130>/Constant'
           *  DataTypeConversion: '<S128>/Data Type Conversion1'
           *  Logic: '<S115>/Logical Operator'
           *  Product: '<S134>/Multiply1'
           *  Product: '<S134>/Multiply2'
           *  RelationalOperator: '<S121>/Compare'
           *  RelationalOperator: '<S122>/Compare'
           *  RelationalOperator: '<S130>/Compare'
           *  S-Function (sfix_bitop): '<S115>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S115>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S127>/lat_cmd valid'
           *  Sum: '<S134>/Sum2'
           *  Switch: '<S118>/Switch'
           */
          rtb_Gain = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? (FMS_U.Auto_Cmd.cmd_mask
            & 1024U) > 0U ? (real32_T)(rtb_Multiply_c_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain_b * FMS_ConstB.SinCos_o1) :
            FMS_U.Auto_Cmd.x_cmd : 0.0F;

          /* SignalConversion: '<S120>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[7] = FMS_ConstB.VectorConcatenate3[1];

          /* Product: '<S114>/Multiply' incorporates:
           *  Constant: '<S121>/Constant'
           *  Constant: '<S122>/Constant'
           *  Constant: '<S130>/Constant'
           *  DataTypeConversion: '<S128>/Data Type Conversion1'
           *  Logic: '<S115>/Logical Operator'
           *  Product: '<S134>/Multiply3'
           *  Product: '<S134>/Multiply4'
           *  RelationalOperator: '<S121>/Compare'
           *  RelationalOperator: '<S122>/Compare'
           *  RelationalOperator: '<S130>/Compare'
           *  S-Function (sfix_bitop): '<S115>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S115>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S127>/lon_cmd valid'
           *  Sum: '<S134>/Sum3'
           *  Switch: '<S118>/Switch'
           */
          rtb_Switch_f_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? (FMS_U.Auto_Cmd.cmd_mask
            & 2048U) > 0U ? (real32_T)(rtb_Gain_b * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_c_idx_0 * FMS_ConstB.SinCos_o1) : FMS_U.Auto_Cmd.y_cmd :
            0.0F;

          /* SignalConversion: '<S120>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Product: '<S114>/Multiply' incorporates:
           *  Constant: '<S121>/Constant'
           *  Constant: '<S122>/Constant'
           *  Constant: '<S130>/Constant'
           *  DataTypeConversion: '<S128>/Data Type Conversion'
           *  DataTypeConversion: '<S128>/Data Type Conversion1'
           *  Gain: '<S128>/Gain2'
           *  Gain: '<S131>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S115>/Logical Operator'
           *  RelationalOperator: '<S121>/Compare'
           *  RelationalOperator: '<S122>/Compare'
           *  RelationalOperator: '<S130>/Compare'
           *  S-Function (sfix_bitop): '<S115>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S115>/z_cmd valid'
           *  S-Function (sfix_bitop): '<S127>/alt_cmd valid'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Sum: '<S131>/Sum1'
           *  Switch: '<S118>/Switch'
           */
          rtb_Switch_f_idx_2 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? (FMS_U.Auto_Cmd.cmd_mask
            & 4096U) > 0U ? (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0) : FMS_U.Auto_Cmd.z_cmd : 0.0F;
          for (i = 0; i < 3; i++) {
            rtb_Switch_bq[i] = ((rtb_VectorConcatenate_e[3 * i + 1] *
                                 rtb_Switch_f_idx_1 + rtb_VectorConcatenate_e[3 *
                                 i] * rtb_Gain) + rtb_VectorConcatenate_e[3 * i
                                + 2] * rtb_Switch_f_idx_2) + FMS_DW.home[i];
          }
          break;
        }

        /* End of MultiPortSwitch: '<S113>/Index Vector' */

        /* MATLAB Function: '<S98>/NearbyRefWP' incorporates:
         *  Constant: '<S86>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S98>/OutRegionRegWP'
         *  MATLAB Function: '<S98>/SearchL1RefWP'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_Switch_f_idx_2 = rtb_Switch_bq[0] - FMS_U.INS_Out.x_R;
        rtb_Gain = rtb_Switch_bq[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Switch_f_idx_1 = sqrtf(rtb_Switch_f_idx_2 * rtb_Switch_f_idx_2 +
          rtb_Gain * rtb_Gain);
        if (rtb_Switch_f_idx_1 <= FMS_PARAM.L1) {
          rtb_MathFunction_k[0] = rtb_Switch_bq[0];
          rtb_MathFunction_k[1] = rtb_Switch_bq[1];
        } else {
          rtb_Switch_f_idx_1 = -1.0F;
          rtb_MathFunction_k[0] = 0.0F;
          rtb_MathFunction_k[1] = 0.0F;
        }

        /* End of MATLAB Function: '<S98>/NearbyRefWP' */

        /* MATLAB Function: '<S98>/SearchL1RefWP' incorporates:
         *  Constant: '<S86>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        A = rtb_Switch_f_idx_2 * rtb_Switch_f_idx_2 + rtb_Gain * rtb_Gain;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        D = 0.0F - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                        FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                       FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R) +
                      FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) -
                     (FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R + FMS_U.INS_Out.y_R *
                      FMS_U.INS_Out.y_R) * 2.0F) - FMS_PARAM.L1 * FMS_PARAM.L1) *
          (4.0F * A);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_TmpSignalConversionAtMath_0 = -1.0F;
        rtb_P_f_idx_0 = 0.0F;
        rtb_P_f_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = u1_tmp / (2.0F * A);
          A = (-0.0F - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (A >= 0.0F) && (A <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = fmaxf(D, A);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = D;
            guard1 = true;
          } else {
            if ((A >= 0.0F) && (A <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = A;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -0.0F / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_P_f_idx_0 = rtb_Switch_f_idx_2 * rtb_TmpSignalConversionAtMath_0 +
            FMS_U.INS_Out.x_R;
          rtb_P_f_idx_1 = rtb_Gain * rtb_TmpSignalConversionAtMath_0 +
            FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* MATLAB Function: '<S98>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S103>/TmpSignal ConversionAt SFunction Inport1'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_Saturation_gm = 0.0F / (rtb_Switch_f_idx_2 * rtb_Switch_f_idx_2 +
          rtb_Gain * rtb_Gain);
        rtb_Compare_m = (rtb_Saturation_gm >= 1.0F);
        if (rtb_Saturation_gm <= 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          A = FMS_U.INS_Out.x_R;
          rtb_Switch_f_idx_0 = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        } else if (rtb_Compare_m) {
          A = rtb_Switch_bq[0];
          rtb_Switch_f_idx_0 = rtb_Switch_bq[1];
        } else {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          A = rtb_Saturation_gm * rtb_Switch_f_idx_2 + FMS_U.INS_Out.x_R;
          rtb_Switch_f_idx_0 = rtb_Saturation_gm * rtb_Gain + FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S93>/Switch' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  S-Function (sfix_bitop): '<S93>/psi_cmd_valid'
         *  S-Function (sfix_bitop): '<S93>/r_cmd_valid'
         *  SignalConversion: '<S21>/Signal Copy'
         *  Switch: '<S93>/Switch1'
         */
        if ((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) {
          rtb_Gain = FMS_U.Auto_Cmd.r_cmd;
        } else if ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U) {
          /* Sum: '<S92>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Switch: '<S93>/Switch1'
           */
          rtb_Gain = FMS_U.Auto_Cmd.psi_cmd - FMS_U.INS_Out.psi;

          /* Abs: '<S96>/Abs' incorporates:
           *  Switch: '<S93>/Switch1'
           */
          rtb_Switch_f_idx_1 = fabsf(rtb_Gain);

          /* Switch: '<S96>/Switch' incorporates:
           *  Constant: '<S96>/Constant'
           *  Constant: '<S97>/Constant'
           *  Product: '<S96>/Multiply'
           *  RelationalOperator: '<S97>/Compare'
           *  Sum: '<S96>/Subtract'
           *  Switch: '<S93>/Switch1'
           */
          if (rtb_Switch_f_idx_1 > 3.14159274F) {
            /* Signum: '<S96>/Sign' */
            if (rtb_Gain < 0.0F) {
              rtb_Gain = -1.0F;
            } else {
              if (rtb_Gain > 0.0F) {
                rtb_Gain = 1.0F;
              }
            }

            /* End of Signum: '<S96>/Sign' */
            rtb_Gain *= rtb_Switch_f_idx_1 - 6.28318548F;
          }

          /* End of Switch: '<S96>/Switch' */

          /* Switch: '<S93>/Switch1' incorporates:
           *  Gain: '<S92>/Gain2'
           */
          rtb_Gain *= FMS_PARAM.YAW_P;
        } else {
          /* Sum: '<S108>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S108>/Math Function'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Switch: '<S93>/Switch1'
           */
          rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
            FMS_U.INS_Out.ve;

          /* Math: '<S108>/Math Function1' incorporates:
           *  Sum: '<S108>/Sum of Elements'
           *  Switch: '<S93>/Switch1'
           *
           * About '<S108>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            rtb_Switch_f_idx_2 = -sqrtf(fabsf(rtb_Gain));
          } else {
            rtb_Switch_f_idx_2 = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S108>/Math Function1' */

          /* Switch: '<S108>/Switch' incorporates:
           *  Constant: '<S108>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S108>/Product'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Switch: '<S93>/Switch1'
           */
          if (rtb_Switch_f_idx_2 > 0.0F) {
            rtb_Switch_bq[0] = FMS_U.INS_Out.vn;
            rtb_Switch_bq[1] = FMS_U.INS_Out.ve;
            rtb_Switch_bq[2] = rtb_Switch_f_idx_2;
          } else {
            rtb_Switch_bq[0] = 0.0F;
            rtb_Switch_bq[1] = 0.0F;
            rtb_Switch_bq[2] = 1.0F;
          }

          /* End of Switch: '<S108>/Switch' */

          /* Product: '<S108>/Divide' incorporates:
           *  Switch: '<S93>/Switch1'
           */
          rtb_Saturation_gm = rtb_Switch_bq[0] / rtb_Switch_bq[2];
          D = rtb_Switch_bq[1] / rtb_Switch_bq[2];

          /* Switch: '<S98>/Switch1' incorporates:
           *  Constant: '<S101>/Constant'
           *  RelationalOperator: '<S101>/Compare'
           *  Switch: '<S93>/Switch1'
           */
          if (rtb_Switch_f_idx_1 <= 0.0F) {
            /* Switch: '<S98>/Switch' incorporates:
             *  Constant: '<S100>/Constant'
             *  MATLAB Function: '<S98>/SearchL1RefWP'
             *  RelationalOperator: '<S100>/Compare'
             */
            if (rtb_TmpSignalConversionAtMath_0 >= 0.0F) {
              rtb_MathFunction_k[0] = rtb_P_f_idx_0;
              rtb_MathFunction_k[1] = rtb_P_f_idx_1;
            } else {
              rtb_MathFunction_k[0] = A;
              rtb_MathFunction_k[1] = rtb_Switch_f_idx_0;
            }

            /* End of Switch: '<S98>/Switch' */
          }

          /* End of Switch: '<S98>/Switch1' */

          /* Sum: '<S99>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Switch: '<S93>/Switch1'
           */
          rtb_P_f_idx_0 = rtb_MathFunction_k[0] - FMS_U.INS_Out.x_R;
          rtb_P_f_idx_1 = rtb_MathFunction_k[1] - FMS_U.INS_Out.y_R;

          /* Math: '<S109>/Math Function' incorporates:
           *  Math: '<S107>/Square'
           *  Switch: '<S93>/Switch1'
           */
          rtb_Switch_f_idx_1 = rtb_P_f_idx_0 * rtb_P_f_idx_0;
          rtb_Gain = rtb_P_f_idx_1 * rtb_P_f_idx_1;

          /* Sum: '<S109>/Sum of Elements' incorporates:
           *  Math: '<S109>/Math Function'
           *  Switch: '<S93>/Switch1'
           */
          A = rtb_Switch_f_idx_1 + rtb_Gain;

          /* Math: '<S109>/Math Function1' incorporates:
           *  Sum: '<S109>/Sum of Elements'
           *  Switch: '<S93>/Switch1'
           *
           * About '<S109>/Math Function1':
           *  Operator: sqrt
           */
          if (A < 0.0F) {
            rtb_Switch_f_idx_2 = -sqrtf(fabsf(A));
          } else {
            rtb_Switch_f_idx_2 = sqrtf(A);
          }

          /* End of Math: '<S109>/Math Function1' */

          /* Switch: '<S109>/Switch' incorporates:
           *  Constant: '<S109>/Constant'
           *  Product: '<S109>/Product'
           *  Switch: '<S93>/Switch1'
           */
          if (rtb_Switch_f_idx_2 > 0.0F) {
            rtb_Switch_bq[0] = rtb_P_f_idx_0;
            rtb_Switch_bq[1] = rtb_P_f_idx_1;
            rtb_Switch_bq[2] = rtb_Switch_f_idx_2;
          } else {
            rtb_Switch_bq[0] = 0.0F;
            rtb_Switch_bq[1] = 0.0F;
            rtb_Switch_bq[2] = 1.0F;
          }

          /* End of Switch: '<S109>/Switch' */

          /* Product: '<S109>/Divide' incorporates:
           *  Switch: '<S93>/Switch1'
           */
          rtb_MathFunction_k[0] = rtb_Switch_bq[0] / rtb_Switch_bq[2];
          rtb_MathFunction_k[1] = rtb_Switch_bq[1] / rtb_Switch_bq[2];

          /* Sum: '<S111>/Sum of Elements' incorporates:
           *  Math: '<S111>/Math Function'
           *  SignalConversion: '<S111>/TmpSignal ConversionAtMath FunctionInport1'
           *  Switch: '<S93>/Switch1'
           */
          A = D * D + rtb_Saturation_gm * rtb_Saturation_gm;

          /* Math: '<S111>/Math Function1' incorporates:
           *  Sum: '<S111>/Sum of Elements'
           *  Switch: '<S93>/Switch1'
           *
           * About '<S111>/Math Function1':
           *  Operator: sqrt
           */
          if (A < 0.0F) {
            A = -sqrtf(fabsf(A));
          } else {
            A = sqrtf(A);
          }

          /* End of Math: '<S111>/Math Function1' */

          /* Switch: '<S111>/Switch' incorporates:
           *  Constant: '<S111>/Constant'
           *  Product: '<S111>/Product'
           *  Switch: '<S93>/Switch1'
           */
          if (A > 0.0F) {
            rtb_Switch_bq[0] = D;
            rtb_Switch_bq[1] = rtb_Saturation_gm;
            rtb_Switch_bq[2] = A;
          } else {
            rtb_Switch_bq[0] = 0.0F;
            rtb_Switch_bq[1] = 0.0F;
            rtb_Switch_bq[2] = 1.0F;
          }

          /* End of Switch: '<S111>/Switch' */

          /* Product: '<S111>/Divide' incorporates:
           *  Switch: '<S93>/Switch1'
           */
          rtb_Saturation_gm = rtb_Switch_bq[0] / rtb_Switch_bq[2];
          D = rtb_Switch_bq[1] / rtb_Switch_bq[2];

          /* Sum: '<S112>/Sum of Elements' incorporates:
           *  Math: '<S112>/Math Function'
           *  SignalConversion: '<S112>/TmpSignal ConversionAtMath FunctionInport1'
           *  Switch: '<S93>/Switch1'
           */
          A = rtb_MathFunction_k[1] * rtb_MathFunction_k[1] +
            rtb_MathFunction_k[0] * rtb_MathFunction_k[0];

          /* Math: '<S112>/Math Function1' incorporates:
           *  Sum: '<S112>/Sum of Elements'
           *  Switch: '<S93>/Switch1'
           *
           * About '<S112>/Math Function1':
           *  Operator: sqrt
           */
          if (A < 0.0F) {
            A = -sqrtf(fabsf(A));
          } else {
            A = sqrtf(A);
          }

          /* End of Math: '<S112>/Math Function1' */

          /* Switch: '<S112>/Switch' incorporates:
           *  Constant: '<S112>/Constant'
           *  Product: '<S112>/Product'
           *  Switch: '<S93>/Switch1'
           */
          if (A > 0.0F) {
            rtb_Switch_bq[0] = rtb_MathFunction_k[1];
            rtb_Switch_bq[1] = rtb_MathFunction_k[0];
            rtb_Switch_bq[2] = A;
          } else {
            rtb_Switch_bq[0] = 0.0F;
            rtb_Switch_bq[1] = 0.0F;
            rtb_Switch_bq[2] = 1.0F;
          }

          /* End of Switch: '<S112>/Switch' */

          /* Product: '<S112>/Divide' incorporates:
           *  Switch: '<S93>/Switch1'
           */
          rtb_MathFunction_k[0] = rtb_Switch_bq[0] / rtb_Switch_bq[2];
          rtb_MathFunction_k[1] = rtb_Switch_bq[1] / rtb_Switch_bq[2];

          /* Sum: '<S110>/Subtract' incorporates:
           *  Product: '<S110>/Multiply'
           *  Product: '<S110>/Multiply1'
           *  Switch: '<S93>/Switch1'
           */
          rtb_Switch_f_idx_2 = rtb_MathFunction_k[0] * D - rtb_MathFunction_k[1]
            * rtb_Saturation_gm;

          /* Signum: '<S105>/Sign1' incorporates:
           *  Switch: '<S93>/Switch1'
           */
          if (rtb_Switch_f_idx_2 < 0.0F) {
            rtb_Switch_f_idx_2 = -1.0F;
          } else {
            if (rtb_Switch_f_idx_2 > 0.0F) {
              rtb_Switch_f_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S105>/Sign1' */

          /* Switch: '<S105>/Switch2' incorporates:
           *  Constant: '<S105>/Constant4'
           *  Switch: '<S93>/Switch1'
           */
          if (rtb_Switch_f_idx_2 == 0.0F) {
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S105>/Switch2' */

          /* DotProduct: '<S105>/Dot Product' incorporates:
           *  Switch: '<S93>/Switch1'
           */
          A = rtb_Saturation_gm * rtb_MathFunction_k[0] + D *
            rtb_MathFunction_k[1];

          /* Trigonometry: '<S105>/Acos' incorporates:
           *  DotProduct: '<S105>/Dot Product'
           *  Switch: '<S93>/Switch1'
           */
          if (A > 1.0F) {
            A = 1.0F;
          } else {
            if (A < -1.0F) {
              A = -1.0F;
            }
          }

          /* Product: '<S105>/Multiply' incorporates:
           *  Switch: '<S93>/Switch1'
           *  Trigonometry: '<S105>/Acos'
           */
          rtb_Switch_f_idx_2 *= acosf(A);

          /* Saturate: '<S99>/Saturation' incorporates:
           *  Switch: '<S93>/Switch1'
           */
          if (rtb_Switch_f_idx_2 > 1.57079637F) {
            rtb_Switch_f_idx_2 = 1.57079637F;
          } else {
            if (rtb_Switch_f_idx_2 < -1.57079637F) {
              rtb_Switch_f_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S99>/Saturation' */

          /* Sqrt: '<S106>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S106>/Square'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Sum: '<S106>/Sum of Elements'
           *  Switch: '<S93>/Switch1'
           */
          A = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                    FMS_U.INS_Out.ve);

          /* Switch: '<S93>/Switch1' incorporates:
           *  Constant: '<S86>/L1'
           *  Gain: '<S94>/AccToRate'
           *  Gain: '<S99>/Gain'
           *  Gain: '<S99>/Gain1'
           *  Math: '<S99>/Square'
           *  MinMax: '<S99>/Max'
           *  MinMax: '<S99>/Min'
           *  Product: '<S99>/Divide'
           *  Product: '<S99>/Multiply1'
           *  Sqrt: '<S107>/Sqrt'
           *  Sum: '<S107>/Sum of Elements'
           *  Trigonometry: '<S99>/Sin'
           */
          rtb_Gain = A * A * 2.0F * arm_sin_f32(rtb_Switch_f_idx_2) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Gain + rtb_Switch_f_idx_1), 0.5F *
              FMS_PARAM.L1)) * FMS_PARAM.ACC2RATE;
        }

        /* End of Switch: '<S93>/Switch' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S64>/Bus Assignment'
         *  Constant: '<S64>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S64>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_n;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S87>/Switch' incorporates:
         *  Constant: '<S142>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S142>/Compare'
         *  S-Function (sfix_bitop): '<S141>/u_cmd valid'
         *  SignalConversion: '<S21>/Signal Copy'
         */
        if ((FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U) {
          /* BusAssignment: '<S64>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_U.Auto_Cmd.u_cmd;
        } else {
          /* BusAssignment: '<S64>/Bus Assignment' incorporates:
           *  BusAssignment: '<S23>/Bus Assignment'
           *  Constant: '<S87>/vel'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S87>/Switch' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S64>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S85>/Constant'
         *  MATLAB Function: '<S88>/bit_shift'
         *  MATLAB Function: '<S89>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S85>/Add'
         */
        FMS_Y.FMS_Out.r_cmd = rtb_Gain;

        /* Outputs for Atomic SubSystem: '<S85>/u_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S85>/r_cmd_valid' */
        FMS_Y.FMS_Out.cmd_mask = 68U;

        /* End of Outputs for SubSystem: '<S85>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S85>/u_cmd_valid' */
        /* End of Outputs for SubSystem: '<S27>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S27>/Mission' incorporates:
           *  ActionPort: '<S63>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S27>/Switch Case' incorporates:
           *  UnitDelay: '<S66>/Delay Input1'
           *
           * Block description for '<S66>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S27>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S27>/Mission' incorporates:
         *  ActionPort: '<S63>/Action Port'
         */
        /* Outputs for Resettable SubSystem: '<S63>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S67>/Reset'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = (ZCSigState)(FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* Sum: '<S80>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S80>/Math Function'
         *  RelationalOperator: '<S66>/FixPt Relational Operator'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S66>/Delay Input1'
         *
         * Block description for '<S66>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S80>/Math Function1' incorporates:
         *  Sum: '<S80>/Sum of Elements'
         *
         * About '<S80>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain < 0.0F) {
          A = -sqrtf(fabsf(rtb_Gain));
        } else {
          A = sqrtf(rtb_Gain);
        }

        /* End of Math: '<S80>/Math Function1' */

        /* Switch: '<S80>/Switch' incorporates:
         *  Constant: '<S80>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S80>/Product'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        if (A > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_Switch_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_2 = A;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S80>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S70>/NearbyRefWP' incorporates:
         *  Constant: '<S67>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_bq[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_MathFunction_k, &rtb_Gain);

        /* MATLAB Function: '<S70>/SearchL1RefWP' incorporates:
         *  Constant: '<S67>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S70>/OutRegionRegWP'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        a_tmp = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        b_a_tmp = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        A = a_tmp * a_tmp + b_a_tmp * b_a_tmp;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        rtb_Saturation_gm = (a_tmp * (FMS_B.Cmd_In.cur_waypoint[0] -
          FMS_U.INS_Out.x_R) + b_a_tmp * (FMS_B.Cmd_In.cur_waypoint[1] -
          FMS_U.INS_Out.y_R)) * 2.0F;
        D = rtb_Saturation_gm * rtb_Saturation_gm - (((((FMS_U.INS_Out.x_R *
          FMS_U.INS_Out.x_R + FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
          FMS_B.Cmd_In.cur_waypoint[0] * FMS_B.Cmd_In.cur_waypoint[0]) +
          FMS_B.Cmd_In.cur_waypoint[1] * FMS_B.Cmd_In.cur_waypoint[1]) -
          (FMS_U.INS_Out.x_R * FMS_B.Cmd_In.cur_waypoint[0] + FMS_U.INS_Out.y_R *
           FMS_B.Cmd_In.cur_waypoint[1]) * 2.0F) - FMS_PARAM.L1 * FMS_PARAM.L1) *
          (4.0F * A);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_TmpSignalConversionAtMath_0 = -1.0F;
        rtb_Divide_g[0] = 0.0F;
        rtb_Divide_g[1] = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-rtb_Saturation_gm + u1_tmp) / (2.0F * A);
          A = (-rtb_Saturation_gm - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (A >= 0.0F) && (A <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = fmaxf(D, A);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_TmpSignalConversionAtMath_0 = D;
            guard1 = true;
          } else {
            if ((A >= 0.0F) && (A <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = A;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -rtb_Saturation_gm / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_TmpSignalConversionAtMath_0 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Divide_g[0] = a_tmp * rtb_TmpSignalConversionAtMath_0 +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_g[1] = b_a_tmp * rtb_TmpSignalConversionAtMath_0 +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S70>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_gm = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
                             b_a_tmp + (FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.cur_waypoint[0]) * a_tmp) / (a_tmp * a_tmp + b_a_tmp *
          b_a_tmp);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Compare_m = (rtb_Saturation_gm <= 0.0F);
        u = (rtb_Saturation_gm >= 1.0F);
        if (rtb_Compare_m) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_P_f_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_P_f_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_P_f_idx_0 = rtb_Saturation_gm * a_tmp + FMS_B.Cmd_In.cur_waypoint
            [0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Switch: '<S70>/Switch1' incorporates:
         *  Constant: '<S73>/Constant'
         *  RelationalOperator: '<S73>/Compare'
         */
        if (rtb_Gain <= 0.0F) {
          /* Switch: '<S70>/Switch' incorporates:
           *  Constant: '<S72>/Constant'
           *  MATLAB Function: '<S70>/SearchL1RefWP'
           *  RelationalOperator: '<S72>/Compare'
           */
          if (rtb_TmpSignalConversionAtMath_0 >= 0.0F) {
            rtb_MathFunction_k[0] = rtb_Divide_g[0];
            rtb_MathFunction_k[1] = rtb_Divide_g[1];
          } else {
            rtb_MathFunction_k[0] = rtb_P_f_idx_0;

            /* MATLAB Function: '<S70>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_Compare_m) {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_MathFunction_k[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_MathFunction_k[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_MathFunction_k[1] = rtb_Saturation_gm * b_a_tmp +
                FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            }
          }

          /* End of Switch: '<S70>/Switch' */
        }

        /* End of Switch: '<S70>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S71>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S21>/Signal Copy1'
         */
        rtb_P_f_idx_1 = rtb_MathFunction_k[0] - FMS_U.INS_Out.x_R;
        rtb_TmpSignalConversionAtMath_0 = rtb_MathFunction_k[1] -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S81>/Math Function' incorporates:
         *  Math: '<S79>/Square'
         */
        rtb_P_f_idx_0 = rtb_P_f_idx_1 * rtb_P_f_idx_1;
        rtb_Gain = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0;

        /* Sum: '<S81>/Sum of Elements' incorporates:
         *  Math: '<S81>/Math Function'
         */
        A = rtb_P_f_idx_0 + rtb_Gain;

        /* Math: '<S81>/Math Function1' incorporates:
         *  Sum: '<S81>/Sum of Elements'
         *
         * About '<S81>/Math Function1':
         *  Operator: sqrt
         */
        if (A < 0.0F) {
          A = -sqrtf(fabsf(A));
        } else {
          A = sqrtf(A);
        }

        /* End of Math: '<S81>/Math Function1' */

        /* Switch: '<S81>/Switch' incorporates:
         *  Constant: '<S81>/Constant'
         *  Product: '<S81>/Product'
         */
        if (A > 0.0F) {
          rtb_Switch_bq[0] = rtb_P_f_idx_1;
          rtb_Switch_bq[1] = rtb_TmpSignalConversionAtMath_0;
          rtb_Switch_bq[2] = A;
        } else {
          rtb_Switch_bq[0] = 0.0F;
          rtb_Switch_bq[1] = 0.0F;
          rtb_Switch_bq[2] = 1.0F;
        }

        /* End of Switch: '<S81>/Switch' */

        /* Product: '<S80>/Divide' */
        rtb_Divide_g[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
        rtb_Divide_g[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Sum: '<S83>/Sum of Elements' incorporates:
         *  Math: '<S83>/Math Function'
         *  SignalConversion: '<S83>/TmpSignal ConversionAtMath FunctionInport1'
         */
        A = rtb_Divide_g[1] * rtb_Divide_g[1] + rtb_Divide_g[0] * rtb_Divide_g[0];

        /* Math: '<S83>/Math Function1' incorporates:
         *  Sum: '<S83>/Sum of Elements'
         *
         * About '<S83>/Math Function1':
         *  Operator: sqrt
         */
        if (A < 0.0F) {
          A = -sqrtf(fabsf(A));
        } else {
          A = sqrtf(A);
        }

        /* End of Math: '<S83>/Math Function1' */

        /* Switch: '<S83>/Switch' incorporates:
         *  Constant: '<S83>/Constant'
         *  Product: '<S83>/Product'
         */
        if (A > 0.0F) {
          rtb_Switch_f_idx_0 = rtb_Divide_g[1];
          rtb_Switch_f_idx_1 = rtb_Divide_g[0];
          rtb_Switch_f_idx_2 = A;
        } else {
          rtb_Switch_f_idx_0 = 0.0F;
          rtb_Switch_f_idx_1 = 0.0F;
          rtb_Switch_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S83>/Switch' */

        /* Product: '<S81>/Divide' */
        rtb_Divide_g[0] = rtb_Switch_bq[0] / rtb_Switch_bq[2];
        rtb_Divide_g[1] = rtb_Switch_bq[1] / rtb_Switch_bq[2];

        /* Sum: '<S84>/Sum of Elements' incorporates:
         *  Math: '<S84>/Math Function'
         *  SignalConversion: '<S84>/TmpSignal ConversionAtMath FunctionInport1'
         */
        A = rtb_Divide_g[1] * rtb_Divide_g[1] + rtb_Divide_g[0] * rtb_Divide_g[0];

        /* Math: '<S84>/Math Function1' incorporates:
         *  Sum: '<S84>/Sum of Elements'
         *
         * About '<S84>/Math Function1':
         *  Operator: sqrt
         */
        if (A < 0.0F) {
          A = -sqrtf(fabsf(A));
        } else {
          A = sqrtf(A);
        }

        /* End of Math: '<S84>/Math Function1' */

        /* Switch: '<S84>/Switch' incorporates:
         *  Constant: '<S84>/Constant'
         *  Product: '<S84>/Product'
         */
        if (A > 0.0F) {
          rtb_Switch_bq[0] = rtb_Divide_g[1];
          rtb_Switch_bq[1] = rtb_Divide_g[0];
          rtb_Switch_bq[2] = A;
        } else {
          rtb_Switch_bq[0] = 0.0F;
          rtb_Switch_bq[1] = 0.0F;
          rtb_Switch_bq[2] = 1.0F;
        }

        /* End of Switch: '<S84>/Switch' */

        /* Product: '<S84>/Divide' */
        rtb_Divide_g[0] = rtb_Switch_bq[0] / rtb_Switch_bq[2];

        /* Product: '<S83>/Divide' */
        rtb_MathFunction_k[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

        /* Product: '<S84>/Divide' */
        rtb_Divide_g[1] = rtb_Switch_bq[1] / rtb_Switch_bq[2];

        /* Product: '<S83>/Divide' */
        rtb_MathFunction_k[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sqrt: '<S78>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S78>/Square'
         *  SignalConversion: '<S21>/Signal Copy1'
         *  Sum: '<S78>/Sum of Elements'
         */
        A = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                  FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S71>/Gain' incorporates:
         *  Math: '<S71>/Square'
         */
        rtb_Switch_f_idx_1 = A * A * 2.0F;

        /* Sum: '<S82>/Subtract' incorporates:
         *  Product: '<S82>/Multiply'
         *  Product: '<S82>/Multiply1'
         */
        A = rtb_Divide_g[0] * rtb_MathFunction_k[1] - rtb_Divide_g[1] *
          rtb_MathFunction_k[0];

        /* Signum: '<S77>/Sign1' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S77>/Sign1' */

        /* Switch: '<S77>/Switch2' incorporates:
         *  Constant: '<S77>/Constant4'
         */
        if (A == 0.0F) {
          A = 1.0F;
        }

        /* End of Switch: '<S77>/Switch2' */

        /* DotProduct: '<S77>/Dot Product' */
        rtb_Switch_f_idx_2 = rtb_MathFunction_k[0] * rtb_Divide_g[0] +
          rtb_MathFunction_k[1] * rtb_Divide_g[1];

        /* Trigonometry: '<S77>/Acos' incorporates:
         *  DotProduct: '<S77>/Dot Product'
         */
        if (rtb_Switch_f_idx_2 > 1.0F) {
          rtb_Switch_f_idx_2 = 1.0F;
        } else {
          if (rtb_Switch_f_idx_2 < -1.0F) {
            rtb_Switch_f_idx_2 = -1.0F;
          }
        }

        /* Product: '<S77>/Multiply' incorporates:
         *  Trigonometry: '<S77>/Acos'
         */
        A *= acosf(rtb_Switch_f_idx_2);

        /* Saturate: '<S71>/Saturation' */
        if (A > 1.57079637F) {
          A = 1.57079637F;
        } else {
          if (A < -1.57079637F) {
            A = -1.57079637F;
          }
        }

        /* End of Saturate: '<S71>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S67>/Bus Assignment'
         *  Constant: '<S67>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S67>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Constant: '<S67>/L1'
         *  Constant: '<S67>/vel'
         *  Constant: '<S71>/Constant'
         *  Gain: '<S68>/AccToRate'
         *  MinMax: '<S71>/Max'
         *  MinMax: '<S71>/Min'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S71>/Divide'
         *  Product: '<S71>/Multiply1'
         *  Sqrt: '<S79>/Sqrt'
         *  Sum: '<S79>/Sum of Elements'
         *  Trigonometry: '<S71>/Sin'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;
        FMS_Y.FMS_Out.r_cmd = arm_sin_f32(A) * rtb_Switch_f_idx_1 / fminf
          (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Gain + rtb_P_f_idx_0), 0.5F)) *
          FMS_PARAM.ACC2RATE;

        /* End of Outputs for SubSystem: '<S63>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Update for UnitDelay: '<S66>/Delay Input1' incorporates:
         *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S66>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S27>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S27>/Unknown' incorporates:
         *  ActionPort: '<S65>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S27>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S27>/Switch Case' */
      /* End of Outputs for SubSystem: '<S22>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S22>/Assist' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      /* SwitchCase: '<S26>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Stabilize:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 0;
        break;

       case VehicleState_Position:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 1;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 2;
        break;
      }

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) && (rtPrevAction
           == 1)) {
        /* Disable for SwitchCase: '<S36>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S26>/Stabilize' incorporates:
         *  ActionPort: '<S32>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S32>/Bus Assignment'
         *  Constant: '<S32>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S32>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S61>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 0.05F) {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -0.05F) {
          rtb_Gain = 0.0F;
        } else {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - -0.05F;
        }

        /* End of DeadZone: '<S61>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S32>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Gain: '<S32>/Gain'
         *  Gain: '<S61>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.05263162F * rtb_Gain * FMS_PARAM.MAX_VEL;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S62>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > 0.05F) {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_roll - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -0.05F) {
          rtb_Gain = 0.0F;
        } else {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_roll - -0.05F;
        }

        /* End of DeadZone: '<S62>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S32>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Gain: '<S32>/Gain1'
         *  Gain: '<S62>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.05263162F * rtb_Gain * FMS_PARAM.MAX_R;

        /* End of Outputs for SubSystem: '<S26>/Stabilize' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S26>/Position' incorporates:
           *  ActionPort: '<S31>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S26>/Switch Case' incorporates:
           *  Chart: '<S37>/Motion State'
           */
          FMS_DW.is_active_c10_FMS = 0U;
          FMS_DW.is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;

          /* End of SystemReset for SubSystem: '<S26>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S26>/Position' incorporates:
         *  ActionPort: '<S31>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S60>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 0.05F) {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - 0.05F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -0.05F) {
          rtb_Gain = 0.0F;
        } else {
          rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle - -0.05F;
        }

        /* End of DeadZone: '<S60>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S35>/Gain' incorporates:
         *  Gain: '<S60>/Gain'
         */
        rtb_P_f_idx_0 = 1.05263162F * rtb_Gain * FMS_PARAM.MAX_VEL;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* RelationalOperator: '<S58>/Compare' incorporates:
         *  Abs: '<S37>/Abs1'
         *  Constant: '<S58>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S21>/Signal Copy2'
         */
        rtb_Compare_m = (fabsf(FMS_U.Pilot_Cmd.stick_roll) > 0.05F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Chart: '<S37>/Motion State' */
        if (FMS_DW.is_active_c10_FMS == 0U) {
          FMS_DW.is_active_c10_FMS = 1U;
          FMS_DW.is_c10_FMS = FMS_IN_Move;
          rtb_state = MotionState_Move;
        } else if (FMS_DW.is_c10_FMS == FMS_IN_Hold) {
          rtb_state = MotionState_Hold;
          if (rtb_Compare_m) {
            FMS_DW.is_c10_FMS = FMS_IN_Move;
            rtb_state = MotionState_Move;
          }
        } else {
          rtb_state = MotionState_Move;
          if (!rtb_Compare_m) {
            FMS_DW.is_c10_FMS = FMS_IN_Hold;
            rtb_state = MotionState_Hold;
          }
        }

        /* End of Chart: '<S37>/Motion State' */

        /* SwitchCase: '<S36>/Switch Case' incorporates:
         *  Math: '<S49>/Square'
         *  Product: '<S42>/Multiply'
         *  Product: '<S56>/Divide'
         *  Sum: '<S41>/Subtract'
         *  Switch: '<S40>/Switch'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_g;
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        switch (rtb_state) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_g = 0;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_g = 1;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_g) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S36>/Hold Control' incorporates:
             *  ActionPort: '<S38>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S36>/Switch Case' incorporates:
             *  Delay: '<S42>/start_vel'
             *  Delay: '<S42>/start_wp'
             *  UnitDelay: '<S55>/Delay Input1'
             *
             * Block description for '<S55>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.icLoad = 1U;
            FMS_DW.DelayInput1_DSTATE = 0.0F;
            FMS_DW.icLoad_f = 1U;

            /* End of InitializeConditions for SubSystem: '<S36>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S36>/Hold Control' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S50>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S50>/Math Function'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          rtb_Gain = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
            FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Math: '<S50>/Math Function1' incorporates:
           *  Sum: '<S50>/Sum of Elements'
           *
           * About '<S50>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            A = -sqrtf(fabsf(rtb_Gain));
          } else {
            A = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S50>/Math Function1' */

          /* Switch: '<S50>/Switch' incorporates:
           *  Constant: '<S50>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S50>/Product'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          if (A > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            rtb_Switch_bq[0] = FMS_U.INS_Out.vn;
            rtb_Switch_bq[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            rtb_Switch_bq[2] = A;
          } else {
            rtb_Switch_bq[0] = 0.0F;
            rtb_Switch_bq[1] = 0.0F;
            rtb_Switch_bq[2] = 1.0F;
          }

          /* End of Switch: '<S50>/Switch' */

          /* Switch: '<S57>/Switch' incorporates:
           *  Constant: '<S57>/Constant'
           *  Constant: '<S57>/Constant1'
           */
          if (rtb_P_f_idx_0 >= 0.0F) {
            i = 1;
          } else {
            i = -1;
          }

          /* End of Switch: '<S57>/Switch' */

          /* Delay: '<S42>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Trigonometry: '<S42>/Cos'
           *  Trigonometry: '<S42>/Cos1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = arm_cos_f32(FMS_U.INS_Out.psi);
            FMS_DW.start_vel_DSTATE[1] = arm_sin_f32(FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          }

          /* Product: '<S42>/Multiply' incorporates:
           *  Delay: '<S42>/start_vel'
           */
          rtb_Switch_f_idx_1 = FMS_DW.start_vel_DSTATE[0] * (real32_T)i;

          /* Math: '<S56>/Math Function' */
          rtb_Divide_g[0] = rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1;
          rtb_P_f_idx_1 = rtb_Switch_f_idx_1;

          /* Product: '<S42>/Multiply' incorporates:
           *  Delay: '<S42>/start_vel'
           */
          rtb_Switch_f_idx_1 = FMS_DW.start_vel_DSTATE[1] * (real32_T)i;

          /* Sum: '<S56>/Sum of Elements' incorporates:
           *  Math: '<S56>/Math Function'
           */
          rtb_Gain = rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1 + rtb_Divide_g[0];

          /* Math: '<S56>/Math Function1' incorporates:
           *  Sum: '<S56>/Sum of Elements'
           *
           * About '<S56>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            A = -sqrtf(fabsf(rtb_Gain));
          } else {
            A = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S56>/Math Function1' */

          /* Switch: '<S56>/Switch' incorporates:
           *  Constant: '<S56>/Constant'
           *  Product: '<S56>/Product'
           */
          if (A > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_P_f_idx_1;
            rtb_Switch_f_idx_2 = A;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S56>/Switch' */

          /* Product: '<S50>/Divide' */
          rtb_Divide_g[0] = rtb_Switch_bq[0] / rtb_Switch_bq[2];
          rtb_Divide_g[1] = rtb_Switch_bq[1] / rtb_Switch_bq[2];

          /* Sum: '<S53>/Sum of Elements' incorporates:
           *  Math: '<S53>/Math Function'
           *  SignalConversion: '<S53>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Gain = rtb_Divide_g[1] * rtb_Divide_g[1] + rtb_Divide_g[0] *
            rtb_Divide_g[0];

          /* Math: '<S53>/Math Function1' incorporates:
           *  Sum: '<S53>/Sum of Elements'
           *
           * About '<S53>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain < 0.0F) {
            A = -sqrtf(fabsf(rtb_Gain));
          } else {
            A = sqrtf(rtb_Gain);
          }

          /* End of Math: '<S53>/Math Function1' */

          /* Switch: '<S53>/Switch' incorporates:
           *  Constant: '<S53>/Constant'
           *  Product: '<S53>/Product'
           */
          if (A > 0.0F) {
            rtb_Switch_bq[0] = rtb_Divide_g[1];
            rtb_Switch_bq[1] = rtb_Divide_g[0];
            rtb_Switch_bq[2] = A;
          } else {
            rtb_Switch_bq[0] = 0.0F;
            rtb_Switch_bq[1] = 0.0F;
            rtb_Switch_bq[2] = 1.0F;
          }

          /* End of Switch: '<S53>/Switch' */

          /* RelationalOperator: '<S55>/FixPt Relational Operator' incorporates:
           *  UnitDelay: '<S55>/Delay Input1'
           *
           * Block description for '<S55>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_m = (i != FMS_DW.DelayInput1_DSTATE);

          /* Delay: '<S42>/start_wp' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          if (rtb_Compare_m && (FMS_PrevZCX.start_wp_Reset_ZCE != POS_ZCSIG)) {
            FMS_DW.icLoad_f = 1U;
          }

          FMS_PrevZCX.start_wp_Reset_ZCE = rtb_Compare_m;
          if (FMS_DW.icLoad_f != 0) {
            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* MATLAB Function: '<S40>/SearchL1RefWP' incorporates:
           *  Delay: '<S42>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          rtb_P_f_idx_1 = FMS_DW.start_wp_DSTATE[0] - FMS_U.INS_Out.x_R;
          rtb_TmpSignalConversionAtMath_0 = FMS_DW.start_wp_DSTATE[1] -
            FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Product: '<S56>/Divide' */
          rtb_Switch_f_idx_0 /= rtb_Switch_f_idx_2;

          /* MATLAB Function: '<S40>/SearchL1RefWP' */
          rtb_Gain = rtb_Switch_f_idx_0 * rtb_P_f_idx_1;
          A = rtb_Switch_f_idx_0;

          /* Product: '<S56>/Divide' */
          rtb_Switch_f_idx_0 = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* MATLAB Function: '<S40>/SearchL1RefWP' incorporates:
           *  Constant: '<S38>/L1'
           *  Delay: '<S42>/start_wp'
           */
          rtb_Gain += rtb_Switch_f_idx_0 * rtb_TmpSignalConversionAtMath_0;
          rtb_Saturation_gm = 2.0F * rtb_Gain;
          rtb_MathFunction_k[0] = 0.0F;
          rtb_MathFunction_k[1] = 0.0F;
          D = rtb_Saturation_gm * rtb_Saturation_gm - ((rtb_P_f_idx_1 *
            rtb_P_f_idx_1 + rtb_TmpSignalConversionAtMath_0 *
            rtb_TmpSignalConversionAtMath_0) - FMS_PARAM.L1 * FMS_PARAM.L1) *
            4.0F;
          rtb_Gain = -1.0F;
          if (D > 0.0F) {
            rtb_Gain = sqrtf(D);
            rtb_Gain = fmaxf((-rtb_Saturation_gm + rtb_Gain) / 2.0F,
                             (-rtb_Saturation_gm - rtb_Gain) / 2.0F);
            rtb_MathFunction_k[0] = rtb_Gain * A + FMS_DW.start_wp_DSTATE[0];
            rtb_MathFunction_k[1] = rtb_Gain * rtb_Switch_f_idx_0 +
              FMS_DW.start_wp_DSTATE[1];
          } else {
            if (D == 0.0F) {
              rtb_Gain = -rtb_Saturation_gm / 2.0F;
              rtb_MathFunction_k[0] = rtb_Gain * A + FMS_DW.start_wp_DSTATE[0];
              rtb_MathFunction_k[1] = rtb_Gain * rtb_Switch_f_idx_0 +
                FMS_DW.start_wp_DSTATE[1];
            }
          }

          /* RelationalOperator: '<S43>/Compare' incorporates:
           *  Constant: '<S43>/Constant'
           *  MATLAB Function: '<S40>/SearchL1RefWP'
           */
          rtb_Compare_m = (rtb_Gain > 0.0F);

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* MATLAB Function: '<S40>/OutRegionRefWP' incorporates:
           *  Delay: '<S42>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          rtb_Gain = (FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE[0]) * A +
            (FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE[1]) * rtb_Switch_f_idx_0;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_1 = 1.29246971E-26F;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_2 = fabsf((rtb_Gain * A + FMS_DW.start_wp_DSTATE[0])
            - FMS_U.INS_Out.x_R);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          if (rtb_Switch_f_idx_2 > 1.29246971E-26F) {
            rtb_TmpSignalConversionAtMath_0 = 1.0F;
            rtb_Switch_f_idx_1 = rtb_Switch_f_idx_2;
          } else {
            rtb_P_f_idx_1 = rtb_Switch_f_idx_2 / 1.29246971E-26F;
            rtb_TmpSignalConversionAtMath_0 = rtb_P_f_idx_1 * rtb_P_f_idx_1;
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_f_idx_2 = fabsf((rtb_Gain * rtb_Switch_f_idx_0 +
            FMS_DW.start_wp_DSTATE[1]) - FMS_U.INS_Out.y_R);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          if (rtb_Switch_f_idx_2 > rtb_Switch_f_idx_1) {
            rtb_P_f_idx_1 = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;
            rtb_TmpSignalConversionAtMath_0 = rtb_TmpSignalConversionAtMath_0 *
              rtb_P_f_idx_1 * rtb_P_f_idx_1 + 1.0F;
            rtb_Switch_f_idx_1 = rtb_Switch_f_idx_2;
          } else {
            rtb_P_f_idx_1 = rtb_Switch_f_idx_2 / rtb_Switch_f_idx_1;
            rtb_TmpSignalConversionAtMath_0 += rtb_P_f_idx_1 * rtb_P_f_idx_1;
          }

          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_f_idx_1 * sqrtf
            (rtb_TmpSignalConversionAtMath_0);
          rtb_Gain += rtb_TmpSignalConversionAtMath_0 * 0.577350259F;

          /* Switch: '<S40>/Switch' incorporates:
           *  Delay: '<S42>/start_wp'
           *  MATLAB Function: '<S40>/OutRegionRefWP'
           */
          if (rtb_Compare_m) {
            rtb_Switch_f_idx_1 = rtb_MathFunction_k[0];
          } else {
            rtb_Switch_f_idx_1 = rtb_Gain * A + FMS_DW.start_wp_DSTATE[0];
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S41>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 -= FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Math: '<S51>/Math Function' */
          rtb_P_f_idx_1 = rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1;
          rtb_MathFunction_k[0] = rtb_Switch_f_idx_1;

          /* Switch: '<S40>/Switch' incorporates:
           *  Delay: '<S42>/start_wp'
           *  MATLAB Function: '<S40>/OutRegionRefWP'
           *  Sum: '<S41>/Subtract'
           */
          if (rtb_Compare_m) {
            rtb_Switch_f_idx_1 = rtb_MathFunction_k[1];
          } else {
            rtb_Switch_f_idx_1 = rtb_Gain * rtb_Switch_f_idx_0 +
              FMS_DW.start_wp_DSTATE[1];
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S41>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S21>/Signal Copy1'
           */
          rtb_Switch_f_idx_1 -= FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Math: '<S51>/Math Function' incorporates:
           *  Math: '<S49>/Square'
           */
          rtb_Gain = rtb_Switch_f_idx_1 * rtb_Switch_f_idx_1;

          /* Sum: '<S51>/Sum of Elements' incorporates:
           *  Math: '<S51>/Math Function'
           */
          A = rtb_Gain + rtb_P_f_idx_1;

          /* Math: '<S51>/Math Function1' incorporates:
           *  Sum: '<S51>/Sum of Elements'
           *
           * About '<S51>/Math Function1':
           *  Operator: sqrt
           */
          if (A < 0.0F) {
            A = -sqrtf(fabsf(A));
          } else {
            A = sqrtf(A);
          }

          /* End of Math: '<S51>/Math Function1' */

          /* Switch: '<S51>/Switch' incorporates:
           *  Constant: '<S51>/Constant'
           *  Product: '<S51>/Product'
           */
          if (A > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_MathFunction_k[0];
            rtb_Switch_f_idx_2 = A;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S51>/Switch' */

          /* Product: '<S51>/Divide' */
          rtb_Divide_g[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;
          rtb_Divide_g[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Sum: '<S54>/Sum of Elements' incorporates:
           *  Math: '<S54>/Math Function'
           *  SignalConversion: '<S54>/TmpSignal ConversionAtMath FunctionInport1'
           */
          A = rtb_Divide_g[1] * rtb_Divide_g[1] + rtb_Divide_g[0] *
            rtb_Divide_g[0];

          /* Math: '<S54>/Math Function1' incorporates:
           *  Sum: '<S54>/Sum of Elements'
           *
           * About '<S54>/Math Function1':
           *  Operator: sqrt
           */
          if (A < 0.0F) {
            A = -sqrtf(fabsf(A));
          } else {
            A = sqrtf(A);
          }

          /* End of Math: '<S54>/Math Function1' */

          /* Switch: '<S54>/Switch' incorporates:
           *  Constant: '<S54>/Constant'
           *  Product: '<S54>/Product'
           */
          if (A > 0.0F) {
            rtb_Switch_f_idx_0 = rtb_Divide_g[1];
            rtb_Switch_f_idx_1 = rtb_Divide_g[0];
            rtb_Switch_f_idx_2 = A;
          } else {
            rtb_Switch_f_idx_0 = 0.0F;
            rtb_Switch_f_idx_1 = 0.0F;
            rtb_Switch_f_idx_2 = 1.0F;
          }

          /* End of Switch: '<S54>/Switch' */

          /* Product: '<S54>/Divide' */
          rtb_Divide_g[0] = rtb_Switch_f_idx_0 / rtb_Switch_f_idx_2;

          /* Product: '<S53>/Divide' */
          rtb_P_f_idx_1 = rtb_Switch_bq[0] / rtb_Switch_bq[2];
          rtb_MathFunction_k[0] *= rtb_MathFunction_k[0];

          /* Product: '<S54>/Divide' incorporates:
           *  Math: '<S49>/Square'
           */
          rtb_Divide_g[1] = rtb_Switch_f_idx_1 / rtb_Switch_f_idx_2;

          /* Product: '<S53>/Divide' */
          rtb_TmpSignalConversionAtMath_0 = rtb_Switch_bq[1] / rtb_Switch_bq[2];

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sqrt: '<S48>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S48>/Square'
           *  SignalConversion: '<S21>/Signal Copy1'
           *  Sum: '<S48>/Sum of Elements'
           */
          A = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                    FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Math: '<S46>/Square' */
          rtb_Switch_f_idx_1 = A * A;

          /* Sum: '<S52>/Subtract' incorporates:
           *  Product: '<S52>/Multiply'
           *  Product: '<S52>/Multiply1'
           */
          A = rtb_Divide_g[0] * rtb_TmpSignalConversionAtMath_0 - rtb_Divide_g[1]
            * rtb_P_f_idx_1;

          /* Signum: '<S47>/Sign1' */
          if (A < 0.0F) {
            A = -1.0F;
          } else {
            if (A > 0.0F) {
              A = 1.0F;
            }
          }

          /* End of Signum: '<S47>/Sign1' */

          /* Switch: '<S47>/Switch2' incorporates:
           *  Constant: '<S47>/Constant4'
           */
          if (A == 0.0F) {
            A = 1.0F;
          }

          /* End of Switch: '<S47>/Switch2' */

          /* DotProduct: '<S47>/Dot Product' */
          rtb_Switch_f_idx_2 = rtb_P_f_idx_1 * rtb_Divide_g[0] +
            rtb_TmpSignalConversionAtMath_0 * rtb_Divide_g[1];

          /* Trigonometry: '<S47>/Acos' incorporates:
           *  DotProduct: '<S47>/Dot Product'
           */
          if (rtb_Switch_f_idx_2 > 1.0F) {
            rtb_Switch_f_idx_2 = 1.0F;
          } else {
            if (rtb_Switch_f_idx_2 < -1.0F) {
              rtb_Switch_f_idx_2 = -1.0F;
            }
          }

          /* Product: '<S47>/Multiply' incorporates:
           *  Trigonometry: '<S47>/Acos'
           */
          A *= acosf(rtb_Switch_f_idx_2);

          /* Saturate: '<S46>/Saturation' */
          if (A > 1.57079637F) {
            A = 1.57079637F;
          } else {
            if (A < -1.57079637F) {
              A = -1.57079637F;
            }
          }

          /* End of Saturate: '<S46>/Saturation' */

          /* Gain: '<S38>/AccToRate' incorporates:
           *  Constant: '<S38>/L1'
           *  Constant: '<S46>/Constant'
           *  Gain: '<S46>/Gain'
           *  MinMax: '<S46>/Max'
           *  MinMax: '<S46>/Min'
           *  Product: '<S46>/Divide'
           *  Product: '<S46>/Multiply1'
           *  Sqrt: '<S49>/Sqrt'
           *  Sum: '<S49>/Sum of Elements'
           *  Trigonometry: '<S46>/Sin'
           */
          FMS_B.Merge = 2.0F * rtb_Switch_f_idx_1 * arm_sin_f32(A) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Gain + rtb_MathFunction_k[0]), 0.5F))
            * FMS_PARAM.ACC2RATE;

          /* Update for Delay: '<S42>/start_vel' */
          FMS_DW.icLoad = 0U;

          /* Update for UnitDelay: '<S55>/Delay Input1'
           *
           * Block description for '<S55>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE = (real32_T)i;

          /* Update for Delay: '<S42>/start_wp' */
          FMS_DW.icLoad_f = 0U;

          /* End of Outputs for SubSystem: '<S36>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S36>/Move Control' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Gain: '<S39>/Gain6' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S21>/Signal Copy2'
           */
          FMS_B.Merge = FMS_PARAM.MAX_R * FMS_U.Pilot_Cmd.stick_roll;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S36>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S36>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S31>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S31>/Bus Assignment' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.u_cmd = rtb_P_f_idx_0;
        FMS_Y.FMS_Out.r_cmd = FMS_B.Merge;

        /* End of Outputs for SubSystem: '<S26>/Position' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S26>/Unknown' incorporates:
         *  ActionPort: '<S33>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S23>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S26>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S26>/Switch Case' */
      /* End of Outputs for SubSystem: '<S22>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S22>/Manual' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S23>/Bus Assignment'
       *  BusAssignment: '<S28>/Bus Assignment'
       *  Constant: '<S28>/Constant'
       *  SignalConversion: '<S28>/TmpHiddenBufferAtBus AssignmentInport1'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S28>/Bus Assignment' incorporates:
       *  BusAssignment: '<S23>/Bus Assignment'
       *  Constant: '<S28>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      /* Saturate: '<S144>/Saturation' incorporates:
       *  Constant: '<S144>/Constant4'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S21>/Signal Copy2'
       *  Sum: '<S144>/Sum'
       */
      if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
        rtb_Gain = 2.0F;
      } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
        rtb_Gain = 0.0F;
      } else {
        rtb_Gain = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
      }

      /* End of Saturate: '<S144>/Saturation' */
      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

      /* BusAssignment: '<S28>/Bus Assignment' incorporates:
       *  BusAssignment: '<S23>/Bus Assignment'
       *  Constant: '<S144>/Constant5'
       *  DataTypeConversion: '<S143>/Data Type Conversion'
       *  Gain: '<S144>/Gain4'
       *  Outport: '<Root>/FMS_Out'
       *  Sum: '<S144>/Add'
       */
      FMS_Y.FMS_Out.actuator_cmd[0] = (uint16_T)fmodf(floorf(500.0F * rtb_Gain +
        1000.0F), 65536.0F);

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
      /* DataTypeConversion: '<S143>/Data Type Conversion1' incorporates:
       *  Bias: '<S143>/Bias1'
       *  Gain: '<S143>/Gain1'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S21>/Signal Copy2'
       */
      rtb_Gain = fmodf(floorf(500.0F * FMS_U.Pilot_Cmd.stick_roll + 1500.0F),
                       65536.0F);

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

      /* BusAssignment: '<S28>/Bus Assignment' incorporates:
       *  BusAssignment: '<S23>/Bus Assignment'
       *  DataTypeConversion: '<S143>/Data Type Conversion1'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[1] = (uint16_T)(rtb_Gain < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Gain : (int32_T)(uint16_T)rtb_Gain);
      for (i = 0; i < 14; i++) {
        FMS_Y.FMS_Out.actuator_cmd[i + 2] = 0U;
      }

      /* End of Outputs for SubSystem: '<S22>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S22>/Unknown' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S23>/Bus Assignment'
       */
      FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S22>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S22>/Switch Case' */
    /* End of Outputs for SubSystem: '<S20>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S20>/Switch Case' */

  /* BusAssignment: '<S23>/Bus Assignment' incorporates:
   *  Constant: '<S23>/Constant'
   *  DataStoreRead: '<S23>/Data Store Read'
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   *  DiscreteIntegrator: '<S165>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S21>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S23>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE_g;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
  FMS_Y.FMS_Out.home[0] = FMS_DW.home[0];
  FMS_Y.FMS_Out.home[1] = FMS_DW.home[1];
  FMS_Y.FMS_Out.home[2] = FMS_DW.home[2];
  FMS_Y.FMS_Out.home[3] = FMS_DW.home[3];

  /* Update for DiscreteIntegrator: '<S165>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S165>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Update for UnitDelay: '<S7>/Delay Input1' incorporates:
   *  Inport: '<Root>/Auto_Cmd'
   *
   * Block description for '<S7>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.Auto_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Gain = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Gain < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = (uint32_T)rtb_Gain;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for Delay: '<S8>/Delay' */
  FMS_DW.Delay_DSTATE_m = rtb_Switch_b5;
}

/* Model initialize function */
void FMS_init(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(FMS_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &FMS_B), 0,
                sizeof(B_FMS_T));

  {
    FMS_B.state = VehicleState_None;
    FMS_B.target_mode = PilotMode_None;
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* states (dwork) */
  (void) memset((void *)&FMS_DW, 0,
                sizeof(DW_FMS_T));

  /* external inputs */
  (void)memset(&FMS_U, 0, sizeof(ExtU_FMS_T));

  /* external outputs */
  FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

  /* Start for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Start for SwitchCase: '<S20>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S20>/Arm' */
  /* Start for SwitchCase: '<S22>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S22>/SubMode' */
  /* Start for SwitchCase: '<S29>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* End of Start for SubSystem: '<S22>/SubMode' */

  /* Start for IfAction SubSystem: '<S22>/Auto' */
  /* Start for SwitchCase: '<S27>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S22>/Auto' */

  /* Start for IfAction SubSystem: '<S22>/Assist' */
  /* Start for SwitchCase: '<S26>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S26>/Position' */
  /* Start for SwitchCase: '<S36>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S26>/Position' */
  /* End of Start for SubSystem: '<S22>/Assist' */
  /* End of Start for SubSystem: '<S20>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;
  FMS_PrevZCX.start_wp_Reset_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<Root>/SafeMode' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<Root>/FMS State Machine' */
  initialize_msg_local_queues_for();
  FMS_DW.sfEvent = -1;
  FMS_DW.is_active_Combo_Stick = 0U;
  FMS_DW.is_Combo_Stick = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_active_Command_Listener = 0U;
  FMS_DW.is_Command_Listener = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD;
  FMS_DW.temporalCounter_i1 = 0U;
  FMS_DW.is_active_c11_FMS = 0U;
  FMS_DW.M_msgReservedData = FMS_Cmd_None;
  FMS_DW.bl = false;
  FMS_DW.br = false;
  FMS_DW.prep_mission = 0.0;
  FMS_B.wp_consume = 0U;
  FMS_B.wp_index = 1U;
  FMS_DW.chartAbsoluteTimeCounter = 0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SystemInitialize for IfAction SubSystem: '<S20>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S22>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S29>/Return' */
  /* InitializeConditions for Delay: '<S149>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* End of SystemInitialize for SubSystem: '<S29>/Return' */
  /* End of SystemInitialize for SubSystem: '<S22>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S22>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S27>/Mission' */
  /* InitializeConditions for UnitDelay: '<S66>/Delay Input1'
   *
   * Block description for '<S66>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* End of SystemInitialize for SubSystem: '<S27>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S22>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S22>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S26>/Position' */
  /* SystemInitialize for Chart: '<S37>/Motion State' */
  FMS_DW.is_active_c10_FMS = 0U;
  FMS_DW.is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for IfAction SubSystem: '<S36>/Hold Control' */
  /* InitializeConditions for Delay: '<S42>/start_vel' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for UnitDelay: '<S55>/Delay Input1'
   *
   * Block description for '<S55>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S42>/start_wp' */
  FMS_DW.icLoad_f = 1U;

  /* End of SystemInitialize for SubSystem: '<S36>/Hold Control' */

  /* SystemInitialize for Merge: '<S36>/Merge' */
  FMS_B.Merge = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S26>/Position' */
  /* End of SystemInitialize for SubSystem: '<S22>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S20>/Arm' */
  /* End of SystemInitialize for SubSystem: '<Root>/FMS Commander' */
}

/* Model terminate function */
void FMS_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
