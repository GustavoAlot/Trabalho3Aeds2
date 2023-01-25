#include "lista.h"
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main() {
  /*
   * Declaração de variáveis utilizadas.
   */
  No *fila = NULL;
  No *pilha = NULL;
  No *lista = NULL;
  No *ordenado = NULL;

  No *aux;
  int newop = 0;
  string placa;
  char resposta;
  No *buscado;
  No *removido;

  preenche_lista();

  /*
   * Escrita do menu na tela.
   */
  while (newop != 7) {
    cout << "[1] Incluir novo veículo." << endl;
    cout << "[2] Remover veiculo." << endl;
    cout << "[3] Buscas." << endl;
    cout << "[4] Montar arvores busca e avl." << endl;
    cout << "[5] Relatorio das arvores." << endl;
    cout << "[6] Relatório da lista ." << endl;
    cout << "[7] Sair do programa." << endl;
    cout << "Insira a opção desejada:" << endl;
    aux = lista;

    cin >> newop;

    /*
     * switch case para as opções do menu.
     */
    switch (newop) {
    case 1:
      cout << "Digite a placa do veículo. Ex: HJA9065" << endl;
      cin >> placa;

      buscado = buscar(lista, placa);
      if (buscado) {
        cout << "Carro já existente\n" << endl;
      } else {
        insere_veiculo(&lista, placa);
      }
      break;

    case 2:
      cout << "Insira a placa:" << endl;
      cin >> placa;
      buscado = buscar(lista, placa);

      if (buscado) {
        cout << "Veículo encontrado." << endl;
        cout << "Deseja remover o veículo? [S]=sim ou [N]=não" << endl;
        cin >> resposta;
        if (resposta == 'S' || resposta == 's') {
          removido = remove_veiculo(&lista, placa);
          cout << "Veículo removido\n" << endl;
        } else {
          cout << "Veículo não removido do BD." << endl;
        }
      } else {
        cout << "Veículo não existente no BD." << endl;
      }
      break;

    case 3:
      cout << "Insira a placa:" << endl;
      cin >> placa;
      buscado = buscar(lista, placa);

      if (buscado) {
        cout << "Veículo encontrado." << endl;
      }else{
        cout << "Veículo não existente no BD." << endl;

      }

      break;

    case 4:

      //OPcao de arvores
      break;

    case 5:
      //relatorio das arvores
      break;

    case 6:
      aux = lista;
      escreve_lista();
      break;

    case 7:
      cout << "Programa finalizado." << endl;

      while (lista) {
        No *deletando = lista;
        lista = lista->prox;
        free(deletando);
      }
      
      return 0;

      break;

    default:
      cout << "\n\t\tOpção inválida.\n\n";
    }
  }
}
