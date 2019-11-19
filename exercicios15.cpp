#include <iostream>
#include <new>
using namespace std;
template <typename T>
struct Pilha{
    struct Noh{
        T elem; Noh* prox;
    };
    Noh* topo;
    void inicializar(){
        topo = nullptr;
    }
    bool vazia(){
        return(topo==nullptr);
    }
    T consultar_topo(){
        return(topo->elem);
    }
    bool empilhar(T e){
        Noh* n = new(nothrow)Noh;
        if(n==nullptr){
            return true;
        }
        n->prox=topo;
        n->elem=e;
        topo =n;
        return false;
    }
    T desempilhar(){
            T e = topo->elem;
            Noh* n=topo;
            topo= topo->prox;
            delete n;
            return e;
    }
    void terminar(){
        while(!vazia()){
            desempilhar();
        }
    }
};
int main(){
    Pilha<int> a;
    a.inicializar();
    a.empilhar(10);
    a.empilhar(20);
    a.empilhar(30);
    a.empilhar(40);
    cout << a.consultar_topo() << "\n";
    cout << a.desempilhar() << "\n";
    a.desempilhar();
    cout << a.desempilhar() << "\n";
    a.terminar();
    cout << a.vazia() << "\n";

}