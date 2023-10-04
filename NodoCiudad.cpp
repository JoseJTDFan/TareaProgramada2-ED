

#include "NodoCiudad.h"


void rotSimpleDer_Cur (pnodoCiudad &nodo, pnodoCiudad &n1)
{
    nodo->setHDer(n1->getHIzq());
	n1->setHIzq(nodo);
	
    if(n1->getFB() == 1) {
        nodo->setFB(0); n1->setFB(0);
    } else {
        nodo->setFB(1); n1->setFB(-1);
    } nodo = n1;
}

void rotSimpleIzq_Cur (pnodoCiudad &nodo, pnodoCiudad &n1)
{
	nodo->setHIzq(n1->getHDer());
    n1->setHDer(nodo);

    if(n1->getFB()==-1) {
        nodo->setFB(0); n1->setFB(0);
    } else {
        nodo->setFB(-1); n1->setFB(-1);
    } nodo = n1;
}

void rotDobleDer_Cur (pnodoCiudad &nodo, pnodoCiudad &n1)
{    
	pnodoCiudad n2;
    n2 = n1->getHIzq ();
    nodo->setHDer (n2->getHIzq ());
    n2->setHIzq (nodo);
    n1->setHIzq (n2->getHDer ());
    n2->setHDer (n1);

    if(n2->getFB() == 1) {nodo->setFB(-1);}	
	else {nodo->setFB(0);}
    if(n2->getFB() == -1) {n1->setFB(1);}
	else {n1->setFB(0);}
	
    n2->setFB(0); nodo = n2;
}

void rotDobleIzq_Cur (pnodoCiudad &nodo, pnodoCiudad &n1)
{    
	pnodoCiudad n2;
    n2 = n1->getHDer();
    nodo->setHIzq (n2->getHDer ());
    n2->setHDer (nodo);
    n1->setHDer (n2->getHIzq ());
    n2->setHIzq (n1);

    if(n2->getFB() == 1) {n1->setFB(-1);} 
	else {n1->setFB(0);}
    if(n2->getFB() == -1) {nodo->setFB(1);}
	else {nodo->setFB(0);}
    
	n2->setFB(0); nodo = n2;
}

NodoCiudad::NodoCiudad() 
{
	this->FB = 0;
	//this->codPasillo = 0; 
	this->codPais = 0; 
	this->codCiudad = 0;
	this->nombre = "";
	this->hDer = NULL; 
	this->hIzq = NULL;
	this->dirRest = NULL;
}

NodoCiudad::NodoCiudad (int codPais, int codCiudad, string nombre) 
{
	this->FB = 0;
	//this->codPasillo = codPasillo; 
	this->codPais = codPais; 
	this->codCiudad =codCiudad;
	this->nombre = nombre;
	this->hDer = NULL; 
	this->hIzq = NULL;
	this->dirRest = NULL;
}

void NodoCiudad::insertCiudad (NodoCiudad * &nodo, bool & Hh, int &codPais, int codCiudad, string &nombre)
{
	pnodoCiudad n1, inputAux;
	if (nodo == NULL) 
		{
		nodo = new NodoCiudad (codPais,codCiudad, nombre);
		Hh = true; 
		return;
		}
	
	if (nodo->getcodCiudad() < codCiudad) {
		inputAux = nodo->getHDer (); 
		nodo->insertCiudad (inputAux, Hh, codPais, codCiudad, nombre); 
		nodo->setHDer (inputAux);
        if (Hh) {
            switch (nodo->getFB()) {
            	case -1:
            		nodo->setFB (0); Hh = false;
            		break;
            	case 0:
            		nodo->setFB (1); 
					break;
            	case 1:
					n1 = nodo->getHDer();
            		if(n1->getFB() == 1) {
            			inputAux = nodo; rotSimpleDer_Cur (inputAux, n1); nodo = inputAux;
                    } else { 
						inputAux = nodo; rotDobleDer_Cur (inputAux, n1); nodo = inputAux;
                    } Hh = false; break;
			}
		}
    } 
	else {
    	inputAux = nodo->getHIzq (); nodo->insertCiudad (inputAux, Hh, codPais, codCiudad, nombre); 
		nodo->setHIzq (inputAux);
        if(Hh) {
            switch (nodo->getFB ()) {
                case 1:
				    nodo->setFB (0); Hh = false;
                    break;
                case 0:
				    nodo->setFB (-1);
                    break;
                case -1:         
					n1 = nodo->getHIzq();
                    if(n1->getFB() == -1) {
						inputAux = nodo; rotSimpleIzq_Cur (inputAux, n1); nodo = inputAux;
                    } else {
						inputAux = nodo; rotDobleIzq_Cur (inputAux, n1); nodo = inputAux;
                    } Hh = false; break;
            }
        }
	}
}

