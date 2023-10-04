#pragma once
#include <iostream>
#include "listaProductos.h"

using namespace std;

class NodoFila { //AVL

	private:
		int cedula;
		string nombreCliente;
		int lugar;
		listaProductos productos;
		
	public:
		
		NodoFila () 
		{
			this->cedula = 0;
			this->nombreCliente = "";
			this->lugar=0;
		}
		NodoFila (int cedula, string nombreCliente, int lugar) 
		{
			this->cedula = cedula;
			this->nombreCliente = nombreCliente;
			this->lugar=lugar;
		}
		
	friend class cola;
	friend class Menu;
};

typedef NodoFila * pnodoFila;
