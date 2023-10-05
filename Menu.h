//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos

#include <iostream>
#include "ArbolPais.h"
#include "ArbolClientes.h"
#include "cola.h"
#include <cstdlib>
#include <string.h>


using namespace std;



class Menu {
	public:
		
		Menu ()
		{
			baseDeDatos.leeDocPais();
			baseDeDatos.leerDocCiudad();
			baseDeDatos.leeDocRest();
			baseDeDatos.leeDocMenu();
			baseDeDatos.leeDocProducto();
			clientes.leerDocCliente();
			
//			baseDeDatos.imprimir_Arbol_Ventas();
//			cout<<endl<<endl;
//			system("pause");
		}
		//Menu
		void lecturaArchivos();
		void menu();
		void insertar();
//		void eliminar();
		void buscar();
		void modificar();
		void reportes();
		void comprar();
		
		//Insertar
		void insertarPais();
		void insertarCiudad();
		void insertarRest();
		void insertarMenu();
		void insertarProducto();
		void insertarCliente();
		
		//Buscar
		void buscarPais();
		void buscarCiudad();
		void buscarRest();
		void buscarMenu();
		void buscarProducto();
		void buscarClientes();
		
		//Modificar
		void modificarPais();
		void modificarCiudad();
		void modificarRest();
		void modificarMenu();
		void modificarProducto();
		void modificarCliente();
		void modificarCompra();
		
		//Reportes
		void reportarPais();
		void reportarCiudad();
		void reportarRest();
		void reportarCliente();
		void reportarRestMasBuscado();
		void reportarPrecio();
		
		//Extra
		bool desicion(bool bandera);
		void guardarEnArchivo(string nombreArchivo, string texto);

	private:
		ArbolPais baseDeDatos;
		ArbolClientes clientes;
//		listaClientes clientes; //lista de clientes
		cola colaClientes;
};

