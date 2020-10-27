/**************************************************************************
 **         (c) Airbus UK Ltd 2006                                       **
 **         PROJECT : A330/A340 Fuel Avionics rig                        **
 **            FILE : InterfaceCommon.c                                  **
 **          AUTHOR : Stephen Burnell          			                 **
 **           ISSUE : 1.0                                                **
 **   CREATION DATE : 20 February 2006                                   **
 **      DESIGN REF :                                                    **
 **   SOFTWARE TASK :                                                    **
 **************************************************************************
 **          MODULE : VolHeightTranslation                               **
 **************************************************************************
 **   MODIFICATION HISTORY :                                             **
 **									                                     **
 **		Version 1 :  Initial Issue                                       **
 **             A330 tank probe signal array definitions                 **
 **             A330 tank ID naming conventions			                 **
 **************************************************************************/

/*
 * InterfaceCommon.h
 *
 * Shared interface definitions 
 *
 * Generally should match with definitions in AcModel\InitModel.m
 *
 */

#ifndef INTERFACE_COMMON_H
#define INTERFACE_COMMON_H

/* Overide RTW time stepping */
#ifdef WIN32
#ifdef rtmIsSampleHit
#undef rtmIsSampleHit
#define rtmIsSampleHit(x,y,z) 1
#endif
#endif

/* System sampling period */
#define MAIN_SAMPLING_PERIOD 0.25 /* sec */

/******************************************************************************************************************/
/* Offsets for Extmodels - AC Model */
#define EXTMODELS_ACMODEL_OP_WINGS_UP_OFFSET	0
#define EXTMODELS_ACMODEL_OP_PITCH_OFFSET		1
#define EXTMODELS_ACMODEL_OP_ROLL_OFFSET		2
#define EXTMODELS_ACMODEL_OP_HTPA_OFFSET		3
#define EXTMODELS_ACMODEL_OP_AIRTEMP_OFFSET		4

#define EXTMODELS_ACMODEL_IP_WINGS_UP_OFFSET	0
#define EXTMODELS_ACMODEL_IP_PITCH_OFFSET		1
#define EXTMODELS_ACMODEL_IP_ROLL_OFFSET		2
#define EXTMODELS_ACMODEL_IP_NORM_ACCEL_OFFSET	3
#define EXTMODELS_ACMODEL_IP_ALTITUDE_OFFSET	4
#define EXTMODELS_ACMODEL_IP_AIRTEMP_OFFSET		5
#define EXTMODELS_ACMODEL_IP_TXMODE_AUTO_OFFSET	6
#define EXTMODELS_ACMODEL_IP_TXMODE_ON_OFFSET	7
#define EXTMODELS_ACMODEL_IP_HTPA_OFFSET		8

/* Offsets for Extmodels - ADIRU */
#define EXTMODELS_ADIRU_OP_ALTITUDE_203_VALUE_OFFSET		0
#define EXTMODELS_ADIRU_OP_ALTITUDE_203_SSM_OFFSET			1
#define EXTMODELS_ADIRU_OP_ALTITUDE_203_SDI_OFFSET			2
#define EXTMODELS_ADIRU_OP_AIR_TEMP_211_VALUE_OFFSET		3
#define EXTMODELS_ADIRU_OP_AIR_TEMP_211_SSM_OFFSET			4
#define EXTMODELS_ADIRU_OP_AIR_TEMP_211_SDI_OFFSET			5

#define EXTMODELS_ADIRU_OP_LONG_ACCEL_331_VALUE_OFFSET		0
#define EXTMODELS_ADIRU_OP_LONG_ACCEL_331_SSM_OFFSET		1
#define EXTMODELS_ADIRU_OP_LONG_ACCEL_331_SDI_OFFSET		2
#define EXTMODELS_ADIRU_OP_LAT_ACCEL_332_VALUE_OFFSET		3
#define EXTMODELS_ADIRU_OP_LAT_ACCEL_332_SSM_OFFSET			4
#define EXTMODELS_ADIRU_OP_LAT_ACCEL_332_SDI_OFFSET			5
#define EXTMODELS_ADIRU_OP_NORM_ACCEL_333_VALUE_OFFSET		6
#define EXTMODELS_ADIRU_OP_NORM_ACCEL_333_SSM_OFFSET		7
#define EXTMODELS_ADIRU_OP_NORM_ACCEL_333_SDI_OFFSET		8

