#pragma once
#pragma
#include <iostream>
using namespace std;

template <typename T>
class NodoL {
public:
    T dato;
    NodoL<T>* anterior;
    NodoL<T>* siguiente;
    NodoL(T dato, NodoL<T>* siguiente = nullptr, NodoL<T>* anterior = nullptr) {
        this->dato = dato;
        this->siguiente = siguiente;
        this->anterior = anterior;
    }
    T getDato() { return dato; }
};

template <typename T>
class ListaDobleEnlazada {
    int tam;
    NodoL<T>* primero;
    NodoL<T>* ultimo;
public:

    ListaDobleEnlazada() {
        primero = nullptr;
        ultimo = nullptr;
        tam = 0;
    }
    ~ListaDobleEnlazada() {}
    void insertarInicio(T v) {
        NodoL<T>* nuevo = new NodoL<T>(v);

        if (primero == NULL) {
            primero = nuevo;
            ultimo = nuevo;
        }
        else {
            primero->anterior = nuevo;
            nuevo->siguiente = primero;
        }
        primero = nuevo;
        tam++;
    }
    void insertarUltimo(T v) {
        NodoL<T>* nuevo = new NodoL<T>(v);

        if (primero == NULL) {
            primero = nuevo;
            ultimo = nuevo;
        }
        else {
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
        }
        ultimo = nuevo;
        tam++;
    }
    /*void insertarPorRank(T v) {
        Nodo<T>* nuevo = new Nodo<T>(v);
        Nodo<T>* aux1 = primero;
        for (i = 0; i < tam; i++) {
            pos = i;
        }
    }*/
    void eliminarInicio() {
        if (tam == 0) return;
        if (tamm == 1) {
            delete primero;
            primero = nullptr;
            ultimo = nullptr;
        }
        if (tam > 1) {
            NodoL<T>* aux = primero->siguiente;
            delete primero;
            primero = aux;
            primero->anterior = nullptr;

        }
        tam--;
    }
    void eliminarUltimo() {
        if (tam == 0) return;
        if (tamm == 1) {
            delete primero;
            primero = nullptr;
            ultimo = nullptr;
        }
        if (tam > 1) {
            NodoL<T>* aux = ultimo->anterior;
            delete ultimo;
            ultimo = aux;
            ultimo->siguiente = nullptr;

        }
        tam--;
    }
    void mostrarLista() {
        NodoL<T>* nodo = primero;
        cout << "Doctores " << endl;
        do {
            CEspecialista* D_esp = (CEspecialista*)(nodo->dato);
            cout << D_esp->toString();
            nodo = nodo->siguiente;
            cout << "\n";
        } while (nodo != NULL);
        cout << endl;
    }
    /*void mostrarIndice(int indice) {
        Nodo<T>* aux = primero;
        for (int i = 0; i < indice; i++) {
            aux = aux->siguiente;
        }
        cout << "Especialista en el indice "<< indice <<": " << endl;
        CEspecialista* D_esp = (CEspecialista*)(aux->dato);
        cout << D_esp->toString();
        cout << endl;
    }*/
    //Geters
    T getPorIndice(int indice) {
        NodoL<T>* aux = primero;
        for (int i = 0; i < indice; i++) {
            aux = aux->siguiente;
        }
        cout << "Especialista en el indice " << indice << ": " << endl;
        return aux->dato;
    }
    T getPrimero() { return primero->dato; }
    T getUltimo() { return ultimo->dato; }
    T getNodo() {
        return
    }
};
