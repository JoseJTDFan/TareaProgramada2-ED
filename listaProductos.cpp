//José Julián Brenes Garro y Gustavo Pacheco Morales
//c.2022272865
//Estructuras de Datos


#include "listaProductos.h"
using namespace std;

listaProductos::~listaProductos()
{
   pnodoProductos aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}

int listaProductos::largoLista(){
    int cont=0;

    pnodoProductos aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void listaProductos::InsertarInicio(int pais, int ciudad, int rest, int pmenu,int producto, string pnombre,int cantidad)
{
   if (ListaVacia())
   {
   
     primero = new nodoProductos(pais,ciudad, rest, pmenu, producto, pnombre, cantidad);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodoProductos (pais,ciudad, rest, pmenu, producto, pnombre, cantidad, primero);
     primero->siguiente->anterior=primero;
   }
}
//Otra forma ultimas dos lineas
// pnodoProductos nuevo=new nodoProductos(v);
//nuevo->siguiente=primero;
//primero->anterior=nuevo;
//primero=nuevo;
 
void listaProductos::InsertarFinal(int pais, int ciudad, int rest, int pmenu,int producto, string pnombre,int cantidad)
{
   if (ListaVacia())
   {
   
     primero = new nodoProductos(pais,ciudad, rest, pmenu, producto, pnombre, cantidad);
       
   }
   else
     { pnodoProductos aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodoProductos(pais,ciudad, rest, pmenu, producto, pnombre, cantidad);
        aux->siguiente->anterior=aux;       
      }    
}


void listaProductos::InsertarPos(int pais, int ciudad, int rest, int pmenu,int producto, string pnombre,int cantidad, int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodoProductos(pais,ciudad, rest, pmenu, producto, pnombre, cantidad);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(pais,ciudad, rest, pmenu, producto, pnombre, cantidad);    
        else
        {
             pnodoProductos aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoProductos nuevo= new nodoProductos(pais,ciudad, rest, pmenu, producto, pnombre, cantidad);
             nuevo->siguiente=aux->siguiente;
			 nuevo->anterior=aux;
			   nuevo->siguiente->anterior=nuevo;
			   aux->siguiente=nuevo;                      
        }
        }
}
      
void listaProductos::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)//solo un nodoProductos
		 {
        	pnodoProductos temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{

                pnodoProductos aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              pnodoProductos temp = aux->siguiente;
              aux->siguiente= NULL;
                      
                delete temp;
            }
        }
}

void listaProductos::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodoProductos temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{

                pnodoProductos aux = primero;
                primero=primero->siguiente;   
				primero->anterior=NULL;            
                delete aux;
            }
        }
}



void listaProductos:: BorrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Lista vacia" <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))//no validas
        {
        cout << "Error en posicion" << endl;
        }
        else
        {
        if(pos==1)
           BorrarInicio();
        else
        {
          if (pos == largoLista())   
             BorrarFinal();
          else
          {   
            int cont=2;
            pnodoProductos aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoProductos temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}

string listaProductos::getNombreProducto(int pos)
{
     if(ListaVacia()){
        cout << "Lista vacia" <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))//no validas
		{
    		cout << "Error en posicion" << endl;
        }
        else
        {
        if(pos==1){
           pnodoProductos temp=primero;
           return primero->nombre;
    	}
        else
          {   
            int cont=2;
            pnodoProductos aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoProductos temp=aux->siguiente;
            return aux->nombre;
          }//else
        }//else
	}
}


void listaProductos::Mostrar()
{
   pnodoProductos aux;
   cout<<endl<<"		* PAIS -> CIUDAD -> RESTAURANTE -> MENU -> PRODUCTO -> NOMBRE -> CALORIAS -> PRECIO"<<endl;
   aux = primero;
   while(aux) {
      cout <<"		* "<<aux->codPais << " -> "<<aux->codCiudad<<" -> "<<aux->codRest<<" -> "<<aux->codMenu<<" -> ";
      cout<<aux->codProducto<<" -> "<<aux->nombre<<endl;
      aux = aux->siguiente;
   }
   cout << endl;
}

void listaProductos::MostrarReportePrecio()
{
   pnodoProductos aux;
   cout<<endl<<"		* PAIS -> CIUDAD -> RESTAURANTE -> MENU -> PRODUCTO -> NOMBRE -> CALORIAS"<<endl;
   aux = primero;
   while(aux) {
      cout <<"		* "<<aux->codPais << " -> "<<aux->codCiudad<<" -> "<<aux->codRest<<" -> "<<aux->codMenu<<" -> ";
      cout<<aux->codProducto<<" -> "<<aux->nombre<<endl;
      aux = aux->siguiente;
   }
   cout << endl;
}

void listaProductos::MostrarCompra()
{
   pnodoProductos aux;
   cout<<endl<<"		* PAIS -> CIUDAD -> RESTAURANTE -> MENU -> PRODUCTO -> NOMBRE -> CANTIDAD"<<endl;
   aux = primero;
   while(aux) {
      cout <<"		* "<<aux->codPais << " -> "<<aux->codCiudad<<" -> "<<aux->codRest<<" -> "<<aux->codMenu<<" -> ";
      cout<<aux->codProducto<<" -> "<<aux->nombre<<" -> "<<aux->cantidad<<endl;
      aux = aux->siguiente;
   }
   cout << endl;
}

pnodoProductos listaProductos::buscarProducto(int prod){
	if (primero==NULL){
		return NULL;
	}
	pnodoProductos aux=primero;
	while(aux){
		if (aux->codProducto==prod){
			return aux;
		}
		aux = aux->siguiente;
	}
	return NULL;
}

int listaProductos::getPosicion(int codigo){
	if (primero==NULL){
		return 0;
	}
	pnodoProductos aux=primero;
	int cont=1;
	while(aux){
		if (aux->codProducto==codigo){
			return cont;
		}
		aux = aux->siguiente;
		cont++;
	}
	return 0;
}
