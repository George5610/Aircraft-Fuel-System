/*
 * File : PumpControlBlockWrapper.c
 * Abstract: C-file S-function
 *
 * Author: Steve Wright
 *
 * Revision: 1.0
 */

#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME PumpControlBlockWrapper

#include "GenericTypes.h"
#include "Instrumentation.h"
#include "PumpControlBlock.h"


/*================*
 * Build checking *
 *================*/
#if !defined(MATLAB_MEX_FILE)
# error This_file_can_be_used_only_during_simulation_inside_Simulink
#endif

/* Switch in optional functions */
#define MDL_START

/* Function: mdlInitializeSizes */
static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }

    /* Create 8 input ports */
	if (!ssSetNumInputPorts(S, 8)) {
		return;
	}
    ssSetInputPortWidth(S, 0, 1); 
    ssSetInputPortWidth(S, 1, 1);
    ssSetInputPortWidth(S, 2, 1);
    ssSetInputPortWidth(S, 3, 1);
    ssSetInputPortWidth(S, 4, 1);
    ssSetInputPortWidth(S, 5, 1);
    ssSetInputPortWidth(S, 6, 1);
    ssSetInputPortWidth(S, 7, 1);

    /* Actively set direct feedthrough flags (crash if disabled) */
    ssSetInputPortDirectFeedThrough(S, 0, 1); 
    ssSetInputPortDirectFeedThrough(S, 1, 1); 
    ssSetInputPortDirectFeedThrough(S, 2, 1); 
    ssSetInputPortDirectFeedThrough(S, 3, 1); 
    ssSetInputPortDirectFeedThrough(S, 4, 1); 
    ssSetInputPortDirectFeedThrough(S, 5, 1); 
    ssSetInputPortDirectFeedThrough(S, 6, 1); 
    ssSetInputPortDirectFeedThrough(S, 7, 1); 
   
    /* Force inputs to contiguous */
    ssSetInputPortRequiredContiguous(S,0,1);
    ssSetInputPortRequiredContiguous(S,1,1);
    ssSetInputPortRequiredContiguous(S,2,1);
    ssSetInputPortRequiredContiguous(S,3,1);
    ssSetInputPortRequiredContiguous(S,4,1);
    ssSetInputPortRequiredContiguous(S,5,1);
    ssSetInputPortRequiredContiguous(S,6,1);
    ssSetInputPortRequiredContiguous(S,7,1);

	/* Create 5 output ports */
    if (!ssSetNumOutputPorts(S,5)) return;
    ssSetOutputPortWidth(S, 0, 1);                
    ssSetOutputPortWidth(S, 1, 1); 
    ssSetOutputPortWidth(S, 2, 1); 
    ssSetOutputPortWidth(S, 3, 1); 
    ssSetOutputPortWidth(S, 4, 1); 

    /* Only 1 sample time */
    ssSetNumSampleTimes(S, 1);

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_USE_TLC_WITH_ACCELERATOR);
}


/* Function: mdlInitializeSampleTimes */
static void mdlInitializeSampleTimes(SimStruct *S)
{
#if DEBUG_PRINT == 1
	printf("%s: %s\n", __FILE__, "mdlInitializeSampleTimes");
#endif
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}

/* Function: mdlStart */
static void mdlStart(SimStruct *S)
{
#if DEBUG_PRINT == 1
	printf("%s: %s\n", __FILE__, "mdlStart");
#endif
  OpenPumpControl();
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
	int i;

	real_T *en          = (real_T *) ssGetInputPortSignal(S, 0); 
	real_T *bypass      = (real_T *) ssGetInputPortSignal(S, 1); 
	real_T *pos         = (real_T *) ssGetInputPortSignal(S, 2); 
	real_T *srcIn       = (real_T *) ssGetInputPortSignal(S, 3); 
	real_T *sinkIn      = (real_T *) ssGetInputPortSignal(S, 4); 
	real_T *inletPress  = (real_T *) ssGetInputPortSignal(S, 5); 
	real_T *outletPress = (real_T *) ssGetInputPortSignal(S, 6);
	real_T *thruFlow    = (real_T *) ssGetInputPortSignal(S, 7); 

	real_T *srcOut    = (real_T *) ssGetOutputPortSignal(S, 0);      
	real_T *pressOut  = (real_T *) ssGetOutputPortSignal(S, 1);      
	real_T *resOut    = (real_T *) ssGetOutputPortSignal(S, 2);      
	real_T *nrvEnOut  = (real_T *) ssGetOutputPortSignal(S, 3);      
	real_T *flowOut   = (real_T *) ssGetOutputPortSignal(S, 4);      

#if DEBUG_PRINT == 1
	printf("%s: %s\n", __FILE__, "mdlOutputs");
#endif
	/* call RunPumpControl from PumpControlBlock.c */
	RunPumpControl(*en,*bypass,*pos,*srcIn,*sinkIn,*inletPress,*outletPress,*thruFlow,
			   srcOut,pressOut,resOut,nrvEnOut,flowOut);
 }


/* Function: mdlTerminate */
static void mdlTerminate(SimStruct *S)
{
#if DEBUG_PRINT == 1
	printf("%s: %s\n", __FILE__, "mdlTerminate");
#endif
  ClosePumpControl();
}


#if defined(MATLAB_MEX_FILE)
#define MDL_RTW
/* Function: mdlRTW ===========================================================
 * Abstract:
 *	Since we've declared all are parameters as non-tunable, we need
 *	only provide this routine so that they aren't written to the model.rtw
 *	file. The values of the parameters are implicitly encoded in the
 *	sample times.
 */
static void mdlRTW(SimStruct *S)
{

}
#endif /* MDL_RTW */


#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
