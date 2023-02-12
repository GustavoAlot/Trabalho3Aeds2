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

#include "lista.h"
#include <bits/stdc++.h>

using namespace std;

/*
 * Função para preencher lista com os carros de BD.
 * @param lista
 * @param novo
 */
void preenche_lista(No **lista, No *novo) {
    No *aux = *lista;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = NULL;
    }
}

/*
 * Função para a remoção de um nó da lista a partir da placa.
 * @param lista
 * @param placa a ser removida
 * @return o nó removido
 */
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

/*
 *Função para salvar a lista no txt
 * @param lista
 */
void salvar_arq(No *lista) {
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

/*
 * Função para a escrita dos campos de um novo carro,
 * sendo a placa o critério de existência na lista.
 * @param placa a ser inserida.
 * @return nó do carro inserido.
 */
Tveiculo *new_carro(string placa) {
    Tveiculo *newcarro = new(Tveiculo);

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

/*
 * Função para inserção de um veículo.
 * @param lista
 * @param placa a ser inserida.
 * @return 
 */
No *insere_veiculo(No **lista, string placa) {

    No *novo = new(No);
    novo->veiculo = new_carro(placa);
    novo->prox = *lista;
    *lista = novo;
    return novo;
}

/*
 * Função para a busca de uma placa na lista.
 * @param lista
 * @param placa a ser buscada.
 * @return o nó do carro em que a placa foi buscada.
 */
No *buscar(No *lista, string placa) {
    No *removido = NULL;
    while (lista && lista->veiculo->placa != placa) {
        lista = lista->prox;
    }
    removido = lista;
    return removido;
}

/*
 *Função para imprimir na tela o relatório da lista. 
 * @param lista
 */
void relatorio(No *lista) {
    No *aux = NULL;
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