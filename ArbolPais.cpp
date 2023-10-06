
#include "ArbolPais.h"
 
//----------------- Pais ---------------------

void ArbolPais::insertPais (int codPais, string nombre)
{	
	if (this->raiz == NULL) {
		raiz = new NodoPais (codPais, nombre); 
		return;
	}
	this->raiz->insert (codPais, nombre);
}


void ArbolPais::borrar_Pais(int codPais)
{
	if (this->raiz != NULL)
	{
		pnodoPais Pais_Aux = NULL;
		this->raiz->borrar(codPais, this->raiz, Pais_Aux);
		this->raiz = Pais_Aux;
	}
}


pnodoPais ArbolPais::buscarPais  (int & codPais)
{
	if (this->raiz == NULL) 
		return NULL; 
	return this->raiz->buscarPais (codPais); 
}

bool ArbolPais::verificarPais(int codPais)
{
	if (this->buscarPais (codPais) == NULL) 
		return false;
	return true;
}

string ArbolPais::imprimir_Pais()
{	
	if (this->raiz == NULL) {
		return "\n\tNo hay Paiss registrados.";
	}
	return this->raiz->inOrden_Pais();
}

void ArbolPais::agregar_Datos_Pais (string & pDatosLinea)
{
	std::string datos [2] = {"", ""};
	int indiceDatos = 0;
	for (int indice = 0; indice < pDatosLinea.size(); indice++) {
		if (pDatosLinea[indice] != ';')
			datos[indiceDatos] = datos[indiceDatos] + pDatosLinea[indice];
		else
			indiceDatos++;
	}
	if (!this->verificarPais ( stoi (datos[0].c_str() ) ) )
		this->insertPais (stoi (datos[0].c_str()), datos[1]);
}

void ArbolPais::leeDocPais ()
{
	string nombreArchivo = "Paises.txt";
	ifstream file(nombreArchivo.c_str());
    string linea;
    
    while(!file.eof())
	{
		linea = "";
    	getline (file, linea);
    	this->agregar_Datos_Pais(linea);
	}
	file.close();
}

string ArbolPais::reportePais(){
	pnodoPais nodo = this->raiz;
	return nodo->preOrden_Pais();
}

//--------------------- Ciudades ---------------------

void ArbolPais::insertCiudad (int codPais, int codCiudad, string nombre)
{
	pnodoCiudad inputAux;
	pnodoPais Pais_Temporal = raiz->buscarPais (codPais);
	
	if (Pais_Temporal == NULL) 
		return;
	if (Pais_Temporal->getCiudad() == NULL) {
		Pais_Temporal->setDirCiudad ( new NodoCiudad (codPais, codCiudad, nombre) ); 
		return;
	}
    bool Hh = false;
    inputAux = Pais_Temporal->getCiudad (); 
	Pais_Temporal->getCiudad()->insertCiudad (inputAux, Hh,codPais, codCiudad, nombre); 
	Pais_Temporal->setDirCiudad (inputAux);
}

void ArbolPais::borrar_Ciudad(int pCodPais, int pCodCiudad)
{
	pnodoCiudad input_Aux;
	pnodoCiudad Ciudad;
	pnodoPais Pais_Temporal = raiz->buscarPais(pCodPais);

	if (Pais_Temporal != NULL) {
		bool Hh = false;
		if (Pais_Temporal->getCiudad() != NULL) {
			input_Aux = Pais_Temporal->getCiudad();

			borrar_Ciudad_Vent(input_Aux, Hh, pCodCiudad);
			Pais_Temporal->setDirCiudad(input_Aux);
		}
	}
}

pnodoCiudad ArbolPais::buscarCiudad(int & codPais, int & codCiudad)
{
	pnodoPais Pais_Temporal = this->buscarPais (codPais);	
	if (Pais_Temporal == NULL) 
		return NULL;
	if (Pais_Temporal->getCiudad () == NULL) 
		return NULL;
	return Pais_Temporal->getCiudad()->buscarCiudad(codCiudad);
}

bool ArbolPais::verificarCiudad(int codPais, int codCiudad)
{
	pnodoCiudad Ciudad_Temporal = this->buscarCiudad (codPais, codCiudad);
	if (Ciudad_Temporal == NULL) 
		return false;
	return true;
}

string ArbolPais::imprimir_Ciudad (int codPais)
{
	pnodoPais Pais_Temporal = this->buscarPais(codPais);
	if (Pais_Temporal == NULL) {
		return "\n\tPais no registrado.";
	}
	if (Pais_Temporal->getCiudad() == NULL) {
		return "\n\tNo hay ciudades registrados.";
	}
	return Pais_Temporal->getCiudad()->inOrden_Ciudad();
}

