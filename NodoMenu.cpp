#include "NodoMenu.h"

string to_Stigear(int pNumero)
{
	ostringstream buff;
	buff << pNumero;
	return buff.str();
}

void giro (pnodoMenu &nodo, pnodoMenu &n1)
{
	pnodoMenu n2 = n1;//Por aquello pEsrCurso es ahora nuestro pnodoMenu
	nodo->setHIzq (n1->getHDer());
	n2->setHDer (nodo);
	n2->setNivel (nodo->getNivel());
	nodo = n2;
}

void repartir (pnodoMenu &nodo, pnodoMenu &n1)
{
	pnodoMenu n2 = nodo->getHDer();
	n2->setHDer (n1);
	nodo->setHDer (n2->getHIzq());
	n2->setHIzq (nodo);
	n2->setNivel (nodo->getNivel() + 1);
	nodo = n2;
}

NodoMenu::NodoMenu () 
{
	this->codPais = 0; 
	this->codCiudad = 0;
	this->codRest = 0;
	this->codMenu = 0; 
	this->nombre = "";
	this->nivel = 1;
	this->hDer = NULL;
	this->hIzq = NULL;
}

NodoMenu::NodoMenu (int codPais, int codCiudad, int codRest, int codMenu, string nombre) 
{
	
	this->codPais = codPais; 
	this->codCiudad = codCiudad;
	this->codRest = codRest;
	this->codMenu = codMenu; 
	this->nombre = nombre;
	this->nivel = 1; 
	this->hDer = NULL; 
	this->hIzq = NULL;
}

void NodoMenu::insertMenu (NodoMenu* &nodo, int codPais, int codCiudad, int codRest, int codMenu, string nombre)
{
	pnodoMenu n1, inputAux;
    if(nodo->getcodMenu() < codMenu) {
    	
    	if (nodo->getHDer() == NULL) {
			nodo->setHDer (new NodoMenu (codPais, codCiudad, codRest, codMenu, nombre)); 
			nodo->getHDer()->setNivel (nodo->getNivel()); 
			return;}
			
		if (nodo->getNivel() != nodo->getHDer()->getNivel()) {
			inputAux = nodo->getHDer(); 
			nodo->insertMenu (inputAux, codPais, codCiudad, codRest, codMenu, nombre); 
			nodo->setHDer (inputAux); 
			return;}
		
		if (nodo->getHDer()->getcodMenu() < codMenu) {
			
			if (nodo->getHDer()->getHDer() == NULL) {
				inputAux = nodo; 
				n1 = new NodoMenu (codPais, codCiudad, codRest, codMenu, nombre); 
				repartir (inputAux, n1); 
				nodo = inputAux; 
				return;}
			else {
				n1 = nodo->getHDer()->getHDer(); 
				nodo->insertMenu (n1, codPais, codCiudad, codRest, codMenu, nombre);
				
				if (n1->getNivel() == nodo->getNivel()) {
					inputAux = nodo; 
					repartir (inputAux, n1); 
					nodo = inputAux; 
					return;}
					
				nodo->getHDer()->setHDer (n1); 
				return;
			}
		} else {
			if (nodo->getHDer()->getHIzq() == NULL) {
				n1 = nodo->getHDer(); 
				nodo->setHDer (new NodoMenu (codPais, codCiudad, codRest, codMenu, nombre)); 
				nodo->getHDer()->setNivel (nodo->getNivel()); 
				inputAux = nodo; 
				repartir (inputAux, n1); 
				nodo = inputAux; 
				return;
			} else {
				n1 = nodo->getHDer()->getHIzq(); 
				nodo->insertMenu (n1, codPais, codCiudad, codRest, codMenu, nombre);
				
				if (n1->getNivel() == nodo->getNivel()) {
					inputAux = nodo; 
					repartir (inputAux, n1); 
					nodo = inputAux; 
					return;}
					
				else {
					nodo->getHDer()->setHDer (n1); 
					return;}
			}
		}
    } else {
        if (nodo->getHIzq() == NULL) {
			n1 = new NodoMenu (codPais, codCiudad, codRest, codMenu, nombre); 
			inputAux = nodo; 
			giro (inputAux, n1); 
			nodo = inputAux; 
			
			if (nodo->getHDer()->getHDer() != NULL) {
				n1 = nodo->getHDer()->getHDer(); 
				inputAux = nodo; 
				repartir (inputAux, n1); 
				nodo = inputAux; 
				return;}
				
		} else {
        	inputAux = nodo->getHIzq(); 
			nodo->insertMenu (inputAux, codPais, codCiudad, codRest, codMenu, nombre);
        	if (inputAux->getNivel() == nodo->getNivel()) {
				n1 = inputAux; inputAux = nodo; 
				giro (inputAux, n1); 
				nodo = inputAux; 
				return;}
        	else {nodo->setHIzq (inputAux); 
				return;}
		}
    }
}


