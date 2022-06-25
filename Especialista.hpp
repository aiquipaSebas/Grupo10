#pragma once
#pragma
#include <iostream>
#include <sstream>
using namespace std;

class CEspecialista {
private:
	string nombre;
	char especialidad;
	char ciudad;
	float rank;
	int codigo;
public:
	CEspecialista(string nombre, char especialidad, char ciudad, float rank, int codigo) :nombre(nombre), especialidad(especialidad), ciudad(ciudad), rank(rank), codigo(codigo) {};
	~CEspecialista() {};
	string toString() {
		ostringstream  d;
		d << "Codigo: ";
		d << codigo;
		d << endl;
		d << "Nombre: ";
		d << nombre;
		d << endl;
		d << "Especialidad: ";
		d << especialidad;
		d << endl;
		d << "Ciudad: ";
		d << ciudad;
		d << endl;
		d << "Ranking: ";
		d << rank;
		d << endl;
		return(d.str());
	}
	int getCodigo() { return codigo; }
	int getrank() { return rank; }
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
	void setEspecialidad(char especialidad) {
		this->especialidad = especialidad;
	}
	void setCiudad(char ciudad) {
		this->ciudad = ciudad;
	}
	void setRanking(float rank) {
		this->rank = rank;
	}
};