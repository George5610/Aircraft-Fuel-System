/*
 * File : OrifaceControlBlockWrapper.c
 * Abstract: C-file S-function
 *
 * Author: Steve Wright
 *
 * Revision: 1.1
 * Changes - populated mdlOutputs() based on .tlc file
 */

#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME  OrifaceControlBlockWrapper

#include "GenericTypes.h"
#include "Instrumentation.h"
#include "OrifaceControlBlock.h"

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

    /* Create 3 input ports */
    if (!ssSetNumInputPorts(S, 3)) return;
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortWidth(S, 1, 1);
    ssSetInputPortWidth(S, 2, 1);

    /* Actively set direct feedthrough flags */
    ssSetInputPortDirectFeedThrough(S, 0, 1); 
    ssSetInputPortDirectFeedThrough(S, 1, 1); 
    ssSetInputPortDirectFeedThrough(S, 2, 1); 
    
    /* Force inputs to contiguous */
    ssSetInputPortRequiredContiguous(S,0,1);
    ssSetInputPortRequiredContiguous(S,1,1);
    ssSetInputPortRequiredContiguous(S,2,1);

	/* Create 1 output port */
    if (!ssSetNumOutputPorts(S,1)) return;
    ssSetOutputPortWidth(S, 0, 1);                

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
	/* Nothing to do */
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
	/* all width 1 */
    real_T *flow = (real_T *) ssGetInputPortSignal(S, 0); 
    real_T *c    = (real_T *) ssGetInputPortSignal(S, 1); 
    real_T *prev = (real_T *) ssGetInputPortSignal(S, 2); 

    real_T *res  = (real_T *) ssGetOutputPortSignal(S, 0);      
#if DEBUG_PRINT == 1
	printf("%s: %s\n", __FILE__, "mdlOutputs");
#endif

    *res = GetOrifaceRes(*flow,*c,*prev);
}


/* Function: mdlTerminate */
static void mdlTerminate(SimStruct *S)
{
#if DEBUG_PRINT == 1
	printf("%s: %s\n", __FILE__, "mdlTerminate");
#endif
	/* Nothing to do */
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
