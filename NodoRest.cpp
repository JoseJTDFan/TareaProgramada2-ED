#include "NodoRest.h"

string to_Stiringeo(int pNumero)
{
	ostringstream buff;
	buff << pNumero;
	return buff.str();
}

void rotSimpleDer_Gr (pnodoRest & nodo, pnodoRest & n1)
{
    if (nodo->getHIzq() != NULL && nodo->getHIzq()->getRojo()) {
    	nodo->getHIzq()->setRojo (false);
    	n1->setRojo (false);
    	nodo->setRojo (true);
    	return;
	} else {
		if (n1->getHIzq() != NULL) n1->getHIzq()->setPadre (nodo);
        
		nodo->setHDer(n1->getHIzq());
	    n1->setHIzq (nodo);
	    
	    n1->setPadre (nodo->getPadre());
	    nodo->setPadre (n1);
	    
	    n1->setRojo (false);
	    nodo->setRojo (true);
        nodo = n1;
    }
}

void rotSimpleIzq_Gr (pnodoRest & nodo, pnodoRest & n1)
{
	if (nodo->getHDer() != NULL && nodo->getHDer()->getRojo()) {
    	nodo->getHDer()->setRojo (false);
    	n1->setRojo (false);
    	nodo->setRojo (true);
    	return;
    } else {
    	if (n1->getHDer() != NULL) n1->getHDer()->setPadre (nodo);
    	
	    nodo->setHIzq (n1->getHDer());
        n1->setHDer (nodo);
        
        n1->setPadre (nodo->getPadre());
	    nodo->setPadre (n1);

        n1->setRojo (false);
	    nodo->setRojo (true);
        nodo = n1;
    }
}

void rotDobleDer_Gr (pnodoRest & nodo, pnodoRest & n1)
{
    if (nodo->getHIzq() != NULL && nodo->getHIzq()->getRojo()) {
    	nodo->getHIzq()->setRojo (false);
    	n1->setRojo (false);
    	nodo->setRojo (true);
    	return;
    } else {
	    pnodoRest n2;
        n2 = n1->getHIzq();
    
	    if (n2->getHIzq() != NULL) n2->getHIzq()->setPadre(nodo);
        
	    nodo->setHDer (n2->getHIzq());
	    n2->setHIzq (nodo);
    
        if (n2->getHDer() != NULL) n2->getHDer()->setPadre(n1);

	    n1->setHIzq (n2->getHDer());
        n2->setHDer (n1);
    
        n2->setPadre (nodo->getPadre());
        n2->getHDer()->setPadre (n2);
        n2->getHIzq()->setPadre (n2);

        n2->setRojo (false);
	    nodo->setRojo (true);
        nodo = n2;
    }
}

void rotDobleIzq_Gr (pnodoRest & nodo, pnodoRest & n1)
{	
	if (nodo->getHDer() != NULL && nodo->getHDer()->getRojo()) {
    	nodo->getHDer()->setRojo (false);
    	n1->setRojo (false);
    	nodo->setRojo (true);
    	return;
    } else {
		pnodoRest n2;
    	n2 = n1->getHDer();
    
    	if (n2->getHDer() != NULL) n2->getHDer()->setPadre(nodo);
    
    	nodo->setHIzq(n2->getHDer());
    	n2->setHDer(nodo);
    
    	if (n2->getHIzq() != NULL) n2->getHIzq()->setPadre(n1);
    
    	n1->setHDer (n2->getHIzq());
    	n2->setHIzq (n1);
    
    	n2->setPadre (nodo->getPadre());
    	n2->getHDer()->setPadre (n2);
    	n2->getHIzq()->setPadre (n2);

    	n2->setRojo (false);
		nodo->setRojo (true);
		nodo = n2;
    }
}

NodoRest::NodoRest()
{
	this->rojo = true;
	this->codPais = 0; 
	this->codCiudad = 0; 
	this->codRest = 0;
	this->nombre="";
	this->padre = NULL;
	this->hDer = NULL;
	this->hIzq = NULL;
}

NodoRest::NodoRest (int codPais, int codCiudad, int codRest, string nombre) 
{
	
	this->rojo = true;
	this->codPais = codPais;
	this->codCiudad = codCiudad;
	this->codRest = codRest;
	this->nombre=nombre;
	this->padre = NULL;
	this->hDer = NULL;
	this->hIzq = NULL;
}

