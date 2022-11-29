#include "Seccion.h"

Seccion::Seccion (int numero, string nombre) : numero(numero), nombre(nombre), LC(new listaCategoria()){
	
}

Seccion::~Seccion ( ) {
	
}

void Seccion::setnumero (int numero) {
	this->numero=numero;
}

int Seccion::getnumero ( ) {
	return numero;
}

void Seccion::setnombre (string nombre) {
	this->nombre=nombre;
}

string Seccion::getnombre ( ) {
	return nombre;
}

string Seccion::toString ( ) {
	stringstream x;
	x<<getnumero()<<" "<<getnombre()<<endl;
	return x.str();
}

void Seccion::agregarProducto(pilaProducto *Dato, int opc) {
	LC->tipoInsercion(Dato, opc);
}

string Seccion::eliminarProducto (string nombre) {
	return LC->eliminarDato(nombre);
}

string Seccion::mostrarProductosSeccion ( ) {
	return LC->toString();
}

Producto* Seccion::agregarDatoCarrito (string nombre) {
	return LC->agregarDatoCarrito(nombre);
}

void Seccion::guardarListaCategoria (string nombreArchivo) {
	LC->guardarListaCategoria(nombreArchivo);
}

void Seccion::guardarArchivoProducto ( ) {
	LC->guardarArchivoProducto();
}

void Seccion::cargarListaCategoria (string nombreArchivo) {
	LC->cargarListaCategoria(nombreArchivo);
}

