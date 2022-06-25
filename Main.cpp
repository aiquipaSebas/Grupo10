#include <iostream>
#include "Controladora.hpp"
using namespace std;
int menu() {
	int opc;
	cout << "Menu" << endl;
	cout << "SI ERES ESPECIALISTA" << endl;
	cout << "1: Registrarte " << endl;
	cout << "2: Mostrar Especialistas registrados: " << endl;
	cout << "3: Editar Datos: " << endl;
	cout << "\n";
	cout << "SI ERES PACIENTE" << endl;
	cout << "4:Puntuar a un especialista" << endl;
	cout << "5: Foro: " << endl;
	cout << "6: Agregar Ticket: " << endl;
	cout << "7: Mostrar Tickets: " << endl;
	cout << "9: Salir: " << endl;
	cin >> opc;
	return opc;
}
void main() {
	srand(time(NULL));
	CControladora* controller = new CControladora();
	string texto;
	while (1) {
		system("cls");
		switch (menu()) {
		case 1:
			system("cls");
			cout << "Registrarte como Especialista: \n";
			controller->InsertarDatoS();
			break;
		case 2:
			system("cls");
			controller->MostrarDatos();
			system("pause");
			break;
		case 3:
			system("cls");
			controller->modificarPorIndice();
			system("pause");
			break;
		case 4:
			system("cls");
			controller->puntuarAunEspecialista();
			break;
		case 5:
			system("cls");
			controller->agregarComentarios();
			system("pause");
			break;
		case 6:
			system("cls");
			controller->agregarTickets();
			break;
		case 7:
			system("cls");
			controller->mostrarTickets();
			system("pause");
			break;
		case 9:
			exit(1);
		}
	}
	system("pause>>null");
}