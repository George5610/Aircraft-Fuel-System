/*
 * InletControlBlock.h
 *
 * Block for inlet open/closed logic
 *
 */
 
#define LATCHED_ELEMENTS 20

/* Prototypes to functions */
extern int    OpenInletControlBlock(void);
extern double RunInletControl(double pipeCovered,double outsidePress,double insidePress,double inFlow,double error,double *inData,double *outData);
extern void   CloseInletControlBlock(void);



