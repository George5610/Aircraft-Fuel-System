/*
 * InterfaceFspGeneric.h
 *
 * Shared interface definitions applicable to all FSPs
 *
 * Generally should match with definitions in Fsp_Generic\InitFspGeneric.m
 *
 */

/* Overide RTW time stepping */
#ifdef OS_WIN
#ifdef rtmIsSampleHit
#undef rtmIsSampleHit
#define rtmIsSampleHit(x,y,z) 1
#endif
#endif

/* System sampling period */
#define FSP_PERIOD 0.25 /* sec */

/* Configuration path input */
#define MAX_CONFIG_PATH_LEN 100

/* Description of offsets to generate indices for backbone */
#define BBONE_BASE_PRESS_OFFSET 0
#define BBONE_TEMP_OFFSET       1
#define BBONE_AVAL_OFFSET       2
#define BBONE_BVAL_OFFSET       3
#define BBONE_SRC_AVAIL_OFFSET  4
#define BBONE_SINK_AVAIL_OFFSET 5
#define BBONE_VENT_AVAIL_OFFSET 6
#define BBONE_HEIGHT_OFFSET     7
#define BBONE_INST_SIZE         8

/* Description of offsets to generate indices for aircarft information signal */
#define ACINFO_VARIANT_OFFSET        0
#define ACINFO_WINGBEND_OFFSET       1
#define ACINFO_AIRTEMPERATURE_OFFSET 2
#define ACINFO_EFFECTIVEPITCH_OFFSET 3
#define ACINFO_EFFECTIVEROLL_OFFSET  4
#define ACINFO_HTPA_OFFSET           5
#define ACINFO_SIZE                  6

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
#define TANK_ERROR_OFFSET                0
#define TANK_LEAKAGE_OFFSET              1
#define TANK_HEAT_CONDUCTANCE_OFFSET     2
#define TANK_RESET_MASS_OFFSET           3
#define TANK_RESET_TEMP_OFFSET           4
#define TANK_RESET_A_OFFSET              5
#define TANK_RESET_B_OFFSET              6
#define TANK_OVERRIDE_MASS_OFFSET        7
#define TANK_OVERRIDE_TEMP_OFFSET        8
#define TANK_OVERRIDE_A_OFFSET           9
#define TANK_OVERRIDE_B_OFFSET           10
#define TANK_INLET1_MODE_OFFSET          11
#define TANK_INLET1_FLOW_OVERRIDE_OFFSET 12
#define TANK_INLET2_MODE_OFFSET          13
#define TANK_INLET2_FLOW_OVERRIDE_OFFSET 14
#define TANK_INLET3_MODE_OFFSET          15
#define TANK_INLET3_FLOW_OVERRIDE_OFFSET 16

/* Description of offsets to generate indices for common tank instrumentation signal */
/* Must match indexes in InitFspGeneric.m                                            */
#define TANK_INST_MAX_VOL_OFFSET        0
#define TANK_INST_MASS_OFFSET           1
#define TANK_INST_VOLUME_OFFSET         2
#define TANK_INST_SURFACE_HEIGHT_OFFSET 3
#define TANK_INST_NETINFLOW_OFFSET      4
#define TANK_INST_TEMP_OFFSET           5
#define TANK_INST_A_OFFSET		        6
#define TANK_INST_B_OFFSET              7
#define TANK_INST_CG_VERT_OFFSET        8
#define TANK_INST_CG_LONG_OFFSET        9
#define TANK_INST_CG_LAT_OFFSET         10
#define TANK_INST_HEAD_PRESS_OFFSET     11
#define TANK_INST_VERT_POS_OFFSET       12
#define TANK_INST_LONG_POS_OFFSET       13
#define TANK_INST_LAT_POS_OFFSET        14
#define TANK_INST_INLET1_HEIGHT_OFFSET  15
#define TANK_INST_INLET2_HEIGHT_OFFSET  16
#define TANK_INST_INLET3_HEIGHT_OFFSET  17
#define TANK_INST_OUTLET1_HEIGHT_OFFSET 18
#define TANK_INST_OUTLET2_HEIGHT_OFFSET 19
#define TANK_INST_SIZE                  20

/* For FSPV only, therefore not included within TANK_INST_SIZE */
#define TANK_INST_OVERFLOW_OUTERFEED_OFFSET 20
#define TANK_INST_OVERFLOW_CENTRE_OFFSET    21
#define TANK_INST_OVERFLOW_SURGE_OFFSET     22
#define TANK_INST_OVERBOARDTOTAL_OFFSET     23