void ArbolPais::agregar_Datos_Ciudad (string & pDatosLinea)
{
	std::string datos [3] = {"", "", ""};
	int indiceDatos = 0;
	for (int indice = 0; indice < pDatosLinea.size(); indice++) {
		if (pDatosLinea[indice] != ';')
			datos[indiceDatos] = datos[indiceDatos] + pDatosLinea[indice];
		else
			indiceDatos++;
	}
	if (this->verificarPais ( stoi (datos[0].c_str() ) ) && !this->verificarCiudad ( stoi (datos[0].c_str() ), stoi (datos[1].c_str() ) ) )
		this->insertCiudad (stoi (datos[0].c_str()), stoi (datos[1].c_str() ), datos[2]);
}

void ArbolPais::leerDocCiudad ()
{
	string nombreArchivo = "Ciudades.txt";
	ifstream file(nombreArchivo.c_str());
    string linea;
    
    while(!file.eof())
	{
		linea = "";
    	getline (file, linea);
    	this->agregar_Datos_Ciudad(linea);
	}
	file.close();
}

string ArbolPais::reporteCiudad(pnodoPais pais){
	pnodoCiudad nodo = pais->getCiudad();
	return nodo->preOrden_Ciudad();
}
//--------------------- Rests---------------------

void ArbolPais::insertRest (int codPais, int codCiudad, int codRest, string nombre)
{
	pnodoRest inputAux;
	pnodoCiudad Ciudad_Temporal = this->buscarCiudad (codPais, codCiudad);
	if (Ciudad_Temporal == NULL)
		return;
	if (Ciudad_Temporal->getRest () == NULL) {
		Ciudad_Temporal->setRest(new NodoRest (codPais,codCiudad, codRest, nombre)); 
		return;}
    bool Hh = false;
    inputAux = Ciudad_Temporal->getRest (); 
	Ciudad_Temporal->getRest ()->insertRest (inputAux, Hh, codPais,codCiudad, codRest, nombre); 
	Ciudad_Temporal->setRest (inputAux);
}

void ArbolPais::borrar_Rest(int codPais, int codCiudad, int codRest)
{
	pnodoRest inputAux;
	pnodoCiudad Ciudad_Temporal = this->buscarCiudad(codPais, codCiudad);
	if (Ciudad_Temporal == NULL)
		return;
	if (Ciudad_Temporal->getRest() == NULL) {
		return;
	}
	bool Hh = false;
	inputAux = Ciudad_Temporal->getRest();
	borrar_Rest_RN(inputAux, Hh, codRest);
	Ciudad_Temporal->setRest(inputAux);
}


pnodoRest ArbolPais::buscarRest (int & codPais, int & codCiudad, int & codRest)
{
	pnodoCiudad Ciudad_Temporal = this->buscarCiudad (codPais, codCiudad);	
	if (Ciudad_Temporal == NULL) 
		return NULL;
	if (Ciudad_Temporal->getRest() == NULL) 
		return NULL;
	pnodoRest hola = Ciudad_Temporal->getRest()->buscarRest(codRest);
	return hola;
}

bool ArbolPais::verificarRest (int codPais, int codCiudad, int codRest)
{
	pnodoRest Rest_Temporal = this->buscarRest(codPais, codCiudad, codRest);
	
	if (Rest_Temporal == NULL) 
		return false;
	return true;
}

string ArbolPais::imprimir_Rest(int codPais, int codCiudad)
{
	pnodoCiudad Ciudad_Temporal = this->buscarCiudad(codPais, codCiudad); 
	if (Ciudad_Temporal == NULL) {
		return "\n\tCiudad no registrado.";
	}
	if (Ciudad_Temporal->getRest() == NULL) {
		return "\n\tNo hay restaurantes registrados.";
	}
	return Ciudad_Temporal->getRest()->inOrden_Rest();
}

void ArbolPais::agregar_Datos_Rest (string & pDatosLinea)
{
	std::string datos [4] = {"", "", "", ""};
	int indiceDatos = 0;
	for (int indice = 0; indice < pDatosLinea.size(); indice++) {
		if (pDatosLinea[indice] != ';')
			datos[indiceDatos] = datos[indiceDatos] + pDatosLinea[indice];
		else
			indiceDatos++;
	} 
	
	if (this->verificarCiudad ( stoi (datos[0].c_str() ), stoi (datos[1].c_str() ) ) && !this->verificarRest ( stoi (datos[0].c_str() ), stoi (datos[1].c_str() ), stoi (datos[2].c_str() ) ) ) {
		this->insertRest (stoi (datos[0].c_str()), stoi (datos[1].c_str() ), stoi (datos[2].c_str() ), datos[3] );
	}
}

