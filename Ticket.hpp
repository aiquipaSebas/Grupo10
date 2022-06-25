#pragma once
#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class CTicket {
private:
	string infEsp;
	string nombrePac;
	string dniPac;
	string dia;
	string hora;
public:
	CTicket(string infEsp, string nombrePac, string dniPac, string dia, string hora) : infEsp(infEsp), nombrePac(nombrePac), dniPac(dniPac), dia(dia), hora(hora) {}
	~CTicket() {};
	string toString() {
		ostringstream  d;
		d << "============================";
		d << "Especialista: ";
		d << infEsp << "\n";
		d << endl;
		d << "Nombre: ";
		d << nombrePac;
		d << endl;
		d << "DNI del paciente";
		d << dniPac;
		d << endl;
		d << "Dia: ";
		d << dia;
		d << endl;
		d << "Hora: ";
		d << hora;
		d << endl;
		d << "============================";
		return(d.str());
	}

};