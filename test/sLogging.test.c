
#include "sLogging.h"

int main(int argc, char* argv[]) {
  sLog("test of sLog.");
  sLogDebug("test of sLogDebug.");
  sLogInfo("test of sLogInfo.");
  sLogWarn("test of sLogWarn.");
  sLogError("test of sLogError.");
  sLogFatal("test of sLogFatal.");

  return 0;
}
