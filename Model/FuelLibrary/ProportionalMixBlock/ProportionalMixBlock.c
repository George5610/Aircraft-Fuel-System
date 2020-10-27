/*
 * ProportionalMixBlock.c
 */
 
/* Include headers */
#include "ProportionalMixBlock.h"
#include "GenericTypes.h"

void OpenProportionalMix(void)
{
	/* Nothing to do */
}

void CloseProportionalMix(void)
{
	/* Nothing to do */
}

void GetProportionalMixSignal(double mass1,double sig1,double mass2,double sig2,double *sigOut,double *sigOutValid)
{
	int sigOutValidInt;

	/* Direct call to standard call */
	ProportionalMix(mass1,sig1,mass2,sig2,sigOut,&sigOutValidInt);

	/* Cast to API type */
	*sigOutValid = (double)(sigOutValidInt);
}
