#include <stdio.h>
#include <stdlib.h>

typedef struct vetordin VetorDin;
struct vetordin {
  int n; /* numero de elementos aramazenados no vetor */
  int v_dim; /* dimensao do vetor */
  float *v; /* ponteiro para o vetor de elementos */
};


VetorDin* cria_vetord(int dim);
int insere_vetord(VetorDin* vd, float x);
int tamanho_vetord(VetorDin* vd);
int acessa_vetord(VetorDin* vd, int pos, float *v);
void libera_vetord(VetorDin* vd);
void exibeVetor(VetorDin* vd);


/**
 * Essa funcao cria um vetor dinâmico
 *
 * @param dim Dimensao do vetor dinamico
 * @return Ponteiro para variavel do tipo VetorDin
 */
VetorDin* cria_vetord(int dim) {
  
  if (dim == 0) {
    printf("Dimensao deve ser positiva!\n");
    exit(1);
  }
  
  VetorDin *vd = NULL;
  vd = (VetorDin*) malloc(sizeof(VetorDin));
  if (!vd) {
    printf("ERRO!\n");
    exit(1);
  }
  
  vd->n = 0;
  vd->v_dim = dim;
  vd->v = NULL;

  vd->v = (float*) malloc(dim * sizeof(float));
  if (!vd->v) {
    printf("ERRO!\n");
    free(vd);
    exit(1);
  }

  return vd;
}


/**
 * Essa funcao insere elemento no vetor
 *
 * @param vd Ponteiro para variavel do tipo VetorDin
 * @param x Elemento que vai ser inserido no vetor
 * @return Retorna 0 em caso de fracasso e 1 se for sucesso
 */
int insere_vetord(VetorDin* vd, float x) {
  
  if (vd->n < vd->v_dim) {
    vd->v[vd->n] = x;
    vd->n++;
    return 1;
  }
  else if (vd->n == vd->v_dim) {
    vd->v_dim++;
    vd->v = (float*) realloc(vd->v, vd->v_dim * sizeof(float));
    vd->v[vd->n] = x;
    vd->n++;
    return 1;
  }
  else {
    return 0;
  }
}


/**
 * Essa funcao retorna o tamanho do vetor
 *
 * @param vd Ponteiro para variavel do tipo VetorDin
 * @return Retorna o tamanho do vetor
 */
int tamanho_vetord(VetorDin* vd) {
  return vd->n;
}


/**
 * Essa funcao acessa um dos valores do vetor
 *
 * @param vd Ponteiro para variavel do tipo VetorDin
 * @param pos Indice do valor que sera acessado no vetor
 * @param v Ponteiro para variavel do tipo float, representa valor acessado
 * @return Retorna 0 em caso de fracasso e 1 se for sucesso
 */
int acessa_vetord(VetorDin* vd, int pos, float *v) {
  
  if (pos < 0) {
    return 0;
  }
  else if (pos >= vd->n) {
    return 0;
  }
  else {
    *v = vd->v[pos];
    return 1;
  }
}


/**
 * Essa funcao libera memoria do vetor alocado dinamicamente
 *
 * @param vd Ponteiro para variavel do tipo VetorDin
 */
void libera_vetord(VetorDin* vd) {
  free(vd->v);
  free(vd);
}


/**
 * Essa funcao exibe o vetor alocado dinamicamente
 *
 * @param vd Ponteiro para variavel do tipo VetorDin
 */
void exibeVetor(VetorDin* vd) {
  
  printf("Valores do vetor: ");
  for (int i = 0; i < vd->n; i++) {
    printf("%f ", vd->v[i]);
  }
  printf("\n");
  
}