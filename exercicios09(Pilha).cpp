//ENUNCIADO:
// Com base no conteúdo apresentado até aqui, implemente, de alguma forma, um
// tipo que represente uma pilha em C++. Observações:
// a) As operações básicas a serem implementadas são: inicializar, empilhar,
// desempilhar, vazia, topo e terminar.
// b) Você escolhe se implementará uma pilha limitada ou ilimitada. No caso
// da versão limitada, o tamanho máximo da pilha deve ser informado à
// função de inicialização.
// c) Você também pode escolher se implementará uma pilha genérica, que pode
// ser instanciada para qualquer tipo de elemento T, ou se implementará uma
// pilha para elementos de um tipo específico (int, double, etc).
// d) Por fim, você escolhe se as operações serão definidas como funções fora
// do tipo Pilha, ou se serão funções-membro desse tipo.
// e) Considere a opção metodológica de começar implementando uma pilha
// bem simples, e então, na medida em que houver tempo, adicionar recursos
// mais elaborados (pilha ilimitada, polimorfismo, funções-membro).
#include <iostream>
#include <new>
using namespace std;
struct Pilha{
    double* v; int ult, tamanho;

    bool inicializar(){
        v = new(nothrow)double[1];
        if(v==nullptr){
            return true;
        }
        ult = -1;
        tamanho = 1;
        return false;
    }
    bool vazia(){
        if(ult == -1){
            return true;
        }
        return false;
    }
    double topo(){
        return(v[ult]);
    }
    void terminar(){
        delete[] v;
    }
    bool redimensionar(int tamanho_novo){
        double *w = new(nothrow)double[tamanho_novo];
        if(w==nullptr){
            return true;
        }
        for(int i=0; i<=ult;++i){
            w[i] = v[i];
        }
        delete[] v; v=w;
        tamanho = tamanho_novo;
        return false;
    }
    bool empilhar(int e){
        if(ult == tamanho){
            if(redimensionar(tamanho*2)){
                return true;
            }
        }
        ult +=1;
        v[ult] = e;
        return false;
    }
    bool desempilhar(){
        if(!vazia() && 4*(ult+1) <=tamanho){
            if(redimensionar(tamanho/2)){
                return true;
            }
        }
        ult -=1;
        return false;
    }
};

int main(){
    Pilha p;
    p.inicializar();
    cout<<"Digite 0 para parar e 1 para continuar, 2 para inserir e 3 para remover\n";
    int escolha =1;int escolha2;
    int e;
    while(escolha!=0){
        cout<<"Deseja inserir ou remover um elemento da pilha? [0/1]\n";
        cin>>escolha;
        cout<<"Deseja desempilhar ou empilhar? [3/2]\n";
        cin>>escolha2;
        if(escolha2 == 2){
            cout<<"Qual elemento deseja empilhar? \n";
            cin >> e;
            p.empilhar(e);
        }
        if(escolha2 ==3){
            cout << "Elemento desempilhado: " << p.topo() <<"\n";
            p.desempilhar();
        }
    }

}