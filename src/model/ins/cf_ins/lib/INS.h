/*
 * File: INS.h
 *
 * Code generated for Simulink model 'INS'.
 *
 * Model version                  : 1.4162
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Jan  1 15:42:20 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_INS_h_
#define RTW_HEADER_INS_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef INS_COMMON_INCLUDES_
# define INS_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* INS_COMMON_INCLUDES_ */

#include "arm_math.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_INS_T RT_MODEL_INS_T;

#ifndef DEFINED_TYPEDEF_FOR_IMU_Bus_
#define DEFINED_TYPEDEF_FOR_IMU_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T gyr_x;
  real32_T gyr_y;
  real32_T gyr_z;
  real32_T acc_x;
  real32_T acc_y;
  real32_T acc_z;
} IMU_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MAG_Bus_
#define DEFINED_TYPEDEF_FOR_MAG_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T mag_x;
  real32_T mag_y;
  real32_T mag_z;
} MAG_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Barometer_Bus_
#define DEFINED_TYPEDEF_FOR_Barometer_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T pressure;
  real32_T temperature;
} Barometer_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_GPS_uBlox_Bus_
#define DEFINED_TYPEDEF_FOR_GPS_uBlox_Bus_

typedef struct {
  uint32_T timestamp;
  uint32_T iTOW;
  uint16_T year;
  uint8_T month;
  uint8_T day;
  uint8_T hour;
  uint8_T min;
  uint8_T sec;
  uint8_T valid;
  uint32_T tAcc;
  int32_T nano;
  uint8_T fixType;
  uint8_T flags;
  uint8_T reserved1;
  uint8_T numSV;
  int32_T lon;
  int32_T lat;
  int32_T height;
  int32_T hMSL;
  uint32_T hAcc;
  uint32_T vAcc;
  int32_T velN;
  int32_T velE;
  int32_T velD;
  int32_T gSpeed;
  int32_T heading;
  uint32_T sAcc;
  uint32_T headingAcc;
  uint16_T pDOP;
  uint16_T reserved2;
} GPS_uBlox_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Rangefinder_Bus_
#define DEFINED_TYPEDEF_FOR_Rangefinder_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T distance;
} Rangefinder_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Optical_Flow_Bus_
#define DEFINED_TYPEDEF_FOR_Optical_Flow_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T vx;
  real32_T vy;
  uint8_T quality;
  uint8_T reserved1;
  uint16_T reserved2;
} Optical_Flow_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_AirSpeed_Bus_
#define DEFINED_TYPEDEF_FOR_AirSpeed_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T diff_pressure;
  real32_T temperature;
} AirSpeed_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_External_Pos_Bus_
#define DEFINED_TYPEDEF_FOR_External_Pos_Bus_

typedef struct {
  uint32_T timestamp;
  uint32_T field_valid;
  real32_T x;
  real32_T y;
  real32_T z;
  real32_T phi;
  real32_T theta;
  real32_T psi;
} External_Pos_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_INS_Out_Bus_
#define DEFINED_TYPEDEF_FOR_INS_Out_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T phi;
  real32_T theta;
  real32_T psi;
  real32_T quat[4];
  real32_T p;
  real32_T q;
  real32_T r;
  real32_T ax;
  real32_T ay;
  real32_T az;
  real32_T vn;
  real32_T ve;
  real32_T vd;
  real32_T airspeed;
  real_T lat;
  real_T lon;
  real_T alt;
  real_T lat_0;
  real_T lon_0;
  real_T alt_0;
  real_T dx_dlat;
  real_T dy_dlon;
  real32_T x_R;
  real32_T y_R;
  real32_T h_R;
  real32_T h_AGL;
  uint32_T flag;
  uint32_T status;
} INS_Out_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_i6HyuFQRjfkj8sSCv2bg5D_
#define DEFINED_TYPEDEF_FOR_struct_i6HyuFQRjfkj8sSCv2bg5D_

typedef struct {
  uint32_T period;
  int8_T model_info[14];
} struct_i6HyuFQRjfkj8sSCv2bg5D;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_DP7rbDXzvySaL2o76hvHzF_
#define DEFINED_TYPEDEF_FOR_struct_DP7rbDXzvySaL2o76hvHzF_

typedef struct {
  real32_T GPS_HOR_Q_BIAS;
  real32_T GPS_HOR_Q_SCALE;
  real32_T GPS_VER_Q_BIAS;
  real32_T GPS_VER_Q_SCALE;
  real32_T GPS_VEL_Q_BIAS;
  real32_T GPS_VEL_Q_SCALE;
  real32_T ATT_GAIN;
  real32_T HEADING_GAIN;
  real32_T MAG_GAIN;
  uint8_T MAG_AIR_EN;
  real32_T BIAS_G_GAIN;
  real32_T GPS_POS_GAIN;
  real32_T GPS_ALT_GAIN;
  real32_T GPS_VEL_GAIN;
  real32_T GPS_BIAS_A_GAIN;
  uint32_T GPS_POS_DELAY;
  uint32_T GPS_VEL_DELAY;
  real32_T RTK_POS_GAIN;
  real32_T RTK_ALT_GAIN;
  real32_T RTK_VEL_GAIN;
  real32_T RTK_BIAS_A_GAIN;
  real32_T OPF_VEL_GAIN;
  real32_T OPF_BIAS_A_GAIN;
  uint32_T OPF_VEL_DELAY;
  real32_T OPF_FIX_GAIN;
  real32_T BARO_H_GAIN;
  real32_T BARO_VZ_GAIN;
  real32_T BARO_BIAS_AZ_GAIN;
  uint32_T BARO_H_DELAY;
  real32_T RF_H_GAIN;
  real32_T RF_VZ_GAIN;
  real32_T RF_BIAS_AZ_GAIN;
  uint32_T RF_H_DELAY;
  real32_T EXTPOS_POS_GAIN;
  real32_T EXTPOS_VEL_GAIN;
  real32_T EXTPOS_BIAS_A_GAIN;
  uint32_T EXTPOS_POS_DELAY;
  uint8_T EXTPOS_PSI_MODE;
  real32_T EXTPOS_PSI;
} struct_DP7rbDXzvySaL2o76hvHzF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Gsh1YUlqR57cYRpVuxG74E_
#define DEFINED_TYPEDEF_FOR_struct_Gsh1YUlqR57cYRpVuxG74E_

typedef struct {
  real_T dt;
  real32_T g;
  real32_T wmm_mag[629];
  real32_T wmm_dec[629];
  real32_T wmm_inc[629];
} struct_Gsh1YUlqR57cYRpVuxG74E;

#endif

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion;           /* '<S434>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<S434>/Data Type Conversion1' */
  real_T Multiply2;                    /* '<S450>/Multiply2' */
  real_T Rm;                           /* '<S450>/Product3' */
  real32_T Divide;                     /* '<S415>/Divide' */
  real32_T Merge;                      /* '<S307>/Merge' */
  real32_T Merge_e;                    /* '<S308>/Merge' */
  real32_T Merge_g[2];                 /* '<S250>/Merge' */
  real32_T Merge_n[2];                 /* '<S251>/Merge' */
  real32_T rf_height_bias;             /* '<S298>/Switch' */
  real32_T Sum1[3];                    /* '<S292>/Sum1' */
  real32_T Sum1_p[3];                  /* '<S280>/Sum1' */
  real32_T Sum1_c[3];                  /* '<S271>/Sum1' */
  real32_T Sum1_pu[3];                 /* '<S262>/Sum1' */
  real32_T Saturation;                 /* '<S262>/Saturation' */
  real32_T Sum1_f[6];                  /* '<S241>/Sum1' */
  real32_T Sum1_o[6];                  /* '<S228>/Sum1' */
  real32_T Sum1_b[6];                  /* '<S219>/Sum1' */
  real32_T Merge_l[4];                 /* '<S159>/Merge' */
  real32_T OutportBufferForquat_0[4];  /* '<S138>/DCM To Quaternion' */
  real32_T Integrator[3];              /* '<S93>/Integrator' */
} BlockIO_INS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE;                /* '<S397>/Delay1' */
  real_T Delay_DSTATE[2];              /* '<S398>/Delay' */
  real_T Delay1_DSTATE_o[2];           /* '<S398>/Delay1' */
  real32_T Delay_3_DSTATE;             /* '<Root>/Delay' */
  real32_T Delay_4_DSTATE;             /* '<Root>/Delay' */
  real32_T Delay_9_DSTATE[9];          /* '<Root>/Delay' */
  real32_T Delay_DSTATE_j;             /* '<S493>/Delay' */
  real32_T DiscreteTimeIntegrator5_DSTATE[2];/* '<S481>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_c[2];/* '<S480>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S467>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S467>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_g;/* '<S447>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTAT_m;/* '<S448>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k;/* '<S447>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S448>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_d;             /* '<S415>/Delay' */
  real32_T Delay_4_DSTATE_k;           /* '<S56>/Delay' */
  real32_T Delay_5_DSTATE;             /* '<S56>/Delay' */
  real32_T Delay_6_DSTATE;             /* '<S56>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_f;/* '<S340>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_h;/* '<S340>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE_a;             /* '<S344>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S366>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S378>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S365>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S377>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_k3;/* '<S379>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_b[3];          /* '<S304>/Delay' */
  real32_T Delay_DSTATE_l[6];          /* '<S247>/Delay' */
  real32_T h_delay_DSTATE[500];        /* '<S296>/h_delay' */
  real32_T Delay_DSTATE_f;             /* '<S301>/Delay' */
  real32_T h_delay_DSTATE_l[500];      /* '<S284>/h_delay' */
  real32_T vd_delay_DSTATE[500];       /* '<S284>/vd_delay' */
  real32_T Delay_DSTATE_p[3];          /* '<S273>/Delay' */
  real32_T x_delay_DSTATE[500];        /* '<S275>/x_delay' */
  real32_T Delay_DSTATE_m;             /* '<S277>/Delay' */
  real32_T Delay_DSTATE_dr[3];         /* '<S264>/Delay' */
  real32_T x_delay_DSTATE_b[500];      /* '<S266>/x_delay' */
  real32_T Delay_DSTATE_h;             /* '<S268>/Delay' */
  real32_T vn_delay_DSTATE[500];       /* '<S245>/vn_delay' */
  real32_T ve_delay_DSTATE[500];       /* '<S245>/ve_delay' */
  real32_T x_delay_DSTATE_k[500];      /* '<S232>/x_delay' */
  real32_T x_delay1_DSTATE[100];       /* '<S232>/x_delay1' */
  real32_T vn_delay_DSTATE_n[500];     /* '<S232>/vn_delay' */
  real32_T vn_delay1_DSTATE[500];      /* '<S232>/vn_delay1' */
  real32_T x_delay_DSTATE_l[500];      /* '<S223>/x_delay' */
  real32_T y_delay_DSTATE[500];        /* '<S223>/y_delay' */
  real32_T Delay_DSTATE_k[2];          /* '<S225>/Delay' */
  real32_T DiscreteTimeIntegrator5_DSTAT_o[2];/* '<S199>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_m;/* '<S197>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTA_ow;/* '<S198>/Discrete-Time Integrator5' */
  real32_T Delay1_DSTATE_h[3];         /* '<S57>/Delay1' */
  real32_T Delay2_DSTATE[3];           /* '<S57>/Delay2' */
  real32_T Delay1_DSTATE_e[4];         /* '<S120>/Delay1' */
  real32_T DiscreteTimeIntegrator2_DSTATE[3];/* '<S122>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator1_DSTAT_o[3];/* '<S90>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE_lv[600];       /* '<S88>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTAT_lq[3];/* '<S90>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S108>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTAT_c[3];/* '<S103>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE_lt;            /* '<S104>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_g[3];/* '<S103>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S108>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_b[3];/* '<S118>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_ce[3];/* '<S118>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE[3];       /* '<S93>/Integrator' */
  real32_T Integrator1_DSTATE[3];      /* '<S93>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_bo;/* '<S12>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_hi;/* '<S15>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_b3;/* '<S17>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_ca;/* '<S11>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_e;/* '<S13>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_kg;/* '<S14>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_ax;/* '<S16>/Discrete-Time Integrator' */
  int32_T UnitDelay_DSTATE;            /* '<S443>/Unit Delay' */
  uint32_T DelayInput1_DSTATE;         /* '<S492>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_e3;/* '<S488>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTAT_cv;/* '<S489>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_k;       /* '<S484>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_gj;/* '<S478>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_n;       /* '<S474>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_lg;/* '<S460>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S454>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_lp;/* '<S452>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S446>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S437>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_b;       /* '<S428>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_nj;/* '<S426>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_g;       /* '<S418>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_c;       /* '<S421>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_nm;/* '<S414>/Discrete-Time Integrator' */
  uint32_T Delay_DSTATE_fy;            /* '<S416>/Delay' */
  uint32_T Delay1_DSTATE_i;            /* '<S415>/Delay1' */
  uint32_T DelayInput1_DSTATE_l;       /* '<S293>/Delay Input1' */
  uint32_T Delay1_DSTATE_p;            /* '<S301>/Delay1' */
  uint32_T DelayInput1_DSTATE_m;       /* '<S303>/Delay Input1' */
  uint32_T Delay2_DSTATE_o;            /* '<S301>/Delay2' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S281>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_a;       /* '<S272>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_lg;      /* '<S263>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_ml;      /* '<S242>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d0;      /* '<S229>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_no;      /* '<S220>/Delay Input1' */
  uint32_T Delay_DSTATE_i;             /* '<S149>/Delay' */
  uint32_T Delay_DSTATE_ly;            /* '<S150>/Delay' */
  uint32_T Delay_DSTATE_n;             /* '<S145>/Delay' */
  uint32_T DiscreteTimeIntegrator_DSTATE_d;/* '<S97>/Discrete-Time Integrator' */
  uint32_T Output_DSTATE;              /* '<S4>/Output' */
  real32_T Memory_PreviousInput;       /* '<S298>/Memory' */
  real32_T Memory_PreviousInput_f[3];  /* '<S294>/Memory' */
  real32_T Memory_PreviousInput_b;     /* '<S288>/Memory' */
  real32_T Memory_PreviousInput_e[3];  /* '<S282>/Memory' */
  real32_T Memory_PreviousInput_n[6];  /* '<S243>/Memory' */
  real32_T Memory_PreviousInput_d[2];  /* '<S237>/Memory' */
  real32_T Memory_PreviousInput_h[6];  /* '<S230>/Memory' */
  real32_T Memory_PreviousInput_m[6];  /* '<S221>/Memory' */
  uint8_T Delay_DSTATE_fp;             /* '<S475>/Delay' */
  uint8_T Delay_DSTATE_bw;             /* '<S455>/Delay' */
  uint8_T Delay_DSTATE_g;              /* '<S429>/Delay' */
  uint8_T Delay_DSTATE_i1;             /* '<S422>/Delay' */
  uint8_T Delay_DSTATE_n2;             /* '<S343>/Delay' */
  uint8_T DelayInput1_DSTATE_cz;       /* '<S347>/Delay Input1' */
  uint8_T Delay_DSTATE_e;              /* '<S348>/Delay' */
  boolean_T Delay_DSTATE_c;            /* '<S485>/Delay' */
  boolean_T DelayInput1_DSTATE_ic;     /* '<S346>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S359>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_hg;     /* '<S375>/Delay Input1' */
  boolean_T Delay_DSTATE_kh;           /* '<S366>/Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S360>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S388>/Delay Input1' */
  boolean_T Delay_DSTATE_k4;           /* '<S378>/Delay' */
  boolean_T Delay_DSTATE_ng;           /* '<S365>/Delay' */
  boolean_T DelayInput1_DSTATE_kh;     /* '<S370>/Delay Input1' */
  boolean_T Delay_DSTATE_c1;           /* '<S377>/Delay' */
  boolean_T DelayInput1_DSTATE_ch;     /* '<S383>/Delay Input1' */
  boolean_T Delay_DSTATE_n2o;          /* '<S379>/Delay' */
  boolean_T DelayInput1_DSTATE_jx;     /* '<S393>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dp;     /* '<S399>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_mw;     /* '<S401>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_oe;     /* '<S300>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ib;     /* '<S291>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pq;     /* '<S290>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_a4;     /* '<S279>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S270>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f1;     /* '<S239>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_gn;     /* '<S240>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dp5;    /* '<S227>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pr;     /* '<S143>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_nk;     /* '<S144>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_mm;     /* '<S153>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ff;     /* '<S92>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_d2;     /* '<S107>/Delay Input1' */
  boolean_T Delay_DSTATE_bn;           /* '<S12>/Delay' */
  boolean_T Delay_DSTATE_cx;           /* '<S15>/Delay' */
  boolean_T Delay_DSTATE_l0;           /* '<S17>/Delay' */
  boolean_T Delay_DSTATE_cn;           /* '<S11>/Delay' */
  boolean_T Delay_DSTATE_pk;           /* '<S13>/Delay' */
  boolean_T Delay_DSTATE_db;           /* '<S14>/Delay' */
  boolean_T Delay_DSTATE_lyf;          /* '<S16>/Delay' */
  boolean_T DelayInput1_DSTATE_dx;     /* '<S21>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_mu;     /* '<S26>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dq;     /* '<S31>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f4;     /* '<S36>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ng;     /* '<S41>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dql;    /* '<S46>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_fq;     /* '<S51>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S489>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S467>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_k;/* '<S467>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_l;/* '<S447>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_j;/* '<S448>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S447>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_j;/* '<S448>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_h;/* '<S340>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S340>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ky;/* '<S366>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_l;/* '<S378>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S365>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_b;/* '<S377>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_kt;/* '<S379>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_p;/* '<S90>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S90>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_i;/* '<S108>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_m;/* '<S103>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_n;/* '<S97>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_lr;/* '<S103>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S108>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_o;/* '<S118>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_nh;/* '<S118>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S93>/Integrator' */
  int8_T Integrator1_PrevResetState;   /* '<S93>/Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_nf;/* '<S12>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S15>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_dj;/* '<S17>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_h1;/* '<S11>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_as;/* '<S13>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S14>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_ar;/* '<S16>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S481>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S480>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S467>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S447>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_e;/* '<S448>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_k;/* '<S340>/Discrete-Time Integrator1' */
  uint8_T icLoad;                      /* '<S296>/h_delay' */
  uint8_T icLoad_b;                    /* '<S301>/Delay1' */
  uint8_T icLoad_o;                    /* '<S284>/h_delay' */
  uint8_T icLoad_f;                    /* '<S284>/vd_delay' */
  uint8_T icLoad_p;                    /* '<S275>/x_delay' */
  uint8_T icLoad_a;                    /* '<S266>/x_delay' */
  uint8_T icLoad_h;                    /* '<S245>/vn_delay' */
  uint8_T icLoad_j;                    /* '<S245>/ve_delay' */
  uint8_T icLoad_op;                   /* '<S232>/x_delay' */
  uint8_T icLoad_i;                    /* '<S232>/x_delay1' */
  uint8_T icLoad_m;                    /* '<S232>/vn_delay' */
  uint8_T icLoad_jp;                   /* '<S232>/vn_delay1' */
  uint8_T icLoad_hw;                   /* '<S223>/x_delay' */
  uint8_T icLoad_od;                   /* '<S223>/y_delay' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_p;/* '<S199>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_n;/* '<S197>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_L_ns;/* '<S198>/Discrete-Time Integrator5' */
  uint8_T icLoad_o2;                   /* '<S120>/Delay1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_i;/* '<S90>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_m;/* '<S108>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_a;/* '<S103>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_l;/* '<S118>/Discrete-Time Integrator1' */
  uint8_T Integrator1_IC_LOADING;      /* '<S93>/Integrator1' */
  boolean_T Relay_Mode;                /* '<S488>/Relay' */
  boolean_T Relay_Mode_n;              /* '<S478>/Relay' */
  boolean_T Relay_Mode_n2;             /* '<S352>/Relay' */
  boolean_T Relay1_Mode;               /* '<S352>/Relay1' */
  boolean_T Relay_Mode_n5;             /* '<S140>/Relay' */
  boolean_T Relay_Mode_nf;             /* '<S94>/Relay' */
  boolean_T Relay_Mode_n1;             /* '<S9>/Relay' */
  boolean_T Relay1_Mode_j;             /* '<S9>/Relay1' */
  boolean_T Reference_Height_MODE;     /* '<S413>/Reference_Height' */
  boolean_T Rangefinder_Correct_MODE;  /* '<S261>/Rangefinder_Correct' */
  boolean_T GPS_Correct_MODE;          /* '<S260>/GPS_Correct' */
  boolean_T ExternalPos_Correct_MODE;  /* '<S259>/ExternalPos_Correct' */
  boolean_T Baro_Correct_MODE;         /* '<S258>/Baro_Correct' */
  boolean_T OptFlow_Correct_MODE;      /* '<S218>/OptFlow_Correct' */
  boolean_T GPS_Correct_MODE_o;        /* '<S217>/GPS_Correct' */
  boolean_T ExternalPos_Correct_MODE_k;/* '<S216>/ExternalPos_Correct' */
  boolean_T GPS_Meas_Acc_MODE;         /* '<S89>/GPS_Meas_Acc' */
} D_Work_INS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState WGS84_Model_Trig_ZCE;     /* '<S406>/WGS84_Model' */
  ZCSigState h_delay_Reset_ZCE;        /* '<S296>/h_delay' */
  ZCSigState h_delay_Reset_ZCE_m;      /* '<S284>/h_delay' */
  ZCSigState vd_delay_Reset_ZCE;       /* '<S284>/vd_delay' */
  ZCSigState x_delay_Reset_ZCE;        /* '<S275>/x_delay' */
  ZCSigState x_delay_Reset_ZCE_l;      /* '<S266>/x_delay' */
  ZCSigState vn_delay_Reset_ZCE;       /* '<S245>/vn_delay' */
  ZCSigState ve_delay_Reset_ZCE;       /* '<S245>/ve_delay' */
  ZCSigState x_delay_Reset_ZCE_b;      /* '<S232>/x_delay' */
  ZCSigState x_delay1_Reset_ZCE;       /* '<S232>/x_delay1' */
  ZCSigState vn_delay_Reset_ZCE_p;     /* '<S232>/vn_delay' */
  ZCSigState vn_delay1_Reset_ZCE;      /* '<S232>/vn_delay1' */
  ZCSigState x_delay_Reset_ZCE_lr;     /* '<S223>/x_delay' */
  ZCSigState y_delay_Reset_ZCE;        /* '<S223>/y_delay' */
} PrevZCSigStates_INS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  IMU_Bus IMU;                         /* '<Root>/IMU' */
  MAG_Bus MAG;                         /* '<Root>/MAG' */
  Barometer_Bus Barometer;             /* '<Root>/Barometer' */
  GPS_uBlox_Bus GPS_uBlox;             /* '<Root>/GPS_uBlox' */
  Rangefinder_Bus Rangefinder;         /* '<Root>/Rangefinder' */
  Optical_Flow_Bus Optical_Flow;       /* '<Root>/Optical_Flow' */
  AirSpeed_Bus AirSpeed;               /* '<Root>/AirSpeed' */
  External_Pos_Bus External_Pos;       /* '<Root>/External_Pos' */
} ExternalInputs_INS_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  INS_Out_Bus INS_Out;                 /* '<Root>/INS_Out' */
} ExternalOutputs_INS_T;

