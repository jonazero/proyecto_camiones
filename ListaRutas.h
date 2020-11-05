#ifndef LISTARUTAS_H_INCLUDED
#define LISTARUTAS_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int tam;
extern Ruta nueva;
typedef Ruta *pRutas;
pRutas inicior,
pRutas finr;

class ListaRuta{
    public:
        void Inicializar();
        void Insertar();
        void Mostrar();
        void Buscar(string aux);
        void Modificar(string aux);
        void Eliminar(string aux);
        void BorrarInicio();
        void medio(int aux);
        void BorrarFinal();
        void Capturar20rutas();
        void rutasquick(pRutas pLeft,
			pRutas pRight);
        void bRutas();
        void firstUpper ( string& str ) {
        str[0] = ::toupper( str[0] );
        for ( string::iterator it = str.begin(); it != str.end(); it++ )
	{
            if ( *it == ' ' )
	    {
                *( it+1 ) = ::toupper( *( it+1 ) );
	    }
	}
        int posicion =0;
};

void ListaRuta::Inicializar()
{
    tam=0;
    inicio=NULL;
    fin=NULL;
}

void ListaRuta::Capturar20rutas()
{
    for(int i=0; i<20; i++)
    {
        if(tam==0)
	{
            pRutas nuevo = new Ruta();
            nuevo->rutaArray(i);
            nuevo->siguiente=NULL;
            inicior=nuevo;
            finr = nuevo;
            tam++;
	}
        else
	{
            pRutas nuevo = new Ruta();
            pRutas actual = finr;
            actual->siguiente = nuevo;
            nuevo->rutaArray(i);
            nuevo->siguiente=NULL;
            nuevo->anterior=actual;
            finr = nuevo;
            tam++;
	}
    }
}

void ListaRuta::Insertar()
{
    if(tam==0)
    {
        pRutas nuevo = new Ruta();
        nuevo->Ingresar();
        nuevo->siguiente=NULL;
        inicior=nuevo;
        finr = nuevo;
        tam++;
    }
    else
    {
        pRutas nuevo = new Ruta();
        pRutas actual=finr;
        actual->siguiente=nuevo;
        nuevo->Ingresar();
        nuevo->siguiente=NULL;
        nuevo->anterior=actual;
        finr=nuevo;
        tam++;
    }
}
	
void ListaRuta::Mostrar()
{
    if(tam==0)
    {
        cout<<"Error"<<endl;
    }
    else
    {
        pRutas actual;
        actual = inicior;
        for(int i=1; i<=tam;i++)
	{
            actual->Mostrar();
            actual=actual->siguiente;
        }
    }
}
	
void ListaRuta::Buscar(string aux)
{
    if(tam<0)
    {
        cout<<"Error"<<endl;
    }
    else
    {
        pRutas actual = inicior;
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
void ListaRuta::Modificar(string aux)
{
    if(tam==0)
    {
        cout<<"Error"<<endl;
    }
    else
    {
        pRutas actual = inicior;
        for(int i=0; i<tam; i++)
        {
            if(actual->id == aux)
            {
                int c;
                cout<<"Elige una opcion para modificar de "<<aux<<endl;
                cout<<"1.- Ingrese el nuevo id"<<endl;
                cout<<"2.- Ingrese la nueva ruta"<<endl;
                cout<<"3.- Ingrese el nuevo origen"<<endl;
                cout<<"4.- Ingrese el nuevo destino"<<endl;
                cin>>c;
                switch(c)
                {
                    case 1: 
		        cout<<"Ingrese el nuevo id"<<endl;
                        fflush(stdin);
                        getline(cin,actual->id);
                        break;
                    case 2:
			cout<<"Ingrese la nueva ruta"<<endl;
                        cin>>actual->ruta;
                        break;
                    case 3: 
			cout<<"Ingrese el nuevo origen"<<endl;
                        fflush(stdin);
                        getline(cin,actual->origen);
                        firstUpper(actual->origen);
                        break;
                    case 4:
			cout<<"Ingrese en nuevo destino"<<endl;
                        fflush(stdin);
                        getline(cin,actual->destino);
                        firstUpper(actual->destino);
                        break;
		    default:
			break;
		}
	    }
            actual = actual->siguiente;
	}
    }
}
	
void ListaRuta::Eliminar(string aux)
{
    int pos;
    if(tam ==0)
    {
        cout<<"Error"<<endl;
        inicior=NULL;
        finr=NULL;
        tam =0;
    }
    else{
        pRutas actual = inicior;
        for(int i =1; i<=tam; i++)
        {
            if(actual->id==aux)
            {
                pos=i;
            }
            actual=actual->siguiente;
        }
        int ban =0;
        if(pos==1)
	{
            BorrarInicio();
            ban=1;
        }
        if(pos>1&&pos<tam&&ban==0)
	{
            medio(pos);
            ban=1;
        }
        if(pos>1 && pos<tam && ban==0)
	{
            medio(pos);
            ban=1;
        }
        if(pos==tam && ban==0)
	{
            BorrarFinal();
            ban=1;
        }

    }
}

void ListaRuta::BorrarInicio()
{
    pRutas sup, actual;
    actual = inicior;
    sup=actual;
    inicior=actual->siguiente;
    tam--;
    delete(sup);
}

void ListaRuta::medio(int aux)
{
    pRutas sup;
    pRutas actual;
    actual=inicior;
    for(int j=1; j<aux; j++)
    {
        actual=actual->siguiente;
    }
    sup=actual;
    actual=sup->anterior;
    actual->siguiente=sup->siguiente;
    actual->siguiente->anterior=actual;
    delete(sup);
    tam--;
}

void ListaRuta::BorrarFinal()
{
    pRutas sup;
    pRutas actual;
    sup=finr;
    actual=sup->anterior;
    actual->siguiente=NULL;
    finr=actual;
    tam--;
    delete(sup);
    if(tam==0)
    {
        tam=0;
        inicior=NULL;
        finr=NULL;
    }
}
void ListaRuta::rutasquick(pRutas pLeft, 
			   pRutas pRight)
{
    pRutas pStart;
    pRutas pCurrent;
    string copyid;
    string copyorigen;
    string copydestino;
    int copyruta;

    // If the left and right pointers are the same, then return
    if (pLeft == pRight)
    {
	return;
    }

    // Set the Start and the Current item pointers
    pStart = pLeft;
    pCurrent = pStart->siguiente;

    // Loop forever (well until we get to the right)
    while (1)
    {
	// If the start item is less then the right
	if (pStart->ruta < pCurrent->ruta)
	{
	    // Swap the items
	    copyid = pCurrent->id;
	    copydestino = pCurrent->destino;
	    copyorigen = pCurrent->origen;
	    copyruta=pCurrent->ruta;

	    pCurrent->id = pStart->id;
	    pCurrent->destino=pStart->destino;
	    pCurrent->origen=pStart->origen;
	    pCurrent->ruta=pStart->ruta;

	    pStart->id = copyid;
	    pStart->destino = copydestino;
	    pStart->origen=copyorigen;
	    pStart->ruta = copyruta;
	}

	// Check if we have reached the right end
	if (pCurrent == pRight)
	{
            break;
	}

	// Move to the next item in the list
	pCurrent = pCurrent->siguiente;
    }

    // Swap the First and Current items
    copyid = pLeft->id;
    copyorigen = pLeft->origen;
    copydestino=pLeft->destino;
    copyruta=pLeft->ruta;

    pLeft->id= pCurrent->id;
    pLeft->origen=pCurrent->origen;
    pLeft->destino=pCurrent->destino;
    pLeft->ruta=pCurrent->ruta;

    pCurrent->id = copyid;
    pCurrent->origen = copyorigen;
    pCurrent->destino= copydestino;
    pCurrent->ruta = copyruta;

    // Save this Current item
    pRutas pOldCurrent = pCurrent;

    // Check if we need to sort the left hand size of the Current point
    pCurrent = pCurrent->anterior;
    if (pCurrent != NULL)
    {
	if ((pLeft->anterior != pCurrent) && (pCurrent->siguiente != pLeft))
	{
	    rutasquick(pLeft, pCurrent);
	}
    }

    // Check if we need to sort the right hand size of the Current point
    pCurrent = pOldCurrent;
    pCurrent = pCurrent->siguiente;
    if (pCurrent != NULL)
    {
	if ((pCurrent->anterior != pRight) && (pRight->siguiente != pCurrent))
	{
	    rutasquick(pCurrent, pRight);
	}
    }
}

void ListaRuta::bRutas()
{
    bool pal = false;
    int palabra;
    cout<<"Ingrese la ruta a buscar: "<<endl;
    cin>>palabra;
    int auxiliar = 0;
    pRutas aux = inicior;
    while(aux!=finr)
    {
	auxiliar++;
	aux=aux->siguiente;
    }
    aux=inicior;
    cout<<auxiliar<<endl;
    Ruta datos[auxiliar+1];
    for(int i=0; i<auxiliar+1; i++)
    {
        datos[i].id = aux->id;
        datos[i].ruta = aux->ruta;
        datos[i].origen = aux->origen;
        datos[i].destino = aux->destino;
        aux = aux->siguiente;
    }
    int ult;
    int j;
    int i;
    int medio;
    ult=auxiliar;
    i=0;
    j=ult;
    while(i<=j)
    {
        medio=(j+i)/2;
        if(datos[medio].ruta==palabra)
	{
            pal = true;
            cout<<"°RUTA ENCONTRADA°"<<endl;
            cout<<"Id: "<<datos[medio].id<<endl;
            cout<<"Ruta: "<<datos[medio].ruta<<endl;
            cout<<"Origen: "<<datos[medio].origen<<endl;
            cout<<"Destino: "<<datos[medio].destino<<endl;
        }
        if(palabra<datos[medio].ruta)
	{
            j=medio-1;
        }
        else
	{
            i=medio+1;
        }
    }
    if(pal==false)
    {
        cout<<"Error no se encontro la ruta"<<endl;
    }
}
#endif // LISTARUTAS_H_INCLUDED