NodoCiudad * NodoCiudad::buscarCiudad (int &codCiudad)
{
	if (this->codCiudad == codCiudad) 
		return this;
	
	if (this->codCiudad < codCiudad) {
		if (this->getHDer () == NULL) 
			return NULL;
		else 
			return this->getHDer ()->buscarCiudad (codCiudad);
	} else {
		if (this->getHIzq () == NULL) return NULL;
		else return this->getHIzq ()->buscarCiudad (codCiudad);
	}
}



void equilibrar_Uno_Vent(NodoCiudad*& pNodo, bool& pHh)
{
	NodoCiudad* producto_NUno;
	NodoCiudad* producto_Aux;
	switch (pNodo->getFB()) {
	case -1:
		pNodo->setFB(0); //pNodo->FB = 0;
		break;
	case 0:
		pNodo->setFB(1); //pNodo->FB = 1;
		pHh = false;
		break;
	case 1:
		producto_NUno = pNodo->getHDer();
		if (producto_NUno->getFB() >= 0) {
			if (producto_NUno->getFB() == 0)
				pHh = false;
			producto_Aux = pNodo; rotSimpleDer_Cur(producto_Aux, producto_NUno); pNodo = producto_Aux;
			//RotacionSimpleDerecha(n, n1);
		}
		else {
			producto_Aux = pNodo; rotDobleDer_Cur(producto_Aux, producto_NUno); pNodo = producto_Aux;
			//RotacionDobleDerecha(n, n1);
		}
	}
}

void equilibrar_Dos_Vent(NodoCiudad*& pNodo, bool& pHh)
{
	NodoCiudad* producto_NUno;
	NodoCiudad* producto_Aux;
	switch (pNodo->getFB()) {
	case 1:
		pNodo->setFB(0);//n->FB = 0;
		break;
	case 0:
		pNodo->setFB(-1);//n->FB = -1; //1;
		pHh = false;
		break;
	case -1:
		producto_NUno = pNodo->getHIzq();
		if (producto_NUno->getFB() <= 0) {
			if (producto_NUno->getFB() == 0)
				pHh = false;
			producto_Aux = pNodo; rotSimpleIzq_Cur(producto_Aux, producto_NUno); pNodo = producto_Aux;
			//RotacionSimpleIzquierda(n, n1);
		}
		else {
			producto_Aux = pNodo; rotDobleIzq_Cur(producto_Aux, producto_NUno); pNodo = producto_Aux;
			//RotacionDobleIzquierda(n, n1);
		}
	}
}

void borrar_Vent(NodoCiudad*& pProducto_Sustituto, NodoCiudad*& pNodo, bool& pHh)
{
	NodoCiudad* producto_Aux = NULL;
	NodoCiudad* sustituto_Temp = NULL;

	if (pNodo->getHDer() != NULL) {
		producto_Aux = pNodo->getHDer();
		sustituto_Temp = pNodo->getHDer();

		borrar_Vent(sustituto_Temp, producto_Aux, pHh);

		pProducto_Sustituto = sustituto_Temp;
		pNodo->setHDer(producto_Aux);  //Borrar(D->Hder, Hh);
		if (pHh) {
			if (pNodo->getHDer() == sustituto_Temp)
				pNodo->setHDer(pNodo->getHDer()->getHIzq());
			producto_Aux = pNodo; equilibrar_Dos_Vent(producto_Aux, pHh); pNodo = producto_Aux; //Equilibrar2(D, Hh); 
		}
		else { //Copia y asigna nuevo q

		}
	}
	else
		pHh = true;
}

