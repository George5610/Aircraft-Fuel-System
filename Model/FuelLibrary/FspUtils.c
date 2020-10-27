/*
 * FspUtils.c
 *
 * General functions for manipulating FSP components and properties
 *
 */

/* Includes */
#include "FspUtils.h"
#include "StatusCode.h"

int CheckMassSigValid(double mass,double sig)
{
	/* Check if mass negligable or less-than-zero */
	if(mass<=ALMOST_ZERO_FLOW) {
		return FALSE;
	}
	else if(sig==UNKNOWN_VALUE) {
		return FALSE;
	}

	/* Report valid */
	return TRUE;
}

void ProportionalMix(double mass1,double sig1,double mass2,double sig2,double *sigOut,int *sigOutValid)
{
	int sig1Valid = CheckMassSigValid(mass1,sig1);
	int sig2Valid = CheckMassSigValid(mass2,sig2);

	/* Set defaults */
	*sigOut      = UNKNOWN_VALUE;
	*sigOutValid = FALSE;

	/* Check if both masses invalid */
	if((sig1Valid==FALSE) && (sig2Valid==FALSE)) {
		/* Report default */
		return;
	}
	/* Sig1 OK/Sig2 Invalid */
	else if(sig2Valid==FALSE) {
		*sigOutValid = TRUE;
		*sigOut = sig1;
		return;
	}
	/* Sig1 Invalid/Sig2 OK */
	else if(sig1Valid==FALSE) {
		*sigOutValid = TRUE;
		*sigOut = sig2;
		return;
	}

	/* Both valid - mix */
	*sigOutValid = TRUE;
	*sigOut = ((mass1 * sig1) + (mass2 * sig2))/(mass1 + mass2);
}

double DiscreteInverse(double onOff)
{
    if(onOff==DISCRETE_ON) return DISCRETE_OFF;
    else                   return DISCRETE_ON;
}

double Volume2Mass(double volume, double temperature)
{
	double mass;

	/* Calculate mass of given volume at this temperature */
	mass = Temperature2Density(temperature,TYPICAL_A_VALUE,TYPICAL_B_VALUE) * volume;

	/* Report */
	return mass;
}

double Temperature2Dielectric(double temperature,double bValue)
{
	/* Report K */
    return(bValue - (0.00146 * temperature) + 1);
}

double Temperature2Density(double temperature,double aValue,double bValue)
{
    double kMinusOne;
    double density;

    /* Calculate first part */
    kMinusOne = Temperature2Dielectric(temperature,bValue) - 1;
    
    /* Calculate second part */
    density = kMinusOne / (aValue + (0.3568 * kMinusOne));
    
    /* Translate kg/lit to kg/m3 */
    density *= KPL2KPM3;

    /* Report */
    return density;
}

