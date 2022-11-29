#include "listaSucursal.h"

listaSucursal::listaSucursal(){
	nodoCabeza = NULL;
}

listaSucursal::~listaSucursal ( ) {
	nodoFerreteria *n=nodoCabeza;
	nodoFerreteria *aux;
	while(n != NULL){
		aux = n->getSig();
		delete n;
		n=aux;
	}
	nodoCabeza = NULL;
}

void listaSucursal::agregarDato (Ferreteria* Dato) {
	nodoCabeza= new nodoFerreteria(Dato, nodoCabeza);
}

string listaSucursal::eliminarElemento (string id) {
	stringstream x;
	bool encontrado = false;
	if(!empty()){
		nodoFerreteria *actual = nodoCabeza;
		nodoFerreteria *aux;
		if(nodoCabeza->getDato()->getid() == id){
			aux = nodoCabeza;
			nodoCabeza = nodoCabeza->getSig();
			delete aux;
			x<<"Se elimino correctamente. \n";
			encontrado=true;
		}else{
			while(actual->getSig() != NULL && !encontrado){
				if(actual->getSig()->getDato()->getid() == id){
					aux=actual->getSig();
					actual->setSig(aux->getSig());
					delete aux;
					x<<"Se elimino correctamente. \n";
					encontrado=true;
				}else{
					actual=actual->getSig();
				}
			}
		}
	}else{
		x<<"La lista esta vacia. \n";
	}
	if(!encontrado){
		x<<"No se encontro la sucursal digitada. \n";
	}
	return x.str();
}

bool listaSucursal::empty ( ) {
	return nodoCabeza == NULL;
}

string listaSucursal::mostrarLista ( ) {
	stringstream x;
	nodoFerreteria *actual;
	actual=nodoCabeza;
	if(!empty()){
		while(actual!=NULL){
			x<<actual->getDato()->toString();
			actual=actual->getSig();
		}
	}else{
		x<<"Lista vacia."<<endl;
	}
	return x.str();
}

int listaSucursal::buscarSucursal (string id) {
	nodoFerreteria *actual;
	actual=nodoCabeza;
	bool encontrado=false;
		while(actual!=NULL && !encontrado){
			if(actual->getDato()->getid() == id){
				encontrado=true;
			}
			actual=actual->getSig();
		}
		if(encontrado){
			return 1;
		}else{
			return 0;
		}
}

void listaSucursal::agregarSeccion(string id, Seccion * Dato, int opc) {
	nodoFerreteria *actual;
	actual=nodoCabeza;
	bool encontrado=false;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getid() == id){
			encontrado=true;
			actual->getDato()->agregarSeccion(Dato, opc);
		}
		actual=actual->getSig();
	}
}

int listaSucursal::BuscarSeccion (string id, int numero) {
	nodoFerreteria *actual;
	actual=nodoCabeza;
	bool encontrado=false;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getid() == id && actual->getDato()->buscarSeccion(numero) == 1 ){
			encontrado=true;
		}
		actual=actual->getSig();
	}
	if(encontrado){
		return 1;
	}else{
		return 0;
	}
}

void listaSucursal::agregarProductoSeccion (string id, int numero ,pilaProducto *Dato, int opc) {
	nodoFerreteria *actual;
	actual=nodoCabeza;
	bool encontrado=false;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getid() == id){
			encontrado=true;
			actual->getDato()->agregarProductoSeccion(numero, Dato, opc);
		}
		actual=actual->getSig();
	}
}

string listaSucursal::eliminarSeccion (string id, int numero) {
	nodoFerreteria *actual;
	actual=nodoCabeza;
	string x;
	bool encontrado=false;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getid() == id){
			x = actual->getDato()->eliminarSeccion(numero);
			encontrado=true;
		}
		actual=actual->getSig();
	}
	return x;
}

string listaSucursal::eliminarProducto (string id, int numero, string nombre) {
	nodoFerreteria *actual;
	actual=nodoCabeza;
	string x;
	bool encontrado=false;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getid() == id){
			x = actual->getDato()->eliminarProducto(numero, nombre);
			encontrado=true;
		}
		actual=actual->getSig();
	}
	return x;
}

string listaSucursal::mostrarSecciones (string id) {
	nodoFerreteria *actual;
	actual=nodoCabeza;
	string x;
	bool encontrado=false;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getid() == id){
			x = actual->getDato()->mostrarSecciones ( );
			encontrado=true;
		}
		actual=actual->getSig();
	}
	if(!encontrado){
		x="No hay sucursal con ese id. \n";
	}
	return x;
}

string listaSucursal::mostrarProductosSeccion (string id, int numero) {
	nodoFerreteria *actual;
	actual=nodoCabeza;
	string x;
	bool encontrado=false;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getid() == id){
			x = actual->getDato()->mostrarProductosSeccion(numero);
			encontrado=true;
		}
		actual=actual->getSig();
	}
	if(!encontrado){
		x="No hay seccion con ese numero. \n";
	}
	return x;
}

Producto* listaSucursal::agregarDatoCarrito (string id, int numero, string nombre) {
	Producto *P= new Producto();
	nodoFerreteria *actual;
	actual=nodoCabeza;
	string x;
	bool encontrado=false;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getid() == id){
			P = actual->getDato()->agregarDatoCarrito(numero, nombre);
			encontrado=true;
		}
		actual=actual->getSig();
	}
	return P;
}

void listaSucursal::cargarListaSucursal ( ) {
	ifstream Archivo;
	Archivo.open("Lista Sucursales.txt");
	if(!Archivo){
		cout<<"Error, no se pudo abrir el archivo. \n";
	}else{
		while(Archivo.good()){
			string id, ubicacion;
			getline(Archivo, id, ';');
			getline(Archivo, ubicacion, ';');
			Archivo.ignore(); 
			if(id != ""){
				Ferreteria *F = new Ferreteria(id, ubicacion);
				F->cargarListaSeccion(id);
				agregarDato(F);
			}
		}
	}
	Archivo.close();
}

void listaSucursal::guardarDatosSucursal ( ) {
	ofstream salidaC;
	nodoFerreteria *actual;
	actual=nodoCabeza;
	salidaC.open("Lista Sucursales.txt", ios::out);
	while(actual != NULL){
		salidaC<<actual->getDato()->getid()<<";"
				<<actual->getDato()->getubicacion()<<";"
				<<"\n";
		actual=actual->getSig();
	}
	salidaC.close();
}

void listaSucursal::guardarDatosSeccion ( ) {
	nodoFerreteria *actual;
	actual=nodoCabeza;
	while(actual!=NULL){
		actual->getDato()->guardarListaSeccion(actual->getDato()->getid());
		actual=actual->getSig();
	}
}

void listaSucursal::guardarDatosCategoria () {
	nodoFerreteria *actual;
	actual=nodoCabeza;
	while(actual!=NULL){
		actual->getDato()->guardarListaCategoria();
		actual=actual->getSig();
	}
}

void listaSucursal::guardarArchivosPila ( ) {
	nodoFerreteria *actual;
	actual=nodoCabeza;
	while(actual!=NULL){
		actual->getDato()->guardarArchivosPila( );
		actual=actual->getSig();
	}
}






