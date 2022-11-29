#include "pilaCarrito.h"

pilaCarrito::pilaCarrito (){
}


pilaCarrito::~pilaCarrito ( ) {
	while(!carrito.empty()){
		carrito.pop();
	}
}

void pilaCarrito::llenarPila ( Producto *Dato) {
	carrito.push(*Dato);
}

string pilaCarrito::toString( ) {
	stack<Producto> aux= carrito;
	stringstream x;
	if(!aux.empty()){
		while(!aux.empty()){
			x<<aux.top().toString();
			aux.pop();
		}
	}else{
		x<<"No se ha agregado ningun dato al carrito. \n";	
	}
	return x.str();
}

string pilaCarrito::eliminarProducto(){
	string x;
	x=carrito.top().toString();
	carrito.pop();
	return x;
	
}

int pilaCarrito::cantProductos ( ) {
	return carrito.size();
}

bool pilaCarrito::empty ( ) {
	return carrito.empty();
}
