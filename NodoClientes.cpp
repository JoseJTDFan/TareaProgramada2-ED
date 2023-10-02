#include "NodoClientes.h"

Pagina_Administrador::Pagina_Administrador()
{
	for (int i = 0; i < 5; i++) 
	{
		this->cedula[i] = -1;
		this->nombre[i] = "";
	}
	this->rama1 = NULL; 
	this->rama2 = NULL; 
	this->rama3 = NULL; 
	this->rama4 = NULL; 
	this->rama5 = NULL;
}	

Pagina_Administrador::Pagina_Administrador (int pCedula, std::string pNombre)
{
	this->cedula[0] = pCedula;
	this->nombre[0] = pNombre;
	for (int i = 1; i < 5; i++) 
	{
		this->cedula[i] = -1;
		this->nombre[i] = "";
	}
	this->rama1 = NULL; 
	this->rama2 = NULL; 
	this->rama3 = NULL; 
	this->rama4 = NULL; 
	this->rama5 = NULL;
}

int Pagina_Administrador::getCuentas()
{
	int contador = 0;
	while (contador <= 4) {
		if (this->cedula[contador] == -1) 
			return contador;
		else 
			contador++;
	} 
	return contador;
}

int Pagina_Administrador::getCedula(int pIndice)
{
	return this->cedula[pIndice];
}

string Pagina_Administrador::getNombre(int pIndice)
{
	return this->nombre[pIndice];
}

Pagina_Administrador* Pagina_Administrador::getRama (int & pIndice)
{
	switch (pIndice) 
	{ 
		case 0:
			return this->rama1;
		case 1:
			return this->rama2;
		case 2:
			return this->rama3;
		case 3:
			return this->rama4;
		case 4:
			return this->rama5;
	}
}

void Pagina_Administrador::setCedula (int pIndice, int pCedula)
{
	this->cedula[pIndice] = pCedula;
}

void Pagina_Administrador::setNombre (int pIndice, string pNombre)
{
	this->nombre[pIndice] = pNombre;
}

void Pagina_Administrador::setRama (int pIndice, Pagina_Administrador * pRama)
{
	switch (pIndice) 
	{ 
		case 0:
			this->rama1 = pRama;
			break;
		case 1:
			this->rama2 = pRama;
			break;
		case 2:
			this->rama3 = pRama;
			break;
		case 3:
			this->rama4 = pRama;
			break;
		case 4:
			this->rama5 = pRama;
			break;
	}
}

void Pagina_Administrador::imprimir ()
{ 
	int cantidad_Datos = this->getCuentas ();
	if (cantidad_Datos == 0) 
		return;

	for (int i = 0; i <= cantidad_Datos; i++) {
		if (i != cantidad_Datos) {
			if (this->getRama (i) != NULL)
				this->getRama (i)->imprimir();
			cout<<"\nIdentificacion: "<<this->cedula[i]<<" - Nombre: "<<this->nombre[i]<<" ->";
		} else {
			if (this->getRama (i) != NULL)
				this->getRama (i)->imprimir();
		}
	}
}

void Pagina_Administrador::imprimir_Pagina()
{
	//cout<<"\nNumero de cuentas__"<<this->getCuentas ();
	for (int i = 0; i < this->getCuentas (); i++) 
	{
		cout<<"\nIdentificacion: "<<this->cedula[i]<<" - Nombre: "<<this->nombre[i]<<" ->";
	}
}

Pagina_Administrador * Pagina_Administrador::buscar (int pCedula)
{
	int cantidad_Datos = this->getCuentas ();
	if (cantidad_Datos == 0) 
		return NULL;
	puntero_Administrador administrador_Temporal = NULL;
	for (int i = 0; i <= cantidad_Datos; i++) {
		
		if (i != cantidad_Datos) {
			if (this->getRama (i) != NULL && administrador_Temporal == NULL)
				administrador_Temporal = this->getRama (i)->buscar(pCedula);
			if (this->cedula[i] == pCedula)
				return this;
				
		} else {
			if (this->getRama (i) != NULL && administrador_Temporal == NULL)
				administrador_Temporal = this->getRama (i)->buscar(pCedula);
		}
	}
	return administrador_Temporal;
}

int Pagina_Administrador::getIndice(int pCedula)
{
	int cantidad_Datos = this->getCuentas ();
	if (cantidad_Datos == 0) 
		return -1;
	
	for (int i = 0; i < cantidad_Datos; i++) {
		if (this->cedula[i] == pCedula)
			return i;
	}
	return -1;
}
