#ifndef ARVORE_H
#define ARVORE_H
#include <bits/stdc++.h>
#include "lista.h"

using namespace std;


typedef struct noArvBinaria {
    Tveiculo *veiculo;
    struct noArvBinaria *direita, *esquerda;
} NoArvB;

typedef struct noArvAvl {
    Tveiculo*veiculo;
    struct noArvAvl *esq;
    struct noArvAvl *dir;
    int bal; // fator de balanceamento (0, -1 ou +1) => alt. direita - alt. esquerda
} NoArvA;

int quantidade_nos(NoArvB *raiz);
void inserir_versao_3(NoArvB **raiz, No *lista);
int altura(NoArvB *raiz);
void imprimir_em_ordem(NoArvB *raiz);
void imprimir_pre_ordem(NoArvB *raiz);
void imprimir_pos_ordem(NoArvB *raiz);
int quantidade_folhas(NoArvB *raiz);

NoArvA*rotacaoL(NoArvA*p);
NoArvA*criarNovoNo(No*lista);
int max(int a, int b);
int atualizarBalanceamentoTotal(NoArvA*raizAVL);
NoArvA*rotacaoL(NoArvA*p);
NoArvA*rotacaoR(NoArvA*p);
void inserirAVL(NoArvA**pp,No *lista, bool alterou);
void destruirAux(NoArvA*subRaiz);
void destruirArvore(NoArvA**raiz);
void imprimir_em_ordem(NoArvA *raizAVL);
void imprimir_pre_ordem(NoArvA *raizAVL);
void imprimir_pos_ordem(NoArvA *raizAVL);
int altura(NoArvA *raizAVL);
int quantidade_nos(NoArvA *raizAVL);
#endif