#include "ListaSeccion.h"

ListaSeccion::ListaSeccion() : primero(NULL), ultimo(NULL) {
	
}

string ListaSeccion::getNombre ( ) {
	return Nombre;
}


ListaSeccion::~ListaSeccion(){
	//agregar codigo del destructor
	
}

void ListaSeccion::insertarDatoUltimo(Seccion *Dato){
	nodoSeccion *nuevo=new nodoSeccion(Dato, primero, ultimo);
	if(primero == NULL){
		primero=nuevo;
		ultimo=nuevo;
		primero->setSig(primero);
		primero->setAtras(ultimo);
	}else{
		ultimo->setSig(nuevo);
		nuevo->setAtras(ultimo);
		nuevo->setSig(primero);
		ultimo=nuevo;
		primero->setAtras(ultimo);
	}
}

void ListaSeccion::insertarDatoPrimero(Seccion *Dato){
	nodoSeccion *nuevo=new nodoSeccion(Dato, primero, ultimo);
	if(primero == NULL){
		primero=nuevo;
		ultimo=nuevo;
		primero->setSig(primero);
		primero->setAtras(ultimo);
	}else{
		primero->setAtras(nuevo);
		nuevo->setSig(primero);
		nuevo->setAtras(ultimo);
		primero=nuevo;
		ultimo->setSig(primero);
	};
	
}
string ListaSeccion::toString(){
	stringstream x;
	nodoSeccion *actual;
	actual=primero;
	if(primero!=NULL){
		do{
			x<<actual->getDato()->toString()<<endl;
			actual=actual->getSig();
		} while(actual!=primero);
	}else{
		x<<"Lista vacia."<<endl;
	}
	return x.str();
}

string ListaSeccion::toStringAtras(){
	stringstream x;
	nodoSeccion *actual;
	actual=ultimo;
	if(primero!=NULL){
		do{
			x<<actual->getDato()->toString()<<endl;
			actual=actual->getAtras();
		} while(actual!=ultimo);
	}else{
		x<<"Lista vacia."<<endl;
	}
	return x.str();
}

string ListaSeccion::eliminarDato (int numero) {
	stringstream x;
	nodoSeccion *actual;
	actual=primero;
	nodoSeccion *anterior;
	anterior=NULL;
	bool encontrado=false;
	if(primero!=NULL){
		while(actual!=NULL && !encontrado){
			if(actual->getDato()->getnumero() == numero){
				if(primero == ultimo ){
					primero=NULL;
				}else if(actual == primero){
					primero=primero->getSig();
					primero->setAtras(ultimo);
					ultimo->setSig(primero);
				}else if(actual == ultimo){
					ultimo=anterior;
					ultimo->setSig(primero);
					primero->setAtras(ultimo);
				}else{
					anterior->setSig(actual->getSig());
					actual->getSig()->setAtras(anterior);
				}
				x<<"Eliminado"<<endl;
				encontrado = true;
			}else{
				anterior=actual;
				actual=actual->getSig();
			}
		};
		if(!encontrado){
			x<<"no se encontro el dato"<<endl;
		};
	}else{
		x<<"lista vacia"<<endl;
	}
	return x.str();
}

int ListaSeccion::buscarSeccion (int numero) {
	nodoSeccion *actual;
	actual = primero;
	bool encontrado=false;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getnumero() == numero){
			encontrado=true;
		}else{
			actual=actual->getSig();
		}
	}
	if(encontrado){
		return 1;
	}else{
		return 0;
	}
}

void ListaSeccion::agregarProducto(int numero, pilaProducto * Dato, int opc) {
	nodoSeccion *actual;
	actual = primero;
	bool encontrado=false;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getnumero() == numero){
			encontrado=true;
			actual->getDato()->agregarProducto(Dato, opc);
		}else{
			actual=actual->getSig();
		}
	}
}

string ListaSeccion::eliminarProducto (int numero, string nombre) {
	nodoSeccion *actual;
	actual = primero;
	bool encontrado=false;
	string x;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getnumero() == numero){
			encontrado=true;
			x=actual->getDato()->eliminarProducto(nombre);
		}else{
			actual=actual->getSig();
		}
	}
	return x;
}

string ListaSeccion::mostrarProductosSeccion (int numero) {
	nodoSeccion *actual;
	actual = primero;
	bool encontrado=false;
	string x;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getnumero() == numero){
			encontrado=true;
			x=actual->getDato()->mostrarProductosSeccion();
		}else{
			actual=actual->getSig();
		}
	}
	if(!encontrado){
		x="No hay seccion con ese id. \n";
	}
	return x;
}

Producto* ListaSeccion::agregarDatoCarrito (int numero, string nombre) {
	nodoSeccion *actual;
	Producto *P = new Producto();
	actual = primero;
	bool encontrado=false;
	string x;
	while(actual!=NULL && !encontrado){
		if(actual->getDato()->getnumero() == numero){
			encontrado=true;
			P=actual->getDato()->agregarDatoCarrito(nombre);
		}else{
			actual=actual->getSig();
		}
	}
	return P;
}

void ListaSeccion::tipoInsercion (Seccion * Dato, int opc) {
	if(opc == 1){
		insertarDatoUltimo(Dato);
	}else{
		insertarDatoPrimero(Dato);
	}
}

void ListaSeccion::cargarListaSeccion (string archivoListaSeccion) {
	ifstream Archivo;
	Archivo.open(archivoListaSeccion+".txt");
	if(!Archivo){
		cout<<"Error, no se pudo abrir el archivo de seccion. \n";
	}else{
		while(Archivo.good()){
			string nombre;
			int numero;
			getline(Archivo, nombre, ';');
			Archivo>>numero;
			Archivo.ignore();
			if(nombre !=""){
				Seccion *S = new Seccion(numero,nombre);
				S->cargarListaCategoria(nombre);
				insertarDatoUltimo(S);
			};
		}
	}
	Archivo.close();
}

void ListaSeccion::guardarListaSeccion (string nombreArchivo ) {
	ofstream salidaC;
	nodoSeccion *actual;
	actual=primero;
	salidaC.open(nombreArchivo+".txt", ios::out);
	while(actual!=NULL){
		salidaC<<actual->getDato()->getnombre()<<";"
				<<actual->getDato()->getnumero()<<endl;
		if(actual == ultimo){
			break;
		}
		actual=actual->getSig();
	}
	salidaC.close();
}

void ListaSeccion::guardarListaCategoria () {
	nodoSeccion *actual;
	actual=primero;
	while(actual!=NULL){
		actual->getDato()->guardarListaCategoria(actual->getDato()->getnombre());
		if(actual == ultimo){
			break;
		}
		actual=actual->getSig();
	}
}

void ListaSeccion::guardarArchivoPila ( ) {
	nodoSeccion *actual;
	actual=primero;
	while(actual!=NULL){
		actual->getDato()->guardarArchivoProducto();
		if(actual == ultimo){
			break;
		}
		actual=actual->getSig();
	}
}










