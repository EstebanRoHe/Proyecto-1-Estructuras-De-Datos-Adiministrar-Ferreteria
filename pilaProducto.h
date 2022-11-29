#ifndef PILAPRODUCTO_H
#define PILAPRODUCTO_H
#include <stack>
#include "Producto.h"
#include <fstream>

using namespace std;
class pilaProducto {
public:
	pilaProducto(string Nombre);
	virtual ~pilaProducto();
	virtual void llenarPila(Producto *P);
	virtual string toString();
	virtual void eliminarProducto();
	virtual Producto* getDato();
	virtual string getNombre();
	virtual string mostrarDatosPila();
	virtual bool empty();
	virtual void cargarPilaProducto(string archivoPilaProducto);
	virtual void guardarPilaProducto(string archivoPilaProducto);
	
private:
	string Nombre;
	stack<Producto> pila;
};

#endif
