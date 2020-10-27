#ifndef PLATFORM_H
#define PLATFORM_H

/* Shared headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* The following preprocessor definitions are used:

OS        : OS_WIN, OS_VXWORKS, OS_UNIX, OS_LINUX
Interface : TMS_INTERFACE, DLL_EXPORT_INTERFACE, TEII_INTERFACE, MCP_INTERFACE, MW_INTERFACE, VCOM_INTERFACE
Endianness: ENDIAN_LITTLE, ENDIAN_BIG
Processor : PROC_X86, PROC_PPC
Debug     : DEBUG_MEMORY_ALLOCATION
*/

/* Checks on preprocessor settings */

#if (!defined TMS_INTERFACE) && !(defined DLL_EXPORT_INTERFACE || DLL_IMPORT_INTERFACE) && (!defined TEII_INTERFACE) && (!defined MCP_INTERFACE) && (!defined MW_INTERFACE) && (!defined VCOM_INTERFACE)
#error "No model interface has been defined"
#endif

#if (!defined OS_WIN) && (!defined OS_VXWORKS) && (!defined OS_UNIX) && (!defined OS_LINUX)
#error "No OS has been defined"
#endif

#if (!defined ENDIAN_LITTLE) && (!defined ENDIAN_BIG)
#error "No endianness has been defined"
#endif

#if (!defined PROC_X86) && (!defined PROC_PPC)
#error "No processor has been defined"
#endif

#if (defined OS_WIN) && (defined BIG_ENDIAN)
#error "Windows and big endian: probable mismatch"
#endif

#if (defined OS_WIN) && !(defined PROC_X86)
#error "Windows and not x86: probable mismatch"
#endif

#if (defined PROC_X86) && (defined BIG_ENDIAN)
#error "x86 and big endian: probable mismatch"
#endif

#if (defined PROC_PPC) && (defined LITTLE_ENDIAN)
#error "PowerPc and little endian: probable mismatch"
#endif

/* Windows platform */
#ifdef OS_WIN

/* Type definitions */
#ifndef _bool_T
#define bool int
#define _bool_T
#endif
typedef void* FUNCPTR ;
typedef void* SEM_ID;

/* Windows headers */
#include <windows.h>

/* VxWorks platform */
#elif OS_VXWORKS

/* VxWorks headers */
#include <vxWorks.h>
#include <taskLib.h>
#include <taskVarLib.h>
#include <sysLib.h>
#include <semLib.h>
#include <rebootLib.h>
#include <logLib.h>
#include <symLib.h>
#include <sysSymTbl.h>
#include <ioLib.h>
#include <fioLib.h>

/* Additional headers for timer routines*/
#include <types\vxTypesBase.h>

#else

#error "No OS platform defined"

#endif /* OS */

#endif /* PLATFORM_H */

#include "PlatformFuncs.h"
