// Filename: sLogging.h
// Description: sLogging library C implementation.
// Revision: RevA
// Release Date: 2022-01-23
// Primary Author: Sky Hoffert
// Secondary Author(s): N/A
// Target Audience: Sky Hoffert and users of the sLogging library.

#ifndef _SLOGGING_H_
#define _SLOGGING_H_

#include <stdio.h>
#include <stdarg.h>

void __sLogGeneral(const char* prefix, const char* fmt, va_list args) {
  printf("%s: ", prefix);
  vprintf(fmt, args);
  printf("\n");
  fflush(stdout);
}

extern inline void sLog(const char* str, ...) {
  va_list listptr;
  va_start(listptr, str);
  vprintf(str, listptr);
  va_end(listptr);
  printf("\n");
  fflush(stdout);
}

extern inline void sLogDebug(const char* str, ...) {
  va_list listptr;
  va_start(listptr, str);
  __sLogGeneral("DBUG", str, listptr);
  va_end(listptr);
}

extern inline void sLogInfo(const char* str, ...) {
  va_list listptr;
  va_start(listptr, str);
  __sLogGeneral("INFO", str, listptr);
  va_end(listptr);
}

extern inline void sLogWarn(const char* str, ...) {
  va_list listptr;
  va_start(listptr, str);
  __sLogGeneral("WARN", str, listptr);
  va_end(listptr);
}

extern inline void sLogError(const char* str, ...) {
  va_list listptr;
  va_start(listptr, str);
  __sLogGeneral("ERR ", str, listptr);
  va_end(listptr);
}

extern inline void sLogFatal(const char* str, ...) {
  va_list listptr;
  va_start(listptr, str);
  __sLogGeneral("FATL", str, listptr);
  va_end(listptr);
}

#endif
