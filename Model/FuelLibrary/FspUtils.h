/*
 * FspUtils.h
 *
 * General functions for manipulating FSP components and properties
 *
 */

#ifndef _FSP_UTILS_
#define _FSP_UTILS_
 
/* Include headers */
#include "WrightSolver.h"

/* Definitions Simulink discretes */
#define DISCRETE_ON  1.0
#define DISCRETE_OFF 0.0

/* Description of controls for tank resets */
#define TANK_RESET_NO_RESET -1000.0
#define RESET_NO_RESET      TANK_RESET_NO_RESET

/* Description of controls for pump override */
#define NO_FLOW_OVERRIDE  NO_CURRENT_OVERRIDE /* Must match NoFlowOverride in .m */

/* Special not-a-number values */
#define FLOATING_PRESSURE      FLOATING_VOLTAGE       /* Must match FloatingPressure in .m */
#define NEAR_INFINITE_PRESSURE NEAR_INFINITE_VOLTAGE  /* Must match NearInfiniteVoltage in .m */
#define UNKNOWN_VALUE          1e50                   /* Must match UnknownValue in .m */

/* Pump pressure switch outputs */
#define PUMP_HI_PRESS DISCRETE_OFF
#define PUMP_LO_PRESS DISCRETE_ON

/* A/B Value Tramlines - must match InitModel.m */
#define MIN_A_VALUE 0.5
#define MAX_A_VALUE 1.5
#define MIN_B_VALUE 0.5
#define MAX_B_VALUE 1.5

/* Physical constants */
#define G 9.81
#define TYPICAL_FUEL_DENSITY 797.0 /* kg/m3 */

/* Scaling factors */
#define PERSEC2PERCYCLE        FSP_PERIOD                       /* Translate per-second to per-cycle */
#define MINS2SECS              60.0                             /* Translate mins to secs */
#define PERMIN2PERSEC          (1/MINS2SECS)                    /* Translate per-min to per-sec */
#define KPL2KPM3               1000.0                           /* Translate kg/litre to kg/m3 */
#define KPS2M3PS               (1/TYPICAL_FUEL_DENSITY)         /* Translate mass flow to volume flow */
#define LPM2LPS                (1/MINS2SECS)                    /* Translate litres/min to litres/sec */
#define MM2M                   (1/1000.0)                       /* Translate mm to metres */
#define M2MM                   1000.0                           /* Translate meteres to mm */
#define PSI2PASCAL             6894.757                         /* Translate psi to pascal */
#define BAR2PASCAL             100000.0                         /* Translate bar to pascal */
#define PASCAL2BAR             (1/BAR2PASCAL)                   /* Translate Pascal to bar */
#define PASCAL2PSI             (1/PSI2PASCAL)                   /* Translate Pascal to psi */
#define LITRES2M3              (1/1000.0)                       /* Translate litres to m3 */
#define M32LITRES              (1000.0)                         /* Translate m3 to litres */
#define LPM2M3PS               (LITRES2M3/MINS2SECS)            /* Translate litres-per-minute to m3-per-sec */
#define LPM2KPS                (LPM2M3PS*TYPICAL_FUEL_DENSITY)  /* Translate litres/min to kg/sec */
#define KPS2LPM                (1/LPM2KPS)                      /* Translate kg/sec to litres/min */
#define BARPERLPM2PASCALPERKPS (BAR2PASCAL/LPM2KPS)             /* Translate Bar/(lit/min) to Pascal/(kg/sec) */
#define CM22M2                 (1/10000.0)                      /* Translate cm2 to m2 */
#define M22CM2                 10000.0                          /* Translate m2 to cm2 */

/* Typical system values */
#define ALMOST_ZERO_FLOW            (10.0e-4 * LPM2KPS)               /* Normal leakage is in the order of 10-3 lits/min */
#define ALMOST_ZERO_PRESSURE        1.0                               /* Pascal */
#define ALMOST_ZERO_MASS            1.0							      /* Kg */
#define ALMOST_ZERO_VOLUME          (ALMOST_ZERO_MASS/TYPICAL_FUEL_DENSITY)
#define NORMAL_PUMP_PRESSURE        (1.0 * BAR2PASCAL)                /* Normal pump pressure is in the order of 1 bar */
#define NORMAL_BOWSER_PRESSURE      (2.0 * BAR2PASCAL)                /* Normal bowser pressure is in the order of 2 bar */
#define NORMAL_BOWSER_TEMPERATURE   100.0
#define TYPICAL_AIR_TEMP            5.0
#define TYPICAL_FLOW                (10.0 * LPM2KPS)                  /* Normal flow is in the order of 10's lits/min */
#define TYPICAL_DENSITY             800.0                             /* kg/m3 */
#define TYPICAL_NRV_LEAKAGE_FLOW    (TYPICAL_FLOW/50.0)
#define TYPICAL_GRAVITY_FLOW        (TYPICAL_FLOW/2.0)                /* Typical gravity transfer flow is half pumped flow */
#define TYPICAL_PRESSURE            (0.5 * NORMAL_PUMP_PRESSURE)      /* Typical pressure is pump pressure with some drop */
#define TYPICAL_TANK_VOLUME         (100.0 * LITRES2M3)               /* Normal quantity is 100's of litres's */
#define TYPICAL_TANK_TEMP           20.0                              /* Normal temp is about 20 degress C */
#define TYPICAL_A_VALUE             1.000384
#define TYPICAL_B_VALUE             1.1492
#define TYPICAL_PRESSURE_SWITCH_ON  (0.43 * BAR2PASCAL)               /* 6.0 psig */
#define TYPICAL_PRESSURE_SWITCH_OFF (0.29 * BAR2PASCAL)               /* 4.0 psig */
#define TYPICAL_JET_PUMP_GAIN       2.0
#define TYPICAL_SCAVENGE_PUMP_GAIN  1.5
#define MODEL_CONTROL_JET_PUMP_GAIN -1.0                              /* Allows gain to be calculated in model */
#define TYPICAL_SURGETANK_BACK_RES  (1.0e-4 * BARPERLPM2PASCALPERKPS) /* Pascal/kgs-1 */
#define TYPICAL_VENTTANK_BACK_RES   (1.0e-4 * BARPERLPM2PASCALPERKPS) /* Pascal/kgs-1 */
#define TYPICAL_ORIFACE_RES         (1.0e-3 * BARPERLPM2PASCALPERKPS) /* Pascal/kgs-1 */
#define TYPICAL_ATMOS_PRESS         (1.0    * BAR2PASCAL)             /* Pascal */

/* Prototypes to external data */
#define MAX_PARAM_STR_SIZE 200
extern char sfuncCName[MAX_PARAM_STR_SIZE+1];

/* Prototypes to external functions */
void   ProportionalMix(double,double,double,double,double *,int *);
double Volume2Mass(double,double);
double Temperature2Dielectric(double,double);
double Temperature2Density(double,double,double);
void   ClearFspReset(int);
void   ClearTankReset(int);
void   ClearPipeReset(int);
void   SetValve(int,double);
void   Init1InputValve(int,double);
void   Init2InputValve(int,double);
#ifdef FSP_V1
void   InitPump(int,double);
#else
void   InitPump(int,double,double);
#endif
void   InitPressureLimitedPump(int,double,double,double);
void   InitPressureSwitch(int);
void   InitTank(int);
void   InitPipe(int) ;
void   InitBowser(int) ;
void   InitJetPump(int,double,double);
int    FindFspSignalIndexByName(char *);
char   *FindFspSignalNameByIndex(int);

#endif