#define EXTMODELS_ADIRU_IP_AC_PITCH_OVRD_OFFSET				0
#define EXTMODELS_ADIRU_IP_AC_ROLL_OVRD_OFFSET				1
#define EXTMODELS_ADIRU_IP_AC_NORM_ACCEL_OVRD_OFFSET		2
#define EXTMODELS_ADIRU_IP_AC_SET_PITCH_OVRD_OFFSET			3
#define EXTMODELS_ADIRU_IP_AC_SET_ROLL_OVRD_OFFSET			4
#define EXTMODELS_ADIRU_IP_AC_SET_NORM_ACCEL_OVRD_OFFSET	5
#define EXTMODELS_ADIRU_IP_SET_SSM_203_OVRD_OFFSET			6
#define EXTMODELS_ADIRU_IP_SSM_203_OVRD_VAL_OFFSET			7
#define EXTMODELS_ADIRU_IP_SET_SDI_203_OVRD_OFFSET			8
#define EXTMODELS_ADIRU_IP_SDI_203_OVRD_VAL_OFFSET			9
#define EXTMODELS_ADIRU_IP_ALT_MASTER_OVRD_OFFSET			10
#define EXTMODELS_ADIRU_IP_AC_ALTITUDE_OVRD_VAL_OFFSET		11
#define EXTMODELS_ADIRU_IP_SET_SSM_211_OVRD_OFFSET			12
#define EXTMODELS_ADIRU_IP_SSM_211_OVRD_VAL_OFFSET			13
#define EXTMODELS_ADIRU_IP_SET_SDI_211_OVRD_OFFSET			14
#define EXTMODELS_ADIRU_IP_SDI_211_OVRD_VAL_OFFSET			15
#define EXTMODELS_ADIRU_IP_TEMP_MASTER_OVRD_OFFSET			16
#define EXTMODELS_ADIRU_IP_TEMP_OVRD_VAL_OFFSET		17
#define EXTMODELS_ADIRU_IP_SET_SSM_331_OVRD_OFFSET			18
#define EXTMODELS_ADIRU_IP_SSM_331_OVRD_VAL_OFFSET			19
#define EXTMODELS_ADIRU_IP_SET_SDI_331_OVRD_OFFSET			20
#define EXTMODELS_ADIRU_IP_SDI_331_OVRD_VAL_OFFSET			21
#define EXTMODELS_ADIRU_IP_LONG_ACCEL_MASTER_OVRD_OFFSET			22
#define EXTMODELS_ADIRU_IP_LONG_ACCEL_OVRD_VAL_OFFSET		23
#define EXTMODELS_ADIRU_IP_SET_SSM_332_OVRD_OFFSET			24
#define EXTMODELS_ADIRU_IP_SSM_332_OVRD_VAL_OFFSET			25
#define EXTMODELS_ADIRU_IP_SET_SDI_332_OVRD_OFFSET			26
#define EXTMODELS_ADIRU_IP_SDI_332_OVRD_VAL_OFFSET			27
#define EXTMODELS_ADIRU_IP_LAT_ACCEL_MASTER_OVRD_OFFSET			28
#define EXTMODELS_ADIRU_IP_LAT_ACCEL_OVRD_VAL_OFFSET		29
#define EXTMODELS_ADIRU_IP_SET_SSM_333_OVRD_OFFSET			30
#define EXTMODELS_ADIRU_IP_SSM_333_OVRD_VAL_OFFSET			31
#define EXTMODELS_ADIRU_IP_SET_SDI_333_OVRD_OFFSET			32
#define EXTMODELS_ADIRU_IP_SDI_333_OVRD_VAL_OFFSET			33
#define EXTMODELS_ADIRU_IP_NORM_ACCEL_MASTER_OVRD_OFFSET			34
#define EXTMODELS_ADIRU_IP_NORM_ACCEL_OVRD_VAL_OFFSET		35

/* Offsets for Extmodels - PRIM FCDC */
#define EXTMODELS_PRIMFCDC_OP_ARINC_315_HTPA_OFFSET			0
#define EXTMODELS_PRIMFCDC_OP_ARINC_315_SSM_OFFSET			1
#define EXTMODELS_PRIMFCDC_OP_ARINC_315_SDI_OFFSET			2

