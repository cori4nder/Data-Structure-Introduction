/**
 * @file fila.h
 * @author Lucas Dantas (lgd@academico.ufpb.br)
 * @brief 
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef FILA_H
#define FILA_H

typedef struct fila Fila;

Fila* fila_cria (void );

void fila_insere (Fila* f, float v);
float fila_retira (Fila* f);
int fila_vazia (Fila* f);
void fila_libera (Fila* f);


#endif
