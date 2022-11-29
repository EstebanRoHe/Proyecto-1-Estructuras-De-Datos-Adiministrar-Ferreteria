#ifndef LISTASUCURSAL_H
#define LISTASUCURSAL_H
#include"nodoFerreteria.h"
#include <fstream>

class listaSucursal {
public:
	listaSucursal();
	virtual ~listaSucursal();
	virtual void agregarDato(Ferreteria*);
	virtual string eliminarElemento(string id);
	virtual bool empty();
	virtual string mostrarLista();
	virtual int buscarSucursal(string id);
	virtual void agregarSeccion(string id, Seccion *Dato, int opc);
	virtual int BuscarSeccion(string id, int numero);
	virtual void agregarProductoSeccion(string nombre, int numero ,pilaProducto *Dato, int opc);
	virtual string eliminarSeccion(string id, int numero);
	virtual string eliminarProducto(string id, int numero, string nombre);
	virtual string mostrarSecciones(string id);
	virtual string mostrarProductosSeccion(string id, int numero);
	virtual Producto* agregarDatoCarrito(string id, int numero, string nombre);
	virtual void cargarListaSucursal();
	virtual void guardarDatosSucursal();
	virtual void guardarDatosSeccion();
	virtual void guardarDatosCategoria();
	virtual void guardarArchivosPila();
	
	
private:
	nodoFerreteria *nodoCabeza;
};

#endif
