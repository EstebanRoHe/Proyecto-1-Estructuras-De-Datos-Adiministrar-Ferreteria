#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "listaSucursal.h"
#include "ListaSeccion.h"
#include "listaCategoria.h"
#include "caja.h"
#include "pilaCarrito.h"

class interfaz {
public:
	interfaz();
	virtual ~interfaz();
	virtual void agregarSucursal();
	virtual void agregarSeccion();
	virtual void agregarProducto();
	virtual void eliminarSucursal();
	virtual void eliminarSeccion();
	virtual void eliminarProducto();
	virtual void agregarDatoCarrito(string id, int numero, pilaCarrito *carrito);
	virtual void menuAdministrativo();
	virtual void menuCliente();
	virtual void Menu();
	virtual void compra(pilaCarrito *carrito);
	virtual void menuCaja();
private:
	listaSucursal *LS;
	caja *C;
};

#endif

