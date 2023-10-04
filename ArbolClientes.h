#pragma once

#include <fstream>
#include <cstdlib>
#include <string>

#include "NodoClientes.h"

using namespace std;

class ArbolClientes {
	private:
		puntero_Cliente raiz;

	public:
		ArbolClientes ();
		bool arbol_Vacio ();
		puntero_Cliente getRaiz ();
		
		void buscar_Dato (int & pCedula, puntero_Cliente & pRaiz, bool & pEsta, int & pIndice_Rama);
		void inserta (int pCedula, string pNombre);
		void meter_Dato (int & pCedulaAux, string & pNombreAux, puntero_Cliente & pPaginaXr, puntero_Cliente & pRaiz, int & pIndice_Rama);
		void empujar_Arriba (int & pCedula, string & pNombre, puntero_Cliente & pRaiz, bool & pEmpujar_Arriba, int & pCedula_Aux, string & pNombre_Aux, puntero_Cliente & pPaginaXr);
		void dividir_Pagina (int & pCedula_Aux, string & pNombre_Aux, puntero_Cliente & pPaginaXr, puntero_Cliente & pRaiz, int & pIndice_Rama, int & pCedula_Aux2, string & pNombre_Aux2, puntero_Cliente & pPaginaXr2);
		void imprimir_Arbol ();
		
		void eliminar (int pCedula);
		void quitar (puntero_Cliente & pRaiz, int & pIndice_Rama);
		void sucesor (puntero_Cliente & pRaiz, int & pIndice_Rama);
		void eliminar_Registro (int & pCedula, puntero_Cliente & pRaiz, bool & pEncontrado);
		void mover_Derecha (puntero_Cliente & pRaiz, int & pIndice_Rama);
		void mover_Izquierda (puntero_Cliente & pRaiz, int & pIndice_Rama);
		void combinar (puntero_Cliente & pRaiz, int & pIndice_Rama);
		void restablecer (puntero_Cliente & pRaiz, int & pIndice_Rama);
		
		puntero_Cliente buscarCliente (int pCedula);
		bool esta_cliente (int pCedula);
		void agregar_Datos_lectura (string & pDatosLinea);
		void leerDocCliente();
};
