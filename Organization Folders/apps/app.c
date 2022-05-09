#include <stdio.h>
#include "../include/matriz.h"

int main() {
    
    Matriz *matrix = cria_matriz(2, 2);
    exibe_matriz(matrix);
    
    return 0;
}
