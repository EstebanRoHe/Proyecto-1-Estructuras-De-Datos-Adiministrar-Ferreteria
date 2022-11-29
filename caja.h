#ifndef CAJA_H
#define CAJA_H
#include <queue>
#include "pilaCarrito.h"
#include <ctime>

class caja {
public:
	caja();
	virtual ~caja();
	virtual void ingresarCarrito(pilaCarrito *carrito);
	virtual void eliminarCarrito();
	virtual bool empty();
	virtual string factura();
	virtual string toString();
	virtual string eliminarProductosCarrito();
	
private:
	queue<pilaCarrito> colaCaja;
};

#endif
