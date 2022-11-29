#ifndef NODOFERRETERIA_H
#define NODOFERRETERIA_H
#include "Ferreteria.h"

class nodoFerreteria {
public:
	nodoFerreteria(Ferreteria* , nodoFerreteria* );
	virtual ~nodoFerreteria();
	virtual void setDato(Ferreteria *Dato);
	virtual Ferreteria* getDato()const;
	virtual void setSig(nodoFerreteria* Sig);
	virtual nodoFerreteria* getSig()const;
	
private:
	Ferreteria *Dato;
	nodoFerreteria *Sig;
};

#endif


