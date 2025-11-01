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
		numeroSucursales++;
		Sucursal* nuevaSucursal = new Sucursal(numeroSucursales);
		listaSucursales->agregarSucursal(nuevaSucursal);
}
bool Control::eliminarSucursal(int numSucursal) {
		if(listaSucursales->eliminarSucursal(numSucursal)) {
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
		cout << "-----Menu Principal-----" << endl << endl;
		cout << "1. Agregar Sucursal" << endl;
		cout << "2. Eliminar Sucursal" << endl;
		cout << "3. Mostrar Sucursales" << endl;
		cout << "4. Gestionar Sucursales" << endl;
		cout << "5. Cerrar programa" << endl;
		cout << "Ingrese una opcion: ";
		cin >> respuesta;
		switch (respuesta) {
		case 1: {
			agregarSucursal();
			cout << "Sucursal " << numeroSucursales << " agregada exitosamente." << endl;
			break;
		}
		case 2: {
			int numSuc;
			this->mostrarSucursales();
			cout << endl << "Ingrese el numero de la sucursal a eliminar: ";
			cin >> numSuc;
			if (eliminarSucursal(numSuc)) {
				cout << "Sucursal " << numSuc << " eliminada exitosamente." << endl;
			}
			else {
				cout << "No se encontro la sucursal " << numSuc << "." << endl;
			}
			break;
		}
		case 3: {
			mostrarSucursales();
			break;
		}
		case 4: {
			do {
				mostrarSucursales();
				cout << endl << "Ingrese el numero de la sucursal a gestionar: ";
				int numSucursal;
				cin >> numSucursal;
				if (numSucursal<0 || numSucursal>numeroSucursales) {
					system("cls");
					cout << "Numero de sucursal invalido intentelo de nuevo" << endl;
					continue;
				}
				else {
					subMenuSucursales(numSucursal);
				}
				break;
			} while (true);
			break;
		}
		case 5:
			cout << "Saliendo del programa..." << endl;
			return;
		default:
			cout << "Opcion invalida. Por favor, intente de nuevo." << endl << endl;
			cin.ignore(10000, '\n');
			continue;

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
			submenuSolicitudesYContratos(sGestionar);
			break;
		case 5:
			cout << "Volviendo al Menu Principal..." << endl;
			this->menuPrincipal();
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
				s->agregarColaborador(new Colaborador(cedula, nombre, fechaActual));
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
			subMenuSucursales(s->getNumSucursal());
			break;
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
			cout << "Volviendo al Submenu de Sucursales..." << endl;
			subMenuSucursales(s->getNumSucursal());
			break;
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
		case 2:
		{
			if(s->getPlanteles()->getTam() == 0) {
				system("cls");
				cout << "No hay planteles en esta sucursal para visualizar." << endl;
				cout << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
				cin.get();
				break;
			}
			bool seguir = true;
			while (seguir) {
				system("cls");
				char letra;
				bool conf = false;
				cout << "=== Visualizacion Grafica de un Plantel ===" << endl << endl;
				s->getPlanteles()->mostrarPlanteles();
				while (true) {
					cout << endl << "Ingrese la letra del plantel a visualizar (o 'n' para salir): ";
					cin >> letra;
					cin.ignore(10000, '\n');
					if (letra == 'n' || letra == 'N') {
						seguir = false;
						break;
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
			cout << "Volviendo al Submenu de Sucursales..." << endl;
			subMenuSucursales(s->getNumSucursal());
			break;
		}
		default: {
			cout << "Opcion invalida. Por favor, intente de nuevo." << endl << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		}

	} while (resp != 11);
}
void Control::subMenuSolicitudesYContratos(Sucursal* s) {
	int resp = 0;
	do {
		cout << "-----Submenu de Solicitudes y Contratos-----" << endl << endl;
		cout << "1. Crear Solicitud de Alquiler" << endl;
		cout << "2. Aprobar/Rechazar Solicitud de Alquiler" << endl;
		cout << "3. Mostrar Solicitudes/Contratos de Alquiler de la sucursal" << endl;
		cout << "4. Mostrar Solicitud/Contrato de Alquiler especifico" << endl;
		cout << "5. Recepcion de vehiculos" << endl;
		cout << "6. Reportes de Solicitudes y Contratos" << endl;
		cout << "7. Volver al Submenu de Sucursales" << endl << endl;
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
			cout << "Volviendo al Submenu de Sucursales..." << endl;
			subMenuSucursales(s->getNumSucursal());
			break;
		}
		default: {
			cout << "Opcion invalida. Por favor, intente de nuevo." << endl << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		}

	} while (resp != 7);
}

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
void Control::funcionAgregarVehiculo(Sucursal* s) {
	string placa, modelo, marca;
	char cate, lice;
	bool seguir = true;
	while(seguir) {
		system("cls");
		s->getPlanteles()->mostrarPlanteles();
		cout<<"En que plantel desea agregar el vehiculo? (Ingrese la letra del plantel): ";
		char letraPlantel;
		cin >> letraPlantel;
		cin.ignore(10000, '\n');
		if(s->getPlanteles()->getTam() == 0){
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
		cout << "Ingrese la marca del vehiculo: ";
		getline(cin, marca);
		while (true) {
			cout << "Ingrese la categoria del vehiculo (A, B, C, D, E): ";
			cin >> cate;
			cin.ignore(10000, '\n');
			cate = toupper(cate); //..................... No sabia que existia esta funcion............... Mucho tiempo desperdiciado
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

	Vehiculo* vehi= new Vehiculo(placa, modelo, marca, cate, lice);
	p->getListaVehiculos()->agregarVehiculo(vehi);
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
//Falta agregar el vehiculo a un espacio de estacionamiento libre del plantel
void Control::funcionEliminarVehiculo(Sucursal* s) {
	string placa;
	bool seguir = true;
	while (seguir) {
		system("cls");
		s->getPlanteles()->mostrarPlanteles();
		cout << "En que plantel desea eliminar el vehiculo? (Ingrese la letra del plantel): ";
		char letraPlantel;
		cin >> letraPlantel;
		cin.ignore(10000, '\n');
		if(s->getPlanteles()->getTam() == 0){
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
		if (!p->getListaVehiculos()) {
			cout << "No hay vehiculos en el plantel. Agregue un vehiculo primero." << endl;
			cin.get();
			return;
		}
		p->getListaVehiculos()->mostrarVehiculosSimple();
		while (true) {
			cout << endl << "Ingrese la placa del vehiculo a eliminar (o 'n' para salir): ";
			cin >> placa;
			cin.ignore(10000, '\n');
			if (placa == "n" || placa == "N") break;
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
		if (placa != "n" && placa != "N") {
			p->getListaVehiculos()->eliminarVehiculo(placa);
			cout << "Vehiculo eliminado exitosamente." << endl;
		}
		else {
			return;
		}
		char op;
		while (true) {
			cout << "Desea eliminar otro vehiculo? (s/n): ";
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
				v->cambiarEstado(0, c, fechaActual);
				break;
			}
			case 2: {
				v->cambiarEstado(1, c, fechaActual);
				break;
			}
			case 3: {
				v->cambiarEstado(2, c, fechaActual);
				break;
			}
			case 4: {
				v->cambiarEstado(3, c, fechaActual);
				break;
			}
			case 5: {
				v->cambiarEstado(4, c, fechaActual);
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
	cout << "El porcentaje de ocupacion de los planteles es: " << s->getPlanteles()->reporteDePorcentajeDeOcupacionDeLosPlanteles() << "%" << endl;
	cout << endl << "Aprete enter para volver al submenu de vehiculos y planteles" << endl;
	cin.get();
}

void Control::funcionTrasladoVehiculosEntreSucursales(Sucursal* s) {

}

void Control::funcionCrearSolicitudDeAlquiler(Sucursal* s){

}

void Control::funcionAprobarRechazarSolicitudDeAlquiler(Sucursal* s){

}

void Control::funcionMostrarSolicitudesYContratosDeAlquilerDeLaSucursal(Sucursal* s){

}

void Control::funcionMostrarSolicitudContratoEspecifico(Sucursal* s){

}

void Control::funcionRecepcionDeVehiculos(Sucursal* s){

}

void Control::funcionReportesDeSolicitudesYContratos(Sucursal* s){

}
