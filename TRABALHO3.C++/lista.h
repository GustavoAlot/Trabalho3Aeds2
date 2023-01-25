#ifndef LISTA_H
#define LISTA_H
#include <stdlib.h>
#include <iostream>
#include "arvore.cpp"

using namespace std;


typedef struct {
  string modelo;
  string marca;
  string tipo;
  int ano;
  int km;
  float potencia;
  string combustivel;
  string cambio;
  string direcao;
  string cor;
  int portas;
  string placa;
  float valor;
} Tveiculo;

typedef struct no {
  Tveiculo *veiculo;
  struct no *prox;
} No;


void inseredotxt(No **lista, No *novo);
void preenche_lista();
No *remove_veiculo(No **lista, string placa);
void printarq(No *lista);
Tveiculo *new_carro(string placa);
No *insere_veiculo(No **lista, string placa);
No *buscar(No *lista, string placa);
void relatorio();
void escreve_lista(No *aux);



// a partir daqui sao funcoes das arvores
void preencheArvoreBusca(NoArv **raiz,No *lista);
void imprimir_versao_1(NoArv *raiz);
void imprimir_versao_2(NoArv *raiz);
int altura(NoArv *raiz);
int quantidade_nos(NoArv *raiz);
#endif