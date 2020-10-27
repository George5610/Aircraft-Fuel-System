#ifndef PLATFORMFUNCS_H
#define PLATFORMFUNCS_H

#include <stdio.h>
#include <stdarg.h>
#include "GenericTypes.h"

#ifdef OS_WIN
#include <windows.h>
#endif

#ifdef OS_WIN
	/* Visual Studio 2003 */
	#if _MSC_VER == 1310
		#define MICROSOFT_DEPRECATED_FUNCTIONS
	#endif
#endif

#ifdef OS_VXWORKS
int _isnan(double x);
double _copysign(double x, double y);
char *_strlwr(char * str);
int _stricmp(const char *str1, const char *str2);
int _strnicmp(const char *str1, const char *str2, size_t count);
char *_strdup(const char *s1);
void *GlobalAlloc(unsigned int uFlags, size_t dwBytes);
void GlobalFree(void *hMem);
#endif	/* OS_VXWORKS */

#if (defined OS_VXWORKS) || (defined MICROSOFT_DEPRECATED_FUNCTIONS)
/* Microsoft deprecated functions */
void memcpy_s(void *dest, size_t destBytes, const void *src, size_t srcBytes);
char *strcat_s(char *strDestination, size_t numberOfElements, const char *strSource);
void strcpy_s(char *strDestination, size_t numberOfElements, const char *strSource);
void strncpy_s(char *strDest, size_t numberOfElements, const char *strSource, size_t count);
char *strtok_s(char *strToken, const char *strDelimit, char **context);
int sprintf_s(char *buffer, size_t sizeOfBuffer, const char *format, ...);
int _snprintf_s(char *buffer, size_t sizeOfBuffer, size_t count, const char *format, ...);
int vsprintf_s(char *buffer, size_t sizeOfBuffer, const char *format, va_list args);
void fopen_s(FILE** pFile, const char *filename, const char *mode);
void strerror_s(char *buffer, size_t numberOfElements, int errnum);
#define sscanf_s	sscanf
#endif	/* OS_VXWORKS || MICROSOFT_DEPRECATED_FUNCTIONS */

extern int64_t atoll(const char *caString);

#endif	/* PLATFORMFUNCS_H */

#ifdef OS_WIN
/*
   The standard memory functions (malloc, free etc) in Windows use the compiler's heap manager.
   This allocates a block of memory at startup. Each malloc call grabs a bit of that memory. Each
   free call marks it to be free'd, but will not actually free the memory. 
   By using HeapAlloc functions we are allocating and freeing memory directly from the OS.
   This is as VxWorks, works across application and DLL boundaries and also makes debugging
   actual memory leaks easier.
 */
/* Undefine standard functions */
#ifdef malloc
	#undef malloc
#endif	/* malloc */
#ifdef calloc
	#undef calloc
#endif	/* calloc */
#ifdef realloc
	#undef realloc
#endif	/* realloc */
#ifdef free
	#undef free
#endif	/* free */

#define malloc(size)		HeapAlloc(GetProcessHeap(), 0, size)
#define calloc(n, size)		HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, n*size)
#define realloc(ptr, size)	HeapReAlloc(GetProcessHeap(), 0, ptr, size)
#define free(ptr)			HeapFree(GetProcessHeap(), 0, ptr)
#endif	/* OS_WIN */
