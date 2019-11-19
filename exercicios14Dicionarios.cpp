#include <iostream>
#include <new>
using namespace std;
template<typename X, typename Y>
struct Par{
     X x;Y y;
};
template<typename TC,typename TD>
struct Dicionario{
    Par<TC,TD> *v; int ult, tam_v;
    bool inicializar(){
        v = new(nothrow)Par<TC,TD>[1];
        if(v==nullptr){
            return true;
        }
        tam_v =1;
        ult =-1;
        return false;
    }
    void terminar(){
        delete[] v;
    }
    bool vazio(){
        if(ult==-1){
            return true;
        }
        return false;
    }
    Par<bool,TD> procurar(TC c){
        for(int i=0;i<=ult; i+=1){
            if(v[i].x==c){
                Par<bool,TD> p;
                p.x =true;
                p.y = v[i].y;
                return p;
            }
        }
        Par<bool,TD> p;
        p.x =false;
        return p;
    }
    Par<bool,bool> inserir(TC c,TD d){
        if(ult==tam_v-1){
            if(redimensionar(tam_v*2)){
                Par<bool,bool> r;
                r.x=false;
                r.y=true;
                return r;
            }
        }
        Par<bool,TD> p=procurar(c);
        if(p.x){
            Par<bool,bool> r;
            r.x = true;
            cout<< "Elemento já pertence!\n";
            return r;
        }
        ult+=1;v[ult].x =c;v[ult].y =d;
        Par<bool,bool> r={false,false};
        return r;
    }
    bool redimensionar(int tam_w){
        Par<TC,TD> *w= new(nothrow)Par<TC,TD>[tam_w];
        if(w ==nullptr){
            return true;
        }
        for(int i=0;i<=ult;i+=1){
            w[i] = v[i];
        }
        delete[] v; v=w;
        tam_v =tam_w;
        return false;
    }
    Par<bool,bool> remover(TC c){
        if(!vazio() && 4*ult<=tam_v){
            if(redimensionar(tam_v/2)){
                Par<bool,bool> r;
                r.x=false;
                r.y = true;
                return r;
            }
        }
        Par<bool,TD> p = procurar(c);
        if(p.x == false){
            Par<bool,bool> r;
            r.x = true;
            return r;
        }
        Par<bool,bool> r;
        int i = 0;
        while (v[i].x != c) i++;
        v[i].x = v[ult].x;
        ult--;
        r.x = false; r.y = false;
        return r;
    }
    void print(){
        cout<<"Vetor: [";
        for(int i=0; i<=ult;i+=1){
            cout << v[i] << ", ";
        }
        cout << "]\n";
    }
};
int main () {
    Dicionario<char, double> D;
    if (D.inicializar()) return 1;
    char c, key;
    double num;
    do {
        cout << "\nOperações: i (inserir), (r) remover, (p) pertence, (s) parar: " ; cin >> c; cout << '\n';
        switch (c) {
            case 'i': {
                cout << "Insira a chave a ser inserida (um caractere): "; cin >> key;
                cout << "Insira o número a ser inserido: "; cin >> num;
                Par<bool, bool> r = D.inserir(key, num);
                if (r.x) cout << "Chave já pertence ao conjunto. \n";
                else if (!(r.x) && (r.y)) {
                    cout << "Erro de alocação!\n";
                } else if (!(r.x) && !(r.y)) {
                    cout << "Chave inserida!\n";
                }
            } break;

            case 'r': {
                cout << "Insira a chave a ser removida (um caractere): "; cin >> key;
                Par<bool, bool> j = D.remover(key);
                if (j.x) cout << "Chave não pertence ao conjunto. \n";
                else if (!(j.x) && (j.y)) {
                    cout << "Erro de alocação!\n";
                }
                else if (!(j.x) && !(j.y)) {
                    cout << "Chave removida!\n";
                }
            } break;

            case 'p': {
                cout << "Pesquisar chave: "; cin >> key;
                Par<bool, double> k = D.procurar(key);
                if (k.x) cout << key << ": " << k.y << '\n';
                else if (!(k.x)) cout << "Chave não encontrada. \n";
            } break;
        }
    } while (c != 's');
    D.terminar();
}
