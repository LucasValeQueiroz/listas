#include <iostream>
#define TAM 100
using namespace std; //função para utilizar std sem precisar utilizar (util para quando vai utilizar muitas vezes o "std::")
//Implemente as operações necessárias para manipular listas estáticas (Slides Aula 7) e um
//programa principal para demonstrar o uso dos procedimentos criados.
//IMPLEMENTAÇÃO




struct Lista {
    // Tamanho definido pela variavel TAM
    int vetor[TAM];
    int fim;
};

// Função para criar a lista
void criarLista(Lista &lista) {
    lista.fim = 0;
}

// Função para limpar a lista
void limparLista(Lista &lista) {
    lista.fim = 0;
}

// Função para verificar se a lista está cheia
bool listaCheia(const Lista &lista) {
    return lista.fim == TAM;
}

// Função para verificar se a lista está vazia
bool listaVazia(const Lista &lista) {
    return lista.fim == 0;
}

// Função para inserir item na última posição
bool inserirUltimaPosicao(Lista &lista, int item) {
    if (listaCheia(lista)) return false;
    lista.vetor[lista.fim++] = item;
    return true;
}

// Função auxiliar para empurrar itens
void empurrar(Lista &lista, int pos) {
    for (int i = lista.fim; i > pos; --i) {
        lista.vetor[i] = lista.vetor[i - 1];
    }
}

// Função para inserir item por posição
bool inserirPorPosicao(Lista &lista, int item, int pos) {
    if (listaCheia(lista) || pos < 0 || pos > lista.fim) return false;
    empurrar(lista, pos);
    lista.vetor[pos] = item;
    lista.fim++;
    return true;
}

// Função para remover item na última posição
bool removerUltimaPosicao(Lista &lista) {
    if (listaVazia(lista)) return false;
    lista.fim--;
    return true;
}
// Função para remover item em uma determinada posição
bool removerPosicao(Lista &lista, int posicao) {
    if (listaVazia(lista) || posicao < 0 || posicao >= lista.fim) return false;
    for (int i = posicao; i < lista.fim - 1; i++) {
        lista.vetor[i] = lista.vetor[i + 1];
    }
    lista.fim--;
    return true;
}
// Função para recuperar item dado uma chave
bool recuperarPorChave(const Lista &lista, int chave, int &item) {
    for (int i = 0; i < lista.fim; ++i) {
        if (lista.vetor[i] == chave) {
            item = lista.vetor[i];
            return true;
        }
    }
    return false;
}

// Função auxiliar para recolher itens
void recolher(Lista &lista, int pos) {
    for (int i = pos; i < lista.fim - 1; ++i) {
        lista.vetor[i] = lista.vetor[i + 1];
    }
}

// Função para recuperar item por posição
bool recuperarPorPosicao(const Lista &lista, int pos, int &item) {
    if (pos < 0 || pos >= lista.fim) return false;
    item = lista.vetor[pos];
    return true;
}

// Função para contar o número de itens
int contarItens(const Lista &lista) {
    return lista.fim;
}

// Função para imprimir a lista
void imprimirLista(const Lista &lista) {
    for (int i = 0; i < lista.fim; ++i) {
        cout << lista.vetor[i] << " ";
    }
    cout << endl;
}

// Programa principal para demonstrar o uso dos procedimentos criados
int main() {
    int opcao, item, chave = 0, posicao = 0;
    bool sair = false;
    Lista lista;
    //Cria a lista
    criarLista(lista);
    //Inicializa o Menu
    cout << "***************************************************" << endl;
    cout << "* Bem-vindos ao etudo de listas estaticas em C++! *" << endl;
    cout << "***************************************************" << endl;
    //Inicializa o loop até sair verdadeiro
    while (sair == false)
    {
        //MENU opções
        //Imprimindo quantidade de chaves na lista 
        cout << "**************"<< endl <<  "**QUANTIDADE**" << endl << "**************" << endl;
        cout << "Número de chaves na lista: " << contarItens(lista) << endl << endl;
        cout << "********"<< endl <<  "**MENU**" << endl << "********" << endl;
        cout << "1 - Imprimir lista de chaves" << endl;
        cout << "2 - Inserir chave na lista" << endl;
        cout << "3 - Inserir chave na lista em determinada posição" << endl;
        cout << "4 - Remover chave da lista" << endl;
        cout << "5 - Remover chave da lista em determinada posição" << endl;
        cout << "6 - Verificar se a chave existe na lista" << endl;
        cout << "7 - Verificar a  chave na posição" << endl;
        cout << "8 - Sair" << endl;
        cout << "Escolha uma opção:";
        cin >> opcao;
        if (opcao == 1){
            //Imprimir lista de chaves
            cout << "*********"<< endl <<  "**LISTA**" << endl << "*********" << endl; 
            cout << "Lista de chaves :" << endl;
            imprimirLista(lista);
        }else if (opcao == 2){
            //Inserir chave na ultima posição
            cout << "Digite a chave:";
            cin >> chave;
            cout << "*************"<< endl <<  "*ADICIONANDO*" << endl << "*************" << endl;
            inserirUltimaPosicao(lista, chave);
        }else if (opcao == 3){
            //Inserir chave em determinada posição
            cout << "Digite a chave:";
            cin >> chave;
            cout << "Digite a posição:";
            cin >> posicao;
            cout << "*************"<< endl <<  "*ADICIONANDO*" << endl << "*************" << endl;
            inserirPorPosicao(lista, chave, posicao);
        }else if (opcao == 4){
            cout << "***********"<< endl <<  "*REMOVENDO*" << endl << "***********" << endl;
            //Remover chave na ultima posição
            removerUltimaPosicao(lista);
        }else if (opcao == 5){
            //Remover chave em determinada posição
            cout << "Digite a posição:";
            cin >> posicao;
            cout << "*************"<< endl <<  "**REMOVENDO**" << endl << "**************" << endl;
            removerPosicao(lista, posicao);
        }else if (opcao == 6){
            //Verificar se a chave existe
            cout << "Digite a chave:";
            cin >> chave;
            cout << "***************"<< endl <<  "**VERIFICANDO**" << endl << "***************" << endl;
            if (recuperarPorChave(lista, chave, item)) {
                cout << "Chave encontrada: " << item << endl;
            } else {
                cout << "Chave não encontrada." << endl;
            }
        }else if (opcao == 7){
            //Verificar a chave na posição
            cout << "Digite a posição:";
            cin >> posicao;
            cout << "***************"<< endl <<  "**VERIFICANDO**" << endl << "***************" << endl;
            if (recuperarPorPosicao(lista, posicao, item)) {
                cout << "Item na posição "<< posicao<<": " << item << endl;
            } else {
                cout << "Posição inválida." << endl;
            }        
        }else if (opcao == 8){
            limparLista(lista);
            sair = true;
        }else{
            cout << "Opção invalida" << endl;
        }
        

    }

    return 0;
}