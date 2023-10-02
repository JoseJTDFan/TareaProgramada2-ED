#include "ArbolClientes.h"

Adiministrador_ArbB::Adiministrador_ArbB() {
	this->raiz = NULL;
}

bool Adiministrador_ArbB::arbol_Vacio() {
	return this->raiz == NULL;
}

puntero_Administrador Adiministrador_ArbB::getRaiz() {
	return this->raiz;
}

void Adiministrador_ArbB::buscar_Dato(int& pCedula, puntero_Administrador& pRaiz, bool& pEsta, int& pIndice_Rama)
{
	if (pCedula < pRaiz->getCedula(0)) {
		pEsta = false;
		pIndice_Rama = 0;
	}
	else {
		pIndice_Rama = pRaiz->getCuentas();
		while (pIndice_Rama > 0 && pCedula < pRaiz->getCedula(pIndice_Rama - 1))
			pIndice_Rama = pIndice_Rama - 1;
		pEsta = pCedula == pRaiz->getCedula(pIndice_Rama - 1);
	}
}

void Adiministrador_ArbB::meter_Dato(int& pCedulaAux, string& pNombreAux, puntero_Administrador& pPaginaXr, puntero_Administrador& pRaiz, int& pIndice_Rama)
{
	for (int i = pRaiz->getCuentas(); i >= pIndice_Rama + 1; i--)
	{
		pRaiz->setCedula(i, pRaiz->getCedula(i - 1));
		pRaiz->setNombre(i, pRaiz->getNombre(i - 1));
		pRaiz->setRama(i + 1, pRaiz->getRama(i));
	}
	pRaiz->setCedula(pIndice_Rama, pCedulaAux);
	pRaiz->setNombre(pIndice_Rama, pNombreAux);
	pRaiz->setRama(pIndice_Rama + 1, pPaginaXr);
}

void Adiministrador_ArbB::empujar_Arriba(int& pCedula, string& pNombre, puntero_Administrador& pRaiz, bool& pEmpujar_Arriba, int& pCedula_Aux, string& pNombre_Aux, puntero_Administrador& pPaginaXr)
{
	int indice_Rama = 0;
	bool esta = false;
	if (pRaiz == NULL) {
		pEmpujar_Arriba = true;
		pCedula_Aux = pCedula;
		pNombre_Aux = pNombre;
		pPaginaXr = NULL;

	}
	else {
		this->buscar_Dato(pCedula, pRaiz, esta, indice_Rama);
		if (esta)
			return;
		puntero_Administrador rama = pRaiz->getRama(indice_Rama);
		this->empujar_Arriba(pCedula, pNombre, rama, pEmpujar_Arriba, pCedula_Aux, pNombre_Aux, pPaginaXr);
		pRaiz->setRama(indice_Rama, rama);

		if (pEmpujar_Arriba) {
			if (pRaiz->getCuentas() < 4) {
				pEmpujar_Arriba = false;
				puntero_Administrador paginaAux = pPaginaXr;
				this->meter_Dato(pCedula_Aux, pNombre_Aux, paginaAux, pRaiz, indice_Rama);
				pPaginaXr = paginaAux;
			}
			else {
				pEmpujar_Arriba = true;
				int cedulaAuxD = 0;
				string nombreAuxD = "";
				puntero_Administrador paginaAux = NULL;

				this->dividir_Pagina(pCedula_Aux, pNombre_Aux, pPaginaXr, pRaiz, indice_Rama, cedulaAuxD, nombreAuxD, paginaAux);

				pCedula_Aux = cedulaAuxD;
				pNombre_Aux = nombreAuxD;
				pPaginaXr = paginaAux;
			}
		}
	}
}

void Adiministrador_ArbB::inserta(int pCedula, string pNombre)
{
	bool empujar_Arriba = false;
	int cedula_Aux = 0;
	string nombre_Aux = "";
	puntero_Administrador paginaXr = NULL;
	puntero_Administrador paginaAux = NULL;

	this->empujar_Arriba(pCedula, pNombre, this->raiz, empujar_Arriba, cedula_Aux, nombre_Aux, paginaXr);

	if (empujar_Arriba) {
		paginaAux = new Pagina_Administrador(cedula_Aux, nombre_Aux);
		paginaAux->setRama(0, this->raiz);
		paginaAux->setRama(1, paginaXr);
		this->raiz = paginaAux;
	}
}

