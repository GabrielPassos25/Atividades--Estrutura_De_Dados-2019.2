#include <iostream>
#include <new>
using namespace std;
template <typename T>
struct ArvoreBinaria{
    struct Noh{
        T elem;
        Noh *fesq, *fdir;
    };
    Noh* raiz = nullptr;
    int inserir(T elem){
        Noh* novo = new(nothrow)Noh;
        novo->elem = elem;
        novo->fesq = novo->fdir = nullptr;
        if(raiz == nullptr){
            raiz = novo;
            return 1;
        }
        else{
            decisao(raiz,novo);
            return 1;
        }
    }
    void decisao(Noh* raiz,Noh* novo){
        if(raiz->elem >= novo->elem){
            inserir_esquerda(raiz,novo);
        }
        else{
            inserir_direita(raiz,novo);
        }
    }
    int inserir_esquerda(Noh* raiz, Noh* novo){
        if(raiz->fesq == nullptr){
            raiz->fesq = novo;
            return 1;
        }
        else{
            raiz = raiz->fesq;
            decisao(raiz,novo);
            return 1;
        }
        return 0;
    }
    int inserir_direita(Noh* raiz, Noh* novo){
        if(raiz->fdir == nullptr){
            raiz->fdir = novo;
            return 1;
        }
        else{
            raiz = raiz->fdir;
            decisao(raiz,novo);
            return 1;
        }
        return 0;
    }
    void em_ordem_nivel_balanceamento(Noh *raiz){
        if(raiz==nullptr){
            return;
        }
        em_ordem_nivel_balanceamento(raiz->fesq);
        int a = fator_balanceamento(raiz);
        cout << "Fator de balanceamento: " << a << " Valor do elemento: " << raiz->elem << "\n";
        em_ordem_nivel_balanceamento(raiz->fdir);
    }
    int fator_balanceamento(Noh* raiz){
        if(raiz == nullptr){
            return 0;
        }
        return altura(raiz->fdir) - altura(raiz->fesq);
    }
    int altura (Noh* r) {
    if (r == NULL) 
        return -1; // altura da árvore vazia
    else {
        int he = altura (r->fesq);
        int hd = altura (r->fdir);
        if (he < hd) return hd + 1;
        else return he + 1;
    }
}

};
int main(){
    ArvoreBinaria<int> b;
    b.inserir(20);
    b.inserir(10);
    b.inserir(30);
    b.inserir(5);
    b.inserir(8);
    b.inserir(7);
    b.inserir(26);
    b.inserir(27);
    cout << "\n";
    b.em_ordem_nivel_balanceamento(b.raiz);
}