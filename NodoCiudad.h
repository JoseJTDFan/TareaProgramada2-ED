
#pragma once
#include <iostream>
#include "NodoRest.h"

using namespace std;

class NodoCiudad { //AVL

	private:
		
		int FB;
		int codPais, codCiudad;
		string nombre;
		NodoCiudad * hDer;
		NodoCiudad * hIzq;
		pnodoRest dirRest;
		
	public:
		
		NodoCiudad ();
		NodoCiudad (int codPais, int codCiudad, string nombre) ;
		void insertCiudad (NodoCiudad * &nodo, bool & Hh, int &codPais, int codCiudad, string &nombre);
		NodoCiudad * buscarCiudad (int &codCiudad);
		string toString ();
		
		void setFB(int FB);
		void setnombre (string nombre);
		void setHDer (NodoCiudad * hijoDer);
		void setHIzq (NodoCiudad * hijoIzq);
		void setRest (pnodoRest pRest);
		void setCodigo(int pCodigo);
		
		string inOrden_Ciudad();
		string imprimir_Arbol ();
		
		
		
		int getFB();
		int getcodPais ();
		int getcodCiudad();
		string getnombre ();
		NodoCiudad * getHDer ();
		NodoCiudad * getHIzq ();
		pnodoRest getRest ();
};

typedef NodoCiudad * pnodoCiudad;

void rotSimpleDer_Cur (pnodoCiudad &nodo, pnodoCiudad &n1);
void rotSimpleIzq_Cur (pnodoCiudad &nodo, pnodoCiudad &n1);
void rotDobleDer_Cur (pnodoCiudad &nodo, pnodoCiudad &n1);
void rotDobleIzq_Cur (pnodoCiudad &nodo, pnodoCiudad &n1);

void equilibrar_Uno_Vent(NodoCiudad*& pNodo, bool& pHh);
void equilibrar_Dos_Vent(NodoCiudad*& pNodo, bool& pHh);
void borrar_Vent(NodoCiudad*& pProducto_Sustituto, NodoCiudad*& pNodo, bool& pHh);
void borrar_Ciudad_Vent(NodoCiudad*& pNodo, bool& pHh, int& pcodPais);