#define EXTMODELS_PRIMFCDC_IP_HTPA_OVRD_VAL_OFFSET	        0
#define EXTMODELS_PRIMFCDC_IP_SET_HTPA_OVRD_OFFSET			1
#define EXTMODELS_PRIMFCDC_IP_SET_HTPA_MASTER_OVRD_OFFSET			2
#define EXTMODELS_PRIMFCDC_IP_SSM_OVRD_VAL_OFFSET			3
#define EXTMODELS_PRIMFCDC_IP_SET_SSM_OVRD_OFFSET			4
#define EXTMODELS_PRIMFCDC_IP_SDI_OVRD_VAL_OFFSET			5
#define EXTMODELS_PRIMFCDC_IP_SET_SDI_OVRD_OFFSET			6


/* Offsets for Extmodels - FMS */
#define EXTMODELS_FMS_OP_ZFCG_VALUE_OFFSET					0
#define EXTMODELS_FMS_OP_ZFCG_SSM_OFFSET					1
#define EXTMODELS_FMS_OP_ZFCG_SDI_OFFSET					2
#define EXTMODELS_FMS_OP_ZFW_VALUE_OFFSET					3
#define EXTMODELS_FMS_OP_ZFW_SSM_OFFSET						4
#define EXTMODELS_FMS_OP_ZFW_SDI_OFFSET						5
#define EXTMODELS_FMS_OP_JFGW_VALUE_OFFSET					6
#define EXTMODELS_FMS_OP_JFGW_SSM_OFFSET					7
#define EXTMODELS_FMS_OP_JFGW_SDI_OFFSET					8
#define EXTMODELS_FMS_OP_ACGW_VALUE_OFFSET					9
#define EXTMODELS_FMS_OP_ACGW_SSM_OFFSET					10
#define EXTMODELS_FMS_OP_ACGW_SDI_OFFSET					11
#define EXTMODELS_FMS_OP_AXCG_VALUE_OFFSET					12
#define EXTMODELS_FMS_OP_AXCG_SSM_OFFSET					13
#define EXTMODELS_FMS_OP_AXCG_SDI_OFFSET					14
#define EXTMODELS_FMS_OP_PFQ_VALUE_OFFSET					15
#define EXTMODELS_FMS_OP_PFQ_SSM_OFFSET						16
#define EXTMODELS_FMS_OP_PFQ_SDI_OFFSET						17
#define EXTMODELS_FMS_OP_ZFW_REINIT_BIT_OFFSET				18
#define EXTMODELS_FMS_OP_RTD_VALUE_OFFSET					19
#define EXTMODELS_FMS_OP_RTD_SSM_OFFSET						20
#define EXTMODELS_FMS_OP_RTD_SDI_OFFSET						21
#define EXTMODELS_FMS_OP_ZFCG_REINIT_BIT_OFFSET				22
#define	EXTMODELS_FMS_OP_ACGW_REINIT_BIT_OFFSET				23
#define EXTMODELS_FMS_OP_AXCG_REINIT_BIT_OFFSET				24
#define EXTMODELS_FMS_OP_PFQ_REINIT_BIT_OFFSET				25

