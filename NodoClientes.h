#pragma once
#include <iostream>

using namespace std;

class Pagina_Cliente {
	private:
		int cedula [5];
		std::string nombre [5];
		Pagina_Cliente* rama1; 
		Pagina_Cliente* rama2; 
		Pagina_Cliente* rama3; 
		Pagina_Cliente* rama4; 
		Pagina_Cliente* rama5;
		
	public:
		Pagina_Cliente ();
		Pagina_Cliente (int pCedula, string pNombre);
		
		int getCuentas ();
		int getCedula (int pIndice);
		string getNombre (int pCedula);
		Pagina_Cliente* getRama (int & pIndice);
		
		void setCedula (int pIndice, int pCedula);
		void setNombre (int pIndice, string pNombre);
		void setRama (int pIndice, Pagina_Cliente* pRama);
		
		Pagina_Cliente* buscar (int pCedula);
		int getIndice (int pCedula);
		
		void imprimir ();
		void imprimir_Pagina ();
};

typedef Pagina_Cliente* puntero_Cliente;
