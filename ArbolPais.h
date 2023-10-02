

#pragma once
#include "NodoPais.h" 

#include <fstream>
#include <cstdlib>
#include <string>
 
class ArbolPais{
	
	private:
		pnodoPais raiz;
	public:
		ArbolPais () {raiz = NULL;}
		
		//----------------- Paiss ---------------------
		void insertPais (int codPais, string nombre);
		void borrar_Pais(int codPais);
		pnodoPais buscarPais (int & codPais);
		bool verificarPais (int codPais);
		string imprimir_Pais ();
		void agregar_Datos_Pais (string & pDatosLinea);
		void leeDocPais ();
		
//		--------------------- Ciudad ---------------------
		void insertCiudad (int codPais, int codCiudad, string nombre);
		void borrar_Ciudad(int pCodPais, int pCodCiudad);
		pnodoCiudad buscarCiudad (int & codPais, int & codCiudad);
		bool verificarCiudad (int codPais, int codCiudad);
		string imprimir_Ciudad (int codPais);
		void agregar_Datos_Ciudad (string & pDatosLinea);
		void leerDocCiudad ();

//		--------------------- Marcas---------------------
		void insertRest (int codPais, int codCiudad, int codRest, string nombre);
		void borrar_Rest(int codPais, int codCiudad, int codRest);
		pnodoRest buscarRest (int & codPais, int & codCiudad, int & codRest);
		bool verificarRest     (int codPais, int codCiudad, int codRest);
		string imprimir_Rest (int codPais, int codCiudad);
		void agregar_Datos_Rest (string & pDatosLinea);
		void leeDocRest ();
		
		string imprimir_Arbol_Ventas ();
	
	
};
