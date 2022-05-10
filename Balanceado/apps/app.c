#include <stdio.h>
#include <stdlib.h>

#include "../include/pilha.h"

int verifica(char* exp);

int main() {

    char certo1[] = "[{()()}{}]";
    char certo2[] = "{[([{}])]}";

    char errado1[] = "{[(}])";
    char errado2[] = "{[)()(]}";

    printf("Resultado certo = %d\n", verifica(certo1));
    printf("Resultado certo = %d\n", verifica(certo2));

    printf("Resultado errado = %d\n", verifica(errado1));
    printf("Resultado errado = %d\n", verifica(errado2));

    return 0;
}
