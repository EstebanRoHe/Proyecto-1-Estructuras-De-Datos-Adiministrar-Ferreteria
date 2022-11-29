#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <sstream>

using namespace std;
class Producto {
public:
	Producto();
	Producto(string Nombre, int Codigo);
	virtual ~Producto();
	virtual string getNombre();
	virtual int getCodigo();
	virtual string toString();
private:
	string Nombre;
	int Codigo;
};

#endif