#define EXTMODELS_FMS_IP_ZFW_OFFSET							0
#define EXTMODELS_FMS_IP_ZFCG_OFFSET						1
#define EXTMODELS_FMS_IP_JFGW_OFFSET						2
#define EXTMODELS_FMS_IP_ACGW_OFFSET						3
#define EXTMODELS_FMS_IP_AXCG_OFFSET						4
#define EXTMODELS_FMS_IP_RTD_OFFSET							5
#define EXTMODELS_FMS_IP_SET_SSM_077_OVRD_OFFSET			6
#define EXTMODELS_FMS_IP_SSM_077_OVRD_VAL_OFFSET			7
#define EXTMODELS_FMS_IP_SET_SDI_077_OVRD_OFFSET			8
#define EXTMODELS_FMS_IP_SDI_077_OVRD_VAL_OFFSET			9
#define EXTMODELS_FMS_IP_SET_SSM_074_OVRD_OFFSET			10
#define EXTMODELS_FMS_IP_SSM_074_OVRD_VAL_OFFSET			11
#define EXTMODELS_FMS_IP_SET_SDI_074_OVRD_OFFSET			12
#define EXTMODELS_FMS_IP_SDI_074_OVRD_VAL_OFFSET			13
#define EXTMODELS_FMS_IP_SET_SSM_064_OVRD_OFFSET			14
#define EXTMODELS_FMS_IP_SSM_064_OVRD_VAL_OFFSET			15
#define EXTMODELS_FMS_IP_SET_SDI_064_OVRD_OFFSET			16
#define EXTMODELS_FMS_IP_SDI_064_OVRD_VAL_OFFSET			17
#define EXTMODELS_FMS_IP_SET_SSM_075_OVRD_OFFSET			18
#define EXTMODELS_FMS_IP_SSM_075_OVRD_VAL_OFFSET			19
#define EXTMODELS_FMS_IP_SET_SDI_075_OVRD_OFFSET			20
#define EXTMODELS_FMS_IP_SDI_075_OVRD_VAL_OFFSET			21
#define EXTMODELS_FMS_IP_SET_SSM_076_OVRD_OFFSET			22
#define EXTMODELS_FMS_IP_SSM_076_OVRD_VAL_OFFSET			23
#define EXTMODELS_FMS_IP_SET_SDI_076_OVRD_OFFSET			24
#define EXTMODELS_FMS_IP_SDI_076_OVRD_VAL_OFFSET			25
#define EXTMODELS_FMS_IP_PFQ_OFFSET							26
#define EXTMODELS_FMS_IP_SET_SSM_250_OVRD_OFFSET			27
#define EXTMODELS_FMS_IP_SSM_250_OVRD_VAL_OFFSET			28
#define EXTMODELS_FMS_IP_SET_SDI_250_OVRD_OFFSET			29
#define EXTMODELS_FMS_IP_SDI_250_OVRD_VAL_OFFSET			30
#define EXTMODELS_FMS_IP_SET_MASTER_077_OVRD_OFFSET			31
#define EXTMODELS_FMS_IP_SET_MASTER_064_OVRD_OFFSET			32
#define EXTMODELS_FMS_IP_SET_MASTER_075_OVRD_OFFSET			33
#define EXTMODELS_FMS_IP_SET_MASTER_074_OVRD_OFFSET			34
#define EXTMODELS_FMS_IP_SET_MASTER_076_OVRD_OFFSET			35
#define EXTMODELS_FMS_IP_SET_MASTER_250_OVRD_OFFSET			36
#define EXTMODELS_FMS_IP_SET_MASTER_251_OVRD_OFFSET			37
#define EXTMODELS_FMS_IP_SSM_251_OVRD_VAL_OFFSET			38
#define EXTMODELS_FMS_IP_SDI_251_OVRD_VAL_OFFSET			39

/* Offsets for ExtModels - FMS Simulation Control */
#define EXTMODELS_FMSC_IP_REINIT_PERIOD_OFFSET			0
#define EXTMODELS_FMSC_IP_REINIT_SIGNAL_OFFSET				1
#define EXTMODELS_FMSC_IP_ON_GROUND_OFFSET					2
#define EXTMODELS_FMSC_IP_END_OF_FLIGHT_OFFSET				3
#define EXTMODELS_FMSC_IP_PFQ_TS_OFFSET				4
#define EXTMODELS_FMSC_IP_FUEL_TS_OFFSET				5
#define EXTMODELS_FMSC_IP_WEIGHT_TS_OFFSET				6
#define EXTMODELS_FMSC_IP_JFGW_TS_OFFSET				7
#define EXTMODELS_FMSC_IP_RTD_TS_OFFSET				8
#define EXTMODELS_FMSC_IP_RTD_FIX_OFFSET				9

/* Offsets for Extmodels - SFCC */
#define EXTMODELS_SFCC_OP_SLATS_EXTENDED_OFFSET				0
#define EXTMODELS_SFCC_OP_SLATS_LEVER_UP_OFFSET				1

#define EXTMODELS_SFCC_IP_SLATS_EXTENDED_OFFSET				0
#define EXTMODELS_SFCC_IP_SLATS_LEVER_UP_OFFSET				1
#define EXTMODELS_SFCC_IP_SLATS_EXTEND_DELAY_OFFSET			2
#define EXTMODELS_SFCC_IP_AUTO_SLAT_EXTEND_OFFSET			3
#define EXTMODELS_SFCC_IP_AUTO_SLAT_ENABLE_OFFSET			4

