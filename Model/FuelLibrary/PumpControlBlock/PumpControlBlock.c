/*
 * PumpControlBlock.c
 *
 * Block for refuel coupling control
 *
 */
 
/* Include headers */
#include "GenericTypes.h"
#include "PumpControlBlock.h"
#include "FspUtils.h"
#include "InterfaceFsp.h"
#include "Instrumentation.h"

#define PUMP_PRESSURE    100000.0 // Pascals
#define PUMP_RESISTANCE  49714.7  // (kg/s)/Pa

void OpenPumpControl(void)
{
	/* Nothing to do */
}

void ClosePumpControl(void)
{
	/* Nothing to do */
}

void RunPumpControl(real_T en,real_T bypass,real_T pos,real_T srcIn,real_T sinkIn,real_T inletPress,real_T outletPress,real_T thruFlow,
                    real_T *srcOut,real_T *pressOut,real_T *resOut,real_T *nrvEnOut,real_T *flowOut)
{
	/* Set default outputs */
	*srcOut    = 0.0;
	*pressOut  = FLOATING_PRESSURE;
	*resOut    = INFINITE_RESISTANCE;
	*nrvEnOut  = 0.0;
	*flowOut   = NO_FLOW_OVERRIDE;

	/* Check for no source */
	if(srcIn==0.0) {
		/* Default to off */
	}
	/* Check for no source pressure */
	else if(inletPress==FLOATING_PRESSURE) {
		/* Default to off */
	}
	/* Check for pump switched off */
	else if(en==0.0) {
    	/* Default to off */
	}
	/* Pump switched on and pressured */
	else {

		
		/* NRV functionality */
		if(sinkIn==0.0) {
			/* Pump stalled: source on but NRV closed */
			*srcOut   = 1.0;
			*pressOut = PUMP_PRESSURE * pos;
			*resOut   = PUMP_RESISTANCE;
			*nrvEnOut = 0.0;
		}
		else if((outletPress!=FLOATING_PRESSURE) && (outletPress > (inletPress + PUMP_PRESSURE))) {
			/* Inside/outside pressures but inside overwhelmed - NRV closed */
			*srcOut   = 1.0;
			*pressOut = PUMP_PRESSURE * pos;
			*resOut   = PUMP_RESISTANCE;
		}
		/* Pump-on and NRV enabled - decode mode */
		else {

			*srcOut   = 1.0;
			*pressOut = PUMP_PRESSURE * pos;
			*resOut   = PUMP_RESISTANCE;
			*nrvEnOut = 1.0;
		}
	}
}





