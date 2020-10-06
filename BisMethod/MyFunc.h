#pragma once
double AlgFunc(double x);
double AlgFuncDer(double x);
double TranscFunc(double x);
double TranscFuncDer(double x);

double BisMeth(double(*Func)(double), double a, double b, int *iterCount, double eps);
double NewtMeth(double(*Func)(double), double(*FuncDer)(double),
  double a, double b, int *iterCount, double eps);