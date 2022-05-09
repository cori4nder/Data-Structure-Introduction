#include <stdio.h>
#include <stdlib.h>

#include "cpx.h"

struct cpx {
	float a;
	float b;
};

CPX *cria_complexo(float x, float y) {
	CPX *v = (CPX*)malloc(sizeof(CPX));
	
	if(!v) {
		return NULL;
	}
	
	v -> a = x;
	v -> b = y;
	
	return v;
}

void libera_complexo(CPX *v) {
	if (!v) {
		printf("Deu errado!\n");
	}
	
	free(v);
}

CPX *pega_valores(CPX *cpx, float *x, float *y) {
	if(!cpx) {
		return 1;
	} else {
		*x = cpx -> a;
		*y = cpx -> b;
	}
}

CPX *setar

#endif
