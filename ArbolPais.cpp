
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
	if (!this->verificarPais ( atoi (datos[0].c_str() ) ) )
		this->insertPais (atoi (datos[0].c_str()), datos[1]);
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
	if (this->verificarPais ( atoi (datos[0].c_str() ) ) && !this->verificarCiudad ( atoi (datos[0].c_str() ), atoi (datos[1].c_str() ) ) )
		this->insertCiudad (atoi (datos[0].c_str()), atoi (datos[1].c_str() ), datos[2]);
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
	
	if (this->verificarCiudad ( atoi (datos[0].c_str() ), atoi (datos[1].c_str() ) ) && !this->verificarRest ( atoi (datos[0].c_str() ), atoi (datos[1].c_str() ), atoi (datos[2].c_str() ) ) ) {
		this->insertRest (atoi (datos[0].c_str()), atoi (datos[1].c_str() ), atoi (datos[2].c_str() ), datos[3] );
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

string ArbolPais::imprimir_Arbol_Ventas()
{
	if (this->raiz == NULL) {
		return "\n\n\tInventario vacio.";
	}
	return this->raiz->imprimir_Arbol();
}
