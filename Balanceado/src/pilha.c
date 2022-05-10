#include <stdio.h>
#include <stdlib.h>

#include "../include/pilha.h"

#ifndef PILHA_C
#define PILHA_C

struct elemento {
    char info;
    struct elemento* prox;
};

typedef struct elemento Elemento;

struct pilha {
    Elemento* prim;
};

Pilha* pilha_cria() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p -> prim = NULL;

    return p;
}

void pilha_push(Pilha* p, char v) {
    Elemento * novo = (Elemento *)malloc(sizeof(Elemento));

    novo -> info = v;
    novo -> prox = p->prim;
    p -> prim = novo;
}

float pilha_pop(Pilha* p) {
    Elemento * t;
    char a;

    if (pilha_vazia(p)) {
        printf("Pilha vazia.\n");
        exit(1);
    }

    t = p -> prim;
    a = t -> info;
    p -> prim = t -> prox;

    free(t);

    return a;
}

int pilha_vazia(Pilha* p) {
    return (p -> prim == NULL);
}

void pilha_libera(Pilha* p) {
    Elemento *t, * q = p -> prim;

    while (q != NULL) {
    t = q -> prox;
    free(q);
    q = t;
}

    free(p);
}

#endif