void Adiministrador_ArbB::dividir_Pagina(int& pCedula_Aux, string& pNombre_Aux, puntero_Administrador& pPaginaXr, puntero_Administrador& pRaiz, int& pIndice_Rama, int& pCedula_Aux2, string& pNombre_Aux2, puntero_Administrador& pPaginaXr2)
{
	int posMda = 0;
	if (pIndice_Rama <= 2)
		posMda = 2;
	else
		posMda = 3;
	pPaginaXr2 = new Pagina_Administrador();
	puntero_Administrador rama = NULL;

	for (int i = 0; i < 5; i++) {
		pPaginaXr2->setRama(i, rama);
	}
	for (int i = posMda + 1; i <= 4; i++) {
		pPaginaXr2->setCedula(i - posMda - 1, pRaiz->getCedula(i - 1));
		pPaginaXr2->setNombre(i - posMda - 1, pRaiz->getNombre(i - 1));
		pRaiz->setCedula(i - 1, -1);
		pRaiz->setNombre(i - 1, "");

		rama = pRaiz->getRama(i);
		pPaginaXr2->setRama(i - posMda, rama);
	}
	if (pIndice_Rama <= 2)
		this->meter_Dato(pCedula_Aux, pNombre_Aux, pPaginaXr, pRaiz, pIndice_Rama);
	else
	{
		pIndice_Rama = pIndice_Rama - posMda;
		this->meter_Dato(pCedula_Aux, pNombre_Aux, pPaginaXr, pPaginaXr2, pIndice_Rama);
		pIndice_Rama = pIndice_Rama + posMda;
	}
	pCedula_Aux2 = pRaiz->getCedula(pRaiz->getCuentas() - 1);
	pNombre_Aux2 = pRaiz->getNombre(pRaiz->getCuentas() - 1);

	int cuentas_Temporal = pRaiz->getCuentas();
	rama = pRaiz->getRama(cuentas_Temporal);
	pPaginaXr2->setRama(0, rama);

	int i = cuentas_Temporal - 1;
	pRaiz->setCedula(i, -1);
	pRaiz->setNombre(i, "");
}

void Adiministrador_ArbB::imprimir_Arbol()
{
	if (this->arbol_Vacio()) {
		cout << "\n\tArbol vacio.\n";
		return;
	}
	this->raiz->imprimir();
}


void Adiministrador_ArbB::quitar(puntero_Administrador& pRaiz, int& pIndice_Rama)
{
	int cuentas = pRaiz->getCuentas();
	for (int j = pIndice_Rama; j <= cuentas; j++)
	{
		pRaiz->setCedula(j - 1, pRaiz->getCedula(j));
		pRaiz->setNombre(j - 1, pRaiz->getNombre(j));
		pRaiz->setRama(j - 1, pRaiz->getRama(j));
	}
	pRaiz->setCedula(cuentas - 1, -1);
	pRaiz->setNombre(cuentas - 1, "");
}

void Adiministrador_ArbB::sucesor(puntero_Administrador& pRaiz, int& pIndice_Rama)
{
	puntero_Administrador pagina_Q = pRaiz->getRama(pIndice_Rama);
	int indice_Cero = 0;
	while (pagina_Q->getRama(indice_Cero) != NULL)
		pagina_Q = pagina_Q->getRama(indice_Cero);

	pRaiz->setCedula(pIndice_Rama - 1, pagina_Q->getCedula(0));
	pRaiz->setNombre(pIndice_Rama - 1, pagina_Q->getNombre(0));
}

