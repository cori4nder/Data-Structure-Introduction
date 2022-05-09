#include <stdio.h>
#include <stdlib.h>
#include "float_vector.h"

struct float_vector {
    int capacity; // num máximo de elementos
    int size; // qtde de elementos armazenados atual
    float *data; // vetor de floats
};

/**
 * @brief Cria (aloca) um vetor de floats com uma dada capacidade
 * 
 * @param capacity Capacidade de vetor 
 * @return FloatVector* Um vetor de floats alcocado/criado
 */

FloatVector *creat(int capacity) {
    FloatVector *vec = (FloatVector*) calloc(1, sizeof(FloatVector));
    
    vec -> size = 0;
    vec -> capacity = capacity;
    vec -> data = (float*) calloc(capacity, sizeof(float));

    return vec;
}

void destroy(FloatVector **vec_ref) {
    FloatVector *vec = *vec_ref;

    free(vec -> data);
    free(vec);

    *vec_ref = NULL;
}

