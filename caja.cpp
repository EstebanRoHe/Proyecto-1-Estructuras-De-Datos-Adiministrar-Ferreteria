#include "caja.h"

caja::caja() {
	
}

caja::~caja ( ) {
	while(!colaCaja.empty()){
		colaCaja.pop();
	}
}

void caja::ingresarCarrito (pilaCarrito * carrito) {
	colaCaja.push(*carrito);
}

void caja::eliminarCarrito ( ) {
	colaCaja.pop();
}

bool caja::empty ( ) {
	return colaCaja.empty();
}

string caja::factura(){
	time_t now=time(0);
	char *dt=ctime(&now);
	stringstream x;
	x<<"<<<<<<FACTURA>>>>>>"<<"\n";
	x<<"Fecha: "<<dt<<"\n";
	x<<"Cantidad productos: "<<colaCaja.front().cantProductos()<<"\n";
	x<<"Lista de productos comprados: \n";
	x<<colaCaja.front().toString();
	return x.str();
}

string caja::toString(){
	stringstream x;
	x<<"  ---Fila carritos---"<<endl;
	if(!empty()){
		int cant=colaCaja.size();
		for(int i=1; i<=cant; i++){
			x<<i<<"-Carrito \n\n";
		}
	}else{
		x<<"Sin carritos en fila \n";
	}
	return x.str();
}

string caja::eliminarProductosCarrito ( ) {
	stringstream x;
	queue<pilaCarrito> aux= colaCaja;
	while(!aux.front().empty()){
		x<<"Eliminando el producto :";
		x<<aux.front().eliminarProducto()<<"\n";
	}
	if(aux.front().empty()){
		x<<"Todos los productos del carrtio han sido eliminados. \n";
	}
	return x.str();
}





