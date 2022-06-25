
#include <iostream>
#include "Lista.hpp"
#include "Especialista.hpp"
#include "Cola.hpp"
#include "Pilas.hpp"
#include "Ticket.hpp"
#include "Htable.h"
#include <string>
#include <functional>
using namespace std;
class CControladora {
private:
	ListaDobleEnlazada<CEspecialista*>* L_es;
	Pila<string>* p;
	Cola<CTicket*>* c;
	CTablaHash* ht;


	int CodigoEspecialista;
	int CodigoTicket;
public:
	CControladora() {
		L_es = new ListaDobleEnlazada<CEspecialista*>();
		c = new Cola<CTicket*>();
		p = new Pila<string>();
		ht = new CTablaHash(1000000);
		CodigoEspecialista = 100;
		CodigoTicket = 1;
	}
	void InsertarDatoS() {
		string nombre;
		char ciudad, especialidad;
		int CodigoA = CodigoEspecialista;
		cout << "Escribe tu nombre: ";
		cin >> nombre;
		cout << "Escribe la ciudad donde trabajas: ";
		cin >> ciudad;
		cout << "Escribe tu especialidad: ";
		cin >> especialidad;
		L_es->insertarUltimo(new CEspecialista(nombre, ciudad, especialidad, rand() % 11, CodigoA));
		CodigoEspecialista++;
	}
	void MostrarDatos() {
		L_es->mostrarLista();
	}
	void modificarPorIndice() {
		int indice;
		string n;
		char c, e;
		cout << "Escribe el indice donde se encuentra los datos que desea modificar" << endl;
		cin >> indice;
		CEspecialista* aux = L_es->getPorIndice(indice);
		cout << "Escribe el nombre: ";
		cin >> n;
		aux->setNombre(n);
		cout << "Escribe la ciudad donde trabajas: ";
		cin >> c;
		aux->setCiudad(c);
		cout << "Escribe tu especialidad: ";
		cin >> e;
		aux->setEspecialidad(e);
	}
	void puntuarAunEspecialista() {
		int indice;
		float rankA, p;
		cout << "Escribe el indice donde se encuentra los datos que desea modificar" << endl;
		cin >> indice;
		cout << "Escribe La puntuacion que le das al especialista: " << endl;
		cin >> p;
		CEspecialista* aux = L_es->getPorIndice(indice);
		rankA = aux->getrank();
		auto promedio = [](float a, float b) {return ((a + b / 2) * 1.0); };
		aux->setRanking(promedio(rankA, p));
	}
	void agregarComentarios() {
		cout << "Foro: " << endl;
		string texto;
		cout << "Texto: "; getline(cin, texto);
		p->AgregarPila(texto);
		p->mostrar([](string n) {cout << n << endl; });
	}
	void agregarTickets() {
		int indice;
		string infEsp, nombre, dni, dia, hora;
		cout << "Escribe el indice del especialista: ";
		cin >> indice;
		CEspecialista* aux = L_es->getPorIndice(indice);
		infEsp = aux->toString();
		cout << "Escribre tu nombre" << endl;
		cin >> nombre;
		cout << "Escribre tu DNI" << endl;
		cin >> dni;
		cout << "Escribre la dia de la cita" << endl;
		cin >> dia;
		cout << "Escribre la hora de la cita" << endl;
		cin >> hora;
		c->AgregaDato(new CTicket(infEsp, nombre, dni, dia, hora));
		CodigoTicket++;
	}
	void mostrarTickets() {
		cout << "Tickets: " << endl;
		c->mostrar();
		cout << "\n";
	};

	void mostrarCita() {




	}





};