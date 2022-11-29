#ifndef LISTACATEGORIA_H
#define LISTACATEGORIA_H
#include "nodoCategoria.h"
#include <fstream>

class listaCategoria {
public:
	listaCategoria();
	virtual ~listaCategoria();
	virtual void insertarDatoUltimo(pilaProducto *Dato);
	virtual string toString();
	virtual void BuscarProducto(string nombre);
	virtual string eliminarDato(string nombre);
	virtual void insertarDatoPrimero(pilaProducto *Dato);
	virtual Producto* agregarDatoCarrito(string nombre);
	virtual void tipoInsercion(pilaProducto *Dato, int opc);
	virtual void cargarListaCategoria(string archivoListaCategoria);
	virtual void guardarListaCategoria(string nombreArchivo);
	virtual void guardarArchivoProducto();
private:
	nodoCategoria *primero;
	nodoCategoria *ultimo;
};

#endif
