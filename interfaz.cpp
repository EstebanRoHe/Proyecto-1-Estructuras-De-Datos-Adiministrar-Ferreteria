#include "interfaz.h"

interfaz::interfaz() {
	LS= new listaSucursal();
	C= new caja();
}

interfaz::~interfaz ( ) {
	delete LS;
	delete C;
}
void interfaz::agregarSucursal ( ) {
	string id, ubicacion;
	cout<<"Ingrese el id de la nueva sucursal."<<endl;
	cin.get();
	getline(cin, id);
	cout<<"Ingrese la ubicacion de la nueva sucursal."<<endl;
	getline(cin, ubicacion);
	Ferreteria *F=new Ferreteria(id, ubicacion);
	LS->agregarDato(F);
}

void interfaz::agregarSeccion ( ) {
	string id, nombre;
	int opc;
	cout<<"Digite el id de la sucursal a la que desea ingresarle una seccion."<<endl;
	cin.get();
	getline(cin, id);
	int numero;
	if(LS->buscarSucursal(id) == 1){
		cout<<"Digite el numero de la nueva seccion. \n";
		cin>>numero;
		while(cin.fail()>>numero){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Error, usted no ha digitado un valor numerico, digite un valor numerico valido."<<endl;
			cin>>numero;
			
		}
		cout<<"Digite el nombre de la nueva seccion. \n";
		cin.get();
		getline(cin,nombre);
		cout<<"Digite que opcion desea de inserccion. \n";
		cout<<"1-Inserta al final. \n";
		cout<<"2-Inserta al principio. \n";
		cin>>opc;
		Seccion *S=new Seccion(numero, id+nombre);
		LS->agregarSeccion(id, S, opc);
	}else{
		cout<<"No se encontro sucursal con ese nombre. \n";
	}
	
}

void interfaz::agregarProducto( ) {
	string id, nombre;
	int numero, codigo, n, opc;
	cout<<LS->mostrarLista();
	cout<<"Digite el id de la sucursal a la que desea acceder. \n";
	cin.get();
	getline(cin, id);
	if(LS->buscarSucursal(id) == 1){
		cout<<LS->mostrarSecciones(id);
		cout<<"Digite el numero de la seccion a la cual desea agregarle un producto. \n";
		cin>>numero;
		while(cin.fail()>>numero){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Error, usted no ha digitado un valor numerico, digite un valor numerico valido. \n";
			cin>>numero;
		}
		if(LS->BuscarSeccion(id, numero) == 1){
			cout<<"Digite el nombre del producto que desea agregar. \n";
			cin.get();
			getline(cin,nombre);
			pilaProducto *pilaP = new pilaProducto(id+nombre);
			cout<<"Digite cuantos productos desea agregar. \n";
			cin>>n;
			while(cin.fail()>>n){
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Error, usted no ha digitado un valor numerico, digite un valor numerico valido."<<endl;
				cin>>n;
			}
			for(int i=0; i<n; i++){
				cout<<"Digite el codigo del producto. \n";
				cin>>codigo;
				while(cin.fail()>>codigo){
					cin.clear();
					cin.ignore(1000,'\n');
					cout<<"Error, usted no ha digitado un valor numerico, digite un valor numerico valido."<<endl;
					cin>>codigo;
					
				}
				Producto *P=new Producto(nombre, codigo);
				pilaP->llenarPila(P);
			}
			cout<<"Digite el tipo de insercion. \n";
			cout<<"1-Insertar al final. \n";
			cout<<"2-Insertar al principio. \n";
			cin>>opc;
			LS->agregarProductoSeccion(id, numero, pilaP, opc);
		}else{
			cout<<"No hay seccion con ese numero en la sucursal. \n";
		}
	}else{
		cout<<"No se encontro sucursal con ese nombre. \n";
	}
}

void interfaz::eliminarSucursal ( ) {
	string id;
	cout<<"Digite la sucursal que desea eliminar. \n"<<endl;
	cin.get();
	getline(cin, id);
	LS->eliminarElemento(id);
}

void interfaz::eliminarSeccion ( ) {
	string id;
	int numero;
	cout<<LS->mostrarLista();
	cout<<"Digite el id de la sucursal a la que le desea eliminar una seccion. \n"<<endl; 
	cin.get();
	getline(cin,id);
	if(LS->buscarSucursal(id) == 1){
		cout<<LS->mostrarSecciones(id);
		cout<<"Digite el numero de la seccion que desea eliminar. \n";
		cin>>numero;
		while(cin.fail()>>numero){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Error, usted no ha digitado un valor numerico, digite un valor numerico valido."<<endl;
			cin>>numero;
			
		}
		if(LS->BuscarSeccion(id, numero)){
			cout<<LS->eliminarSeccion(id, numero);
		}else{
			cout<<"No se encontro una seccion con ese numero en la sucursal. \n";
		}
	}else{
		cout<<"No hay sucursal con ese id. \n";
	}
}

