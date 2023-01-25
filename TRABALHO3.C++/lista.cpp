#include "lista.h"
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

No* lista = NULL;
No* aux = NULL;

void inseredotxt(No **lista, No *novo) {
  No *aux = *lista;

  if (*lista == NULL) {
    *lista = novo;
  } else {
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
  }
}

void escreve_lista(No * aux){
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

}


void preenche_lista(){
    ifstream myfile("BD_veiculos_2.txt");

    if (myfile.is_open()) {
        do {
        No *novoNo = new (No);
        inseredotxt(&lista, novoNo);

        Tveiculo *newveiculo = new (Tveiculo);
        myfile >> newveiculo->modelo;
        myfile >> newveiculo->marca;
        myfile >> newveiculo->tipo;
        myfile >> newveiculo->ano;
        myfile >> newveiculo->km;
        myfile >> newveiculo->potencia;
        myfile >> newveiculo->combustivel;
        myfile >> newveiculo->cambio;
        myfile >> newveiculo->direcao;
        myfile >> newveiculo->cor;
        myfile >> newveiculo->portas;
        myfile >> newveiculo->placa;
        myfile >> newveiculo->valor;
        novoNo->veiculo = newveiculo;

        } while (!myfile.eof());

        myfile.close();
    } else
        cout << "\n\n\n ARQUIVO NÃO ENCONTRADO. \n\n\n" << endl;

}





No *remove_veiculo(No **lista, string placa) {

  No *aux = *lista;
  No *remover = NULL;

  if ((*lista)->veiculo->placa == placa) {
    remover = *lista;
    *lista = remover->prox;
  } else {
    aux = *lista;
    while (aux->prox != NULL && aux->prox->veiculo->placa != placa) {
      aux = aux->prox;
    }

    if (aux->prox) {
      remover = aux->prox;
      aux->prox = remover->prox;
    }
  }
  return remover;
}




void printarq(No *lista) {

  ofstream out;
  out.open("BD_veiculos_2.txt");
  while (lista != NULL) {
    out << lista->veiculo->modelo << " " << lista->veiculo->marca << " "
        << lista->veiculo->tipo << " " << lista->veiculo->ano << " "
        << lista->veiculo->km << " " << lista->veiculo->potencia << " "
        << lista->veiculo->combustivel << " " << lista->veiculo->cambio << " "
        << lista->veiculo->direcao << " " << lista->veiculo->cor << " "
        << lista->veiculo->portas << " " << lista->veiculo->placa << " "
        << lista->veiculo->valor << " " << endl;
    lista = lista->prox;
  }
}




Tveiculo *new_carro(string placa) {
  Tveiculo *newcarro = new (Tveiculo);

  newcarro->placa = placa;

  cout << "Digite o modelo do veículo. Ex: KA\n";
  cin >> newcarro->modelo;

  cout << "Digite a marca do veículo. Ex: FORD.\n";
  cin >> newcarro->marca;

  cout << "Digite o tipo do veículo. Ex: SUV.\n";
  cin >> newcarro->tipo;

  cout << "Digite o ano do veículo. Ex: 2000.\n";
  cin >> newcarro->ano;

  cout << "Digite a quilometragem do veículo. Ex: 32000.\n";
  cin >> newcarro->km;

  cout << "Digite a potência do veículo. Ex: 1.6\n";
  cin >> newcarro->potencia;

  cout << "Digite o tipo de combustível do veículo. Ex: Flex.\n";
  cin >> newcarro->combustivel;

  cout << "Digite o tipo de câmbio do veículo. Ex: Manual.\n";
  cin >> newcarro->cambio;

  cout << "Digite o tipo de direção do veículo. Ex: Hidráulica.\n";
  cin >> newcarro->direcao;

  cout << "Digite a cor do veículo. Ex: Preto.\n";
  cin >> newcarro->cor;

  cout << "Digite quantas portas há no veículo. Ex: 4\n";
  cin >> newcarro->portas;

  cout << "Digite o valor do veículo. Ex: 00000.00\n";
  cin >> newcarro->valor;

  cout << "  Veículo inserido.\n" << endl;

  return newcarro;
}




No *insere_veiculo(No **lista, string placa) {

  No *novo = new (No);
  novo->veiculo = new_carro(placa);
  novo->prox = *lista;
  *lista = novo;
  return novo;
}
  



No *buscar(No *lista, string placa) {
  No *removido = NULL;
  while (lista && lista->veiculo->placa != placa) {
    lista = lista->prox;
  }
  removido = lista;
  return removido;
}



void relatorio(){
    
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
}
