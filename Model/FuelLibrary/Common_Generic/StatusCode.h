/* Definitions of returned status codes */

#ifdef OS_WIN
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#endif

#define SUCCESS 0
#define FAILURE 1
#define END_FILE 2

#define SIM_SUCCESS 0
#define SIM_FAILURE 1

#ifdef SIMULINK_EMBEDDED_CODER
#include "rtwtypes.h"
#else
#define FALSE 0
#define TRUE  1
#endif