void NodoRest::insertRest (NodoRest* &nodo, bool  Hh, int codPais, int codCiudad, int codRest, string nombre)
{
	pnodoRest n1, inputAux;

    if(nodo == NULL) {
		nodo = new NodoRest (codPais, codCiudad, codRest, nombre); 
		Hh = true; 
		return;
	}
    if(nodo->getcodRest() < codRest){
    	inputAux = nodo->getHDer(); 
		insertRest (inputAux, Hh, codPais, codCiudad, codRest, nombre);
        
        if (nodo == inputAux->getHIzq() || nodo == inputAux->getHDer() || nodo == inputAux) {
			nodo = inputAux;
			}
		else {
			inputAux->setPadre (nodo); 
			nodo->setHDer (inputAux);
			}
		
		if (Hh) {
			if (nodo->getRojo() && nodo->getHDer()->getRojo()) {
            	if (nodo->getPadre() != NULL) {
            		n1 = nodo;
					if (nodo->getPadre()->getcodRest() < codPais) {
						inputAux = nodo->getPadre(); 
						rotSimpleDer_Gr (inputAux, n1); 
						nodo = inputAux;
					} else {
						inputAux = nodo->getPadre(); 
						rotDobleIzq_Gr (inputAux, n1); 
						nodo = inputAux;
					}
				}
			}
        }
    } else {
    	inputAux = nodo->getHIzq(); 
		insertRest (inputAux, Hh, codPais, codCiudad, codRest, nombre);
            
        if (nodo == inputAux->getHIzq() || nodo == inputAux->getHDer() || nodo == inputAux) {
			nodo = inputAux;
			}
		else {
			inputAux->setPadre (nodo); 
			nodo->setHIzq (inputAux);
		}
        
		if(Hh==true) {
			if (nodo->getRojo() && nodo->getHIzq()->getRojo()) {
            	if (nodo->getPadre() != NULL){
            		n1 = nodo;
					if (nodo->getPadre()->getcodRest() >= codPais) {
						inputAux = nodo->getPadre(); 
						rotSimpleIzq_Gr (inputAux, n1); 
						nodo = inputAux;
					} else {
						inputAux = nodo->getPadre(); 
						rotDobleDer_Gr (inputAux, n1); 
						nodo = inputAux;
					}
				}
			}
        }
    }
}

NodoRest * NodoRest::buscarRest (int codRest) 
{
	if (this->codRest == codRest) {
		return this;
	}
	if (this->codRest < codRest) {
		if (this->getHDer () == NULL)
			return NULL;
		else
			return this->getHDer ()->buscarRest (codRest);
	} else {
		if (this->getHIzq () == NULL)
			return NULL;
		else 
			return this->getHIzq ()->buscarRest (codRest);
	}	
}

void NodoRest::mostrarMarca ()
{
	if(this==NULL){
        return;
	}else{
		if(this->hIzq!=NULL)
        	this->hIzq->mostrarMarca();
        cout<<this->codRest<<" <> ";
        if (this->hDer)
			this->hDer->mostrarMarca();
    }
}

bool NodoRest::verificarMarca (bool i, int pcodRest) 
{
	if(this==NULL){
        return i;
    }else{
		if (this->getcodRest()==pcodRest){
			return i=true;
		}
		else{
			if(this->hIzq!=NULL)
				i=this->hIzq->verificarMarca(i,pcodRest);
			if(this->hDer!=NULL)
				i=this->hDer->verificarMarca(i,pcodRest);	
		} 
    }
}


void equilibrar_Uno_RN(pnodoRest& pNodo, bool& pHh, int& pcodRest)
{
	pnodoRest producto_NUno = NULL;
	pnodoRest producto_Aux = NULL;
	producto_Aux = pNodo->getHDer();

	if (pNodo == producto_Aux->getHIzq() || pNodo == producto_Aux->getHDer() || pNodo == producto_Aux) {
		pNodo = producto_Aux;
	}
	else {
		producto_Aux->setPadre(pNodo);
		pNodo->setHDer(producto_Aux);
	}
	if (pHh) {
		if (pNodo->getRojo() && pNodo->getHDer()->getRojo()) {
			if (pNodo->getPadre() != NULL) {
				producto_NUno = pNodo;
				pHh = false;
				if (pNodo->getPadre()->getcodRest() < pcodRest) {
					//pHh = false;
					producto_Aux = pNodo->getPadre();
					rotSimpleDer_Gr(producto_Aux, producto_NUno);
					pNodo = producto_Aux;
				}
				else {
					//pHh = false;
					producto_Aux = pNodo->getPadre();
					rotDobleIzq_Gr(producto_Aux, producto_NUno);
					pNodo = producto_Aux;
				}
			}
		}
	}
}

