// Filename: sLogging.h
// Description: sLogging library C implementation.
// Revision: RevA
// Release Date: 2022-01-22
// Primary Author: Sky Hoffert
// Secondary Author(s): N/A
// Target Audience: Sky Hoffert and users of the sLogging library.

#ifndef _SLOGGING_H_
#define _SLOGGING_H_

#include <stdio.h>

void __sLogGeneral(const char* str, const char* prefix) {
  printf("%s", prefix);
  printf(": ");
  printf("%s", str);
  printf("\n");
  fflush(stdout);
}

extern inline void sLog(const char* str) {
  __sLogGeneral(str, "DBUG");
}

extern inline void sLogDebug(const char* str) {
  __sLogGeneral(str, "DBUG");
}

extern inline void sLogInfo(const char* str) {
  __sLogGeneral(str, "INFO");
}

extern inline void sLogWarn(const char* str) {
  __sLogGeneral(str, "WARN");
}

extern inline void sLogError(const char* str) {
  __sLogGeneral(str, "ERR ");
}

extern inline void sLogFatal(const char* str) {
  __sLogGeneral(str, "FATL");
}

#endif
