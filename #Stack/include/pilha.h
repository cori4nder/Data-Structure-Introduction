/**
 * @file pilha.h
 * @author Lucas Dantas (lgd@academico.ufpb.br)
 * @brief 
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;

Pilha* pilha_cria(void);

void pilha_push(Pilha* p, float v);
float pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);

#endif 