/* Offsets for Extmodels - LG */
#define EXTMODELS_LG_OP_GEAR_LEVER_DOWN_OFFSET				0
#define EXTMODELS_LG_OP_GEAR_LOCK_OFFSET					1
#define EXTMODELS_LG_OP_WOW_OFFSET							2

#define EXTMODELS_LG_IP_AUTO_GEAR_DELAY_OFFSET				0
#define EXTMODELS_LG_IP_AUTO_GEAR_DOWN_OFFSET				1
#define EXTMODELS_LG_IP_AUTO_GEAR_ENABLED_OFFSET			2
#define EXTMODELS_LG_IP_AUTO_GEAR_DOWN_OVRD_OFFSET			3
#define EXTMODELS_LG_IP_AUTO_GEAR_LOCK_OVRD_OFFSET			4
#define EXTMODELS_LG_IP_AUTO_WOW_OVRD_OFFSET				5

/* Offsets for Extmodels - APU */
#define EXTMODELS_APU_OP_APU_LINE_VENT_OFFSET				0
#define EXTMODELS_APU_OP_APU_FUEL_COMMAND_OFFSET			1
#define EXTMODELS_APU_OP_APU_FIRE_EMERGENCY_OFFSET			2
#define EXTMODELS_APU_OP_APU_AFT_PUMP_PRESS_OFFSET			3
#define EXTMODELS_APU_OP_APU_SPARE_PRESS_OFFSET				4
#define EXTMODELS_APU_OP_APU_FSP_THROTTLE_OFFSET			5

#define EXTMODELS_APU_IP_APU_LINE_VENT_OFFSET				0
#define EXTMODELS_APU_IP_APU_FUEL_COMMAND_OFFSET			1
#define EXTMODELS_APU_IP_APU_FIRE_EMERGENCY_OFFSET			2
#define EXTMODELS_APU_IP_APU_AFT_PUMP_PRESS_OFFSET			3
#define EXTMODELS_APU_IP_APU_SPARE_PRESS_OFFSET				4
#define EXTMODELS_APU_IP_APU_FSP_THROTTLE_OFFSET			5

/******************************************************************************************************************/
/* Offsets for FSP Model */
/* Description of offsets to generate indices for volumetric pipe control */
#define PIPE_SET_MAX_VOL_OFFSET   0
#define PIPE_RESET_MASS_OFFSET    1
#define PIPE_RESET_TEMP_OFFSET    2
#define PIPE_RESET_A_OFFSET       3
#define PIPE_RESET_B_OFFSET       4
#define PIPE_OVERRIDE_MASS_OFFSET 5
#define PIPE_OVERRIDE_TEMP_OFFSET 6
#define PIPE_OVERRIDE_A_OFFSET    7
#define PIPE_OVERRIDE_B_OFFSET    8
#define PIPE_CON_SIZE             9

/* Description of offsets to generate indices for volumetric pipe instrumentation */
#define PIPE_INST_MAX_VOL_OFFSET 0
#define PIPE_INST_MASS_OFFSET    1
#define PIPE_INST_TEMP_OFFSET    2
#define PIPE_INST_A_OFFSET       3
#define PIPE_INST_B_OFFSET       4
#define PIPE_INST_HEIGHT1_OFFSET 5
#define PIPE_INST_INFLOW1_OFFSET 6
#define PIPE_INST_HEIGHT2_OFFSET 7
#define PIPE_INST_INFLOW2_OFFSET 8
#define PIPE_INST_SIZE           9

/* Description of offsets to generate indices for common tank config signal */
#define TANK_ERROR_OFFSET					0
#define TANK_LEAKAGE_OFFSET					1
#define TANK_CONDUCTANCE_OFFSET				2
#define TANK_RESET_MASS_OFFSET				3
#define TANK_RESET_TEMP_OFFSET				4
#define TANK_RESET_A_OFFSET					5
#define TANK_RESET_B_OFFSET					6
#define TANK_OVERRIDE_MASS_OFFSET			7
#define TANK_OVERRIDE_TEMP_OFFSET			8
#define TANK_OVERRIDE_A_OFFSET				9
#define TANK_OVERRIDE_B_OFFSET				10
#define TANK_SIZE							11

