#include <iostream>
#include <new>
using namespace std;
template<typename T>
struct Deque{
    struct Noh{
        T elem; Noh *anterior, *sucessor;
    };
    Noh *esq, *dir;
    void inicializar(){
        esq = dir = nullptr;
    }
    bool vazia(){
        return(esq==nullptr && dir ==nullptr);
    }
    bool inserir_esquerda(T e){
        Noh* n=new(nothrow)Noh;
        if(n==nullptr){
            return true;
        }
        n->elem=e;
        n->anterior = nullptr;
        n->sucessor = esq;
        if(vazia()){
            dir= n;
        }else{
            esq->anterior = n;
        }
        esq =n;
        return false;

    }
    bool inserir_direita(T e){
        Noh* n= new(nothrow)Noh;
        if(n==nullptr){
            return true;
        }
        n->elem = e;
        n->sucessor = nullptr;
        n->anterior=dir;
        if(vazia()){
            esq = n;
        }else{
            dir->sucessor =n;
        }
        dir = n;
        return false;
    }
    T remover_esquerda(){
        T e = esq->elem;
        if(dir == esq){
            delete esq;
            return e;
        }else{
            Noh* n = esq;
            esq = esq->sucessor;
            esq->anterior = nullptr;
            delete n;
            return e;
        }
    }
    T remover_direita(){
        T e = dir->elem;
        if(dir == esq){
            delete dir;
            return e;
        }else{
            Noh *n = dir;
            dir = dir->anterior;
            dir->sucessor = nullptr;
            delete n;
            return e;
        }
    }
    T consultar_esquerda(){
        return(esq->elem);
    }
    T consultar_dir(){
        return(dir->elem);
    }
    void terminar(){
        while(esq!=nullptr){
            Noh* n = esq;
            esq = esq->sucessor;
            delete n;
        }
    }
    void print(){
        Noh* n = esq;
        cout << "Deque: [";
        while(n!=nullptr){
            cout << n->elem << ",";
            n = n->sucessor;
        }
        cout<<"]\n";
        delete n;
    }
};
int main(){
    Deque<int> a;
    a.inicializar();
    cout << a.vazia() <<" Vazia\n";
    a.inserir_esquerda(1);
    a.print();
    a.inserir_esquerda(2);
    cout << a.consultar_esquerda() <<" Consultar esquerda\n";
    a.print();
    a.inserir_direita(3);
    a.print();
    a.inserir_direita(8);
    a.print();
    a.inserir_esquerda(9);
    a.print();
    cout << a.consultar_dir() <<" Consultar direita\n";
    a.remover_direita();
    a.print();
    a.remover_direita();
    a.print();
    a.remover_esquerda();
    a.print();
    a.remover_esquerda();
    a.print();
    a.terminar();
    a.print();


}