void ArbolPais::leeDocRest ()
{
	string nombreArchivo = "Restaurantes.txt";
	ifstream file(nombreArchivo.c_str());
    string linea;
    
	while(!file.eof())
	{
		linea = "";
    	getline (file, linea);
    	this->agregar_Datos_Rest(linea);
	}
	file.close();
}

string ArbolPais::reporteRest(pnodoCiudad ciudad){
	pnodoRest nodo = ciudad->getRest();
	return nodo->preOrden_Rest();
}
//--------------------- Menus ---------------------

void ArbolPais::insertMenu (int codPais, int codCiudad, int codRest, int codMenu, string nombre)
{
	pnodoMenu inputAux;
	pnodoRest Rest_Temporal = this->buscarRest (codPais, codCiudad, codRest);
	if (Rest_Temporal == NULL)
		return;
	if (Rest_Temporal->getMenu () == NULL) {
		Rest_Temporal->setMenu(new NodoMenu (codPais, codCiudad, codRest, codMenu, nombre)); 
		return;}
    bool Hh = false;
    inputAux = Rest_Temporal->getMenu (); 
	Rest_Temporal->getMenu ()->insertMenu (inputAux,codPais, codCiudad, codRest, codMenu, nombre); 
	Rest_Temporal->setMenu (inputAux);
}

void ArbolPais::borrar_Menu(int codPais, int codCiudad, int codRest, int codMenu)
{
	pnodoMenu inputAux;
	pnodoRest Rest_Temporal = this->buscarRest (codPais, codCiudad, codRest);
	if (Rest_Temporal == NULL)
		return;
	if (Rest_Temporal->getMenu() == NULL) {
		return;
	}
	bool Hh = false;
	inputAux = Rest_Temporal->getMenu();
	borrar_Menu_AA(inputAux, Hh, codMenu);
	Rest_Temporal->setMenu(inputAux);
}


pnodoMenu ArbolPais::buscarMenu (int & codPais, int & codCiudad, int & codRest, int & codMenu)
{
	pnodoRest Rest_Temporal = this->buscarRest (codPais, codCiudad, codRest);
	if (Rest_Temporal == NULL) 
		return NULL;
	if (Rest_Temporal->getMenu() == NULL) 
		return NULL;
	return Rest_Temporal->getMenu()->buscarMenu (codMenu);
}

bool ArbolPais::verificarMenu (int codPais, int codCiudad, int codRest, int codMenu)
{
	pnodoMenu Menu_Temporal = this->buscarMenu (codPais,codCiudad, codRest, codMenu);
	
	if (Menu_Temporal == NULL) 
		return false;
	return true;
}

string ArbolPais::imprimir_Menu (int codPais, int codCiudad, int codRest)
{
	pnodoRest Rest_Temporal = this->buscarRest (codPais, codCiudad, codRest);
	if (Rest_Temporal == NULL) {
		return "\n\tMenu no registrado.";
	}
	if (Rest_Temporal->getMenu() == NULL) {
		return "\n\tNo hay menus registrados.";
	}
	return Rest_Temporal->getMenu()->inOrden_Menu();
}

void ArbolPais::agregar_Datos_Menu (string & pDatosLinea)
{
	std::string datos [5] = {"", "", "", "",""};
	int indiceDatos = 0;
	for (int indice = 0; indice < pDatosLinea.size(); indice++) {
		if (pDatosLinea[indice] != ';')
			datos[indiceDatos] = datos[indiceDatos] + pDatosLinea[indice];
		else
			indiceDatos++;
	} 
	
	if (this->verificarRest ( stoi (datos[0].c_str() ), stoi (datos[1].c_str() ), stoi (datos[2].c_str() ) ) && !this->verificarMenu ( stoi (datos[0].c_str() ), stoi (datos[1].c_str() ), stoi (datos[2].c_str() ), stoi (datos[3].c_str() ) ) ) {
		this->insertMenu (stoi (datos[0].c_str()), stoi (datos[1].c_str() ), stoi (datos[2].c_str() ), stoi (datos[3].c_str() ), datos[4] );
	}
}

void ArbolPais::leeDocMenu ()
{
	string nombreArchivo = "Menu.txt";
	ifstream file(nombreArchivo.c_str());
    string linea;
    
	while(!file.eof())
	{
		linea = "";
    	getline (file, linea);
    	this->agregar_Datos_Menu(linea);
	}
	file.close();
}

string ArbolPais::reporteMenu(pnodoRest restaurante){
	pnodoMenu nodo = restaurante->getMenu();
	return nodo->preOrden_Menu();
}

//--------------------- Productos ---------------------