/* Parameters for system: '<S308>/Baro_Velocity' */
struct rtP_Baro_Velocity_INS_T_ {
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S313>/Constant'
                                        */
};

/* Parameters for system: '<S308>/Baro_Velocity' */
typedef struct rtP_Baro_Velocity_INS_T_ rtP_Baro_Velocity_INS_T;

/* Parameters (default storage) */
struct Parameters_INS_T_ {
  struct_Gsh1YUlqR57cYRpVuxG74E INS_CONST;/* Variable: INS_CONST
                                           * Referenced by:
                                           *   '<S463>/Declination_Lookup_Table'
                                           *   '<S463>/Inclination_Lookup_Table'
                                           *   '<S463>/Magnitude_Lookup_Table'
                                           *   '<S69>/Constant'
                                           *   '<S305>/Constant1'
                                           */
  real_T WMM_LUT_resolution;           /* Mask Parameter: WMM_LUT_resolution
                                        * Referenced by: '<S463>/rad_to_index'
                                        */
  int32_T valid_samples_const;         /* Mask Parameter: valid_samples_const
                                        * Referenced by: '<S444>/Constant'
                                        */
  real32_T Sensor_Valid_acc_max;       /* Mask Parameter: Sensor_Valid_acc_max
                                        * Referenced by: '<S456>/Upper Limit'
                                        */
  real32_T Sensor_Valid_acc_min;       /* Mask Parameter: Sensor_Valid_acc_min
                                        * Referenced by: '<S456>/Lower Limit'
                                        */
  real32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S96>/Constant'
                                        */
  real32_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S100>/Constant'
                                        */
  real32_T CompareToConstant_const_h;  /* Mask Parameter: CompareToConstant_const_h
                                        * Referenced by: '<S109>/Constant'
                                        */
  real32_T CompareToConstant_const_n;  /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S117>/Constant'
                                        */
  real32_T CompareToConstant_const_p;  /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S141>/Constant'
                                        */
  real32_T CompareToConstant1_const_o; /* Mask Parameter: CompareToConstant1_const_o
                                        * Referenced by: '<S142>/Constant'
                                        */
  real32_T CompareToConstant_const_hd; /* Mask Parameter: CompareToConstant_const_hd
                                        * Referenced by: '<S302>/Constant'
                                        */
  real32_T DeadZone_dz;                /* Mask Parameter: DeadZone_dz
                                        * Referenced by:
                                        *   '<S479>/Dead Zone'
                                        *   '<S479>/Gain'
                                        */
  real32_T Sensor_Valid_gyr_max;       /* Mask Parameter: Sensor_Valid_gyr_max
                                        * Referenced by: '<S457>/Upper Limit'
                                        */
  real32_T Sensor_Valid_gyr_min;       /* Mask Parameter: Sensor_Valid_gyr_min
                                        * Referenced by: '<S457>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit;      /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S146>/Lower Limit'
                                        */
  real32_T Sensor_Valid_mag_max;       /* Mask Parameter: Sensor_Valid_mag_max
                                        * Referenced by: '<S476>/Upper Limit'
                                        */
  real32_T Sensor_Valid_mag_min;       /* Mask Parameter: Sensor_Valid_mag_min
                                        * Referenced by: '<S476>/Lower Limit'
                                        */
  real32_T Sensor_Valid_max_alt;       /* Mask Parameter: Sensor_Valid_max_alt
                                        * Referenced by:
                                        *   '<S488>/Relay'
                                        *   '<S494>/Upper Limit'
                                        */
  real32_T Sensor_Valid_max_pressure;  /* Mask Parameter: Sensor_Valid_max_pressure
                                        * Referenced by: '<S423>/Upper Limit'
                                        */
  real32_T Sensor_Valid_max_temp;      /* Mask Parameter: Sensor_Valid_max_temp
                                        * Referenced by: '<S424>/Upper Limit'
                                        */
  real32_T Sensor_Valid_max_vel;       /* Mask Parameter: Sensor_Valid_max_vel
                                        * Referenced by:
                                        *   '<S486>/Upper Limit'
                                        *   '<S487>/Upper Limit'
                                        */
  real32_T Sensor_Valid_min_alt;       /* Mask Parameter: Sensor_Valid_min_alt
                                        * Referenced by: '<S494>/Lower Limit'
                                        */
  real32_T Sensor_Valid_min_pressure;  /* Mask Parameter: Sensor_Valid_min_pressure
                                        * Referenced by: '<S423>/Lower Limit'
                                        */
  real32_T Sensor_Valid_min_temp;      /* Mask Parameter: Sensor_Valid_min_temp
                                        * Referenced by: '<S424>/Lower Limit'
                                        */
  real32_T Sensor_Valid_min_vel;       /* Mask Parameter: Sensor_Valid_min_vel
                                        * Referenced by:
                                        *   '<S486>/Lower Limit'
                                        *   '<S487>/Lower Limit'
                                        */
  real32_T valid_check2_time_out;      /* Mask Parameter: valid_check2_time_out
                                        * Referenced by: '<S23>/Constant'
                                        */
  real32_T valid_check5_time_out;      /* Mask Parameter: valid_check5_time_out
                                        * Referenced by: '<S38>/Constant'
                                        */
  real32_T valid_check8_time_out;      /* Mask Parameter: valid_check8_time_out
                                        * Referenced by: '<S48>/Constant'
                                        */
  real32_T valid_check1_time_out;      /* Mask Parameter: valid_check1_time_out
                                        * Referenced by: '<S18>/Constant'
                                        */
  real32_T valid_check3_time_out;      /* Mask Parameter: valid_check3_time_out
                                        * Referenced by: '<S28>/Constant'
                                        */
  real32_T valid_check4_time_out;      /* Mask Parameter: valid_check4_time_out
                                        * Referenced by: '<S33>/Constant'
                                        */
  real32_T valid_check6_time_out;      /* Mask Parameter: valid_check6_time_out
                                        * Referenced by: '<S43>/Constant'
                                        */
  real32_T valid_hold1_time_out;       /* Mask Parameter: valid_hold1_time_out
                                        * Referenced by: '<S372>/Constant'
                                        */
  real32_T valid_hold1_time_out_m;     /* Mask Parameter: valid_hold1_time_out_m
                                        * Referenced by: '<S385>/Constant'
                                        */
  real32_T valid_hold_time_out;        /* Mask Parameter: valid_hold_time_out
                                        * Referenced by: '<S367>/Constant'
                                        */
  real32_T valid_hold_time_out_d;      /* Mask Parameter: valid_hold_time_out_d
                                        * Referenced by: '<S380>/Constant'
                                        */
  real32_T valid_hold2_time_out;       /* Mask Parameter: valid_hold2_time_out
                                        * Referenced by: '<S390>/Constant'
                                        */
  real32_T IntervalTest_uplimit;       /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S146>/Upper Limit'
                                        */
  uint32_T xyvalid_BitMask;            /* Mask Parameter: xyvalid_BitMask
                                        * Referenced by: '<S426>/xy valid'
                                        */
  uint32_T heightvalid_BitMask;        /* Mask Parameter: heightvalid_BitMask
                                        * Referenced by: '<S426>/height valid'
                                        */
  uint32_T headingvalid_BitMask;       /* Mask Parameter: headingvalid_BitMask
                                        * Referenced by: '<S426>/heading valid'
                                        */
  uint32_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S101>/Constant'
                                        */
  uint32_T valid_samples_const_k;      /* Mask Parameter: valid_samples_const_k
                                        * Referenced by: '<S155>/Constant'
                                        */
  uint32_T valid_samples_const_g;      /* Mask Parameter: valid_samples_const_g
                                        * Referenced by: '<S156>/Constant'
                                        */
  uint32_T CompareToConstant_const_nb; /* Mask Parameter: CompareToConstant_const_nb
                                        * Referenced by: '<S417>/Constant'
                                        */
  uint32_T CompareToConstant4_const_e; /* Mask Parameter: CompareToConstant4_const_e
                                        * Referenced by: '<S445>/Constant'
                                        */
  uint32_T CompareToConstant_const_d;  /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S441>/Constant'
                                        */
  uint32_T CompareToConstant_const_m;  /* Mask Parameter: CompareToConstant_const_m
                                        * Referenced by: '<S495>/Constant'
                                        */
  uint32_T IntervalTest3_lowlimit;     /* Mask Parameter: IntervalTest3_lowlimit
                                        * Referenced by: '<S419>/Lower Limit'
                                        */
  uint32_T Sensor_Valid_timeout;       /* Mask Parameter: Sensor_Valid_timeout
                                        * Referenced by: '<S420>/Constant'
                                        */
  uint32_T Sensor_Valid_timeout_e;     /* Mask Parameter: Sensor_Valid_timeout_e
                                        * Referenced by: '<S427>/Constant'
                                        */
  uint32_T Sensor_Valid_timeout_a;     /* Mask Parameter: Sensor_Valid_timeout_a
                                        * Referenced by: '<S453>/Constant'
                                        */
  uint32_T Sensor_Valid_timeout_b;     /* Mask Parameter: Sensor_Valid_timeout_b
                                        * Referenced by: '<S473>/Constant'
                                        */
  uint32_T Sensor_Valid_timeout_ai;    /* Mask Parameter: Sensor_Valid_timeout_ai
                                        * Referenced by: '<S483>/Constant'
                                        */
  uint32_T Sensor_Valid_timeout_p;     /* Mask Parameter: Sensor_Valid_timeout_p
                                        * Referenced by: '<S491>/Constant'
                                        */
  uint32_T IntervalTest3_uplimit;      /* Mask Parameter: IntervalTest3_uplimit
                                        * Referenced by: '<S419>/Upper Limit'
                                        */
  uint32_T DetectChange_vinit;         /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S220>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_i;       /* Mask Parameter: DetectChange_vinit_i
                                        * Referenced by: '<S229>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_l;       /* Mask Parameter: DetectChange_vinit_l
                                        * Referenced by: '<S242>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_m;       /* Mask Parameter: DetectChange_vinit_m
                                        * Referenced by: '<S263>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_j;       /* Mask Parameter: DetectChange_vinit_j
                                        * Referenced by: '<S272>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_h;       /* Mask Parameter: DetectChange_vinit_h
                                        * Referenced by: '<S281>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_g;       /* Mask Parameter: DetectChange_vinit_g
                                        * Referenced by: '<S293>/Delay Input1'
                                        */
  uint32_T DetectIncrease_vinit;       /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S303>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_d;       /* Mask Parameter: DetectChange_vinit_d
                                        * Referenced by: '<S418>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_n;       /* Mask Parameter: DetectChange_vinit_n
                                        * Referenced by: '<S421>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_lj;      /* Mask Parameter: DetectChange_vinit_lj
                                        * Referenced by: '<S428>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_e;       /* Mask Parameter: DetectChange_vinit_e
                                        * Referenced by: '<S446>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_md;      /* Mask Parameter: DetectChange_vinit_md
                                        * Referenced by: '<S454>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_lp;      /* Mask Parameter: DetectChange_vinit_lp
                                        * Referenced by: '<S474>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_ju;      /* Mask Parameter: DetectChange_vinit_ju
                                        * Referenced by: '<S484>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_c;       /* Mask Parameter: DetectChange_vinit_c
                                        * Referenced by: '<S492>/Delay Input1'
                                        */
  boolean_T CompareToConstant1_const_m;/* Mask Parameter: CompareToConstant1_const_m
                                        * Referenced by: '<S24>/Constant'
                                        */
  boolean_T CompareToConstant1_const_j;/* Mask Parameter: CompareToConstant1_const_j
                                        * Referenced by: '<S39>/Constant'
                                        */
  boolean_T CompareToConstant1_const_g;/* Mask Parameter: CompareToConstant1_const_g
                                        * Referenced by: '<S49>/Constant'
                                        */
  boolean_T CompareToConstant1_const_e;/* Mask Parameter: CompareToConstant1_const_e
                                        * Referenced by: '<S19>/Constant'
                                        */
  boolean_T CompareToConstant1_const_ei;/* Mask Parameter: CompareToConstant1_const_ei
                                         * Referenced by: '<S29>/Constant'
                                         */
  boolean_T CompareToConstant1_const_ec;/* Mask Parameter: CompareToConstant1_const_ec
                                         * Referenced by: '<S34>/Constant'
                                         */
  boolean_T CompareToConstant1_const_em;/* Mask Parameter: CompareToConstant1_const_em
                                         * Referenced by: '<S44>/Constant'
                                         */
  boolean_T CompareToConstant2_const;  /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S20>/Constant'
                                        */
  boolean_T CompareToConstant2_const_c;/* Mask Parameter: CompareToConstant2_const_c
                                        * Referenced by: '<S25>/Constant'
                                        */
  boolean_T CompareToConstant2_const_n;/* Mask Parameter: CompareToConstant2_const_n
                                        * Referenced by: '<S30>/Constant'
                                        */
  boolean_T CompareToConstant2_const_b;/* Mask Parameter: CompareToConstant2_const_b
                                        * Referenced by: '<S35>/Constant'
                                        */
  boolean_T CompareToConstant2_const_i;/* Mask Parameter: CompareToConstant2_const_i
                                        * Referenced by: '<S40>/Constant'
                                        */
  boolean_T CompareToConstant2_const_l;/* Mask Parameter: CompareToConstant2_const_l
                                        * Referenced by: '<S45>/Constant'
                                        */
  boolean_T CompareToConstant2_const_i1;/* Mask Parameter: CompareToConstant2_const_i1
                                         * Referenced by: '<S50>/Constant'
                                         */
  boolean_T CompareToConstant1_const_i;/* Mask Parameter: CompareToConstant1_const_i
                                        * Referenced by: '<S373>/Constant'
                                        */
  boolean_T CompareToConstant2_const_j;/* Mask Parameter: CompareToConstant2_const_j
                                        * Referenced by: '<S374>/Constant'
                                        */
  boolean_T CompareToConstant1_const_a;/* Mask Parameter: CompareToConstant1_const_a
                                        * Referenced by: '<S386>/Constant'
                                        */
  boolean_T CompareToConstant2_const_d;/* Mask Parameter: CompareToConstant2_const_d
                                        * Referenced by: '<S387>/Constant'
                                        */
  boolean_T CompareToConstant1_const_h;/* Mask Parameter: CompareToConstant1_const_h
                                        * Referenced by: '<S368>/Constant'
                                        */
  boolean_T CompareToConstant2_const_a;/* Mask Parameter: CompareToConstant2_const_a
                                        * Referenced by: '<S369>/Constant'
                                        */
  boolean_T CompareToConstant1_const_hv;/* Mask Parameter: CompareToConstant1_const_hv
                                         * Referenced by: '<S381>/Constant'
                                         */
  boolean_T CompareToConstant2_const_dj;/* Mask Parameter: CompareToConstant2_const_dj
                                         * Referenced by: '<S382>/Constant'
                                         */
  boolean_T CompareToConstant1_const_l;/* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S391>/Constant'
                                        */
  boolean_T CompareToConstant2_const_h;/* Mask Parameter: CompareToConstant2_const_h
                                        * Referenced by: '<S392>/Constant'
                                        */
  boolean_T DetectRisePositive_vinit;  /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S21>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_c;/* Mask Parameter: DetectRisePositive_vinit_c
                                        * Referenced by: '<S26>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_m;/* Mask Parameter: DetectRisePositive_vinit_m
                                        * Referenced by: '<S31>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_k;/* Mask Parameter: DetectRisePositive_vinit_k
                                        * Referenced by: '<S36>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_a;/* Mask Parameter: DetectRisePositive_vinit_a
                                        * Referenced by: '<S41>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_f;/* Mask Parameter: DetectRisePositive_vinit_f
                                        * Referenced by: '<S46>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_l;/* Mask Parameter: DetectRisePositive_vinit_l
                                        * Referenced by: '<S51>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_b;    /* Mask Parameter: DetectIncrease_vinit_b
                                        * Referenced by: '<S92>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_d;    /* Mask Parameter: DetectIncrease_vinit_d
                                        * Referenced by: '<S107>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_fc;/* Mask Parameter: DetectRisePositive_vinit_fc
                                         * Referenced by: '<S143>/Delay Input1'
                                         */
  boolean_T DetectRisePositive1_vinit; /* Mask Parameter: DetectRisePositive1_vinit
                                        * Referenced by: '<S144>/Delay Input1'
                                        */
  boolean_T DetectRisePositive1_vinit_b;/* Mask Parameter: DetectRisePositive1_vinit_b
                                         * Referenced by: '<S153>/Delay Input1'
                                         */
  boolean_T DetectIncrease_vinit_m;    /* Mask Parameter: DetectIncrease_vinit_m
                                        * Referenced by: '<S227>/Delay Input1'
                                        */
  boolean_T DetectChange_vinit_c3;     /* Mask Parameter: DetectChange_vinit_c3
                                        * Referenced by: '<S239>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_p;    /* Mask Parameter: DetectIncrease_vinit_p
                                        * Referenced by: '<S240>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_c;    /* Mask Parameter: DetectIncrease_vinit_c
                                        * Referenced by: '<S270>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_j;    /* Mask Parameter: DetectIncrease_vinit_j
                                        * Referenced by: '<S279>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_ji;   /* Mask Parameter: DetectIncrease_vinit_ji
                                        * Referenced by: '<S291>/Delay Input1'
                                        */
  boolean_T DetectChange_vinit_f;      /* Mask Parameter: DetectChange_vinit_f
                                        * Referenced by: '<S290>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_a;    /* Mask Parameter: DetectIncrease_vinit_a
                                        * Referenced by: '<S300>/Delay Input1'
                                        */
  boolean_T DetectDecrease_vinit;      /* Mask Parameter: DetectDecrease_vinit
                                        * Referenced by: '<S346>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_me;/* Mask Parameter: DetectRisePositive_vinit_me
                                         * Referenced by: '<S359>/Delay Input1'
                                         */
  boolean_T DetectRisePositive_vinit_o;/* Mask Parameter: DetectRisePositive_vinit_o
                                        * Referenced by: '<S375>/Delay Input1'
                                        */
  boolean_T DetectRisePositive1_vinit_h;/* Mask Parameter: DetectRisePositive1_vinit_h
                                         * Referenced by: '<S360>/Delay Input1'
                                         */
  boolean_T DetectRisePositive_vinit_h;/* Mask Parameter: DetectRisePositive_vinit_h
                                        * Referenced by: '<S388>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_d;/* Mask Parameter: DetectRisePositive_vinit_d
                                        * Referenced by: '<S370>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_dn;/* Mask Parameter: DetectRisePositive_vinit_dn
                                         * Referenced by: '<S383>/Delay Input1'
                                         */
  boolean_T DetectRisePositive_vinit_cj;/* Mask Parameter: DetectRisePositive_vinit_cj
                                         * Referenced by: '<S393>/Delay Input1'
                                         */
  boolean_T DetectRisePositive3_vinit; /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S399>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit_h;/* Mask Parameter: DetectRisePositive3_vinit_h
                                         * Referenced by: '<S401>/Delay Input1'
                                         */
  uint8_T CompareToConstant_const_l;   /* Mask Parameter: CompareToConstant_const_l
                                        * Referenced by: '<S355>/Constant'
                                        */
  uint8_T CompareToConstant1_const_n;  /* Mask Parameter: CompareToConstant1_const_n
                                        * Referenced by: '<S442>/Constant'
                                        */
  uint8_T CompareToConstant_const_i;   /* Mask Parameter: CompareToConstant_const_i
                                        * Referenced by: '<S430>/Constant'
                                        */
  uint8_T CompareToConstant1_const_la; /* Mask Parameter: CompareToConstant1_const_la
                                        * Referenced by: '<S431>/Constant'
                                        */
  uint8_T CompareToConstant2_const_bv; /* Mask Parameter: CompareToConstant2_const_bv
                                        * Referenced by: '<S435>/Constant'
                                        */
  uint8_T Sensor_Valid_q_high;         /* Mask Parameter: Sensor_Valid_q_high
                                        * Referenced by: '<S478>/Relay'
                                        */
  uint8_T Sensor_Valid_q_low;          /* Mask Parameter: Sensor_Valid_q_low
                                        * Referenced by: '<S478>/Relay'
                                        */
  uint8_T DetectIncrease_vinit_dy;     /* Mask Parameter: DetectIncrease_vinit_dy
                                        * Referenced by: '<S347>/Delay Input1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10e7
                                        * Referenced by: '<S213>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 1e-6
                                        * Referenced by: '<S213>/Saturation'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S213>/Constant'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S397>/Delay1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S398>/Delay'
                                        */
  real_T Delay1_InitialCondition_e;    /* Expression: 0.0
                                        * Referenced by: '<S398>/Delay1'
                                        */
  real_T lon_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S434>/lon_0_rad'
                                        */
  real_T lat_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S434>/lat_0_rad'
                                        */
  real_T dx_dlat_Y0;                   /* Expression: 1
                                        * Referenced by: '<S434>/dx_dlat'
                                        */
  real_T dy_dlon_Y0;                   /* Expression: 1
                                        * Referenced by: '<S434>/dy_dlon'
                                        */
  real_T dz_dh_Y0;                     /* Expression: 1
                                        * Referenced by: '<S434>/dz_dh'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S450>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S450>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 2
                                        * Referenced by: '<S450>/Constant2'
                                        */
  real_T R_Value;                      /* Expression: 6378137
                                        * Referenced by: '<S450>/R'
                                        */
  real_T f_Value;                      /* Expression: 1/298.257223563
                                        * Referenced by: '<S450>/f'
                                        */
  int32_T UnitDelay_InitialCondition;  /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S443>/Unit Delay'
                                        */
  int32_T Saturation_UpperSat_a;       /* Computed Parameter: Saturation_UpperSat_a
                                        * Referenced by: '<S443>/Saturation'
                                        */
  int32_T Saturation_LowerSat_f;       /* Computed Parameter: Saturation_LowerSat_f
                                        * Referenced by: '<S443>/Saturation'
                                        */
  int32_T offset_Value[2];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S463>/offset'
                                        */
  int32_T Saturation1_UpperSat[2];     /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S463>/Saturation1'
                                        */
  int32_T Saturation1_LowerSat;        /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S463>/Saturation1'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S432>/Gain'
                                        */
  int32_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S432>/Gain1'
                                        */
  int32_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S432>/Gain2'
                                        */
  int32_T Scalefactor3_Gain;           /* Computed Parameter: Scalefactor3_Gain
                                        * Referenced by: '<S432>/Scalefactor3'
                                        */
  int32_T Scalefactor1_Gain;           /* Computed Parameter: Scalefactor1_Gain
                                        * Referenced by: '<S432>/Scalefactor1'
                                        */
  int32_T Scalefactor2_Gain;           /* Computed Parameter: Scalefactor2_Gain
                                        * Referenced by: '<S432>/Scalefactor2'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<S12>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S12>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperSat;/* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                                            * Referenced by: '<S12>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerSat;/* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                                            * Referenced by: '<S12>/Discrete-Time Integrator'
                                            */
  real32_T Gain10_Gain;                /* Computed Parameter: Gain10_Gain
                                        * Referenced by: '<S8>/Gain10'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_i;/* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                                            * Referenced by: '<S15>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_i;/* Computed Parameter: DiscreteTimeIntegrator_IC_i
                                        * Referenced by: '<S15>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_g;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_g
                                            * Referenced by: '<S15>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_j;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_j
                                            * Referenced by: '<S15>/Discrete-Time Integrator'
                                            */
  real32_T Relay_OnVal;                /* Computed Parameter: Relay_OnVal
                                        * Referenced by: '<S9>/Relay'
                                        */
  real32_T Relay_OffVal;               /* Computed Parameter: Relay_OffVal
                                        * Referenced by: '<S9>/Relay'
                                        */
  real32_T Relay_YOn;                  /* Computed Parameter: Relay_YOn
                                        * Referenced by: '<S9>/Relay'
                                        */
  real32_T Relay_YOff;                 /* Computed Parameter: Relay_YOff
                                        * Referenced by: '<S9>/Relay'
                                        */
  real32_T Relay1_OnVal;               /* Computed Parameter: Relay1_OnVal
                                        * Referenced by: '<S9>/Relay1'
                                        */
  real32_T Relay1_OffVal;              /* Computed Parameter: Relay1_OffVal
                                        * Referenced by: '<S9>/Relay1'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_m;/* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                            * Referenced by: '<S17>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_o;/* Computed Parameter: DiscreteTimeIntegrator_IC_o
                                        * Referenced by: '<S17>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_d;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_d
                                            * Referenced by: '<S17>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_n;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_n
                                            * Referenced by: '<S17>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_k;/* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                            * Referenced by: '<S11>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_l;/* Computed Parameter: DiscreteTimeIntegrator_IC_l
                                        * Referenced by: '<S11>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_n;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_n
                                            * Referenced by: '<S11>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_l;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_l
                                            * Referenced by: '<S11>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_p;/* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                            * Referenced by: '<S13>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_j;/* Computed Parameter: DiscreteTimeIntegrator_IC_j
                                        * Referenced by: '<S13>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_f;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_f
                                            * Referenced by: '<S13>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_f;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_f
                                            * Referenced by: '<S13>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainv_me;/* Computed Parameter: DiscreteTimeIntegrator_gainv_me
                                            * Referenced by: '<S14>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_ig;/* Computed Parameter: DiscreteTimeIntegrator_IC_ig
                                         * Referenced by: '<S14>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_UpperS_m;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_m
                                            * Referenced by: '<S14>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_i;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_i
                                            * Referenced by: '<S14>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainv_my;/* Computed Parameter: DiscreteTimeIntegrator_gainv_my
                                            * Referenced by: '<S16>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_e;/* Computed Parameter: DiscreteTimeIntegrator_IC_e
                                        * Referenced by: '<S16>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_Upper_ml;/* Computed Parameter: DiscreteTimeIntegrator_Upper_ml
                                            * Referenced by: '<S16>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_g;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_g
                                            * Referenced by: '<S16>/Discrete-Time Integrator'
                                            */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S53>/Constant'
                                        */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S54>/Constant'
                                        */
  real32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S64>/Constant'
                                        */
  real32_T Saturation_UpperSat_h;      /* Computed Parameter: Saturation_UpperSat_h
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real32_T Saturation_LowerSat_m;      /* Computed Parameter: Saturation_LowerSat_m
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real32_T Constant1_Value_o;          /* Computed Parameter: Constant1_Value_o
                                        * Referenced by: '<S64>/Constant1'
                                        */
  real32_T Constant2_Value_d;          /* Computed Parameter: Constant2_Value_d
                                        * Referenced by: '<S64>/Constant2'
                                        */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S63>/Gain'
                                        */
  real32_T Constant_Value_j1;          /* Computed Parameter: Constant_Value_j1
                                        * Referenced by: '<S67>/Constant'
                                        */
  real32_T Constant1_Value_j;          /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S67>/Constant1'
                                        */
  real32_T Constant2_Value_a;          /* Computed Parameter: Constant2_Value_a
                                        * Referenced by: '<S67>/Constant2'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S67>/Constant3'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S67>/Constant4'
                                        */
  real32_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S67>/Gain'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S83>/Constant'
                                        */
  real32_T Constant_Value_jy;          /* Computed Parameter: Constant_Value_jy
                                        * Referenced by: '<S84>/Constant'
                                        */
  real32_T gps_acc_O_mPs2_Y0;          /* Computed Parameter: gps_acc_O_mPs2_Y0
                                        * Referenced by: '<S93>/gps_acc_O_mPs2'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S93>/Integrator'
                                        */
  real32_T Integrator_IC;              /* Computed Parameter: Integrator_IC
                                        * Referenced by: '<S93>/Integrator'
                                        */
  real32_T Integrator1_gainval;        /* Computed Parameter: Integrator1_gainval
                                        * Referenced by: '<S93>/Integrator1'
                                        */
  real32_T gain_Gain;                  /* Computed Parameter: gain_Gain
                                        * Referenced by: '<S93>/gain'
                                        */
  real32_T gain1_Gain;                 /* Computed Parameter: gain1_Gain
                                        * Referenced by: '<S93>/gain1'
                                        */
  real32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S95>/Constant'
                                        */
  real32_T Constant_Value_ny;          /* Computed Parameter: Constant_Value_ny
                                        * Referenced by: '<S99>/Constant'
                                        */
  real32_T Constant_Value_g3;          /* Computed Parameter: Constant_Value_g3
                                        * Referenced by: '<S90>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                            * Referenced by: '<S90>/Discrete-Time Integrator1'
                                            */
  real32_T Relay_OnVal_j;              /* Computed Parameter: Relay_OnVal_j
                                        * Referenced by: '<S94>/Relay'
                                        */
  real32_T Relay_OffVal_i;             /* Computed Parameter: Relay_OffVal_i
                                        * Referenced by: '<S94>/Relay'
                                        */
  real32_T Relay_YOn_m;                /* Computed Parameter: Relay_YOn_m
                                        * Referenced by: '<S94>/Relay'
                                        */
  real32_T Relay_YOff_n;               /* Computed Parameter: Relay_YOff_n
                                        * Referenced by: '<S94>/Relay'
                                        */
  real32_T Delay_InitialCondition_m;   /* Computed Parameter: Delay_InitialCondition_m
                                        * Referenced by: '<S88>/Delay'
                                        */
  real32_T gravity_Value[3];           /* Expression: [0;0;-INS_CONST.g]
                                        * Referenced by: '<S75>/gravity'
                                        */
  real32_T Gain1_Gain_l;               /* Computed Parameter: Gain1_Gain_l
                                        * Referenced by: '<S76>/Gain1'
                                        */
  real32_T Gain2_Gain_i;               /* Computed Parameter: Gain2_Gain_i
                                        * Referenced by: '<S76>/Gain2'
                                        */
  real32_T DeadZone2_Start;            /* Computed Parameter: DeadZone2_Start
                                        * Referenced by: '<S76>/Dead Zone2'
                                        */
  real32_T DeadZone2_End;              /* Computed Parameter: DeadZone2_End
                                        * Referenced by: '<S76>/Dead Zone2'
                                        */
  real32_T Saturation_UpperSat_k;      /* Computed Parameter: Saturation_UpperSat_k
                                        * Referenced by: '<S76>/Saturation'
                                        */
  real32_T Saturation_LowerSat_k;      /* Computed Parameter: Saturation_LowerSat_k
                                        * Referenced by: '<S76>/Saturation'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S83>/Switch'
                                        */
  real32_T Switch_Threshold_m;         /* Computed Parameter: Switch_Threshold_m
                                        * Referenced by: '<S84>/Switch'
                                        */
  real32_T max_Value;                  /* Computed Parameter: max_Value
                                        * Referenced by: '<S82>/max'
                                        */
  real32_T Saturation_UpperSat_e;      /* Computed Parameter: Saturation_UpperSat_e
                                        * Referenced by: '<S82>/Saturation'
                                        */
  real32_T Saturation_LowerSat_fo;     /* Computed Parameter: Saturation_LowerSat_fo
                                        * Referenced by: '<S82>/Saturation'
                                        */
  real32_T Constant1_Value_n;          /* Computed Parameter: Constant1_Value_n
                                        * Referenced by: '<S82>/Constant1'
                                        */
  real32_T Gain2_Gain_m;               /* Computed Parameter: Gain2_Gain_m
                                        * Referenced by: '<S77>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_n;/* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                                            * Referenced by: '<S90>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_a;/* Computed Parameter: DiscreteTimeIntegrator_IC_a
                                        * Referenced by: '<S90>/Discrete-Time Integrator'
                                        */
  real32_T Gain_Gain_p;                /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S90>/Gain'
                                        */
  real32_T Gain1_Gain_p;               /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S90>/Gain1'
                                        */
  real32_T Gain_Gain_m[3];             /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S71>/Gain'
                                        */
  real32_T Constant_Value_as[2];       /* Computed Parameter: Constant_Value_as
                                        * Referenced by: '<S72>/Constant'
                                        */
  real32_T Constant_Value_g5;          /* Computed Parameter: Constant_Value_g5
                                        * Referenced by: '<S108>/Constant'
                                        */
  real32_T Gain_Gain_pq;               /* Computed Parameter: Gain_Gain_pq
                                        * Referenced by: '<S105>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_h;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_h
                                            * Referenced by: '<S108>/Discrete-Time Integrator1'
                                            */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S102>/Constant'
                                        */
  real32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S103>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_k;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_k
                                            * Referenced by: '<S103>/Discrete-Time Integrator1'
                                            */
  real32_T Delay_InitialCondition_i;   /* Computed Parameter: Delay_InitialCondition_i
                                        * Referenced by: '<S104>/Delay'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_b;/* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                            * Referenced by: '<S103>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_h;/* Computed Parameter: DiscreteTimeIntegrator_IC_h
                                        * Referenced by: '<S103>/Discrete-Time Integrator'
                                        */
  real32_T Gain_Gain_i;                /* Computed Parameter: Gain_Gain_i
                                        * Referenced by: '<S103>/Gain'
                                        */
  real32_T Gain1_Gain_o;               /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S103>/Gain1'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_d;/* Computed Parameter: DiscreteTimeIntegrator_gainva_d
                                            * Referenced by: '<S108>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_ip;/* Computed Parameter: DiscreteTimeIntegrator_IC_ip
                                         * Referenced by: '<S108>/Discrete-Time Integrator'
                                         */
  real32_T Gain_Gain_l;                /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S108>/Gain'
                                        */
  real32_T Gain1_Gain_b;               /* Computed Parameter: Gain1_Gain_b
                                        * Referenced by: '<S108>/Gain1'
                                        */
  real32_T Constant_Value_no;          /* Computed Parameter: Constant_Value_no
                                        * Referenced by: '<S118>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_j;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_j
                                            * Referenced by: '<S118>/Discrete-Time Integrator1'
                                            */
  real32_T Saturation2_UpperSat;       /* Computed Parameter: Saturation2_UpperSat
                                        * Referenced by: '<S69>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat;       /* Computed Parameter: Saturation2_LowerSat
                                        * Referenced by: '<S69>/Saturation2'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_kw;/* Computed Parameter: DiscreteTimeIntegrator_gainv_kw
                                            * Referenced by: '<S118>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_m;/* Computed Parameter: DiscreteTimeIntegrator_IC_m
                                        * Referenced by: '<S118>/Discrete-Time Integrator'
                                        */
  real32_T Gain_Gain_ib;               /* Computed Parameter: Gain_Gain_ib
                                        * Referenced by: '<S118>/Gain'
                                        */
  real32_T Gain1_Gain_i;               /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S118>/Gain1'
                                        */
  real32_T Constant_Value_pu;          /* Computed Parameter: Constant_Value_pu
                                        * Referenced by: '<S120>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                            * Referenced by: '<S122>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC; /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                        * Referenced by: '<S122>/Discrete-Time Integrator2'
                                        */
  real32_T DiscreteTimeIntegrator2_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
                                            * Referenced by: '<S122>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
                                            * Referenced by: '<S122>/Discrete-Time Integrator2'
                                            */
  real32_T Gain1_Gain_e;               /* Computed Parameter: Gain1_Gain_e
                                        * Referenced by: '<S120>/Gain1'
                                        */
  real32_T dT_Gain;                    /* Expression: INS_CONST.dt
                                        * Referenced by: '<S120>/dT'
                                        */
  real32_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S132>/Gain'
                                        */
  real32_T Gain1_Gain_pl;              /* Computed Parameter: Gain1_Gain_pl
                                        * Referenced by: '<S132>/Gain1'
                                        */
  real32_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S133>/Gain'
                                        */
  real32_T Gain1_Gain_b3;              /* Computed Parameter: Gain1_Gain_b3
                                        * Referenced by: '<S133>/Gain1'
                                        */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S134>/Gain'
                                        */
  real32_T Gain1_Gain_f;               /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<S134>/Gain1'
                                        */
  real32_T Delay1_InitialCondition_h;  /* Computed Parameter: Delay1_InitialCondition_h
                                        * Referenced by: '<S57>/Delay1'
                                        */
  real32_T Delay2_InitialCondition;    /* Computed Parameter: Delay2_InitialCondition
                                        * Referenced by: '<S57>/Delay2'
                                        */
  real32_T Constant_Value_c0;          /* Computed Parameter: Constant_Value_c0
                                        * Referenced by: '<S170>/Constant'
                                        */
  real32_T Gain_Gain_eu;               /* Computed Parameter: Gain_Gain_eu
                                        * Referenced by: '<S170>/Gain'
                                        */
  real32_T Gain1_Gain_h;               /* Computed Parameter: Gain1_Gain_h
                                        * Referenced by: '<S170>/Gain1'
                                        */
  real32_T Constant2_Value_az[2];      /* Computed Parameter: Constant2_Value_az
                                        * Referenced by: '<S183>/Constant2'
                                        */
  real32_T Constant1_Value_e;          /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S183>/Constant1'
                                        */
  real32_T Constant_Value_ae;          /* Computed Parameter: Constant_Value_ae
                                        * Referenced by: '<S184>/Constant'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S172>/Gain'
                                        */
  real32_T Gain1_Gain_g;               /* Computed Parameter: Gain1_Gain_g
                                        * Referenced by: '<S172>/Gain1'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S172>/Gain3'
                                        */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S172>/Gain4'
                                        */
  real32_T Constant2_Value_o[2];       /* Computed Parameter: Constant2_Value_o
                                        * Referenced by: '<S188>/Constant2'
                                        */
  real32_T Constant1_Value_l;          /* Computed Parameter: Constant1_Value_l
                                        * Referenced by: '<S188>/Constant1'
                                        */
  real32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S189>/Constant'
                                        */
  real32_T Gain_Gain_lj;               /* Computed Parameter: Gain_Gain_lj
                                        * Referenced by: '<S173>/Gain'
                                        */
  real32_T Gain1_Gain_m;               /* Computed Parameter: Gain1_Gain_m
                                        * Referenced by: '<S173>/Gain1'
                                        */
  real32_T Gain2_Gain_o;               /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S173>/Gain2'
                                        */
  real32_T Gain3_Gain_e;               /* Computed Parameter: Gain3_Gain_e
                                        * Referenced by: '<S173>/Gain3'
                                        */
  real32_T Constant2_Value_m[2];       /* Computed Parameter: Constant2_Value_m
                                        * Referenced by: '<S178>/Constant2'
                                        */
  real32_T Constant1_Value_a;          /* Computed Parameter: Constant1_Value_a
                                        * Referenced by: '<S178>/Constant1'
                                        */
  real32_T Constant_Value_hd;          /* Computed Parameter: Constant_Value_hd
                                        * Referenced by: '<S179>/Constant'
                                        */
  real32_T Gain_Gain_g;                /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S171>/Gain'
                                        */
  real32_T Gain1_Gain_ig;              /* Computed Parameter: Gain1_Gain_ig
                                        * Referenced by: '<S171>/Gain1'
                                        */
  real32_T Gain2_Gain_mx;              /* Computed Parameter: Gain2_Gain_mx
                                        * Referenced by: '<S171>/Gain2'
                                        */
  real32_T Gain3_Gain_ea;              /* Computed Parameter: Gain3_Gain_ea
                                        * Referenced by: '<S171>/Gain3'
                                        */
  real32_T Constant_Value_d1;          /* Computed Parameter: Constant_Value_d1
                                        * Referenced by: '<S194>/Constant'
                                        */
  real32_T Constant_Value_b[3];        /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S160>/Constant'
                                        */
  real32_T Constant_Value_d0;          /* Computed Parameter: Constant_Value_d0
                                        * Referenced by: '<S195>/Constant'
                                        */
  real32_T Constant1_Value_k;          /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S195>/Constant1'
                                        */
  real32_T Constant2_Value_dw;         /* Computed Parameter: Constant2_Value_dw
                                        * Referenced by: '<S195>/Constant2'
                                        */
  real32_T Constant4_Value_c;          /* Computed Parameter: Constant4_Value_c
                                        * Referenced by: '<S195>/Constant4'
                                        */
  real32_T Gain_Gain_pj;               /* Computed Parameter: Gain_Gain_pj
                                        * Referenced by: '<S193>/Gain'
                                        */
  real32_T Gain_Gain_ok;               /* Computed Parameter: Gain_Gain_ok
                                        * Referenced by: '<S195>/Gain'
                                        */
  real32_T Constant3_Value_b;          /* Computed Parameter: Constant3_Value_b
                                        * Referenced by: '<S195>/Constant3'
                                        */
  real32_T Switch_Threshold_e;         /* Computed Parameter: Switch_Threshold_e
                                        * Referenced by: '<S194>/Switch'
                                        */
  real32_T Constant_Value_h1;          /* Computed Parameter: Constant_Value_h1
                                        * Referenced by: '<S161>/Constant'
                                        */
  real32_T Constant_Value_aee;         /* Computed Parameter: Constant_Value_aee
                                        * Referenced by: '<S162>/Constant'
                                        */
  real32_T Constant_Value_hp;          /* Computed Parameter: Constant_Value_hp
                                        * Referenced by: '<S163>/Constant'
                                        */
  real32_T quat_0_Y0[4];               /* Computed Parameter: quat_0_Y0
                                        * Referenced by: '<S138>/quat_0'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S138>/Gain'
                                        */
  real32_T Switch_Threshold_a;         /* Computed Parameter: Switch_Threshold_a
                                        * Referenced by: '<S161>/Switch'
                                        */
  real32_T Switch_Threshold_f;         /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S162>/Switch'
                                        */
  real32_T Switch_Threshold_mm;        /* Computed Parameter: Switch_Threshold_mm
                                        * Referenced by: '<S163>/Switch'
                                        */
  real32_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S159>/Merge'
                                        */
  real32_T DiscreteTimeIntegrator5_gainval;/* Computed Parameter: DiscreteTimeIntegrator5_gainval
                                            * Referenced by: '<S199>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_gainv_n;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_n
                                            * Referenced by: '<S197>/Discrete-Time Integrator5'
                                            */
  real32_T Saturation2_UpperSat_i;     /* Computed Parameter: Saturation2_UpperSat_i
                                        * Referenced by: '<S140>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat_g;     /* Computed Parameter: Saturation2_LowerSat_g
                                        * Referenced by: '<S140>/Saturation2'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_m;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_m
                                            * Referenced by: '<S198>/Discrete-Time Integrator5'
                                            */
  real32_T Relay_OnVal_g;              /* Computed Parameter: Relay_OnVal_g
                                        * Referenced by: '<S140>/Relay'
                                        */
  real32_T Relay_OffVal_f;             /* Computed Parameter: Relay_OffVal_f
                                        * Referenced by: '<S140>/Relay'
                                        */
  real32_T Relay_YOn_k;                /* Computed Parameter: Relay_YOn_k
                                        * Referenced by: '<S140>/Relay'
                                        */
  real32_T Relay_YOff_f;               /* Computed Parameter: Relay_YOff_f
                                        * Referenced by: '<S140>/Relay'
                                        */
  real32_T Gain_Gain_fr;               /* Computed Parameter: Gain_Gain_fr
                                        * Referenced by: '<S199>/Gain'
                                        */
  real32_T Gain_Gain_je;               /* Computed Parameter: Gain_Gain_je
                                        * Referenced by: '<S197>/Gain'
                                        */
  real32_T Gain_Gain_h;                /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S198>/Gain'
                                        */
  real32_T X_Next_Y0;                  /* Computed Parameter: X_Next_Y0
                                        * Referenced by: '<S219>/X_Next'
                                        */
  real32_T Delay_InitialCondition_e;   /* Computed Parameter: Delay_InitialCondition_e
                                        * Referenced by: '<S225>/Delay'
                                        */
  real32_T Memory_InitialCondition;    /* Computed Parameter: Memory_InitialCondition
                                        * Referenced by: '<S221>/Memory'
                                        */
  real32_T Gain3_Gain_ev;              /* Expression: INS_CONST.dt
                                        * Referenced by: '<S221>/Gain3'
                                        */
  real32_T Gain1_Gain_j;               /* Computed Parameter: Gain1_Gain_j
                                        * Referenced by: '<S234>/Gain1'
                                        */
  real32_T Gain1_Gain_a;               /* Computed Parameter: Gain1_Gain_a
                                        * Referenced by: '<S235>/Gain1'
                                        */
  real32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S238>/Constant'
                                        */
  real32_T X_Next_Y0_c;                /* Computed Parameter: X_Next_Y0_c
                                        * Referenced by: '<S228>/X_Next'
                                        */
  real32_T Memory_InitialCondition_l[2];/* Computed Parameter: Memory_InitialCondition_l
                                         * Referenced by: '<S237>/Memory'
                                         */
  real32_T Memory_InitialCondition_o;  /* Computed Parameter: Memory_InitialCondition_o
                                        * Referenced by: '<S230>/Memory'
                                        */
  real32_T Gain3_Gain_o;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S230>/Gain3'
                                        */
  real32_T Constant_Value_o[2];        /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S244>/Constant'
                                        */
  real32_T X_Next_Y0_k;                /* Computed Parameter: X_Next_Y0_k
                                        * Referenced by: '<S241>/X_Next'
                                        */
  real32_T Memory_InitialCondition_i;  /* Computed Parameter: Memory_InitialCondition_i
                                        * Referenced by: '<S243>/Memory'
                                        */
  real32_T Gain3_Gain_p;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S243>/Gain3'
                                        */
  real32_T Constant_Value_bj[2];       /* Computed Parameter: Constant_Value_bj
                                        * Referenced by: '<S249>/Constant'
                                        */
  real32_T Saturation_UpperSat_b;      /* Computed Parameter: Saturation_UpperSat_b
                                        * Referenced by: '<S265>/Saturation'
                                        */
  real32_T Saturation_LowerSat_c;      /* Computed Parameter: Saturation_LowerSat_c
                                        * Referenced by: '<S265>/Saturation'
                                        */
  real32_T X_Next_Y0_m;                /* Computed Parameter: X_Next_Y0_m
                                        * Referenced by: '<S262>/X_Next'
                                        */
  real32_T Delay_InitialCondition_j;   /* Computed Parameter: Delay_InitialCondition_j
                                        * Referenced by: '<S264>/Delay'
                                        */
  real32_T Delay_InitialCondition_mk;  /* Computed Parameter: Delay_InitialCondition_mk
                                        * Referenced by: '<S268>/Delay'
                                        */
  real32_T Gain_Gain_pl;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S264>/Gain'
                                        */
  real32_T Saturation_UpperSat_as;     /* Computed Parameter: Saturation_UpperSat_as
                                        * Referenced by: '<S262>/Saturation'
                                        */
  real32_T Saturation_LowerSat_e;      /* Computed Parameter: Saturation_LowerSat_e
                                        * Referenced by: '<S262>/Saturation'
                                        */
  real32_T Saturation_UpperSat_hz;     /* Computed Parameter: Saturation_UpperSat_hz
                                        * Referenced by: '<S274>/Saturation'
                                        */
  real32_T Saturation_LowerSat_n;      /* Computed Parameter: Saturation_LowerSat_n
                                        * Referenced by: '<S274>/Saturation'
                                        */
  real32_T X_Next_Y0_j;                /* Computed Parameter: X_Next_Y0_j
                                        * Referenced by: '<S271>/X_Next'
                                        */
  real32_T Delay_InitialCondition_ms;  /* Computed Parameter: Delay_InitialCondition_ms
                                        * Referenced by: '<S273>/Delay'
                                        */
  real32_T Delay_InitialCondition_d;   /* Computed Parameter: Delay_InitialCondition_d
                                        * Referenced by: '<S277>/Delay'
                                        */
  real32_T Gain_Gain_ov;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S273>/Gain'
                                        */
  real32_T Gain4_Gain_b;               /* Computed Parameter: Gain4_Gain_b
                                        * Referenced by: '<S286>/Gain4'
                                        */
  real32_T Gain4_Gain_l;               /* Computed Parameter: Gain4_Gain_l
                                        * Referenced by: '<S287>/Gain4'
                                        */
  real32_T X_Next_Y0_i;                /* Computed Parameter: X_Next_Y0_i
                                        * Referenced by: '<S280>/X_Next'
                                        */
  real32_T Memory_InitialCondition_p;  /* Computed Parameter: Memory_InitialCondition_p
                                        * Referenced by: '<S288>/Memory'
                                        */
  real32_T Memory_InitialCondition_c;  /* Computed Parameter: Memory_InitialCondition_c
                                        * Referenced by: '<S282>/Memory'
                                        */
  real32_T Gain3_Gain_k;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S282>/Gain3'
                                        */
  real32_T Saturation_UpperSat_i;      /* Computed Parameter: Saturation_UpperSat_i
                                        * Referenced by: '<S295>/Saturation'
                                        */
  real32_T Saturation_LowerSat_h;      /* Computed Parameter: Saturation_LowerSat_h
                                        * Referenced by: '<S295>/Saturation'
                                        */
  real32_T X_Next_Y0_mm;               /* Computed Parameter: X_Next_Y0_mm
                                        * Referenced by: '<S292>/X_Next'
                                        */
  real32_T rf_bias_Y0;                 /* Computed Parameter: rf_bias_Y0
                                        * Referenced by: '<S292>/rf_bias'
                                        */
  real32_T Delay_InitialCondition_dc;  /* Computed Parameter: Delay_InitialCondition_dc
                                        * Referenced by: '<S301>/Delay'
                                        */
  real32_T Constant1_Value_b;          /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S301>/Constant1'
                                        */
  real32_T Memory_InitialCondition_g;  /* Computed Parameter: Memory_InitialCondition_g
                                        * Referenced by: '<S298>/Memory'
                                        */
  real32_T Memory_InitialCondition_h;  /* Computed Parameter: Memory_InitialCondition_h
                                        * Referenced by: '<S294>/Memory'
                                        */
  real32_T Gain3_Gain_j;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S294>/Gain3'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S306>/Constant'
                                        */
  real32_T Merge_InitialOutput_g;      /* Computed Parameter: Merge_InitialOutput_g
                                        * Referenced by: '<S307>/Merge'
                                        */
  real32_T Merge_InitialOutput_d;      /* Computed Parameter: Merge_InitialOutput_d
                                        * Referenced by: '<S308>/Merge'
                                        */
  real32_T Delay_InitialCondition_mt;  /* Computed Parameter: Delay_InitialCondition_mt
                                        * Referenced by: '<S304>/Delay'
                                        */
  real32_T Gain1_Gain_k;               /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S305>/Gain1'
                                        */
  real32_T Constant_Value_nn;          /* Computed Parameter: Constant_Value_nn
                                        * Referenced by: '<S305>/Constant'
                                        */
  real32_T Gain_Gain_mr;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S305>/Gain'
                                        */
  real32_T Merge_InitialOutput_o;      /* Computed Parameter: Merge_InitialOutput_o
                                        * Referenced by: '<S250>/Merge'
                                        */
  real32_T Merge_InitialOutput_c;      /* Computed Parameter: Merge_InitialOutput_c
                                        * Referenced by: '<S251>/Merge'
                                        */
  real32_T Delay_InitialCondition_g;   /* Computed Parameter: Delay_InitialCondition_g
                                        * Referenced by: '<S247>/Delay'
                                        */
  real32_T Constant_Value_lx[2];       /* Computed Parameter: Constant_Value_lx
                                        * Referenced by: '<S248>/Constant'
                                        */
  real32_T Gain_Gain_ic;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S248>/Gain'
                                        */
  real32_T Relay_OnVal_l;              /* Computed Parameter: Relay_OnVal_l
                                        * Referenced by: '<S352>/Relay'
                                        */
  real32_T Relay_OffVal_p;             /* Computed Parameter: Relay_OffVal_p
                                        * Referenced by: '<S352>/Relay'
                                        */
  real32_T Relay_YOn_b;                /* Computed Parameter: Relay_YOn_b
                                        * Referenced by: '<S352>/Relay'
                                        */
  real32_T Relay_YOff_d;               /* Computed Parameter: Relay_YOff_d
                                        * Referenced by: '<S352>/Relay'
                                        */
  real32_T Relay1_OnVal_b;             /* Computed Parameter: Relay1_OnVal_b
                                        * Referenced by: '<S352>/Relay1'
                                        */
  real32_T Relay1_OffVal_n;            /* Computed Parameter: Relay1_OffVal_n
                                        * Referenced by: '<S352>/Relay1'
                                        */
  real32_T Relay1_YOn;                 /* Computed Parameter: Relay1_YOn
                                        * Referenced by: '<S352>/Relay1'
                                        */
  real32_T Relay1_YOff;                /* Computed Parameter: Relay1_YOff
                                        * Referenced by: '<S352>/Relay1'
                                        */
  real32_T Constant_Value_oi;          /* Computed Parameter: Constant_Value_oi
                                        * Referenced by: '<S340>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_bq;/* Computed Parameter: DiscreteTimeIntegrator_gainv_bq
                                            * Referenced by: '<S340>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_c;/* Computed Parameter: DiscreteTimeIntegrator_IC_c
                                        * Referenced by: '<S340>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_d;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_d
                                            * Referenced by: '<S340>/Discrete-Time Integrator1'
                                            */
  real32_T Gain_Gain_b;                /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S340>/Gain'
                                        */
  real32_T Gain1_Gain_c;               /* Computed Parameter: Gain1_Gain_c
                                        * Referenced by: '<S340>/Gain1'
                                        */
  real32_T Delay_InitialCondition_m0;  /* Computed Parameter: Delay_InitialCondition_m0
                                        * Referenced by: '<S344>/Delay'
                                        */
  real32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S345>/Gain'
                                        */
  real32_T Constant_Value_hc;          /* Computed Parameter: Constant_Value_hc
                                        * Referenced by: '<S349>/Constant'
                                        */
  real32_T Constant1_Value_p;          /* Computed Parameter: Constant1_Value_p
                                        * Referenced by: '<S349>/Constant1'
                                        */
  real32_T Constant2_Value_e;          /* Computed Parameter: Constant2_Value_e
                                        * Referenced by: '<S349>/Constant2'
                                        */
  real32_T Constant3_Value_n;          /* Computed Parameter: Constant3_Value_n
                                        * Referenced by: '<S349>/Constant3'
                                        */
  real32_T Constant4_Value_m;          /* Computed Parameter: Constant4_Value_m
                                        * Referenced by: '<S349>/Constant4'
                                        */
  real32_T Gain_Gain_b2;               /* Computed Parameter: Gain_Gain_b2
                                        * Referenced by: '<S349>/Gain'
                                        */
  real32_T Constant_Value_gd;          /* Computed Parameter: Constant_Value_gd
                                        * Referenced by: '<S338>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_bt;/* Computed Parameter: DiscreteTimeIntegrator_gainv_bt
                                            * Referenced by: '<S366>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_g;/* Computed Parameter: DiscreteTimeIntegrator_IC_g
                                        * Referenced by: '<S366>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_p;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_p
                                            * Referenced by: '<S366>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_p;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_p
                                            * Referenced by: '<S366>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                            * Referenced by: '<S378>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_lb;/* Computed Parameter: DiscreteTimeIntegrator_IC_lb
                                         * Referenced by: '<S378>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_UpperS_j;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_j
                                            * Referenced by: '<S378>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_Lower_f2;/* Computed Parameter: DiscreteTimeIntegrator_Lower_f2
                                            * Referenced by: '<S378>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainv_iy;/* Computed Parameter: DiscreteTimeIntegrator_gainv_iy
                                            * Referenced by: '<S365>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_b;/* Computed Parameter: DiscreteTimeIntegrator_IC_b
                                        * Referenced by: '<S365>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_Upper_jm;/* Computed Parameter: DiscreteTimeIntegrator_Upper_jm
                                            * Referenced by: '<S365>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_d;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_d
                                            * Referenced by: '<S365>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_a;/* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                            * Referenced by: '<S377>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_hz;/* Computed Parameter: DiscreteTimeIntegrator_IC_hz
                                         * Referenced by: '<S377>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_Upper_fv;/* Computed Parameter: DiscreteTimeIntegrator_Upper_fv
                                            * Referenced by: '<S377>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_b;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_b
                                            * Referenced by: '<S377>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainv_jp;/* Computed Parameter: DiscreteTimeIntegrator_gainv_jp
                                            * Referenced by: '<S379>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_ms;/* Computed Parameter: DiscreteTimeIntegrator_IC_ms
                                         * Referenced by: '<S379>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_UpperS_e;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_e
                                            * Referenced by: '<S379>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_Lower_no;/* Computed Parameter: DiscreteTimeIntegrator_Lower_no
                                            * Referenced by: '<S379>/Discrete-Time Integrator'
                                            */
  real32_T Delay_4_InitialCondition;   /* Computed Parameter: Delay_4_InitialCondition
                                        * Referenced by: '<S56>/Delay'
                                        */
  real32_T Delay_5_InitialCondition;   /* Computed Parameter: Delay_5_InitialCondition
                                        * Referenced by: '<S56>/Delay'
                                        */
  real32_T Delay_6_InitialCondition;   /* Computed Parameter: Delay_6_InitialCondition
                                        * Referenced by: '<S56>/Delay'
                                        */
  real32_T AirDensity_15C_Value;       /* Computed Parameter: AirDensity_15C_Value
                                        * Referenced by: '<S411>/AirDensity_15C'
                                        */
  real32_T Gain_Gain_oz;               /* Computed Parameter: Gain_Gain_oz
                                        * Referenced by: '<S411>/Gain'
                                        */
  real32_T Saturation1_UpperSat_i;     /* Computed Parameter: Saturation1_UpperSat_i
                                        * Referenced by: '<S403>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_n;     /* Computed Parameter: Saturation1_LowerSat_n
                                        * Referenced by: '<S403>/Saturation1'
                                        */
  real32_T h_R_m_Y0;                   /* Computed Parameter: h_R_m_Y0
                                        * Referenced by: '<S415>/h_R_m'
                                        */
  real32_T Delay_InitialCondition_p;   /* Computed Parameter: Delay_InitialCondition_p
                                        * Referenced by: '<S415>/Delay'
                                        */
  real32_T Gain1_Gain_aj;              /* Computed Parameter: Gain1_Gain_aj
                                        * Referenced by: '<S412>/Gain1'
                                        */
  real32_T p1_Value;                   /* Computed Parameter: p1_Value
                                        * Referenced by: '<S412>/p1'
                                        */
  real32_T aR_g_Value;                 /* Computed Parameter: aR_g_Value
                                        * Referenced by: '<S412>/aR_g'
                                        */
  real32_T T1_Value;                   /* Computed Parameter: T1_Value
                                        * Referenced by: '<S412>/T1'
                                        */
  real32_T a_Value;                    /* Computed Parameter: a_Value
                                        * Referenced by: '<S412>/a'
                                        */
  real32_T Gain_Gain_ge;               /* Computed Parameter: Gain_Gain_ge
                                        * Referenced by: '<S425>/Gain'
                                        */
  real32_T Constant_Value_n5;          /* Computed Parameter: Constant_Value_n5
                                        * Referenced by: '<S447>/Constant'
                                        */
  real32_T Saturation1_UpperSat_m;     /* Computed Parameter: Saturation1_UpperSat_m
                                        * Referenced by: '<S438>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_d;     /* Computed Parameter: Saturation1_LowerSat_d
                                        * Referenced by: '<S438>/Saturation1'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_b;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_b
                                            * Referenced by: '<S447>/Discrete-Time Integrator1'
                                            */
  real32_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S448>/Constant'
                                        */
  real32_T Saturation_UpperSat_l;      /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S439>/Saturation'
                                        */
  real32_T Saturation_LowerSat_ku;     /* Computed Parameter: Saturation_LowerSat_ku
                                        * Referenced by: '<S439>/Saturation'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_e;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_e
                                            * Referenced by: '<S448>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_g;/* Computed Parameter: DiscreteTimeIntegrator_gainva_g
                                            * Referenced by: '<S447>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_d;/* Computed Parameter: DiscreteTimeIntegrator_IC_d
                                        * Referenced by: '<S447>/Discrete-Time Integrator'
                                        */
  real32_T Gain_Gain_j2;               /* Computed Parameter: Gain_Gain_j2
                                        * Referenced by: '<S447>/Gain'
                                        */
  real32_T Gain1_Gain_kf;              /* Computed Parameter: Gain1_Gain_kf
                                        * Referenced by: '<S447>/Gain1'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_mf;/* Computed Parameter: DiscreteTimeIntegrator_gainv_mf
                                            * Referenced by: '<S448>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_f;/* Computed Parameter: DiscreteTimeIntegrator_IC_f
                                        * Referenced by: '<S448>/Discrete-Time Integrator'
                                        */
  real32_T Gain_Gain_gh;               /* Computed Parameter: Gain_Gain_gh
                                        * Referenced by: '<S448>/Gain'
                                        */
  real32_T Gain1_Gain_cj;              /* Computed Parameter: Gain1_Gain_cj
                                        * Referenced by: '<S448>/Gain1'
                                        */
  real32_T default_mag_quality_Value;  /* Computed Parameter: default_mag_quality_Value
                                        * Referenced by: '<S461>/default_mag_quality'
                                        */
  real32_T Saturation_UpperSat_m;      /* Computed Parameter: Saturation_UpperSat_m
                                        * Referenced by: '<S464>/Saturation'
                                        */
  real32_T Saturation_LowerSat_b;      /* Computed Parameter: Saturation_LowerSat_b
                                        * Referenced by: '<S464>/Saturation'
                                        */
  real32_T Constant_Value_hy;          /* Computed Parameter: Constant_Value_hy
                                        * Referenced by: '<S471>/Constant'
                                        */
  real32_T Switch_Threshold_b;         /* Computed Parameter: Switch_Threshold_b
                                        * Referenced by: '<S471>/Switch'
                                        */
  real32_T Constant1_Value_l1;         /* Computed Parameter: Constant1_Value_l1
                                        * Referenced by: '<S472>/Constant1'
                                        */
  real32_T Constant_Value_a1;          /* Computed Parameter: Constant_Value_a1
                                        * Referenced by: '<S470>/Constant'
                                        */
  real32_T Constant1_Value_i;          /* Computed Parameter: Constant1_Value_i
                                        * Referenced by: '<S470>/Constant1'
                                        */
  real32_T Constant2_Value_mb;         /* Computed Parameter: Constant2_Value_mb
                                        * Referenced by: '<S470>/Constant2'
                                        */
  real32_T Constant4_Value_cj;         /* Computed Parameter: Constant4_Value_cj
                                        * Referenced by: '<S470>/Constant4'
                                        */
  real32_T Gain_Gain_gg;               /* Computed Parameter: Gain_Gain_gg
                                        * Referenced by: '<S462>/Gain'
                                        */
  real32_T Gain_Gain_bo;               /* Computed Parameter: Gain_Gain_bo
                                        * Referenced by: '<S470>/Gain'
                                        */
  real32_T Constant3_Value_f;          /* Computed Parameter: Constant3_Value_f
                                        * Referenced by: '<S470>/Constant3'
                                        */
  real32_T Gauss_to_uT_Gain;           /* Computed Parameter: Gauss_to_uT_Gain
                                        * Referenced by: '<S408>/Gauss_to_uT'
                                        */
  real32_T Gain1_Gain_od;              /* Computed Parameter: Gain1_Gain_od
                                        * Referenced by: '<S465>/Gain1'
                                        */
  real32_T Constant2_Value_h;          /* Computed Parameter: Constant2_Value_h
                                        * Referenced by: '<S465>/Constant2'
                                        */
  real32_T gain_Gain_g;                /* Computed Parameter: gain_Gain_g
                                        * Referenced by: '<S465>/gain'
                                        */
  real32_T Saturation_UpperSat_g;      /* Computed Parameter: Saturation_UpperSat_g
                                        * Referenced by: '<S465>/Saturation'
                                        */
  real32_T Saturation_LowerSat_a;      /* Computed Parameter: Saturation_LowerSat_a
                                        * Referenced by: '<S465>/Saturation'
                                        */
  real32_T Nominal_Magnitude_Value;    /* Computed Parameter: Nominal_Magnitude_Value
                                        * Referenced by: '<S466>/Nominal_Magnitude'
                                        */
  real32_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S466>/Constant1'
                                        */
  real32_T gain_Gain_m;                /* Computed Parameter: gain_Gain_m
                                        * Referenced by: '<S466>/gain'
                                        */
  real32_T Saturation_UpperSat_gv;     /* Computed Parameter: Saturation_UpperSat_gv
                                        * Referenced by: '<S466>/Saturation'
                                        */
  real32_T Saturation_LowerSat_p;      /* Computed Parameter: Saturation_LowerSat_p
                                        * Referenced by: '<S466>/Saturation'
                                        */
  real32_T Constant_Value_fn;          /* Computed Parameter: Constant_Value_fn
                                        * Referenced by: '<S467>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_m;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_m
                                            * Referenced by: '<S467>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator_gainv_bm;/* Computed Parameter: DiscreteTimeIntegrator_gainv_bm
                                            * Referenced by: '<S467>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_mb;/* Computed Parameter: DiscreteTimeIntegrator_IC_mb
                                         * Referenced by: '<S467>/Discrete-Time Integrator'
                                         */
  real32_T Gain_Gain_cw;               /* Computed Parameter: Gain_Gain_cw
                                        * Referenced by: '<S467>/Gain'
                                        */
  real32_T Gain1_Gain_bn;              /* Computed Parameter: Gain1_Gain_bn
                                        * Referenced by: '<S467>/Gain1'
                                        */
  real32_T Gain_Gain_gn;               /* Computed Parameter: Gain_Gain_gn
                                        * Referenced by: '<S477>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_j;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_j
                                            * Referenced by: '<S481>/Discrete-Time Integrator5'
                                            */
  real32_T DeadZone_Start;             /* Computed Parameter: DeadZone_Start
                                        * Referenced by: '<S479>/Dead Zone'
                                        */
  real32_T Constant_Value_eu;          /* Computed Parameter: Constant_Value_eu
                                        * Referenced by: '<S482>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_c;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_c
                                            * Referenced by: '<S480>/Discrete-Time Integrator5'
                                            */
  real32_T Gain_Gain_ca;               /* Computed Parameter: Gain_Gain_ca
                                        * Referenced by: '<S480>/Gain'
                                        */
  real32_T Gain_Gain_ft;               /* Computed Parameter: Gain_Gain_ft
                                        * Referenced by: '<S481>/Gain'
                                        */
  real32_T Delay_InitialCondition_n;   /* Computed Parameter: Delay_InitialCondition_n
                                        * Referenced by: '<S493>/Delay'
                                        */
  real32_T Relay_OffVal_b;             /* Computed Parameter: Relay_OffVal_b
                                        * Referenced by: '<S488>/Relay'
                                        */
  real32_T Relay_YOn_e;                /* Computed Parameter: Relay_YOn_e
                                        * Referenced by: '<S488>/Relay'
                                        */
  real32_T Relay_YOff_c;               /* Computed Parameter: Relay_YOff_c
                                        * Referenced by: '<S488>/Relay'
                                        */
  real32_T Delay_3_InitialCondition;   /* Computed Parameter: Delay_3_InitialCondition
                                        * Referenced by: '<Root>/Delay'
                                        */
  real32_T Delay_4_InitialCondition_m; /* Computed Parameter: Delay_4_InitialCondition_m
                                        * Referenced by: '<Root>/Delay'
                                        */
  real32_T Delay_9_InitialCondition;   /* Computed Parameter: Delay_9_InitialCondition
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Gain1_Gain_ap;              /* Computed Parameter: Gain1_Gain_ap
                                        * Referenced by: '<S10>/Gain1'
                                        */
  uint32_T Gain9_Gain;                 /* Computed Parameter: Gain9_Gain
                                        * Referenced by: '<S8>/Gain9'
                                        */
  uint32_T Gain_Gain_or;               /* Computed Parameter: Gain_Gain_or
                                        * Referenced by: '<S223>/Gain'
                                        */
  uint32_T Gain_Gain_jz;               /* Computed Parameter: Gain_Gain_jz
                                        * Referenced by: '<S232>/Gain'
                                        */
  uint32_T Gain1_Gain_d;               /* Computed Parameter: Gain1_Gain_d
                                        * Referenced by: '<S232>/Gain1'
                                        */
  uint32_T Period_Gain;                /* Computed Parameter: Period_Gain
                                        * Referenced by: '<S245>/Period'
                                        */
  uint32_T Gain_Gain_nu;               /* Computed Parameter: Gain_Gain_nu
                                        * Referenced by: '<S266>/Gain'
                                        */
  uint32_T Gain_Gain_gnx;              /* Computed Parameter: Gain_Gain_gnx
                                        * Referenced by: '<S275>/Gain'
                                        */
  uint32_T Gain_Gain_fs;               /* Computed Parameter: Gain_Gain_fs
                                        * Referenced by: '<S284>/Gain'
                                        */
  uint32_T Gain1_Gain_p0;              /* Computed Parameter: Gain1_Gain_p0
                                        * Referenced by: '<S284>/Gain1'
                                        */
  uint32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S296>/Gain'
                                        */
  uint32_T Gain1_Gain_po;              /* Computed Parameter: Gain1_Gain_po
                                        * Referenced by: '<S438>/Gain1'
                                        */
  uint32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S439>/Gain5'
                                        */
  uint32_T Output_InitialCondition;    /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S4>/Output'
                                        */
  uint32_T Constant_Value_pt;          /* Computed Parameter: Constant_Value_pt
                                        * Referenced by: '<S8>/Constant'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S12>/Delay'
                                        */
  uint32_T Delay_DelayLength_l;        /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S15>/Delay'
                                        */
  uint32_T Delay_DelayLength_k;        /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S17>/Delay'
                                        */
  uint32_T Delay_DelayLength_j;        /* Computed Parameter: Delay_DelayLength_j
                                        * Referenced by: '<S11>/Delay'
                                        */
  uint32_T Delay_DelayLength_lg;       /* Computed Parameter: Delay_DelayLength_lg
                                        * Referenced by: '<S13>/Delay'
                                        */
  uint32_T Delay_DelayLength_m;        /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S14>/Delay'
                                        */
  uint32_T Delay_DelayLength_f;        /* Computed Parameter: Delay_DelayLength_f
                                        * Referenced by: '<S16>/Delay'
                                        */
  uint32_T Constant_Value_lm;          /* Computed Parameter: Constant_Value_lm
                                        * Referenced by: '<S10>/Constant'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_io;/* Computed Parameter: DiscreteTimeIntegrator_IC_io
                                         * Referenced by: '<S97>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_UpperS_c;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_c
                                            * Referenced by: '<S97>/Discrete-Time Integrator'
                                            */
  uint32_T DiscreteTimeIntegrator_LowerS_m;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_m
                                            * Referenced by: '<S97>/Discrete-Time Integrator'
                                            */
  uint32_T Delay_DelayLength_e;        /* Computed Parameter: Delay_DelayLength_e
                                        * Referenced by: '<S104>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S120>/Delay1'
                                        */
  uint32_T Delay1_DelayLength_f;       /* Computed Parameter: Delay1_DelayLength_f
                                        * Referenced by: '<S57>/Delay1'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S57>/Delay2'
                                        */
  uint32_T Delay_DelayLength_fi;       /* Computed Parameter: Delay_DelayLength_fi
                                        * Referenced by: '<S149>/Delay'
                                        */
  uint32_T Delay_InitialCondition_n0;  /* Computed Parameter: Delay_InitialCondition_n0
                                        * Referenced by: '<S149>/Delay'
                                        */
  uint32_T Saturation_UpperSat_k5;     /* Computed Parameter: Saturation_UpperSat_k5
                                        * Referenced by: '<S149>/Saturation'
                                        */
  uint32_T Saturation_LowerSat_hb;     /* Computed Parameter: Saturation_LowerSat_hb
                                        * Referenced by: '<S149>/Saturation'
                                        */
  uint32_T Delay_DelayLength_o;        /* Computed Parameter: Delay_DelayLength_o
                                        * Referenced by: '<S150>/Delay'
                                        */
  uint32_T Delay_InitialCondition_m5;  /* Computed Parameter: Delay_InitialCondition_m5
                                        * Referenced by: '<S150>/Delay'
                                        */
  uint32_T Saturation_UpperSat_az;     /* Computed Parameter: Saturation_UpperSat_az
                                        * Referenced by: '<S150>/Saturation'
                                        */
  uint32_T Saturation_LowerSat_d;      /* Computed Parameter: Saturation_LowerSat_d
                                        * Referenced by: '<S150>/Saturation'
                                        */
  uint32_T Delay_DelayLength_md;       /* Computed Parameter: Delay_DelayLength_md
                                        * Referenced by: '<S145>/Delay'
                                        */
  uint32_T Delay_InitialCondition_ij;  /* Computed Parameter: Delay_InitialCondition_ij
                                        * Referenced by: '<S145>/Delay'
                                        */
  uint32_T Saturation_UpperSat_p;      /* Computed Parameter: Saturation_UpperSat_p
                                        * Referenced by: '<S145>/Saturation'
                                        */
  uint32_T Saturation_LowerSat_mo;     /* Computed Parameter: Saturation_LowerSat_mo
                                        * Referenced by: '<S145>/Saturation'
                                        */
  uint32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S154>/Constant'
                                        */
  uint32_T Delay_DelayLength_k2;       /* Computed Parameter: Delay_DelayLength_k2
                                        * Referenced by: '<S225>/Delay'
                                        */
  uint32_T Delay_DelayLength_fx;       /* Computed Parameter: Delay_DelayLength_fx
                                        * Referenced by: '<S264>/Delay'
                                        */
  uint32_T Delay_DelayLength_d;        /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S268>/Delay'
                                        */
  uint32_T Delay_DelayLength_mb;       /* Computed Parameter: Delay_DelayLength_mb
                                        * Referenced by: '<S273>/Delay'
                                        */
  uint32_T Delay_DelayLength_b;        /* Computed Parameter: Delay_DelayLength_b
                                        * Referenced by: '<S277>/Delay'
                                        */
  uint32_T Constant_Value_kt;          /* Computed Parameter: Constant_Value_kt
                                        * Referenced by: '<S301>/Constant'
                                        */
  uint32_T Delay_DelayLength_f2;       /* Computed Parameter: Delay_DelayLength_f2
                                        * Referenced by: '<S301>/Delay'
                                        */
  uint32_T Delay1_DelayLength_i;       /* Computed Parameter: Delay1_DelayLength_i
                                        * Referenced by: '<S301>/Delay1'
                                        */
  uint32_T Delay2_DelayLength_j;       /* Computed Parameter: Delay2_DelayLength_j
                                        * Referenced by: '<S301>/Delay2'
                                        */
  uint32_T Delay2_InitialCondition_o;  /* Computed Parameter: Delay2_InitialCondition_o
                                        * Referenced by: '<S301>/Delay2'
                                        */
  uint32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S301>/Switch1'
                                        */
  uint32_T Delay_DelayLength_p;        /* Computed Parameter: Delay_DelayLength_p
                                        * Referenced by: '<S304>/Delay'
                                        */
  uint32_T Delay_DelayLength_ly;       /* Computed Parameter: Delay_DelayLength_ly
                                        * Referenced by: '<S247>/Delay'
                                        */
  uint32_T Delay_DelayLength_a;        /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S343>/Delay'
                                        */
  uint32_T Delay_DelayLength_kg;       /* Computed Parameter: Delay_DelayLength_kg
                                        * Referenced by: '<S344>/Delay'
                                        */
  uint32_T Delay_DelayLength_h;        /* Computed Parameter: Delay_DelayLength_h
                                        * Referenced by: '<S348>/Delay'
                                        */
  uint32_T Delay_DelayLength_as;       /* Computed Parameter: Delay_DelayLength_as
                                        * Referenced by: '<S366>/Delay'
                                        */
  uint32_T Delay_DelayLength_g;        /* Computed Parameter: Delay_DelayLength_g
                                        * Referenced by: '<S378>/Delay'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S365>/Delay'
                                        */
  uint32_T Delay_DelayLength_d0;       /* Computed Parameter: Delay_DelayLength_d0
                                        * Referenced by: '<S377>/Delay'
                                        */
  uint32_T Delay_DelayLength_dm;       /* Computed Parameter: Delay_DelayLength_dm
                                        * Referenced by: '<S379>/Delay'
                                        */
  uint32_T Delay1_DelayLength_f4;      /* Computed Parameter: Delay1_DelayLength_f4
                                        * Referenced by: '<S397>/Delay1'
                                        */
  uint32_T Delay_DelayLength_ch;       /* Computed Parameter: Delay_DelayLength_ch
                                        * Referenced by: '<S398>/Delay'
                                        */
  uint32_T Delay1_DelayLength_o;       /* Computed Parameter: Delay1_DelayLength_o
                                        * Referenced by: '<S398>/Delay1'
                                        */
  uint32_T Delay_4_DelayLength;        /* Computed Parameter: Delay_4_DelayLength
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Delay_5_DelayLength;        /* Computed Parameter: Delay_5_DelayLength
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Delay_6_DelayLength;        /* Computed Parameter: Delay_6_DelayLength
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Constant1_Value_f;          /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S415>/Constant1'
                                        */
  uint32_T Delay_DelayLength_jx;       /* Computed Parameter: Delay_DelayLength_jx
                                        * Referenced by: '<S415>/Delay'
                                        */
  uint32_T Delay1_DelayLength_p;       /* Computed Parameter: Delay1_DelayLength_p
                                        * Referenced by: '<S415>/Delay1'
                                        */
  uint32_T Delay1_InitialCondition_k;  /* Computed Parameter: Delay1_InitialCondition_k
                                        * Referenced by: '<S415>/Delay1'
                                        */
  uint32_T Saturation1_UpperSat_n;     /* Computed Parameter: Saturation1_UpperSat_n
                                        * Referenced by: '<S415>/Saturation1'
                                        */
  uint32_T Saturation1_LowerSat_m;     /* Computed Parameter: Saturation1_LowerSat_m
                                        * Referenced by: '<S415>/Saturation1'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_iu;/* Computed Parameter: DiscreteTimeIntegrator_IC_iu
                                         * Referenced by: '<S414>/Discrete-Time Integrator'
                                         */
  uint32_T Delay_DelayLength_ew;       /* Computed Parameter: Delay_DelayLength_ew
                                        * Referenced by: '<S422>/Delay'
                                        */
  uint32_T Delay_DelayLength_dn;       /* Computed Parameter: Delay_DelayLength_dn
                                        * Referenced by: '<S416>/Delay'
                                        */
  uint32_T Delay_InitialCondition_nt;  /* Computed Parameter: Delay_InitialCondition_nt
                                        * Referenced by: '<S416>/Delay'
                                        */
  uint32_T Saturation_UpperSat_f;      /* Computed Parameter: Saturation_UpperSat_f
                                        * Referenced by: '<S416>/Saturation'
                                        */
  uint32_T Saturation_LowerSat_pw;     /* Computed Parameter: Saturation_LowerSat_pw
                                        * Referenced by: '<S416>/Saturation'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_jj;/* Computed Parameter: DiscreteTimeIntegrator_IC_jj
                                         * Referenced by: '<S426>/Discrete-Time Integrator'
                                         */
  uint32_T Delay_DelayLength_fr;       /* Computed Parameter: Delay_DelayLength_fr
                                        * Referenced by: '<S429>/Delay'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_p;/* Computed Parameter: DiscreteTimeIntegrator_IC_p
                                        * Referenced by: '<S437>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_ba;/* Computed Parameter: DiscreteTimeIntegrator_IC_ba
                                         * Referenced by: '<S452>/Discrete-Time Integrator'
                                         */
  uint32_T Delay_DelayLength_d3;       /* Computed Parameter: Delay_DelayLength_d3
                                        * Referenced by: '<S455>/Delay'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_k;/* Computed Parameter: DiscreteTimeIntegrator_IC_k
                                        * Referenced by: '<S460>/Discrete-Time Integrator'
                                        */
  uint32_T Delay_DelayLength_bx;       /* Computed Parameter: Delay_DelayLength_bx
                                        * Referenced by: '<S475>/Delay'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_n;/* Computed Parameter: DiscreteTimeIntegrator_IC_n
                                        * Referenced by: '<S478>/Discrete-Time Integrator'
                                        */
  uint32_T Delay_DelayLength_b4;       /* Computed Parameter: Delay_DelayLength_b4
                                        * Referenced by: '<S485>/Delay'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_f4;/* Computed Parameter: DiscreteTimeIntegrator_IC_f4
                                         * Referenced by: '<S488>/Discrete-Time Integrator'
                                         */
  uint32_T Delay_DelayLength_ca;       /* Computed Parameter: Delay_DelayLength_ca
                                        * Referenced by: '<S493>/Delay'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_n1;/* Computed Parameter: DiscreteTimeIntegrator_IC_n1
                                         * Referenced by: '<S489>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_UpperS_l;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_l
                                            * Referenced by: '<S489>/Discrete-Time Integrator'
                                            */
  uint32_T DiscreteTimeIntegrator_Lower_bq;/* Computed Parameter: DiscreteTimeIntegrator_Lower_bq
                                            * Referenced by: '<S489>/Discrete-Time Integrator'
                                            */
  uint32_T Delay_3_DelayLength;        /* Computed Parameter: Delay_3_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Delay_4_DelayLength_g;      /* Computed Parameter: Delay_4_DelayLength_g
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Delay_9_DelayLength;        /* Computed Parameter: Delay_9_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint16_T Gain1_Gain_kq;              /* Computed Parameter: Gain1_Gain_kq
                                        * Referenced by: '<S8>/Gain1'
                                        */
  uint16_T Gain13_Gain;                /* Computed Parameter: Gain13_Gain
                                        * Referenced by: '<S8>/Gain13'
                                        */
  uint16_T Gain12_Gain;                /* Computed Parameter: Gain12_Gain
                                        * Referenced by: '<S8>/Gain12'
                                        */
  uint16_T Gain11_Gain;                /* Computed Parameter: Gain11_Gain
                                        * Referenced by: '<S8>/Gain11'
                                        */
  uint16_T Gain5_Gain_e;               /* Computed Parameter: Gain5_Gain_e
                                        * Referenced by: '<S8>/Gain5'
                                        */
  uint16_T Gain4_Gain_a;               /* Computed Parameter: Gain4_Gain_a
                                        * Referenced by: '<S8>/Gain4'
                                        */
  uint16_T Gain2_Gain_o5;              /* Computed Parameter: Gain2_Gain_o5
                                        * Referenced by: '<S8>/Gain2'
                                        */
  uint16_T GPS_Delay_Value;            /* Computed Parameter: GPS_Delay_Value
                                        * Referenced by: '<S88>/GPS_Delay'
                                        */
  uint16_T Constant_Value_gn;          /* Computed Parameter: Constant_Value_gn
                                        * Referenced by: '<S361>/Constant'
                                        */
  uint16_T Constant_Value_bt;          /* Computed Parameter: Constant_Value_bt
                                        * Referenced by: '<S362>/Constant'
                                        */
  uint16_T Constant_Value_m3;          /* Computed Parameter: Constant_Value_m3
                                        * Referenced by: '<S400>/Constant'
                                        */
  uint16_T Constant_Value_pti;         /* Computed Parameter: Constant_Value_pti
                                        * Referenced by: '<S402>/Constant'
                                        */
  boolean_T Delay_InitialCondition_go; /* Computed Parameter: Delay_InitialCondition_go
                                        * Referenced by: '<S12>/Delay'
                                        */
  boolean_T Delay_InitialCondition_mz; /* Computed Parameter: Delay_InitialCondition_mz
                                        * Referenced by: '<S15>/Delay'
                                        */
  boolean_T Relay1_YOn_i;              /* Computed Parameter: Relay1_YOn_i
                                        * Referenced by: '<S9>/Relay1'
                                        */
  boolean_T Relay1_YOff_k;             /* Computed Parameter: Relay1_YOff_k
                                        * Referenced by: '<S9>/Relay1'
                                        */
  boolean_T Delay_InitialCondition_a;  /* Computed Parameter: Delay_InitialCondition_a
                                        * Referenced by: '<S17>/Delay'
                                        */
  boolean_T Delay_InitialCondition_c;  /* Computed Parameter: Delay_InitialCondition_c
                                        * Referenced by: '<S11>/Delay'
                                        */
  boolean_T Delay_InitialCondition_cj; /* Computed Parameter: Delay_InitialCondition_cj
                                        * Referenced by: '<S13>/Delay'
                                        */
  boolean_T Delay_InitialCondition_ae; /* Computed Parameter: Delay_InitialCondition_ae
                                        * Referenced by: '<S14>/Delay'
                                        */
  boolean_T Delay_InitialCondition_em; /* Computed Parameter: Delay_InitialCondition_em
                                        * Referenced by: '<S16>/Delay'
                                        */
  boolean_T Constant_Value_mt;         /* Computed Parameter: Constant_Value_mt
                                        * Referenced by: '<S22>/Constant'
                                        */
  boolean_T Constant_Value_m2;         /* Computed Parameter: Constant_Value_m2
                                        * Referenced by: '<S27>/Constant'
                                        */
  boolean_T Constant_Value_o2;         /* Computed Parameter: Constant_Value_o2
                                        * Referenced by: '<S32>/Constant'
                                        */
  boolean_T Constant_Value_hk;         /* Computed Parameter: Constant_Value_hk
                                        * Referenced by: '<S37>/Constant'
                                        */
  boolean_T Constant_Value_l1;         /* Computed Parameter: Constant_Value_l1
                                        * Referenced by: '<S42>/Constant'
                                        */
  boolean_T Constant_Value_m2n;        /* Computed Parameter: Constant_Value_m2n
                                        * Referenced by: '<S47>/Constant'
                                        */
  boolean_T Constant_Value_ao;         /* Computed Parameter: Constant_Value_ao
                                        * Referenced by: '<S52>/Constant'
                                        */
  boolean_T Constant_Value_af;         /* Computed Parameter: Constant_Value_af
                                        * Referenced by: '<S151>/Constant'
                                        */
  boolean_T Constant_Value_bf;         /* Computed Parameter: Constant_Value_bf
                                        * Referenced by: '<S152>/Constant'
                                        */
  boolean_T Constant_Value_jz;         /* Computed Parameter: Constant_Value_jz
                                        * Referenced by: '<S323>/Constant'
                                        */
  boolean_T Constant_Value_br;         /* Computed Parameter: Constant_Value_br
                                        * Referenced by: '<S326>/Constant'
                                        */
  boolean_T Constant_Value_pf;         /* Computed Parameter: Constant_Value_pf
                                        * Referenced by: '<S328>/Constant'
                                        */
  boolean_T Constant_Value_ha;         /* Computed Parameter: Constant_Value_ha
                                        * Referenced by: '<S329>/Constant'
                                        */
  boolean_T Constant_Value_bz;         /* Computed Parameter: Constant_Value_bz
                                        * Referenced by: '<S332>/Constant'
                                        */
  boolean_T Constant_Value_dc;         /* Computed Parameter: Constant_Value_dc
                                        * Referenced by: '<S376>/Constant'
                                        */
  boolean_T Delay_InitialCondition_in; /* Computed Parameter: Delay_InitialCondition_in
                                        * Referenced by: '<S366>/Delay'
                                        */
  boolean_T Constant_Value_jo;         /* Computed Parameter: Constant_Value_jo
                                        * Referenced by: '<S389>/Constant'
                                        */
  boolean_T Delay_InitialCondition_ns; /* Computed Parameter: Delay_InitialCondition_ns
                                        * Referenced by: '<S378>/Delay'
                                        */
  boolean_T Delay_InitialCondition_k;  /* Computed Parameter: Delay_InitialCondition_k
                                        * Referenced by: '<S365>/Delay'
                                        */
  boolean_T Constant_Value_nm;         /* Computed Parameter: Constant_Value_nm
                                        * Referenced by: '<S371>/Constant'
                                        */
  boolean_T Delay_InitialCondition_dh; /* Computed Parameter: Delay_InitialCondition_dh
                                        * Referenced by: '<S377>/Delay'
                                        */
  boolean_T Constant_Value_ej;         /* Computed Parameter: Constant_Value_ej
                                        * Referenced by: '<S384>/Constant'
                                        */
  boolean_T Delay_InitialCondition_ia; /* Computed Parameter: Delay_InitialCondition_ia
                                        * Referenced by: '<S379>/Delay'
                                        */
  boolean_T Constant_Value_i;          /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S394>/Constant'
                                        */
  boolean_T Delay_InitialCondition_f;  /* Computed Parameter: Delay_InitialCondition_f
                                        * Referenced by: '<S485>/Delay'
                                        */
  boolean_T Constant_Value_pa;         /* Computed Parameter: Constant_Value_pa
                                        * Referenced by: '<S496>/Constant'
                                        */
  int8_T Saturation1_UpperSat_d;       /* Computed Parameter: Saturation1_UpperSat_d
                                        * Referenced by: '<S321>/Saturation1'
                                        */
  int8_T Saturation1_LowerSat_p;       /* Computed Parameter: Saturation1_LowerSat_p
                                        * Referenced by: '<S321>/Saturation1'
                                        */
  int8_T Constant_Value_ej5;           /* Computed Parameter: Constant_Value_ej5
                                        * Referenced by: '<S324>/Constant'
                                        */
  int8_T Saturation_UpperSat_ma;       /* Computed Parameter: Saturation_UpperSat_ma
                                        * Referenced by: '<S321>/Saturation'
                                        */
  int8_T Saturation_LowerSat_h5;       /* Computed Parameter: Saturation_LowerSat_h5
                                        * Referenced by: '<S321>/Saturation'
                                        */
  int8_T Constant_Value_m2k;           /* Computed Parameter: Constant_Value_m2k
                                        * Referenced by: '<S325>/Constant'
                                        */
  int8_T Constant_Value_bze;           /* Computed Parameter: Constant_Value_bze
                                        * Referenced by: '<S327>/Constant'
                                        */
  int8_T Saturation2_UpperSat_l;       /* Computed Parameter: Saturation2_UpperSat_l
                                        * Referenced by: '<S322>/Saturation2'
                                        */
  int8_T Saturation2_LowerSat_i;       /* Computed Parameter: Saturation2_LowerSat_i
                                        * Referenced by: '<S322>/Saturation2'
                                        */
  int8_T Constant_Value_c1;            /* Computed Parameter: Constant_Value_c1
                                        * Referenced by: '<S330>/Constant'
                                        */
  int8_T Saturation_UpperSat_gx;       /* Computed Parameter: Saturation_UpperSat_gx
                                        * Referenced by: '<S322>/Saturation'
                                        */
  int8_T Saturation_LowerSat_co;       /* Computed Parameter: Saturation_LowerSat_co
                                        * Referenced by: '<S322>/Saturation'
                                        */
  int8_T Constant_Value_lc;            /* Computed Parameter: Constant_Value_lc
                                        * Referenced by: '<S331>/Constant'
                                        */
  int8_T Saturation1_UpperSat_ig;      /* Computed Parameter: Saturation1_UpperSat_ig
                                        * Referenced by: '<S322>/Saturation1'
                                        */
  int8_T Saturation1_LowerSat_g;       /* Computed Parameter: Saturation1_LowerSat_g
                                        * Referenced by: '<S322>/Saturation1'
                                        */
  int8_T Constant_Value_ktj;           /* Computed Parameter: Constant_Value_ktj
                                        * Referenced by: '<S333>/Constant'
                                        */
  int8_T Constant_Value_ew;            /* Computed Parameter: Constant_Value_ew
                                        * Referenced by: '<S334>/Constant'
                                        */
  uint8_T Gain6_Gain;                  /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S10>/Gain6'
                                        */
  uint8_T Gain5_Gain_a;                /* Computed Parameter: Gain5_Gain_a
                                        * Referenced by: '<S10>/Gain5'
                                        */
  uint8_T Gain4_Gain_p;                /* Computed Parameter: Gain4_Gain_p
                                        * Referenced by: '<S10>/Gain4'
                                        */
  uint8_T Gain3_Gain_f;                /* Computed Parameter: Gain3_Gain_f
                                        * Referenced by: '<S10>/Gain3'
                                        */
  uint8_T Gain2_Gain_h;                /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<S10>/Gain2'
                                        */
  uint8_T Constant1_Value_cq;          /* Computed Parameter: Constant1_Value_cq
                                        * Referenced by: '<S343>/Constant1'
                                        */
  uint8_T Constant1_Value_cj;          /* Computed Parameter: Constant1_Value_cj
                                        * Referenced by: '<S348>/Constant1'
                                        */
  uint8_T Delay_InitialCondition_o;    /* Computed Parameter: Delay_InitialCondition_o
                                        * Referenced by: '<S343>/Delay'
                                        */
  uint8_T Delay_InitialCondition_du;   /* Computed Parameter: Delay_InitialCondition_du
                                        * Referenced by: '<S348>/Delay'
                                        */
  uint8_T Constant1_Value_bj;          /* Computed Parameter: Constant1_Value_bj
                                        * Referenced by: '<S422>/Constant1'
                                        */
  uint8_T Delay_InitialCondition_j0;   /* Computed Parameter: Delay_InitialCondition_j0
                                        * Referenced by: '<S422>/Delay'
                                        */
  uint8_T Constant1_Value_ns;          /* Computed Parameter: Constant1_Value_ns
                                        * Referenced by: '<S429>/Constant1'
                                        */
  uint8_T Delay_InitialCondition_h;    /* Computed Parameter: Delay_InitialCondition_h
                                        * Referenced by: '<S429>/Delay'
                                        */
  uint8_T Constant1_Value_no;          /* Computed Parameter: Constant1_Value_no
                                        * Referenced by: '<S455>/Constant1'
                                        */
  uint8_T Delay_InitialCondition_ja;   /* Computed Parameter: Delay_InitialCondition_ja
                                        * Referenced by: '<S455>/Delay'
                                        */
  uint8_T Constant1_Value_ev;          /* Computed Parameter: Constant1_Value_ev
                                        * Referenced by: '<S475>/Constant1'
                                        */
  uint8_T Delay_InitialCondition_jy;   /* Computed Parameter: Delay_InitialCondition_jy
                                        * Referenced by: '<S475>/Delay'
                                        */
  uint8_T Constant1_Value_o0;          /* Computed Parameter: Constant1_Value_o0
                                        * Referenced by: '<S485>/Constant1'
                                        */
  uint8_T Relay_OnVal_f;               /* Computed Parameter: Relay_OnVal_f
                                        * Referenced by: '<S478>/Relay'
                                        */
  uint8_T Relay_OffVal_k;              /* Computed Parameter: Relay_OffVal_k
                                        * Referenced by: '<S478>/Relay'
                                        */
  uint8_T Constant1_Value_h;           /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S493>/Constant1'
                                        */
  rtP_Baro_Velocity_INS_T Rf_Velocity; /* '<S308>/Rf_Velocity' */
  rtP_Baro_Velocity_INS_T Baro_Velocity;/* '<S308>/Baro_Velocity' */
};

