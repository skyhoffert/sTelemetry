// Filename: s.h
// Description: s library C implementation.
// Revision: RevA
// Release Date: 2022-01-22
// Primary Author: Sky Hoffert
// Secondary Author(s): N/A
// Target Audience: Sky Hoffert and users of the s library.

#ifndef _S_H_
#define _S_H_

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

// function sContains(x, y, rx, ry, rw, rh) {
//   return x > rx - rw/2 && x < rx + rw/2 && y > ry - rh/2 && y < ry + rh/2;
// }

// function sDateString(datedelim="-", timedelim=":", spacer=" ") {
//   let now = new Date();
//   return "" + now.getFullYear() + datedelim +
//     (now.getMonth()+1).toString().padStart(2, "0") + datedelim +
//     now.getDate().toString().padStart(2, "0") + spacer +
//     now.getHours().toString().padStart(2, "0") + timedelim +
//     now.getMinutes().toString().padStart(2, "0") + timedelim +
//     now.getSeconds().toString().padStart(2, "0");
// }

#endif