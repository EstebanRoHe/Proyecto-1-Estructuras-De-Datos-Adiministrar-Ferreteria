#include "nodoCategoria.h"

nodoCategoria::nodoCategoria(pilaProducto *Dato, nodoCategoria *siguiente = NULL, nodoCategoria *atras = NULL) : Dato(Dato), siguiente(siguiente), atras(atras) {
	
}

nodoCategoria::~nodoCategoria(){
	
}

void nodoCategoria::setDato (pilaProducto * Dato) {
	this->Dato=Dato;
}

pilaProducto * nodoCategoria::getDato ( ) const {
	return Dato;
}

void nodoCategoria::setSig (nodoCategoria * siguiente) {
	this->siguiente=siguiente;
}

nodoCategoria * nodoCategoria::getSig ( ) const {
	return siguiente;
}

void nodoCategoria::setatras (nodoCategoria * atras) {
	this->atras=atras;
}

nodoCategoria* nodoCategoria::getatras ( ) const {
	return atras;
}
