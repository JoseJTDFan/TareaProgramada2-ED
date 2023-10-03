
#pragma once
#include <iostream>
#include "NodoCiudad.h"

using namespace std;

class NodoPais { //ABB
	
	private:
		int codPais; 
		string nombre;
		NodoPais * hDer;
		NodoPais * hIzq;
		pnodoCiudad dirCiudad;
	public:
		NodoPais ();
		NodoPais (int &codPais, string &nombre);
		void insert (int &codPais, string &nombre);
		NodoPais * buscarPais (int &codPais);

		void borrar(int& pcodPais, NodoPais*& pPasillo, NodoPais*& pPasilloAux);
		
		void setnombre (string pnombre);
		void setHDer (NodoPais * hijoDer);
		void setHIzq (NodoPais * hijoIzq);
		void setDirCiudad (pnodoCiudad pdirCiudad);
		
		int getcodPais();
		string getnombre();
		NodoPais * getHDer ();
		NodoPais * getHIzq ();
		pnodoCiudad getCiudad ();
		
		string inOrden_Pais ();
		void imprimir_Arbol ();
		
		
	friend class Nodo_Producto;

};
typedef NodoPais * pnodoPais;
