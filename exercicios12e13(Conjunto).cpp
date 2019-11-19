// 1. Complete a implementação de Conjunto Dinâmico iniciada em sala, escrevendo
// as funções-membro "redimensionar" e "terminar".
#include <iostream>
#include <new>
using namespace std;
struct Conjunto{    
    double *v; int tam_v, ult;
    bool inicializar(){
        v = new(nothrow)double[1];
        if(v==nullptr){
            return true;
        }
        tam_v = 1;
        ult = -1;
    }
    void terminar(){
        delete[] v;
    }
    bool redimensionar(int tam_n){
        double *w = new(nothrow)double[tam_n];
        if(w==nullptr){
            return true;
        }
        for(int i=0;i<=tam_n;i+=1){
            w[i] = v[i];
        }
        delete[] v; v=w;
        tam_v = tam_n;
        return false;
    }
    bool inserir(double e){
        if(ult <=tam_v){
            if(redimensionar(tam_v*2)){
                return true;
            }
        }
        ult +=1;
        v[ult] = e;
        return false;
    }
    bool remover(double e){
        if(!vazio() && 4*(ult+1)<=tam_v){
            if(redimensionar(tam_v/2)){
                return true;
            }
        }
        int i =0;
        while(e != v[i]){
            ++i;
        }
        v[i] = v[ult];
        ult-=1;
        return false;
    }
    bool pertence(double e){
        for(int i=0; i<=tam_v;i+=1){
            if(v[i]==e){
                return 1;
            }
        }
        return 0;
    }
    bool vazio(){
        if(ult == -1){
            return true;
        }
        return false;
    }
    void print(){
        cout<<"Vetor: [";
        for(int i=0; i<=ult;i+=1){
            cout << v[i] << ", ";
        }
        cout << "]\n";
    }
};
int main(){
    Conjunto p;
    p.inicializar();
    cout<<"Digite 0 para parar e 1 para continuar, 2 para inserir e 3 para remover\n";
    int escolha =1;int escolha2;
    double e;
    while(escolha!=0){
        cout<<"Deseja continuar no programa? [0/1]\n";
        cin>>escolha;
        cout<<"Deseja checar remover ou inserir um elemento? [4/3/2]\n";
        cin>>escolha2;
        if(escolha2 == 2){
            cout<<"Qual elemento deseja inserir?\n";
            cin >> e;
            p.inserir(e);
            p.print();
        }
        if(escolha2 ==3){
            cout << "Qual elemento deseja remover?\n";
            cin >> e;
            p.remover(e);
            p.print();
        }
        if(escolha2 ==4){
            cout << "0 representa que o elemento não pertence e 1 que o elemento pertence\n";
            cout << "Qual elemento deseja checar?\n";
            cin >> e;
            cout << "Resposta: " << p.pertence(e) <<"\n";
        }
    }

}