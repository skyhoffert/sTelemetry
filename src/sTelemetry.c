// Filename: sTelemetry.c
// Description: sTelemetry library main function.
// Revision: RevA
// Release Date: 2022-01-22
// Primary Author: Sky Hoffert
// Secondary Author(s): N/A
// Target Audience: Sky Hoffert and similar programmers looking for simple telemetry logging.

///////////////////////////////////////////////////////////////////////////////////////////////////
// Includes for other files in this project.
///////////////////////////////////////////////////////////////////////////////////////////////////
#include "temp.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
// Includes for libraries contained in "lib/".
///////////////////////////////////////////////////////////////////////////////////////////////////
#include "s.h"
#include "sLogging.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
// Includes for standard library files.
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////////////////////////
// Global variables.
///////////////////////////////////////////////////////////////////////////////////////////////////
static volatile int shutdown_flag = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////
// Function declarations.
///////////////////////////////////////////////////////////////////////////////////////////////////
void KeyboardInterruptHandler();

///////////////////////////////////////////////////////////////////////////////////////////////////
// Main.
///////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
  // Set up interrupt handler.
  signal(SIGINT, KeyboardInterruptHandler);

  sLogInfo("sTelemetry started.");

  // Initializing variables.
  int temp = 0;
  char str[100];
  memset(str, 0, 100);

  // Main ticking loop where work is done.
  while (shutdown_flag == 0) {
    temp = ((int) GetCPUTemp_SkyDesktop()); // This should be pretty time efficient.
    memset(str, 0, 100);
    sDateUTC(str);
    str[10] = ' ';
    sTimeUTC(str+11);
    sLog("%s | %d", str, temp);

    sleep(1);
  }

  sLogInfo("sTelemetry shutting down.");

  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Function definitions.
///////////////////////////////////////////////////////////////////////////////////////////////////
void KeyboardInterruptHandler() {
  shutdown_flag = 1;
  printf("\nInterrupt handler caught a signal.\n");
}
