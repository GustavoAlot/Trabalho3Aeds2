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
    if (raiz) {
        cout << raiz->veiculo->placa << " " << raiz->veiculo->modelo << endl;
        imprimir_pre_ordem(raiz->esquerda);
        imprimir_pre_ordem(raiz->direita);
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
        while (aux) {
            if (lista->veiculo->placa < aux->veiculo->placa) {
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
        cout << "inserindo: " << aux->veiculo->modelo << " " << aux->veiculo->placa << endl;
}

void imprimir_pre_ordem(NoArvA *raizAVL) { // imprime em ordem de insercao
    if (raizAVL) {
        cout << raizAVL->veiculo->placa << " " << raizAVL->veiculo->modelo << endl;
        imprimir_pre_ordem(raizAVL->esq);
        imprimir_pre_ordem(raizAVL->dir);
    }
}


NoArvA*criarNovoNo(No*lista) {
    NoArvA*novoNo = new(NoArvA);
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->veiculo = lista->veiculo;
    novoNo->bal = 0;
    return novoNo;
}

/* Rotações à direita (LL e LR) 
   Retornará o endereço do nó que será a nova raiz da subárvore originalmente 
   iniciada por p */
NoArvA*rotacaoL(NoArvA*p) {
    NoArvA*u;
    NoArvA*v;
    u = p->esq;
    if (u->bal == -1) { // LL
        p->esq = u->dir;
        u->dir = p;
        p->bal = 0;
        u->bal = 0;
        return u;
    } else
        if (u->bal == 1) { // LR
        v = u->dir;
        u->dir = v->esq;
        v->esq = u;
        p->esq = v->dir;
        v->dir = p;
        if (v->bal == -1)
            p->bal = 1;
        else
            p->bal = 0;
        if (v->bal == 1)
            u->bal = -1;
        else
            u->bal = 0;
        v->bal = 0;
        return v;
    } else {
        p->esq = u->dir;
        u->dir = p;
        u->bal = 1;
        return u;
    }
}

/* Rotações à esquerda (RR e RL) 
   Retornará o endereço do nó que será a nova raiz da subárvore originalmente 
   iniciada por p */
NoArvA*rotacaoR(NoArvA*p) {
    NoArvA*u;
    NoArvA*v;
    u = p->dir;
    if (u->bal == 1) { //RR
        p->dir = u->esq;
        u->esq = p;
        p->bal = 0;
        u->bal = 0;
        return u;
    } else
        if (u->bal == -1) { //RL
        v = u->esq;
        u->esq = v->dir;
        v->dir = u;
        p->dir = v->esq;
        v->esq = p;
        if (v->bal == 1)
            p->bal = -1;
        else
            p->bal = 0;
        if (v->bal == -1)
            u->bal = 1;
        else
            u->bal = 0;
        v->bal = 0;
        return v;
    } else {
        p->dir = u->esq;
        u->esq = p;
        u->bal = -1;
        return u;
    }
}

/* Inserção AVL: p é inicializado com o endereco do nó raiz e 
 *alterou com false                                         */
void inserirAVL(NoArvA**pp, No*lista, bool*alterou) {
        NoArvA*p = *pp;
        if (!p) {
            *pp = criarNovoNo(lista);
            *alterou = true;
        } else {
            if (lista->veiculo->placa == p->veiculo->placa)
                *alterou = false;
            else
                if (lista->veiculo->placa <= p->veiculo->placa) {
                inserirAVL(&(p->esq), lista, alterou);
                if (*alterou)
                    switch (p->bal) {
                        case 1:
                            p->bal = 0;
                            *alterou = false;
                            break;
                        case 0:
                            p->bal = -1;
                            break;
                        case -1:
                            *pp = rotacaoL(p);
                            *alterou = false;
                            break;
                    }
            } else {
                inserirAVL(&(p->dir), lista, alterou);
                if (*alterou)
                    switch (p->bal) {
                        case -1:
                            p->bal = 0;
                            *alterou = false;
                            break;
                        case 0:
                            p->bal = 1;
                            break;
                        case 1:
                            *pp = rotacaoR(p);
                            *alterou = false;
                            break;
                    }
            }
        }
}

/* funcao auxiliar na destruicao (liberacao da memoria) de uma arvore */
void destruirAux(NoArvA*subRaiz) {
    if (subRaiz) {
        destruirAux(subRaiz->esq);
        destruirAux(subRaiz->dir);
        free(subRaiz);
    }
}

/* libera toda memoria de uma arvore e coloca NULL no valor da raiz    */
void destruirArvore(NoArvA**raiz) {
    destruirAux(*raiz);
    *raiz = NULL;
}

int quantidade_nos(NoArvA *raizAVL) { // quantidade de nos da arvore
    if (raizAVL == NULL) {
        return 0;
    } else {
        return 1 + quantidade_nos(raizAVL->esq) + quantidade_nos(raizAVL->dir);
    }
}

int altura(NoArvA *raizAVL) { // altura da arvore
    if (raizAVL == NULL) {
        return -1;
    } else {
        int esq = altura(raizAVL->esq);
        int dir = altura(raizAVL->dir);
        if (esq > dir) {
            return esq + 1;
        } else {
            return dir + 1;
        }
    }
}