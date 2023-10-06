#pragma once
#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string> 
#include <sstream>
#include "NodoMenu.h"

using namespace std;

class NodoRest { //ARN
	private:
		bool rojo;
		int codPais, codCiudad, codRest;
		string nombre;
		NodoRest* padre;
		NodoRest* hDer;
		NodoRest* hIzq;
		pnodoMenu dirMenu;
	public:
		NodoRest ();
		NodoRest (int codPais, int codCiudad, int codRest, string nombre);
		void insertRest (NodoRest* &nodo, bool  Hh, int codPais, int codCiudad, int codRest, string nombre);
		NodoRest * buscarRest (int codRest);
		void mostrarMarca();
		bool verificarMarca(bool i, int codPais);
		
		void setRojo (bool rojo);
		void setcodRest (int pcodRest);
		void setNombre (string pNombre);
		void setPadre (NodoRest * padre);
		void setHDer (NodoRest * hijoDer);
		void setHIzq (NodoRest * hijoIzq);
		//void setcodRest(int codRest);
		void setcodCiudad(int pcodCiudad);
		void setCodigo(int pCodigo);
		void setMenu (pnodoMenu pMenu);
		
		bool getRojo ();
		int getcodPais ();
		int getcodCiudad();
		int getcodRest();
		string getnombre();
		NodoRest * getPadre ();
		NodoRest * getHDer ();
		NodoRest * getHIzq ();
		pnodoMenu getMenu ();
		
		string inOrden_Rest ();
		string preOrden_Rest();
		void imprimir_Arbol ();
		
		
		
};

typedef NodoRest * pnodoRest;

void rotSimpleDer_Gr (pnodoRest & nodo, pnodoRest & n1);
void rotSimpleIzq_Gr (pnodoRest & nodo, pnodoRest & n1);
void rotDobleDer_Gr (pnodoRest & nodo, pnodoRest & n1);
void rotDobleIzq_Gr (pnodoRest & nodo, pnodoRest & n1);
string to_Stiringeo(int pNumero);


void equilibrar_Uno_RN(pnodoRest& pNodo, bool& pHh, int& pcodPais);
void equilibrar_Dos_RN(pnodoRest& pNodo, bool& pHh, int& pcodPais);
void borrar_RN(pnodoRest& pProducto_Sustituto, pnodoRest& pNodo, bool& pHh);
void borrar_Rest_RN(pnodoRest& pNodo, bool& pHh, int& pcodPais);