/*
void insertMenu(NodoMenu*& nodo, int& codMenu, int& cantStock, int& codCanasta, string& nombre)
{
	pnodoMenu n1, inputAux;
	if (nodo->getcodMenu() < codMenu) {

		if (nodo->getHDer() == NULL) {
			nodo->setHDer(new NodoMenu(codMenu, cantStock, codCanasta, nombre));
			nodo->getHDer()->setNivel(nodo->getNivel());
			return;
		}
		if (nodo->getNivel() != nodo->getHDer()->getNivel()) {
			inputAux = nodo->getHDer();
			insertMenu(inputAux, codMenu, cantStock, codCanasta, nombre);
			nodo->setHDer(inputAux);
			return;
		}

		if (nodo->getHDer()->getcodMenu() < codMenu) {

			if (nodo->getHDer()->getHDer() == NULL) {
				inputAux = nodo;
				n1 = new NodoMenu(codMenu, cantStock, codCanasta, nombre);
				repartir(inputAux, n1);
				nodo = inputAux;
				return;
			}
			else
			{
				n1 = nodo->getHDer()->getHDer();
				insertMenu(n1, codMenu, cantStock, codCanasta, nombre);

				if (n1->getNivel() == nodo->getNivel()) {
					inputAux = nodo;
					repartir(inputAux, n1);
					nodo = inputAux;
					return;
				}

				nodo->getHDer()->setHDer(n1);
				return;
			}
		}
		else {
			if (nodo->getHDer()->getHIzq() == NULL) {
				n1 = nodo->getHDer();
				nodo->setHDer(new NodoMenu(codMenu, cantStock, codCanasta, nombre));
				nodo->getHDer()->setNivel(nodo->getNivel());
				inputAux = nodo;
				repartir(inputAux, n1);
				nodo = inputAux;
				return;
			}
			else {
				n1 = nodo->getHDer()->getHIzq();
				insertMenu(n1, codMenu, cantStock, codCanasta, nombre);

				if (n1->getNivel() == nodo->getNivel()) {
					inputAux = nodo;
					repartir(inputAux, n1);
					nodo = inputAux;
					return;
				}
				else {
					nodo->getHDer()->setHDer(n1);
					return;
				}
			}
		}
	}
	else {
		if (nodo->getHIzq() == NULL) {
			n1 = new NodoMenu(codMenu, cantStock, codCanasta, nombre);
			inputAux = nodo;
			giro(inputAux, n1);
			nodo = inputAux;

			if (nodo->getHDer()->getHDer() != NULL) {
				n1 = nodo->getHDer()->getHDer();
				inputAux = nodo;
				repartir(inputAux, n1);
				nodo = inputAux;
				return;
			}

		}
		else {
			inputAux = nodo->getHIzq();
			insertMenu(inputAux, codMenu, cantStock, codCanasta, nombre);
			if (inputAux->getNivel() == nodo->getNivel()) {
				n1 = inputAux; inputAux = nodo;
				giro(inputAux, n1);
				nodo = inputAux;
				return;
			}
			else {
				nodo->setHIzq(inputAux);
				return;
			}
		}
	}
}*/



NodoMenu * NodoMenu::buscarMenu (int codMenu)
{
	if (this->codMenu == codMenu) {
		return this;}
	if (this->codMenu < codMenu) {
		if (this->getHDer () == NULL) 
			return NULL;
		else 
			return this->getHDer ()->buscarMenu (codMenu);
	} else {
		if (this->getHIzq () == NULL) 
			return NULL;
		else 
			return this->getHIzq ()->buscarMenu (codMenu);
	}
}


void equilibrar_Uno_AA(NodoMenu*& pNodo, bool& pHh)
{
	//cout<<"\nAaah\n";
	pnodoMenu puntero_Aux = NULL;
	if (pNodo->getHIzq() == NULL) {
		if (pNodo->getNivel() == pNodo->getHDer()->getNivel())
		{
			pNodo->setNivel(pNodo->getHDer()->getHIzq()->getNivel());
			if (pNodo->getHDer()->getHIzq()->getHDer() != NULL)
			{
				puntero_Aux = pNodo->getHDer()->getHIzq();
				puntero_Aux->setNivel(pNodo->getHDer()->getNivel());
				pNodo->getHDer()->setHIzq(pNodo->getHDer()->getHIzq()->getHDer());
				puntero_Aux->setHDer(pNodo->getHDer());
				puntero_Aux->setHIzq(pNodo);
				pNodo = puntero_Aux;
				pHh = false;
				return;
			}
			else
			{
				puntero_Aux = pNodo->getHDer();
				pNodo->setHDer(pNodo->getHDer()->getHIzq());
				puntero_Aux->setHIzq(pNodo);
				pNodo = puntero_Aux;
				pHh = false;
				return;
			}
		}
		else {
			//			cout<<"\nEeey\n";
			if (pNodo->getHDer()->getHDer() != NULL) {
				//				cout<<"\nOoooh\n";
				puntero_Aux = pNodo->getHDer();
				puntero_Aux->setNivel(pNodo->getNivel());
				pNodo->setNivel(pNodo->getHDer()->getHDer()->getNivel());

				//pNodo->setHDer( puntero_Aux->getHIzq() );
				pNodo->setHDer(NULL);
				puntero_Aux->setHIzq(pNodo);
				pNodo = puntero_Aux;
				pHh = false;
				return;
			}
			else {
				pNodo->getHDer()->setNivel(pNodo->getNivel());
				pHh = false;
				return;
			}
		}
	}
}

