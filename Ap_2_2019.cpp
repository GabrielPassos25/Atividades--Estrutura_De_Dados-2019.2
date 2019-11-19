#include <iostream>
#include<new>
using namespace std;
struct ListaEncadeada{
    struct Noh{
        int elem;
        Noh* ant, *prox;
    };
    Noh* ini;
    Noh* aux;
    void inicializar(){
        ini = nullptr;
        aux = ini;
    }
    void inserir(int elem){
        Noh* n = new(nothrow)Noh;
        n->ant = aux;
        n->prox = nullptr;
        n->elem = elem;
        if(aux == nullptr){
            ini = n;
        }
        else{
            aux->prox = n;
        }
        aux = n;
    }
    void print(){
        Noh* j = ini;
        while(j != nullptr){
            cout << j->elem;
            j = j->prox;
        }
    }
};
int main(){
    ListaEncadeada cu;
    cu.inicializar();
    cu.inserir(4);
    cu.inserir(5);
    cu.inserir(8);
    cu.print();
}