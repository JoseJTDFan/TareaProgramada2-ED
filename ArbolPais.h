

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
		
		//----------------- Pais ---------------------
		void insertPais (int codPais, string nombre);
		void borrar_Pais(int codPais);
		pnodoPais buscarPais (int & codPais);
		bool verificarPais (int codPais);
		string imprimir_Pais ();
		void agregar_Datos_Pais (string & pDatosLinea);
		void leeDocPais ();
		string reportePais();
		
//		--------------------- Ciudad ---------------------
		void insertCiudad (int codPais, int codCiudad, string nombre);
		void borrar_Ciudad(int pCodPais, int pCodCiudad);
		pnodoCiudad buscarCiudad (int & codPais, int & codCiudad);
		bool verificarCiudad (int codPais, int codCiudad);
		string imprimir_Ciudad (int codPais);
		void agregar_Datos_Ciudad (string & pDatosLinea);
		void leerDocCiudad ();
		string reporteCiudad(pnodoPais pais);
	
//		--------------------- Restaurante---------------------
		void insertRest (int codPais, int codCiudad, int codRest, string nombre);
		void borrar_Rest (int codPais, int codCiudad, int codRest);
		pnodoRest buscarRest (int & codPais, int & codCiudad, int & codRest);
		bool verificarRest     (int codPais, int codCiudad, int codRest);
		string imprimir_Rest (int codPais, int codCiudad);
		void agregar_Datos_Rest (string & pDatosLinea);
		void leeDocRest ();
		string reporteRest(pnodoCiudad ciudad);
		
	//		--------------------- Menu---------------------
		void insertMenu (int codPais, int codCiudad, int codRest, int codMenu, string nombre);
		void borrar_Menu(int codPais, int codCiudad, int codRest, int codMenu);
		pnodoMenu buscarMenu (int & codPais, int & codCiudad, int & codRest, int & codMenu);
		bool verificarMenu     (int codPais, int codCiudad, int codRest, int codMenu);
		string imprimir_Menu (int codPais, int codCiudad, int codRest);
		void agregar_Datos_Menu (string & pDatosLinea);
		void leeDocMenu ();
		string reporteMenu(pnodoRest restaurante);
		
	//		--------------------- Producto ---------------------
		void insertProducto (int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, int cantidad);
		void borrar_Producto(int codPais, int codCiudad, int codRest, int codMenu, int codProducto);
		pnodoProducto buscarProducto (int & codPais, int & codCiudad, int & codRest, int & codMenu , int &codProducto);
		bool verificarProducto     (int codPais, int codCiudad, int codRest, int codMenu, int codProducto);
		void imprimir_Producto (int codPais, int codCiudad, int codRest, int codMenu);
		void agregar_Datos_Producto (string & pDatosLinea);
		void leeDocProducto ();
		string reporteProducto(pnodoMenu menu);
		string reportePrecio(pnodoProducto producto);
		
		void imprimir_Arbol_Ventas ();
	
	
};
