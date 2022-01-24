// Filename: s.h
// Description: s library C implementation.
// Revision: RevA
// Release Date: 2022-01-23
// Primary Author: Sky Hoffert
// Secondary Author(s): N/A
// Target Audience: Sky Hoffert and users of the s library.

#ifndef _S_H_
#define _S_H_

#include <time.h>
#include <stdio.h>

#define sFalse 0
#define sTrue 1

typedef int sBool;

// static double[] sLinspace(double a, double b, double d, bool incl=true) {
//   let t = [];
//   const end = incl ? b : b-d;
//   for (let i = a; i <= end; i += d) {
//       t.push(i);
//   }
//   return t;
// }

// function sMax(ar) {
//   return Math.max.apply(Math, ar);
// }

// function sMin(ar) {
//   return Math.min.apply(Math, ar);
// }

// function sSigs(n, dig=3) {
//   return Math.round(n * Math.pow(10, dig)) / Math.pow(10, dig);
// }

// function sRandInt(l,h) {
//   // Range = [l,h]
//   return Math.floor(Math.random() * (h-l+1)) + l;
// }

// function sRandID(len=6) {
//   let result           = "";
//   let characters       = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
//   let charactersLength = characters.length;
//   for (let i = 0; i < len; i++ ) {
//       result += characters.charAt(Math.floor(Math.random() * charactersLength));
//   }
//   return result;
// }

// function sRandNormal(mu, sigma, nsamples=10){
//   if(!sigma) sigma = 1
//   if(!mu) mu=0

//   var run_total = 0
//   for(var i=0 ; i<nsamples ; i++){
//      run_total += Math.random()
//   }

//   return sigma*(run_total - nsamples/2)/(nsamples/2) + mu
// }

// function sCot(v) { return 1 / Math.tan(v); }
// function sSin(v) { return Math.sin(v); }
// function sCos(v) { return Math.cos(v); }
// function sCsc(v) { return 1 / Math.sin(v); }
// function sLn(v) { return Math.log(v) / Math.log(Math.E); }
// function sSqr(v) { return Math.pow(v,2); }
// function sSqrt(v) { return Math.sqrt(v); }
// function sCube(v) { return Math.pow(v,3); }
// function sFourth(v) { return Math.pow(v,4); }
// function sExp(v) { return Math.exp(v); }
// function sLog10(v) { return Math.log10(v); }
// function sPow(b,e) { return Math.pow(b, e); }
// function sRound(v) { return Math.round(v); }

extern inline double sAbs(double v) {
  if (v >= 0) { return v; }
  else return v * (-1);
}

// Returns value "v" limited by "min" and "max".
extern inline double sClamp(double v, double min, double max) {
  if (v < min) { return min; }
  if (v > max) { return max; }
  return v;
}

extern inline sBool sFuzzyEquals(double v1, double v2, double fuzz) {
  return sAbs(v1 - v2) < fuzz ? sTrue : sFalse;
}

// Function: sDate
// Description: Writes current date (local time) to given buffer.
// Params:
//   char* str: buffer to be written to -> must be AT LEAST 10 bytes.
// Return Value: int, with 0 indicating success and 1 indicating error.
// Example:
//   char buf[11];
//   if (sDate(buf) == 1) { sLogError("Error with sDate call.") }
//   else { sLog("Today is %s.", buf); }
//   // this will print "Today is 2022-01-23."
extern inline int sDate(char* buf) {
  time_t tmi;
  time(&tmi);
  struct tm* info = localtime(&tmi);

  strftime(buf, 11, "%Y-%m-%d", info);

  return 0;
}
extern inline int sDateUTC(char* buf) {
  time_t tmi;
  time(&tmi);
  struct tm* info = gmtime(&tmi);

  strftime(buf, 11, "%Y-%m-%d", info);

  return 0;
}

// Function: sTime
// Description: Writes current time (local time) to given buffer.
// Params:
//   char* str: buffer to be written to -> must be AT LEAST 8 bytes.
// Return Value: int, with 0 indicating success and 1 indicating error.
// Example:
//   char buf[9];
//   if (sTime(buf) == 1) { sLogError("Error with sTime call.") }
//   else { sLog("Local time is %s.", buf); }
//   // this will print "Local time is 13:45:02."
extern inline int sTime(char* buf) {
  time_t tmi;
  time(&tmi);
  struct tm* info = localtime(&tmi);

  strftime(buf, 9, "%H:%M:%S", info);

  return 0;
}
extern inline int sTimeUTC(char* buf) {
  time_t tmi;
  time(&tmi);
  struct tm* info = gmtime(&tmi);

  strftime(buf, 9, "%H:%M:%S", info);

  return 0;
}

// function sContains(x, y, rx, ry, rw, rh) {
//   return x > rx - rw/2 && x < rx + rw/2 && y > ry - rh/2 && y < ry + rh/2;
// }

#endif