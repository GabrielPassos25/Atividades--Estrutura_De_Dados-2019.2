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
        int a = fator_balanceamento(raiz);
        em_ordem_nivel_balanceamento(raiz->fesq);
        cout << "Fator de balanceamento: " << a << " Valor do elemento: " << raiz->elem << "\n";
        em_ordem_nivel_balanceamento(raiz->fdir);
    }
    int fator_balanceamento(Noh* raiz){
        if(raiz == nullptr){
            return -1;
        }
        int esq = fator_balanceamento(raiz->fesq);
        int dir = fator_balanceamento(raiz->fdir);
        cout << esq << "e\n";
        cout << dir <<"d\n";
        return dir-esq;
    }
};
int main(){
    ArvoreBinaria<int> b;
    b.inserir(30);
    b.inserir(20);
    b.inserir(50);
    b.inserir(10);
    b.inserir(25);
    b.inserir(40);
    b.inserir(26);
    b.inserir(27);
    cout << "\n";
    b.em_ordem_nivel_balanceamento(b.raiz);
}
// -1
// -2