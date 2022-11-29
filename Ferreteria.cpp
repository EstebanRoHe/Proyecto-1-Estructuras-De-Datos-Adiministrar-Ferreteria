#include "Ferreteria.h"

Ferreteria::Ferreteria(string id, string ubicacion) :id(id), ubicacion(ubicacion), LS(new ListaSeccion()){
	
}

Ferreteria::~Ferreteria ( ) {
	
}

void Ferreteria::setid (string id) {
	this->id=id;
}

string Ferreteria::getid ( ) {
	return id;
}

void Ferreteria::setubicacion (string ubicacion) {
	this->ubicacion=ubicacion;
}

string Ferreteria::getubicacion ( ) {
	return ubicacion;
}

string Ferreteria::toString ( ) {
	stringstream x;
	x<<"Id sucursal: "<<getid()<<endl;
	x<<"Ubicacion: "<<getubicacion()<<endl;
	return x.str();
}

void Ferreteria::agregarSeccion(Seccion * Dato, int opc) {
	LS->tipoInsercion(Dato, opc);
}

void Ferreteria::agregarProductoSeccion(int numero, pilaProducto * Dato, int opc) {
	LS->agregarProducto(numero, Dato, opc);
}

int Ferreteria::buscarSeccion (int numero) {
	return LS->buscarSeccion(numero);
}

string Ferreteria::eliminarSeccion (int numero) {
	return LS->eliminarDato(numero);
}

string Ferreteria::eliminarProducto (int numero, string nombre) {
	return LS->eliminarProducto(numero, nombre);
}

string Ferreteria::mostrarSecciones ( ) {
	return LS->toString();
}

string Ferreteria::mostrarProductosSeccion (int numero) {
	return LS->mostrarProductosSeccion (numero);
}


Producto* Ferreteria::agregarDatoCarrito (int numero, string nombre) {
	return LS->agregarDatoCarrito(numero, nombre);
}

void Ferreteria::cargarListaSeccion (string archivoListaSeccion) {
	LS->cargarListaSeccion(archivoListaSeccion);
}


string Ferreteria::nombreSeccion ( ) {
	return LS->getNombre();
}

void Ferreteria::guardarListaSeccion (string nombreArchivo){
	LS->guardarListaSeccion(nombreArchivo);
}

void Ferreteria::guardarListaCategoria () {
	LS->guardarListaCategoria();
}

void Ferreteria::guardarArchivosPila ( ) {
	LS->guardarArchivoPila();
}
