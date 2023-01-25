#include "lista.h"
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

NoArv * raiz = NULL;

typedef struct no { // estrutura no para composicao da arvore
  Tveiculo *veiculo;
  struct no *direita, *esquerda;
} NoArv;




void preencheArvoreBusca(NoArv **raiz,No *lista) { 
  NoArv *aux = *raiz;
  NoArv *novo;

  while(lista){
    while (aux) {
      if (lista->veiculo->valor < aux->veiculo->valor) {
        raiz = &aux->esquerda;
      } else {
        raiz = &aux->direita;
      }
      aux = *raiz;
    }

    aux = new(NoArv);
    aux->veiculo = lista->veiculo;
    aux->direita = NULL;
    aux->esquerda = NULL;
    *raiz = aux;
  }
}


void imprimir_versao_1(NoArv *raiz) { // imprime em ordem de insercao
  if (raiz) {
    printf("%d  ", raiz->veiculo->valor);
    imprimir_versao_1(raiz->esquerda);
    imprimir_versao_1(raiz->direita);
  }
}

void imprimir_versao_2(NoArv *raiz) { // imprime em ordem crescente
  if (raiz) {
    imprimir_versao_2(raiz->esquerda);
    printf("%d  ", raiz->veiculo->valor);
    imprimir_versao_2(raiz->direita);
  }
}


int quantidade_nos(NoArv *raiz) { // quantidade de nos da arvore
  if (raiz == NULL) {
    return 0;
  } else {
    return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
  }
}

int altura(NoArv *raiz) { // altura da arvore
  if (raiz == NULL) {
    return -1;
  } else {
    int esq = altura(raiz->esquerda);
    int dir = altura(raiz->direita);
    if (esq > dir) {
      return esq + 1;
    } else {
      return dir + 1;
    }
  }
}