/* Description of offsets to generate indices for common tank instrumentation signal */
#define TANK_INST_MAX_VOL_OFFSET			0
#define TANK_INST_MASS_OFFSET				1
#define TANK_INST_VOLUME_OFFSET				2
#define TANK_INST_SURFACE_HEIGHT_OFFSET		3
#define TANK_INST_FLOW_OFFSET				4
#define TANK_INST_TEMP_OFFSET				5
#define TANK_INST_A_OFFSET					6
#define TANK_INST_B_OFFSET					7
#define TANK_INST_CG_VERT_OFFSET			8
#define TANK_INST_CG_LONG_OFFSET			9
#define TANK_INST_CG_LAT_OFFSET				10
#define TANK_INST_HEAD_PRESS_OFFSET			11
#define TANK_INST_VERT_POS_OFFSET			12
#define TANK_INST_LONG_POS_OFFSET			13
#define TANK_INST_LAT_POS_OFFSET			14
#define TANK_INST_INLET1_HEIGHT_OFFSET		15
#define TANK_INST_INLET2_HEIGHT_OFFSET		16
#define TANK_INST_INLET3_HEIGHT_OFFSET		17
#define TANK_INST_OUTLET1_HEIGHT_OFFSET		18
#define TANK_INST_OUTLET2_HEIGHT_OFFSET		19
#define TANK_INST_SIZE						20

/* Description of offsets to generate indices for engine control signal */
#define ENGINE_THROTTLE_OFFSET				0
#define ENGINE_FUEL_METER_RESET_OFFSET		1

/* Description of offsets to generate indices for engine/APU instrumentation signal */
#define ENGINE_BURN_METER_OFFSET			0

/* Description of offsets to generate indices for bowser control signal */
#define BOWSER_RESET_PRES_OFFSET			0
#define BOWSER_RESET_TEMP_OFFSET			1
#define BOWSER_RESET_A_OFFSET				2
#define BOWSER_RESET_B_OFFSET				3
#define BOWSER_RESET_REFUEL_METER_OFFSET	4
#define BOWSER_RESET_DEFUEL_METER_OFFSET	5

/* Description of offsets to generate indices for pump status signal */
#define PUMP_CONTACT_OFFSET					0
#define PUMP_STAT_OFFSET					1
#define PUMP_POS_OFFSET						2
#define PUMP_FLOW_OFFSET					3

/* Description of offsets to generate indices for pump control signal */
#define PUMP_EN_OFFSET						0
#define PUMP_SW_TIME_OFFSET					1
#define PUMP_ON_PRESS_OFFSET				2
#define PUMP_OFF_PRESS_OFFSET				3
#define PUMP_ERROR_OFFSET					4
#define PUMP_MAX_PRESS_OFFSET				5

/* Description of offsets to generate indices for valve instrumentation signal */
#define VALVE_STAT_OPEN_OFFSET				0
#define VALVE_STAT_CLOSED_OFFSET			1
#define VALVE_POS_OFFSET					2
#define VALVE_FLOW_OFFSET					3
#define VALVE_INST_SIZE						4

/* Description of offsets to generate indices for 1 input valve control signal */
#define VALVE1IP_CMD_OPEN_OFFSET			0
#define VALVE1IP_SW_TIME_OFFSET				1
#define VALVE1IP_ERROR_OFFSET				2

/* Description of offsets to generate indices for 2 input valve control signal */
#define VALVE2IP_CMD_OPEN_OFFSET			0
#define VALVE2IP_CMD_CLOSE_OFFSET			1
#define VALVE2IP_SW_TIME_OFFSET				2
#define VALVE2IP_ERROR_OFFSET				3

/* Description of offsets to generate indices for valve injected error codes */
#define VALVE_NO_ERROR						0
#define VALVE_FLAP_OPEN_ERROR				1
#define VALVE_FLAP_SHUT_ERROR				2

/* Description of offsets to generate indices for valve instrumentation signal */
#define VALVE_STAT_OPEN_OFFSET				0
#define VALVE_STAT_CLOSED_OFFSET			1
#define VALVE_POS_OFFSET					2
#define VALVE_FLOW_OFFSET					3
#define VALVE_INST_SIZE						4

