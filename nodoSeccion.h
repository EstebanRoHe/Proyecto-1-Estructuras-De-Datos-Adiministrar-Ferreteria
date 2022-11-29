#ifndef NODOSECCION_H
#define NODOSECCION_H
#include "Seccion.h"
class nodoSeccion {
public:
	nodoSeccion(Seccion *Dato, nodoSeccion *siguiente, nodoSeccion *atras);
	virtual ~nodoSeccion();
	virtual void setDato(Seccion *Dato);
	virtual Seccion* getDato()const;
	virtual void setSig(nodoSeccion* siguiente);
	virtual nodoSeccion* getSig()const;
	virtual void setAtras(nodoSeccion* atras);
	virtual nodoSeccion* getAtras()const;
private:
	Seccion *Dato;
	nodoSeccion *siguiente;
	nodoSeccion *atras;
};

#endif

