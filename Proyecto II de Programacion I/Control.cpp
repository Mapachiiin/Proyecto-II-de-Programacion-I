#include "Control.h"
#include <ctime>

static int numeroSucursales = 1;
static Fecha* fechaActual = Fecha::obtenerFechaActualPtr();


Control::Control() {
	listaSucursales = new ListaSucursales();
}
Control::~Control() {
	delete listaSucursales;
}
void Control::agregarSucursal() {
	Sucursal* nuevaSucursal = new Sucursal(numeroSucursales);
	numeroSucursales++;
	listaSucursales->agregarSucursal(nuevaSucursal);
}
bool Control::eliminarSucursal(int numSucursal) {
	if (listaSucursales->eliminarSucursal(numSucursal)) {
		numeroSucursales--;
		return true;
	}
	return false;
}
void Control::mostrarSucursales() {
	listaSucursales->mostrarSucursales();
}
//menus y sub menus
void Control::menuPrincipal() {
	int respuesta = 0;
	do {
		system("cls");
		cout << " Bienvenido al Sistema D.R.T " << endl;
		cout << "     " << fechaActual->toString() << endl << endl;
		cout << "-----Menu Principal-----" << endl << endl;
		cout << "1. Agregar Sucursal" << endl;
		cout << "2. Eliminar Sucursal" << endl;
		cout << "3. Mostrar Sucursales" << endl;
		cout << "4. Gestionar Sucursales" << endl;
		cout << "5. Cerrar programa" << endl << endl;
		cout << "Ingrese una opcion: ";
		cin >> respuesta;
		cin.ignore(10000, '\n');

		switch (respuesta) {
		case 1: {
			system("cls");
			cout << " Agregar Sucursal " << endl << endl;
			agregarSucursal();
			cout << "Sucursal #" << (numeroSucursales - 1) << " agregada exitosamente." << endl;
			cout << endl << "Aprete enter para volver al menu principal" << endl;
			cin.get();
			break;
		}
		case 2: {
			if (numeroSucursales == 0) {
				system("cls");
				cout << "No hay sucursales para eliminar. Agregue una sucursal primero." << endl;
				cout << endl << "Aprete enter para volver al menu principal" << endl;
				cin.get();
				break;
			}

			system("cls");
			cout << " Eliminar Sucursal " << endl << endl;
			mostrarSucursales();

			int nSuc;
			while (true) {
				cout << endl << "Ingrese el numero de la sucursal a eliminar (o 0 para cancelar): ";
				cin >> nSuc;
				cin.ignore(10000, '\n');

				if (nSuc == 0) {
					cout << "Operacion cancelada." << endl;
					cout << endl << "Aprete enter para volver al menu principal" << endl;
					cin.get();
					break;
				}

				if (nSuc < 0 || nSuc >= numeroSucursales) {
					cout << "Numero de sucursal invalido. Intente de nuevo." << endl;
					continue;
				}
				char conf;
				while (true) {
					cout << "Esta seguro que desea eliminar la sucursal #" << nSuc << "? (s/n): ";
					cin >> conf;
					cin.ignore(10000, '\n');

					if (conf == 's' || conf == 'S') {
						if (eliminarSucursal(nSuc)) {
							cout << endl << "Sucursal #" << nSuc << " eliminada exitosamente." << endl;
						}
						else {
							cout << endl << "Error: No se pudo eliminar la sucursal #" << nSuc << "." << endl;
						}
						cout << endl << "Aprete enter para volver al menu principal" << endl;
						cin.get();
						break;
					}
					else if (conf == 'n' || conf == 'N') {
						cout << "Eliminacion cancelada." << endl;
						cout << endl << "Aprete enter para volver al menu principal" << endl;
						cin.get();
						break;
					}
					else {
						cout << "Opcion invalida. Intente de nuevo." << endl;
					}
				}
				break;
			}
			break;
		}
		case 3: {
			if (numeroSucursales == 0) {
				system("cls");
				cout << "No hay sucursales registradas. Agregue una sucursal primero." << endl;
				cout << endl << "Aprete enter para volver al menu principal" << endl;
				cin.get();
				break;
			}
			system("cls");
			cout << " Sucursales Registradas " << endl << endl;
			mostrarSucursales();
			cout << endl << "Aprete enter para volver al menu principal" << endl;
			cin.get();
			break;
		}
		case 4: {
			if (numeroSucursales == 0) {
				system("cls");
				cout << "No hay sucursales para gestionar. Agregue una sucursal primero." << endl;
				cout << endl << "Aprete enter para volver al menu principal" << endl;
				cin.get();
				break;
			}
			bool volverMenuPrincipal = false;
			while (!volverMenuPrincipal) {
				system("cls");
				cout << " Gestionar Sucursales " << endl << endl;
				mostrarSucursales();
				int numSucursal;
				while (true) {
					cout << endl << "Ingrese el numero de la sucursal a gestionar (o 'n' para volver): ";
					string entrada;
					cin >> entrada;
					cin.ignore(10000, '\n');
					if (entrada == "n" || entrada == "N") {
						volverMenuPrincipal = true;
						break;
					}
					try {
						numSucursal = stoi(entrada);
					}
					catch (...) {
						cout << "Entrada invalida. Intente de nuevo." << endl;
						continue;
					}
					if (numSucursal < 0 || numSucursal >= numeroSucursales) {
						cout << "Numero de sucursal invalido. Intente de nuevo." << endl;
						continue;
					}
					subMenuSucursales(numSucursal);
					volverMenuPrincipal = true;
					break;
				}
			}
			break;
		}
		case 5: {
			system("cls");
			char conf;
			while (true) {
				cout << "Esta seguro que desea cerrar el programa? (s/n): ";
				cin >> conf;
				cin.ignore(10000, '\n');

				if (conf == 's' || conf == 'S') {
					cout << endl << "Cerrando el sistema D.R.T..." << endl;
					cout << "Gracias por usar el sistema D.R.T. Hasta luego!" << endl;
					return;
				}
				else if (conf == 'n' || conf == 'N') {
					break;
				}
				else {
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			}
			break;
		}
		default: {
			system("cls");
			cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
			cout << endl << "Aprete enter para continuar" << endl;
			cin.get();
			continue;
		}
		}
	} while (respuesta != 5);
}
void Control::subMenuSucursales(int numSucursal) {
	int respuesta = 0;
	Sucursal* sGestionar = listaSucursales->obtenerSucursal(numSucursal);
	if(!sGestionar) {
		cout << "Sucursal no encontrada." << endl;
		return;
	}
	do {
		system("cls");
		cout << "-----Submenu de Sucursal " << numSucursal << " -----" << endl << endl;
		cout << "1. Gestionar Colaboradores" << endl;
		cout << "2. Gestionar Clientes" << endl;
		cout << "3. Gestionar Vehiculos y Planteles" << endl;
		cout << "4. Gestionar Solicitudes y Contratos" << endl;
		cout << "5. Volver al Menu Principal" << endl;
		cout << "Ingrese una opcion: ";
		cin >> respuesta;
		switch (respuesta) {
		case 1:
			subMenuColaboradores(sGestionar);
			break;
		case 2:
			subMenuClientes(sGestionar);
			break;
		case 3:
			subMenuVehiculosyPlanteles(sGestionar);
			break;
		case 4:
			subMenuSolicitudesYContratos(sGestionar);
			break;
		case 5:
			return;
		default:
			cout << "Opcion invalida. Por favor, intente de nuevo." << endl << endl;
			cin.ignore(10000, '\n');
			continue;
		}
	} while (respuesta != 5);
	return;
}
void Control::subMenuColaboradores(Sucursal* s) {
	if (!s) return;
	int respuesta = 0;
	do {
		system("cls");
		cout << "-----Submenu de Colaboradores-----" << endl << endl;
		cout << "1. Agregar Colaborador a la sucursal" << endl;
		cout << "2. Eliminar Colaborador de la sucursal" << endl;
		cout << "3. Mostrar Colaboradores de la sucursal" << endl;
		cout << "4. Reporte de alquileres y contratos realizados por colaborador" << endl;
		cout << "5. Volver al Submenu de Sucursales" << endl;
		cout << "Ingrese una opcion: ";
		cin >> respuesta;
		cin.ignore(10000, '\n');

		switch (respuesta)
		{
		case 1: {
			system("cls");
			bool seguir = true;
			while (seguir) {
				string cedula, nombre;
				cout << "Agregar Colaborador a la sucursal" << endl << endl;
				while (true) {
					cout << "Ingrese el numero de cedula del nuevo colaborador: ";
					cin >> cedula;
					cin.ignore(10000, '\n');
					if (cedula.empty()) {
						cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
						continue;
					}
					bool tieneEspacio = false;
					for (char c : cedula) {
						if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
							tieneEspacio = true;
							break;
						}
					}
					if (tieneEspacio) {
						cout << "La cedula no puede contener espacios. Intente de nuevo." << endl;
						continue;
					}
					if (s->getColaboradores()->buscarColaboradorPorCed(cedula) != nullptr) {
						cout << "El colaborador ya existe. Intente de nuevo." << endl;
						continue;
					}
					break;
				}
				while (true) {
					cout << "Ingrese el nombre del nuevo colaborador: ";
					getline(cin, nombre);
					if (nombre.empty()) {
						cout << "El nombre no puede estar vacio. Intente de nuevo." << endl;
						continue;
					}
					break;
				}
				s->agregarColaborador(new Colaborador(cedula, nombre, fechaActual->clonar()));
				cout <<endl<< "Colaborador agregado exitosamente." << endl;
				char op;
				while (true) {
					cout <<endl<< "Desea agregar otro colaborador? (s/n): ";
					cin >> op;
					cin.ignore(10000, '\n');
					if (op == 's' || op == 'S') {
						break;
					}
					else if (op == 'n' || op == 'N') {
						seguir = false;
						break;
					}
					else {
						cout << "Opcion invalida. Intente de nuevo." << endl;
					}
				}
			}
			cout << "Aprete enter para volver al submenu de colaboradores" << endl;
			cin.get();
			break;
		}
		case 2: { 
			if(s->getColaboradores()->getTam() == 0) {
				system("cls");
				cout << "No hay colaboradores para eliminar." << endl;
				cout << "Aprete enter para volver al submenu de colaboradores" << endl;
				cin.get();
				break;
			}
			system("cls");
			bool seguir = true;
			while (seguir) {
				string cedula;
				s->getColaboradores()->mostrarColaboradores();
				while (true) {
					cout << endl << "Ingrese la cedula del colaborador a eliminar (o 'n' para salir): ";
					cin >> cedula;
					cin.ignore(10000, '\n');
					if (cedula == "N" || cedula == "n") { seguir = false; break; }
					if (cedula.empty()) {
						cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
						continue;
					}
					if (!s->getColaboradores()->buscarColaboradorPorCed(cedula)) {
						cout << "El colaborador no existe. Intente de nuevo." << endl;
						continue;
					}
					break;
				}
				if (!seguir) break;
				char conf;
				while (true) {
					cout << "Confirma eliminar al colaborador con cedula " << cedula << " ? (s/n): ";
					cin >> conf;
					cin.ignore(10000, '\n');
					if (conf == 's' || conf == 'S') break;
					if (conf == 'n' || conf == 'N') { cout << "Eliminacion cancelada." << endl; break; }
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			    if (conf == 'n' || conf == 'N') {
					char op;
					while (true) {
						cout << "Desea intentar eliminar otro colaborador? (s/n): ";
						cin >> op;
						cin.ignore(10000, '\n');
						if (op == 's' || op == 'S') break;
						if (op == 'n' || op == 'N') { seguir = false; break; }
						cout << "Opcion invalida. Intente de nuevo." << endl;
					}
					continue;
				}
				s->eliminarColaborador(cedula);
				cout << "Colaborador eliminado exitosamente." << endl;

				char op;
				while (true) {
					cout << "Desea eliminar otro colaborador? (s/n): ";
					cin >> op;
					cin.ignore(10000, '\n');
					if (op == 's' || op == 'S') break;
					if (op == 'n' || op == 'N') { seguir = false; break; }
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			}
			cout << "Aprete enter para volver al submenu de colaboradores" << endl;
			cin.get();
			break;
		}
		case 3: {
			if(s->getColaboradores()->getTam() == 0) {
				system("cls");
				cout << "No hay colaboradores para mostrar." << endl;
				cout << "Aprete enter para volver al submenu de colaboradores" << endl;
				cin.get();
				break;
			}
			system("cls");
			cout << " Colaboradores de la sucursal " << s->getNumSucursal() << endl << endl;
			s->getColaboradores()->mostrarColaboradores();
			cout << "Aprete enter para volver al submenu de colaboradores" << endl;
			cin.clear();
			cin.get();
			break;
		}
		case 4: {
			if (s->getColaboradores()->getTam() == 0) {
				system("cls");
				cout << "No hay colaboradores para mostrar reportes." << endl;
				cout << "Aprete enter para volver al submenu de colaboradores" << endl;
				cin.get();
				break;
			}
			bool seguir = true;
			while (seguir) {
				system("cls");
				string cedula;
				s->getColaboradores()->mostrarColaboradores();

				cout << endl << "Ingrese la cedula del colaborador para ver su historial (o 'n' para salir): ";
				getline(cin, cedula);
				if (cedula == "n" || cedula == "N") break;
				if (cedula.empty()) {
					cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
					continue;
				}
				bool tieneEspacio = false;
				for (char c : cedula) {
					if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
						tieneEspacio = true;
						break;
					}
				}
				if (tieneEspacio) {
					cout << "La cedula no puede contener espacios. Intente de nuevo." << endl;
					continue;
				}
				if (!s->getColaboradores()->buscarColaboradorPorCed(cedula)) {
					cout << "El colaborador no existe. Intente de nuevo." << endl;
					continue;
				}
				s->getSolicitudes()->reportesAlquilerPorColaborador(cedula);
				char opcionDetalle;
				while (true) {
					cout << endl << "Desea ver detalladamente alguna solicitud o contrato realizado por este colaborador? (s/n): ";
					cin >> opcionDetalle;
					cin.ignore(10000, '\n');
					if (opcionDetalle == 's' || opcionDetalle == 'S') {
						string codigo;
						while (true) {
							cout << "Ingrese el codigo de la solicitud o contrato (o 'q' para cancelar): ";
							cin >> codigo;
							cin.ignore(10000, '\n');
							if (codigo == "q" || codigo == "Q") break;
							if (codigo.empty()) {
								cout << "El codigo no puede estar vacio. Intente de nuevo." << endl;
								continue;
							}
							system("cls");
							s->getSolicitudes()->mostrarSolicitudEspecifica(codigo);
							break;
						}
						break;
					}
					else if (opcionDetalle == 'n' || opcionDetalle == 'N') {
						break;
					}
					else {
						cout << "Opcion invalida. Intente de nuevo." << endl;
					}
				}
				char opcionOtro;
				while (true) {
					cout << endl << "Desea ver los contratos de otro colaborador? (s/n): ";
					cin >> opcionOtro;
					cin.ignore(10000, '\n');
					if (opcionOtro == 's' || opcionOtro == 'S') break;
					if (opcionOtro == 'n' || opcionOtro == 'N') { seguir = false; break; }
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			}
			cout << "Aprete enter para volver al submenu de colaboradores" << endl;
			cin.get();
			break;
		}
		case 5: {
			return;
		}
		default: {
			cout << "Opcion invalida. Por favor, intente de nuevo." << endl << endl;
			break;
		}
		}
	} while (respuesta != 5);
	return;
}
void Control::subMenuClientes(Sucursal* s) {
	if (!s) return;
	string cedula, nombre, paisResi, activiEco;
	int respuesta;
	do {
		system("cls");
		cout << "-----Submenu de Clientes-----" << endl << endl;
		cout << "1. Agregar Cliente a la sucursal" << endl;
		cout << "2. Eliminar Cliente de la sucursal" << endl;
		cout << "3. Mostrar Cliente de la sucursal" << endl;
		cout << "4. Historial de solicitudes y contratos por cliente" << endl;
		cout << "5. Reporte de clientes por cantidad de contratos" << endl;
		cout << "6. Volver al Submenu de Sucursales" << endl;
		cout << "Ingrese una opcion: ";
		cin >> respuesta;
		cin.ignore(10000, '\n');

		switch (respuesta) {
		case 1: {
			bool seguir = true;
			while (seguir) {
				double descuento = 0.0;
				char opcion = 'z';
				bool juri = false;

				system("cls");
				cout << "Agregar Cliente a la sucursal" << endl << endl;
				while (true) {
					cout << "Ingrese el numero de cedula del nuevo cliente: ";
					cin >> cedula;
					cin.ignore(10000, '\n');
					if (cedula.empty()) {
						cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
						continue;
					}
					bool tieneEspacio = false;
					for (char c : cedula) { if (c == ' ' || c == '\t') { tieneEspacio = true; break; } }
					if (tieneEspacio) {
						cout << "La cedula no puede contener espacios. Intente de nuevo." << endl;
						continue;
					}

					if (s->getClientes()->buscarClientePorCedula(cedula) != nullptr) {
						cout << "El cliente ya existe. Intente de nuevo." << endl;
						continue;
					}
					break;
				}
				while (true) {
					cout << endl << "Ingrese el nombre del nuevo cliente: ";
					getline(cin, nombre);
					if (nombre.empty()) {
						cout << "El nombre no puede estar vacio. Intente de nuevo." << endl;
						continue;
					}
					break;
				}
				while (true) {
					cout << "Ingrese el pais de residencia del nuevo cliente: ";
					getline(cin, paisResi);
					if (paisResi.empty()) {
						cout << "El pais de residencia no puede estar vacio. Intente de nuevo." << endl;
						continue;
					}
					break;
				}
				while (true) {
					cout << "Es el cliente una persona juridica? (s/n): ";
					cin >> opcion;
					cin.ignore(10000, '\n');
					if (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N') {
						cout << "Opcion invalida. Intente de nuevo." << endl;
						continue;
					}
					if (opcion == 's' || opcion == 'S') {
						juri = true;
						cout << "Ingrese la actividad economica del nuevo cliente: ";
						getline(cin, activiEco);
						while (true) {
							cout << "Ingrese el porcentaje de descuento para el nuevo cliente (0-100): ";
							cin >> descuento;
							if (cin.fail()) {
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Entrada invalida. Ingrese un numero (puede tener decimales)." << endl;
								continue;
							}
							cin.ignore(10000, '\n');
							if (descuento < 0.0 || descuento > 100.0) {
								cout << "El porcentaje de descuento debe estar entre 0 y 100; puede tener decimales. Intente de nuevo." << endl;
								continue;
							}
							descuento = descuento / 100.0;
							break;
						}
					}
					if (!juri) {
						s->agregarCliente(new Cliente(cedula, nombre, paisResi));
					}
					else {
						s->agregarCliente(new Cliente(cedula, nombre, paisResi, activiEco, descuento));
					}

					cout << "Cliente agregado exitosamente." << endl;
					char op;
					while (true) {
						cout << "Desea agregar otro cliente? (s/n): ";
						cin >> op;
						cin.ignore(10000, '\n');
						if (op == 's' || op == 'S') {
							break;
						}
						else if (op == 'n' || op == 'N') {
							seguir = false;
							break;
						}
						else {
							cout << "Opcion invalida. Intente de nuevo." << endl;
							cin.ignore(10000, '\n');
						}
					}
				}
				cout << "Aprete enter para volver al submenu de clientes" << endl;
				cin.get();
				break;
			}
		}
		case 2: {
			if(s->getClientes()->getTam() == 0) {
				system("cls");
				cout << "No hay clientes para eliminar." << endl;
				cout << "Aprete enter para volver al submenu de clientes" << endl;
				cin.get();
				break;
			}
			bool seguir = true;
			while (seguir) {
				system("cls");
				string cedula;
				s->getClientes()->mostrarClientes();
				while (true) {
					cout << endl << "Ingrese la cedula del cliente a eliminar (o 'n' para cancelar): ";
					cin >> cedula;
					cin.ignore(10000, '\n');
					if (cedula == "n" || cedula == "N") break;
					if (cedula.empty()) {
						cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
						continue;
					}
					bool tieneEspacio = false;
					for (char c : cedula) { if (c == ' ' || c == '\t') { tieneEspacio = true; break; } }
					if (tieneEspacio) {
						cout << "La cedula no puede contener espacios. Intente de nuevo." << endl;
						continue;
					}
					if (!s->getClientes()->buscarClientePorCedula(cedula)) {
						cout << "El cliente no existe. Intente de nuevo." << endl;
						continue;
					}
					break;
				}
				if (cedula != "N" && cedula != "n") {
					s->eliminarCliente(cedula);
					cout << "Cliente eliminado exitosamente." << endl;
				}
				else {
					cout << "Operacion cancelada." << endl;
				}
				char op;
				while (true) {
					cout << "Desea eliminar otro cliente? (s/n): ";
					cin >> op;
					cin.ignore(10000, '\n');
					if (op == 's' || op == 'S') {
						break;
					}
					else if (op == 'n' || op == 'N') {
						seguir = false;
						break;
					}
					else {
						cout << "Opcion invalida. Intente de nuevo." << endl;
						cin.ignore(10000, '\n');
					}
				}
			}
			cout << "Aprete enter para volver al submenu de clientes" << endl;
			cin.get();
			break;
		}
		case 3: {
			if(s->getClientes()->getTam() == 0) {
				system("cls");
				cout << "No hay clientes para mostrar." << endl;
				cout << "Aprete enter para volver al submenu de clientes" << endl;
				cin.get();
				break;
			}
			system("cls");
			cout << " Clientes de la sucursal " << s->getNumSucursal() << endl << endl;
			s->getClientes()->mostrarClientes();
			cout << endl << "Aprete enter para volver al submenu de clientes" << endl;
			cin.clear();
			cin.get();
			break;
		}
		case 4: {
			if(s->getClientes()->getTam() == 0) {
				system("cls");
				cout << "No hay clientes para mostrar historial." << endl;
				cout << "Aprete enter para volver al submenu de clientes" << endl;
				cin.get();
				break;
			} 
			bool seguir = true;
			while (seguir) {
				system("cls");
				cout << "Historial de solicitudes y contratos por cliente" << endl;
				string cedula;
				s->getClientes()->mostrarClientes();
				while (true) {
					cout << endl << "Ingrese la cedula del cliente para ver su historial (o 'n' para salir): ";
					cin >> cedula;
					cin.ignore(10000, '\n');
					if (cedula == "n" || cedula == "N") break;
					if (cedula.empty()) {
						cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
						continue;
					}
					bool tieneEspacio = false;
					for (char c : cedula) { if (c == ' ' || c == '\t') { tieneEspacio = true; break; } }
					if (tieneEspacio) {
						cout << "La cedula no puede contener espacios. Intente de nuevo." << endl;
						continue;
					}
					if (!s->getClientes()->buscarClientePorCedula(cedula)) {
						cout << "El cliente no existe. Intente de nuevo." << endl;
						continue;
					}
					break;
				}
				s->getSolicitudes()->historialPorCliente(cedula);
				char op;
				while (true) {
					cout << endl << "Desea ver el historial de otro cliente? (s/n): ";
					cin >> op;
					cin.ignore(10000, '\n');
					if (op == 's' || op == 'S') {
						break;
					}
					else if (op == 'n' || op == 'N') {
						seguir = false;
						break;
					}
					else {
						cout << "Opcion invalida. Intente de nuevo." << endl;
					}
				}
			}
			cout << endl << "Aprete enter para volver al submenu de clientes" << endl;
			cin.get();
			break;
		}
		case 5: {
			if(s->getClientes()->getTam() == 0) {
				system("cls");
				cout << "No hay clientes para generar reporte." << endl;
				cout << "Aprete enter para volver al submenu de clientes" << endl;
				cin.get();
				break;
			}
			system("cls");
			cout << "Reporte de clientes por cantidad de contratos" << endl;
			s->getSolicitudes()->reporteClientesPorCantidadDeContratos();
			cout << endl << "Aprete enter para volver al submenu de clientes" << endl;
			cin.get();
			break;
		}
		case 6: {
			return;
		}
		default: {
			cout << "Opcion invalida. Por favor, intente de nuevo." << endl << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		} 
	}while (respuesta != 6);
}
void Control::subMenuVehiculosyPlanteles(Sucursal* s) {
	int resp = 0;
	do {
		system("cls");
		cout << "-----Submenu de Vehiculos y Planteles-----" << endl << endl;
		cout << "1. Agregar Plantel a la sucursal" << endl;
		cout << "2. Visualizacion Grafica de un Plantel" << endl;
		cout << "3. Agregar Vehiculo a la sucursal" << endl;
		cout << "4. Eliminar Vehiculo de la sucursal" << endl;
		cout << "5. Visualizacion de Vehiculo" << endl;
		cout << "6. Reubicar Vehiculo en la sucursal" << endl;
		cout << "7. Cambio de Estado de un Vehiculo" << endl;
		cout << "8. Estados de un Vehiculo especifico" << endl;
		cout << "9. Porcentaje de ocupacion de los planteles" << endl;
		cout << "10. Traslado de Vehiculos entre Sucursales" << endl;
		cout << "11. Volver al Submenu de Sucursales" << endl << endl;
		cout << "Ingrese una opcion: ";
		cin >> resp;
		cin.ignore(10000, '\n');

		switch (resp) {
		case 1: {
			funcionAgregarPlantel(s);
			break;
		}
		case 2: {
			if(s->getPlanteles()->getTam() == 0) {
				system("cls");
				cout << "No hay planteles en esta sucursal para visualizar." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			}
			funcionVisualizacionPlantel(s);
			break;
		}
		case 3: {
			funcionAgregarVehiculo(s);
			break;
		}
		case 4: {
			if(s->getPlanteles()->getTam() == 0) {
				system("cls");
				cout << "No hay planteles en esta sucursal para eliminar vehiculos." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			} else if (s->getPlanteles()->reporteDePorcentajeDeOcupacionDeLosPlanteles() == 0) {
				system("cls");
				cout << "No hay vehiculos en los planteles de esta sucursal para eliminar." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			}
			funcionEliminarVehiculo(s);
			break;
		}
		case 5: {
			if(s->getPlanteles()->getTam() == 0) {
				system("cls");
				cout << "No hay planteles en esta sucursal para visualizar vehiculos." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			} else if (s->getPlanteles()->reporteDePorcentajeDeOcupacionDeLosPlanteles() == 0) {
				system("cls");
				cout << "No hay vehiculos en los planteles de esta sucursal para visualizar." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			}
			funcionVisualizacionVehiculo(s);
			break;
		}
		case 6: {
			if(s->getPlanteles()->getTam() == 0) {
				system("cls");
				cout << "No hay planteles en esta sucursal para reubicar vehiculos." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			} else if (s->getPlanteles()->reporteDePorcentajeDeOcupacionDeLosPlanteles() == 0) {
				system("cls");
				cout << "No hay vehiculos en los planteles de esta sucursal para reubicar." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			}
			funcionReubicarVehiculo(s);
			break;
		}
		case 7: {
			if(s->getPlanteles()->getTam() == 0) {
				system("cls");
				cout << "No hay planteles en esta sucursal para cambiar estado de vehiculos." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			} else if (s->getPlanteles()->reporteDePorcentajeDeOcupacionDeLosPlanteles() == 0) {
				system("cls");
				cout << "No hay vehiculos en los planteles de esta sucursal para cambiar estado." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			}
			funcionCambioEstadoVehiculo(s);
			break;
		}
		case 8: {
			if(s->getPlanteles()->getTam() == 0) {
				system("cls");
				cout << "No hay planteles en esta sucursal para ver estados de vehiculos." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			} else if (s->getPlanteles()->reporteDePorcentajeDeOcupacionDeLosPlanteles() == 0) {
				system("cls");
				cout << "No hay vehiculos en los planteles de esta sucursal para ver estados." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			}
			funcionEstadosVehiculo(s);
			break;
		}
		case 9: {
			funcionPorcentajeOcupacionPlanteles(s);
			break;
		}
		case 10: {
			if(s->getPlanteles()->getTam() == 0) {
				system("cls");
				cout << "No hay planteles en esta sucursal para trasladar vehiculos." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			} else if (s->getPlanteles()->reporteDePorcentajeDeOcupacionDeLosPlanteles() == 0) {
				system("cls");
				cout << "No hay vehiculos en los planteles de esta sucursal para trasladar." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			} else if(this->listaSucursales->getTam() < 2) {
				system("cls");
				cout << "No hay otras sucursales para trasladar vehiculos." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			}
			funcionTrasladoVehiculosEntreSucursales(s);
			break;
		}
		case 11: {
			return;
		}
		default: {
			cout << "Opcion invalida. Por favor, intente de nuevo." << endl << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		}

	} while (resp != 12);
}
void Control::subMenuSolicitudesYContratos(Sucursal* s) {
	int resp = 0;
	do {
		system("cls");
		cout << "-----Submenu de Solicitudes y Contratos-----" << endl << endl;
		cout << "1. Crear Solicitud de Alquiler" << endl;
		cout << "2. Aprobar/Rechazar Solicitud de Alquiler" << endl;
		cout << "3. Mostrar Solicitudes/Contratos de Alquiler de la sucursal" << endl;
		cout << "4. Mostrar Solicitud/Contrato de Alquiler especifico" << endl;
		cout << "5. Recepcion de vehiculos" << endl;
		cout << "6. Reportes de Solicitudes y Contratos" << endl;
		cout << "7. Reporte contratos por vehiculo" << endl;
		cout << "8. Reportes de la sucursal ordenados por fechas" << endl;
		cout << "9. Volver al Submenu de Sucursales" << endl << endl;
		cout << "Ingrese una opcion: ";
		cin >> resp;
		cin.ignore(10000, '\n');
		switch (resp) {
		case 1: {
			funcionCrearSolicitudDeAlquiler(s);
			break;
		}
		case 2: {
			if(s->getSolicitudes()->getTam() == 0) {
				system("cls");
				cout << "No hay solicitudes en esta sucursal para aprobar o rechazar." << endl;
				cout << "Aprete enter para volver al submenu de solicitudes y contratos" << endl;
				cin.get();
				break;
			}
			funcionAprobarRechazarSolicitudDeAlquiler(s);
			break;
		}
		case 3: {
			if(s->getSolicitudes()->getTam() == 0) {
				system("cls");
				cout << "No hay solicitudes o contratos en esta sucursal para mostrar." << endl;
				cout << "Aprete enter para volver al submenu de solicitudes y contratos" << endl;
				cin.get();
				break;
			}
			funcionMostrarSolicitudesYContratosDeAlquilerDeLaSucursal(s);
			break;
		}
		case 4: {
			if(s->getSolicitudes()->getTam() == 0) {
				system("cls");
				cout << "No hay solicitudes o contratos en esta sucursal para mostrar." << endl;
				cout << "Aprete enter para volver al submenu de solicitudes y contratos" << endl;
				cin.get();
				break;
			}
			funcionMostrarSolicitudContratoEspecifico(s);
			break;
		}
		case 5: {
			if(s->getSolicitudes()->getTam() == 0) {
				system("cls");
				cout << "No hay solicitudes o contratos en esta sucursal para recepcion de vehiculos." << endl;
				cout << "Aprete enter para volver al submenu de solicitudes y contratos" << endl;
				cin.get();
				break;
			}
			funcionRecepcionDeVehiculos(s);
			break;

		}
		case 6: {
			if(s->getSolicitudes()->getTam() == 0) {
				system("cls");
				cout << "No hay solicitudes o contratos en esta sucursal para generar reportes." << endl;
				cout << "Aprete enter para volver al submenu de solicitudes y contratos" << endl;
				cin.get();
				break;
			}
			funcionReportesDeSolicitudesYContratos(s);
			break;
		}
		case 7: {
			if (s->getPlanteles()->getTam() == 0) {
				system("cls");
				cout << "No hay planteles en esta sucursal para generar reportes de contratos por vehiculo." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			}
			else if (s->getPlanteles()->reporteDePorcentajeDeOcupacionDeLosPlanteles() == 0) {
				system("cls");
				cout << "No hay vehiculos en los planteles de esta sucursal para generar reportes de contratos por vehiculo." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			}
			funcionReporteContratosPorVehiculo(s);
			break;
		}
		case 8: {
			if(s->getSolicitudes()->getTam() == 0) {
				system("cls");
				cout << "No hay solicitudes o contratos en esta sucursal para generar reportes ordenados por fechas." << endl;
				cout << "Aprete enter para volver al submenu de solicitudes y contratos" << endl;
				cin.get();
				break;
			}
			funcionReportesDeLaSucursalOrdenadosPorFechas(s);
			break;
		}
		case 9: {
			return;
		}
		default: {
			cout << "Opcion invalida. Por favor, intente de nuevo." << endl << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		}

	} while (resp != 7);
}
//funciones de los submenus
void Control::funcionAgregarPlantel(Sucursal* s) {
	string tipo;
	bool seguir = true;
	while (seguir) {

		system("cls");
		char letra;
		int capMax;
		cout << "Agregar Plantel a la sucursal" << endl << endl;
		while (true) {
			cout << "Ingrese la letra del plantel: ";
			cin >> letra;
			cin.ignore(10000, '\n');
			if (s->getPlanteles()->existeLetraPlantel(letra)) {
				cout << "La letra del plantel ya existe. Intente de nuevo." << endl;
				continue;
			}
			if (letra < 'A' || letra > 'Z') { //Que loco como efectivamente los char se pueden comparar asi, como numeros.
				cout << "La letra del plantel debe ser una letra mayuscula (A-Z). Intente de nuevo." << endl;
				continue;
			}
			break;
		}
		while (true) {
			cout << "Ingrese la capacidad maxima del plantel: ";
			cin >> capMax;
			cin.ignore(10000, '\n');
			if (capMax <= 0) {
				cout << "La capacidad maxima del plantel debe ser un numero positivo. Intente de nuevo." << endl;
				continue;
			}
			break;
		}
		while (true) {
			int op = 0;
			cout << "Ingrese el tipo de plantel:" << endl;
			cout << "1. Techado y asfaltado" << endl;
			cout << "2. Techado y lastreado" << endl;
			cout << "3. Asfaltado" << endl;
			cout << "4. Lastreado" << endl;
			cout << "Ingrese una opcion (1-4): ";
			cin >> op;
			cin.ignore(10000, '\n');
			switch (op) {
			case 1: {
				tipo = "Techado y asfaltado";
				break;
			}
			case 2: {
				tipo = "Techado y lastreado";
				break;
			}
			case 3: {
				tipo = "Asfaltado";
				break;
			}
			case 4: {
				tipo = "Lastreado";
				break;
			}
			default:
				cout << "Opcion invalida. Intente de nuevo." << endl;
				cin.ignore(10000, '\n');
				cin.clear();
				continue;
			}


			break;
		}
		Plantel* p = new Plantel(letra, tipo, capMax);
		s->getPlanteles()->agregarPlantel(p);
		cout << endl << "Plantel agregado exitosamente." << endl;
		char op;
		while (true) {
			cout << "Desea agregar otro plantel? (s/n): ";
			cin >> op;
			cin.ignore(10000, '\n');
			if (op == 's' || op == 'S') {
				break;
			}
			else if (op == 'n' || op == 'N') {
				seguir = false;
				break;
			}
			else {
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		}
	}
	cout << endl << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
	cin.get();
	return;
}
void Control::funcionVisualizacionPlantel(Sucursal* s) {
	if (!s) return;
	bool seguir = true;
	while (seguir) {
		system("cls");
		char letra;
		bool conf = false;
		cout << " Visualizacion Grafica de un Plantel " << endl << endl;
		s->getPlanteles()->mostrarPlanteles();
		while (true) {
			cout << endl << "Ingrese la letra del plantel a visualizar (o 'n' para salir): ";
			cin >> letra;
			cin.ignore(10000, '\n');
			if (letra == 'n' || letra == 'N') {
				seguir = false;
				return;
			}
			if (!s->getPlanteles()->existeLetraPlantel(letra)) {
				cout << "No se encontro el plantel con la letra: " << letra << endl;
				continue;
			}
			conf = true;
			break;
		}
		if (conf && s->getPlanteles()->existeLetraPlantel(letra)) {
			s->getPlanteles()->visualizacionGraficaDePlanteles(letra);
			Plantel* p = s->getPlanteles()->obtenerPlantelPorLetra(letra);
			char verEspacio;
			while (true) {
				cout << endl << "Desea consultar un espacio especifico? (s/n): ";
				cin >> verEspacio;
				cin.ignore(10000, '\n');
				if (verEspacio == 's' || verEspacio == 'S') {
					bool seguirConsultando = true;
					while (seguirConsultando) {
						int numeroEspacio;
						cout << "Ingrese el numero del espacio (1-" << p->getCapMax() << ") o 0 para salir: ";
						cin >> numeroEspacio;
						cin.ignore(10000, '\n');
						if (numeroEspacio == 0) {
							break;
						}
						if (numeroEspacio < 1 || numeroEspacio > p->getCapMax()) {
							cout << "Numero fuera de rango. Debe ser entre 1 y " << p->getCapMax() << "." << endl;
							continue;
						}
						int numColumnas = p->getEstacionamiento()->getnC();
						int posicion = numeroEspacio - 1;
						int fila = posicion / numColumnas;
						int columna = posicion % numColumnas;
						string codigoEspacio = string(1, toupper(letra)) + (numeroEspacio < 10 ? "0" : "") + to_string(numeroEspacio);
						cout << endl;
						if (p->getEstacionamiento()->estaOcupado(fila, columna)) {
							cout << "Espacio " << codigoEspacio << " - Ocupado " << endl;
							cout << p->getEstacionamiento()->getVehiculoEnEspacio(fila, columna)->toString() << endl;
						}
						else {
							cout << "Espacio " << codigoEspacio << " - Vacio " << endl;
							cout << "Posicion: [Fila: " << fila << "][Columna: " << columna << "]" << endl;
						}
						cout << endl;
					}
					break;
				}
				else if (verEspacio == 'n' || verEspacio == 'N') {
					break;
				}
				cout << "Opcion invalida." << endl;
			}
		}
		while (true) {
			cout << endl << "Desea visualizar otro plantel? (s/n): ";
			char op;
			cin >> op;
			cin.ignore(10000, '\n');
			if (op == 's' || op == 'S') {
				break;
			}
			else if (op == 'n' || op == 'N') {
				seguir = false;
				break;
			}
			else {
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		}
	}
	cout << endl << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
	cin.get();
}
void Control::funcionAgregarVehiculo(Sucursal* s) {
	string placa, modelo, marca;
	char cate, lice;
	bool seguir = true;
	while (seguir) {
		system("cls");
		s->getPlanteles()->mostrarPlanteles();
		cout << "En que plantel desea agregar el vehiculo? (Ingrese la letra del plantel): ";
		char letraPlantel;
		cin >> letraPlantel;
		cin.ignore(10000, '\n');
		if (s->getPlanteles()->getTam() == 0) {
			cout << "No hay planteles en la sucursal. Agregue un plantel primero." << endl;
			cin.get();
			return;
		}
		Plantel* p = s->getPlanteles()->obtenerPlantelPorLetra(letraPlantel);
		if (!p) {
			cout << "Plantel no encontrado. Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		while (true) {
			cout << "Ingrese la placa del vehiculo: ";
			cin >> placa;
			cin.ignore(10000, '\n');
			if (placa.empty()) {
				cout << "La placa no puede estar vacia. Intente de nuevo." << endl;
				continue;
			}
			if (p->getListaVehiculos()->buscarVehiculoPorPlaca(placa)) {
				cout << "La placa del vehiculo ya existe. Intente de nuevo." << endl;
				continue;
			}
			break;
		}
		cout << "Ingrese el modelo del vehiculo: ";
		getline(cin, modelo);
		cout << "Ingrese el marca del vehiculo: ";
		getline(cin, marca);
		while (true) {
			cout << "Ingrese la categoria del vehiculo (A: Economico, B: Estandar, C: Lujo, D: 4x4): ";
			cin >> cate;
			cin.ignore(10000, '\n');
			cate = toupper(cate);
			if (cate < 'A' || cate > 'D') {
				cout << "Categoria invalida. Intente de nuevo." << endl;
				continue;
			}
			break;
		}
		while (true) {
			cout << "Ingrese el tipo de licencia requerida para conducir el vehiculo (A, B, C, D, E): ";
			cin >> lice;
			cin.ignore(10000, '\n');
			lice = toupper(lice);
			if (lice < 'A' || lice > 'E') {
				cout << "Tipo de licencia invalida. Intente de nuevo." << endl;
				continue;
			}
			break;
		}
		Vehiculo* vehi = new Vehiculo(placa, modelo, marca, cate, lice);
		p->getListaVehiculos()->agregarVehiculo(vehi);
		system("cls");
		cout << " Estacionar vehiculo " << endl << endl;
		s->getPlanteles()->visualizacionGraficaDePlanteles(letraPlantel);
		cout << endl << p->getEstacionamiento()->espacioRecomendado() << endl << endl;
		while (true) {
			int numeroEspacio;
			cout << "Ingrese el numero del espacio (1-" << p->getCapMax() << "): ";
			cin >> numeroEspacio;
			cin.ignore(10000, '\n');
			if (numeroEspacio < 1 || numeroEspacio > p->getCapMax()) {
				cout << "Numero fuera de rango. Debe ser entre 1 y " << p->getCapMax() << "." << endl;
				continue;
			}
			int numColumnas = p->getEstacionamiento()->getnC();
			int posicion = numeroEspacio - 1;
			int fila = posicion / numColumnas;
			int columna = posicion % numColumnas;
			string codigoEspacio = string(1, toupper(letraPlantel)) +
				(numeroEspacio < 10 ? "0" : "") +
				to_string(numeroEspacio);
			if (p->getEstacionamiento()->estaOcupado(fila, columna)) {
				cout << "El espacio " << codigoEspacio << " ya esta ocupado. Intente de nuevo." << endl;
				continue;
			}
			if (p->getEstacionamiento()->agregarVehiculoEnEspacio(vehi, fila, columna)) {
				cout << endl << "Vehiculo estacionado exitosamente en espacio " << codigoEspacio << endl;
				break;
			}
			else {
				cout << "Error al estacionar el vehiculo. Intente de nuevo." << endl;
			}
		}
		cout << endl << "Vehiculo agregado exitosamente." << endl;
		char op;
		while (true) {
			cout << "Desea agregar otro vehiculo? (s/n): ";
			cin >> op;
			cin.ignore(10000, '\n');
			if (op == 's' || op == 'S') {
				break;
			}
			else if (op == 'n' || op == 'N') {
				seguir = false;
				break;
			}
			else {
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		}
	}
	return;
}
void Control::funcionEliminarVehiculo(Sucursal* s) {
	string placa;
	bool seguir = true;

	while (seguir) {
		system("cls");

		if (s->getPlanteles()->getTam() == 0) {
			cout << "No hay planteles en la sucursal. Agregue un plantel primero." << endl;
			cout << endl << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
			cin.get();
			return;
		}

		s->getPlanteles()->mostrarPlanteles();
		cout << "En que plantel desea eliminar el vehiculo? (Ingrese la letra del plantel): ";
		char letraPlantel;
		cin >> letraPlantel;
		cin.ignore(10000, '\n');

		Plantel* p = s->getPlanteles()->obtenerPlantelPorLetra(letraPlantel);
		if (!p) {
			cout << "Plantel no encontrado. Intente de nuevo." << endl;
			cout << endl << "Aprete enter para continuar" << endl;
			cin.get();
			continue;
		}

		if (!p->getListaVehiculos() || p->getListaVehiculos()->getTam() == 0) {
			cout << "No hay vehiculos en el plantel. Agregue un vehiculo primero." << endl;
			cout << endl << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
			cin.get();
			return;
		}

		system("cls");
		cout << "=== Eliminar Vehiculo del Plantel " << letraPlantel << " ===" << endl << endl;
		p->getListaVehiculos()->mostrarVehiculosSimple();

		while (true) {
			cout << endl << "Ingrese la placa del vehiculo a eliminar (o 'n' para salir): ";
			cin >> placa;
			cin.ignore(10000, '\n');
			if (placa == "n" || placa == "N") {
				break;
			}
			if (placa.empty()) {
				cout << "La placa no puede estar vacia. Intente de nuevo." << endl;
				continue;
			}
			if (!p->getListaVehiculos()->buscarVehiculoPorPlaca(placa)) {
				cout << "El vehiculo con placa " << placa << " no existe en este plantel. Intente de nuevo." << endl;
				continue;
			}
			char conf;
			while (true) {
				cout << "Esta seguro que desea eliminar el vehiculo con placa " << placa << "? (s/n): ";
				cin >> conf;
				cin.ignore(10000, '\n');
				if (conf == 's' || conf == 'S') {
					bool eliEspacio = p->getEstacionamiento()->eliminarVehi(placa);
					bool eliLista = p->getListaVehiculos()->eliminarVehiculo(placa);
					if (eliLista) {
						cout << endl << "Vehiculo con placa " << placa << " eliminado exitosamente." << endl;
						if (!eliEspacio) {
							cout << "(El vehiculo no estaba estacionado en ningun espacio)" << endl;
						}
					}
					else {
						cout << endl << "Error: No se pudo eliminar el vehiculo." << endl;
					}
					break;
				}
				else if (conf == 'n' || conf == 'N') {
					cout << "Eliminacion cancelada." << endl;
					break;
				}
				else {
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			}
			break;
		}
		if (placa == "n" || placa == "N") {
			return;
		}
		char op;
		while (true) {
			cout << endl << "Desea eliminar otro vehiculo? (s/n): ";
			cin >> op;
			cin.ignore(10000, '\n');
			if (op == 's' || op == 'S') {
				break;
			}
			else if (op == 'n' || op == 'N') {
				seguir = false;
				break;
			}
			else {
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		}
	}
	cout << endl << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
	cin.get();
}
void Control::funcionVisualizacionVehiculo(Sucursal* s) {
	if (!s) return;
	if (!s->getPlanteles()) {
		cout << "No hay planteles en la sucursal. Agregue un plantel primero." << endl;
		cin.get();
		return;
	}
	string placa;
	bool seguir = true;
	while (seguir) {
		system("cls");
		s->getPlanteles()->mostrarPlanteles();
		cout << "En que plantel se encuentra el vehiculo? (Ingrese la letra del plantel): ";
		char letraPlantel;
		cin >> letraPlantel;
		cin.ignore(10000, '\n');
		Plantel* p = s->getPlanteles()->obtenerPlantelPorLetra(letraPlantel);
		if (!p) {
			cout << "Plantel no encontrado. Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		if (!p->getListaVehiculos()) {
			cout << "No hay vehiculos en el plantel. Agregue un vehiculo primero." << endl;
			cin.get();
			return;
		}
		p->getListaVehiculos()->mostrarVehiculosSimple();
		while (true) {
		cout << endl << "Ingrese la placa del vehiculo a visualizar: ";
		cin >> placa;
		cin.ignore(10000, '\n');
		if(placa.empty()) {
			cout << "La placa no puede estar vacia. Intente de nuevo." << endl;
			continue;
		}
		if (!p->getListaVehiculos()->buscarVehiculoPorPlaca(placa)) {
			cout << "El vehiculo no existe. Intente de nuevo." << endl;
			continue;
		}
		break;
	}
		cout << p->getListaVehiculos()->obtenerVehiculoPorPlaca(placa)->toString()<<endl;
		char op;
		while (true) {
			cout << "Desea visualizar otro vehiculo? (s/n): ";
			cin >> op;
			cin.ignore(10000, '\n');
			if (op == 's' || op == 'S') {
				break;
			}
			else if (op == 'n' || op == 'N') {
				seguir = false;
				break;
			}
			else {
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		}
	}
}
void Control::funcionReubicarVehiculo(Sucursal* s) {
	if (!s) return;
	string placa;
	bool seguir = true;
	while (seguir) {
		system("cls");
		s->getPlanteles()->mostrarPlanteles();
		cout << "En que plantel se encuentra el vehiculo a reubicar? (Ingrese la letra del plantel): ";
		char letraPlantel;
		cin >> letraPlantel;
		cin.ignore(10000, '\n');
		Plantel* p = s->getPlanteles()->obtenerPlantelPorLetra(letraPlantel);
		if (!p) {
			cout << "Plantel no encontrado. Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		if (!p->getListaVehiculos()) {
			cout << "No hay vehiculos en el plantel. Agregue un vehiculo primero." << endl;
			cin.get();
			return;
		}
		p->getListaVehiculos()->mostrarVehiculosSimple();
		while (true) {
			cout << endl << "Ingrese la placa del vehiculo a reubicar: ";
			cin >> placa;
			cin.ignore(10000, '\n');
			if (placa.empty()) {
				cout << "La placa no puede estar vacia. Intente de nuevo." << endl;
				continue;
			}
			if (!p->getListaVehiculos()->buscarVehiculoPorPlaca(placa)) {
				cout << "El vehiculo no existe. Intente de nuevo." << endl;
				continue;
			}
			break;
		}
		Vehiculo* v = p->getListaVehiculos()->obtenerVehiculoPorPlaca(placa);
		while (true) {
			system("cls");
			cout << "Seleccione el nuevo plantel para reubicar el vehiculo:" << endl;
			s->getPlanteles()->mostrarPlanteles();
			cout << "Ingrese la letra del nuevo plantel: ";
			char nuevaLetra;
			cin >> nuevaLetra;
			cin.ignore(10000, '\n');

			Plantel* nuevoPlantel = s->getPlanteles()->obtenerPlantelPorLetra(nuevaLetra);
			if (!nuevoPlantel) {
				cout << "Plantel no encontrado. Intente de nuevo." << endl;
				cin.get();
				continue;
			}
			while (true) {
				int numFila;
				int numColumna;
				system("cls");
				s->getPlanteles()->visualizacionGraficaDePlanteles(nuevaLetra);
				cout << nuevoPlantel->getEstacionamiento()->espacioRecomendado() << endl;
				while (true) {
					cout << "En que fila desea reubicar el vehiculo? (Ingrese el numero de fila): ";

					cin >> numFila;
					cin.ignore(10000, '\n');
					if (numFila < 0 || numFila >= nuevoPlantel->getEstacionamiento()->getnF()) {
						cout << "Fila no valida. Intente de nuevo." << endl;
						continue;
					}
					break;
				}
				while (true) {
					cout << "En que columna desea reubicar el vehiculo? (Ingrese el numero de columna): ";
					cin >> numColumna;
					cin.ignore(10000, '\n');
					if (numColumna < 0 || numColumna >= nuevoPlantel->getEstacionamiento()->getnC()) {
						cout << "Columna no valida. Intente de nuevo." << endl;
						continue;
					}
					break;
				}
				if (nuevoPlantel->getEstacionamiento()->agregarVehiculoEnEspacio(v, numFila, numColumna)) {
					p->getListaVehiculos()->eliminarVehiculo(placa);
					cout << "Vehiculo reubicado exitosamente." << endl;
					break;
				}
				else {
					cout << "No se pudo reubicar el vehiculo en el espacio seleccionado. Intente de nuevo." << endl;
					continue;
				}
			}
			break;
 		}
		char op;
		while (true) {
			cout << "Desea reubicar otro vehiculo? (s/n): ";
			cin >> op;
			cin.ignore(10000, '\n');
			if (op == 's' || op == 'S') {
				break;
			}
			else if (op == 'n' || op == 'N') {
				seguir = false;
				break;
			}
			else {
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		}
	}
}
void Control::funcionCambioEstadoVehiculo(Sucursal* s) {
	if (!s) return;
	bool seguir = true;
	while (true) {
		system("cls");
		s->getPlanteles()->mostrarPlanteles();
		cout << "Que plantel contiene el vehiculo cuyo estado desea cambiar? (Ingrese la letra del plantel): ";
		char letraPlantel;
		cin >> letraPlantel;
		cin.ignore(10000, '\n');
		Plantel* p = s->getPlanteles()->obtenerPlantelPorLetra(letraPlantel);
		if (!p) {
			cout << "Plantel no encontrado. Intente de nuevo." << endl;
			cin.get();
			return;
		}
		if (!p->getListaVehiculos()) {
			cout << "No hay vehiculos en el plantel. Agregue un vehiculo primero." << endl;
			cin.get();
			return;
		}
		p->getListaVehiculos()->mostrarVehiculosSimple();
		string placa;
		while (true) {
			cout << endl << "Ingrese la placa del vehiculo cuyo estado desea cambiar: ";
			cin >> placa;
			cin.ignore(10000, '\n');
			if (placa.empty()) {
				cout << "La placa no puede estar vacia. Intente de nuevo." << endl;
				continue;
			}
			if (!p->getListaVehiculos()->buscarVehiculoPorPlaca(placa)) {
				cout << "El vehiculo no existe. Intente de nuevo." << endl;
				continue;
			}
			break;
		}
		Vehiculo* v = p->getListaVehiculos()->obtenerVehiculoPorPlaca(placa);
		system("cls");
		s->getColaboradores()->mostrarColaboradores();

		Colaborador* c = nullptr;
		while (true) {
			cout << "Ingrese la cedula del colaborador que realiza el cambio de estado: ";
			string cedColaborador;
			cin >> cedColaborador;
			cin.ignore(10000, '\n');
			if (cedColaborador.empty()) {
				cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
				continue;
			}
			c = s->getColaboradores()->buscarColaboradorPorCed(cedColaborador); 
			if (!c) {
				cout << "El colaborador no existe. Intente de nuevo." << endl;
				continue;
			}
			break; 
		}
		int opcion;
		while (true) {
			system("cls");
			cout << "Estado actual del vehiculo: " << v->getEstadoNombre() << endl;
			cout << "Seleccione el nuevo estado del vehiculo:" << endl;
			cout << "1. Disponible" << endl;
			cout << "2. Alquilado" << endl;
			cout << "3. Devuelto" << endl;
			cout << "4. Revision" << endl;
			cout << "5. Lavado" << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;
			cin.ignore(10000, '\n');

			switch (opcion) {
			case 1: {
				v->cambiarEstado(0, c, fechaActual->clonar());
				break;
			}
			case 2: {
				v->cambiarEstado(1, c, fechaActual->clonar());
				break;
			}
			case 3: {
				v->cambiarEstado(2, c, fechaActual->clonar());
				break;
			}
			case 4: {
				v->cambiarEstado(3, c, fechaActual->clonar());
				break;
			}
			case 5: {
				v->cambiarEstado(4, c, fechaActual->clonar());
				break;
			}
			default:
				cout << "Opcion invalida. Intente de nuevo." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			break;
		}
		char op;
		while (true) {
			cout << "Desea cambiar el estado de otro vehiculo? (s/n): ";
			cin >> op;
			cin.ignore(10000, '\n');
			if (op == 's' || op == 'S') {
				break;
			}
			else if (op == 'n' || op == 'N') {
				seguir = false;
				break;
			}
			else {
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		}
	}
}
void Control::funcionEstadosVehiculo(Sucursal* s) {
	if (!s) return;
	string placa;
	bool seguir = true;
	while (seguir) {
		system("cls");
		s->getPlanteles()->mostrarPlanteles();
		cout << "En que plantel se encuentra el vehiculo? (Ingrese la letra del plantel): ";
		char letraPlantel;
		cin >> letraPlantel;
		cin.ignore(10000, '\n');
		Plantel* p = s->getPlanteles()->obtenerPlantelPorLetra(letraPlantel);
		if (!p) {
			cout << "Plantel no encontrado. Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		if (!p->getListaVehiculos()) {
			cout << "No hay vehiculos en el plantel. Agregue un vehiculo primero." << endl;
			cin.get();
			return;
		}
		p->getListaVehiculos()->mostrarVehiculosSimple();
		while (true) {
			cout << endl << "Ingrese la placa del vehiculo para ver sus estados: ";
			cin >> placa;
			cin.ignore(10000, '\n');
			if (placa.empty()) {
				cout << "La placa no puede estar vacia. Intente de nuevo." << endl;
				continue;
			}
			if (!p->getListaVehiculos()->buscarVehiculoPorPlaca(placa)) {
				cout << "El vehiculo no existe. Intente de nuevo." << endl;
				continue;
			}
			break;
		}
		Vehiculo* v = p->getListaVehiculos()->obtenerVehiculoPorPlaca(placa);
		if(!v) {
			cout << "Vehiculo no encontrado. Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		v->mostrarBitacora();
		cout << endl;
		char op;
		while (true) {
			cout << "Desea ver los estados de otro vehiculo? (s/n): ";
			cin >> op;
			cin.ignore(10000, '\n');
			if (op == 's' || op == 'S') {
				break;
			}
			else if (op == 'n' || op == 'N') {
				seguir = false;
				break;
			}
			else {
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		}
	}
}
void Control::funcionPorcentajeOcupacionPlanteles(Sucursal* s) {
	if (!s) return;
	system("cls");
	s->getPlanteles()->reportajeDePorcentajeDeOcupacionDeCadaPlantel();
	cout << endl << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
	cin.get();
}
void Control::funcionCrearSolicitudDeAlquiler(Sucursal* s){
	if (!s) return;
	bool seguir = true;

	while (seguir) {
		system("cls");
		string codSolicitud;
		int codSucu = s->getNumSucursal();
		Cliente* cli = nullptr;
		Colaborador* colab = nullptr;
		Plantel* plantel = nullptr;
		Fecha* fechaFinal = nullptr;
		Vehiculo* vehi = nullptr;
		string pVehi;
		int diasAlquiler;

		cout << "Crear Solicitud de Alquiler" << endl << endl;
		while (true) {

			cout << "Ingrese el codigo de la solicitud de alquiler: ";
			cin >> codSolicitud;
			cin.ignore(10000, '\n');
			if (codSolicitud.empty()) {
				cout << "El codigo no puede estar vacio. Intente de nuevo." << endl;
				continue;
			}
			if (s->getSolicitudes()->buscarSolicitudPorCodigo(codSolicitud)) {
				cout << "El codigo de la solicitud ya existe. Intente de nuevo." << endl;
				continue;
			}
			break;
		}
		while (true) {
			cout << endl;
			if(s->getClientes()->getTam() == 0){
				cout << "No hay clientes en la sucursal. Agregue un cliente primero." << endl;
				cin.get();
				return;
			}
			s->getClientes()->mostrarClientes();
			cout << "Ingrese la cedula del cliente que realiza la solicitud: ";
			string cedulaCliente;
			cin >> cedulaCliente;
			cin.ignore(10000, '\n');
			if(!s->getClientes()->buscarClientePorCedula(cedulaCliente)){
				cout << "El cliente no existe. Intente de nuevo." << endl;
				continue;
			}
			cli = s->getClientes()->buscarClientePorCedula(cedulaCliente);
			break;
		}

		while (true) {
			cout << endl;
			if(s->getColaboradores()->getTam() == 0){
				cout << "No hay colaboradores en la sucursal. Agregue un colaborador primero." << endl;
				cin.get();
				return;
			}
			s->getColaboradores()->mostrarColaboradores();
			cout << "Ingrese la cedula del colaborador que realiza la solicitud: ";
			string cedulaColaborador;
			cin >> cedulaColaborador;
			cin.ignore(10000, '\n');
		
			if (!s->getColaboradores()->buscarColaboradorPorCed(cedulaColaborador)) {
				cout << "El colaborador no existe. Intente de nuevo." << endl;
				continue;
			}
			colab = s->getColaboradores()->buscarColaboradorPorCed(cedulaColaborador);
			break;
		}
		while (true) {
			cout << endl;
			if (s->getPlanteles()->getTam() == 0) {
				cout << "No hay planteles en la sucursal. Agregue un plantel primero." << endl;
				cin.get();
				return;
			}
			s->getPlanteles()->mostrarPlanteles();
			cout << "Ingrese la letra del plantel donde se encuentra el vehiculo a alquilar: ";
			char letraPlantel;
			cin >> letraPlantel;
			cin.ignore(10000, '\n');
			if(s->getPlanteles()->existeLetraPlantel(letraPlantel) == false){
				cout << "El plantel no existe. Intente de nuevo." << endl;
				continue;
			}
			if(s->getPlanteles()->obtenerPlantelPorLetra(letraPlantel)->getListaVehiculos()->getTam() == 0){
				cout << "No hay vehiculos en el plantel seleccionado. Agregue un vehiculo primero o intente con otro plantel." << endl;
				char op;
				while (true) {
					cout << "Desea intentar con otro plantel? (s/n): ";
					cin >> op;
					cin.ignore(10000, '\n');
					if (op == 's' || op == 'S') {
						break;
					}
					else if (op == 'n' || op == 'N') {
						return;
					}
					else {
						cout << "Opcion invalida. Intente de nuevo." << endl;
					}
				}
				continue;
			}
			plantel = s->getPlanteles()->obtenerPlantelPorLetra(letraPlantel);
			plantel->getListaVehiculos()->mostrarVehiculosSimple();
			while (true) {
				cout << endl;
				cout << "Ingrese la placa del vehiculo que se desea alquilar: ";
				cin >> pVehi;
				cin.ignore(10000, '\n');
				if (pVehi.empty()) {
					cout << "La placa no puede estar vacia. Intente de nuevo." << endl;
					continue;
				}
				if (!plantel->getListaVehiculos()->buscarVehiculoPorPlaca(pVehi)) {
					cout << "El vehiculo no existe. Intente de nuevo." << endl;
					continue;
				}
				vehi = plantel->getListaVehiculos()->obtenerVehiculoPorPlaca(pVehi);
				break;
			}
			break;
		}
		while (true) {
			cout << "Ingrese la cantidad de dias de alquiler: ";
			cin >> diasAlquiler;
			cin.ignore(10000, '\n');
			if(diasAlquiler <= 0){
				cout << "La cantidad de dias debe ser mayor a 0. Intente de nuevo." << endl;
				continue;
			}
			fechaFinal = fechaActual->agregarDias(diasAlquiler);
			break;
		}
		SoliAlquiyContra* nuevaSolicitud = new SoliAlquiyContra(codSolicitud, cli, colab, codSucu, pVehi, diasAlquiler, fechaActual->clonar(), fechaFinal, vehi->getPrecio());
		s->getSolicitudes()->agregarSolicitud(nuevaSolicitud);
		cout << "Solicitud de alquiler creada exitosamente." << endl;
		char op;
		while (true) {
			cout << "Desea crear otra solicitud de alquiler? (s/n): ";
			cin >> op;
			cin.ignore(10000, '\n');

			if (op == 's' || op == 'S') {
				break;
			}
			else if (op == 'n' || op == 'N') {
				seguir = false;
				break;
			}
			else {
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		}
		cin.get();
	}
}
void Control::funcionAprobarRechazarSolicitudDeAlquiler(Sucursal* s) {
	if (!s) return;
	bool seguir = true;
	while (seguir) {
		SoliAlquiyContra* solicitud = nullptr;
		system("cls");
		s->getSolicitudes()->mostrarSolicitudOContraSucursal(false); //Este false es para que muestre solo las solicitudes, no los contratos
		while (true) {
			cout << "Ingrese el codigo de la solicitud a aprobar/rechazar: ";
			string codSolicitud;
			cin >> codSolicitud;
			cin.ignore(10000, '\n');
			if (codSolicitud.empty()) {
				cout << "El codigo no puede estar vacio. Intente de nuevo." << endl;
				continue;
			}
			if (!s->getSolicitudes()->buscarSolicitudPorCodigo(codSolicitud)) {
				cout << "La solicitud no existe. Intente de nuevo." << endl;
				continue;
			}
			solicitud = s->getSolicitudes()->obtenerSolicitudPorCodigo(codSolicitud);
			if (solicitud->getEstadoSoli() != "Pendiente") {
				cout << "La solicitud ya ha sido aprobada o rechazada. Intente de nuevo." << endl;
				continue;
			}
			break;
		}
		solicitud->mostrarInfo();
		int opcion;
		while (true) {
			cout << "Menu de Aprobacion/Rechazo de Solicitud de Alquiler" << endl;
			cout << "1. Aprobar Solicitud" << endl;
			cout << "2. Rechazar Solicitud" << endl;
			cout << "3. Anular solicitud" << endl;
			cout << "4. Cancelar y volver al submenu de contratos y alquileres" << endl << endl;
			cin >> opcion;
			cin.ignore(10000, '\n');
			switch (opcion) {
			case 1: {
				solicitud->cambiarEstadoSoli("Aprobada");
				cout << "Solicitud aprobada exitosamente y convertida a contrato." << endl;
				break;
			}
			case 2: {
				solicitud->cambiarEstadoSoli("Rechazada");
				cout << "Solicitud rechazada exitosamente." << endl;
				break;
			}
			case 3: {
				solicitud->cambiarEstadoSoli("Anulada");
				cout << "Solicitud anulada exitosamente." << endl;
				break;
			}
			case 4: {
				break;
			}
			default: {
				cout << "Opcion invalida. Intente de nuevo." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			}
			break;
		}
		char op;
		while (true) {
			cout << "Desea aprobar/rechazar otra solicitud de alquiler? (s/n): ";
			cin >> op;
			cin.ignore(10000, '\n');
			if (op == 's' || op == 'S') {
				break;
			}
			else if (op == 'n' || op == 'N') {
				seguir = false;
				break;
			}
			else {
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		}
	}
}
void Control::funcionMostrarSolicitudesYContratosDeAlquilerDeLaSucursal(Sucursal* s) {
	if (!s) return;
	bool opCA = true;
	int op;
	do {
		system("cls");
		cout << "Visualizacion de alquileres, solicitudes y contratos" << endl << endl;
		cout << "1. Solicitudes de alquiler" << endl;
		cout << "2. Contratos de alquiler" << endl;
		cout << "3. Volver al submenu de contratos y alquileres" << endl << endl;
		cout << "Ingrese una opcion: ";
		cin >> op;
		cin.ignore(10000, '\n');
		switch (op) {
		case 1: {
			opCA = false;
			s->getSolicitudes()->mostrarSolicitudOContraSucursal(opCA); //Este true es para que muestre los contratos
			cout << endl << "Aprete enter para volver al menu anterior" << endl;
			cin.clear();
			cin.get();
			break;
		}
		case 2: {
			opCA = true;
			s->getSolicitudes()->mostrarSolicitudOContraSucursal(opCA); //Este true es para que muestre los contratos
			cout << endl << "Aprete enter para volver al menu anterior" << endl;
			cin.clear();
			cin.get();
			break;
		}
		case 3: {
			break;
		}
		default: {
			cout << "Opcion invalida. Intente de nuevo." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		}
		} while (op != 3);
}
void Control::funcionMostrarSolicitudContratoEspecifico(Sucursal* s) {
	if (!s) return;
	while (true) {
		system("cls");
		bool opCA;
		int opc;
		cout << "Visualizacion de solicitud o contrato especifico" << endl << endl;
		cout << "1. Solicitud de alquiler" << endl;
		cout << "2. Contrato de alquiler" << endl;
		cout << "3. Volver al submenu de contratos y alquileres" << endl << endl;
		cout << "Ingrese una opcion: ";
		cin >> opc;
		cin.ignore(10000, '\n');
		switch (opc) {
		case 1: {
			opCA = false;
			bool seguir = true;
			while (seguir) {
				s->getSolicitudes()->mostrarSolicitudOContraSucursal(opCA);
				cout << endl;
				while (true) {
					cout << "Ingrese el codigo de la solicitud a visualizar: ";
					string codSolicitud;
					cin >> codSolicitud;
					cin.ignore(10000, '\n');
					if (codSolicitud.empty()) {
						cout << "El codigo no puede estar vacio. Intente de nuevo." << endl;
						continue;
					}
					if (!s->getSolicitudes()->buscarSolicitudPorCodigo(codSolicitud)) {
						cout << "La solicitud no existe. Intente de nuevo." << endl;
						continue;
					}
					s->getSolicitudes()->mostrarSolicitudEspecifica(codSolicitud);
					cin.clear();
					cout << endl << "Aprete enter para volver al submenu de contratos y alquileres";
					cin.get();
					break;
				}
				char op;
				while (true) {
					cout << "Desea visualizar otra solicitud? (s/n): ";
					cin >> op;
					cin.ignore(10000, '\n');
					if (op == 's' || op == 'S') {
						break;
					}
					else if (op == 'n' || op == 'N') {
						seguir = false;
						break;
					}
					else {
						cout << "Opcion invalida. Intente de nuevo." << endl;
					}
				}
			}
			break;
		}
		case 2: {
			opCA = false;
			bool seguir = true;
			while (seguir) {
				s->getSolicitudes()->mostrarSolicitudOContraSucursal(opCA);
				cout << endl;
				while (true) {
					cout << "Ingrese el codigo del contrato a visualizar: ";
					string codContrato;
					cin >> codContrato;
					cin.ignore(10000, '\n');
					if (codContrato.empty()) {
						cout << "El codigo no puede estar vacio. Intente de nuevo." << endl;
						continue;
					}
					if (!s->getSolicitudes()->buscarSolicitudPorCodigo(codContrato)) {
						cout << "El contrato no existe. Intente de nuevo." << endl;
						continue;
					}
					s->getSolicitudes()->mostrarSolicitudEspecifica(codContrato);
					cin.clear();
					cout << endl << "Aprete enter para volver al submenu de contratos y alquileres";
					cin.get();
					break;
				}
				char op;
				while (true) {
					cout << "Desea visualizar otro contrato? (s/n): ";
					cin >> op;
					cin.ignore(10000, '\n');
					if (op == 's' || op == 'S') {
						break;
					}
					else if (op == 'n' || op == 'N') {
						seguir = false;
						break;
					}
					else {
						cout << "Opcion invalida. Intente de nuevo." << endl;
					}
				}
			}
			break;
		}
		case 3: {
			return;
		}
		default: {
			cout << "Opcion invalida. Intente de nuevo." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		}
	}
}
void Control::funcionRecepcionDeVehiculos(Sucursal* s) {
	if (!s) return;
	while (true) {
		system("cls");
		s->getPlanteles()->mostrarPlanteles();
		cout << "En que plantel se encuentra registrado el vehiculo alquilado que se va a recibir? (Ingrese la letra del plantel): ";
		char letraPlantel;
		cin >> letraPlantel;
		cin.ignore(10000, '\n');

		Plantel* p = s->getPlanteles()->obtenerPlantelPorLetra(letraPlantel);
		if (!p) {
			cout << "Plantel no encontrado. Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		if (!p->getListaVehiculos()) {
			cout << "No hay vehiculos en el plantel. Agregue un vehiculo primero." << endl;
			cin.get();
			return;
		}
		p->getListaVehiculos()->mostrarVehiculosAlquilados();
		string placa;
		while (true) {
			cout << endl << "Ingrese la placa del vehiculo alquilado a recibir: ";
			cin >> placa;
			cin.ignore(10000, '\n');
			if (placa.empty()) {
				cout << "La placa no puede estar vacia. Intente de nuevo." << endl;
				continue;
			}
			if (!p->getListaVehiculos()->buscarVehiculoPorPlaca(placa)) {
				cout << "El vehiculo no existe. Intente de nuevo." << endl;
				continue;
			}
			break;
		}
		Vehiculo* v = p->getListaVehiculos()->obtenerVehiculoPorPlaca(placa);
		v->cambiarEstado(2, nullptr, fechaActual->clonar());
		cout << "Vehiculo recibido exitosamente." << endl;
		cin.clear();
		cin.get();
		return;
	}
}
void Control::funcionReportesDeSolicitudesYContratos(Sucursal* s) {
	if (!s) return;
	while (true) {
		system("cls");
		cout << "Reportes de Solicitudes y Contratos" << endl << endl;
		cout << "1. Reporte de solicitudes de alquiler por estado" << endl;
		cout << "2. Reporte de contratos de alquiler por estado" << endl;
		cout << "3. Volver al submenu de contratos y alquileres" << endl << endl;
		cout << "Ingrese una opcion: ";
		int opcion;
		cin >> opcion;
		cin.ignore(10000, '\n');
		switch (opcion) {
		case 1: {
			bool opCA = false;
			string codSolicitud;
			while (true) {
				s->getSolicitudes()->mostrarSolicitudOContraSucursal(opCA);
				cout << endl;
				while (true) {
					cout << "Ingrese el codigo de la solicitud a visualizar: ";
					cin >> codSolicitud;
					cin.ignore(10000, '\n');
					if (codSolicitud.empty()) {
						cout << "El codigo no puede estar vacio. Intente de nuevo." << endl;
						continue;
					}
					if (!s->getSolicitudes()->buscarSolicitudPorCodigo(codSolicitud)) {
						cout << "La solicitud no existe. Intente de nuevo." << endl;
						continue;
					}
					break;
				}
				s->getSolicitudes()->obtenerSolicitudPorCodigo(codSolicitud)->mostrarInfo();
				break;
			}
			cout << endl << "Aprete enter para volver al menu anterior" << endl;
			cin.clear();
			cin.get();
			break;
		}
		case 2: {
			bool opCA = true;
			string codSolicitud;
			while (true) {
				s->getSolicitudes()->mostrarSolicitudOContraSucursal(opCA);
				cout << endl;
				while (true) {
					cout << "Ingrese el codigo del contrato a visualizar: ";
					cin >> codSolicitud;
					cin.ignore(10000, '\n');
					if (codSolicitud.empty()) {
						cout << "El codigo no puede estar vacio. Intente de nuevo." << endl;
						continue;
					}
					if (!s->getSolicitudes()->buscarSolicitudPorCodigo(codSolicitud)) {
						cout << "El contrato no existe. Intente de nuevo." << endl;
						continue;
					}
					break;
				}
				s->getSolicitudes()->obtenerSolicitudPorCodigo(codSolicitud)->mostrarInfo();
				break;
			}
			cout << endl << "Aprete enter para volver al menu anterior" << endl;
			cin.clear();
			cin.get();
			break;
		}
		case 3: {
			return;
		}
		default: {
			cout << "Opcion invalida. Intente de nuevo." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		}
	}
}
void Control::funcionReporteContratosPorVehiculo(Sucursal* s) {
	if (!s) return;
	while (true) {
		system("cls");
		s->getPlanteles()->mostrarPlanteles();
		cout << "En que plantel se encuentra el vehiculo? (Ingrese la letra del plantel): ";
		char letraPlantel;
		cin >> letraPlantel;
		cin.ignore(10000, '\n');
		Plantel* p = s->getPlanteles()->obtenerPlantelPorLetra(letraPlantel);
		if (!p) {
			cout << "Plantel no encontrado. Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		if (!p->getListaVehiculos()) {
			cout << "No hay vehiculos en el plantel. Agregue un vehiculo primero." << endl;
			cin.get();
			return;
		}
string placa;
while (true) {
	system("cls");
	p->getListaVehiculos()->mostrarVehiculosSimple();
	cout << endl << "Ingrese la placa del vehiculo para ver sus contratos: ";
	cin >> placa;
			cin.ignore(10000, '\n');
			if (placa.empty()) {
				cout << "La placa no puede estar vacia. Intente de nuevo." << endl;
				continue;
			}
			if (!p->getListaVehiculos()->buscarVehiculoPorPlaca(placa)) {
				cout << "El vehiculo no existe. Intente de nuevo." << endl;
				continue;
			}
			if (!s->getSolicitudes()->tieneVehiContrato(placa)) {
				cout << "No hay contratos asociados al vehiculo con placa: " << placa << endl;
				char opVolver;
				while (true) {
					cout << "Desea buscar otro vehiculo? (s/n): ";
					cin >> opVolver;
					cin.ignore(10000, '\n');
					if (opVolver == 's' || opVolver == 'S') {
						break;
					}
					else if (opVolver == 'n' || opVolver == 'N') {
						return;
					}
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
				continue;
			}
			break;
		}
		Vehiculo* v = p->getListaVehiculos()->obtenerVehiculoPorPlaca(placa);
		s->getSolicitudes()->reportesSolicitudesPorVehiculo(v->getPlaca());
		char verDetalle;
		while (true) {
			cout << endl << "Desea ver el detalle de algun contrato? (s/n): ";
			cin >> verDetalle;
			cin.ignore(10000, '\n');
			if (verDetalle == 's' || verDetalle == 'S') {
				string codigoContrato;
				cout << "Ingrese el codigo del contrato: ";
				cin >> codigoContrato;
				cin.ignore(10000, '\n');

				if (s->getSolicitudes()->buscarSolicitudPorCodigo(codigoContrato)) {
					system("cls");
					s->getSolicitudes()->mostrarSolicitudEspecifica(codigoContrato);
					cout << endl << "Aprete enter para continuar..." << endl;
					cin.get();
				}
				else {
					cout << "Contrato no encontrado." << endl;
				}
				break;
			}
			else if (verDetalle == 'n' || verDetalle == 'N') {
				break;
			}
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
		char op;
		while (true) {
			cout << "Desea ver los contratos de otro vehiculo? (s/n): ";
			cin >> op;
			cin.ignore(10000, '\n');
			if (op == 's' || op == 'S') {
				break;
			}
			else if (op == 'n' || op == 'N') {
				cout << endl << "Aprete enter para volver al submenu de contratos y alquileres" << endl;
				cin.get();
				return;
			}
			else {
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		}
	}
}
void Control::funcionReportesDeLaSucursalOrdenadosPorFechas(Sucursal* s) {
	if (!s) return;
	while (true) {
		system("cls");
		s->getSolicitudes()->mostrarContratosOrdenados();

		cout << endl << "Aprete enter para volver al submenu..." << endl;
		cin.get();
		break;
	}
}
void Control::funcionTrasladoVehiculosEntreSucursales(Sucursal* s) {
	if (!s) return;
	Sucursal* sucuOrigen = nullptr;
	Sucursal* sucuDestino = nullptr;
	Plantel* planOrigen = nullptr;
	Plantel* planDestino = nullptr;
	Vehiculo* vehiculoATrasladar = nullptr;

	while (true) {
		system("cls");
		cout << "Seleccione la sucursal origen del vehiculo a trasladar:" << endl;
		this->listaSucursales->mostrarSucursales();
		cout << endl << "Ingrese el numero de sucursal origen: ";
		int nSucuOrigen;
		cin >> nSucuOrigen;
		cin.ignore(10000, '\n');
		if (!this->listaSucursales->existeSucursal(nSucuOrigen)) {
			cout << "Sucursal no encontrada. Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		if(this->listaSucursales->obtenerSucursal(nSucuOrigen)->getPlanteles()->getTam() == 0){
			cout << "La sucursal seleccionada no tiene planteles. Agregue un plantel primero." << endl;
			cout << "Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		if (!listaSucursales->obtenerSucursal(nSucuOrigen)){
			cout << "Sucursal no encontrada. Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		else sucuOrigen = this->listaSucursales->obtenerSucursal(nSucuOrigen);
		while (true) {
			system("cls");
			cout << "Seleccione el plantel de origen del vehiculo a trasladar:" << endl;
			sucuOrigen->getPlanteles()->mostrarPlanteles();
			cout << endl << "Ingrese la letra del plantel de origen: ";
			char nPlantelOrigen;
			cin >> nPlantelOrigen;
			cin.ignore(10000, '\n');
			if (!sucuOrigen->getPlanteles()->existeLetraPlantel(nPlantelOrigen)) {
				cout << "Plantel no encontrado. Intente de nuevo." << endl;
				cin.get();
				continue;
			}
			if(!sucuOrigen->getPlanteles()->obtenerPlantelPorLetra(nPlantelOrigen)) {
				cout << "Plantel no encontrado. Intente de nuevo." << endl;
				cin.get();
				continue;
			}
			else planOrigen = sucuOrigen->getPlanteles()->obtenerPlantelPorLetra(nPlantelOrigen);
			if(planOrigen->getListaVehiculos()->getTam() == 0){
				cout << "El plantel seleccionado no tiene vehiculos. Agregue un vehiculo primero." << endl;
				cout << "Intente de nuevo." << endl;
				cin.get();
				continue;
			}
			break;
		}
		while (true) {
			system("cls");
			cout << "Seleccione el vehiculo a trasladar:" << endl;
			planOrigen->getListaVehiculos()->mostrarVehiculosSimple();
			cout << endl << "Ingrese la placa del vehiculo a trasladar: ";
			string placa;
			cin >> placa;
			cin.ignore(10000, '\n');
			if (!planOrigen->getListaVehiculos()->buscarVehiculoPorPlaca(placa)) {
				cout << "Vehiculo no encontrado. Intente de nuevo." << endl;
				cin.get();
				continue;
			}
			else {
				vehiculoATrasladar = planOrigen->getListaVehiculos()->obtenerVehiculoPorPlaca(placa);
				if (vehiculoATrasladar->getEstadoNombre() == "Alquilado") {
					cout << "El vehiculo seleccionado esta alquilado y no puede ser trasladado. Intente de nuevo." << endl;
					cin.get();
					continue;
				}
			}
			if (!vehiculoATrasladar) {
				cout << "Vehiculo no encontrado. Intente de nuevo." << endl;
				cin.get();
				continue;
			}
			else {
				cout << "Vehiculo seleccionado exitosamente." << endl;
				cin.clear();
				cin.get();
				break;
			}
		}
		break;
	}
	while (true) {
		system("cls");
		cout << "Seleccione la sucursal destino del vehiculo a trasladar:" << endl;
		this->listaSucursales->mostrarSucursales();
		cout << endl << "Ingrese el numero de sucursal destino: ";
		int nSucuDestino;
		cin >> nSucuDestino;
		cin.ignore(10000, '\n');
		if (!this->listaSucursales->existeSucursal(nSucuDestino)) {
			cout << "Sucursal no encontrada. Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		if (this->listaSucursales->obtenerSucursal(nSucuDestino)->getPlanteles()->getTam() == 0) {
			cout << "La sucursal seleccionada no tiene planteles. Agregue un plantel primero." << endl;
			cout << "Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		if (!listaSucursales->obtenerSucursal(nSucuDestino)) {
			cout << "Sucursal no encontrada. Intente de nuevo." << endl;
			cin.get();
			continue;
		}
		else sucuDestino = this->listaSucursales->obtenerSucursal(nSucuDestino);
		while (true) {
			system("cls");
			cout << "Seleccione el plantel de destino del vehiculo a trasladar:" << endl;
			sucuDestino->getPlanteles()->mostrarPlanteles();
			cout << endl << "Ingrese la letra del plantel de destino: ";
			char nPlantelDestino;
			cin >> nPlantelDestino;
			cin.ignore(10000, '\n');
			if (!sucuDestino->getPlanteles()->existeLetraPlantel(nPlantelDestino)) {
				cout << "Plantel no encontrado. Intente de nuevo." << endl;
				cin.get();
				continue;
			}
			if (!sucuDestino->getPlanteles()->obtenerPlantelPorLetra(nPlantelDestino)) {
				cout << "Plantel no encontrado. Intente de nuevo." << endl;
				cin.get();
				continue;
			}
			else planDestino = sucuDestino->getPlanteles()->obtenerPlantelPorLetra(nPlantelDestino);
			break;
		}
		break;
	}
	system("cls");
	cout << " Resumen del traslado " << endl << endl;
	cout << "ORIGEN:" << endl;
	cout << "  Sucursal: #" << sucuOrigen->getNumSucursal() << endl;
	cout << "  Plantel: " << planOrigen->getLetra() << endl << endl;
	cout << " - Vehiculo -" << endl;
	cout << vehiculoATrasladar->toString() << endl << endl;
	cout << "DESTINO:" << endl;
	cout << "  Sucursal: #" << sucuDestino->getNumSucursal() << endl;
	cout << "  Plantel: " << planDestino->getLetra() << endl << endl;
	char conf;
	while (true) {
		cout << "Esta seguro que desea realizar este traslado? (s/n): ";
		cin >> conf;
		cin.ignore(10000, '\n');

		if (conf == 'n' || conf == 'N') {
			cout << " Traslado cancelado. " << endl;
			cout << endl << " Aprete enter para volver " << endl;
			cin.get();
			return;
		}
		else if (conf == 's' || conf == 'S') {
			break;
		}
		else {
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	}
	string placaVehiculo = vehiculoATrasladar->getPlaca();
	planOrigen->getEstacionamiento()->eliminarVehi(placaVehiculo);
	if (!planOrigen->getListaVehiculos()->eliminarNodoVehiSinDelete(placaVehiculo)) {
		cout << " No se pudo remover el vehiculo de la lista origen. " << endl;
		cout << endl << " Aprete enter para volver " << endl;
		cin.get();
		return;
	}
	planDestino->getListaVehiculos()->agregarVehiculo(vehiculoATrasladar);
	system("cls");
	cout << " Estacionar vehiculo " << endl << endl;
	sucuDestino->getPlanteles()->visualizacionGraficaDePlanteles(planDestino->getLetra());
	cout << endl << planDestino->getEstacionamiento()->espacioRecomendado() << endl << endl;
	while (true) {
		int numeroEspacio;
		cout << "Ingrese el numero del espacio (1-" << planDestino->getCapMax() << "): ";
		cin >> numeroEspacio;
		cin.ignore(10000, '\n');
		if (numeroEspacio < 1 || numeroEspacio > planDestino->getCapMax()) {
			cout << "Numero fuera de rango. Intente de nuevo." << endl;
			continue;
		}
		int numColumnas = planDestino->getEstacionamiento()->getnC();
		int posicion = numeroEspacio - 1;
		int fila = posicion / numColumnas;
		int columna = posicion % numColumnas;
		if (planDestino->getEstacionamiento()->estaOcupado(fila, columna)) {
			cout << "El espacio esta ocupado. Intente de nuevo." << endl;
			continue;
		}
		if (planDestino->getEstacionamiento()->agregarVehiculoEnEspacio(vehiculoATrasladar, fila, columna)) {
			string codigoEspacio = string(1, toupper(planDestino->getLetra())) + (numeroEspacio < 10 ? "0" : "") + to_string(numeroEspacio);
			cout << endl << "Vehiculo estacionado exitosamente en espacio " << codigoEspacio << endl;
			break;
		}
		else {
			cout << "Error al estacionar. Intente de nuevo." << endl;
		}
	}

	cout << endl << " Traslado completado " << endl;
	cout << "Vehiculo trasladado de la Sucursal #" << sucuOrigen->getNumSucursal() << " (Plantel " << planOrigen->getLetra() << ")";
	cout << " a la Sucursal #" << sucuDestino->getNumSucursal() << " (Plantel " << planDestino->getLetra() << ")" << endl;

	cout << endl << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
	cin.get();
}

