#include "pilaProducto.h"

pilaProducto::pilaProducto (string Nombre): Nombre(Nombre){
}


pilaProducto::~pilaProducto ( ) {
	while(!pila.empty()){
		pila.pop();
	}
	
}

void pilaProducto::llenarPila ( Producto *P) {
	pila.push(*P);
}

string pilaProducto::toString( ) {
	stack<Producto> aux= pila;
	stringstream x;
	while(!aux.empty()){
		x<<aux.top().toString();
		aux.pop();
	}
	return x.str();
}

void pilaProducto::eliminarProducto ( ) {
	pila.pop();
}

string pilaProducto::getNombre ( ) {
	return Nombre;
}

string pilaProducto::mostrarDatosPila(){
	stringstream x;
	x<<getNombre()<<" cantidad: "<<pila.size()<<endl;
	return x.str();
}

Producto* pilaProducto::getDato ( ) {
	Producto *P= new Producto();
	*P=pila.top();
	pila.pop();
	
	return P;
}

bool pilaProducto::empty(){
	return pila.empty();
}

void pilaProducto::cargarPilaProducto (string archivoPilaProducto) {
	ifstream Archivo; 
	Archivo.open(archivoPilaProducto+".txt");
	if(!Archivo){
		cout<<"Error, no se pudo abrir el archivo. \n";
	}else{
		while(Archivo.good()){
			string Nombre;
			int Codigo;
			getline(Archivo, Nombre, ';');
			Archivo>>Codigo;
			Archivo.ignore();
			if(Nombre != ""){
				Producto *P= new Producto(Nombre, Codigo);
				pila.push(*P);
			}
		}
	}
	Archivo.close();
}

void pilaProducto::guardarPilaProducto (string archivoPilaProducto) {
	ofstream salidaC;
	salidaC.open(archivoPilaProducto+".txt", ios::out);
	while(!pila.empty()){
		salidaC<<pila.top().getNombre()<<";"
			<<pila.top().getCodigo()<<"\n";
		pila.pop();
	}

}






