//ENUNCIADO QUESTÃO 2:
// Assim como uma pilha, uma FILA é um contêiner, em que podem ser inseridos e
// removidos elementos; entretanto, enquanto a operação de remoção de uma pilha
// retira o ÚLTIMO elemento inserido, a remoção de uma fila retira o PRIMEIRO
// elemento inserido (dentre aqueles ainda presentes na estrutura). O TAD Fila
// pode, portanto, ser definido como possuindo as seguintes operações básicas:
// 1. inicializar(F): inicializa F como uma fila vazia.
// 2. enfilar(F,e): insere em F o elemento "e" (que se torna o último de F).
// 3. ultimo(F): retorna, sem remover, o último elemento da fila F.
// 4. vazia(F): informa se a fila F está vazia ou não.
// 5. desenfilar(F): remove da fila F seu primeiro elemento.
// 6. terminar(F): "destrói" F (na prática, libera os recursos usados por F).
// 7. primeiro(F): retorna, sem remover, o primeiro elemento da fila F.
// Assim sendo, pense em como uma fila pode ser eficientemente representada por
// meio de um vetor. Especificamente, procure conceber uma representação que
// garanta que:
// 1. Toda inserção ou remoção exija no máximo um número constante de
// operações (isto é, um número "fixo" de operações, que não dependa nem do
// número de elementos armazenados na fila e nem do tamanho do vetor
// utilizado), exceto em caso de redimensionamento do vetor.
// 2. Redimensionamentos só serão realizados quando realmente necessário, isto
// é, no caso de uma inserção, quando o vetor já estiver cheio antes da
// inserção, e, no caso de uma remoção, quando, após a remoção, o vetor
// ficar no máximo 25% ocupado.
#include <iostream>
#include <new>
using namespace std;
struct Fila{
    double *v; int inicio, fim, tamanho, elementos;
    bool inicializar(){
        v = new(nothrow)double[1];
        if(v==nullptr){
            return true;
        }
        inicio = 0;
        fim = -1;
        tamanho =1;
        elementos =0;
        return false;
    }
    bool redimensionar(int tamanho_novo){
        double *w = new(nothrow)double[tamanho_novo];
        if(w == nullptr){
            return true;
        }
        for(int i=0; i<elementos;++i){
            w[i] = v[inicio+i];
        }
        inicio =0;fim=elementos-1;
        delete[] v; v=w;
        tamanho = tamanho_novo;
        return false;
    }
    bool enfilar(double e){
        if(fim==tamanho-1){
            if(redimensionar(tamanho*2)){
                return true;
            }
        }
        fim +=1;
        v[fim]=e;
        elementos +=1;
        return false;
    }
    bool desenfilar(){
        if(!vazia() && 4*elementos<=tamanho){
            if(redimensionar(tamanho/2)){
                return true;
            }
        }
        inicio +=1;
        elementos -=1;
        return false;
    }
    double ultimo(){
        return(v[fim]);
    }
    double primeiro(){
        return(v[inicio]);
    }
    bool vazia(){
        if(fim ==-1){
            return true;
        }
        return false;
    }
    void terminar(){
        delete[] v;
    }
    void print(){
        cout<<"Vetor: [";
        for(int i=inicio; i<=fim;i+=1){
            cout << v[i] << ", ";
        }
        cout << "]\n";
    }
};

int main(){
    Fila p;
    p.inicializar();
    cout<<"Digite 0 para parar e 1 para continuar, 2 para inserir e 3 para remover\n";
    int escolha =1;int escolha2;
    double e;
    while(escolha!=0){
        cout<<"Deseja inserir ou remover um elemento da fila? [0/1]\n";
        cin>>escolha;
        cout<<"Deseja desenfilar ou enfilar? [3/2]\n";
        cin>>escolha2;
        if(escolha2 == 2){
            cout<<"Qual elemento deseja enfilar?\n";
            cin >> e;
            p.enfilar(e);
            p.print();
        }
        if(escolha2 ==3){
            cout << "Elemento desenfilado: " << p.primeiro() <<"\n";
            p.desenfilar();
            p.print();
        }
    }

}
