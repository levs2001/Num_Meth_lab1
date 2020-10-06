#include<math.h>
#include"MyFunc.h"

double AlgFunc(double x) {
  //f(x) = x^4 - 5 x^2 - 4x + 7
  
  return pow(x, 4) - 5 * pow(x, 2) - 4 * x + 7;
}


double AlgFuncDer(double x) {
  //Вычисляет значение первой производной алгебраической функции
  double y = 4 * pow(x, 3) - 10 * x - 4;
  return y;
}

double AlgFunc2Der(double x) {
    //Вычисляет значение первой производной алгебраической функции
    double y = 12 * pow(x, 2) - 10;
    return y;
}


double TranscFunc(double x) {
  //f(x) = x^2 - 5*sin(x) + 2
  double y = pow(x,2) - 5*sin(x) + 2;
  return y;
}

double TranscFuncDer(double x) {
  //f(x) = 2x - 5*cos(x)
  double y = 2*x - 5 * cos(x);
  return y;
}

double TranscFunc2Der(double x) {
    //f(x) = 2x - 5*cos(x)
    double y = 2 + 5 * sin(x);
    return y;
}

double BisMeth(double(*Func)(double), double a, double b, int *iterCount, double eps) {
  //Функция ищет корень на участке a b с помощью метода половинного деления и возвращает его
  double c = 0, funcA = 0, funcC = 0;
  
  (*iterCount) = 0;

  //Проверка условий
  funcA = Func(a);
  if (funcA * Func(b) >= 0) {
    *iterCount = -1;
    return 0;
  }

  while (fabs(b - a) > 2 * eps) {
    c = (a + b) / 2;
    funcC = Func(c);

    if (funcA * funcC < 0)
        b = c;
    else {
        funcA = funcC;
        a = c;
    }
    (*iterCount)++;
  }

  return (a + b) / 2;
}


double NewtMeth(double(*Func)(double), double(*FuncDer)(double), double(*Func2Der)(double),
                double a, double b, int *iterCount, double eps) {
  double x0 = 0, x1 = 0;
  (*iterCount) = 0;
  
  //Проверка условий
  if (Func(a)*Func(b) >= 0) {
    *iterCount = -1;
    return 0;
  }
  
  // для выбора начальной точки проверяем f(x0)*d2f(x0)>0 
  if (Func(a) * Func2Der(a) > 0)
      x0 = a; 
  else
      x0 = b;
    
  x1 = x0 - Func(x0) / FuncDer(x0);
  (*iterCount)++;

  while (fabs(x1 - x0) > eps) {
    x0 = x1;
    x1 = x0 - Func(x0) / FuncDer(x0);
    (*iterCount)++;
  }

  return x1;
}