/*
 * File : ProportionalMixBlockWrapper.c
 * Abstract: C-file S-function
 *
 * Author: Steve Wright
 *
 * Revision: 1.1
 * Changes:
	Inserted input / output handling in mdlOutputs, 
	include "Instrumentation.h",
	call to GetProportionalMixSignal(...) implementation
	call to Open/CloseProportionalMix()
 */

#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME  ProportionalMixBlockWrapper

#include "GenericTypes.h"
#include "Instrumentation.h"
#include "ProportionalMixBlock.h"

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

    /* Create 4 input ports */
    if (!ssSetNumInputPorts(S, 4)) return;
    ssSetInputPortWidth(S, 0, 1); /* sig1 */
    ssSetInputPortWidth(S, 1, 1); /* mass1 */
    ssSetInputPortWidth(S, 2, 1); /* sig2 */
    ssSetInputPortWidth(S, 3, 1); /* mass2 */

    /* Actively set direct feedthrough flags */
    ssSetInputPortDirectFeedThrough(S, 0, 1); 
    ssSetInputPortDirectFeedThrough(S, 1, 1); 
    ssSetInputPortDirectFeedThrough(S, 2, 1); 
    ssSetInputPortDirectFeedThrough(S, 3, 1); 
    
    /* Force inputs to contiguous */
    ssSetInputPortRequiredContiguous(S,0,1);
    ssSetInputPortRequiredContiguous(S,1,1);
    ssSetInputPortRequiredContiguous(S,2,1);
    ssSetInputPortRequiredContiguous(S,3,1);

	/* Create 2 output ports */
    if (!ssSetNumOutputPorts(S,2)) return;
    ssSetOutputPortWidth(S, 0, 1); /* sigOut */     
    ssSetOutputPortWidth(S, 1, 1); /* sigOutValid */

    /* Only 1 sample time */
    ssSetNumSampleTimes(S, 1);

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_USE_TLC_WITH_ACCELERATOR);
}


/* Function: mdlInitializeSampleTimes */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}

/* Function: mdlStart */
static void mdlStart(SimStruct *S)
{
	OpenProportionalMix();
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
	/* get inputs - all width 1*/
    real_T *sig1  = ssGetInputPortSignal(S,0); 
    real_T *mass1 = ssGetInputPortSignal(S,1); 
    real_T *sig2  = ssGetInputPortSignal(S,2); 
	real_T *mass2 = ssGetInputPortSignal(S,3);

	real_T *sigOut      = ssGetOutputPortSignal(S,0);      
    real_T *sigOutValid = ssGetOutputPortSignal(S,1);      

	GetProportionalMixSignal(*mass1,*sig1,*mass2,*sig2,sigOut,sigOutValid);
}


/* Function: mdlTerminate */
static void mdlTerminate(SimStruct *S)
{
	CloseProportionalMix();
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
