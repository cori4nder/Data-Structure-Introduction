/**
 * @file matriz.h
 * @author  Lucas Dantas
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Tipo Abstrato de Dado que representa uma matriz.
 */

typedef struct matriz Matriz;

Matriz* cria_matriz(int nl, int nc);
void libera_matriz(Matriz * mat);
void exibe_matriz(Matriz * mat);
int acessa_matriz(Matriz * mat, int i, int j, float *v);
int atribui_matriz(Matriz * mat, int i, int j, float v);
int nlinhas(Matriz * mat);
int ncolunas(Matriz * mat);