#define TANK_V3_INST_MAX_VOL_OFFSET        0
#define TANK_V3_INST_MASS_OFFSET           1
#define TANK_V3_INST_VOLUME_OFFSET         2
#define TANK_V3_INST_SURFACE_HEIGHT_OFFSET 3
#define TANK_V3_INST_NETINFLOW_OFFSET      4
#define TANK_V3_INST_TEMP_OFFSET           5
#define TANK_V3_INST_A_OFFSET		       6
#define TANK_V3_INST_B_OFFSET              7
#define TANK_V3_INST_DIELECTRIC_OFFSET	   8	       
#define TANK_V3_INST_DENSITY_OFFSET        9      
#define TANK_V3_INST_CG_VERT_OFFSET        10
#define TANK_V3_INST_CG_LONG_OFFSET        11
#define TANK_V3_INST_CG_LAT_OFFSET         12
#define TANK_V3_INST_HEAD_PRESS_OFFSET     13
#define TANK_V3_INST_VERT_POS_OFFSET       14
#define TANK_V3_INST_LONG_POS_OFFSET       15
#define TANK_V3_INST_LAT_POS_OFFSET        16
#define TANK_V3_INST_INLET1_HEIGHT_OFFSET  17
#define TANK_V3_INST_INLET2_HEIGHT_OFFSET  18
#define TANK_V3_INST_INLET3_HEIGHT_OFFSET  19
#define TANK_V3_INST_OUTLET1_HEIGHT_OFFSET 20
#define TANK_V3_INST_OUTLET2_HEIGHT_OFFSET 21
#define TANK_V3_INST_SIZE                  22

/* Definition of Tank probe signal array */
#define TANK_PROBES 50
#define DISCONNECTED_SIGNAL -1000

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
#define JETCONFLOW_OFFSET     0
#define JETFEEDFLOW_OFFSET    1
#define JETOUTPUTFLOW_OFFSET  2
#define CLACKVALVEFLOW_OFFSET 3
#define COLOVERFLOW_OFFSET    4

/* Description of offsets to generate indices for bowser reset signal */
#define BOWSER_RESET_PRES_OFFSET	    0
#define BOWSER_RESET_TEMP_OFFSET	    1
#define BOWSER_RESET_A_OFFSET		    2
#define BOWSER_RESET_B_OFFSET		    3
#define BOWSER_RESET_REFUELMETER_OFFSET	4
#define BOWSER_RESET_DEFUELMETER_OFFSET	5

/* Description of offsets to generate indices for jet-pump control signal */
#define JETPUMP_GAIN_OFFSET      0
#define JETPUMP_ORIFICE_C_OFFSET 1

/* Description of offsets for pump control */
#define PUMP_IP_CMD_OFFSET    0
#define PUMP_SW_TIME_OFFSET   1
#define PUMP_ON_PRESS_OFFSET  2
#define PUMP_OFF_PRESS_OFFSET 3
#define PUMP_ERROR_OFFSET     4
#define PUMP_MODE_OFFSET      5
#define PUMP_PRESS_OFFSET     6
#define PUMP_RES_OFFSET       7
#define PUMP_FLOW_OFFSET      8
#define PUMP_EN_OFFSET PUMP_IP_CMD_OFFSET

/* Description of offsets for 1 input valve */
#define VALVE1IP_CMD_OPEN_OFFSET 0
#define VALVE1IP_SW_TIME_OFFSET  1
#define VALVE1IP_ERROR_OFFSET    2

/* Description of offsets for 2 input valve */
#define VALVE2IP_CMD_OPEN_OFFSET  0
#define VALVE2IP_CMD_CLOSE_OFFSET 1
#define VALVE2IP_SW_TIME_OFFSET   2
#define VALVE2IP_ERROR_OFFSET     3

/* Description of injected error codes - must match definitions in InitModel.m */
#define VALVE_NO_ERROR        0
#define VALVE_FLAP_OPEN_ERROR 1
#define VALVE_FLAP_SHUT_ERROR 2
#define PUMP_NO_ERROR         0
#define PUMP_NRV_OPEN_ERROR   1
#define TANK_NO_ERROR         0
#define TANK_EMPTY_FLOW_ERROR 1

/* Description of offsets to generate indices for engine/APU control signal */
#define ENGINE_THROTTLE_OFFSET         0
#define ENGINE_FUEL_METER_RESET_OFFSET 1

/* Description of offsets to generate indices for engine/APU instrumentation signal */
#define ENGINE_BURN_METER_OFFSET 0

/* Description of offsets to generate indices for common valve status signal */
#define VALVE_STAT_OPEN_OFFSET   0
#define VALVE_STAT_CLOSED_OFFSET 1
#define VALVE_POS_OFFSET         2
#define VALVE_FLOW_OFFSET        3
#define VALVE_INST_SIZE          4

/* Description of offsets to generate indices for common pump status signal */
#define PUMP_CONTACT_OFFSET  0
#define PUMP_STAT_OFFSET     1
#define PUMP_POS_OFFSET      2
#define PUMP_THRUFLOW_OFFSET 3

/* Codes for pump modes */
#define PUMP_PRESSURE_MODE         1
#define PUMP_FLOW_MODE             2
#define PUMP_PRESSURE_LIMITED_MODE 3

/* Codes for tank inlet modes */
#define INLET_PRESSURE_MODE 1 /* Must match InletPressureMode in .m */
#define INLET_FLOW_MODE     2 /* Must match InletFlowMode in .m     */

