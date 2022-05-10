#include "../include/pilha.h"

int verifica(char* exp) {
    int balanceado = 1;
    char par;

    Pilha* p = pilha_cria();
    
    for (int i = 0; balanceado && exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            pilha_push(p, exp[i]);
        } else {
            par = pilha_pop(p);
            
                if (exp[i] == ')' && par != '(') {
                    balanceado = 0;
                } if (exp[i] == ']' && par != '[') {
                    balanceado = 0;
                } if (exp[i] == '}' && par != '{') {
                    balanceado = 0;
                }
            }
        }

    if (!pilha_vazia(p)) {
        balanceado = 0;
    }

    pilha_libera(p);
    return balanceado;
}
