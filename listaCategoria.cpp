#include "listaCategoria.h"

listaCategoria::listaCategoria() : primero(NULL), ultimo(NULL){
	
}

listaCategoria::~listaCategoria ( ) {
	
}

string listaCategoria::toString ( ) {
	stringstream x;
	nodoCategoria *actual;
	actual=primero;
	if(primero != NULL){
		while(actual !=NULL){
			x<<actual->getDato()->mostrarDatosPila()<<endl;
			actual=actual->getSig();
		}
	}else{
		x<<"Lista vacia"<<endl;
	}
	return x.str();
}

void listaCategoria::insertarDatoUltimo (pilaProducto * Dato) {
	nodoCategoria *nuevo= new nodoCategoria(Dato, primero, ultimo);
	if(primero == NULL){
		primero= nuevo;
		primero->setSig(NULL);
		primero->setatras(NULL);
		ultimo=nuevo;
	}else{
		ultimo->setSig(nuevo);
		nuevo->setSig(NULL);
		nuevo->setatras(ultimo);
		ultimo=nuevo;
	}
}

void listaCategoria::insertarDatoPrimero(pilaProducto *Dato){
	nodoCategoria *nuevo= new nodoCategoria(Dato, primero, ultimo);
	if(primero == NULL){
		primero= nuevo;
		primero->setSig(NULL);
		primero->setatras(NULL);
		ultimo=nuevo;
	}else{
		primero->setatras(nuevo);
		nuevo->setSig(primero);
		nuevo->setatras(NULL);
		primero=nuevo;
		
	}
}

void listaCategoria::BuscarProducto (string nombre) {
	nodoCategoria *actual;
	actual=primero;
	bool encontrado = false;
	if(primero  != NULL){
		while(actual !=NULL && !encontrado){
			if(actual->getDato()->getNombre() == nombre){
				cout<<actual->getDato()->toString();
				encontrado = true;
			}
			actual=actual->getSig();
		}
		if(!encontrado){
			cout<<"No hay dato con ese nombre"<<endl;
		}
	}else{
		cout << "\n La listas se encuentra Vacia\n";
	}
	
}


string listaCategoria::eliminarDato (string nombre) {
	stringstream x;
	nodoCategoria *actual;
	actual = primero;
	nodoCategoria *anterior;
	anterior = NULL;
	bool encontrado = false;
	if(primero !=NULL){
		while(actual!=NULL && !encontrado){
			if(actual->getDato()->getNombre() == nombre){
				if(anterior==NULL){
					primero=primero->getSig();
					actual->setSig(NULL);
					actual=primero;
				}else if(actual == primero){
					primero=primero->getSig();
					primero->setatras(NULL);
				}else if(actual == ultimo){
					anterior->setSig(NULL);
					ultimo=anterior;
				}else{
					anterior->setSig(actual->getSig());
					actual->getSig()->setatras(anterior);
				}
				x<<"Eliminado correctemente."<<endl;
				encontrado=true;
			}else{
				anterior=actual;
				actual=actual->getSig();
			};
		}
		if(!encontrado){
			x<<"No se encontro el dato"<<endl;
		}
	}else{
		x<<"Lista vacia"<<endl;
	}
	return x.str();
}

Producto* listaCategoria::agregarDatoCarrito (string nombre) {
	Producto *P= new Producto();
	nodoCategoria *actual;
	actual=primero;
	bool encontrado = false;
	if(primero  != NULL){
		while(actual !=NULL && !encontrado){
			if(actual->getDato()->getNombre() == nombre){
				if(!actual->getDato()->empty()){
					P=actual->getDato()->getDato();
					encontrado = true;
				}
			}
			actual=actual->getSig();
		}
	}
	return P;
}

void listaCategoria::tipoInsercion(pilaProducto * Dato, int opc ) {
	if(opc == 1){
		insertarDatoUltimo(Dato);
	}else{
		insertarDatoPrimero(Dato);
	}
}

void listaCategoria::cargarListaCategoria (string archivoListaCategoria) {
	ifstream Archivo;
	Archivo.open(archivoListaCategoria+".txt");
	if(Archivo){
		while(Archivo.good()){
			string Nombre;
			getline(Archivo, Nombre);
			//Archivo.ignore();
			if(Nombre !=""){
				pilaProducto *pila = new pilaProducto(Nombre);
				pila->cargarPilaProducto(Nombre);
				insertarDatoUltimo(pila);
			}
		}
	}
	Archivo.close();
}

void listaCategoria::guardarListaCategoria (string nombreArchivo) {
	ofstream salidaC;
	nodoCategoria *actual;
	actual=primero;
	salidaC.open(nombreArchivo+".txt", ios::out);
	while(actual != NULL){
		salidaC<<actual->getDato()->getNombre()<<"\n";
		actual=actual->getSig();
	}
	salidaC.close();
}

void listaCategoria::guardarArchivoProducto () {
	nodoCategoria *actual;
	actual=primero;
	while(actual != NULL){
		actual->getDato()->guardarPilaProducto(actual->getDato()->getNombre());
		actual=actual->getSig();
	}
}

