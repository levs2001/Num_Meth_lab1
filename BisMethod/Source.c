#include<stdio.h>
#include"MyFunc.h"


int main(void) {
  int iterCount = 0;
  double root = 0;

  printf("AlgFunc\n");
  root = BisMeth(AlgFunc, 0, 1, &iterCount, 0.000001);
  if (iterCount == -1) 
    printf("No roots\n");
  else {
    printf("BisMeth 0 1, eps = 0.000001\n");
    printf("root = %f, iterCount = %d\n", root, iterCount);
  }


  root = NewtMeth(AlgFunc, AlgFuncDer, AlgFunc2Der, 0, 1, &iterCount, 0.000001);
  if (iterCount == -1)
    printf("No roots\n");
  else {
    printf("NewtMeth 0 1\n");
    printf("root = %f, iterCount = %d\n", root, iterCount);
  }

  /*root = NewtMeth()
  */return 0;
}

