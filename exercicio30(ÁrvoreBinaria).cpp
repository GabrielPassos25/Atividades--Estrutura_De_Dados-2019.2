#include <iostream>
#include <new>
using namespace std;

//EXERCÍCIO 1
template <typename T>
struct Sequencia{
    T *v;
    int ult;
    int tam;
    bool inicializar_vetor(){
            v = new(nothrow)T[1];
            if(v== nullptr){
                return true;
            }
            ult =0;
            tam = 1;
            return false;
        }
        bool inserir_vetor(T elem){
            v[ult] = elem;
            ult +=1;
            if(tam == ult){
                if(redimensionar(tam*2)){
                    return true;
                }
            }
            return false;   
        }
        bool remover_vetor(){
            if(ult >0){
                ult-=1;
                return false;
            }
            return true;
        }
        bool procurar_vetor(T elem){
            for(int i=0; i<ult;i+=1){
                if(v[i] == elem){
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
            for(int i=0; i<ult;i+=1){
                va[i] = v[i];
            }
            delete[] v;
            v= va;
            return false;
        }
        void print(){
            for(int i=0;i<ult;i+=1){
                cout << v[i] << "\n";
            }
        }
        void limpar_vetor(){
            delete[] v;
            inicializar_vetor();
        }
};
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
    void em_ordem(Noh* raiz,Sequencia<T> &S){
        if(raiz == nullptr){
            return;
        }
        else{
            em_ordem(raiz->fesq,S);
            S.inserir_vetor(raiz->elem);
            em_ordem(raiz->fdir,S);
        }
    }
    bool arvore_para_vetor(Sequencia<T> &S){
        if(raiz == nullptr){
            return false;
        }
        else{
            em_ordem(raiz,S);
            return true;
        }
    }
    bool remover(T elem){
        Noh* aux = raiz, *pai=nullptr;
        while(aux != nullptr && aux->elem !=elem){
            pai = aux;
            if(aux->elem < elem){
                aux = aux->fdir;
            }
            else{
                aux = aux->fesq;
            }
        }
        if(aux == nullptr){
            return false;
        }
        else{
            //Liberar memoria
            //1 filho ou 0 filhos
            if(aux->fesq == nullptr){
                if(pai == nullptr){
                    raiz = aux->fdir;
                }
                else if(pai->fesq == aux){
                    pai->fesq = aux->fdir;
                }
                else{
                    pai->fdir = aux->fdir;
                }
            }
            //1 filho ou 0 filhos
            else if(aux->fdir == nullptr){
                if(pai == nullptr){
                    raiz = aux->fesq;
                }
                else if(pai->fesq == aux){
                    pai->fesq = aux->fesq;
                }
                else{
                    pai->fdir = aux->fesq;
                }
            }
            else{
                Noh* menor = aux->fdir, *pai_menor = aux;
                while(menor->fesq !=nullptr){
                    pai_menor = menor;
                    menor = menor->fesq;
                }
                if(pai == nullptr){
                    raiz = menor;
                }
                else if(pai->fesq == aux){
                    pai->fesq = menor;
                }
                else{
                    pai->fdir = menor;
                }
                pai_menor->fesq = menor->fdir;
                menor->fesq = aux->fesq;
                menor->fdir = aux->fdir;
            }
        }
        return true;
    }
    void printar_nivel(Noh *raiz, int i){
        em_ordem(raiz, 1,i);
    }
    int percorrer(Noh* raiz,int cont){
        if(raiz == nullptr){
            return cont;
        }
        else{
            int a = percorrer(raiz->fesq,cont+1);
            int b =percorrer(raiz->fdir,cont+1);
            if(a>b){
                return a;
            }
            else{
                return b;
            }
        }
    }
    void printar_por_nivel(Noh* raiz){
        int c =percorrer(raiz,0);
        for(int i=1;i<=c;i+=1){
            em_ordem(raiz,1,i);
            cout << "\n";
        }
    }
    void em_ordem(Noh* raiz, int cont, int i){
        if(raiz == nullptr){
            return;
        }
        else{
            if(cont == i){
                cout << raiz->elem;
            }
            else{
                em_ordem(raiz->fesq,cont+1,i);
                em_ordem(raiz->fdir,cont+1,i);
            }
        }
    }
};

int main(){
    ArvoreBinaria<int> b;
    Sequencia<int> s;
    b.inserir(10);
    b.inserir(8);
    b.inserir(2);
    b.inserir(15);
    b.inserir(13);
    b.inserir(24);
    b.procurar(12);
    s.inicializar_vetor();
    b.arvore_para_vetor(s);
    // s.print(); 
    cout << "\n";
    // s.limpar_vetor();
    // b.remover(10);
    // b.remover(15);
    // b.remover(25);
    b.arvore_para_vetor(s);
    // s.print();
    b.printar_nivel(b.raiz,5);
    b.printar_por_nivel(b.raiz);
}