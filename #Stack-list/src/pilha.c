#include <stdio.h>
#include <stdlib.h>

#include "../include/pilha.h"

#ifndef PILHA_C
#define PILHA_C

struct listano {
    float info;
    ListaNo* prox;
};

struct pilha {
    ListaNo* prim;
};

Pilha* pilha_cria() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));

    p -> prim = NULL;

    return p;
}

void pilha_push(Pilha* p, float v) {
    ListaNo* n = (ListaNo*) malloc(sizeof(ListaNo));

    n -> info = v;
    n -> prox = p -> prim;
    p -> prim = n;
}

float pilha_pop(Pilha* p) {
    ListaNo* t = p -> prim;

    float v = t -> info;
    p -> prim = t -> prox;

    free(t);

    return v;
}

int pilha_vazia(Pilha* p) {
    return (p -> prim == NULL);
}

void pilha_libera(Pilha* p) {
    ListaNo* q = p -> prim;
    
    while(q != NULL) {
        ListaNo* t = q -> prox;

        free(q);
        
        q = t;
    }

    free(p);
}

void pilha_imprime(Pilha* p) {
    for (ListaNo* q = p -> prim; q != NULL; q = q -> prox) {
        
        printf("%f\n", q -> info);
    }
}

#endif