/* Description of offsets to generate indices for aircraft model control signal */
#define AC_VARIENT_OFFSET					0
#define AC_WING_BEND_OFFSET					1
#define AC_AIR_TEMP_OFFSET					2
#define AC_EFF_PITCH_OFFSET					3
#define AC_EFF_ROLL_OFFSET					4
#define AC_TAIL_ANGLE_OFFSET				5
#define AC_POSITION_ID_OFFSET				6

/* Description of offsets to generate indices for probes instrumentation signal */
#define TANK_PRB_01A_OFFSET					0
#define TANK_PRB_01B_OFFSET					1
#define TANK_PRB_02A_OFFSET					2
#define TANK_PRB_02B_OFFSET					3
#define TANK_PRB_03A_OFFSET					4
#define TANK_PRB_03B_OFFSET					5
#define TANK_PRB_04A_OFFSET					6
#define TANK_PRB_04B_OFFSET					7
#define TANK_PRB_05A_OFFSET					8
#define TANK_PRB_05B_OFFSET					9
#define TANK_PRB_06A_OFFSET					10
#define TANK_PRB_06B_OFFSET					11
#define TANK_PRB_07A_OFFSET					12
#define TANK_PRB_07B_OFFSET					13
#define TANK_PRB_08A_OFFSET					14
#define TANK_PRB_08B_OFFSET					15
#define TANK_PRB_09A_OFFSET					16
#define TANK_PRB_09B_OFFSET					17
#define TANK_PRB_10A_OFFSET					18
#define TANK_PRB_10B_OFFSET					19
#define TANK_PRB_11A_OFFSET					20
#define TANK_PRB_11B_OFFSET					21
#define TANK_PRB_12A_OFFSET					22
#define TANK_PRB_12B_OFFSET					23
#define TANK_PRB_13A_OFFSET					24
#define TANK_PRB_13B_OFFSET					25
#define TANK_PROBE_FTS_01_OFFSET			26
#define TANK_PROBE_FTS_02_OFFSET			27
#define TANK_PROBE_DENS_LWR_OFFSET			28
#define TANK_PROBE_DENS_UPR_OFFSET			29
#define TANK_PROBE_DUMMY_1_OFFSET			30
#define TANK_PROBE_DUMMY_2_OFFSET			31
#define TANK_PROBE_LL_SENS_01_OFFSET		32
#define TANK_PROBE_LL_SENS_02_OFFSET		33
#define TANK_PROBE_LL_SENS_03_OFFSET		34
#define TANK_PROBE_ETOPS_OFFSET				35
#define TANK_PROBE_HL_SENS_01_OFFSET		36
#define TANK_PROBE_HL_SENS_02_OFFSET		37
#define TANK_PROBE_COMP_OFFSET				38
#define	TANK_PROBE_INLET1_OFFSET			39
#define TANK_PROBE_INLET2_OFFSET			40
#define TANK_PROBE_INLET3_OFFSET			41
#define TANK_PROBE_OUTLET1_OFFSET			42
#define TANK_PROBE_OUTLET2_OFFSET			43
#define TANK_PROBE_DUMMY_3_OFFSET			44
#define TANK_PROBE_DUMMY_4_OFFSET			45
#define TANK_PROBE_DUMMY_5_OFFSET			46
#define TANK_PROBE_DUMMY_6_OFFSET			47
#define TANK_PROBE_DUMMY_7_OFFSET			48
#define TANK_PROBE_DUMMY_8_OFFSET			49

/* Description of offsets to generate indices for jet pump instrumentation signal */
#define JETPUMP_CLACKVALVEFLOW_OFFSET		0
#define JETPUMP_COLOVERFLOW_OFFSET			1
#define JETPUMP_FD_JET_CONFLOW_OFFSET		2
#define JETPUMP_FD_JET_FDFLOW_OFFSET		3
#define JETPUMP_FD_JET_OPFLOW_OFFSET		4

#define PUMP_NO_ERROR         0
#define PUMP_NRV_OPEN_ERROR   1
#define TANK_NO_ERROR         0
#define TANK_EMPTY_FLOW_ERROR 1

/*
Definition of Tank probe signal array 
- 26 probes
- 2 temp sens
- 2 densitometers
- 2 spare
- 3 low level sens
- 1 etops warn sens
- 2 hi level sens
- 1 compensator
- 6 inlets
- 5 outlets
*/