void Menu::insertarPais(){
	system("cls");
	cout<<"****************************** INSERTAR PAIS ******************************"<<endl;
	cout<<endl<<"Ingrese el codigo del pais a agregar: ";
	
	int codPais;
	string nombre;
	
	cin>>codPais;
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if (nodoPais==NULL){
		cout<<endl<<"Ingrese el nombre del pais a agregar: ";
		cin.ignore();
		getline(cin,nombre);
		baseDeDatos.insertPais(codPais, nombre);
		system("cls");
		cout<< baseDeDatos.imprimir_Pais();
		cout<<endl<<endl<<"Se ha insertado el pais."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo ya se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::insertarCiudad(){
	system("cls");
	cout<<"****************************** INSERTAR CIUDAD ******************************"<<endl<<endl;
	cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais que quiere insertar una ciudad: ";
	
	int codPais;
	string nombre;
	cin>>codPais;
	cout<<endl;
	
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<endl<<"Ingrese el codigo de la ciudad a agregar: ";
	int codCiudad;
	cin>>codCiudad;
	
	pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if (nodoCiudad==NULL){
		cout<<endl<<"Ingrese el nombre de la ciudad a agregar: ";
		cin.ignore();
		getline(cin,nombre);
		baseDeDatos.insertCiudad (codPais,codCiudad, nombre);
		system("cls");
		cout<<baseDeDatos.imprimir_Ciudad (codPais);
		cout<<endl<<endl<<"Se ha insertado la ciudad."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo ya se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::insertarRest(){
	system("cls");
	cout<<"****************************** INSERTAR RESTAURANTE ******************************"<<endl<<endl;
	cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais que quiere insertar un restaurante: ";
	
	int codPais;
	string nombre;
	cin>>codPais;
	cout<<endl;
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->getCiudad()==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<baseDeDatos.imprimir_Ciudad (codPais);
	
	cout<<endl<<endl<<"Ingrese el codigo de la ciudad que quiere insertar un restaurante: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<endl<<"Ingrese el codigo del restaurante a agregar: ";
	int codRest;
	cin>>codRest;
	bool bandera= nodoCiudad->getRest()->verificarMarca (false, codRest);
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais,codCiudad,codRest);
	if (bandera==false){
		cout<<endl<<"Ingrese el nombre del restaurante a agregar: ";
		cin.ignore();
		getline(cin,nombre);
		baseDeDatos.insertRest (codPais, codCiudad, codRest, nombre);
		system("cls");
		cout<<baseDeDatos.imprimir_Rest (codPais,codCiudad);
		cout<<endl<<endl<<"Se ha insertado el restaurante."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo ya se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::insertarMenu(){
	system("cls");
	cout<<"****************************** INSERTAR MENU ******************************"<<endl<<endl;
	cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais que quiere insertar un menu: ";
	
	int codPais;
	string nombre;
	cin>>codPais;
	cout<<endl;
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->getCiudad()==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	cout<<baseDeDatos.imprimir_Ciudad (codPais);
	
	cout<<endl<<endl<<"Ingrese el codigo de la ciudad que quiere insertar un menu: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	if (nodoCiudad->getRest ()==NULL){
		cout<<endl<<"No hay restaurantes registrados."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	cout<<baseDeDatos.imprimir_Rest ( codPais, codCiudad);
	
	cout<<endl<<endl<<"Ingrese el codigo del restaurante que quiere insertar un menu: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais, codCiudad,codRest);
	if(nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	cout<<endl<<"Ingrese el codigo del menu a agregar: ";
	int codMenu;
	cin>>codMenu;
	
	pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais,codCiudad,codRest,codMenu);
	if (nodoMenu==NULL){
		cout<<endl<<"Ingrese el nombre del menu a agregar: ";
		cin.ignore();
		getline(cin,nombre);
		baseDeDatos.insertMenu(codPais,codCiudad,codRest,codMenu, nombre);
		system("cls");
		cout<<baseDeDatos.imprimir_Menu (codPais, codCiudad, codRest);
		cout<<endl<<endl<<"Se ha insertado el menu."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo ya se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::insertarProducto(){
	system("cls");
	cout<<"****************************** INSERTAR PRODUCTO ******************************"<<endl<<endl;
	cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais que quiere insertar un producto: ";
	
	int codPais;
	string nombre;
	cin>>codPais;
	cout<<endl;
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->getCiudad()==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	cout<<baseDeDatos.imprimir_Ciudad (codPais);
	
	cout<<endl<<endl<<"Ingrese el codigo de la ciudad que quiere insertar un producto: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	if (nodoCiudad->getRest ()==NULL){
		cout<<endl<<"No hay restaurantes registrados."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	cout<<baseDeDatos.imprimir_Rest ( codPais, codCiudad);
	
	cout<<endl<<endl<<"Ingrese el codigo del restaurante que quiere insertar un producto: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais, codCiudad,codRest);
	if(nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoRest->getMenu ()==NULL){
		cout<<endl<<"No hay menus registrados."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	cout<<baseDeDatos.imprimir_Menu ( codPais, codCiudad, codRest);
	
	cout<<endl<<endl<<"Ingrese el codigo del menu que quiere insertar un producto: ";
	int codMenu;
	cin>>codMenu;
	pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais, codCiudad,codRest,codMenu);
	if(nodoMenu==NULL){
		cout<<endl<<"Menu Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	cout<<endl<<"Ingrese el codigo del producto a agregar: ";
	int codProd;
	cin>>codProd;
	
	pnodoProducto nodoProd = baseDeDatos.buscarProducto(codPais,codCiudad,codRest,codMenu, codProd);
	if (nodoProd==NULL){
		int kcal, precio, cantidad;
		cout<<endl<<"Ingrese el nombre del producto a agregar: ";
		cin.ignore();
		getline(cin,nombre);
		cout<<endl<<endl<<"Ingrese las calorias del producto a agregar: ";
		cin>>kcal;
		cout<<endl<<endl<<"Ingrese el precio del producto a agregar: ";
		cin>>precio;
		cout<<endl<<endl<<"Ingrese la cantidad del producto a agregar: ";
		cin>>cantidad;
		baseDeDatos.insertProducto(codPais,codCiudad,codRest,codMenu, codProd, nombre, kcal, precio, cantidad);
		system("cls");
		baseDeDatos.imprimir_Producto (codPais,codCiudad, codRest, codMenu);
		cout<<endl<<endl<<"Se ha insertado el producto."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo ya se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::insertarCliente(){
	system("cls");
	cout<<"****************************** INSERTAR CLIENTE ******************************"<<endl;
	cout<<endl<<"Ingrese la cedula del cliente a agregar: ";
	
	int cedula;
	string nombre;
	
	cin>>cedula;
	puntero_Cliente Pagina_Cliente = clientes.buscarCliente(cedula);
	if (Pagina_Cliente==NULL){
		cout<<endl<<"Ingrese el nombre del cliente a agregar: ";
		cin.ignore();
		getline(cin,nombre);
		clientes.inserta(cedula, nombre);
		system("cls");
		clientes.imprimir_Arbol();
		cout<<endl<<endl<<"Se ha insertado el cliente."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo ya se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::insertar(){
	bool bandera=true;
	do{
		system("cls");
		cout<<"****************************** INSERTAR ******************************"<<endl;
		cout<<endl<<"Ingrese que desea insertar"<<endl<<endl;
		cout<<"1. Un pais."<<endl;
		cout<<"2. Una ciudad."<<endl;
		cout<<"3. Un restaurante."<<endl;
		cout<<"4. Un menu."<<endl;
		cout<<"5. Un producto."<<endl;
		cout<<"6. Un cliente."<<endl;
		cout<<"7. Salir."<<endl;
		cout<<endl<<"----> ";
		int opcion;
	
		cin>>opcion;
		cout<<endl;
		switch (opcion){
			case 1:
				insertarPais();
				break;
			case 2:
				insertarCiudad();
				break;
			case 3:
				insertarRest();
				break;
			case 4:
				insertarMenu();
				break;
			case 5:
				insertarProducto();
				break;
			case 6:
				insertarCliente();
				break;
			case 7:
				bandera=false;
				break;
			default:
				cout<<"Ingrese un numero valido"<<endl;
				system("pause");
				break;
			}
	}while(bandera);
	
}

void Menu::buscarPais(){
	
	system("cls");
	cout<<"****************************** BUSCAR PAIS ******************************"<<endl;
	//baseDeDatos.Mostrar();
	cout<<endl<<"Ingrese el codigo del pais a buscar: ";
	int codPais;
	cin>>codPais;
	
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if (nodoPais!=NULL){
		system("cls");
		cout<<endl<<"		* El codigo del pais es: "<< nodoPais->getcodPais() <<endl;
		cout<<endl<<"		* El nombre del pais es: "<< nodoPais->getnombre() <<endl<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::buscarCiudad(){
	system("cls");
	cout<<"****************************** BUSCAR CIUDAD ******************************"<<endl<<endl;
	cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais que quiere buscar una ciudad: ";
	
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->getCiudad ()==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	system("cls");
	//nodoPais->ciudades.Mostrar();
	cout<<endl<<"Ingrese el codigo de la ciudad a buscar: ";
	int codCiudad;
	cin>>codCiudad;
	
	pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if (nodoCiudad!=NULL){
		system("cls");
		cout<<endl<<"		* El codigo de pais de la ciudad es: "<< nodoCiudad->getcodPais() <<endl;
		cout<<endl<<"		* El codigo de la ciudad es: "<< nodoCiudad->getcodCiudad() <<endl;
		cout<<endl<<"		* El nombre de la ciudad es: "<< nodoCiudad->getnombre() <<endl<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
	
}

void Menu::buscarRest(){
	system("cls");
	cout<<"****************************** BUSCAR RESTAURANTE ******************************"<<endl<<endl;
	cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais que quiere buscar un restaurante: ";
	
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->getCiudad ()==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<baseDeDatos.imprimir_Ciudad (codPais);
	cout<<endl<<endl<<"Ingrese el codigo de la ciudad que quiere buscar un restaurante: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	if (nodoCiudad->getRest ()==NULL){
		cout<<endl<<"No hay restaurantes registrados."<<endl;
		system("pause");
		return;
	}
	system("cls");
	//nodoCiudad->restaurantes.Mostrar();
	cout<<endl<<"Ingrese el codigo del restaurante a buscar: ";
	int codRest;
	cin>>codRest;
	
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais,codCiudad,codRest);
	if (nodoRest!=NULL){
		system("cls");
//		nodoRest->cantBusquedas=nodoRest->cantBusquedas+1;
		cout<<endl<<"		* El codigo de pais del restaurante es: "<< nodoRest->getcodPais() <<endl;
		cout<<endl<<"		* El codigo de ciudad del restaurante es: "<< nodoRest->getcodCiudad() <<endl;
		cout<<endl<<"		* El codigo del restaurante es: "<< nodoRest->getcodRest() <<endl;
		cout<<endl<<"		* El nombre del restaurante es: "<< nodoRest->getnombre() <<endl<<endl;
		system("pause");
		
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
	
}

void Menu::buscarMenu(){
	system("cls");
	cout<<"****************************** BUSCAR MENU ******************************"<<endl<<endl;
	cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais en el que quiere buscar un menu: ";
	
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->getCiudad()==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<baseDeDatos.imprimir_Ciudad (codPais);
	
	cout<<endl<<endl<<"Ingrese el codigo de la ciudad en el que quiere buscar un menu: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	if (nodoCiudad->getRest ()==NULL){
		cout<<endl<<"No hay restaurantes registrados."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	cout<<baseDeDatos.imprimir_Rest ( codPais, codCiudad);
	
	cout<<endl<<endl<<"Ingrese el codigo del restaurante en el que quiere buscar un menu: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais, codCiudad,codRest);
	if(nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoRest->getMenu ()==NULL){
		cout<<endl<<"No hay menus registrados."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	//nodoRest->menus.Mostrar();
	cout<<endl<<"Ingrese el codigo del menu a buscar: ";
	int codMenu;
	cin>>codMenu;
	
	
	pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais,codCiudad,codRest,codMenu);
	if (nodoMenu!=NULL){
		system("cls");
		//nodoRest->menus.Mostrar();
		cout<<endl<<"		* El codigo de pais del menu es: "<< nodoMenu->getcodPais() <<endl;
		cout<<endl<<"		* El codigo de ciudad del menu es: "<< nodoMenu->getcodCiudad() <<endl;
		cout<<endl<<"		* El codigo de restaurante del menu es: "<< nodoMenu->getcodRest() <<endl;
		cout<<endl<<"		* El codigo del menu es: "<< nodoMenu->getcodMenu() <<endl;
		cout<<endl<<"		* El nombre del menu es: "<< nodoMenu->getNombre() <<endl<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::buscarProducto(){
	system("cls");
	cout<<"****************************** BUSCAR PRODUCTO ******************************"<<endl<<endl;
		cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais en el que quiere buscar un producto: ";
	
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->getCiudad()==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<baseDeDatos.imprimir_Ciudad (codPais);
	
	cout<<endl<<endl<<"Ingrese el codigo de la ciudad en el que quiere buscar un producto: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	if (nodoCiudad->getRest ()==NULL){
		cout<<endl<<"No hay restaurantes registrados."<<endl;
		system("pause");
		return;
	}
	
	system("cls");
	cout<<baseDeDatos.imprimir_Rest ( codPais, codCiudad);
	
	cout<<endl<<endl<<"Ingrese el codigo del restaurante en el que quiere buscar un producto: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = baseDeDatos.buscarRest(codPais, codCiudad,codRest);
	if(nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoRest->getMenu ()==NULL){
		cout<<endl<<"No hay menus registrados."<<endl;
		system("pause");
		return;
	}
		
	system("cls");
	cout<<baseDeDatos.imprimir_Menu ( codPais, codCiudad, codRest);
	
	cout<<endl<<endl<<"Ingrese el codigo del menu en el que quiere buscar un producto: ";
	int codMenu;
	cin>>codMenu;
	pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais, codCiudad,codRest,codMenu);
	if(nodoMenu==NULL){
		cout<<endl<<"Menu Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoMenu->getdirProducto()==NULL){
		cout<<endl<<"No hay productos registrados."<<endl;
		system("pause");
		return;
	}
	
	
	system("cls");
	//nodoMenu->productos.Mostrar();
	cout<<endl<<"Ingrese el codigo del producto a buscar: ";
	int codProd;
	cin>>codProd;
	
	
	pnodoProducto nodoProd = baseDeDatos.buscarProducto(codPais,codCiudad,codRest,codMenu,codProd);
	if (nodoProd!=NULL){
		system("cls");
		cout<<endl<<"		* El codigo de pais del producto es: "<< nodoProd->getcodPais() <<endl;
		cout<<endl<<"		* El codigo de ciudad del producto es: "<< nodoProd->getcodCiudad() <<endl;
		cout<<endl<<"		* El codigo de restaurante del producto es: "<< nodoProd->getcodRest() <<endl;
		cout<<endl<<"		* El codigo de menu del producto es: "<< nodoProd->getcodMenu() <<endl;
		cout<<endl<<"		* El codigo  del producto es: "<< nodoProd->getcodProducto() <<endl;
		cout<<endl<<"		* El nombre del producto es: "<< nodoProd->getNombre() <<endl;
		cout<<endl<<"		* Las calorias del producto son: "<< nodoProd->getkcal() <<endl;
		cout<<endl<<"		* El precio del producto es: "<< nodoProd->getprecio() <<endl;
		cout<<endl<<"		* La cantidad del producto es: "<< nodoProd->getcantidad() <<endl<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::buscarClientes(){
	
	system("cls");
	cout<<"****************************** BUSCAR CLIENTE ******************************"<<endl;
	cout<<endl<<"Ingrese la cedula del cliente a buscar: ";
	int cedula;
	cin>>cedula;
	
	puntero_Cliente Pagina_Cliente = clientes.buscarCliente(cedula);
	int indice = Pagina_Cliente->getIndice(cedula);
	if (Pagina_Cliente!=NULL){
		system("cls");
		cout<<endl<<"		* La cedula del cliente es: "<< Pagina_Cliente->getCedula(indice) <<endl;
		cout<<endl<<"		* El nombre del cliente es: "<< Pagina_Cliente->getNombre(indice) <<endl<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::buscar(){
	bool bandera=true;
	do{
		system("cls");
		cout<<"****************************** BUSCAR ******************************"<<endl;
		cout<<endl<<"Ingrese que desea buscar"<<endl<<endl;
		cout<<"1. Un pais."<<endl;
		cout<<"2. Una ciudad."<<endl;
		cout<<"3. Un restaurante."<<endl;
		cout<<"4. Un menu."<<endl;
		cout<<"5. Un producto."<<endl;
		cout<<"6. Un cliente."<<endl;
		cout<<"7. Salir."<<endl;
		cout<<endl<<"----> ";
		int opcion;
	
		cin>>opcion;
		cout<<endl;
		switch (opcion){
			case 1:
				buscarPais();
				break;
			case 2:
				buscarCiudad();
				break;
			case 3:
				buscarRest();
				break;
			case 4:
				buscarMenu();
				break;
			case 5:
				buscarProducto();
				break;
			case 6:
				buscarClientes();
				break;
			case 7:
				bandera=false;
				break;
			default:
				cout<<"Ingrese un numero valido"<<endl;
				system("pause");
				break;
			}
	}while(bandera);
	
}

void Menu::modificarPais(){
	
	system("cls");
	cout<<"****************************** MODIFICAR PAIS ******************************"<<endl;
	cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais a modificar: ";
	int codPais;
	cin>>codPais;
	
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if (nodoPais!=NULL){
		system("cls");
		string nombre;
		cout<<endl<<"Ingrese el nuevo nombre del pais: ";
		cin.ignore();
		getline(cin,nombre);
		nodoPais->setnombre (nombre);
		system("cls");
		cout<<baseDeDatos.imprimir_Pais ();
		cout<<endl<<endl<<"Se ha modificado el pais."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::modificarCiudad(){
	system("cls");
	cout<<"****************************** MODIFICAR CIUDAD ******************************"<<endl<<endl;
	cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais que quiere modificar una ciudad: ";
	
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<baseDeDatos.imprimir_Ciudad (codPais);
	cout<<endl<<endl<<"Ingrese el codigo de la ciudad a modificar: ";
	int codCiudad;
	cin>>codCiudad;
	
	pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if (nodoCiudad!=NULL){
		system("cls");
		string nombre;
		cout<<endl<<"Ingrese el nuevo nombre de la ciudad: ";
		cin.ignore();
		getline(cin,nombre);
		nodoCiudad->setnombre (nombre);
		system("cls");
		cout<<baseDeDatos.imprimir_Ciudad (codPais);
		cout<<endl<<endl<<"Se ha modificado la ciudad."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
}

void Menu::modificarRest(){
	system("cls");
	cout<<"****************************** MODIFICAR RESTAURANTE ******************************"<<endl<<endl;
	cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais que quiere modificar un restaurante: ";
	
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->getCiudad ()==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<baseDeDatos.imprimir_Ciudad (codPais);
	cout<<endl<<endl<<"Ingrese el codigo de la ciudad que quiere modificar un restaurante: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<baseDeDatos.imprimir_Rest (codPais,codCiudad);
	cout<<endl<<endl<<"Ingrese el codigo del restaurante a modificar: ";
	int codRest;
	cin>>codRest;
	
	pnodoRest nodoRest = nodoCiudad->getRest()->buscarRest(codRest);

	if (nodoRest!=NULL){
		system("cls");
		string nombre;
		cout<<endl<<"Ingrese el nuevo nombre del restaurante: ";
		cin.ignore();
		getline(cin,nombre);
		nodoRest->setNombre (nombre);
		system("cls");
		cout<<baseDeDatos.imprimir_Rest (codPais,codCiudad);
		cout<<endl<<endl<<"Se ha modificado el restaurante."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
	
}

void Menu::modificarMenu(){;
	system("cls");
	cout<<"****************************** MODIFICAR MENU ******************************"<<endl<<endl;
	cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais que quiere modificar un menu: ";
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->getCiudad ()==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<baseDeDatos.imprimir_Ciudad (codPais);
	cout<<endl<<endl<<"Ingrese el codigo de la ciudad que quiere modificar un menu: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<baseDeDatos.imprimir_Rest (codPais,codCiudad);
	cout<<endl<<endl<<"Ingrese el codigo del restaurante que quiere modificar un menu: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = nodoCiudad->getRest()->buscarRest(codRest);
	if(nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}

	system("cls");
	cout<<baseDeDatos.imprimir_Menu(codPais, codCiudad, codRest);
	cout<<endl<<endl<<"Ingrese el codigo del menu a modificar: ";
	int codMenu;
	cin>>codMenu;
	pnodoMenu nodoMenu = nodoRest->getMenu()->buscarMenu(codMenu);
	if (nodoMenu!=NULL){
		system("cls");
		string nombre;
		cout<<endl<<"Ingrese el nuevo nombre del menu: ";
		cin.ignore();
		getline(cin,nombre);
		nodoMenu->setNombre (nombre);
		system("cls");
		cout<<baseDeDatos.imprimir_Menu(codPais,codCiudad,codRest);
		cout<<endl<<endl<<"Se ha modificado el menu"<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}
	
}

void Menu::modificarProducto(){;
	system("cls");
	cout<<"****************************** MODIFICAR PRODUCTO ******************************"<<endl<<endl;
	cout<<baseDeDatos.imprimir_Pais ();
	cout<<endl<<endl<<"Ingrese el codigo del pais que quiere modificar un producto: ";
	int codPais;
	cin>>codPais;
	cout<<endl;
	
	pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
	if(nodoPais==NULL){
		cout<<endl<<"Pais Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	if (nodoPais->getCiudad ()==NULL){
		cout<<endl<<"No hay ciudades registradas."<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<baseDeDatos.imprimir_Ciudad (codPais);
	cout<<endl<<endl<<"Ingrese el codigo de la ciudad que quiere modificar un producto: ";
	int codCiudad;
	cin>>codCiudad;
	pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
	if(nodoCiudad==NULL){
		cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<baseDeDatos.imprimir_Rest (codPais,codCiudad);
	cout<<endl<<endl<<"Ingrese el codigo del restaurante que quiere modificar un producto: ";
	int codRest;
	cin>>codRest;
	pnodoRest nodoRest = nodoCiudad->getRest()->buscarRest(codRest);
	if(nodoRest==NULL){
		cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	system("cls");
	cout<<baseDeDatos.imprimir_Menu(codPais, codCiudad, codRest);
	cout<<endl<<endl<<"Ingrese el codigo del menu que quiere modificar un producto: ";
	int codMenu;
	cin>>codMenu;
	pnodoMenu nodoMenu = nodoRest->getMenu()->buscarMenu(codMenu);
	if (nodoMenu==NULL){
		cout<<endl<<"Menu Invalido o No Registrado"<<endl;
		system("pause");
		return;
	}
	system("cls");
	baseDeDatos.imprimir_Producto(codPais,codCiudad,codRest,codMenu);
	cout<<endl<<endl<<"Ingrese el codigo del producto a modificar: ";
	int codProducto;
	cin>>codProducto;
	pnodoProducto nodoProducto = nodoMenu->getdirProducto()->buscarProducto(codProducto);
	if(nodoProducto!=NULL){
		system("cls");
		bool bandera=true;
		do{
		system("cls");
		cout<<"****************************** MODIFICAR PRODUCTO ******************************"<<endl;
		cout<<endl<<"Ingrese el numero de la opcion que desea modificar"<<endl<<endl;
		cout<<"1. El nombre."<<endl;
		cout<<"2. Las calorias."<<endl;
		cout<<"3. El precio."<<endl;
		cout<<"4. Insertar mas cantidad. "<<endl;
		cout<<"5. Salir."<<endl;
		cout<<endl<<"----> ";
		int opcion;
		cin>>opcion;
		cout<<endl;
		switch (opcion){
			case 1:{
				system("cls");
				string nombreNuevo;
				cout<<endl<<"Ingrese el nuevo nombre del producto: ";
				cin.ignore();
				getline(cin,nombreNuevo);
				nodoProducto->setnombre(nombreNuevo);
				system("cls");
				baseDeDatos.imprimir_Producto(codPais,codCiudad,codRest,codMenu);
				cout<<endl<<"Se ha modificado el nombre del producto."<<endl;
				system("pause");
				break;
			}
			case 2:{
				system("cls");
				int kcalNuevo;
				cout<<endl<<"Ingrese las nuevas calorias del producto: ";
				cin>>kcalNuevo;
				nodoProducto->setkcal(kcalNuevo);
				system("cls");
				baseDeDatos.imprimir_Producto(codPais,codCiudad,codRest,codMenu);
				cout<<endl<<"Se han modificado las calorias del producto."<<endl;
				system("pause");
				break;
			}
			case 3:{
				system("cls");
				int precioNuevo;
				cout<<endl<<"Ingrese el nuevo precio del producto: ";
				cin>>precioNuevo;
				nodoProducto->setprecio(precioNuevo);
				system("cls");
				baseDeDatos.imprimir_Producto(codPais,codCiudad,codRest,codMenu);
				cout<<endl<<"Se ha modificado el precio del producto."<<endl;
				system("pause");
				break;
			}
			case 4:{
				system("cls");
				int cantidad = nodoProducto->getcantidad();
				int cantidadExtra;
				cout<<endl<<"Ingrese la cantidad que se va a insertar: ";
				cin>>cantidadExtra;
				nodoProducto->setcantidad(cantidad+cantidadExtra);
				system("cls");
				baseDeDatos.imprimir_Producto(codPais,codCiudad,codRest,codMenu);
				cout<<endl<<"Se ha insertado mas cantidad del producto."<<endl;
				system("pause");
				break;
			}
			case 5:
				bandera=false;
				break;
			default:
				cout<<"Ingrese un numero valido"<<endl;
				system("pause");
				break;
			}
		}while(bandera);
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
		return;
	}	
}

void Menu::modificarCliente(){
	
	system("cls");
	cout<<"****************************** MODIFICAR CLIENTE ******************************"<<endl;
	clientes.imprimir_Arbol();
	cout<<endl<<"Ingrese la cedula del cliente a modificar: ";
	int cedula;
	cin>>cedula;
	puntero_Cliente Pagina_Cliente = clientes.buscarCliente(cedula);
	int indice = Pagina_Cliente->getIndice(cedula);
	if (Pagina_Cliente!=NULL){
		system("cls");
		cout<<endl<<"Ingrese el nuevo nombre del cliente: ";
		string nombre;
		cin.ignore();
		getline(cin,nombre);
		Pagina_Cliente->setNombre(indice,nombre);
		system("cls");
		clientes.imprimir_Arbol();
		cout<<endl<<endl<<"Se ha modificado el cliente."<<endl;
		system("pause");
	}
	else{
		cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::modificar(){
	bool bandera=true;
	do{
		system("cls");
		cout<<"****************************** MODIFICAR ******************************"<<endl;
		cout<<endl<<"Ingrese que desea modificar"<<endl<<endl;
		cout<<"1. Un pais."<<endl;
		cout<<"2. Una ciudad."<<endl;
		cout<<"3. Un restaurante."<<endl;
		cout<<"4. Un menu."<<endl;
		cout<<"5. Un producto."<<endl;
		cout<<"6. Un cliente."<<endl;
//		cout<<"7. Una compra"<<endl;
		cout<<"8. Salir."<<endl;
		cout<<endl<<"----> ";
		int opcion;
	
		cin>>opcion;
		cout<<endl;
		switch (opcion){
			case 1:
				modificarPais();
				break;
			case 2:
				modificarCiudad();
				break;
			case 3:
				modificarRest();
				break;
			case 4:
				modificarMenu();
				break;
			case 5:
				modificarProducto();
				break;
			case 6:
				modificarCliente();
				break;
//			case 7:
//				modificarCompra();
				break;
			case 8:
				bandera=false;
				break;
			default:
				cout<<"Ingrese un numero valido"<<endl;
				system("pause");
				break;
			}
	}while(bandera);	
}

bool Menu::desicion(bool bandera){
	bool bandera2=true;
	do{
		system("cls");
		cout<<endl<<"Desea seguir comprando?"<<endl;
		cout<<"1.Si"<<endl;
		cout<<"2.No"<<endl;
		cout<<endl<<"-->";
		int opcion;
		cin>>opcion;
		switch (opcion){
			case 1:
				bandera2=false;
				break;
			case 2:
				bandera=false;
				bandera2=false;
				break;
			default:
				cout<<"Ingrese un numero valido"<<endl;
				system("pause");
				
		}
	}while(bandera2==true);
	return bandera;
}

void Menu::comprar(){
	system("cls");
	cout<<"****************************** COMPRAR ******************************"<<endl;
	
	if(colaClientes.ColaLlena()){
		cout<<endl<<"La cola esta llena, no puede comprar."<<endl;
		system("pause");
		return;
	}
	
	cout<<endl<<"Ingrese su numero de cedula: ";
	int cedula;
	cin>>cedula;
	
	puntero_Cliente nodoClientes = clientes.buscarCliente(cedula);
	
	if(colaClientes.buscar(cedula)==true){
		cout<<endl<<"El cliente ya esta en la cola."<<endl;
		system("pause");
		return;
	}
	
	if (nodoClientes!=NULL){
		int indice = nodoClientes->getIndice(cedula);
		pnodoFila clienteNodo = new NodoFila();
		clienteNodo->cedula = nodoClientes->getCedula(indice);
		clienteNodo->nombreCliente = nodoClientes->getNombre(indice);
		bool bandera =true, banderaCompra=false;
		banderaCompra=false;
		do{
			system("cls");
			cout<<endl<<endl;
			cout<<baseDeDatos.imprimir_Pais ();
			cout<<endl<<endl<<"Ingrese el codigo del pais en el que quiere comprar: ";
			
			int codPais;
			cin>>codPais;
			cout<<endl;
			
			pnodoPais nodoPais = baseDeDatos.buscarPais(codPais);
			if(nodoPais==NULL){
				cout<<endl<<"Pais Invalido o No Registrado"<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
			if (nodoPais->getCiudad()==NULL){
				cout<<endl<<"No hay ciudades registradas."<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
			system("cls");
			cout<<baseDeDatos.imprimir_Ciudad (codPais);
			
			cout<<endl<<endl<<"Ingrese el codigo de la ciudad en el que quiere comprar: ";
			int codCiudad;
			cin>>codCiudad;
			pnodoCiudad nodoCiudad = baseDeDatos.buscarCiudad(codPais, codCiudad);
			if(nodoCiudad==NULL){
				cout<<endl<<"Ciudad Invalida o No Registrada"<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
			if (nodoCiudad->getRest ()==NULL){
				cout<<endl<<"No hay restaurantes registrados."<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
			
			system("cls");
			cout<<baseDeDatos.imprimir_Rest ( codPais, codCiudad);
			
			cout<<endl<<endl<<"Ingrese el codigo del restaurante en el que quiere comprar: ";
			int codRest;
			cin>>codRest;
			pnodoRest nodoRest = baseDeDatos.buscarRest(codPais, codCiudad,codRest);
			if(nodoRest==NULL){
				cout<<endl<<"Restaurante Invalido o No Registrado"<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
			if (nodoRest->getMenu ()==NULL){
				cout<<endl<<"No hay menus registrados."<<endl;
				system("pause");
				bandera = desicion(bandera);
				continue;
			}
			do{
				
				system("cls");
				cout<<baseDeDatos.imprimir_Menu ( codPais, codCiudad, codRest);
				
				cout<<endl<<endl<<"Ingrese el codigo del menu en el que quiere comprar: ";
				int codMenu;
				cin>>codMenu;
				pnodoMenu nodoMenu = baseDeDatos.buscarMenu(codPais, codCiudad,codRest,codMenu);
				if(nodoMenu==NULL){
					cout<<endl<<"Menu Invalido o No Registrado"<<endl;
					system("pause");
					bandera = desicion(bandera);
					continue;
				}
				if (nodoMenu->getdirProducto()==NULL){
					cout<<endl<<"No hay productos registrados."<<endl;
					system("pause");
					bandera = desicion(bandera);
					continue;
				}
				
				
				system("cls");
				baseDeDatos.imprimir_Producto (codPais,codCiudad, codRest, codMenu);
				cout<<endl<<endl<<"Ingrese el codigo del producto a comprar: ";
				int codProd;
				cin>>codProd;
				
				
				pnodoProducto nodoProd = baseDeDatos.buscarProducto(codPais,codCiudad,codRest,codMenu,codProd);
				if (nodoProd!=NULL){
					int cantidad;
	
					cout<<endl<<"¿Cuantas unidades desea comprar de "<<nodoProd->getNombre ()<<"?: ";
					cin>>cantidad;
					if (cantidad<=nodoProd->getcantidad()){
						nodoProd->setcantidad(nodoProd->getcantidad()-cantidad);
						clienteNodo->productos.InsertarFinal(codPais,codCiudad,codRest,codMenu,codProd,nodoProd->getNombre(),cantidad);
						system("cls");
						clienteNodo->productos.MostrarCompra();
						cout<<endl<<"Se ha insertado el producto a su carrito."<<endl;
						banderaCompra=true;
					}
					else{
						cout<<endl<<"Cantidad ingresada superior a la almacenada."<<endl;
					}
					system("pause");
					bandera = desicion(bandera);
					continue;
				}
				else{
					cout<<endl<<"Este codigo no se encuentra registrado."<<endl;
					system("pause");
					bandera = desicion(bandera);
					continue;
				}
			}while(bandera==true && banderaCompra==true);	
		}while(bandera==true);
		system("cls");
		if(banderaCompra==true){
			bool bandera2=true;
			do{
				system("cls");
				cout<<endl<<"Llevar o comer en el restaurante?"<<endl;
				cout<<"1.Llevar."<<endl;
				cout<<"2.Comer en el restaurante."<<endl;
				cout<<endl<<"-->";
				int opcion;
				cin>>opcion;
				switch (opcion){
					case 1:
						clienteNodo->lugar = 1;
						bandera2=false;
						break;
					case 2:
						clienteNodo->lugar = 2;
						bandera2=false;
						break;
					default:
						cout<<"Ingrese un numero valido"<<endl;
						system("pause");		
				}
			}while(bandera2==true);
			system("cls");
			colaClientes.insertar(clienteNodo);
		colaClientes.imprimir();
		system("pause");
		}
		delete clienteNodo;
		
	}
	else{
		cout<<endl<<"Este cliente no se encuentra registrado."<<endl;
		system("pause");
	}
}

void Menu::menu(){
	bool bandera=true;
	do{
		system("cls");
		cout << "			       $$$    $$$" << endl;
	    cout << "			      $   $  $   $" << endl;
	    cout << "			     $     $$     $" << endl;
	    cout << "		   	    $$     $$     $$" << endl;
	    cout << "			    $$     $$     $$" <<endl;
	    cout << "			    $$     $$     $$" <<endl;
		cout<<"****************************** MC'DONALD'S ******************************"<<endl;
		cout<<endl<<"¡Bienvenido a la base de datos de McDonald's! ¿Que desea realizar?"<<endl<<endl;
		cout<<"1. Insertar."<<endl;
		cout<<"2. Buscar."<<endl;
		cout<<"3. Modificar"<<endl;
//		cout<<"4. Reportar"<<endl;
		cout<<"4. Registrar Compra"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<endl<<"----> ";
		int opcion;
		cin>>opcion;
		cout<<endl;
		switch (opcion){
		case 1:
			insertar();
			menu();
			break;
		case 2:
			buscar();
			break;
		case 3:
			modificar();
			break;
		case 4:
			comprar();
			break;
//		case 5:
//			break;
		case 5:
			bandera=false;
			break;
		default:
			cout<<"Ingrese un numero valido"<<endl;
			system("pause");
			break;
		}
	}while(bandera);
	
	
}

