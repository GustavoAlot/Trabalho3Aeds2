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
void inserir_versao_3(NoArvB **raiz, No *lista);
int altura(NoArvB *raiz);
void imprimir_em_ordem(NoArvB *raiz);
void imprimir_pre_ordem(NoArvB *raiz);
void imprimir_pos_ordem(NoArvB *raiz);
int quantidade_folhas(NoArvB *raiz);

#endif