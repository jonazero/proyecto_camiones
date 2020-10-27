#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Usuarios.h"
#include <ctime>
using namespace std;
extern Usuario nuevo;
typedef Usuario *pUsuario;
pUsuario inicio, fin;
unsigned t0, t1;
class Lista{
public:
    int tam;

    void Inicializar();
    void Insertar();
    void Mostrar();
    void Buscar(string aux);
    void Modificar(string aux);
    void Eliminar(string aux);
    void BorrarInicio();
    void medio(int aux);
    void BorrarFinal();
    void Capturar20();
    void Quicky(pUsuario pLeft, pUsuario pRight);
    void bb();
    void firstUpper ( string& str ) {
    str[0] = ::toupper( str[0] );
    for ( string::iterator it = str.begin(); it != str.end(); it++ )
    if ( *it == ' ' )
    *( it+1 ) = ::toupper( *( it+1 ) );
    }


};

void Lista::Inicializar()
{
    tam=0;
    inicio=NULL;
    fin=NULL;
}

void Lista::Capturar20()
{
    for(int i=0; i<20; i++)
    {
    if(tam==0){
       pUsuario nuevo = new Usuario();
       nuevo->UsuarioArray(i);
       nuevo->siguiente=NULL;
      inicio=nuevo;
      fin = nuevo;
      tam++;
    }
    else{
       pUsuario nuevo = new Usuario();
       pUsuario actual = fin;
       actual->siguiente = nuevo;
       nuevo->UsuarioArray(i);
       nuevo->siguiente=NULL;
       nuevo->anterior=actual;
       fin = nuevo;
       tam++;
    }
    }


}
void Lista::Insertar()
{
  if(tam==0)
  {
      pUsuario nuevo = new Usuario();
      nuevo->Ingresar();
      nuevo->siguiente=NULL;
      inicio=nuevo;
      fin = nuevo;
      tam++;
  }
  else{
    pUsuario nuevo = new Usuario();
    pUsuario actual=fin;
    actual->siguiente=nuevo;
    nuevo->Ingresar();
    nuevo->siguiente=NULL;
    nuevo->anterior=actual;
    fin=nuevo;
    tam++;
  }
}
void Lista::Mostrar()
{

    if(tam==0)
    {
        cout<<"Error"<<endl;
    }
    else{
        pUsuario actual;
        actual = inicio;
        for(int i=1; i<=tam; i++)
        {
            actual->Mostrar();
            actual=actual->siguiente;
        }
    }
}
void Lista::Buscar(string aux)
{
    if(tam<0)
    {
        cout<<"Error"<<endl;
    }
    else{
        pUsuario actual = inicio;
        for(int i=0; i<tam; i++)
        {
            if(actual->id == aux)
            {
                actual->Mostrar();
            }
            actual=actual->siguiente;
        }
    }
}
void Lista::Modificar(string aux)
{
 if(tam==0)
 {
     cout<<"Error"<<endl;
 }
 else{
    pUsuario actual = inicio;
    for(int i=0; i<tam; i++)
    {
        if(actual->id == aux)
        {
         int c;
         cout<<"Elige una opcion para modificar de "<<aux<<endl;
         cout<<"1.- Ingrese el nuevo id"<<endl;
         cout<<"2.- Ingrese el nuevo nombre"<<endl;
         cout<<"3.- Ingrese el nuevo apellido"<<endl;
         cout<<"4.- Ingrese la nueva ruta"<<endl;
         cin>>c;
         switch(c)
         {
          case 1: cout<<"Ingrese el nuevo id"<<endl;
          fflush(stdin);
          getline(cin,actual->id);
          break;
          case 2: cout<<"Ingrese el nuevo nombre"<<endl;
          fflush(stdin);
          getline(cin,actual->nombre);
           firstUpper(actual->nombre);
          break;
          case 3: cout<<"Ingrese el nuevo apellido"<<endl;
          fflush(stdin);
          getline(cin,actual->apellido);
          firstUpper(actual->apellido);
          break;
          case 4: cout<<"Ingrese la nueva ruta"<<endl;
          fflush(stdin);
          getline(cin, actual->ruta);
          break;
         }
        }
        actual = actual->siguiente;
    }
 }
}
void Lista::Eliminar(string aux)
{
    int pos;
    if(tam ==0)
    {
        cout<<"Error"<<endl;
        inicio=NULL;
        fin=NULL;
        tam =0;
    }
    else{
        pUsuario actual = inicio;
        for(int i =1; i<=tam; i++)
        {
            if(actual->id==aux)
            {
                pos=i;
                //actual->Mostrar();
            }
            actual=actual->siguiente;
        }
        int ban =0;
        if(pos==1){
            BorrarInicio();
            ban=1;
        }
        if(pos>1&&pos<tam&&ban==0){
            medio(pos);
            ban=1;
        }
        if(pos>1 && pos<tam && ban==0){
            medio(pos);
            ban=1;
        }
        if(pos==tam && ban==0){
            BorrarFinal();
            ban=1;
        }

    }
}

void Lista::BorrarInicio()
{
    pUsuario sup, actual;
    actual = inicio;
    sup=actual;
    inicio=actual->siguiente;
    tam--;
    delete(sup);
}

