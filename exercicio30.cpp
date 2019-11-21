#include <iostream>
#include <new>
using namespace std;

//EXERCÍCIO 1
template <typename T>
struct ArvoreBinaria{
    struct Noh{
        T elem;
        Noh *fesq, *fdir;
    };
    struct Sequencia{
        T *v;
        int ult;
        int tam;  
    };
    Sequencia S;
    bool inicializar_vetor(){
            S.v = new(nothrow)T[1];
            if(S.v== nullptr){
                return true;
            }
            S.ult =0;
            S.tam = 1;
            return false;
        }
        bool inserir_vetor(T elem){
            S.v[S.ult] = elem;
            S.ult +=1;
            if(S.tam == S.ult){
                if(redimensionar(S.tam*2)){
                    return true;
                }
            }
        }
        bool remover_vetor(){
            if(S.ult >0){
                S.ult-=1;
                return false;
            }
            return true;
        }
        bool procurar_vetor(T elem){
            for(int i=0; i<S.ult;i+=1){
                if(S.v[i] == elem){
                    return true;
                }
            }
            return false;
        }
        bool redimensionar(int tam){
            T* va = new(nothrow)T[tam];
            if(va == nullptr){
                return true;
            }
            for(int i=0; i<S.ult;i+=1){
                va[i] = S.v[i];
            }
            delete[] S.v;
            S.v= va;
            return false;
        }  
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
    bool procurar(T elem){
        Noh* aux = raiz;
        while(aux != nullptr){
            if(aux-> elem == elem){
                return true;
            }
            else if(aux->elem < elem){
                aux = aux->fdir;
            }
            else if(aux->elem > elem){
                aux = aux->fesq;
            }
        }
        return false;
    }
    bool arvore_para_vetor(Noh *raiz, Sequencia &S){
        if(raiz == nullptr){
            return false;
        }
        else{
            Noh* aux = raiz;
            while(aux->fesq != nullptr){
                aux = aux->fesq;
            }
            int menor = aux->elem;
            inserir_vetor(menor);
            
        }
    }
    // bool remover(T elem){
    //     if(procurar(elem)){

    //     }
    //     else{
    //         return false;
    //     }
    // }
};
int main(){
    ArvoreBinaria<int> b;
    b.inserir(10);
    b.inserir(8);
    b.inserir(2);
    b.inserir(15);
    b.inserir(13);
    b.inserir(24);
    b.procurar(12);
    b.inicializar_vetor();
}