void equilibrar_Dos_RN(pnodoRest& pNodo, bool& pHh, int& pcodPais)
{
	pnodoRest producto_NUno = NULL;
	pnodoRest producto_Aux = NULL;
	producto_Aux = pNodo->getHIzq();     //inputAux = nodo->getHIzq();

	if (pNodo == producto_Aux->getHIzq() || pNodo == producto_Aux->getHDer() || pNodo == producto_Aux) {
		pNodo = producto_Aux;
	}
	else
	{
		producto_Aux->setPadre(pNodo);
		pNodo->setHIzq(producto_Aux);
	}

	if (pHh) {
		if (pNodo->getRojo() && pNodo->getHIzq()->getRojo()) {
			if (pNodo->getPadre() != NULL) {
				producto_NUno = pNodo;
				pHh = false;
				if (pNodo->getPadre()->getcodRest() >= pcodPais) { //pHh = false;
					producto_Aux = pNodo->getPadre();
					rotSimpleIzq_Gr(producto_Aux, producto_NUno);
					pNodo = producto_Aux;
				}
				else { //pHh = false;
					producto_Aux = pNodo->getPadre();
					rotDobleDer_Gr(producto_Aux, producto_NUno);
					pNodo = producto_Aux;
				}
			}
		}
	}
}

void borrar_RN(pnodoRest& pProducto_Sustituto, pnodoRest& pNodo, bool& pHh)
{
	pnodoRest marca_Aux = NULL;
	pnodoRest sustituto_Temp = NULL;

	if (pNodo->getHDer() != NULL) {
		marca_Aux = pNodo->getHDer();
		sustituto_Temp = pNodo->getHDer();

		borrar_RN(sustituto_Temp, marca_Aux, pHh);

		pProducto_Sustituto = sustituto_Temp;
		pNodo->setHDer(marca_Aux);  //Borrar(D->Hder, Hh);
		if (pHh) {
			int codeMarca = pProducto_Sustituto->getcodPais();

			if (pNodo->getHDer() == sustituto_Temp) {
				pNodo->setHDer(pNodo->getHDer()->getHIzq());
			}

			if (pNodo->getHDer() != NULL) {//equilibrar_Dos_RN
				marca_Aux = pNodo; equilibrar_Uno_RN(marca_Aux, pHh, codeMarca); pNodo = marca_Aux;//equilibrar_Dos_RN (marca_Aux, pHh, codeMarca); pNodo = marca_Aux; //Equilibrar2(D, Hh); 
			}
		}
		else { //Copia y asigna nuevo q

		}
	}
	else
		pHh = true;
}

