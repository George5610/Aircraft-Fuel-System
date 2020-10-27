/*
 * WrightSolver.h
 *
 */

/* Infinite resistance special value                   */
/* Must match InfiniteResistance in WrightSolverInit.m */
#define INFINITE_RESISTANCE -999.0

/* Special value to represent floating voltage */
#define FLOATING_VOLTAGE 1e50

/* Special value to represent infinite voltage */
/* Bigger than any practical voltage, but not FLOATING_VOLTAGE */
/* Must match NearInfiniteVoltage in WrightSolverInit.m */
#define NEAR_INFINITE_VOLTAGE 1e30

/* Special signal to represent no-override of current */
#define NO_CURRENT_OVERRIDE 1e50 /* NoCurrentOverride in .m */

/* Return codes */
#define RES_OK  1
#define RES_NOK 0

/* Prototypes */
extern int CheckResistanceValid(double,char *);
/* returns 1 for True, 0 for False if first param is similar 
in value to second param, where the difference is less than the
second param multiplied by the third param (i.e. 3rd param is a 
number a lot less than 1) */ 
extern int isEqualTolerance(double, double, double);