void borrar_Ciudad_Vent(NodoCiudad*& pNodo, bool& pHh, int& pcodPais)
{
	NodoCiudad* producto_Q = NULL;
	NodoCiudad* producto_Aux = NULL;
	if (pNodo != NULL) {
		if (pcodPais < pNodo->getcodCiudad()) {
			producto_Aux = pNodo->getHIzq(); borrar_Ciudad_Vent(producto_Aux, pHh, pcodPais); pNodo->setHIzq(producto_Aux);
			//BorrarBalanceado (pNodo->getHIzq(), pHh, pcodPais);
			if (pHh)
			{
				producto_Aux = pNodo; equilibrar_Uno_Vent(producto_Aux, pHh); pNodo = producto_Aux;
				//Equilibrar1(raiz, Hh);
				return;
			}
		}
		else {
			if (pcodPais > pNodo->getcodPais()) {
				producto_Aux = pNodo->getHDer(); borrar_Ciudad_Vent(producto_Aux, pHh, pcodPais); pNodo->setHDer(producto_Aux);
				//BorrarBalanceado(raiz->Hder, Hh, x);
				if (pHh)
				{
					producto_Aux = pNodo; equilibrar_Dos_Vent(producto_Aux, pHh); pNodo = producto_Aux;
					//Equilibrar2(raiz, Hh);
					return;
				}
			}
			else {
				producto_Q = pNodo;
			}
		}
		if (pcodPais != pNodo->getcodCiudad())
			return;
		if (producto_Q->getHDer() == NULL) {
			pNodo = producto_Q->getHIzq();
			pHh = true;
		}
		else {
			if (producto_Q->getHIzq() == NULL) {
				pNodo = producto_Q->getHDer();
				pHh = true;
			}
			else {

				NodoCiudad* producto_Sustituto = pNodo->getHIzq();
				producto_Aux = pNodo->getHIzq();

				borrar_Vent(producto_Sustituto, producto_Aux, pHh);

				pNodo->setHIzq(producto_Aux);
				pNodo->setCodigo(producto_Sustituto->getcodCiudad());
				pNodo->setnombre(producto_Sustituto->getnombre());

				if (producto_Sustituto == pNodo->getHIzq()) {
					pNodo->setHIzq(NULL);
					pHh = true;
				}
				producto_Q = producto_Sustituto;
			}
			if (pHh)
			{
				producto_Aux = pNodo; equilibrar_Uno_Vent(producto_Aux, pHh); pNodo = producto_Aux;
				//Equilibrar1(raiz, Hh);
			}
		}
	}
	if (producto_Q != NULL) {
		delete producto_Q;
	}
}



string NodoCiudad::inOrden_Ciudad()
{
	string reporte = "";
	if (this->getHIzq() != NULL)
		reporte += this->getHIzq()->inOrden_Ciudad();
	reporte += "\n\tCodCiudad: "+to_Stiringeo(this->codCiudad)+" - Nombre: "+this->nombre;
	if (this->getHDer()!= NULL)
		reporte += this->getHDer()->inOrden_Ciudad();
	return reporte;
}

void NodoCiudad::imprimir_Arbol()
{	
//	string reporte = "";
	if (this->getHIzq() != NULL)
		this->getHIzq()->imprimir_Arbol();
	cout<< "\n\n\t\t---------\n\t\tCiudad\n";
	cout<< "\n\t\tCodCiudad: "+to_string(this->codCiudad)+ " - Nombre: "+this->nombre;
	if (this->dirRest != NULL)
		this->dirRest->imprimir_Arbol();
	
	if (this->getHDer()!= NULL)
		this->getHDer()->imprimir_Arbol();
	return;
}



void NodoCiudad::setRest (pnodoRest pRest) {this->dirRest = pRest;}
void NodoCiudad::setFB (int FB) {this->FB = FB;}
void NodoCiudad::setnombre (string nombre) {this->nombre = nombre;}
void NodoCiudad::setHDer (NodoCiudad * hijoDer) {this->hDer = hijoDer;}
void NodoCiudad::setHIzq (NodoCiudad * hijoIzq) {this->hIzq = hijoIzq;}
void NodoCiudad::setCodigo(int pCodigo) { this->codPais = pCodigo; }
	
int NodoCiudad::getFB(){return this->FB;}
int NodoCiudad::getcodPais () {return this->codPais;}
int NodoCiudad::getcodCiudad(){return this->codCiudad;}
string NodoCiudad::getnombre () {return this->nombre;}
	
NodoCiudad * NodoCiudad::getHDer () {return this->hDer;}
NodoCiudad * NodoCiudad::getHIzq () {return this->hIzq;}
pnodoRest NodoCiudad::getRest() {return this->dirRest;}
