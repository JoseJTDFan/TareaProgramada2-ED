#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string> 
#include <sstream>
#include "NodoProducto.h"
using namespace std;

class NodoMenu { //AA
	private:
		int codPais;
		int codCiudad;
		int codRest;
		int codMenu;
		string nombre;
		int nivel;	
		NodoMenu* hDer;
		NodoMenu* hIzq;
		pnodoProducto dirProducto;
		
	public:
		NodoMenu ();
		NodoMenu (int codPais, int codCiudad, int codRest, int codMenu, string nombre);
		void insertMenu (NodoMenu* &nodo, int codPais, int codCiudad, int codRest, int codMenu, string nombre);
		NodoMenu* buscarMenu (int codMenu);
		bool verificarMenu (bool i, int codMenu);
		
		string inOrden_Menu ();
		string preOrden_Menu();
		void imprimir_Arbol();
		
		//getters.
		int getcodMenu();
		string getNombre();
		int getcodPais();
		int getcodCiudad();
		int getcodRest();
		int	getNivel ();
		NodoMenu* getHDer ();
		NodoMenu* getHIzq ();
		pnodoProducto getdirProducto();
		
		//setters.
		void setNombre (string pNombre);
		void setcodPais (int pcodPais);
		void setHDer(NodoMenu* hijo);
		void setHIzq(NodoMenu* hijo);
		void setNivel(int nivel);
		void setdirProducto(pnodoProducto prod);
};

typedef NodoMenu* pnodoMenu;

void giro (pnodoMenu &nodo, pnodoMenu &n1);
void repartir (pnodoMenu &nodo, pnodoMenu &n1);

//void insertMenu(NodoMenu*& nodo, int& codMenu, int& cantStock, int& codCanasta, string& nombre);

void equilibrar_Uno_AA(NodoMenu*& pNodo, bool& pHh);
void equilibrar_Dos_AA(NodoMenu*& pNodo, bool& pHh);
void borrar_AA(NodoMenu*& pProducto_Sustituto, NodoMenu*& pNodo, bool& pHh);
void borrar_Menu_AA(NodoMenu*& pNodo, bool& pHh, int& pcodMenu);
