#ifndef __GENERIC_TYPES_H
#define __GENERIC_TYPES_H

/* Include appropriate type system for Simulink-derived code */
#ifdef SIMULINK_EMBEDDED_CODER
#include "rtwtypes.h"
#elif defined SIMULINK_REALTIME_WORKSHOP
#include "simstruc.h"
#elif defined SIMULINK_SIMULATION
#include "simstruc.h"
#endif

/* C99 type definitions */
#if defined (__LCC__)
  typedef unsigned char    uint8_t ;
  typedef          char    int8_t  ;
  typedef unsigned short   uint16_t;
  typedef          short   int16_t ;
  typedef unsigned int     uint32_t;
  typedef          int     int32_t ;
  typedef unsigned __int64 uint64_t;
  typedef          __int64 int64_t ;
#elif defined (_MSC_VER) || defined(__BORLANDC__)
  typedef unsigned __int8  uint8_t;
  typedef __int8           int8_t;
  typedef unsigned __int16 uint16_t;
  typedef __int16          int16_t;
  typedef unsigned __int32 uint32_t;
  typedef __int32          int32_t;
  typedef unsigned __int64 uint64_t;
  typedef __int64          int64_t;
#else /* Assume VxWorks target */
  #include <types\vxTypes.h>
#endif /* defined (__LCC__) */

/* Locally extended C99 types */
typedef char     char_t;
typedef uint8_t  bits8_t;
typedef uint16_t bits16_t;
typedef uint32_t bits32_t;
typedef uint64_t bits64_t;

/* Type-handling macros */
#define OCTAL(n) (0 ## n)

/****t* Types/Booleans
 * NAME
 *	Booleans
 * SYNOPSIS
 *	typedef enum Booleans
 * DESCRIPTION
 *	Defines boolean enumerator
 * NOTES
 *	None
 * SEE ALSO
 *	None
 * SOURCE
 */
typedef enum {
	BOOLEAN_FALSE = 0,
	BOOLEAN_TRUE = 1
} Booleans;
/******/

/****t* Types/Boolean
 * NAME
 *	Boolean
 * SYNOPSIS
 *	typedef int Boolean
 * DESCRIPTION
 *	Defines boolean type
 * NOTES
 *	1. AP2633 stipulates that booleans are of type int
 *  2. Preprocessor flag allows prevention of redefinition 
 *     attempts by other headers
 * SEE ALSO
 *	None
 * SOURCE
 */
#ifndef _TYPEDEF_BOOLEAN_
#define _TYPEDEF_BOOLEAN_
typedef int	Boolean;
#endif
/******/

#endif	/* __GENERIC_TYPES_H */
