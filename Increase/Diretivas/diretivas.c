// #define, #indef, #undefine e #idndef

#include <stdio.h>
#include <conio.h>

#define VALOR 30
//#undef VALOR

int main() {
    //int total = 3 + VALOR;

    #ifndef VALOR
        printf("Saida: %d.\n", total);
    #else 
        printf("Nao existe.\n");
    #endif 

    return 0;
}