void equilibrar_Dos_AA(NodoMenu*& pNodo, bool& pHh)
{
	pnodoMenu puntero_Aux = NULL;
	if (pNodo->getHDer() == NULL) {
		if (pNodo->getHIzq() != NULL)
		{
			puntero_Aux = pNodo->getHIzq();
			if (puntero_Aux->getHDer() != NULL)
			{
				puntero_Aux->setNivel(pNodo->getNivel());
				pNodo->setNivel(puntero_Aux->getHDer()->getNivel());
				puntero_Aux->setHIzq(puntero_Aux->getHDer());
				puntero_Aux->setHDer(pNodo);
				pNodo = puntero_Aux;
				pHh = false;
				return;
			}
			else
			{
				puntero_Aux->setNivel(pNodo->getNivel());
				puntero_Aux->setHDer(pNodo);
				pNodo = puntero_Aux;
				pHh = false;
				return;
			}

		}
	}
}

void borrar_AA(NodoMenu*& pProducto_Sustituto, NodoMenu*& pNodo, bool& pHh)
{
	pnodoMenu puntero_Aux = NULL;
	if (pNodo->getHIzq()->getHDer() == NULL && pNodo->getHDer()->getHDer() == NULL)
	{
		puntero_Aux = pNodo->getHIzq();
		puntero_Aux->setHDer(pNodo->getHDer());
		pProducto_Sustituto = puntero_Aux;
		pHh = false;
		return;
	}
	if (pNodo->getHDer()->getHIzq() != NULL && pNodo->getNivel() == pNodo->getHDer()->getNivel())
	{
		puntero_Aux = pNodo->getHDer()->getHIzq();
		puntero_Aux->setNivel(pNodo->getNivel());
		puntero_Aux->setHIzq(pNodo->getHIzq());
		puntero_Aux->setHDer(pNodo->getHDer());

		pNodo->getHDer()->setHIzq(NULL);
		puntero_Aux->getHDer()->setNivel(puntero_Aux->getHIzq()->getNivel());
		pProducto_Sustituto = puntero_Aux;
		pHh = false;
		return;
	}
	if (pNodo->getHIzq()->getHDer() != NULL)// && pNodo->getHDer()->getHDer() != NULL)
	{
		puntero_Aux = pNodo->getHIzq()->getHDer();
		pNodo->getHIzq()->setHDer(NULL);
		puntero_Aux->setNivel(pNodo->getNivel());
		puntero_Aux->setHDer(pNodo->getHDer());
		puntero_Aux->setHIzq(pNodo->getHIzq());
		pProducto_Sustituto = puntero_Aux;
		pHh = false;
		return;
	}
	if (pNodo->getHIzq()->getHDer() == NULL)
	{
		puntero_Aux = pNodo->getHDer();
		puntero_Aux->setNivel(pNodo->getNivel());
		puntero_Aux->setHIzq(pNodo->getHIzq());
		pProducto_Sustituto = puntero_Aux;
		pHh = false;
		return;
	}
}

