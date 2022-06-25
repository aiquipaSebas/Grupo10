#pragma once
#include <iostream>
#include<string>
#include <functional>
using namespace std;
template<typename T>
struct NodoP {
    T dato;
    NodoP<T>* siguiente;
    NodoP(T n) {
        dato = n;
        siguiente = nullptr;
    }
};
template <typename T>
class Pila
{
private:
    NodoP<T>* pila;
public:
    Pila() {
        pila = nullptr;
    }
    ~Pila() {}

    void setPila(NodoP<T>* pila) {
        this->pila = pila;
    }
    NodoP<T>* getPila() {
        return pila;
    }

    void AgregarPila(T n) {
        NodoP<T>* nuevoNodo = new NodoP<T>(n);
        if (pila == nullptr)
            pila = nuevoNodo;
        else {
            nuevoNodo->siguiente = pila;
            pila = nuevoNodo;
        }
    }

    void EliminarPila() {
        NodoP<T>* aux = pila;
        T n = aux->dato;
        pila = aux->siguiente;
        delete aux;
    }

    void mostrar(function<void(T)>mostrar) {
        NodoP<T>* n = pila;
        while (n != nullptr) {
            mostrar(n->dato);
            n = n->siguiente;
        }
    }
};