void Adiministrador_ArbB::eliminar_Registro(int& pCedula, puntero_Administrador& pRaiz, bool& pEncontrado)
{
	int indice_Rama = 0;
	if (pRaiz == NULL)
		pEncontrado = false;
	else
	{
		this->buscar_Dato(pCedula, pRaiz, pEncontrado, indice_Rama);
		if (pEncontrado) {

			int indice = indice_Rama - 1;
			if (pRaiz->getRama(indice) == NULL) {
				this->quitar(pRaiz, indice_Rama);

			}
			else {
				this->sucesor(pRaiz, indice_Rama);
				puntero_Administrador rama = pRaiz->getRama(indice_Rama);
				int cedula = pRaiz->getCedula(indice);

				this->eliminar_Registro(cedula, rama, pEncontrado);
				pRaiz->setRama(indice_Rama, rama);

				if (pEncontrado == false)
					cout << "Error: Inconsistencia en el proceso.";
			}
		}
		else {
			puntero_Administrador rama = pRaiz->getRama(indice_Rama);
			this->eliminar_Registro(pCedula, rama, pEncontrado);
			pRaiz->setRama(indice_Rama, rama);

			if (pRaiz->getRama(indice_Rama) != NULL)
				if (pRaiz->getRama(indice_Rama)->getCuentas() < 2)
					this->restablecer(pRaiz, indice_Rama); //cout<<"\tTenemos que restablecer. BT";
		}
	}
}

void Adiministrador_ArbB::eliminar(int pCedula)
{
	bool encontrado = false;
	puntero_Administrador pagina_P = NULL;

	this->eliminar_Registro(pCedula, this->raiz, encontrado); //EliminarRegistro (C1:valor a borrar,Raiz,Encontrado);
	if (encontrado == false)
		cout << "\tError: El elemento no a sido encontrado.";
	else
	{
		if (this->raiz->getCuentas() == 0) { 	 // la raíz ha quedado vacia
			pagina_P = this->raiz; 				 //P= Raiz
			int indice = 0;
			this->raiz = this->raiz->getRama(indice); //Raiz= Raiz.Rama[0]
			delete pagina_P; 					 //Delete(P)
		}
	}
}


void Adiministrador_ArbB::mover_Derecha(puntero_Administrador& pRaiz, int& pIndice_Rama)
{
	puntero_Administrador rama_Trabajo = pRaiz->getRama(pIndice_Rama);
	int cuentas = rama_Trabajo->getCuentas();
	int indice = 0;

	for (int j = cuentas; j >= 1; j--)
	{
		rama_Trabajo->setCedula(j, rama_Trabajo->getCedula(j - 1));
		rama_Trabajo->setNombre(j, rama_Trabajo->getNombre(j - 1));
		indice = j - 1;
		rama_Trabajo->setRama(j + 1, rama_Trabajo->getRama(indice));
	}
	indice = 0;
	rama_Trabajo->setRama(1, rama_Trabajo->getRama(indice));

	indice = pIndice_Rama - 1;
	rama_Trabajo->setCedula(0, pRaiz->getCedula(indice));
	rama_Trabajo->setNombre(0, pRaiz->getNombre(indice));

	rama_Trabajo = pRaiz->getRama(indice);
	indice = rama_Trabajo->getCuentas() - 1;
	pRaiz->setCedula(pIndice_Rama - 1, rama_Trabajo->getCedula(indice));
	pRaiz->setNombre(pIndice_Rama - 1, rama_Trabajo->getNombre(indice));

	pRaiz->getRama(pIndice_Rama)->setRama(0, rama_Trabajo->getRama(indice));

	rama_Trabajo->setCedula(indice, -1);
	rama_Trabajo->setNombre(indice, "");
}

void Adiministrador_ArbB::mover_Izquierda(puntero_Administrador& pRaiz, int& pIndice_Rama)
{
	int indice = pIndice_Rama - 1;
	puntero_Administrador rama_Trabajo = pRaiz->getRama(indice);

	int cuentas = rama_Trabajo->getCuentas() + 1;

	rama_Trabajo->setCedula(cuentas - 1, pRaiz->getCedula(pIndice_Rama - 1));
	rama_Trabajo->setNombre(cuentas - 1, pRaiz->getNombre(pIndice_Rama - 1));
	indice = 0;

	rama_Trabajo->setRama(cuentas, pRaiz->getRama(pIndice_Rama)->getRama(indice));

	rama_Trabajo = pRaiz->getRama(pIndice_Rama);

	pRaiz->setCedula(pIndice_Rama - 1, rama_Trabajo->getCedula(1 - 1));
	pRaiz->setNombre(pIndice_Rama - 1, rama_Trabajo->getNombre(1 - 1));

	indice = 0;
	rama_Trabajo->setRama(indice, rama_Trabajo->getRama(pIndice_Rama));

	cuentas = rama_Trabajo->getCuentas();
	for (int j = 1; j <= cuentas; j++)
	{
		rama_Trabajo->setCedula(j - 1, rama_Trabajo->getCedula(j));
		rama_Trabajo->setNombre(j - 1, rama_Trabajo->getNombre(j));
		indice = j + 1;
		rama_Trabajo->setRama(j, rama_Trabajo->getRama(indice));
	}
}

