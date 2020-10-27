/*
 * PumpControlBlock.h
 *
 * Block for pump control
 *
 */

extern void OpenPumpControl(void);
extern void ClosePumpControl(void);
extern void RunPumpControl(real_T en,real_T bypass,real_T pos,real_T srcIn,real_T sinkIn,real_T inletPress,real_T outletPress,real_T thruFlow,
                           real_T *srcOut,real_T *pressOut,real_T *resOut,real_T *nrvEnOut,real_T *flowOut);
