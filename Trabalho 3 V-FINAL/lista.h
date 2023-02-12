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
#ifndef LISTA_H
#define LISTA_H
#include <bits/stdc++.h>

using namespace std;

/*
 * Struct do veiculo é a principal Struct do projeto. Ela armazena os seguintes valores:
 * Modelo -> O modelo do carro que será guardado.
 * Marca - > A marca do carro que será guardado.
 * Tipo -> O tipo do carro que será guardado.
 * Ano -> O ano de fabricação do carro.
 * Km -> A kilometragem atual do carro.
 * Potência -> A potência do motor.
 * Combustível -> Tipo de combustível do veículo.
 * Câmbio -> Automático ou manual.
 * Direçao -> Mecânica, hidráulica ou elétrica.
 * Cor -> A cor do carro.
 * Portas -> A quantidade de portas do carro.
 * Placa -> A placa do carro que será guardado.
 * Preço -> O preço do carro.
*/
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

/*Struct que representa o nó da lista ligada.
 * prox-> aponta para o próximo nó da lista.
 * veículo-> aponta para a struct do veículo.
 */
typedef struct no {
  Tveiculo *veiculo;
  struct no *prox;
} No;

/*
 * chama da função para preencher a lista.
 */
void preenche_lista(No **lista, No *novo);

/*
 * Chama para a função de remoção.
 */
No *remove_veiculo(No **lista, string placa);

/*
 * chamada da função de salvar a lista no arquivo txt.
 */
void salvar_arq(No *lista);

/*
 * chamada da função de escrita de uma novo carro.
 */
Tveiculo *new_carro(string placa);

/*
 * chamada da função de inserção de um veículo.
 */
No *insere_veiculo(No **lista, string placa);

/*
 * chamada da função de busca na lista.
 */
No *buscar(No *lista, string placa);

/*
 * chamada da função de escrever o relatório.
 */
void relatorio(No *lista);


#endif