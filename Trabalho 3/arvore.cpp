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
        cout << raiz->veiculo->valor << " " << raiz->veiculo->modelo << endl;
        imprimir_pre_ordem(raiz->esquerda);
        imprimir_pre_ordem(raiz->direita);
    }
}

void imprimir_em_ordem(NoArvB *raiz) { // imprime em ordem crescente
    if (raiz) {
        imprimir_em_ordem(raiz->esquerda);
        cout << raiz->veiculo->valor << " " << raiz->veiculo->modelo << endl;
        imprimir_em_ordem(raiz->direita);
    }
}

void imprimir_pos_ordem(NoArvB *raiz) {
    if (raiz) {
        imprimir_pos_ordem(raiz->esquerda);
        imprimir_pos_ordem(raiz->direita);
        cout << raiz->veiculo->valor << " " << raiz->veiculo->modelo << endl;
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
        cout << "inserindo: " << aux->veiculo->modelo << " " << aux->veiculo->valor << endl;
    }
}

void imprimir_pre_ordem(NoArvA *raizAVL) { // imprime em ordem de insercao
    if (raizAVL) {
        cout << raizAVL->veiculo->valor << " " << raizAVL->veiculo->modelo << endl;
        imprimir_pre_ordem(raizAVL->esq);
        imprimir_pre_ordem(raizAVL->dir);
    }
}

void imprimir_em_ordem(NoArvA *raizAVL) { // imprime em ordem crescente
    if (raizAVL) {
        imprimir_em_ordem(raizAVL->esq);
        cout << raizAVL->veiculo->valor << " " << raizAVL->veiculo->modelo << endl;
        imprimir_em_ordem(raizAVL->dir);
    }
}

void imprimir_pos_ordem(NoArvA *raizAVL) {
    if (raizAVL) {
        imprimir_pos_ordem(raizAVL->esq);
        imprimir_pos_ordem(raizAVL->dir);
        cout << raizAVL->veiculo->valor << " " << raizAVL->veiculo->modelo << endl;
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

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int atualizarBalanceamentoTotal(NoArvA*raizAVL) {
    if (!raizAVL)
        return 0;
    int d = atualizarBalanceamentoTotal(raizAVL->dir);
    int e = atualizarBalanceamentoTotal(raizAVL->esq);
    raizAVL->bal = d - e;
    return max(d, e) + 1;
}

/* Rotações à direita (LL e LR) 
   Retornará o endereço do nó que será a nova raiz da subárvore originalmente 
   iniciada por p */
NoArvA*rotacaoL(NoArvA*p) {
    cout << "Rotacao a esquerda, problema no nó:" << p->veiculo->modelo << " " << p->veiculo->valor << endl;
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
    cout << "Rotacao a direita, problema no no:" << p->veiculo->modelo << " " << p->veiculo->valor << endl;
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
void inserirAVL(NoArvA**pp, No*lista, bool alterou) {
    if (lista->veiculo->cor == "Branco") {
        NoArvA*p = *pp;
        if (!p) {
            *pp = criarNovoNo(lista);
            alterou = 1;
        } else {
            if (lista->veiculo->valor == p->veiculo->valor)
                alterou = 0;
            else
                if (lista->veiculo->valor <= p->veiculo->valor) {
                inserirAVL(&(p->esq), lista, alterou);
                if (alterou)
                    switch (p->bal) {
                        case 1:
                            p->bal = 0;
                            alterou = 0;
                            break;
                        case 0:
                            p->bal = -1;
                            break;
                        case -1:
                            *pp = rotacaoL(p);
                            alterou = 0;
                            break;
                    }
            } else {
                inserirAVL(&(p->dir), lista, alterou);
                if (alterou)
                    switch (p->bal) {
                        case -1:
                            p->bal = 0;
                            alterou = 0;
                            break;
                        case 0:
                            p->bal = 1;
                            break;
                        case 1:
                            *pp = rotacaoR(p);
                            alterou = 0;
                            break;
                    }
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