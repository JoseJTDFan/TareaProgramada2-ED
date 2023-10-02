#pragma once
#include <iostream>

using namespace std;

class Pagina_Administrador {
	private:
		int cedula [5];
		std::string nombre [5];
		Pagina_Administrador* rama1; 
		Pagina_Administrador* rama2; 
		Pagina_Administrador* rama3; 
		Pagina_Administrador* rama4; 
		Pagina_Administrador* rama5;
		
	public:
		Pagina_Administrador ();
		Pagina_Administrador (int pCedula, string pNombre);
		
		int getCuentas ();
		int getCedula (int pIndice);
		string getNombre (int pCedula);
		Pagina_Administrador* getRama (int & pIndice);
		
		void setCedula (int pIndice, int pCedula);
		void setNombre (int pIndice, string pNombre);
		void setRama (int pIndice, Pagina_Administrador* pRama);
		
		Pagina_Administrador* buscar (int pCedula);
		int getIndice (int pCedula);
		
		void imprimir ();
		void imprimir_Pagina ();
};

typedef Pagina_Administrador* puntero_Administrador;
