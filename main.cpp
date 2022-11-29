#include<iostream>
#include "listaSucursal.h"
#include "ListaSeccion.h"
#include "listaCategoria.h"
#include "interfaz.h"
using namespace std;
int main (int argc, char *argv[]) {
	interfaz *I = new interfaz();
	I->Menu();
	
	delete I;
	return 0;
}

