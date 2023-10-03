

#include "NodoPais.h"


NodoPais::NodoPais() {
		codPais = 0; 
		nombre = "";
		hDer = NULL; 
		hIzq = NULL;
		dirCiudad = NULL;
	}

NodoPais::NodoPais(int &codPais, string &nombre) {
		this->codPais = codPais; 
		this->nombre = nombre;
		hDer = NULL; 
		hIzq = NULL;
		dirCiudad = NULL;
	}

void NodoPais::insert (int &codPais, string &nombre)
{
	if (this->codPais >= codPais) {
        if (this->getHIzq () == NULL) {this->setHIzq (new NodoPais (codPais, nombre));} 
		else {this->getHIzq ()->insert (codPais, nombre);}
    } else {
        if (this->getHDer () == NULL) {this->setHDer (new NodoPais (codPais, nombre));} 
		else {this->getHDer ()->insert (codPais, nombre);}
    }
}

NodoPais * NodoPais::buscarPais (int &codPais)
{
	if (this->codPais == codPais) return this;
	
	if (this->codPais < codPais) {
		if (this->getHDer () == NULL) 
			return NULL;
		else 
			return this->getHDer ()->buscarPais (codPais);
	} else {
		if (this->getHIzq () == NULL) 
			return NULL;
		else 
			return this->getHIzq ()->buscarPais (codPais);
	}
}

void NodoPais::borrar(int& pcodPais, NodoPais*& pPasillo, NodoPais*& pPasilloAux) //(int &pcodPais, NodoPais_Inventario* &pPasillo, NodoPais_Inventario* &pPasilloAux)
{
	pnodoPais pasillo_Aux;
	if (pPasillo->codPais == pcodPais) {

		if (pPasillo->hDer == NULL && pPasillo->hIzq == NULL) {
			pasillo_Aux = pPasillo;
			pPasillo = NULL;
			pPasilloAux = NULL;
			delete pasillo_Aux;
			return;
		}
		if (pPasillo->hDer == NULL) {
			pasillo_Aux = pPasillo;
			pPasilloAux = pPasillo->hIzq;
			delete pasillo_Aux;
			return;
		}
		if (pPasillo->hIzq == NULL || pPasillo->hDer->hIzq == NULL) {
			pasillo_Aux = pPasillo;
			pPasilloAux = pPasillo->hDer;
			pPasilloAux->hIzq = pPasillo->hIzq;
			delete pasillo_Aux;
			return;
		}

		pnodoPais pasillo_Sustituto = pPasillo->hDer;
		while (pasillo_Sustituto->hIzq != NULL)
			pasillo_Sustituto = pasillo_Sustituto->hIzq;

		pPasillo->codPais = pasillo_Sustituto->codPais;
		pPasillo->nombre = pasillo_Sustituto->nombre;

		pasillo_Aux = pPasilloAux;
		this->borrar(codPais, pPasillo->hDer, pasillo_Aux);
		pPasillo->hDer = pasillo_Aux;
		pPasilloAux = pPasillo;

	}
	if (pPasillo->codPais < pcodPais) {
		if (pPasillo->hDer != NULL)
		{
			pasillo_Aux = pPasilloAux;
			this->borrar(pcodPais, pPasillo->hDer, pasillo_Aux);
			pPasillo->hDer = pasillo_Aux;
			pPasilloAux = pPasillo;
		}
		else {
			pPasilloAux = pPasillo;
		}
	}
	else {
		if (pPasillo->hIzq != NULL)
		{
			pasillo_Aux = pPasilloAux;
			this->borrar(pcodPais, pPasillo->hIzq, pasillo_Aux);
			pPasillo->hIzq = pasillo_Aux;
			pPasilloAux = pPasillo;
		}
		else {
			pPasilloAux = pPasillo;
		}
	}
}


string NodoPais::inOrden_Pais()
{
	string reporte = "";
	if (this->getHIzq() != NULL)
		reporte += this->getHIzq()->inOrden_Pais();
	reporte += "\n\tCodigo: "+to_Stiringeo(this->codPais)+" - Nombre: "+this->nombre;
	if (this->getHDer()!= NULL)
		reporte += this->getHDer()->inOrden_Pais();
	return reporte;
}

void NodoPais::imprimir_Arbol()
{
//	string reporte = "";
	if (this->getHIzq() != NULL)
		this->getHIzq()->imprimir_Arbol();

	cout<< "\n\n\t--------\n\tPais:  \n";
	cout<< "\n\nCodigo: "+to_string(this->codPais) +" - Nombre: "+this->nombre;
	cout<< "\n\t--------";
	if (this->dirCiudad != NULL)
		this->dirCiudad->imprimir_Arbol();
	
	if (this->getHDer()!= NULL)
		this->getHDer()->imprimir_Arbol();
	return ;
}
void NodoPais::setnombre (string pnombre){this->nombre = pnombre;}
void NodoPais::setHDer (NodoPais * hijoDer) {this->hDer = hijoDer;}
void NodoPais::setHIzq (NodoPais * hijoIzq) {this->hIzq = hijoIzq;}
void NodoPais::setDirCiudad (pnodoCiudad pdirCiudad) {this->dirCiudad = pdirCiudad;}

int NodoPais::getcodPais(){return this->codPais;}
string NodoPais::getnombre(){return this->nombre;}
NodoPais * NodoPais::getHDer () {return this->hDer;}
NodoPais * NodoPais::getHIzq () {return this->hIzq;}
pnodoCiudad NodoPais::getCiudad () {return this->dirCiudad;}
