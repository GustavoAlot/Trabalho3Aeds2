#ifndef ARVORE_H
#define ARVORE_H
#include <bits/stdc++.h>
#include "lista.h"

using namespace std;



typedef struct noArvBinaria {
  Tveiculo *veiculo;
  struct noArvBinaria *direita, *esquerda;
} NoArvB;

int quantidade_nos(NoArvB *raiz);
NoArvB *inserir_versao_1(NoArvB *raiz, No *lista);
int altura(NoArvB *raiz);
void imprimir_versao_2(NoArvB *raiz);
void imprimir_versao_1(NoArvB *raiz);
int quantidade_folhas(NoArvB *raiz);

#endif
