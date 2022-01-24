
#include "sLogging.h"

int main(int argc, char* argv[]) {
  sLog("test of sLog.");
  sLogDebug("test of sLogDebug.");
  sLogInfo("test of sLogInfo.");
  sLogWarn("test of sLogWarn.");
  sLogError("test of sLogError.");
  sLogFatal("test of sLogFatal.");

  sLog("test %d of %s.", 2, "sLog");
  sLogDebug("test %d of %s.", 2, "sLogDebug");
  sLogInfo("test %d of %s.", 2, "sLogInfo");
  sLogWarn("test %d of %s.", 2, "sLogWarn");
  sLogError("test %d of %s.", 2, "sLogError");
  sLogFatal("test %d of %s.", 2, "sLogFatal");

  return 0;
}