void Adiministrador_ArbB::combinar(puntero_Administrador& pRaiz, int& pIndice_Rama)
{
	int indice = pIndice_Rama - 1;
	puntero_Administrador pagina_Q = pRaiz->getRama(pIndice_Rama);
	puntero_Administrador rama_Trabajo = pRaiz->getRama(indice);

	int cuentas = rama_Trabajo->getCuentas();
	rama_Trabajo->setCedula(cuentas, pRaiz->getCedula(pIndice_Rama - 1));
	rama_Trabajo->setNombre(cuentas, pRaiz->getNombre(pIndice_Rama - 1));
	indice = 0;
	cuentas = rama_Trabajo->getCuentas();
	rama_Trabajo->setRama(cuentas, pagina_Q->getRama(indice));

	cuentas = pagina_Q->getCuentas();
	for (int j = 1; j <= cuentas; j++)
	{
		indice = rama_Trabajo->getCuentas();
		rama_Trabajo->setCedula(indice, pagina_Q->getCedula(j - 1));
		rama_Trabajo->setNombre(indice, pagina_Q->getNombre(j - 1));
		indice += 1;
		rama_Trabajo->setRama(indice, pagina_Q->getRama(j));
	}

	cuentas = pRaiz->getCuentas();
	for (int i = pIndice_Rama; i <= cuentas; i++)
	{
		pRaiz->setCedula(i - 1, pRaiz->getCedula(i));
		pRaiz->setNombre(i - 1, pRaiz->getNombre(i));
		indice = i + 1;
		pRaiz->setRama(i, pRaiz->getRama(indice));
	}
	pRaiz->setCedula(cuentas - 1, -1);
	pRaiz->setNombre(cuentas - 1, "");

	delete pagina_Q;
}

void  Adiministrador_ArbB::restablecer(puntero_Administrador& pRaiz, int& pIndice_Rama)
{
	//cout<<"\t-------\n\tIndc: "<<pIndice_Rama<<"\n\t-------";
	if (pIndice_Rama > 0) {
		int indice = pIndice_Rama - 1;
		if (pRaiz->getRama(indice)->getCuentas() > 2) {
			this->mover_Derecha(pRaiz, pIndice_Rama);
		}
		else {
			this->combinar(pRaiz, pIndice_Rama);
		}
	}
	else {
		int indice = 1;
		if (pRaiz->getRama(indice)->getCuentas() > 2) {
			this->mover_Izquierda(pRaiz, indice);
		}
		else {
			this->combinar(pRaiz, indice);
		}
	}
}

puntero_Administrador Adiministrador_ArbB::buscar(int pCedula)
{
	if (this->raiz == NULL)
		return NULL;
	return this->raiz->buscar(pCedula);
}

bool Adiministrador_ArbB::esta_Administrador(int pCedula)
{
	if (this->raiz == NULL)
		return false;
	return this->raiz->buscar(pCedula) != NULL;
}

void Adiministrador_ArbB::agregar_Datos_lectura(string& pDatosLinea)
{
	std::string datos[2] = { "", "" };
	int indiceDatos = 0;
	for (int indice = 0; indice < pDatosLinea.size(); indice++) {
		if (pDatosLinea[indice] != ';')
			datos[indiceDatos] = datos[indiceDatos] + pDatosLinea[indice];
		else
			indiceDatos++;
	}
	if (!this->esta_Administrador(stoi(datos[0].c_str())))
		this->inserta(stoi(datos[0].c_str()), datos[1]);
}

void Adiministrador_ArbB::leer_Doc()
{
	string nombreArchivo = "Administradores.txt";
	ifstream file(nombreArchivo.c_str());
	string linea;

	while (!file.eof())
	{
		linea = "";
		getline(file, linea);
		this->agregar_Datos_lectura(linea);
	}
	file.close();
}