void ArbolPais::insertProducto (int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, int cantidad)
{
	pnodoProducto inputAux;
	pnodoMenu Menu_Temporal = this->buscarMenu ( codPais, codCiudad, codRest, codMenu);
	
	if (Menu_Temporal == NULL) 
		return;
	if (Menu_Temporal->getdirProducto() == NULL) {
		Menu_Temporal->setdirProducto(new NodoProducto (codPais, codCiudad, codRest, codMenu, codProducto, nombre, kcal, precio, cantidad) ); 
		return;
	}
    bool Hh = false;
    inputAux = Menu_Temporal->getdirProducto(); 
	Menu_Temporal->getdirProducto()->insertProducto (inputAux, Hh,codPais, codCiudad, codRest, codMenu, codProducto, nombre, kcal, precio, cantidad);
	Menu_Temporal->setdirProducto(inputAux);
}

void ArbolPais::borrar_Producto(int codPais, int codCiudad, int codRest, int codMenu, int codProducto)
{
	pnodoProducto input_Aux;
	pnodoProducto Producto;
	pnodoMenu Menu_Temporal = this->buscarMenu ( codPais, codCiudad, codRest, codMenu);

	if (Menu_Temporal != NULL) {
		bool Hh = false;
		if (Menu_Temporal->getdirProducto() != NULL) {
			input_Aux = Menu_Temporal->getdirProducto();

			borrarProducto_Vent(input_Aux, Hh, codProducto);
			Menu_Temporal->setdirProducto(input_Aux);
		}
	}
}

pnodoProducto ArbolPais::buscarProducto (int & codPais, int & codCiudad, int & codRest, int & codMenu , int &codProducto)
{
	pnodoMenu Menu_Temporal = this->buscarMenu ( codPais, codCiudad, codRest, codMenu);	
	if (Menu_Temporal == NULL) 
		return NULL;
	if (Menu_Temporal->getdirProducto() == NULL) 
		return NULL;
	return Menu_Temporal->getdirProducto()->buscarProducto (codProducto);
}

bool ArbolPais::verificarProducto(int codPais, int codCiudad, int codRest, int codMenu, int codProducto)
{
	pnodoProducto Producto_Temporal = this->buscarProducto ( codPais, codCiudad, codRest, codMenu,codProducto);
	if (Producto_Temporal == NULL) 
		return false;
	return true;
}

void ArbolPais::imprimir_Producto (int codPais, int codCiudad, int codRest, int codMenu)
{
	pnodoMenu Menu_Temporal = this->buscarMenu ( codPais, codCiudad, codRest, codMenu);	
	if (Menu_Temporal == NULL) {
		cout<<"\n\tMenu no registrado.";
		return;
		 
	}
	if (Menu_Temporal->getdirProducto() == NULL) {
		cout<<"\n\tNo hay productos registrados.";
		return;
	}
	Menu_Temporal->getdirProducto()->inOrdenProducto();
	return;
}

void ArbolPais::agregar_Datos_Producto (string & pDatosLinea)
{
	std::string datos [9] = {"", "", "","","","","","",""};
	int indiceDatos = 0;
	for (int indice = 0; indice < pDatosLinea.size(); indice++) {
		if (pDatosLinea[indice] != ';')
			datos[indiceDatos] = datos[indiceDatos] + pDatosLinea[indice];
		else
			indiceDatos++;
	}
	
	if (this->verificarMenu ( stoi (datos[0].c_str() ), stoi (datos[1].c_str() ),stoi (datos[2].c_str() ), stoi (datos[3].c_str() ) ) && !this->verificarProducto( stoi (datos[0].c_str() ), stoi (datos[1].c_str() ),stoi (datos[2].c_str() ),stoi (datos[3].c_str() ),stoi (datos[4].c_str() ) ) )
		this->insertProducto (stoi (datos[0].c_str() ), stoi (datos[1].c_str() ),stoi (datos[2].c_str() ),stoi (datos[3].c_str() ),stoi (datos[4].c_str() ), datos[5],stoi (datos[6].c_str() ),stoi (datos[7].c_str() ),stoi (datos[8].c_str() ));
}

void ArbolPais::leeDocProducto ()
{
	string nombreArchivo = "Productos.txt";
	ifstream file(nombreArchivo.c_str());
    string linea;
    
    while(!file.eof())
	{
		linea = "";
    	getline (file, linea);
    	this->agregar_Datos_Producto(linea);
	}
	file.close();
}

void ArbolPais::imprimir_Arbol_Ventas()
{
	if (this->raiz == NULL) {
		cout<<"\n\n\tInventario vacio.";
		return ;
	}
	return this->raiz->imprimir_Arbol();
}

string ArbolPais::reporteProducto(pnodoMenu menu){
	pnodoProducto nodo = menu->getdirProducto();
	return nodo->preOrdenProducto();
}

//string ArbolPais::reportePrecio(pnodoProducto producto){
//	string reporte = "";
//	reporte += "Precio del producto: " + to_string(producto->getprecio());
//	return reporte;
//}