void borrar_Menu_AA(NodoMenu*& pNodo, bool& pHh, int& pcodMenu)
{
	NodoMenu* marca_Q = NULL;
	NodoMenu* marca_Aux = NULL;

	if (pNodo != NULL) {
		if (pcodMenu < pNodo->getcodMenu()) {
			marca_Aux = pNodo->getHIzq();
			borrar_Menu_AA(marca_Aux, pHh, pcodMenu);
			pNodo->setHIzq(marca_Aux);
			if (pHh)
			{
				marca_Aux = pNodo; equilibrar_Uno_AA(marca_Aux, pHh); pNodo = marca_Aux;
				//	    		cout<<"Subio -> "<<pNodo->getcodMenu()<<" - Nivel: "<<pNodo->getNivel() <<"\n";
				//	    		if(pNodo->getHDer() != NULL)
				//                	cout<<"HDer -> "<<pNodo->getHDer()->getcodMenu()<<" - Nivel: "<<pNodo->getHDer()->getNivel() <<"\n";
				//	    		if(pNodo->getHIzq() != NULL)
				//                	cout<<"HIzq -> "<<pNodo->getHIzq()->getcodMenu()<<" - Nivel: "<<pNodo->getHIzq()->getNivel() <<"\n";
			}
			else
				//	    		cout<<"Subio ---> "<<pNodo->getcodMenu()<<" - Nivel: "<<pNodo->getNivel() <<"\n";
				return;
		}
		else {
			if (pcodMenu > pNodo->getcodMenu()) {
				marca_Aux = pNodo->getHDer();
				borrar_Menu_AA(marca_Aux, pHh, pcodMenu);
				pNodo->setHDer(marca_Aux);
				if (pNodo != NULL)
					//				cout<<"\nUUUHSubio ---> "<<pNodo->getcodMenu()<<" - Nivel: "<<pNodo->getNivel() <<"\n";
					if (pHh)
					{
						marca_Aux = pNodo; equilibrar_Dos_AA(marca_Aux, pHh); pNodo = marca_Aux;

					}return;
			}
			else {
				marca_Q = pNodo;
			}
		}

		if (pcodMenu != pNodo->getcodMenu())
			return;

		if (marca_Q->getHDer() == NULL) {
			pNodo = marca_Q->getHIzq();
			pHh = true;
		}
		else {
			if (marca_Q->getHIzq() == NULL) {
				pNodo = marca_Q->getHDer();
				pHh = true;
			}
			else {

				NodoMenu* marca_Sustituta = marca_Q;
				marca_Aux = marca_Q;

				borrar_AA(marca_Sustituta, marca_Aux, pHh);

				pNodo = marca_Sustituta;
				marca_Q = marca_Aux;
			}
		}
	}
	if (marca_Q != NULL) {
		delete marca_Q;
	}
}



string NodoMenu::inOrden_Menu() 
{
	string reporte = "";
	if (this->getHIzq() != NULL)
		reporte += this->getHIzq()->inOrden_Menu();
	reporte += "\n\tCodPais: "+to_string(this->codPais)+" - CodCiudad: "+to_string(this->codCiudad)+" - CodRestaurante: "+to_string(this->codRest)+" - Nombre: "+this->nombre;
	if (this->getHDer()!= NULL)
		reporte += this->getHDer()->inOrden_Menu();
	return reporte;
}

bool NodoMenu::verificarMenu (bool i, int codMenu) 
{
	if(this==NULL){
        return i;
    }else{
		if (this->getcodMenu()==codMenu){
			return i=true;
		}
		else{
			
			i=this->hIzq->verificarMenu(i,codMenu);
			i=this->hDer->verificarMenu(i,codMenu);	
		} 
    }
}

string NodoMenu::imprimir_Arbol()
{
	string reporte = "";
	if (this->getHIzq() != NULL)
		reporte += this->getHIzq()->imprimir_Arbol();
		
	reporte += "\n\t\t\t\t------\n\t\t\t\tMenu";
	reporte += "\n\t\t\t\tCodPais: " + to_string(this->codPais) + " - CodCiudad: " + to_string(this->codCiudad);
	reporte += " -CodRestaurante: "+to_string(this->codRest) + " - CodMenu: " + to_string(this->codMenu)+" - Nombre: "+this->nombre;
	if (this->dirProducto != NULL)
		reporte += this->dirProducto->imprimir_Arbol();
	if (this->getHDer()!= NULL)
		reporte += this->getHDer()->imprimir_Arbol();
	return reporte;
}

//getters.

int NodoMenu::getcodMenu () {return this->codMenu;}
int NodoMenu::getcodPais() {return this->codPais;}
int NodoMenu::getcodCiudad(){return this->codCiudad;}
string NodoMenu::getNombre(){return this->nombre;}
int	NodoMenu::getNivel () {return this->nivel;}
pnodoProducto NodoMenu::getdirProducto(){return this->dirProducto;}
NodoMenu* NodoMenu::getHDer () {return this->hDer;}
NodoMenu* NodoMenu::getHIzq () {return this->hIzq;}

//setters.

void NodoMenu::setNombre (string pNombre) {this->nombre = pNombre;}
void NodoMenu::setcodPais(int pcodPais) {this->codPais = pcodPais;}
void NodoMenu::setHDer(NodoMenu* hijo) {this->hDer = hijo;}
void NodoMenu::setHIzq(NodoMenu* hijo) {this->hIzq = hijo;}
void NodoMenu::setNivel(int nivel) {this->nivel = nivel;}
void NodoMenu::setdirProducto(pnodoProducto prod) {this->dirProducto = prod;}
