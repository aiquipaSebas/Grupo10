#pragma once
#pragma once
#include <iostream>
#include<string>
#include <functional>
using namespace std;
template<typename T>
struct NodoC {
    T nodo;
    NodoC<T>* siguiente;
    NodoC(T n) {
        nodo = n;
        siguiente = nullptr;
    }

};
template <typename T>
class Cola
{
private:
    NodoC<T>* inicio;
    NodoC<T>* fin;
public:
    Cola() {
        inicio = fin = nullptr;
    }
    ~Cola() { }

    void setInicio(NodoC<T>* inicio) {
        this->inicio = inicio;
    }
    NodoC<T>* getInicio() {
        return inicio;
    }
    void setFin(NodoC<T>* fin) {
        this->fin = fin;
    }
    NodoC<T>* getFin() {
        return fin;
    }

    void AgregaDato(T n) {
        NodoC<T>* nuevoNodo = new NodoC<T>(n);
        if (inicio == nullptr)
            inicio = nuevoNodo;
        else {
            fin->siguiente = nuevoNodo;
        }
        fin = nuevoNodo;
    }

    void EliminarDato() {
        T n = inicio->nodo;
        if (inicio == fin)
            inicio = fin = nullptr;
        else
            inicio = inicio->siguiente;
    }

    void mostrar() {
        NodoC<T>* n = inicio;
        while (n != nullptr) {
            CTicket* D_Ticket = (CTicket*)(n->nodo);
            cout << D_Ticket->toString();
            n = n->siguiente;
            cout << "\n";
        }
    }

};

