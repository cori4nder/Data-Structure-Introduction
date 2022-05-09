#include <stdio.h>
#include <stdlib.h>

#include "../include/matriz.h"

#ifndef MATRIZ_C
#define MATRIZ_C

struct matriz {
  int lin;
  int col;
  float **v;
};

/**
 * Essa funcao cria uma matriz
 *
 * @param nl Linha do valor que sera acessado na matriz
 * @param nc Coluna do valor que sera acessado na matriz
 * @return Ponteiro para variavel do tipo Matriz
 */

Matriz* cria_matriz(int nl, int nc) {
  if (nl <= 0 || nc <= 0) {
    printf("Numero de linhas ou colunas deve ser positivo!\n");

    return 0;
  }
  
  Matriz *mat = NULL;
  mat = (Matriz*) malloc(sizeof(Matriz));

  if (!mat) {
    printf("ERRO!\n");

    return 0;
  }
  
  mat -> lin = nl;
  mat -> col = nc;
  mat -> v = NULL;

  mat -> v = (float**) malloc(nl * sizeof(float));

  if (!mat -> v) {
    printf("ERRO!\n");

    free(mat);

    return 0;
  }
  
  
  for (int i = 0; i < nl; i++) {
    mat -> v[i] = (float*) malloc(nc * sizeof(float));
    if (!mat -> v[i]) {
      
      for (int j = 0; j < i; j++) {
        free(mat -> v[j]);
      }
      free(mat -> v);
      free(mat);

      printf("ERRO!\n");
      exit(1);
    }
  }

  for (int i = 0; i < nl; i++) {
    for (int j = 0; j < nc; j++) {
      printf("Digite o valor na posicao %dx%d: ", i, j);
      scanf("%f", &mat -> v[i][j]);
    }
  }
  printf("\n");

  return mat;
}

/**
 * Essa funcao libera memoria da matriz alocada dinamicamente
 *
 * @param mat Ponteiro para variavel do tipo Matriz
 */

void libera_matriz(Matriz * mat) {
  for (int i = 0; i < mat -> lin; i++) {
    free(mat -> v[i]);
  }

  free(mat -> v);
  free(mat);

  printf("Matriz liberada com sucesso\n");
}

/**
 * Essa funcao exibe a matriz alocada dinamicamente
 *
 * @param mat Ponteiro para variavel do tipo Matriz
 */

void exibe_matriz(Matriz * mat) {
  for (int i = 0; i < mat -> lin; i++) {
    printf("\n");
    for (int j = 0; j < mat->col; j++) {
      printf("\t%.2f", mat -> v[i][j]);
    }
  }
  printf("\n\n");
}

/**
 * Essa funcao acessa um dos valores da matriz
 *
 * @param mat Ponteiro para variavel do tipo Matriz
 * @param i Linha do valor que sera acessado na matriz
 * @param j Coluna do valor que sera acessado na matriz
 * @param v Ponteiro para variavel do tipo float, representa valor acessado
 * @return Retorna 0 em caso de fracasso e 1 se for sucesso
 */

int acessa_matriz(Matriz * mat, int i, int j, float *v) {
  if (i < 0 || j < 0) {
    return 0;
  }
  else if (i >= mat->lin || j >= mat->col) {
    return 0;
  }
  else {
    *v = mat->v[i][j];
    return 1;
  }
}

/**
 * Essa funcao atribui um valor na matriz
 *
 * @param mat Ponteiro para variavel do tipo Matriz
 * @param i Linha do valor que sera acessado na matriz
 * @param j Coluna do valor que sera acessado na matriz
 * @param v Variavel do tipo float, sera atribuida na matriz
 * @return Retorna 0 em caso de fracasso e 1 se for sucesso
 */

int atribui_matriz(Matriz * mat, int i, int j, float v) {
  if (i < 0 || j < 0) {
    return 0;
  }
  else if (i >= mat -> lin || j >= mat -> col) {
    return 0;
  }
  else {
    mat->v[i][j] = v;
    return 1;
  }
}

/**
 * Essa funcao retorna o numero de linhas da matriz
 *
 * @param mat Ponteiro para variavel do tipo Matriz
 * @return Retorna numero de linhas da matriz
 */

int nlinhas(Matriz * mat) {
  return mat -> lin;
}

/**
 * Essa funcao retorna o numero de colunas da matriz
 *
 * @param mat Ponteiro para variavel do tipo Matriz
 * @return Retorna numero de colunas da matriz
 */
int ncolunas(Matriz * mat) {
  return mat -> col;
}

#endif
