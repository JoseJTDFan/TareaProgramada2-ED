#include "NodoProducto.h"


void rotSimpleDer_Cur (pnodoProducto &nodo, pnodoProducto &n1)
{
    nodo->setHDer(n1->getHIzq());
	n1->setHIzq(nodo);
	
    if(n1->getFB() == 1) {
        nodo->setFB(0); n1->setFB(0);
    } else {
        nodo->setFB(1); n1->setFB(-1);
    } nodo = n1;
}

void rotSimpleIzq_Cur (pnodoProducto &nodo, pnodoProducto &n1)
{
	nodo->setHIzq(n1->getHDer());
    n1->setHDer(nodo);

    if(n1->getFB()==-1) {
        nodo->setFB(0); n1->setFB(0);
    } else {
        nodo->setFB(-1); n1->setFB(-1);
    } nodo = n1;
}

void rotDobleDer_Cur (pnodoProducto &nodo, pnodoProducto &n1)
{    
	pnodoProducto n2;
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

void rotDobleIzq_Cur (pnodoProducto &nodo, pnodoProducto &n1)
{    
	pnodoProducto n2;
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

NodoProducto::NodoProducto() 
{
	this->FB = 0;
	//this->codPasillo = 0;
	this->codPais = 0;
	this->codCiudad =0;
	this->codRest =0;
	this->codMenu =  0;
	this->codProducto = 0; 
	this->nombre = "";
	this->kcal = 0;
	this->precio =0;
	this->cantidad =0;
	this->hDer = NULL; 
	this->hIzq = NULL;
}

NodoProducto::NodoProducto (int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, int cantidad) 
{
	this->FB = 0;
	this->codPais = codPais;
	this->codCiudad =codCiudad;
	this->codRest =codRest;
	this->codMenu = codMenu;
	this->codProducto = codProducto; 
	this->nombre = nombre;
	this->kcal = kcal;
	this->precio =precio;
	this->cantidad =cantidad;
	this->hDer = NULL; 
	this->hIzq = NULL;
}

void NodoProducto::insertProducto (NodoProducto * &nodo, bool & Hh, int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, int cantidad)
{
	pnodoProducto n1, inputAux;
	if (nodo == NULL) 
		{
		nodo = new NodoProducto (codPais, codCiudad, codRest, codMenu, codProducto, nombre, kcal, precio, cantidad);
		Hh = true; 
		return;
		}
	
	if (nodo->getcodProducto() < codProducto) {
		inputAux = nodo->getHDer (); 
		nodo->insertProducto (inputAux, Hh, codPais, codCiudad, codRest, codMenu, codProducto, nombre, kcal, precio, cantidad);
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
    	inputAux = nodo->getHIzq (); nodo->insertProducto (inputAux, Hh, codPais, codCiudad, codRest, codMenu, codProducto, nombre, kcal, precio, cantidad);
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

NodoProducto * NodoProducto::buscarProducto (int &codProducto)
{
	if (this->codProducto == codProducto) 
		return this;
	
	if (this->codProducto < codProducto) {
		if (this->getHDer () == NULL) 
			return NULL;
		else 
			return this->getHDer ()->buscarProducto (codProducto);
	} else {
		if (this->getHIzq () == NULL) return NULL;
		else return this->getHIzq ()->buscarProducto (codProducto);
	}
}



void equilibrar_Uno_Vent(NodoProducto*& pNodo, bool& pHh)
{
	NodoProducto* producto_NUno;
	NodoProducto* producto_Aux;
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

void equilibrar_Dos_Vent(NodoProducto*& pNodo, bool& pHh)
{
	NodoProducto* producto_NUno;
	NodoProducto* producto_Aux;
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

void borrar_Vent(NodoProducto*& pProducto_Sustituto, NodoProducto*& pNodo, bool& pHh)
{
	NodoProducto* producto_Aux = NULL;
	NodoProducto* sustituto_Temp = NULL;

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

void borrarProducto_Vent(NodoProducto*& pNodo, bool& pHh, int& pCodProducto)
{
	NodoProducto* producto_Q = NULL;
	NodoProducto* producto_Aux = NULL;
	if (pNodo != NULL) {
		if (pCodProducto < pNodo->getcodProducto()) {
			producto_Aux = pNodo->getHIzq(); borrarProducto_Vent(producto_Aux, pHh, pCodProducto); pNodo->setHIzq(producto_Aux);
			//BorrarBalanceado (pNodo->getHIzq(), pHh, pCodProducto);
			if (pHh)
			{
				producto_Aux = pNodo; equilibrar_Uno_Vent(producto_Aux, pHh); pNodo = producto_Aux;
				//Equilibrar1(raiz, Hh);
				return;
			}
		}
		else {
			if (pCodProducto > pNodo->getcodProducto()) {
				producto_Aux = pNodo->getHDer(); borrarProducto_Vent(producto_Aux, pHh, pCodProducto); pNodo->setHDer(producto_Aux);
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
		if (pCodProducto != pNodo->getcodProducto())
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

				NodoProducto* producto_Sustituto = pNodo->getHIzq();
				producto_Aux = pNodo->getHIzq();

				borrar_Vent(producto_Sustituto, producto_Aux, pHh);

				pNodo->setHIzq(producto_Aux);
				pNodo->setcodProducto(producto_Sustituto->getcodProducto());
				pNodo->setnombre(producto_Sustituto->getNombre());

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



void NodoProducto::inOrdenProducto()
{
//	string reporte = "";
	if (this->getHIzq() != NULL)
		 this->getHIzq()->inOrdenProducto();
	cout<< "\n\tCodProducto: "+to_string(this->codProducto);
	cout<<" - Nombre: ";
	cout<<this->nombre;
	cout<<" - Calorias: ";
	cout<<to_string(this->kcal);
	cout<<" - Precio: ";
	cout<<to_string(this->precio);
	cout<<" - Cantidad: ";
	cout<<to_string(this->cantidad);
	if (this->getHDer()!= NULL)
		this->getHDer()->inOrdenProducto();
	return ;
}

string NodoProducto::preOrdenProducto()
{
	string reporte = "";
	reporte += "\n\tCodProducto: "+to_string(this->codProducto);
	reporte += " - Nombre: ";
	reporte += this->nombre;
	reporte += " - Calorias: ";
	reporte += to_string(this->kcal);
	reporte += " - Precio: ";
	reporte += to_string(this->precio);
	reporte += " - Cantidad: ";
	reporte += to_string(this->cantidad) + "\n";
	
	if (this->getHIzq() != NULL)
		reporte += this->getHIzq()->preOrdenProducto();

	if (this->getHDer()!= NULL)
		reporte += this->getHDer()->preOrdenProducto();
	return reporte;
}

void NodoProducto::imprimir_Arbol()
{	
//	string reporte = "";
	if (this->getHIzq() != NULL)
		 this->getHIzq()->imprimir_Arbol();
	cout<< "\n\t\t\t---------\n\t\t\tProducto\n";
	cout<< "\n\t\t\tCodigo: ";
	cout<<to_string(this->codProducto);
	cout<<" - Nombre: ";
	cout<<this->nombre;
	if (this->getHDer()!= NULL)
		this->getHDer()->imprimir_Arbol();
	return;
}


void NodoProducto::setFB (int FB) {this->FB = FB;}
void NodoProducto::setHDer (NodoProducto * hijoDer) {this->hDer = hijoDer;}
void NodoProducto::setHIzq (NodoProducto * hijoIzq) {this->hIzq = hijoIzq;}

void NodoProducto::setcodProducto(int pcodProducto) { this->codProducto = pcodProducto; }
void NodoProducto::setnombre (string nombre) {this->nombre = nombre;}
void NodoProducto::setkcal (int pkcal){this->kcal = pkcal;}
void NodoProducto::setprecio (int pprecio){this->precio = pprecio;}
void NodoProducto::setcantidad (int pcantidad){this->cantidad = pcantidad;}
	
int NodoProducto::getFB(){return this->FB;}
NodoProducto * NodoProducto::getHDer () {return this->hDer;}
NodoProducto * NodoProducto::getHIzq () {return this->hIzq;}

int NodoProducto::getcodPais(){return this->codPais;}
int NodoProducto::getcodCiudad(){return this->codCiudad;}
int NodoProducto::getcodRest(){return this->codRest;}
int NodoProducto::getcodMenu(){return this->codMenu;}
int NodoProducto::getcodProducto () {return this->codProducto;}
string NodoProducto::getNombre () {return this->nombre;}
int NodoProducto::getkcal(){return this->kcal;}
int NodoProducto::getprecio(){return this->precio;}
int NodoProducto::getcantidad(){return this->cantidad;}
	

