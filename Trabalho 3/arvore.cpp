#include "arvore.h"
#include "lista.h"
#include <bits/stdc++.h>

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

void imprimir_pre_ordem(NoArvB *raiz) { // imprime em ordem de insercao
    if (raiz){
        cout << raiz->veiculo->valor<< " " << raiz->veiculo->modelo << endl;
        imprimir_pre_ordem(raiz->esquerda);
        imprimir_pre_ordem(raiz->direita);
    }
}

void imprimir_em_ordem(NoArvB *raiz) { // imprime em ordem crescente
    if (raiz) {
        imprimir_em_ordem(raiz->esquerda);
        cout << raiz->veiculo->valor<< " " << raiz->veiculo->modelo << endl;
        imprimir_em_ordem(raiz->direita);
    }
}

void imprimir_pos_ordem(NoArvB *raiz) {
    if (raiz) {
        imprimir_pos_ordem(raiz->esquerda);
        imprimir_pos_ordem(raiz->direita);
        cout << raiz->veiculo->valor<< " " << raiz->veiculo->modelo << endl;
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

void inserir_versao_3(NoArvB **raiz, No *lista) { // insere sem retorno e sem recursao
    NoArvB *aux = *raiz;
        if (lista->veiculo->cor == "Branco") {
            while (aux) {
                if (lista->veiculo->valor < aux->veiculo->valor) {
                    raiz = &aux->esquerda;                            
                } else {
                    raiz = &aux->direita;
                }
                aux = *raiz;
            }

            aux = new(NoArvB);
            aux->veiculo = lista->veiculo;
            aux->direita = NULL;
            aux->esquerda = NULL;
            *raiz = aux;
            cout <<"inserindo: "<< aux->veiculo->valor << endl;
        }
}
