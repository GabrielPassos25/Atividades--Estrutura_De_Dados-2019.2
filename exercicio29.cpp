#include <iostream>
#include <new>
using namespace std;
//EXERCICIO 1;
int PesquisaBinaria (int* v,int i, int f,int e){
    while(i<=f){
        int decisao = (i+f)/2;
        if(v[decisao] == e){
            return decisao;
        }
        else if(v[decisao] < e){
            i = decisao+1;
        }
        else{
            f = decisao-1;
        }
    }
    return -1;
}
int main(){
    int vector[11] = {0,1,2,3,4,5,6,7,8,9,35};
    cout << PesquisaBinaria(&vector[0],0,10,35) << "\n";
}

//EXERCÍCIO 2;
struct DicionarioDados{
    int elementos=0;
    struct Dicionario{ 
        int chave;
        int dado;
    };
    Dicionario* vetor;
    int inicializar_dicionario(int tam){
        Dicionario* Vector = new(nothrow)Dicionario[tam];
        vetor = Vector;
    }
    int inserir(int chave, int dado){
        int i =0;
        int aux = elementos;
        while(vetor[i].chave != 0){
            if(chave < vetor[i].chave){
                while(aux!=i){
                    vetor[aux] = vetor[aux-1];
                    aux-=1;
                }
                break;
            }
            i +=1;
        }
        vetor[i].chave = chave;
        vetor[i].dado = dado;
        elementos +=1;
    }
    bool remover(int chave){
        for(int i=0;i<elementos;i+=1){
            if(vetor[i].chave == chave){
                int j =i;
                while(vetor[j].chave != 0){
                    vetor[j].chave = vetor[j+1].chave;
                    j+=1;
                }
                return false;
            }
        }
        return true;
    }
    void print(){
        cout << '[';
        for(int i=0; i<elementos;i+=1){
            cout << vetor[i].chave << " ";
        }
        cout << ']' << "\n";
    }
    bool procurar(int chave){
        for(int i=0;i<elementos;i+=1){
            if(vetor[i].chave == chave){
                return false;
            }
        }
        return true;
    }
};
// int main(){
//     DicionarioDados d;
//     d.inicializar_dicionario(10);
//     d.inserir(2,3);
//     d.print();
//     cout << "\n";
//     d.inserir(3,2);
//     d.print();
//     cout << "\n";
//     d.inserir(1,4);
//     d.print();
//     cout << "\n";
//     d.remover(1 );
//     d.print();
//     cout << "\n";
//     cout << d.procurar(4) << "\n";
//     cout << d.procurar(2) << "\n";
// }
