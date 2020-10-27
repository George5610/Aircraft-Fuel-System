/*
 * File : InletControlBlockWrapper.c
 * Abstract: C-file S-function
 *
 * Author: Steve Wright
 *
 * Revision: 1.1
 * Changes - populated mdlOutputs() based on .tlc file
 */

#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME InletControlBlockWrapper

#include "GenericTypes.h"
#include "Instrumentation.h"
#include "InletControlBlock.h"

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
#if DEBUG_PRINT == 1
	printf("%s: %s\n", __FILE__, "mdlInitializeSizes");
#endif
	ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }

    /* Create 6 input ports */
    if (!ssSetNumInputPorts(S, 6)) return;
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortWidth(S, 1, 1);
    ssSetInputPortWidth(S, 2, 1);
    ssSetInputPortWidth(S, 3, 1);
    ssSetInputPortWidth(S, 4, 1);
    ssSetInputPortWidth(S, 5, LATCHED_ELEMENTS);

    /* Actively set direct feedthrough flags */
    ssSetInputPortDirectFeedThrough(S, 0, 1); 
    ssSetInputPortDirectFeedThrough(S, 1, 1); 
    ssSetInputPortDirectFeedThrough(S, 2, 1); 
    ssSetInputPortDirectFeedThrough(S, 3, 1); 
    ssSetInputPortDirectFeedThrough(S, 4, 1); 
    ssSetInputPortDirectFeedThrough(S, 5, 1); 
    
    /* Force inputs to contiguous */
    ssSetInputPortRequiredContiguous(S,0,1);
    ssSetInputPortRequiredContiguous(S,1,1);
    ssSetInputPortRequiredContiguous(S,2,1);
    ssSetInputPortRequiredContiguous(S,3,1);
    ssSetInputPortRequiredContiguous(S,4,1);
    ssSetInputPortRequiredContiguous(S,5,1);

	/* Create output ports */
    if (!ssSetNumOutputPorts(S,2)) return;
    ssSetOutputPortWidth(S, 0, 1);                
    ssSetOutputPortWidth(S, 1, LATCHED_ELEMENTS); 

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
	/* ignoring return success flag */ 
#if DEBUG_PRINT == 1
	printf("%s: %s\n", __FILE__, "mdlStart");
#endif
	(void) OpenInletControlBlock();
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
	/* width 1 */
	real_T *pipeCovered  = (real_T *) ssGetInputPortSignal(S, 0);
	/* width 1 */
	real_T *outsidePress = (real_T *) ssGetInputPortSignal(S, 1);
	/* width 1 */
	real_T *insidePress  = (real_T *) ssGetInputPortSignal(S, 2);
	/* width 1 */
	real_T *inFlow       = (real_T *) ssGetInputPortSignal(S, 3);
	/* width 1 */
	real_T *error        = (real_T *) ssGetInputPortSignal(S, 4);
	/* array width LATCHED_ELEMENTS */
	real_T *inData       = (real_T *) ssGetInputPortSignal(S, 5);

	/* width 1 */
	real_T *flowEnabled  = (real_T *) ssGetOutputPortSignal(S, 0);
	/* array width LATCHED_ELEMENTS */
	real_T *outData      = (real_T *) ssGetOutputPortSignal(S, 1);
#if DEBUG_PRINT == 1
	printf("%s: %s\n", __FILE__, "mdlOutputs");
#endif

	*flowEnabled = RunInletControl(*pipeCovered,*outsidePress,*insidePress,*inFlow,*error,inData,outData);
}


/* Function: mdlTerminate */
static void mdlTerminate(SimStruct *S)
{
#if DEBUG_PRINT == 1
	printf("%s: %s\n", __FILE__, "mdlTerminate");
#endif
	CloseInletControlBlock();
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