/* Parameters (default storage) */
typedef struct Parameters_INS_T_ Parameters_INS_T;

/* Real-time Model Data Structure */
struct tag_RTM_INS_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern Parameters_INS_T INS_P;

/* Block signals (default storage) */
extern BlockIO_INS_T INS_B;

/* Block states (default storage) */
extern D_Work_INS_T INS_DWork;

/* External inputs (root inport signals with default storage) */
extern ExternalInputs_INS_T INS_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExternalOutputs_INS_T INS_Y;

/* External data declarations for dependent source files */
extern const INS_Out_Bus INS_rtZINS_Out_Bus;/* INS_Out_Bus ground */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern struct_DP7rbDXzvySaL2o76hvHzF INS_PARAM;/* Variable: INS_PARAM
                                                * Referenced by:
                                                *   '<S477>/Gain1'
                                                *   '<S139>/Constant1'
                                                *   '<S438>/Constant1'
                                                *   '<S438>/Gain2'
                                                *   '<S439>/Constant7'
                                                *   '<S439>/Gain3'
                                                *   '<S69>/Gain1'
                                                *   '<S72>/Gain3'
                                                *   '<S76>/Gain'
                                                *   '<S77>/Gain'
                                                *   '<S77>/Gain1'
                                                *   '<S222>/Gain'
                                                *   '<S222>/Gain2'
                                                *   '<S222>/Gain3'
                                                *   '<S223>/pos_delay'
                                                *   '<S232>/pos_delay'
                                                *   '<S232>/vel_delay'
                                                *   '<S244>/Gain'
                                                *   '<S244>/Gain2'
                                                *   '<S245>/Delay'
                                                *   '<S265>/Gain'
                                                *   '<S265>/Gain1'
                                                *   '<S265>/Gain2'
                                                *   '<S266>/delay'
                                                *   '<S274>/Gain'
                                                *   '<S274>/Gain1'
                                                *   '<S274>/Gain2'
                                                *   '<S275>/delay'
                                                *   '<S284>/pos_delay'
                                                *   '<S284>/vel_delay'
                                                *   '<S295>/Gain'
                                                *   '<S295>/Gain1'
                                                *   '<S295>/Gain2'
                                                *   '<S296>/delay'
                                                *   '<S342>/Constant'
                                                *   '<S342>/Constant2'
                                                *   '<S234>/Gain'
                                                *   '<S234>/Gain2'
                                                *   '<S234>/Gain3'
                                                *   '<S235>/Gain'
                                                *   '<S235>/Gain2'
                                                *   '<S235>/Gain3'
                                                *   '<S286>/Gain'
                                                *   '<S286>/Gain1'
                                                *   '<S286>/Gain2'
                                                *   '<S287>/Gain'
                                                *   '<S287>/Gain1'
                                                *   '<S287>/Gain2'
                                                */
