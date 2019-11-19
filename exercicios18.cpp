#ifndef CONJUNTO_HPP
#define CONJUNTO_HPP
#include <iostream>
#include <new>
using namespace std;

template <typename T>
struct Conjunto {
    struct Noh {
        T elem;
        Noh *ant, *prox;
    };

    Noh sentinel;

    void inicializar() { sentinel.ant = sentinel.prox = &sentinel; }

    bool vazio() { return (sentinel.ant == &sentinel); }

    struct Iterator {
        Noh *p;
        bool operator!=(Iterator j) { return p != j.p; }
        bool operator==(Iterator j) { return p == j.p; }
        T operator*() { return p->elem; }
        void operator++() { p = p->prox; }
    };

    Iterator fim() {
        Iterator i;
        i.p = &sentinel;
        return i;
    }

    Iterator inicio() {
        Iterator i;
        i.p = sentinel.prox;
        return i;
    }

    Iterator inserir(T e) {
        Noh *n = new(nothrow) Noh;
        if (n == nullptr) return fim();
        n->elem = e; n->ant = &sentinel; n->prox = sentinel.prox;
        sentinel.prox = n;
        n->prox->ant = n;
        Iterator i;
        i.p = n;
        return i;
    }

    void remover(Iterator i) {
        Noh *n = i.p;
        n->ant->prox = n->prox;
        n->prox->ant = n->ant;
        delete n;
    }

    Iterator procurar(T e) {
        Noh *look = sentinel.prox;
        while (look != &sentinel) {
            if (look->elem == e) {
                Iterator i;
                i.p = look;
                return i;
            }
            look = look->prox;
        }
        return fim();
    }

    bool pertence(T e) {
        if (procurar(e) == fim()) return false;
        return true;
    }

    void terminar() {
        T remove;
        Iterator i;
        while (!vazio()) {
            remove = (sentinel.prox)->elem;
            i = procurar(remove);
            remover(i);
        }
    }
};


#endif
int main(){
    Conjunto<double> C;
    C.inicializar();
    double num; int i;
    auto end = C.fim();
    do {
        cout << "\nOperações: (1) inserir, (2) remover, (3) procurar, (4) parar: " ; cin >> i; cout << '\n';
        switch (i) {
            case 1: {
                cout << "Insira o número a ser inserido: "; cin >> num;
                if (C.pertence(num)) cout << "Erro! Número pertence ao conjunto \n";
                else if (C.inserir(num) != end) cout << "Número inserido\n";
                else cout << "Erro de alocação. \n";
            } break;

            case 2: {
                if (C.vazio()) cout << "ERRO! Conjunto vazio!\n";
                else {
                    cout << "Insira o número a ser retirado: "; cin >> num;
                    auto remove = C.procurar(num);
                    if (!C.pertence(num)) cout << "Erro! Número não pertence ao conjunto \n";
                    else {
                        (C.remover(remove));
                        cout << "Número removido\n";
                    }
                }
            } break;

            case 3: {
                if (C.vazio()) cout << "ERRO! Conjunto vazio!\n";
                cout << "Insira o número a ser procurado: "; cin >> num;
                auto look = C.procurar(num);
                if (look == end) cout << "Não pertence ao conjunto\n";
                else cout << "Pertence ao conjunto\n";
            } break;
        }
    } while (i != 4);
    C.terminar();   
    
}