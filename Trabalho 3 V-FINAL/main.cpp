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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    /*
     * Declaração de variáveis utilizadas.
     */
    NoArvB *raiz = NULL; //inicializando a raiz como nulo.
    NoArvA *raizAVL = NULL; // inicializando a raiz da AVL como nulo.
    No *lista = NULL; //inicializando a lista como nula.
    No *ordenado = NULL; //inicializando o nó de ordenação como nulo.

    No *aux; //declaração de um nó auxiliar.
    int impressao = 0; //declaração do int impressão com o valor 0.
    int newop = 0; //delcaração do int nweop com o valor 0.
    string placa; // declaração da string da placa.
    char resposta; //declaração de char para a resposta do menu.
    No *buscado; //declaração do nó utilizado para busca
    No *removido; //declaração do nó utilizado na remoção.
    bool alterou = false; //declaração do bool alterou como false.



    ifstream myfile("BD_veiculos_2.txt");

    if (myfile.is_open()) {
        do {
            No *novoNo = new (No);
            preenche_lista(&lista, novoNo);

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
        cout << "\n\n ARQUIVO NÃO ENCONTRADO. \n\n" << endl;

    //MENU
    while (newop != 7) {
        cout << "[1] Incluir novo veículo." << endl;
        cout << "[2] Remover veiculo." << endl;
        cout << "[3] Busca." << endl;
        cout << "[4] Montar as árvores AVL e binária." << endl;
        cout << "[5] Relatório das árvores." << endl;
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
                } else {
                    cout << "Veículo não existente no BD." << endl;
                }

                break;


            case 4:
                cout << "Árvores montadas!" << endl;
                cout << "Critério de seleção de veículo: cor Branco" << endl;
                aux = lista;
                while (aux) {
                    if (aux->veiculo->cor == "Branco") {
                        inserir_versao_3(&raiz, aux);
                        inserirAVL(&raizAVL, aux, &alterou);
                    }
                    aux = aux->prox;
                }

                break;

            case 5:
                while (impressao != 3) {
                    cout << "[1] Árvore binária em pré-ordem." << endl;
                    cout << "[2] Árvore AVL em pré-ordem." << endl;
                    cout << "[3] Voltar para o menu principal." << endl;

                    cout << "Insira a opção desejada:" << endl;
                    cin >> impressao;
                    switch (impressao) {
                        case 1:
                            cout << "Árvore binária em pré-ordem" << endl;
                            imprimir_pre_ordem(raiz);
                            printf("\nAltura da árvore : %d\n", altura(raiz));
                            printf("\nQuantidade de nós: %d\n\n", quantidade_nos(raiz));
                            break;

                        case 2:
                            cout << "Árvore AVL em pré-ordem" << endl;
                            imprimir_pre_ordem(raizAVL);
                            printf("\nAltura da árvore : %d\n", altura(raizAVL));
                            printf("\nQuantidade de nós: %d\n\n", quantidade_nos(raizAVL));
                            break;

                        default:
                            if (impressao == 3) {
                                cout << "Retornou ao Menu!" << endl;
                            } else
                                cout << "\n\t\tOpção inválida.\n\n";
                            break;
                    }
                }

                break;

            case 6:
                aux = lista;
                relatorio(aux);
                break;

            case 7:
                cout << "Programa finalizado." << endl;

                salvar_arq(lista);

                while (lista) {
                    No *deletando = lista;
                    lista = lista->prox;
                    free(deletando);
                }
                destruirArvore(&raizAVL);
                destruirArvoreB(&raiz);

                return 0;

                break;

            default:
                cout << "\n\t\tOpção inválida.\n\n";
        }
    }
}