extern struct_i6HyuFQRjfkj8sSCv2bg5D INS_EXPORT;/* Variable: INS_EXPORT
                                                 * Referenced by:
                                                 *   '<S4>/Constant'
                                                 *   '<S414>/Constant'
                                                 *   '<S426>/Constant'
                                                 *   '<S452>/Constant'
                                                 *   '<S460>/Constant'
                                                 *   '<S478>/Constant'
                                                 *   '<S488>/Constant'
                                                 *   '<S11>/Constant'
                                                 *   '<S12>/Constant'
                                                 *   '<S13>/Constant'
                                                 *   '<S14>/Constant'
                                                 *   '<S15>/Constant'
                                                 *   '<S16>/Constant'
                                                 *   '<S17>/Constant'
                                                 *   '<S437>/Constant'
                                                 *   '<S97>/Constant1'
                                                 *   '<S365>/Constant'
                                                 *   '<S366>/Constant'
                                                 *   '<S377>/Constant'
                                                 *   '<S378>/Constant'
                                                 *   '<S379>/Constant'
                                                 */

/* Model entry point functions */
extern void INS_init(void);
extern void INS_step(void);

/* Real-time Model object */
extern RT_MODEL_INS_T *const INS_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'INS'
 * '<S1>'   : 'INS/Bus_Constructor'
 * '<S2>'   : 'INS/Data_Fusion'
 * '<S3>'   : 'INS/Sensor_PreProcess'
 * '<S4>'   : 'INS/Bus_Constructor/Counter'
 * '<S5>'   : 'INS/Bus_Constructor/Rotation_Output'
 * '<S6>'   : 'INS/Bus_Constructor/Status_Output'
 * '<S7>'   : 'INS/Bus_Constructor/Translation_Output'
 * '<S8>'   : 'INS/Bus_Constructor/Status_Output/INS_Flag'
 * '<S9>'   : 'INS/Bus_Constructor/Status_Output/INS_Quality'
 * '<S10>'  : 'INS/Bus_Constructor/Status_Output/Sensor_Status'
 * '<S11>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check1'
 * '<S12>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check2'
 * '<S13>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check3'
 * '<S14>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check4'
 * '<S15>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check5'
 * '<S16>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check6'
 * '<S17>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check8'
 * '<S18>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check1/Compare To Constant'
 * '<S19>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check1/Compare To Constant1'
 * '<S20>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check1/Compare To Constant2'
 * '<S21>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check1/Detect Rise Positive'
 * '<S22>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check1/Detect Rise Positive/Positive'
 * '<S23>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check2/Compare To Constant'
 * '<S24>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check2/Compare To Constant1'
 * '<S25>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check2/Compare To Constant2'
 * '<S26>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check2/Detect Rise Positive'
 * '<S27>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check2/Detect Rise Positive/Positive'
 * '<S28>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check3/Compare To Constant'
 * '<S29>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check3/Compare To Constant1'
 * '<S30>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check3/Compare To Constant2'
 * '<S31>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check3/Detect Rise Positive'
 * '<S32>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check3/Detect Rise Positive/Positive'
 * '<S33>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check4/Compare To Constant'
 * '<S34>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check4/Compare To Constant1'
 * '<S35>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check4/Compare To Constant2'
 * '<S36>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check4/Detect Rise Positive'
 * '<S37>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check4/Detect Rise Positive/Positive'
 * '<S38>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check5/Compare To Constant'
 * '<S39>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check5/Compare To Constant1'
 * '<S40>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check5/Compare To Constant2'
 * '<S41>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check5/Detect Rise Positive'
 * '<S42>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check5/Detect Rise Positive/Positive'
 * '<S43>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check6/Compare To Constant'
 * '<S44>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check6/Compare To Constant1'
 * '<S45>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check6/Compare To Constant2'
 * '<S46>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check6/Detect Rise Positive'
 * '<S47>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check6/Detect Rise Positive/Positive'
 * '<S48>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check8/Compare To Constant'
 * '<S49>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check8/Compare To Constant1'
 * '<S50>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check8/Compare To Constant2'
 * '<S51>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check8/Detect Rise Positive'
 * '<S52>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check8/Detect Rise Positive/Positive'
 * '<S53>'  : 'INS/Bus_Constructor/Status_Output/Sensor_Status/Compare To Zero'
 * '<S54>'  : 'INS/Bus_Constructor/Status_Output/Sensor_Status/Compare To Zero1'
 * '<S55>'  : 'INS/Data_Fusion/Rotation_Filter'
 * '<S56>'  : 'INS/Data_Fusion/Translation_Filter'
 * '<S57>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS'
 * '<S58>'  : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess'
 * '<S59>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor'
 * '<S60>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct'
 * '<S61>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update'
 * '<S62>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor/Euler_Angle'
 * '<S63>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor/Psi To DCM'
 * '<S64>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor/Euler_Angle/Quaternion To Euler'
 * '<S65>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor/Euler_Angle/Quaternion To Euler/Quaternion Normalize'
 * '<S66>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor/Euler_Angle/Quaternion To Euler/Quaternion Normalize/Quaternion Modulus'
 * '<S67>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor/Psi To DCM/Rotation Matrix Z'
 * '<S68>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction'
 * '<S69>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Gyro_Bias_Correction'
 * '<S70>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct'
 * '<S71>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/ExternalPos_Correct'
 * '<S72>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct'
 * '<S73>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct1'
 * '<S74>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct'
 * '<S75>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator'
 * '<S76>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct'
 * '<S77>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct'
 * '<S78>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Cross Product'
 * '<S79>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Cross Product/Subsystem'
 * '<S80>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Cross Product/Subsystem1'
 * '<S81>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Cross Product'
 * '<S82>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Saturation'
 * '<S83>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Vector Normalize'
 * '<S84>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Vector Normalize1'
 * '<S85>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Cross Product/Subsystem'
 * '<S86>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Cross Product/Subsystem1'
 * '<S87>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Saturation/Vector Modulus'
 * '<S88>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Estimate_Acc'
 * '<S89>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc'
 * '<S90>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Estimate_Acc/Second Order LPF'
 * '<S91>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc/Bus_Selection'
 * '<S92>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc/Detect Increase'
 * '<S93>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc/GPS_Meas_Acc'
 * '<S94>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc/Valid_Check'
 * '<S95>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/ExternalPos_Correct/psi_err_saturation'
 * '<S96>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/ExternalPos_Correct/psi_err_saturation/Compare To Constant'
 * '<S97>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/Hover_Mag_Lock'
 * '<S98>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/Mag_Measure'
 * '<S99>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/psi_err_saturation'
 * '<S100>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/Hover_Mag_Lock/Compare To Constant1'
 * '<S101>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/Hover_Mag_Lock/Compare To Constant4'
 * '<S102>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/Hover_Mag_Lock/Compare To Zero'
 * '<S103>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/Hover_Mag_Lock/Second Order LPF1'
 * '<S104>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/Mag_Measure/Bias_Estimation'
 * '<S105>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/Mag_Measure/Mag_Heading'
 * '<S106>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/Mag_Measure/Bias_Estimation/Bias'
 * '<S107>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/Mag_Measure/Bias_Estimation/Detect Increase'
 * '<S108>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/Mag_Measure/Mag_Heading/Second Order LPF1'
 * '<S109>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/psi_err_saturation/Compare To Constant'
 * '<S110>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct1/Hover_Heading_Correct'
 * '<S111>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct1/Mag_Heading'
 * '<S112>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct1/Hover_Heading_Correct/Bias_Estimation'
 * '<S113>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct1/Hover_Heading_Correct/Compare To Constant4'
 * '<S114>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct1/Hover_Heading_Correct/Second Order LPF'
 * '<S115>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct1/Hover_Heading_Correct/psi_err_saturation'
 * '<S116>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct1/Hover_Heading_Correct/Bias_Estimation/Bias'
 * '<S117>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Gyro_Bias_Correction/Compare To Constant'
 * '<S118>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Gyro_Bias_Correction/Second Order LPF'
 * '<S119>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Gyro_Bias_Correction/Vector Modulus'
 * '<S120>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update'
 * '<S121>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update1'
 * '<S122>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Gyro_Bias_Update'
 * '<S123>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Multiply1'
 * '<S124>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Normalize1'
 * '<S125>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion To DCM'
 * '<S126>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Multiply1/q_0'
 * '<S127>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Multiply1/q_1'
 * '<S128>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Multiply1/q_2'
 * '<S129>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Multiply1/q_4'
 * '<S130>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Normalize1/Quaternion Modulus'
 * '<S131>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion To DCM/Quaternion Normalize'
 * '<S132>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion To DCM/column_1'
 * '<S133>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion To DCM/column_2'
 * '<S134>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion To DCM/column_3'
 * '<S135>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S136>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update1/Quaternion Modulus'
 * '<S137>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset'
 * '<S138>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude'
 * '<S139>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Sensor_Select'
 * '<S140>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Standstill'
 * '<S141>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Compare To Constant'
 * '<S142>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Compare To Constant1'
 * '<S143>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Detect Rise Positive'
 * '<S144>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Detect Rise Positive1'
 * '<S145>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/GPS_Heading_Reset'
 * '<S146>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Interval Test'
 * '<S147>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Vector Modulus'
 * '<S148>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Vector Modulus1'
 * '<S149>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/sample_valid'
 * '<S150>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/sample_valid1'
 * '<S151>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Detect Rise Positive/Positive'
 * '<S152>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Detect Rise Positive1/Positive'
 * '<S153>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/GPS_Heading_Reset/Detect Rise Positive1'
 * '<S154>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/GPS_Heading_Reset/Detect Rise Positive1/Positive'
 * '<S155>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/sample_valid/valid_samples'
 * '<S156>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/sample_valid1/valid_samples'
 * '<S157>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Cross Product'
 * '<S158>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Cross Product1'
 * '<S159>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion'
 * '<S160>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Heading_Vector'
 * '<S161>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Vector Normalize'
 * '<S162>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Vector Normalize1'
 * '<S163>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Vector Normalize2'
 * '<S164>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Cross Product/Subsystem'
 * '<S165>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Cross Product/Subsystem1'
 * '<S166>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Cross Product1/Subsystem'
 * '<S167>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Cross Product1/Subsystem1'
 * '<S168>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/DCM Trace'
 * '<S169>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace'
 * '<S170>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Positive Trace'
 * '<S171>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(1,1)'
 * '<S172>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(2,2)'
 * '<S173>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(3,3)'
 * '<S174>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/diag(DCM)'
 * '<S175>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S176>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S177>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S178>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S179>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S180>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S181>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S182>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S183>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S184>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S185>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S186>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S187>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S188>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S189>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S190>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S191>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S192>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S193>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Heading_Vector/Psi To DCM'
 * '<S194>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Heading_Vector/Vector Normalize'
 * '<S195>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Heading_Vector/Psi To DCM/Rotation Matrix Z'
 * '<S196>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Standstill/First Order HPF'
 * '<S197>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Standstill/First Order LPF'
 * '<S198>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Standstill/First Order LPF1'
 * '<S199>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Standstill/First Order HPF/First Order LPF'
 * '<S200>' : 'INS/Data_Fusion/Translation_Filter/CF'
 * '<S201>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess'
 * '<S202>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor'
 * '<S203>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter'
 * '<S204>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter'
 * '<S205>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select'
 * '<S206>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/Bus_Select'
 * '<S207>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/Height_Above_Ground'
 * '<S208>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/Local_Position'
 * '<S209>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/Velocity'
 * '<S210>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/WGS84_Position'
 * '<S211>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/WGS84_Position/WGS84_Position'
 * '<S212>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/WGS84_Position/WGS84_Position/safe_divide'
 * '<S213>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/WGS84_Position/WGS84_Position/safe_divide/Zero_Value_Exclusion'
 * '<S214>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct'
 * '<S215>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict'
 * '<S216>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/ExternalPos Correct'
 * '<S217>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct'
 * '<S218>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/OptFlow Correct'
 * '<S219>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/ExternalPos Correct/ExternalPos_Correct'
 * '<S220>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/ExternalPos Correct/ExternalPos_Correct/Detect Change'
 * '<S221>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/ExternalPos Correct/ExternalPos_Correct/Error_Integrate'
 * '<S222>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/ExternalPos Correct/ExternalPos_Correct/Error_Scaling'
 * '<S223>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/ExternalPos Correct/ExternalPos_Correct/Estimate_State'
 * '<S224>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/ExternalPos Correct/ExternalPos_Correct/Measurement'
 * '<S225>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/ExternalPos Correct/ExternalPos_Correct/Measurement/Bias_Estimation'
 * '<S226>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/ExternalPos Correct/ExternalPos_Correct/Measurement/Bias_Estimation/Bias'
 * '<S227>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/ExternalPos Correct/ExternalPos_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S228>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct'
 * '<S229>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct/Detect Change'
 * '<S230>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct/Error_Integrate'
 * '<S231>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct/Error_Scaling'
 * '<S232>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct/Estimate_State'
 * '<S233>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct/Measurement'
 * '<S234>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct/Error_Scaling/GPS_Error_Scaling'
 * '<S235>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct/Error_Scaling/RTK_Error_Scaling'
 * '<S236>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct/Measurement/Bias_Estimation'
 * '<S237>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct/Measurement/Bias_Estimation/Bias'
 * '<S238>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct/Measurement/Bias_Estimation/Bias/Bias_Update'
 * '<S239>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct/Measurement/Bias_Estimation/Bias/Detect Change'
 * '<S240>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS Correct/GPS_Correct/Measurement/Bias_Estimation/Bias/Detect Increase'
 * '<S241>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/OptFlow Correct/OptFlow_Correct'
 * '<S242>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/OptFlow Correct/OptFlow_Correct/Detect Change'
 * '<S243>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/OptFlow Correct/OptFlow_Correct/Error_Integrate'
 * '<S244>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/OptFlow Correct/OptFlow_Correct/Error_Scaling'
 * '<S245>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/OptFlow Correct/OptFlow_Correct/Estimate_State'
 * '<S246>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/OptFlow Correct/OptFlow_Correct/Measurement'
 * '<S247>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate'
 * '<S248>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Update'
 * '<S249>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init'
 * '<S250>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init'
 * '<S251>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init'
 * '<S252>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init/External_Pos_Init'
 * '<S253>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init/GPS_Pos_Init'
 * '<S254>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/GPS_Vel_Init'
 * '<S255>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/OptFlow_Vel_Init'
 * '<S256>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct'
 * '<S257>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict'
 * '<S258>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct'
 * '<S259>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/ExternalPos_Correct'
 * '<S260>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct'
 * '<S261>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct'
 * '<S262>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct'
 * '<S263>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Detect Change'
 * '<S264>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Error_Hold'
 * '<S265>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Error_Scaling'
 * '<S266>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Estimate_States'
 * '<S267>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement'
 * '<S268>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimation'
 * '<S269>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimation/Bias'
 * '<S270>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S271>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/ExternalPos_Correct/ExternalPos_Correct'
 * '<S272>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/ExternalPos_Correct/ExternalPos_Correct/Detect Change'
 * '<S273>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/ExternalPos_Correct/ExternalPos_Correct/Error_Hold'
 * '<S274>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/ExternalPos_Correct/ExternalPos_Correct/Error_Scaling'
 * '<S275>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/ExternalPos_Correct/ExternalPos_Correct/Estimate_States'
 * '<S276>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/ExternalPos_Correct/ExternalPos_Correct/Measurement'
 * '<S277>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/ExternalPos_Correct/ExternalPos_Correct/Measurement/Bias_Estimation'
 * '<S278>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/ExternalPos_Correct/ExternalPos_Correct/Measurement/Bias_Estimation/Bias'
 * '<S279>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/ExternalPos_Correct/ExternalPos_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S280>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct'
 * '<S281>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Detect Change'
 * '<S282>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Error_Hold'
 * '<S283>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Error_Scaling'
 * '<S284>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Estimate_State'
 * '<S285>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement'
 * '<S286>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Error_Scaling/GPS_Error_Scaling'
 * '<S287>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Error_Scaling/RTK_Error_Scaling'
 * '<S288>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation'
 * '<S289>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation/Bias'
 * '<S290>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation/Detect Change'
 * '<S291>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S292>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct/Rangefinder_Correct'
 * '<S293>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct/Rangefinder_Correct/Detect Change'
 * '<S294>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct/Rangefinder_Correct/Error_Hold'
 * '<S295>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct/Rangefinder_Correct/Error_Scaling'
 * '<S296>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct/Rangefinder_Correct/Estimate_State'
 * '<S297>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct/Rangefinder_Correct/Measurement'
 * '<S298>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct/Rangefinder_Correct/Measurement/Bias_Estimation'
 * '<S299>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct/Rangefinder_Correct/Measurement/Bias_Estimation/Bias'
 * '<S300>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct/Rangefinder_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S301>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct/Rangefinder_Correct/Measurement/Bias_Estimation/Detect_Jump_Signal'
 * '<S302>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct/Rangefinder_Correct/Measurement/Bias_Estimation/Detect_Jump_Signal/Compare To Constant'
 * '<S303>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rf_Correct/Rangefinder_Correct/Measurement/Bias_Estimation/Detect_Jump_Signal/Detect Increase'
 * '<S304>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate'
 * '<S305>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Update'
 * '<S306>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init'
 * '<S307>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Height_Init'
 * '<S308>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Velocity_Init'
 * '<S309>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Height_Init/Baro_Reference_Height'
 * '<S310>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Height_Init/External_Pos_Height'
 * '<S311>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Height_Init/GPS_Reference_Height'
 * '<S312>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Height_Init/Rf_Reference_Height'
 * '<S313>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Velocity_Init/Baro_Velocity'
 * '<S314>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Velocity_Init/GPS_Velocity'
 * '<S315>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Velocity_Init/Rf_Velocity'
 * '<S316>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process'
 * '<S317>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control'
 * '<S318>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select'
 * '<S319>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures'
 * '<S320>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Status'
 * '<S321>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Horizontal_Sensor_Select'
 * '<S322>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Vertical_Sensor_Select'
 * '<S323>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Horizontal_Sensor_Select/Compare To Zero1'
 * '<S324>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Horizontal_Sensor_Select/Compare To Zero2'
 * '<S325>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Horizontal_Sensor_Select/Compare To Zero3'
 * '<S326>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Horizontal_Sensor_Select/Compare To Zero4'
 * '<S327>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Horizontal_Sensor_Select/Compare To Zero5'
 * '<S328>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Vertical_Sensor_Select/Compare To Zero1'
 * '<S329>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Vertical_Sensor_Select/Compare To Zero2'
 * '<S330>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Vertical_Sensor_Select/Compare To Zero3'
 * '<S331>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Vertical_Sensor_Select/Compare To Zero4'
 * '<S332>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Vertical_Sensor_Select/Compare To Zero5'
 * '<S333>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Vertical_Sensor_Select/Compare To Zero6'
 * '<S334>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Vertical_Sensor_Select/Compare To Zero7'
 * '<S335>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/Barometer_Meas'
 * '<S336>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/ExternalPos_Meas'
 * '<S337>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/GPS_Meas'
 * '<S338>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/OpticalFlow_Meas'
 * '<S339>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/Rangefinder_Meas'
 * '<S340>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/Barometer_Meas/Second Order LPF'
 * '<S341>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/ExternalPos_Meas/External_Pos_PreProcess'
 * '<S342>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/ExternalPos_Meas/External_Pos_PreProcess/Local_To_Global'
 * '<S343>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/ExternalPos_Meas/External_Pos_PreProcess/Local_To_Global/Ever_Valid'
 * '<S344>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/ExternalPos_Meas/External_Pos_PreProcess/Local_To_Global/Local_Psi'
 * '<S345>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/ExternalPos_Meas/External_Pos_PreProcess/Local_To_Global/Psi To DCM'
 * '<S346>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/ExternalPos_Meas/External_Pos_PreProcess/Local_To_Global/Ever_Valid/Detect Decrease'
 * '<S347>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/ExternalPos_Meas/External_Pos_PreProcess/Local_To_Global/Local_Psi/Detect Increase'
 * '<S348>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/ExternalPos_Meas/External_Pos_PreProcess/Local_To_Global/Local_Psi/Ever_Valid1'
 * '<S349>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/ExternalPos_Meas/External_Pos_PreProcess/Local_To_Global/Psi To DCM/Rotation Matrix Z'
 * '<S350>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Status/Barometer_Status'
 * '<S351>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Status/ExternalPos_Status'
 * '<S352>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Status/GPS_Status'
 * '<S353>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Status/OpticalFlow_Status'
 * '<S354>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Status/Rangefinder_Status'
 * '<S355>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Status/GPS_Status/Compare To Constant'
 * '<S356>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Filter_Reset'
 * '<S357>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid'
 * '<S358>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/WGS84_Reference'
 * '<S359>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Filter_Reset/Detect Rise Positive'
 * '<S360>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Filter_Reset/Detect Rise Positive1'
 * '<S361>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Filter_Reset/Detect Rise Positive/Positive'
 * '<S362>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Filter_Reset/Detect Rise Positive1/Positive'
 * '<S363>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid'
 * '<S364>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid'
 * '<S365>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold'
 * '<S366>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold1'
 * '<S367>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold/Compare To Constant'
 * '<S368>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold/Compare To Constant1'
 * '<S369>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold/Compare To Constant2'
 * '<S370>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold/Detect Rise Positive'
 * '<S371>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold/Detect Rise Positive/Positive'
 * '<S372>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold1/Compare To Constant'
 * '<S373>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold1/Compare To Constant1'
 * '<S374>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold1/Compare To Constant2'
 * '<S375>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold1/Detect Rise Positive'
 * '<S376>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold1/Detect Rise Positive/Positive'
 * '<S377>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold'
 * '<S378>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold1'
 * '<S379>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold2'
 * '<S380>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold/Compare To Constant'
 * '<S381>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold/Compare To Constant1'
 * '<S382>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold/Compare To Constant2'
 * '<S383>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold/Detect Rise Positive'
 * '<S384>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold/Detect Rise Positive/Positive'
 * '<S385>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold1/Compare To Constant'
 * '<S386>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold1/Compare To Constant1'
 * '<S387>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold1/Compare To Constant2'
 * '<S388>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold1/Detect Rise Positive'
 * '<S389>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold1/Detect Rise Positive/Positive'
 * '<S390>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold2/Compare To Constant'
 * '<S391>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold2/Compare To Constant1'
 * '<S392>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold2/Compare To Constant2'
 * '<S393>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold2/Detect Rise Positive'
 * '<S394>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold2/Detect Rise Positive/Positive'
 * '<S395>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/WGS84_Reference/Bus_Constructor'
 * '<S396>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/WGS84_Reference/Bus_Select'
 * '<S397>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/WGS84_Reference/Height_Ref'
 * '<S398>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/WGS84_Reference/Position_Ref'
 * '<S399>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/WGS84_Reference/Height_Ref/Detect Rise Positive3'
 * '<S400>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/WGS84_Reference/Height_Ref/Detect Rise Positive3/Positive'
 * '<S401>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/WGS84_Reference/Position_Ref/Detect Rise Positive3'
 * '<S402>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/WGS84_Reference/Position_Ref/Detect Rise Positive3/Positive'
 * '<S403>' : 'INS/Sensor_PreProcess/AirSpeed_Process'
 * '<S404>' : 'INS/Sensor_PreProcess/Baro_PreProcess'
 * '<S405>' : 'INS/Sensor_PreProcess/ExternalPos_Process'
 * '<S406>' : 'INS/Sensor_PreProcess/GPS_PreProcess'
 * '<S407>' : 'INS/Sensor_PreProcess/IMU_PreProcess'
 * '<S408>' : 'INS/Sensor_PreProcess/MAG_PreProcess'
 * '<S409>' : 'INS/Sensor_PreProcess/OpticalFlow_PreProcess'
 * '<S410>' : 'INS/Sensor_PreProcess/Rangefinder_PreProcess'
 * '<S411>' : 'INS/Sensor_PreProcess/AirSpeed_Process/Calculate_IAS'
 * '<S412>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Pressure_Height'
 * '<S413>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Relative_Height'
 * '<S414>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Sensor_Valid'
 * '<S415>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Relative_Height/Reference_Height'
 * '<S416>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Relative_Height/Sampling'
 * '<S417>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Relative_Height/Sampling/Compare To Constant'
 * '<S418>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Relative_Height/Sampling/Detect Change'
 * '<S419>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Relative_Height/Sampling/Interval Test3'
 * '<S420>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Sensor_Valid/Compare To Constant4'
 * '<S421>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Sensor_Valid/Detect Change'
 * '<S422>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Sensor_Valid/Ever_Valid'
 * '<S423>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Sensor_Valid/Interval Test1'
 * '<S424>' : 'INS/Sensor_PreProcess/Baro_PreProcess/Sensor_Valid/Interval Test2'
 * '<S425>' : 'INS/Sensor_PreProcess/ExternalPos_Process/Bus_Selector'
 * '<S426>' : 'INS/Sensor_PreProcess/ExternalPos_Process/Sensor_Valid'
 * '<S427>' : 'INS/Sensor_PreProcess/ExternalPos_Process/Sensor_Valid/Compare To Constant4'
 * '<S428>' : 'INS/Sensor_PreProcess/ExternalPos_Process/Sensor_Valid/Detect Change'
 * '<S429>' : 'INS/Sensor_PreProcess/ExternalPos_Process/Sensor_Valid/Ever_Valid'
 * '<S430>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Compare To Constant'
 * '<S431>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Compare To Constant1'
 * '<S432>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Data_Scalling'
 * '<S433>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality'
 * '<S434>' : 'INS/Sensor_PreProcess/GPS_PreProcess/WGS84_Model'
 * '<S435>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/Compare To Constant2'
 * '<S436>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/GPS_Status'
 * '<S437>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/check_timeout'
 * '<S438>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/horizontal_quality'
 * '<S439>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/speed_acc'
 * '<S440>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/vertical_quality'
 * '<S441>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/GPS_Status/Compare To Constant'
 * '<S442>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/GPS_Status/Compare To Constant1'
 * '<S443>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/GPS_Status/Ready'
 * '<S444>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/GPS_Status/Ready/valid_samples'
 * '<S445>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/check_timeout/Compare To Constant4'
 * '<S446>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/check_timeout/Detect Change'
 * '<S447>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/horizontal_quality/Second Order LPF'
 * '<S448>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/speed_acc/Second Order LPF'
 * '<S449>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/vertical_quality/Second Order LPF'
 * '<S450>' : 'INS/Sensor_PreProcess/GPS_PreProcess/WGS84_Model/LAT2FLAT Curve'
 * '<S451>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Data_Select'
 * '<S452>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Sensor_Valid'
 * '<S453>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Sensor_Valid/Compare To Constant4'
 * '<S454>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Sensor_Valid/Detect Change'
 * '<S455>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Sensor_Valid/Ever_Valid'
 * '<S456>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Sensor_Valid/Interval Test1'
 * '<S457>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Sensor_Valid/Interval Test3'
 * '<S458>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Bus_Select'
 * '<S459>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process'
 * '<S460>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Sensor_Valid'
 * '<S461>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate'
 * '<S462>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/WMM_Compensation'
 * '<S463>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/WMM_LUT'
 * '<S464>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate/Mag_Quality'
 * '<S465>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate/Mag_Quality/Inclination_Quality_Estimate'
 * '<S466>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate/Mag_Quality/Intensity_Quality_Estimate'
 * '<S467>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate/Mag_Quality/Second Order LPF'
 * '<S468>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate/Mag_Quality/Inclination_Quality_Estimate/Vector Modulus'
 * '<S469>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate/Mag_Quality/Intensity_Quality_Estimate/Vector Modulus'
 * '<S470>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/WMM_Compensation/Rotation Matrix Z'
 * '<S471>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/WMM_Compensation/Vector Normalize'
 * '<S472>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/WMM_Compensation/safe_divide'
 * '<S473>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Sensor_Valid/Compare To Constant4'
 * '<S474>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Sensor_Valid/Detect Change'
 * '<S475>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Sensor_Valid/Ever_Valid'
 * '<S476>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Sensor_Valid/Interval Test1'
 * '<S477>' : 'INS/Sensor_PreProcess/OpticalFlow_PreProcess/Height_Compensation'
 * '<S478>' : 'INS/Sensor_PreProcess/OpticalFlow_PreProcess/Sensor_Valid'
 * '<S479>' : 'INS/Sensor_PreProcess/OpticalFlow_PreProcess/Height_Compensation/DeadZone'
 * '<S480>' : 'INS/Sensor_PreProcess/OpticalFlow_PreProcess/Height_Compensation/First Order LPF'
 * '<S481>' : 'INS/Sensor_PreProcess/OpticalFlow_PreProcess/Height_Compensation/First Order LPF1'
 * '<S482>' : 'INS/Sensor_PreProcess/OpticalFlow_PreProcess/Height_Compensation/DeadZone/Compare To Zero'
 * '<S483>' : 'INS/Sensor_PreProcess/OpticalFlow_PreProcess/Sensor_Valid/Compare To Constant4'
 * '<S484>' : 'INS/Sensor_PreProcess/OpticalFlow_PreProcess/Sensor_Valid/Detect Change'
 * '<S485>' : 'INS/Sensor_PreProcess/OpticalFlow_PreProcess/Sensor_Valid/Ever_Valid'
 * '<S486>' : 'INS/Sensor_PreProcess/OpticalFlow_PreProcess/Sensor_Valid/Interval Test1'
 * '<S487>' : 'INS/Sensor_PreProcess/OpticalFlow_PreProcess/Sensor_Valid/Interval Test2'
 * '<S488>' : 'INS/Sensor_PreProcess/Rangefinder_PreProcess/Sensor_Valid'
 * '<S489>' : 'INS/Sensor_PreProcess/Rangefinder_PreProcess/Subsystem'
 * '<S490>' : 'INS/Sensor_PreProcess/Rangefinder_PreProcess/Tilt_Compensation'
 * '<S491>' : 'INS/Sensor_PreProcess/Rangefinder_PreProcess/Sensor_Valid/Compare To Constant4'
 * '<S492>' : 'INS/Sensor_PreProcess/Rangefinder_PreProcess/Sensor_Valid/Detect Change'
 * '<S493>' : 'INS/Sensor_PreProcess/Rangefinder_PreProcess/Sensor_Valid/Ever_Valid'
 * '<S494>' : 'INS/Sensor_PreProcess/Rangefinder_PreProcess/Sensor_Valid/Interval Test3'
 * '<S495>' : 'INS/Sensor_PreProcess/Rangefinder_PreProcess/Subsystem/Compare To Constant'
 * '<S496>' : 'INS/Sensor_PreProcess/Rangefinder_PreProcess/Subsystem/Compare To Zero'
 */
#endif                                 /* RTW_HEADER_INS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
