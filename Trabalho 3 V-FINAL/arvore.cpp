/* Universidade Federal de Alfenas (UNIFAL) - 2023
 * Discentes: Gustavo Fernandez Pascoaleto 2021.1.08.009
 * Letícia Freitas de Oliveira 2018.1.08.051
 * Lucas Pessoa Oliveira Alves 2022.1.08.044
 *
 * Docente: Paulo Alexandre Bressan - Algoritimo e Estrutura de Dados II
 * 
 * Trabalho com o objetivo de adquirir conhecimentos de manipulação de dados 
 * numa aplicação que realiza buscas numa lista principal de carros, vans e utilitários
 * e apresenta os resultados em árvore binária e árvore AVL.
 * 
 * Arquivo base para funções da árvore AVL:
 * http://www.each.usp.br/digiampietri/ACH2023/javaec/ArvoreAVL/arvoreAVL.c
 */

#include "arvore.h"
#include "lista.h"
#include <bits/stdc++.h>

using namespace std;

/*
 * Função para indicar a quantidade de nós da árvore.
 * @param raiz
 * @return 
 */
int quantidade_nos(NoArvB *raiz) { // quantidade de nos da arvore
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
    }
}

/*
 * Função para a indicação da quantidade de folhas.
 * @param raiz
 * @return 
 */
int quantidade_folhas(NoArvB *raiz) { // quantidade de folhas da arvore
    if (raiz == NULL) {
        return 0;
    } else if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1;
    } else {
        return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
    }
}

/*
 * Função para printar a árvore em pré-ordem.
 * @param raiz
 */
void imprimir_pre_ordem(NoArvB *raiz) { // imprime em ordem de insercao
    if (raiz) {
        cout << raiz->veiculo->placa << " " << raiz->veiculo->modelo << endl;
        imprimir_pre_ordem(raiz->esquerda);
        imprimir_pre_ordem(raiz->direita);
    }
}

/*
 * Função para indicar a altura da árvore. 
 * @param raiz
 * @return 
 */
int altura(NoArvB *raiz) {
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

/*
 * Função para inserção na árvore sem retorno e sem recursão.
 * @param raiz
 * @param lista
 */
void inserir_versao_3(NoArvB **raiz, No *lista) { 
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
}

/*
 * Função para printar a árvore AVL em pré-ordem.
 * @param raizAVL
 */
void imprimir_pre_ordem(NoArvA *raizAVL) { // imprime em ordem de insercao
    if (raizAVL) {
        cout << raizAVL->veiculo->placa << " " << raizAVL->veiculo->modelo << endl;
        imprimir_pre_ordem(raizAVL->esq);
        imprimir_pre_ordem(raizAVL->dir);
    }
}

/* função auxiliar na destruição (liberação da memória) de uma árvore 
*/
void destruirAuxB(NoArvB*subRaiz) {
    if (subRaiz) {
        destruirAuxB(subRaiz->esquerda);
        destruirAuxB(subRaiz->direita);
        free(subRaiz);
    }
}

/* libera toda memória de uma árvore e coloca NULL no valor da raiz.
 */
void destruirArvoreB(NoArvB**raiz) {
    destruirAuxB(*raiz);
    *raiz = NULL;
}

/*
 * Função para criar um novo nó da árvore.
 * @param lista
 * @return 
 */
NoArvA*criarNovoNo(No*lista) {
    NoArvA*novoNo = new(NoArvA);
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->veiculo = lista->veiculo;
    novoNo->bal = 0;
    return novoNo;
}

/* Rotações à direita (LL e LR) 
 * Retornará o endereço do nó que será a nova raiz da subárvore originalmente 
 * iniciada por p
 */
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
 * Retornará o endereço do nó que será a nova raiz da subárvore originalmente 
 * iniciada por p
 */
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
 *alterou com false
 */                                        
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

/* função auxiliar na destruição (liberação da memória) de uma árvore 
*/
void destruirAux(NoArvA*subRaiz) {
    if (subRaiz) {
        destruirAux(subRaiz->esq);
        destruirAux(subRaiz->dir);
        free(subRaiz);
    }
}

/* libera toda memória de uma árvore e coloca NULL no valor da raiz.
 */
void destruirArvore(NoArvA**raizAVL) {
    destruirAux(*raizAVL);
    *raizAVL = NULL;
}

/*
 * Função para indicar a quantidade dos nós da árvore.
 * @param raizAVL
 * @return 
 */
int quantidade_nos(NoArvA *raizAVL) {
    if (raizAVL == NULL) {
        return 0;
    } else {
        return 1 + quantidade_nos(raizAVL->esq) + quantidade_nos(raizAVL->dir);
    }
}

/*
 * Função para indicar a altura da árvore.
 * @param raizAVL
 * @return 
 */
int altura(NoArvA *raizAVL) {
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