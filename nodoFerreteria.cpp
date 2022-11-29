#include "nodoFerreteria.h"

nodoFerreteria::nodoFerreteria(Ferreteria* dato, nodoFerreteria* sig):Dato(dato),Sig(sig){
	
}

nodoFerreteria::~nodoFerreteria(){
	
}

void nodoFerreteria::setDato (Ferreteria *dato) {
	Dato=Dato;
}

Ferreteria * nodoFerreteria::getDato ( ) const {
	return Dato;
}

void nodoFerreteria::setSig (nodoFerreteria* sig) {
	Sig=sig;
}

nodoFerreteria * nodoFerreteria::getSig ( ) const {
	return Sig;
}
