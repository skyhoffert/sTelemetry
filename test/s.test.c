// Filename: s.test.c
// Description: Test file for s library c implementation.
// Revision: RevA
// Release Date: 2022-01-22
// Primary Author: Sky Hoffert
// Secondary Author(s): N/A
// Target Audience: Those testing the s library c implementation.

#include "s.h"

#include <stdio.h>

void Test_sAbs();
void Test_sFuzzyEquals();
void Test_sClamp();

int main(int argc, char* argv[]) {
  Test_sAbs();
  Test_sFuzzyEquals();
  Test_sClamp();

  return 0;
}

void Test_sAbs() {
  printf("==== %s ====\n", __func__);

  double a = 2.2;
  double b = a * (-1);

  printf("1|Self: %d\n", sAbs(a) == a);
  printf("1|Negated: %d\n", sAbs(b) == a);
}

void Test_sFuzzyEquals() {
  printf("==== %s ====\n", __func__);

  double a = 3.1415926;
  double b = 3.14;

  printf("1|Self: %d\n", sFuzzyEquals(a, a, 0.0000000001));
  printf("0|6 sigs: %d\n", sFuzzyEquals(a, b, 0.000001));
  printf("0|5 sigs: %d\n", sFuzzyEquals(a, b, 0.00001));
  printf("0|4 sigs: %d\n", sFuzzyEquals(a, b, 0.0001));
  printf("0|3 sigs: %d\n", sFuzzyEquals(a, b, 0.001));
  printf("1|2 sigs: %d\n", sFuzzyEquals(a, b, 0.01));
  printf("1|1 sigs: %d\n", sFuzzyEquals(a, b, 0.1));
  printf("1|0 sigs: %d\n", sFuzzyEquals(a, b, 1));
}

void Test_sClamp() {
  printf("==== %s ====\n", __func__);

  double a = 10;

  double self = sClamp(a, a, a);
  printf("1|Self Clamp: %d\n", self == a);

  double low = sClamp(a, 12, 14);
  printf("1|Low Clamp: %d\n", low > a);

  double high = sClamp(a, 6, 8);
  printf("1|High Clamp: %d\n", high < a);

  double no = sClamp(a, 8, 12);
  printf("1|No Clamp: %d\n", no == a);

  double edge = sClamp(a, 8, 9.999999);
  printf("1|Edge Clamp: %d\n", edge < a);
}
