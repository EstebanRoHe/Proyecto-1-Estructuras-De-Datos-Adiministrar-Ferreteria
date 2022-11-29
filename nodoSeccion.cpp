#include "nodoSeccion.h"

nodoSeccion::nodoSeccion(Seccion *Dato, nodoSeccion *siguiente = NULL, nodoSeccion *atras = NULL) : Dato(Dato), siguiente(siguiente), atras(atras){
	
}

nodoSeccion::~nodoSeccion(){
	
}

void nodoSeccion::setDato (Seccion * Dato) {
	this->Dato=Dato;
}

Seccion * nodoSeccion::getDato ( ) const {
	return Dato;
}

void nodoSeccion::setSig (nodoSeccion * siguiente) {
	this->siguiente=siguiente;
}

nodoSeccion * nodoSeccion::getSig ( ) const {
	return siguiente;
}

void nodoSeccion::setAtras (nodoSeccion * atras) {
	this->atras=atras;
}

nodoSeccion * nodoSeccion::getAtras ( ) const {
	return atras;
}
