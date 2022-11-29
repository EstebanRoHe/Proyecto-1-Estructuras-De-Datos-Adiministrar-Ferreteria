#include "Producto.h"

Producto::Producto (){
	Nombre="";
	Codigo=0;
	
}


Producto::Producto (string Nombre, int Codigo) : Nombre(Nombre), Codigo(Codigo){
	
}

Producto::~Producto ( ) {
	
}

string Producto::getNombre ( ) {
	return Nombre;
}

int Producto::getCodigo ( ) {
	return Codigo;
}

string Producto::toString(){
	stringstream x;
	x<<getNombre()<<" "<<getCodigo()<<endl;
	return x.str();
}
