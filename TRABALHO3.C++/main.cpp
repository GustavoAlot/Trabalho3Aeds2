#include "lista.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


int main(){
    No *aux;
    int newop = 0;
    string placa;
    char resposta;
    No *buscado;
    No *removido;

while (newop != 7) {
    cout << "[1] Incluir novo veículo." << endl;
    cout << "[2] Busca por placa e remoção." << endl;
    cout << "[3] Construir fila." << endl;
    cout << "[4] Ordenação por placa." << endl;
    cout << "[5] Construir pilha." << endl;
    cout << "[6] Relatório." << endl;
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
      cout << "Construção da fila.\n" << endl;
      while (aux) {
        if (aux->veiculo->cambio == "Automático") {
          insereFim(&fila, aux);

        } else {
          removido = removeInicio(&fila);
        }
        aux = aux->prox;
      }
      cout << "Final da fila" << endl;
      while (fila) {
        cout << fila->veiculo->modelo << " " << fila->veiculo->placa;
        cout << "\n";
        fila = fila->prox;
      }
      cout << "Início da fila" << endl;
      cout << "\n";
      break;

    case 4:

      cout << "Ordenação por placa.\n";
      ordenacao(lista, &ordenado);
      cout << "\n";
      break;

    case 5:
      cout << "Construção da pilha.\n";
      while (aux) {
        if (aux->veiculo->direcao == "Hidráulica") {
          pilha = empilhar(pilha, aux);
        } else {
          desempilha(&pilha);
        }
        aux = aux->prox;
      }
      cout << "Topo da pilha" << endl;
      while (pilha) {
        cout << pilha->veiculo->modelo << " " << pilha->veiculo->placa;
        cout << "\n";
        pilha = pilha->prox;
      }
      cout << "Base da pilha" << endl;
      cout << "\n";
      break;

    case 6:
      aux = lista;
      while (aux) {
        cout << aux->veiculo->modelo << " " << aux->veiculo->marca << " "
             << aux->veiculo->tipo << " " << aux->veiculo->ano << " "
             << aux->veiculo->km << " " << aux->veiculo->potencia << " "
             << aux->veiculo->combustivel << " " << aux->veiculo->cambio << " "
             << aux->veiculo->direcao << " " << aux->veiculo->cor << " "
             << aux->veiculo->portas << " " << aux->veiculo->placa << " "
             << aux->veiculo->valor << " " << endl;
        aux = aux->prox;
      }
      break;

    case 7:
      cout << "Programa finalizado." << endl;
      printarq(lista);

      while (lista) {
        No *deletando = lista;
        lista = lista->prox;
        free(deletando);
      }
      while (fila) {
        No *deletando = fila;
        fila = fila->prox;
        free(deletando);
      }
      while (pilha) {
        No *deletando = pilha;
        pilha = pilha->prox;
        free(deletando);
      }
      return 0;

      break;

    default:
      cout << "\n\t\tOpção inválida.\n\n";
    }
  }
}
