#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/listaNo2.h"

#ifndef LISTANO2_C
#define LISTANO2_C

struct lista2 {
    ListaNo2* prim;
    ListaNo2* ult;
};

struct listano2 {
    float info;
    ListaNo2* ant;
    ListaNo2* prox;
};

Lista2* lst2_cria() {
    Lista2* l = (Lista2*) malloc(sizeof(Lista2));

    l -> prim = NULL;
    l -> ult = NULL;
    l -> ult = NULL;

    return l;
}
#endif
