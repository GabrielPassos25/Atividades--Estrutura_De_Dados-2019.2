#include <iostream>
#include <new>
using namespace std;
template<typename T>
struct Fila{
    struct Noh{
        T elem; Noh *prox;
    };
    Noh *inicio, *fim;
    void inicializar(){
        inicio = fim = nullptr;
    }
    bool vazia(){
        return(inicio==nullptr);
    }
    T primeiro(){
        return(inicio->elem);
    }
    bool enfilar(T e){
        Noh* n= new(nothrow)Noh;
        if(n==nullptr){
            return true;
        }
        n->elem = e;
        n->prox = nullptr;
        if(vazia()){
            inicio=fim=n;
        }
        else{
            fim->prox=n;
            fim=n;
        }
        return false;
    }
    T desenfilar(){
        T e = inicio->elem;
        Noh* n=inicio;
        inicio = inicio->prox;
        delete n;
        return e;
    }
    void terminar(){
        while(inicio != nullptr){
            Noh* n=inicio;
            inicio = inicio->prox;
            delete n;
        }
    }
    void print(){
        Noh* n=inicio;
        cout <<"Fila: [";
        while(n!=nullptr){
            cout << n->elem << ",";
            n = n->prox;
        }
        cout<<"]\n";
        delete n;
    }
};
int main(){
    Fila<int> a;
    a.inicializar();
    cout<< a.vazia() <<" Vazia\n";
    a.enfilar(10);
    a.print();
    a.enfilar(20);
    a.print();
    a.enfilar(30);
    a.print();
    cout<< a.vazia() <<" Vazia\n";
    a.desenfilar();
    a.print();
    a.desenfilar();
    a.print();   
    cout<<a.primeiro() <<" Primeiro\n";
    a.terminar();
    a.print();   

}