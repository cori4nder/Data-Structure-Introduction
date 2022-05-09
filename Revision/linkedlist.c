#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

#ifndef LINKEDLIST_C
#define LIKEDLIST_C

struct no{
    int info;
    struct no* prox;
};

No * ll_create_no(int info){
    No* no = (No*) malloc(sizeof(No));
    if(no){
        no->info = info;
        no->prox =  NULL;
    }
    return no;
}

int ll_is_empty(No* lhead){
    return (lhead == NULL);
}

int ll_size(No* lhead){
    int counter = 0;
    while(lhead != NULL){
        counter ++;
        lhead = lhead->prox;
    }
    return counter;
}

int ll_insert_first(No **lhead, int info){
    No* aux = ll_create_no(info);
    if(aux){
        aux->prox = *lhead;
        *lhead = aux;
        return 1;
    }
    return 0;
}

int ll_insert_last(No **lhead, int info){
    if(ll_is_empty(*lhead)){
        return ll_insert_first(lhead, info);
    }

    No* aux = ll_create_no(info);
    if(aux){
        No* crt = *lhead;
        while(crt->prox != NULL){
            crt = crt->prox;
        }
        crt->prox = aux;
        return 1;
    }
    return 0;
}

int ll_exists(No* lhead, int info){
    if(ll_is_empty(lhead)){
        return 0;
    }

    while(lhead != NULL){
        if(lhead->info == info){
            return 1;
        }
        lhead = lhead->prox;
    }
    return 0;
}

void ll_print(No* lhead, char* message){
    printf("%s", message);
    while(lhead != NULL){
        printf("%d", lhead->info);
        lhead = lhead->prox;
    }
    printf("\n");
}

void ll_clear(No** lhead){
    No* prox = NULL;
    No * aux = *lhead;
    while(aux != NULL){
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
    *lhead = NULL;
}

int ll_remove(No** lhead, int info){
    No* ante = NULL;
    No* aux = *lhead;
    int found = 0;
    while(aux != NULL){
        if(aux->info == info){
            found = 1;
            break;
        }
        ante = aux;
        aux = aux ->prox;
    }
    if(found){
        if(ante == NULL){
            *lhead =  aux->prox;
            free(aux);
            return 1;
        }

        ante->prox = aux->prox;
        free(aux);

        return 1;
    }
    return 0;
}

int ll_insert_sorted(No ** lhead, int info){
    if(ll_is_empty(*lhead)){
        return ll_insert_first(lhead, info);
    }
    No* new = ll_create_no(info);
    if(new){
        No* ante = NULL;
        No* aux = *lhead;

        while(aux != NULL && aux->info < info){
            ante = aux;
            aux = aux->prox;
        }

        if(ante == NULL){
            new ->prox = *lhead;
            *lhead = new;
            return 1;
        }

        new ->prox = ante->prox;
        ante->prox = new;

        return 1;
    }
    return 0;
}


#endif // LISTASEN_C