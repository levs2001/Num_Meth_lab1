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

double BisMeth(double(*Func)(double), double a, double b, int *iterCount, double eps) {
  //Функция ищет корень на участке a b с помощью метода половинного деления и возвращает его
  double c = 0;
  (*iterCount) = 0;

  //Проверка условий
  if (Func(a)*Func(b) >= 0) {
    *iterCount = -1;
    return 0;
  }
//не считать 2 раза Func(a)
  while (fabs(b - a) > 2 * eps) {
    c = (a + b) / 2;

    if (Func(a)*Func(c) < 0)
      b = c;
    else
      a = c;

    (*iterCount)++;
  }

  return (a + b) / 2;
}


double NewtMeth(double(*Func)(double), double(*FuncDer)(double), 
                double a, double b, int *iterCount, double eps) {
  double x0 = 0, x1 = 0;
  (*iterCount) = 0;
  
  //Проверка условий
  if (Func(a)*Func(b) >= 0) {
    *iterCount = -1;
    return 0;
  }
  x0 = b;
  x1 = x0 - Func(x0) / FuncDer(x0);
  (*iterCount)++;
  //выбирать стартовую точку из правила
  while (fabs(x1 - x0) > eps) {
    x0 = x1;
    x1 = x0 - Func(x0) / FuncDer(x0);
    (*iterCount)++;
  }

  return x1;
}