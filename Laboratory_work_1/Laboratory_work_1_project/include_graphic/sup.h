// sup.h
// This file is a header for "sup.cpp" file

#ifndef SUP_H
#define SUP_H

#include "../shapes/shapes"

// ---------- solve_nonlinear_system----------

void solve_nonlinear_system(sPoint p01, int r1, sPoint p02, int r2, 
sPoint *res1_p1, sPoint *res1_p2, 
sPoint *res2_p1, sPoint *res2_p2, 
sPoint *res3_p1, sPoint *res3_p2, 
sPoint *res4_p1, sPoint *res4_p2
);

// ---------- rightRound ----------

int rightRound(double num);

#endif // SUP_H