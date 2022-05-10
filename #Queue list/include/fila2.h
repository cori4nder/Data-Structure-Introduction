/**
 * @file fila2.h
 * @author Lucas Dantas (lgd@academico.ufpb.br)
 * @brief 
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef FILA2_H
#define FILA2_H

typedef struct fila2 Fila2;

Fila2* fila2_cria();

void fila2_insere_ini(Fila2* f, float v);
void fila2_insere_fim(Fila2* f, float v);
float fila2_retira_ini(Fila2* f);
float fila2_retira_fim(Fila2* f);
int fila2_vazia(Fila2* f);
void fila2_libera(Fila2* f);

#endif