void interfaz::eliminarProducto ( ) {
	string nombre, id;
	int numero, opc;
	cout<<LS->mostrarLista();
	cout<<"Digite la sucursual a la cual desea eliminarle un producto. \n";
	cin.get();
	getline(cin,id);
	if(LS->buscarSucursal(id) == 1){
		cout<<LS->mostrarSecciones(id);
		cout<<"Digite el numero de la seccion a la que desea eliminarle un producto. \n";
		cin>>numero;
		while(cin.fail()>>numero){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Error, usted no ha digitado un valor numerico, digite un valor numerico valido."<<endl;
			cin>>numero;
			
		}
		if(LS->BuscarSeccion(id, numero)){
			cout<<LS->mostrarProductosSeccion(id, numero);
			cout<<"Digite el nombre del producto a eliminar. \n";
			getline(cin,nombre);
			cout<<"Digite 1 si desea todas las unidades del producto o 2 si desea eliminar una cantidad de unindades espeficicas del producto. \n";
			cin>>opc;
			while(cin.fail()>>opc){
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Error, usted no ha digitado un valor numerico, digite un valor numerico valido."<<endl;
				cin>>opc;
				
			}
			if(opc ==1 ){
				cout<<LS->eliminarProducto(id, numero, nombre);
			}else{
				//falata eliminar n cantidad de producos
			}
		}else{
			cout<<"No se encontro una seccion con ese numero en la sucursal. \n";
		}
	}else{
		cout<<"No hay sucursal con ese id. \n";
	}
}

void interfaz::agregarDatoCarrito (string id, int numero, pilaCarrito *carrito) {
	string nombre;
	int opc;
	Producto *P= new Producto();
	do{
	cout<<"Digite el nombre del producto que desea agregar al carrito. \n";
	cin.get();
	getline(cin,nombre);
	P =LS->agregarDatoCarrito(id, numero, nombre);
	carrito->llenarPila(P);
	cout<<"Digite 1 si desea agregar otro producto o 0 para no. \n";
	cin>>opc;
	while(cin.fail()>>opc){
		cin.clear();
		cin.ignore(1000,'\n');
		cout<<"Error, usted no ha digitado un valor numerico, digite un valor numerico valido."<<endl;
		cin>>opc;
		
	}
	}while(opc ==1);
}

void interfaz::compra(pilaCarrito *carrito) {
	string id;
	int numero, opc, opc2;
	cout<<LS->mostrarLista();
	cout<<"Digite el id de sucursal que desea observar. \n";
	cin.get();
	getline(cin,id);
	do{
		if(LS->buscarSucursal(id)  == 1){
			cout<<LS->mostrarSecciones(id);
			cout<<"Digite el numero de la seccion que desea consultar. \n";
			cin>>numero;
			while(cin.fail()>>numero){
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Error, usted no ha digitado un valor numerico, digite un valor numerico valido."<<endl;
				cin>>numero;
				
			}
			if(LS->BuscarSeccion(id, numero) == 1){
				cout<<LS->mostrarProductosSeccion(id, numero);
			}else{
				cout<<"No hay seccion con ese numero. \n";
			}
			cout<<"Desea agregar un producto al carrito. \n";
			cout<<"Digite 1 para Si o cualquier numero para No. \n";
			cin>>opc;
			while(cin.fail()>>opc){
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Error, usted no ha digitado un valor numerico, digite un valor numerico valido."<<endl;
				cin>>opc;
				
			}
			if(opc == 1){
				agregarDatoCarrito(id, numero, carrito);
			}
		}else{
			cout<<"No hay sucursal con ese id. \n";
		}
		cout<<"Digite cualquier numero si desea consultar otra seccion o 0  para Salir. \n";
		cin>>opc2;
	}while(opc2!=0);
}


