#include <stdio.h>
#include <stdlib.h>

#include "../include/pilha.h"

#ifndef PILHA_C
#define PILHA_C

struct pilha {
    int n; // Número de elementos armazenados
    int dim; // Dimensão corrente do vetor
    float* vet; // Vetor dos elemenetos
};

Pilha* pilha_cria() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));

    p -> dim = 2; // Dimensão inicial
    p -> vet = (float*) malloc(p -> dim * sizeof(float));
    p -> n = 0; // Inicializa com 0 elementos

    return p;
}

void pilha_push(Pilha* p, float v) {
    if (p -> n == p -> dim) { // Capacidade esgotada
        p -> dim *= 2;
        p -> vet = (float*) realloc(p -> vet, p -> dim * sizeof(float));
    }

    p -> vet[p -> n++] = v;
}

float pilha_pop(Pilha* p) {
    float v = p -> vet[--p -> n]; // Retira elemento do topo

    return v;
}

int pilha_vazia(Pilha* p) {
    return (p -> n == 0);
}

void pilha_libera(Pilha* p) {
    free(p -> vet);
    free(p);
}

#endif
