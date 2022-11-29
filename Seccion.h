#ifndef SECCION_H
#define SECCION_H
#include <iostream>
#include <sstream>
#include "listaCategoria.h"
using namespace std;
class Seccion {
public:
	Seccion(int numero, string nombre);
	virtual ~Seccion();
	virtual void setnumero(int numero);
	virtual int getnumero();
	virtual void setnombre(string nombre);
	virtual string getnombre();
	virtual string toString();
	virtual void agregarProducto(pilaProducto *Dato, int opc);
	virtual string eliminarProducto(string nombre);
	virtual string mostrarProductosSeccion();
	virtual Producto* agregarDatoCarrito(string nombre);
	virtual void guardarListaCategoria(string nombreArchivo);
	virtual void guardarArchivoProducto();
	virtual void cargarListaCategoria(string nombreArchivo);
private:
	int numero;
	string nombre;
	listaCategoria *LC;
};

#endif

