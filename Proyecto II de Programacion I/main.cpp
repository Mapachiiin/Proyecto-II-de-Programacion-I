#include <iostream>
#include "Control.h"
#include "Fecha.h"
#include "Quemados.h"

using namespace std;

int main() {
    Fecha::inicializarFechaGlobal();

	Control* menu = new Control();
	Quemados* quemar= new Quemados(menu);

	quemar->quemarDatos();
	system("cls");
	cout << "Al igual que el primer proyecto, las unicas sucursales con datos quemados es la #1 y #2 para poder probar todas las funcionalidades basicas, gracias!";
	cin.get();
	menu->menuPrincipal();
	Fecha::liberarFechaGlobal();

	delete quemar;
	delete menu;
	return 0;
}