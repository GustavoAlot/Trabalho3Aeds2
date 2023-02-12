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

#ifndef ARVORE_H
#define ARVORE_H
#include <bits/stdc++.h>
#include "lista.h"

using namespace std;

/*
 * struct do nó de uma árvore binária.
 * veículo-> aponta para a struct do veículo.
 * noArvBinaria*direita,*esquerda-> aponta para o nó a esquerda ou a direita.
 */
typedef struct noArvBinaria {
    Tveiculo *veiculo;
    struct noArvBinaria *direita, *esquerda;
} NoArvB;

/*
 * struct do nó da árvore AVL.
 * veiculo-> aponta para o nó do veículo;
 * noArvAvl-> aponta para o nó da esquerda ou direta.
 * bal-> fator de balanceamento (0, -1 ou +1) => alt. direita - alt. esquerda
 */
typedef struct noArvAvl {
    Tveiculo*veiculo;
    struct noArvAvl *esq, *dir;
    int bal;
} NoArvA;

//ÁRVORE BINÁRIA

/*
 * chamada da função de mostrar a quantidade de nós da árvore.
 */
int quantidade_nos(NoArvB *raiz);

/*
 * chamada da função de inserção na árvore binária.
 */
void inserir_versao_3(NoArvB **raiz, No *lista);

/*
 * chamada para a função de mostrar a altura da árvore.
 */
int altura(NoArvB *raiz);

/*
 * chamada da função de imprimir a árvore em pré ordem.
 */
void imprimir_pre_ordem(NoArvB *raiz);

/*
 * chamada da função para imprimir a quantidade de folhas.
 */
int quantidade_folhas(NoArvB *raiz);

/*
 * chamada da função de desalocar as folhas da árvore AVL.
 */
void destruirAuxB(NoArvB*subRaiz);

/*
 * chamada da função de desalocar toda a memória de uma árvore.
 */
void destruirArvoreB(NoArvB**raiz);


//ÁRVORE AVL

/*
 * chamada da função para criar um novo nó na árvore AVL.
 */
NoArvA*criarNovoNo(No*lista);

/*
 * chamada da função de rotação à esquerda da árvore AVL.
 */
NoArvA*rotacaoL(NoArvA*p);

/*
 * chamada da função de rotação à direita da árvore AVL.
 */
NoArvA*rotacaoR(NoArvA*p);

/*
 * chamada da função de inserção na árvore AVL.
 */
void inserirAVL(NoArvA**pp,No *lista, bool*alterou);

/*
 * chamada da função de desalocar as folhas da árvore AVL.
 */
void destruirAux(NoArvA*subRaiz);

/*
 * chamada da função de desalocar toda a memória de uma árvore.
 */
void destruirArvore(NoArvA**raizAVL);

/*
 * chamada da função de imprimir os valores da árvore em pré-ordem.
 */
void imprimir_pre_ordem(NoArvA *raizAVL);

/*
 * chamada da função de imprimir a altura da árvore.
 */
int altura(NoArvA *raizAVL);

/*
 * chamada da função de imprimir a quantidade de nós da árvore.
 */
int quantidade_nos(NoArvA *raizAVL);
#endif