void interfaz::menuAdministrativo ( ) {
	int opc, numero;
	string nombre;
	do{
		cout<<"------SISTEMA ADMINISTRATIVO------ \n";
		cout<<"1-Registrar sucursal \n";
		cout<<"2-Registrar seccion \n";
		cout<<"3-Registrar producto \n";
		cout<<"4-Eliminar sucursal \n";
		cout<<"5-Eliminar seccion \n";
		cout<<"6-Eliminar producto \n";
		cout<<"7-Ver sucursales. \n";
		cout<<"8-ver secciones \n";
		cout<<"9-ver productos \n";
		cout<<"0-Salir. \n";
		cout<<"Digite la opcion que desea. \n";
		cin>>opc;
		while(cin.fail()>>opc){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Error, usted no ha digitado un valor numerico, digite un valor numerico valido."<<endl;
			cin>>opc;
		}
		switch(opc){
		case 1:{
			agregarSucursal();
			break;
		};
		case 2:{
			agregarSeccion();
			break;
		};
		case 3:{
			agregarProducto();
			break;
		};
		case 4:{
			eliminarSucursal();
			break;
		};
		case 5:{
			eliminarSeccion();
			break;
		};
		case 6:{
			eliminarProducto();
			break;
		};
		case 7:{
			cout<<LS->mostrarLista();
			break;
		};
		case 8:{
			cout<<LS->mostrarLista();
			cout<<"Digite el id de la sucursal. \n"<<endl;
			cin.get();
			getline(cin,nombre);
			cout<<LS->mostrarSecciones(nombre);
			break;
		};
		case 9:{
			cout<<"Digite el id de la sucursal \n";
			cin.get();
			getline(cin,nombre);
			if(LS->buscarSucursal(nombre) == 1){
				cout<<LS->mostrarSecciones(nombre);
				cout<<"Digite el numero de la seccion. \n";
				cin>>numero;
				cout<<LS->mostrarProductosSeccion(nombre,numero);
			}else{
				cout<<"No hay sucursal con ese id. \n";
			}
			break;
		};
			default :{
				cout<<"Opcion incorrecta digite otra \n";
				break;
			};
		}
	}while(opc != 0);
}

void interfaz::menuCliente ( ) {
	pilaCarrito *carrito = new pilaCarrito();
	int opc;
	do{
		cout<<"<<<<<<<FERRETERIA MARTILLAZO FELIZ>>>>>>> \n";
		cout<<"-----Digite la opcion que desea----- \n";
		cout<<"1-Realizar una compra. \n";
		cout<<"2-Ver poructos agregados en el carrito. \n";
		cout<<"0-Salir. \n";
		cin>>opc;
		while(cin.fail()>>opc){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Error, usted no ha digitado un valor numerico, digite un valor numerico valido."<<endl;
			cin>>opc;
		}
		switch(opc){
		case 1:{
			compra(carrito);
			break;
		};
		case 2:{
			cout<<carrito->toString();
			break;
		};
		case 3:{
			
			break;
		};
		default :{
			cout<<"Opcion incorrecta digite otra. \n";
			break;
		};
		}
	}while(opc != 0);
	C->ingresarCarrito(carrito);
}

void interfaz::menuCaja(){
	int opc;
	do{
		cout<<"|------- CAJA -------| \n\n";
		cout<<C->toString()<<"\n";
		cout<<"Digite la opcion que desea realizar. \n";
		cout<<"1-Cancelar carrito. \n";
		cout<<"2-Ver Facturas \n";
		cin>>opc;
		switch(opc){
		case 1:{
			if(!C->empty()){
				cout<<C->eliminarProductosCarrito();
				cout<<C->factura();
				C->eliminarCarrito();
			}else{
				cout<<"No hay carrito en la fila al que realizarle una facturacion. \n";
			}
			break;
		};
		case 2:{
			break;
		};
		default:{
			cout<<"Opcion incorrecta, digite otra. \n";
			break;
		}
		}
	}while(opc != 0);
	
}
void interfaz::Menu ( ) {
	int opc;
	LS->cargarListaSucursal();
	do{
	cout<<"<<<<<<< FERRETERIA EL MARTILLAZO FELIZ >>>>>>>\n";
	cout<<"Digite la opcion que desea realizar. \n";
	cout<<"1-Sistema admistrativo. \n";
	cout<<"2-Sistema compras. \n";
	cout<<"3-Caja. \n";
	cout<<"0-Salir \n";
	cin>>opc;
	switch(opc){
	case 1:{
		menuAdministrativo();
		break;
	};
	case 2:{
		menuCliente();
		break;
	};
	case 3:{
		menuCaja();
		break;
	};
	case 0:{
		cout<<"Saliendo... \n";
		break;
	};
	default:{
		cout<<"Opcion incorrecta digite otra. \n";
		break;
	};
	}
	}while(opc !=0);
	LS->guardarDatosSucursal();
	LS->guardarDatosSeccion();
	LS->guardarDatosCategoria();
	LS->guardarArchivosPila();
}










