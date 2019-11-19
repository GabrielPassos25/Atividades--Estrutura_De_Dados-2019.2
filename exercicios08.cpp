//ENUNCIADO
// Utilizando as estratégias de expansão e contração eficientes de vetores
// discutidas na aula de hoje, escreva um programa em C++ que implemente essas
// ideias. Mais especificamente, o programa deve manter um vetor de números,
// e, em cada momento, o usuário deve ter a possibilidade de inserir um novo
// número ou remover o último número do vetor. Naturalmente, você deve utilizar
// as estratégias eficientes que aprendemos para quando o vetor fica sem espaço
// para um novo número, e para quando ele fica muito pouco povoado após uma
// remoção. Além das opções de inserção e remoção, o programa deve fornecer ao
// usuário a opção de sair. Após cada operação realizada, o programa deve
// imprimir para o usuário os números correntemente armazenados.
// OBSERVAÇÃO: nesta questão, você deve implementar as estratégias do pontos
// 2 e 4 da aula de hoje, ou seja, as estratégias de redimensionamento nas quais
// todas as cópias acontecem de uma vez por ocasião de uma expansão ou contração
// , ao invés de acontecerem de forma "diluída" durante as sucessivas inserções
// e remoções.
#include <iostream>
#include <new>
using namespace std;
struct Vetor{
    int* v;
    int inicio,fim, elementos, tamanho;
    bool inicializar(){
        v = new(nothrow)int[1];
        if(v==nullptr)return true;
        fim =-1;elementos=0,tamanho =1;
        return false;
    }
    bool redimensionar(int tam_n,int tam_a){
        int *w = new(nothrow)int[tam_n];
        if(w==nullptr){
            return true;
        }
        for(int i=0;i<tam_a;++i){
            w[i] = v[i];
        }
        delete[] v; v=w; tamanho = tam_n;
        return false;
    }
    bool inserir_elemento(int e){
        fim +=1;
        if(fim >=tamanho){
            if(redimensionar(tamanho*2,tamanho)){
                return true;
            }
        }
        v[fim]=e;
        elementos +=1;
        return false;
    }
    bool remover_elemento(){
        if(4*elementos<=tamanho && elementos!=0){
            if(redimensionar(tamanho/2,tamanho)){
                return true;
            }
        }
        v[fim] =0;
        fim -=1;
        elementos -=1;
        return false;
    }
    void terminar(){
        delete[] v;
    }
    void printar_vetor(){
        cout<<"Vetor: [";
        for(int i =0;i<tamanho;++i){
            cout<<v[i]<<" ";
        }
        cout<<"]\n";
    }
};

int main(){
    Vetor v;
    v.inicializar();
    cout<<"Digite 0 para parar e 1 para continuar, 2 para inserir e 3 para remover\n";
    int escolha =1;int escolha2;
    int e;
    v.printar_vetor();
    while(escolha!=0){
        cout<<"Deseja inserir ou remover um elemento no vetor? [0/1]\n";
        cin>>escolha;
        cout<<"Deseja remover ou inserir? [3/2]\n";
        cin>>escolha2;
        if(escolha2 == 2){
            cout<<"Qual elemento deseja inserir? \n";
            cin >> e;
            v.inserir_elemento(e);
            v.printar_vetor();
        }
        if(escolha2 ==3){
            v.remover_elemento();
            v.printar_vetor();
        }
    }
}