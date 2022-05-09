#ifndef CPX_H
#define CPX_H

typedef struct cpx CPX;

CPX *cria_complexo(float x, float y);
void libera_complexo(CPX *v);
CPX *pega_valores(CPX *cpx, float *x, float *y)

#endif