#define TANK_PROBES							(26 + 2 + 2 + 2 + 3 + 1 + 2 + 1 + 6 + 5)
#define SIMULATED_PROBE_ARRAY_SIZE			15

/* Description of offsets to generate indices for T Junction instrumentation signal */
#define TJ_INST_HEIGHT_OFFSET	    0
#define TJ_INST_CONNECTED_OFFSET	1
#define TJ_INST_PRES_OFFSET			2
#define TJ_INST_TEMP_OFFSET			3
#define TJ_INST_A_OFFSET			4
#define TJ_INST_B_OFFSET			5
#define TJ_INST_FLOW1_OFFSET        6
#define TJ_INST_FLOW2_OFFSET        7
#define TJ_INST_FLOW3_OFFSET        8
#define TJ_INST_SIZE                9

/* Description of offsets to generate indices for Feed instrumentation signal */
#define JETCONFLOW_OFFSET					0
#define JETFEEDFLOW_OFFSET					1
#define JETOUTPUTFLOW_OFFSET				2
#define CLACKVALVEFLOW_OFFSET				3
#define COLOVERFLOW_OFFSET					4

/* Flight phases for selecting wing bending */
#define ON_GROUND							0
#define IN_FLIGHT							1

/* Flow regime for selecting non-linear element mode */
#define NETWORK_NORMAL_FLOW					0
#define NETWORK_HIGH_FLOW					1
#define NETWORK_LOW_FLOW					2

/* Tank Id's used for selecting appropriate Volume/Height LUT - must match InitModel.m */
#define ERROR_TANK_ID						0
#define TEST_TANK_ID						1
#define OUTER_TANK_ID						2
#define COLLECTOR_1_ID						3
#define COLLECTOR_2_ID						4
#define INNERFWD_TANK_ID					5
#define INNERAFT_TANK_ID					6
#define CENTRE_TANK_ID						7
#define VENT_SURGE_TANK_ID					8
#define TRIM_TANK_ID						9 
#define TRIM_SURGE_TANK_ID					10  
#define TANK_IDS							11

/* Tank areas - used for default if no LUT installed */
#define DEFAULT_TANK_AREA					2.0 /* m^2 */
#define TEST_TANK_AREA						DEFAULT_TANK_AREA
#define OUTER_TANK_AREA						DEFAULT_TANK_AREA
#define COLLECTOR_1_AREA					DEFAULT_TANK_AREA
#define INNERFWD_TANK_AREA					DEFAULT_TANK_AREA
#define INNERAFT_TANK_AREA					DEFAULT_TANK_AREA
#define CENTRE_TANK_AREA					DEFAULT_TANK_AREA
#define VENT_SURGE_TANK_AREA				DEFAULT_TANK_AREA
#define TRIM_TANK_AREA						DEFAULT_TANK_AREA
#define TRIM_SURGE_TANK_AREA				DEFAULT_TANK_AREA

/* Description of controls for tank resets */
#define TANK_RESET_NO_RESET					-1000.0

/* Position ID's to allow common components to be used */
#define TANK_RIGHT_POSITION					-1.0
#define TANK_LEFT_POSITION					1.0
#define TANK_CENTRE_POSITION				0.0

/* Special temperature outputed from TJunction inlet during inflow */
#define ERROR_TEMP							1000000.0

/* Common definition of run-time signal */
#if (EXTINT_RUNTIME != 0) || (TESTBLOCK_RUNTIME != 0) 
#error "Error! EXTINT_RUNTIME and TESTBLOCK_RUNTIME must be equal!"
#endif
#define INTERFACE_RUNTIME 0

/* Dummy references to allow FSP Generic (Non-Used) functions to compile */
#define TANK_PROBE_FPMUD_OFFSET			42
#define TANK_PROBE_FPMUKT_OFFSET		43
#define TANK_PROBE_FPMUDT_OFFSET		44
#define TANK_PROBE_PCTT_OFFSET			37
#define TANK_PROBE_PCTK_OFFSET			38
#define TANK_PROBE_PCTT_2_OFFSET		39
#define TANK_PROBE_PCTK_2_OFFSET		40
#define TANK_PROBE_DTS_A_OFFSET			TANK_PROBE_FTS_01_OFFSET
#define TANK_PROBE_DTS_B_OFFSET			TANK_PROBE_FTS_02_OFFSET

#endif /* INTERFACE_COMMON_H */