void Lista::medio(int aux)
{
    cout <<"Borra en medio"<<endl;
    //system("PAUSE");
    pUsuario sup, actual;
    actual=inicio;
    for(int j=1; j<aux; j++)
    {
        actual=actual->siguiente;
    }
    //actual->Mostrar();
    //system("PAUSE");
    sup=actual;
    actual=sup->anterior;
    //actual->Mostrar();
    //system("PAUSE");
    actual->siguiente=sup->siguiente;
    //actual->siguiente->Mostrar();
    actual->siguiente->anterior=actual;
    //system("PAUSE");
    delete(sup);
    tam--;
}

void Lista::BorrarFinal()
{
    cout<<"Borra al final"<<endl;
    pUsuario sup, actual;
    sup=fin;
    actual=sup->anterior;
    actual->siguiente=NULL;
    fin=actual;
    tam--;
    delete(sup);
    if(tam==0)
    {
        tam=0;
        inicio=NULL;
        fin=NULL;
    }
}
void Lista::Quicky(pUsuario pLeft, pUsuario pRight)
{
    t0=clock();
    pUsuario pinicio;
	pUsuario pactual;
	string copyapellido, copyid, copynombre, copyruta;

	// Si el puntero izquiero y el derecho son iguales entonces
	if (pLeft == pRight) return;

	pinicio = pLeft;
	pactual = pinicio->siguiente;

	// Cliclo para recorrer la lista
	while (1)
	{
		// Comparar alfabeticamente los strings
		if (pinicio->apellido < pactual->apellido)
		{
			//Se cambia la informacion de nodo, para ello utilizamos un auxiliar
			copyapellido = pactual->apellido;
			copynombre = pactual->nombre;
			copyid = pactual->id;
			copyruta=pactual->ruta;

			pactual->apellido = pinicio->apellido;
			pactual->id=pinicio->id;
			pactual->nombre=pinicio->nombre;
			pactual->ruta=pinicio->ruta;

			pinicio->apellido = copyapellido;
			pinicio->nombre = copynombre;
			pinicio->id=copyid;
			pinicio->ruta = copyruta;
		}

		// Si ya se llego al puntero Izquierdo osea el final entonces rompe el ciclo
		if (pactual == pRight) break;

		//Apuntamos al siguiente nodo de la lista
		pactual = pactual->siguiente;
	}

	// Intercambiaomos los nodos primero y el actual
	copyapellido = pLeft->apellido;
	copyid = pLeft->id;
	copynombre=pLeft->nombre;
	copyruta=pLeft->ruta;

	pLeft->apellido = pactual->apellido;
	pLeft->nombre=pactual->nombre;
	pLeft->id=pactual->id;
	pLeft->ruta=pactual->ruta;

	pactual->apellido = copyapellido;
	pactual->nombre = copynombre;
	pactual->id= copyid;
	pactual->ruta = copyruta;

	// Guardamos lo que tenga actual y lo pasamos al puntero auxiliar
	pUsuario paux = pactual;

	// Revisa si necesita ordenar la parte izquierda
	pactual = pactual->anterior;
	if (pactual != NULL)
	{
		if ((pLeft->anterior != pactual) && (pactual->siguiente != pLeft))
			Quicky(pLeft, pactual);
	}

	// Revisa si necesita ordenar la parte derecha
	pactual = paux;
	pactual = pactual->siguiente;
	if (pactual != NULL)
	{
		if ((pactual->anterior != pRight) && (pRight->siguiente != pactual))
			Quicky(pactual, pRight);
	}
t1=clock();

double time = (double(t1-t0)/CLOCKS_PER_SEC);
//cout<<"Tiempo de ejecucion: "<<time<<endl;
}

void Lista::bb()
{

    bool pal = false;
    string palabra;
    cout<<"Ingrese el apellido a buscar"<<endl;
    fflush(stdin);
    getline(cin,palabra);
    firstUpper(palabra);
    int auxiliar=0;
    pUsuario aux1 = inicio;
    while(aux1!=fin)
    {

    auxiliar++;
    aux1=aux1->siguiente;
    }
    aux1=inicio;
    Usuario datos[auxiliar+1];
    for(int i=0; i<auxiliar+1; i++)
    {
        datos[i].id=aux1->id;
        datos[i].nombre=aux1->nombre;
        datos[i].apellido=aux1->apellido;
        datos[i].ruta=aux1->ruta;
        aux1=aux1->siguiente;
    }
   t0 = clock();
    int ult,i,j,medio;
    ult=auxiliar;
    i=0;
    j=ult;
    while(i<=j){
        medio=(j+i)/2;
        if(datos[medio].apellido==palabra){
            pal = true;
            cout<<"°Usuario encontrado°"<<endl;
            cout<<"Nombre: "<<datos[medio].nombre<<endl;
            cout<<"Apellido: "<<datos[medio].apellido<<endl;
            cout<<"Id: "<<datos[medio].id<<endl;
            cout<<"Ruta: "<<datos[medio].ruta<<endl;
        }
        if(palabra<datos[medio].apellido){
            j=medio-1;
        }
        else{
          i=medio+1;
        }
    }
    if(pal == false){
        cout<<"Error usuario no encontrado"<<endl;
    }
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
cout<<"Tiempo de ejecucion: "<<time<<endl;
}
#endif // LISTA_H_INCLUDED
