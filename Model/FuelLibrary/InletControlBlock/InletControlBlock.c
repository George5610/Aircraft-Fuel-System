/*
 * InletControlBlock.c
 *
 * Block for inlet open/closed logic
 *
 */
 
/* Include headers */
#include "InletControlBlock.h"
#include "InterfaceCommon.h"
#include "FspUtils.h"

#define MAX_INLETS 50

int OpenInletControlBlock(void)
{
    /* Report success */
    return 0;
}

double RunInletControl(double pipeCovered,double outsidePress,double insidePress,double inFlow,double error,double *inData,double *outData)
{
	/* Check if empty-flow error set */
	if(error==TANK_EMPTY_FLOW_ERROR) {
		return 1.0;
	}
	else {

		/* Not empty */
		if(pipeCovered) {
			return 1.0;
		}
		/* Empty and no pressure either side */
		else if((outsidePress==FLOATING_PRESSURE) && (insidePress==FLOATING_PRESSURE)) {
			return 0.0;
		}
		/* Empty and no pressure outside */
		else if(outsidePress==FLOATING_PRESSURE) {
			return 0.0;
		}
		/* Empty and pressure outside, no pressure inside */
		else if(insidePress==FLOATING_PRESSURE) {
			return 1.0;
		}
		/* Empty and inward pressure */
		else if(outsidePress>=insidePress) {
			return 1.0;
		}
		/* Empty and outward pressure*/
		else {
			return 0.0;
		}
	}
}

void CloseInletControlBlock(void)
{
	/* Nothing to do */
}
