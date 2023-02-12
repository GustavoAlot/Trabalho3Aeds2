
#include "arvore.h"
#include "lista.h"
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    /*
     * Declaração de vari
     áveis utilizadas.
     */
    NoArvB *raiz = NULL;
    No *lista = NULL;
    No *ordenado = NULL;

    No *aux;
    int impressao = 0;
    int newop = 0;
    string placa;
    char resposta;
    No *buscado;
    No *removido;

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
        cout << "\n\n\n ARQUIVO NÃO ENCONTRADO. \n\n\n" << endl;

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
                } else {
                    cout << "Veículo não existente no BD." << endl;
                }

                break;


            case 4:
                cout << "Arvores montadas!" << endl;
                aux = lista;
                while (aux) {
                    inserir_versao_3(&raiz, aux);
                    aux = aux->prox;
                }



                //ainda falta a AVL

                break;

            case 5:
                while (impressao != 5) {
                    cout << "[1] Arvore binária em ordem." << endl;
                    cout << "[2] Arvire binária em pós-ordem." << endl;
                    cout << "[3] Arvore binária em pré-ordem." << endl;
                    cout << "[5] Voltar para o menu principal." << endl;

                    cout << "Insira a opção desejada:" << endl;
                    cin >> impressao;
                    switch (impressao) {
                        case 1:
                            cout << "Arvore binaria em ordem" << endl;
                            imprimir_em_ordem(raiz);
                            printf("\n\tAltura da arvore : %d\n\n", altura(raiz));
                            printf("\nquantidade de nos: %d\n", quantidade_nos(raiz));
                            break;

                        case 2:
                            cout << "Arvore binaria pós ordem" << endl;
                            imprimir_pos_ordem(raiz);
                            printf("\n\tAltura da arvore : %d\n\n", altura(raiz));
                            printf("\nquantidade de nos: %d\n", quantidade_nos(raiz));
                            break;
                        case 3:
                            cout << "Arvore binaria pré ordem" << endl;
                            imprimir_pre_ordem(raiz);
                            printf("\n\tAltura da arvore : %d\n\n", altura(raiz));
                            printf("\nquantidade de nos: %d\n", quantidade_nos(raiz));
                            break;

                        default:
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

                return 0;

                break;

            default:
                cout << "\n\t\tOpção inválida.\n\n";
        }
    }
}
