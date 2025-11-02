#include "Quemados.h"
Quemados::Quemados(Control* c): control(c){}
Quemados::~Quemados(){}
void Quemados::quemarDatos() {
    for (int i = 0; i < 10; i++) {
        control->agregarSucursal();
    }

    //Sucursal 1

    Sucursal* sucursal1 = control->getListaSucursales()->obtenerSucursal(1);

    sucursal1->agregarColaborador(new Colaborador("101110111", "Juan Perez", Fecha::obtenerFechaActualPtr()->clonar()));
    sucursal1->agregarColaborador(new Colaborador("202220222", "Maria Rodriguez", Fecha::obtenerFechaActualPtr()->clonar()));
    sucursal1->agregarColaborador(new Colaborador("303330333", "Carlos Sanchez", Fecha::obtenerFechaActualPtr()->clonar()));

    sucursal1->agregarCliente(new Cliente("111222333", "Pedro Gomez", "Costa Rica"));
    sucursal1->agregarCliente(new Cliente("444555666", "Ana Martinez", "Panama"));
    sucursal1->agregarCliente(new Cliente("777888999", "Luis Fernandez", "Nicaragua"));
    sucursal1->agregarCliente(new Cliente("123456789", "Empresa ABC S.A.", "Costa Rica", "Transporte", 0.15)); // Cliente jurídico 15%

    Plantel* plantelA1 = new Plantel('A', "Techado y asfaltado", 20);
    sucursal1->getPlanteles()->agregarPlantel(plantelA1);

    Vehiculo* v1 = new Vehiculo("ABC123", "Corolla", "Toyota", 'A', 'B');
    Vehiculo* v2 = new Vehiculo("DEF456", "Civic", "Honda", 'A', 'B');
    Vehiculo* v3 = new Vehiculo("GHI789", "Sentra", "Nissan", 'B', 'B');
    Vehiculo* v4 = new Vehiculo("JKL012", "Mazda3", "Mazda", 'B', 'B');
    Vehiculo* v5 = new Vehiculo("MNO345", "Elantra", "Hyundai", 'A', 'B');
    Vehiculo* v6 = new Vehiculo("PQR678", "Jetta", "Volkswagen", 'B', 'B');
    Vehiculo* v7 = new Vehiculo("STU901", "Focus", "Ford", 'A', 'B');
    Vehiculo* v8 = new Vehiculo("VWX234", "Cruze", "Chevrolet", 'B', 'B');

    plantelA1->getListaVehiculos()->agregarVehiculo(v1);
    plantelA1->getListaVehiculos()->agregarVehiculo(v2);
    plantelA1->getListaVehiculos()->agregarVehiculo(v3);
    plantelA1->getListaVehiculos()->agregarVehiculo(v4);
    plantelA1->getListaVehiculos()->agregarVehiculo(v5);
    plantelA1->getListaVehiculos()->agregarVehiculo(v6);
    plantelA1->getListaVehiculos()->agregarVehiculo(v7);
    plantelA1->getListaVehiculos()->agregarVehiculo(v8);

    plantelA1->getEstacionamiento()->agregarVehiculoEnEspacio(v1, 0, 1); // A02
    plantelA1->getEstacionamiento()->agregarVehiculoEnEspacio(v2, 0, 3); // A04
    plantelA1->getEstacionamiento()->agregarVehiculoEnEspacio(v3, 1, 0); // A06
    plantelA1->getEstacionamiento()->agregarVehiculoEnEspacio(v4, 1, 2); // A08
    plantelA1->getEstacionamiento()->agregarVehiculoEnEspacio(v5, 2, 1); // A12
    plantelA1->getEstacionamiento()->agregarVehiculoEnEspacio(v6, 2, 4); // A15
    plantelA1->getEstacionamiento()->agregarVehiculoEnEspacio(v7, 3, 0); // A16
    plantelA1->getEstacionamiento()->agregarVehiculoEnEspacio(v8, 3, 3); // A19

    Plantel* plantelB1 = new Plantel('B', "Techado y lastreado", 15);
    sucursal1->getPlanteles()->agregarPlantel(plantelB1);

    Vehiculo* v9 = new Vehiculo("YZA567", "CR-V", "Honda", 'D', 'C');
    Vehiculo* v10 = new Vehiculo("BCD890", "RAV4", "Toyota", 'D', 'C');
    Vehiculo* v11 = new Vehiculo("EFG123", "Tucson", "Hyundai", 'C', 'C');
    Vehiculo* v12 = new Vehiculo("HIJ456", "Sportage", "Kia", 'C', 'C');
    Vehiculo* v13 = new Vehiculo("KLM789", "X5", "BMW", 'C', 'D');
    Vehiculo* v14 = new Vehiculo("NOP012", "Q7", "Audi", 'C', 'D');

    plantelB1->getListaVehiculos()->agregarVehiculo(v9);
    plantelB1->getListaVehiculos()->agregarVehiculo(v10);
    plantelB1->getListaVehiculos()->agregarVehiculo(v11);
    plantelB1->getListaVehiculos()->agregarVehiculo(v12);
    plantelB1->getListaVehiculos()->agregarVehiculo(v13);
    plantelB1->getListaVehiculos()->agregarVehiculo(v14);

    plantelB1->getEstacionamiento()->agregarVehiculoEnEspacio(v9, 0, 2);
    plantelB1->getEstacionamiento()->agregarVehiculoEnEspacio(v10, 0, 4); 
    plantelB1->getEstacionamiento()->agregarVehiculoEnEspacio(v11, 1, 1); 
    plantelB1->getEstacionamiento()->agregarVehiculoEnEspacio(v12, 1, 3); 
    plantelB1->getEstacionamiento()->agregarVehiculoEnEspacio(v13, 2, 0); 
    plantelB1->getEstacionamiento()->agregarVehiculoEnEspacio(v14, 2, 4); 

    Colaborador* colab1 = sucursal1->getColaboradores()->buscarColaboradorPorCed("101110111");
    Colaborador* colab2 = sucursal1->getColaboradores()->buscarColaboradorPorCed("202220222");

    Cliente* cliente1 = sucursal1->getClientes()->buscarClientePorCedula("111222333");
    Cliente* cliente2 = sucursal1->getClientes()->buscarClientePorCedula("444555666");
    Cliente* cliente3 = sucursal1->getClientes()->buscarClientePorCedula("777888999");
    Cliente* cliente4 = sucursal1->getClientes()->buscarClientePorCedula("123456789");

    Fecha* fechaInicio = Fecha::obtenerFechaActualPtr()->clonar();

    Fecha* fechaFin1 = fechaInicio->agregarDias(7);
    SoliAlquiyContra* contrato1 = new SoliAlquiyContra("CON001", cliente1, colab1, 1, "ABC123", 7, fechaInicio->clonar(), fechaFin1, v1->getPrecio());
    contrato1->cambiarEstadoSoli("Aprobada");
    sucursal1->getSolicitudes()->agregarSolicitud(contrato1);
    v1->cambiarEstado(1, colab1, fechaInicio->clonar());

    Fecha* fechaFin2 = fechaInicio->agregarDias(5);
    SoliAlquiyContra* solicitud1 = new SoliAlquiyContra("SOL001", cliente2, colab2, 1, "DEF456", 5, fechaInicio->clonar(), fechaFin2, v2->getPrecio());
    sucursal1->getSolicitudes()->agregarSolicitud(solicitud1);

    Fecha* fechaFin3 = fechaInicio->agregarDias(10);
    SoliAlquiyContra* contrato2 = new SoliAlquiyContra("CON002", cliente3, colab1, 1, "GHI789", 10, fechaInicio->clonar(), fechaFin3, v3->getPrecio());
    contrato2->cambiarEstadoSoli("Aprobada");
    sucursal1->getSolicitudes()->agregarSolicitud(contrato2);
    v3->cambiarEstado(1, colab1, fechaInicio->clonar());

    Fecha* fechaFin4 = fechaInicio->agregarDias(3);
    SoliAlquiyContra* solicitud2 = new SoliAlquiyContra("SOL002", cliente4, colab2, 1, "JKL012", 3, fechaInicio->clonar(), fechaFin4, v4->getPrecio());
    sucursal1->getSolicitudes()->agregarSolicitud(solicitud2);

    Fecha* fechaFin5 = fechaInicio->agregarDias(14);
    SoliAlquiyContra* contrato3 = new SoliAlquiyContra("CON003", cliente1, colab2, 1, "YZA567", 14, fechaInicio->clonar(), fechaFin5, v9->getPrecio());
    contrato3->cambiarEstadoSoli("Aprobada");
    sucursal1->getSolicitudes()->agregarSolicitud(contrato3);
    v9->cambiarEstado(1, colab2, fechaInicio->clonar()); 

    Fecha* fechaFin6 = fechaInicio->agregarDias(6);
    SoliAlquiyContra* solicitud3 = new SoliAlquiyContra("SOL003", cliente2, colab1, 1, "BCD890", 6, fechaInicio->clonar(), fechaFin6, v10->getPrecio());
    sucursal1->getSolicitudes()->agregarSolicitud(solicitud3);

    Fecha* fechaFin7 = fechaInicio->agregarDias(21);
    SoliAlquiyContra* contrato4 = new SoliAlquiyContra("CON004", cliente4, colab1, 1, "KLM789", 21, fechaInicio->clonar(), fechaFin7, v13->getPrecio());
    contrato4->cambiarEstadoSoli("Aprobada");
    sucursal1->getSolicitudes()->agregarSolicitud(contrato4);
    v13->cambiarEstado(1, colab1, fechaInicio->clonar()); 

    // Sucursal 2

    Sucursal* sucursal2 = control->getListaSucursales()->obtenerSucursal(2);

    sucursal2->agregarColaborador(new Colaborador("404440444", "Sofia Ramirez", Fecha::obtenerFechaActualPtr()->clonar()));
    sucursal2->agregarColaborador(new Colaborador("505550555", "Diego Castro", Fecha::obtenerFechaActualPtr()->clonar()));


    sucursal2->agregarCliente(new Cliente("555666777", "Laura Jimenez", "El Salvador"));
    sucursal2->agregarCliente(new Cliente("888999000", "Roberto Mora", "Honduras"));
    sucursal2->agregarCliente(new Cliente("987654321", "Transportes XYZ Ltda.", "Costa Rica", "Logistica", 0.20)); // Cliente jurídico 20%

    Plantel* plantelC2 = new Plantel('C', "Asfaltado", 18);
    sucursal2->getPlanteles()->agregarPlantel(plantelC2);

    Vehiculo* v15 = new Vehiculo("QRS345", "Accord", "Honda", 'B', 'B');
    Vehiculo* v16 = new Vehiculo("TUV678", "Camry", "Toyota", 'B', 'B');
    Vehiculo* v17 = new Vehiculo("WXY901", "Altima", "Nissan", 'B', 'B');
    Vehiculo* v18 = new Vehiculo("ZAB234", "Optima", "Kia", 'B', 'B');
    Vehiculo* v19 = new Vehiculo("CDE567", "Malibu", "Chevrolet", 'B', 'B');
    Vehiculo* v20 = new Vehiculo("FGH890", "Passat", "Volkswagen", 'B', 'C');
    Vehiculo* v21 = new Vehiculo("IJK123", "Fusion", "Ford", 'B', 'B');

    plantelC2->getListaVehiculos()->agregarVehiculo(v15);
    plantelC2->getListaVehiculos()->agregarVehiculo(v16);
    plantelC2->getListaVehiculos()->agregarVehiculo(v17);
    plantelC2->getListaVehiculos()->agregarVehiculo(v18);
    plantelC2->getListaVehiculos()->agregarVehiculo(v19);
    plantelC2->getListaVehiculos()->agregarVehiculo(v20);
    plantelC2->getListaVehiculos()->agregarVehiculo(v21);

    plantelC2->getEstacionamiento()->agregarVehiculoEnEspacio(v15, 0, 0); 
    plantelC2->getEstacionamiento()->agregarVehiculoEnEspacio(v16, 0, 3);
    plantelC2->getEstacionamiento()->agregarVehiculoEnEspacio(v17, 1, 1);
    plantelC2->getEstacionamiento()->agregarVehiculoEnEspacio(v18, 1, 4); 
    plantelC2->getEstacionamiento()->agregarVehiculoEnEspacio(v19, 2, 2); 
    plantelC2->getEstacionamiento()->agregarVehiculoEnEspacio(v20, 2, 5);
    plantelC2->getEstacionamiento()->agregarVehiculoEnEspacio(v21, 1, 5); 

    Plantel* plantelD2 = new Plantel('D', "Lastreado", 16);
    sucursal2->getPlanteles()->agregarPlantel(plantelD2);

    Vehiculo* v22 = new Vehiculo("LMN456", "Escape", "Ford", 'C', 'C');
    Vehiculo* v23 = new Vehiculo("OPQ789", "CX-5", "Mazda", 'C', 'C');
    Vehiculo* v24 = new Vehiculo("RST012", "Tiguan", "Volkswagen", 'C', 'C');
    Vehiculo* v25 = new Vehiculo("UVW345", "Grand Cherokee", "Jeep", 'D', 'D');
    Vehiculo* v26 = new Vehiculo("XYZ678", "4Runner", "Toyota", 'D', 'D');
    Vehiculo* v27 = new Vehiculo("AAA111", "Pilot", "Honda", 'C', 'C');

    plantelD2->getListaVehiculos()->agregarVehiculo(v22);
    plantelD2->getListaVehiculos()->agregarVehiculo(v23);
    plantelD2->getListaVehiculos()->agregarVehiculo(v24);
    plantelD2->getListaVehiculos()->agregarVehiculo(v25);
    plantelD2->getListaVehiculos()->agregarVehiculo(v26);
    plantelD2->getListaVehiculos()->agregarVehiculo(v27);

    plantelD2->getEstacionamiento()->agregarVehiculoEnEspacio(v22, 0, 1);
    plantelD2->getEstacionamiento()->agregarVehiculoEnEspacio(v23, 1, 0); 
    plantelD2->getEstacionamiento()->agregarVehiculoEnEspacio(v24, 1, 3); 
    plantelD2->getEstacionamiento()->agregarVehiculoEnEspacio(v25, 2, 2); 
    plantelD2->getEstacionamiento()->agregarVehiculoEnEspacio(v26, 3, 1); 
    plantelD2->getEstacionamiento()->agregarVehiculoEnEspacio(v27, 3, 3); 

    Colaborador* colab3 = sucursal2->getColaboradores()->buscarColaboradorPorCed("404440444");
    Colaborador* colab4 = sucursal2->getColaboradores()->buscarColaboradorPorCed("505550555");

    Cliente* cliente5 = sucursal2->getClientes()->buscarClientePorCedula("555666777");
    Cliente* cliente6 = sucursal2->getClientes()->buscarClientePorCedula("888999000");
    Cliente* cliente7 = sucursal2->getClientes()->buscarClientePorCedula("987654321");

    Fecha* fechaFin8 = fechaInicio->agregarDias(8);
    SoliAlquiyContra* contrato5 = new SoliAlquiyContra("CON005", cliente5, colab3, 2, "QRS345", 8, fechaInicio->clonar(), fechaFin8, v15->getPrecio());
    contrato5->cambiarEstadoSoli("Aprobada");
    sucursal2->getSolicitudes()->agregarSolicitud(contrato5);
    v15->cambiarEstado(1, colab3, fechaInicio->clonar());

    Fecha* fechaFin9 = fechaInicio->agregarDias(4);
    SoliAlquiyContra* solicitud4 = new SoliAlquiyContra("SOL004", cliente6, colab4, 2, "TUV678", 4, fechaInicio->clonar(), fechaFin9, v16->getPrecio());
    sucursal2->getSolicitudes()->agregarSolicitud(solicitud4);

    Fecha* fechaFin10 = fechaInicio->agregarDias(15);
    SoliAlquiyContra* contrato6 = new SoliAlquiyContra("CON006", cliente7, colab3, 2, "UVW345", 15, fechaInicio->clonar(), fechaFin10, v25->getPrecio());
    contrato6->cambiarEstadoSoli("Aprobada");
    sucursal2->getSolicitudes()->agregarSolicitud(contrato6);
    v25->cambiarEstado(1, colab3, fechaInicio->clonar()); 

    Fecha* fechaFin11 = fechaInicio->agregarDias(9);
    SoliAlquiyContra* solicitud5 = new SoliAlquiyContra("SOL005", cliente5, colab4, 2, "XYZ678", 9, fechaInicio->clonar(), fechaFin11, v26->getPrecio());
    sucursal2->getSolicitudes()->agregarSolicitud(solicitud5);
}