void borrar_Rest_RN(pnodoRest& pNodo, bool& pHh, int& pcodRest)
{
	pnodoRest marca_Q = NULL;
	pnodoRest marca_Aux = NULL;
	int codigoMarca = 0;

	if (pNodo != NULL) {
		if (pcodRest < pNodo->getcodRest()) {
			//            	cout<<"\naaaah\n\n";
			marca_Aux = pNodo->getHIzq(); borrar_Rest_RN(marca_Aux, pHh, pcodRest); pNodo->setHIzq(marca_Aux);
			//BorrarBalanceado (pNodo->getHIzq(), pHh, pCodProducto);
			if (pHh)
			{
				codigoMarca = pcodRest;//pNodo->getcodPais();
				marca_Aux = pNodo; equilibrar_Uno_RN(marca_Aux, pHh, codigoMarca); pNodo = marca_Aux;
				//Equilibrar1(raiz, Hh);
				return;
			}
		}
		else {
			if (pcodRest > pNodo->getcodRest()) {
				//            	cout<<"\nMa bro\n\n";
				marca_Aux = pNodo->getHDer(); borrar_Rest_RN(marca_Aux, pHh, pcodRest); pNodo->setHDer(marca_Aux);
				//	    		cout<<"\n---------------------------\n\n";
								//BorrarBalanceado(raiz->Hder, Hh, x);
				if (pHh)
				{
					codigoMarca = pcodRest;//pNodo->getcodPais();
					marca_Aux = pNodo; equilibrar_Dos_RN(marca_Aux, pHh, codigoMarca); pNodo = marca_Aux;
					//Equilibrar2(raiz, Hh);
					return;
				}
			}
			else {
				marca_Q = pNodo;
			}
		}

		if (pcodRest != pNodo->getcodRest())
			return;
		//        cout<<"Pasa";
		if (marca_Q->getHDer() == NULL) {
			//	    	cout<<"\nMy no comprender\n\n";
			//	    	cout<<"\nValor: "<< marca_Q->getcodPais()  <<"\n\n";


			delete pNodo;
			pNodo = marca_Q->getHIzq();

			/*
			pNodo = marca_Q->getHIzq();
			pHh = true;
			*/
			//        	cout<<"\nFlagante\n\n";
			return;
		}
		else {
			if (marca_Q->getHIzq() == NULL) {
				//            	cout<<"\nay\n\n";
				pNodo = marca_Q->getHDer();
				pHh = true;
			}
			else {

				pnodoRest marca_Sustituto = pNodo->getHIzq();
				marca_Aux = pNodo->getHIzq();

				borrar_RN(marca_Sustituto, marca_Aux, pHh);

				pNodo->setHIzq(marca_Aux);
				pNodo->setCodigo(marca_Sustituto->getcodRest());
				pNodo->setNombre(marca_Sustituto->getnombre());

				if (marca_Sustituto == pNodo->getHIzq()) {
					pNodo->setHIzq(NULL);
					pHh = true;
				}
				marca_Q = marca_Sustituto;
			}
			if (pHh)
			{
				codigoMarca = pcodRest;//pNodo->getcodPais();
				marca_Aux = pNodo; equilibrar_Uno_RN(marca_Aux, pHh, codigoMarca); pNodo = marca_Aux;
				//Equilibrar1(raiz, Hh);
			}
		}
	}
	if (marca_Q != NULL) {
		//    	cout<<"\nborra q\n\n";
		delete marca_Q;
		//    	cout<<"\nborra q Finaliza\n\n";
	}
}



string NodoRest::inOrden_Rest ()
{
	string reporte = "";
	if (this->getHIzq() != NULL)
		reporte += this->getHIzq()->inOrden_Rest();
	reporte += "\n\tCodRestaurante: "+to_Stiringeo(this->codRest)+" - Nombre: "+this->nombre;
	if (this->getHDer()!= NULL)
		reporte += this->getHDer()->inOrden_Rest();
	return reporte;
}

void NodoRest::imprimir_Arbol()
{
//	string reporte = "";
	if (this->getHIzq() != NULL)
		this->getHIzq()->imprimir_Arbol();
		
	cout<< "\n\t\t\t------\n\t\t\tRestaurante\t";
	cout<< "\n\t\t\tCodPais: " + to_string(this->codPais) + " - CodCiudad: " + to_string(this->codCiudad);
	cout<< " -CodRestaurante: "+to_string(this->codRest) +" - Nombre: "+this->nombre;
	if (this->dirMenu != NULL)
		 this->dirMenu->imprimir_Arbol();
	if (this->getHDer()!= NULL)
		 this->getHDer()->imprimir_Arbol();
	return;
}


void NodoRest::setNombre (string pNombre) {this->nombre = pNombre;}
void NodoRest::setRojo (bool rojo) {this->rojo = rojo;}
void NodoRest::setcodRest (int pcodRest) {this->codRest = pcodRest;}
void NodoRest::setPadre (NodoRest * padre) {this->padre = padre;}
void NodoRest::setHDer (NodoRest * hijoDer) {this->hDer = hijoDer;}
void NodoRest::setHIzq (NodoRest * hijoIzq) {this->hIzq = hijoIzq;}
/*void NodoRest::setcodRest(int codRest){
	this->codRest=codRest;
}*/
void NodoRest::setMenu (pnodoMenu pMenu){this->dirMenu=pMenu;}
void NodoRest::setcodCiudad(int pcodCiudad) {this->codCiudad=pcodCiudad;}
void NodoRest::setCodigo(int pCodigo) { this->codPais = pCodigo; }

bool NodoRest::getRojo () {return this->rojo;}
int NodoRest::getcodPais () {return this->codPais;}
int NodoRest::getcodCiudad() {return this->codCiudad;}
int NodoRest::getcodRest(){return this->codRest;}
string NodoRest::getnombre(){return this->nombre;}
pnodoMenu NodoRest::getMenu (){return this->dirMenu;}
NodoRest * NodoRest::getPadre () {return this->padre;}
NodoRest * NodoRest::getHDer () {return this->hDer;}
NodoRest * NodoRest::getHIzq () {return this->hIzq;}

