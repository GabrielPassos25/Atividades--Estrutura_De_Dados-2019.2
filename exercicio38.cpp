#include <iostream>
#include <new>
using namespace std;
template <typename T>
struct FilaDePrioridadeDesordenada{
    T *v, *maior; 
    int ultimo;
    T maior_elem;
    bool inicializar(){
        v = new(nothrow)T[10];
        if(v == nullptr){
            return true;
        }
        maior = nullptr;
        ultimo = -1;
        return false;
    }
    void inserir(T e){
        ultimo +=1;
        v[ultimo] = e;
        if(ultimo == 0){
            maior_elem = e;
            maior = &(v[0]);
        }
        else{
            v[ultimo] = e;
        }
        if(maior_elem < e){
            maior_elem = e;
            maior = &(v[ultimo]);
        }
    }
    T consultar_max(){
        if(ultimo == -1){
            cout << "Não possui elementos na fila!\n";
            return -1;
        }
        return *(maior);
    }
    T remover_max(){
        T elem = *(maior);
        *(maior) = v[ultimo];
        ultimo -=1;
        if(ultimo == -1){
            cout << "Não é possível remover de uma fila vazia!\n";
            return -1;
        }
        T maior_c = v[0];
        for(int i=0; i<ultimo;i+=1){
            if(v[i] > maior_c){
                maior = &(v[i]);
                maior_elem = v[i];
            }
            else{
                maior = &(v[0]);
                maior_elem = v[0]; 
            }
        }
        cout << "Elemento removido: ";
        return elem;
    }
    void printar(){
        cout << "["; 
        for(int i=0; i<=ultimo;i+=1){
            cout <<v[i]  << ",";
        }
        cout << "]\n";
    }

};
template <typename T>
struct FiladePrioridadeOrdenada{
    T *v; 
    int ultimo;
    bool inicializar(){
        v = new(nothrow)T[10];
        if(v == nullptr){
            return true;
        }
        ultimo = -1;
        return false;
    }
    void inserir(T e){
        ultimo +=1;
        if(ultimo == 0){
            v[ultimo] = e;
            return;
        }
        else{
            v[ultimo] = e;
            for(int i=0; i<ultimo;i+=1){
                while(v[i]>v[i+1]){
                    T aux = v[i];
                    v[i] = v[i+1];
                    v[i+1] = aux;
                    i-=1;
                }
            }
        }
    }
    T consultar_max(){
        return v[ultimo];
    }
    T remover_max(){
        T elem = v[ultimo];
        ultimo-=1;
        return elem;
    }
    void printar(){
        cout << "["; 
        for(int i=0; i<=ultimo;i+=1){
            cout <<v[i]  << ",";
        }
        cout << "]\n";
    }
    // void remover()
};
int main(){
    FilaDePrioridadeDesordenada<int> f;
    f.inicializar();
    f.inserir(3);
    cout << "Elemento máximo: " << f.consultar_max() << "\n";
    f.inserir(8);
    f.inserir(18);
    f.inserir(38);
    f.inserir(2);
    f.printar();
    cout << "Elemento máximo: " << f.consultar_max() << "\n";
    cout << f.remover_max() << "\n";
    cout << "Elemento máximo: " << f.consultar_max() << "\n";
    f.printar();
    cout << f.remover_max() << "\n";
    cout << "Elemento máximo: " << f.consultar_max() << "\n";
    f.printar();
    cout << f.remover_max() << "\n";
    cout << "Elemento máximo: " << f.consultar_max() << "\n";
    f.printar();
    cout << f.remover_max() << "\n";
    cout << "Elemento máximo: " << f.consultar_max() << "\n";
    f.printar();
    
    cout << f.remover_max() << "\n";
    cout << "Elemento máximo: " << f.consultar_max() << "\n";
    f.printar();
    FiladePrioridadeOrdenada<int> p;
    p.inicializar();
    p.inserir(1);
    p.printar();
    p.inserir(4);
    p.printar();
    p.inserir(3);
    p.printar();
    p.inserir(5);
    p.printar();
    p.inserir(2);
    p.printar();
    cout << "Elemento máximo: " << p.consultar_max() << "\n";
    cout << p.remover_max() << "\n";
    cout << "Elemento máximo: " << p.consultar_max() << "\n";
    p.printar();
    cout << p.remover_max() << "\n";
    cout << "Elemento máximo: " << p.consultar_max() << "\n";
    p.printar();
}