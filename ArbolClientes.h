#pragma once

#include <fstream>
#include <cstdlib>
#include <string>

#include "NodoClientes.h"

using namespace std;

class Adiministrador_ArbB {
	private:
		puntero_Administrador raiz;

	public:
		Adiministrador_ArbB ();
		bool arbol_Vacio ();
		puntero_Administrador getRaiz ();
		
		void buscar_Dato (int & pCedula, puntero_Administrador & pRaiz, bool & pEsta, int & pIndice_Rama);
		void inserta (int pCedula, string pNombre);
		void meter_Dato (int & pCedulaAux, string & pNombreAux, puntero_Administrador & pPaginaXr, puntero_Administrador & pRaiz, int & pIndice_Rama);
		void empujar_Arriba (int & pCedula, string & pNombre, puntero_Administrador & pRaiz, bool & pEmpujar_Arriba, int & pCedula_Aux, string & pNombre_Aux, puntero_Administrador & pPaginaXr);
		void dividir_Pagina (int & pCedula_Aux, string & pNombre_Aux, puntero_Administrador & pPaginaXr, puntero_Administrador & pRaiz, int & pIndice_Rama, int & pCedula_Aux2, string & pNombre_Aux2, puntero_Administrador & pPaginaXr2);
		void imprimir_Arbol ();
		
		void eliminar (int pCedula);
		void quitar (puntero_Administrador & pRaiz, int & pIndice_Rama);
		void sucesor (puntero_Administrador & pRaiz, int & pIndice_Rama);
		void eliminar_Registro (int & pCedula, puntero_Administrador & pRaiz, bool & pEncontrado);
		void mover_Derecha (puntero_Administrador & pRaiz, int & pIndice_Rama);
		void mover_Izquierda (puntero_Administrador & pRaiz, int & pIndice_Rama);
		void combinar (puntero_Administrador & pRaiz, int & pIndice_Rama);
		void restablecer (puntero_Administrador & pRaiz, int & pIndice_Rama);
		
		puntero_Administrador buscar (int pCedula);
		bool esta_Administrador (int pCedula);
		void agregar_Datos_lectura (string & pDatosLinea);
		void leer_Doc ();
};
