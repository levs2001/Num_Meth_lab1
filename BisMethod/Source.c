#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"MyFunc.h"
#include<math.h>

int main(void) {
	int iterCount = 0;
	double root = 0, eps = 0;
	FILE *alg_bis = NULL, *alg_newt = NULL, *transc_bis = NULL, *transc_newt = NULL;

	alg_bis = fopen("D:\\MyProgramms\\Num_Meth_Lab1\\N_eps_algFunc_BisMeth.txt", "w");
	alg_newt = fopen("D:\\MyProgramms\\Num_Meth_Lab1\\N_eps_algFunc_NewtMeth.txt", "w");
	transc_bis = fopen("D:\\MyProgramms\\Num_Meth_Lab1\\N_eps_transcFunc_BisMeth.txt", "w");
	transc_newt = fopen("D:\\MyProgramms\\Num_Meth_Lab1\\N_eps_transcFunc_NewtMeth.txt", "w");
	if (alg_bis == NULL || alg_newt == NULL || transc_bis == NULL || transc_newt == NULL) {
		printf("Can't open one of files");
		return;
	}

	for (int degree = 1; degree < 12; degree++) {
		eps = pow(10, -degree);
		root = BisMeth(AlgFunc, 0, 1, &iterCount, eps);
		fprintf(alg_bis, "%g %d\n", eps, iterCount);
		root = NewtMeth(AlgFunc, AlgFuncDer, AlgFunc2Der, 0, 1, &iterCount, eps);
		fprintf(alg_newt, "%g %d\n", eps, iterCount);
		root = BisMeth(TranscFunc, 0, 1, &iterCount, eps);
		fprintf(transc_bis, "%g %d\n", eps, iterCount);
		root = NewtMeth(TranscFunc, TranscFuncDer, TranscFunc2Der, 0, 1, &iterCount, eps);
		fprintf(transc_newt, "%g %d\n", eps, iterCount);
	}
	
	fclose(alg_bis);
	fclose(alg_newt);
	fclose(transc_bis);
	fclose(transc_newt);

	return 0;
}

