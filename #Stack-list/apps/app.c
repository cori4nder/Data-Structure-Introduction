#include <stdio.h>
#include "../include/pilha.h"

int main() {
    
    Pilha* stack1 = pilha_cria();

    pilha_push(stack1, 2);
    pilha_push(stack1, 8);

    printf("Antes do Pop\n");
    pilha_imprime(stack1);
    printf("\n");

    pilha_pop(stack1);

    printf("Pós Pop\n");
    pilha_imprime(stack1);

    return 0;
}
