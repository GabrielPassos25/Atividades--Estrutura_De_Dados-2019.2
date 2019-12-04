#include <iostream>
#include <new>
using namespace std;
template <typename T>
struct Heap{
    T *v;
    int ultimo;
    bool inicializar(){
        v = new(nothrow)T[10];
        ultimo = 0;
    }
    void subir(T chave){
        if(chave ==0){
            return;
        }
        if(v[(chave-1)/2] < v[chave]){
            T elem = v[(chave-1)/2];
            v[(chave-1)/2] = v[chave];
            v[chave] = elem;
            subir((chave-1)/2);
        }
        return;
    }
    void inserir(T e){
        v[ultimo] = e;
        subir(ultimo);
        ultimo +=1;
    }
    void descer(int i){
        T e = v[i];
        for(;;){
            int max = (2*i)+1; //fesq
            if(ultimo <= max){
                break;
            }
            int fd = (2*i)+2;
            if(fd < ultimo && fd>max){
                max = fd;
            }
            if(e >= v[max]) break;
            v[i] = v[max];
            i = max;
        }
        v[i] = e;
    }
    T remover(){
        T elem = v[0];
        v[0] = v[ultimo-1];
        ultimo-=1;
        if(ultimo == 0){
            return elem;
        }
        descer(0);
        return elem;
    }
    void print(){
        cout << "[";
        for(int i =0; i<ultimo;i+=1){
            cout << v[i] << ",";
        }
        cout << "]";
    }

};
int main(){
    Heap<int> h;
    h.inicializar();
    h.inserir(10);
    h.inserir(10);
    h.inserir(5);

    h.inserir(13);

    h.inserir(2);
    h.inserir(12);
    h.inserir(14);
    // h.inserir(20);
    h.remover();
    // h.remover();
    // h.remover();
    h.print();

}