
#ifndef LISTA_H
#define LISTA_H
#include <bits/stdc++.h>






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
No *remove_veiculo(No **lista, string placa);
void printarq(No *lista);
Tveiculo *new_carro(string placa);
No *insere_veiculo(No **lista, string placa);
No *buscar(No *lista, string placa);
void relatorio(No *lista);




#endif