/*
 * ProportionalMixBlock.h
 *
 * Block for oriface control
 *
 */

extern void OpenProportionalMix(void);
extern void CloseProportionalMix(void);
extern void GetProportionalMixSignal(double mass1,double sig1,double mass2,double sig2,double *sigOut,double *sigOutValid);
