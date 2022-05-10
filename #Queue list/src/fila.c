#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/fila.h"

#ifndef FILA_C
#define FILA_C

struct fila {
    int n; // Número de elementos armazenados
    int ini; // Índice do início da fila
    int dim; // Dimensão corrente do vetor
    float* vet; // Vetor dos elementos
};

Fila* fila_cria (void ) {
    Fila* f = (Fila*) malloc(sizeof(Fila));

    f -> dim = 4; // Dimensão inicial
    f -> vet = (float *) malloc(f-> dim*sizeof (float ));
    f -> n = 0; // Inicializa fila vazia 
    f -> ini = 0; // Escolhe uma posição inicial

    return f;
}

void fila_insere(Fila* f, float v) {
    int fim;
    // Capacidade esgotada
    if (f -> n == f -> dim) { 
        f -> dim *= 2; // Realoca dobrando o tamanho
        f -> vet = (float*) realloc(f -> vet, f -> dim * sizeof(float));

        if (f -> ini != 0) {
            memmove(&f -> vet[f -> dim - f -> ini], &f -> vet[f -> ini], (f -> n - f -> ini) * sizeof(float));
        }
    }

    fim = (f -> ini + f -> n) % f -> dim;

    f -> vet[fim] = v;
    f -> n++;
}

float fila_retira(Fila* f) {
    float v;

    v = f -> vet[f -> ini]; // Retira do início
    f -> ini = (f -> ini + 1) % f -> dim;
    f -> n--;

    return v;
}

int fila_vazia(Fila* f) {
    return (f -> n == 0);
}

void fila_libera(Fila* f) {
    free(f -> vet);
    free(f);
}

#endif
