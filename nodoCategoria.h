#ifndef NODOCATEGORIA_H
#define NODOCATEGORIA_H
#include "pilaProducto.h"
class nodoCategoria {
public:
	nodoCategoria(pilaProducto *Dato, nodoCategoria *siguiente, nodoCategoria *anterior);
	virtual ~nodoCategoria();
	virtual void setDato( pilaProducto *Dato);
	virtual pilaProducto* getDato()const;
	virtual void setSig(nodoCategoria* siguiente);
	virtual nodoCategoria* getSig()const;
	virtual void setatras(nodoCategoria* anterior);
	virtual nodoCategoria* getatras()const;
private:
	pilaProducto *Dato;
	nodoCategoria *siguiente;
	nodoCategoria *atras;
	
};

#endif

