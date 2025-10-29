#include "Control.h"
#include <ctime>

static int numeroSucursales = 1;
static Fecha* fechaActual = new Fecha();


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
	fechaActual = fechaActual->obtenerFechaActual();
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
			delete listaSucursales;
			exit(0);
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
			//subMenuVehiculosyPlanteles(sGestionar);
			break;
		case 4:
			//submenuSolicitudesYContratos(sGestionar);
			break;
		case 5:
			cout << "Volviendo al Menu Principal..." << endl;
			break;
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
		switch (respuesta)
		{
		case 1: {
			string cedula, nombre;
			cout << "Agregar Colaborador a la sucursal" << endl << endl;
			do {
				cout << "Ingrese el numero de cedula del nuevo colaborador :";cin >> cedula;
				if (cedula.empty()) {
					cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
					continue;
				}
				if (s->getColaboradores()->buscarColaboradorPorCed(cedula) && cedula == s->getColaboradores()->buscarColaboradorPorCed(cedula)->getCedula()) {
					cout << "El colaborador ya existe. Intente de nuevo." << endl;
					continue;
				}
				break;
			} while (true);
			do {
				cout <<endl<< "Ingrese el nombre del nuevo colaborador: ";
				cin.clear();
				cin.ignore();
				getline(cin, nombre);
				if (nombre.empty()) {
					cout << "El nombre no puede estar vacio. Intente de nuevo." << endl;
					continue;
				}
				break;
			} while (true);
			s->agregarColaborador(new Colaborador(cedula, nombre, fechaActual));
			break;
		}

		case 2: {
			string cedula;
			s->getColaboradores()->mostrarColaboradores();
			do{
				cout << endl << "Ingrese la cedula del colaborador a eliminar: ";
				cin >> cedula;
				if (cedula.empty()) {
					cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
					continue;
				}
				if (!s->getColaboradores()->buscarColaboradorPorCed(cedula)) {
					cout << "El colaborador no existe. Intente de nuevo." << endl;
					continue;
				}
				break;
			} while (true);
			s->eliminarColaborador(cedula);
			cout << "Colaborador eliminado exitosamente." << endl;
			cin.clear();
			cin.get();
			break;
		}
		case 3: {
			cout << " Colaboradores de la sucursal " << s->getNumSucursal() <<endl<< endl;
			s->getColaboradores()->mostrarColaboradores();
			cin.get();
			break;
		}
		case 4: {
			do {
			string cedula;
			s->getColaboradores()->mostrarColaboradores();
			
			cout << endl << "Ingrese la cedula del colaborador para ver su historial: ";
			cin >> cedula;
			if (cedula.empty()) {
				cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
				continue;
			}
			if (s->getColaboradores()->buscarColaboradorPorCed(cedula) &&!s->getColaboradores()->buscarColaboradorPorCed(cedula)) {
				cout << "El colaborador no existe. Intente de nuevo." << endl;
				continue;
			}
			s->getSolicitudes()->reportesAlquilerPorColaborador(cedula);
			char opcion;
			do {
				cout << endl << "Desea ver detalladamente alguna solicitud o contrato realizado por este colaborador? (s/n): ";
				cin >> opcion;
				if (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N') {
					cout << "Opcion invalida. Intente de nuevo." << endl;
					continue;
				}

				if (opcion == 's' || opcion == 'S') {
					string codigo;
					do {
						cout << "Ingrese el codigo de la solicitud o contrato: ";
						cin >> codigo;
						if (codigo.empty()) {
							cout << "El codigo no puede estar vacio. Intente de nuevo." << endl;
							continue;
						}
						system("cls");
						s->getSolicitudes()->mostrarSolicitudEspecifica(codigo);
						break;
					} while (true);
				} 

			}while (true);

			do{
			cout << endl << "Desea ver los contratos de otro colaborador? (s/n): ";
			cin >> opcion;
			if(opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N') {
				cout << "Opcion invalida. Intente de nuevo." << endl;
				continue;
			}
			
			break;
			} while (true);
			if (opcion == 's' || opcion == 'S') continue;
			break;
		} while (true);
			break;
		}
		case 5: {
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
	} while (respuesta != 5);
	return;
}
void Control::subMenuClientes(Sucursal* s) {
	if (!s) return;
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

		switch (respuesta)
		{
		case 1: {
			string cedula, nombre, paisResi, activiEco= " ";
			double descuento = 0.0;
			char opcion;
			bool juri;
			cout << "Agregar Cliente a la sucursal" << endl << endl;
			do {
				cout << "Es el cliente una persona juridica? (s/n): ";
				cin >> opcion;
				if (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N') {
					cout << "Opcion invalida. Intente de nuevo." << endl;
					continue;
				}
				if(opcion == 's' || opcion == 'S') {
					juri = true;
					cout << "Ingrese la actividad economica del nuevo cliente: ";
					cin.clear();
					cin.ignore();
					getline(cin, activiEco);
					do {
						cout << "Ingrese el porcentaje de descuento para el nuevo cliente (0-100): ";
						cin >> descuento;
						if (descuento < 0 || descuento > 100) {
							cout << "El porcentaje de descuento debe estar entre 0 y 100; puede tener decimales. Intente de nuevo." << endl;
							continue;
						}
						descuento = descuento / 100;
						break;
					} while (true);
				} else {
					juri = false;
				}
				break;
			} while (true);
			do {
				cout << "Ingrese el numero de cedula del nuevo colaborador :";cin >> cedula;
				if (cedula.empty()) {
					cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
					continue;
				}
				if (s->getClientes()->buscarClientePorCedula(cedula) && cedula == s->getClientes()->buscarClientePorCedula(cedula)->getCedula()) {
					cout << "El cliente ya existe. Intente de nuevo." << endl;
					continue;
				}
				break;
			} while (true);
			do {
				cout << endl << "Ingrese el nombre del nuevo cliente: ";
				cin.clear();
				cin.ignore();
				getline(cin, nombre);
				if (nombre.empty()) {
					cout << "El nombre no puede estar vacio. Intente de nuevo." << endl;
					continue;
				}
				break;
			} while (true);
			if(!juri){
			s->agregarCliente(new Cliente(cedula, nombre, paisResi));
			}
			else {
				s->agregarCliente(new Cliente(cedula, nombre, paisResi, activiEco, descuento));
			}
			break;
		}
		case 2: {
			string cedula;
			s->getClientes()->mostrarClientes();
			do{
				cout << endl << "Ingrese la cedula del cliente a eliminar: ";
				cin >> cedula;
				if (cedula.empty()) {
					cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
					continue;
				}
				if (!s->getClientes()->buscarClientePorCedula(cedula)) {
					cout << "El cliente no existe. Intente de nuevo." << endl;
					continue;
				}
				break;
			} while (true);
			s->eliminarCliente(cedula);
			cout << "Cliente eliminado exitosamente." << endl;
			cin.clear();
			cin.get();
			break;
		}
		case 3: {
			cout << " Clientes de la sucursal " << s->getNumSucursal() <<endl<< endl;
			s->getClientes()->mostrarClientes();
			cin.get();
			break;
		}
		case 4: {
			cout << "Historial de solicitudes y contratos por cliente" << endl;
			string cedula;
			s->getClientes()->mostrarClientes();
			do{
				cout << endl << "Ingrese la cedula del cliente para ver su historial: ";
				cin >> cedula;
				if (cedula.empty()) {
					cout << "La cedula no puede estar vacia. Intente de nuevo." << endl;
					continue;
				}
				if (!s->getClientes()->buscarClientePorCedula(cedula)) {
					cout << "El cliente no existe. Intente de nuevo." << endl;
					continue;
				}
				break;
			} while (true);
			s->getSolicitudes()->historialPorCliente(cedula);
			cin.clear();
			cin.get();
			break;
		}
		case 5: {
			cout << "Reporte de clientes por cantidad de contratos" << endl;
			s->getSolicitudes()->reporteClientesPorCantidadDeContratos();
			cin.clear();
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
	} while (respuesta != 5);
}

//void Control::subMenuVehiculosyPlanteles(Sucursal* s) {}
//void Control::submenuSolicitudesYContratos(Sucursal* s) {}
