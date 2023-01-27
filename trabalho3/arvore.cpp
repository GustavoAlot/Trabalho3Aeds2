#include "lista.h"
#include <bits/stdc++.h>
#include "arvore.h"

using namespace std;


int quantidade_nos(NoArvB *raiz) { // quantidade de nos da arvore
  if (raiz == NULL) {
    return 0;
  } else {
    return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
  }
}

int quantidade_folhas(NoArvB *raiz) { // quantidade de folhas da arvore
  if (raiz == NULL) {
    return 0;
  } else if (raiz->esquerda == NULL && raiz->direita == NULL) {
    return 1;
  } else {
    return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
  }
}

void imprimir_versao_1(NoArvB *raiz) { // imprime em ordem de insercao
  if (raiz) {
    printf("%f  ", raiz->veiculo->valor);
    imprimir_versao_1(raiz->esquerda);
    imprimir_versao_1(raiz->direita);
  }
}

void imprimir_versao_2(NoArvB *raiz) { // imprime em ordem crescente
  if (raiz) {
    imprimir_versao_2(raiz->esquerda);
    printf("%f  ", raiz->veiculo->valor);
    imprimir_versao_2(raiz->direita);
  }
}

int altura(NoArvB *raiz) { // altura da arvore
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

NoArvB *inserir_versao_1(NoArvB *raiz,
                         No *lista) { // insercao com retorno e recursao
No *aux = lista;
  while(aux){
    if (raiz == NULL) {
    NoArvB *aux = new (NoArvB);
    aux->veiculo = lista->veiculo;
    aux->direita = NULL;
    aux->esquerda = NULL;
    return aux;
  } else {
    if (lista->veiculo->placa < raiz->veiculo->placa) {
      raiz->esquerda = inserir_versao_1(raiz->esquerda, lista);
    } else {
      raiz->direita = inserir_versao_1(raiz->direita, lista);
    }
    return raiz;
  }
    aux=aux->prox;
  }
  
}
