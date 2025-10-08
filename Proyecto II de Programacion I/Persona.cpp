#include "Persona.h"
#include <iostream>
using namespace std;

Persona::Persona() : nombre(""), apellido(""), edad(0), cedula("") {}
Persona::~Persona() {}
string Persona::getNombre() const {
	return nombre;
}
string Persona::getApellido() const {
	return apellido;
}
string Persona::getCedula() const {
	return cedula;
}
int Persona::getEdad() const {
	return edad;
}
void Persona::setNombre(string nom) {
	nombre = nom;
}
void Persona::setApellido(string ape) {
	apellido = ape;
}
void Persona::setEdad(int ed) {
	edad = ed;
}
void Persona::setCedula(string ced) {
	cedula = ced;
}
