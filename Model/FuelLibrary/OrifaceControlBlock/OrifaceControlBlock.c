/*
 * OrifaceControlBlock.c
 *
 * Block for refuel coupling control
 *
 */
 
/* Include headers */
#include <math.h>
#include "OrifaceControlBlock.h"
#include "Instrumentation.h"

double GetOrifaceRes(double flow,double c,double prevRes)
{
	double absFlow = fabs(flow);
	double res     = c * absFlow;
	double newRes  = (0.5 * prevRes) + (0.5 * res);

	return newRes;
}
