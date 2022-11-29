#ifndef PILACARRITO_H
#define PILACARRITO_H
#include <stack>
#include "Producto.h"

class pilaCarrito {
public:
	pilaCarrito();
	virtual ~pilaCarrito();
	virtual void llenarPila(Producto *Dato);
	virtual string toString();
	virtual string eliminarProducto();
	virtual int cantProductos();
	virtual bool empty();
private:
	stack<Producto> carrito;
};

#endif

