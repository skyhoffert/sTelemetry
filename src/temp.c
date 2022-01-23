// Filename: temp.c
// Description: sTelemetry routines for getting temperature - definitions.
// Revision: RevA
// Release Date: 2022-01-22
// Primary Author: Sky Hoffert
// Secondary Author(s): N/A
// Target Audience: sTelemetry library.

#include "temp.h"

double GetCPUTemp_SkyDesktop() {
  /* command contains the command string (a character array) */
  char* command = "cat /sys/class/thermal/thermal_zone*/temp";

  /* If you want to read output from command */
  FILE* fp = popen(command, "r");
  /* read output from command */
  int temp0, temp1, temp2;
  fscanf(fp, "%d %d %d", &temp0, &temp1, &temp2);   /* or other STDIO input functions */

  double average = temp0 + temp1 + temp2;
  average /= 3;

  fclose(fp);

  return average;
}
