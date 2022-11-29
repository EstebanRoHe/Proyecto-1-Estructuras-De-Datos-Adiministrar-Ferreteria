#ifndef LISTASECCION_H
#define LISTASECCION_H
#include "nodoSeccion.h"
#include <fstream>

class ListaSeccion {
public:
	ListaSeccion();
	~ListaSeccion();
	virtual string getNombre();
	virtual void insertarDatoUltimo(Seccion *Dato);
	virtual string toString();
	virtual string toStringAtras();
	virtual string eliminarDato(int numero);
	virtual void insertarDatoPrimero(Seccion *Dato);
	virtual int buscarSeccion(int numero);
	virtual void agregarProducto(int numero, pilaProducto *Dato, int opc);
	virtual string eliminarProducto(int numero, string nombre);
	virtual string mostrarProductosSeccion (int numero);
	virtual Producto* agregarDatoCarrito(int numero, string nombre);
	virtual void tipoInsercion(Seccion *Dato, int opc);
	virtual void cargarListaSeccion(string archivoListaSeccion);
	virtual void guardarListaSeccion(string nombreArchivo);
	virtual void guardarListaCategoria();
	virtual void guardarArchivoPila();
private:
	string Nombre;
	nodoSeccion *primero;
	nodoSeccion	*ultimo;
};

#endif

