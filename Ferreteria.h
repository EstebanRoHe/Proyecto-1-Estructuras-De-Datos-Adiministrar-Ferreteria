#ifndef FERRETERIA_H
#define FERRETERIA_H
#include <iostream>
#include <sstream>
#include "ListaSeccion.h"
using namespace std;
class Ferreteria {
public:
	Ferreteria();
	Ferreteria(string id, string ubicacion);
	virtual ~Ferreteria();
	virtual void setid(string id);
	virtual string getid();
	virtual void setubicacion(string ubicacion);
	virtual string getubicacion();
	virtual string toString();
	virtual void agregarSeccion(Seccion *Dato, int opc);
	virtual void agregarProductoSeccion(int numero, pilaProducto *Dato, int opc);
	virtual int buscarSeccion(int numero);
	virtual string eliminarSeccion(int numero);
	virtual string eliminarProducto(int numero, string nombre);
	virtual string mostrarSecciones();
	virtual string mostrarProductosSeccion(int numero);
	virtual Producto* agregarDatoCarrito(int numero, string nombre);
	virtual void cargarListaSeccion(string archivoListaSeccion);
	virtual void guardarListaSeccion(string nombreArchivo);
	virtual void guardarListaCategoria();
	virtual string nombreSeccion();
	virtual void guardarArchivosPila();
private:
	string id;
	string ubicacion;
	ListaSeccion *LS;
};

#endif

