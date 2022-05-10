#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/fila2.h"
#include "../include/listaNo2.h"

#include "../src/Listano2.c"

#ifndef FILA2_C
#define FILA2_C

struct fila2 {
    ListaNo2* ini;
    ListaNo2* fim;
};

void fila2_insere_ini(Fila2* f, float v) {
    ListaNo2* novo = (ListaNo2*) malloc(sizeof(ListaNo2));

    Lista2* l = lst2_cria();

    novo -> info = v;
    novo -> prox = l -> prim;
    novo -> ant = NULL;

    if (l -> prim != NULL) {
        l -> prim -> ant = novo;
    } else {
        l -> ult = novo;
        l -> prim = novo;
    }
}

void fila2_insere_fim(Fila2* f, float v) {
    ListaNo2* novo = (ListaNo2*) malloc(sizeof(ListaNo2));

    Lista2* l = lst2_cria();
    
    novo -> info = v;
    novo -> ant = l -> ult;
    novo -> prox = NULL;

    if (l -> ult != NULL) {
        l -> ult -> prox = novo;
    } else {
        l -> prim = novo;
        l -> ult = novo;
    }
}

float fila2_retira_ini(Fila2* f) {
    ListaNo2* t = f -> ini;
    float v = t -> info;
    f -> ini = t -> prox;

    if (f -> ini == NULL) {
        f -> fim = NULL;
    } else {
        f -> ini -> ant = NULL;
    }

    free(t);

    return v;
}

float fila2_retira_fim(Fila2* f) {
    ListaNo2* t = f -> fim;

    float v = t -> info;
    f -> fim = t -> ant;

    if (f -> fim == NULL) {
        f -> ini = NULL;
    } else {
        f -> fim -> prox = NULL; 

        free(t);

        return v;
    }

}

int fila2_vazia(Fila2* f) {
    return (f -> ini == 0);
}

void fila2_libera(Fila2* f) {
    free(f);
}

#endif
