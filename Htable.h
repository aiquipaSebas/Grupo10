#pragma once
#include <iostream>
using namespace std;

class CNodoHash {

private:
	int key;
	int valor;

public:
	CNodoHash(int _key, int _valor) {
		key = _key;
		valor = _valor;

	}
	int getKey() {

		return key;

	}

	int getValue() {

		return valor;

	}

	void MostrarDatos() {

		cout << "Key: " << key;

	}


};


class CTablaHash {


private:


	CNodoHash** tabla;
	int cantElementos;
	int tamanioTabla;


public:

	CTablaHash(int _tamaniotabla){
	
		tamanioTabla = _tamaniotabla;
		tabla = new CNodoHash * [tamanioTabla];

		for (int i = 0; i < tamanioTabla; i++)
		{
			tabla[i] = nullptr;
		}
	
		cantElementos = 0;
	}

	~CTablaHash() {

		for (int i = 0; i < tamanioTabla; i++)
		{
			if (tabla[i]!=nullptr)
			{
				delete tabla[i];
			}
		}
		delete tabla;
	}

	void insertarElemento(int key, int valor) {
		int base, step, hash;



		if (cantElementos == tamanioTabla)return;
		base = key % tamanioTabla;
		hash = base;
		step = 0;
		while (tabla[hash] != nullptr) {

			hash = (base + step) % tamanioTabla;

			step++;





		}

		tabla[hash] = new CNodoHash(key, valor);
		cantElementos++;


	}
	
	int tamTabla() {

		return tamanioTabla;

	}

	int tamActual() {

		return cantElementos;

	}


	int buscaElemento(int key) {

		int step = 0, hash, base;

		hash = base = key % tamanioTabla;

		while (true)
		{
			if (tabla[hash] == nullptr)return -0;
			else if (tabla[hash]->getKey() == key) {
				return hash;
			}
			step++;
			hash = (base + step) % tamanioTabla;
		}

	}

	int eliminarElemento(int key) {

		int step = 0, hash, base;

		hash = base = key % tamanioTabla;

		while (true)
		{
			if (tabla[hash] == nullptr) break;
			else if (tabla[hash]->getKey() == key) {
				delete tabla[hash];
				break;
			}
			step++;
			hash = (base + step) % tamanioTabla;
		}

	}


};

