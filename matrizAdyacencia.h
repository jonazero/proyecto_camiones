#ifndef MATRIZADYACENCIA_H_INCLUDED
#define MATRIZADYACENCIA_H_INCLUDED
#include "Rutas.h"
#include"ListaRutas.h"
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <limits.h>
#include <climits>
#include <limits>
using namespace std;
    vector<string>origenes;
    vector<string>destinos;
    vector<int>pos1;
    vector<int>pos2;
    vector<int>orpos;
    vector<int>despos;
    int oporigen, opdestino;

int tama(int auxiliar)
{
    auxiliar=0;
    pRutas aux = inicior;
    while(aux!=finr){
    auxiliar++;
    aux=aux->siguiente;
    }
    auxiliar++;
    return auxiliar;
}
void posiciones()
{
    int pat =0;
    int pat2=1;
    int tamano = tama(tamano);
    string chacha[tamano][2];

    for(int j=0; j<destinos.size(); j++)
    {
        if(destinos[0] == origenes[j])
        {
          despos.push_back(j);
        }

    }
    pRutas aux = inicior;

    //Matriz que guarda origen y destino
    for(int i=0; i<tamano; i++)
    {

        for(int j=0; j<1; j++)
        {
            chacha[i][j] = aux->origen;
            origenes.push_back(aux->origen);
            destinos.push_back(aux->destino);
        }
        for(int k=1; k<2; k++)
        {
            chacha[i][k] = aux->destino;

        }
        aux =aux->siguiente;
    }
    auto last = unique(origenes.begin(), origenes.end());
    origenes.erase(last, origenes.end());


    auto last1 = unique(destinos.begin(), destinos.end());
    destinos.erase(last1, destinos.end());


    for(int k=0; k<destinos.size(); k++)
    {
        for(int h=0; h<origenes.size(); h++)
        {
          if(destinos[k]==origenes[h])
          {
              despos.push_back(h);
          }
        }
    }

     for(int i=0; i<despos.size()/2; i++)
     {
        pos1.push_back(despos[i+pat]);
        pat++;
     }

     cout<<"Arreglo2\n\n"<<endl;
     for(int i=0; i<despos.size()/2; i++)
     {
         pos2.push_back(despos[i+pat2]);
         pat2++;
     }



}
const int Vertices = 10;

//funcion que devuelce la distancia minima del vertice origen
int distanciaMinima(int dist[], bool origen[])
{
	int min = INT_MAX, disminima;

	for (int v = 0; v < Vertices; v++)
		if (origen[v] == false && dist[v] <= min)
			min = dist[v], disminima = v;

	return disminima;
}


void Imprimircamino(int origen[], int destino)
{

	if (origen[destino] == -1)
		return;

	Imprimircamino(origen, origen[destino]);

	cout<<"-> "<<origenes[destino];
}
int ImprimirSolucion(int dist[], int n, int auxiliar[])
{
	int src = 0;


    cout<<"\n"<<origenes[oporigen]<<" -> "<<origenes[opdestino]<<"\tDistancia: "<<dist[opdestino]<<"\tCamino:"<<origenes[oporigen];
    Imprimircamino(auxiliar, opdestino);
	return 0;
}

void dijkstra(int Grafo[Vertices][Vertices], int origen)
{
	int dist[Vertices]; //dist guarda la distancia mas corta de entre dos vertices


	bool aux[Vertices];


	int conexion[Vertices]; //almacena la conexion entre vertices

    //se inician todas las distancias con false
	for (int i = 0; i < Vertices; i++)
	{
		conexion[origen] = -1;
		dist[i] = INT_MAX;
		aux[i] = false;
	}

	dist[origen] = 0;

	//Buscar el camino mas corto para todos los vertices
	for (int count = 0; count < Vertices - 1; count++)
	{

		int u = distanciaMinima(dist, aux);
        //se marca el certice como true para saber que ya se proceso
		aux[u] = true;

		//se actualiza las distancias considerando el vertice si no se encuentra en auxiliar
		for (int v = 0; v < Vertices; v++)

			if (!aux[v] && Grafo[u][v] &&
				dist[u] + Grafo[u][v] < dist[v])
			{
				conexion[v] = u;
				dist[v] = dist[u] + Grafo[u][v];
			}
	}

	ImprimirSolucion(dist, Vertices, conexion);
}

int dijkFuncion()
{
    unsigned t0, t1;
    t0 = clock();

    int pat =0;
    int pat2 = 1;
    int inicio, fin, medio;
    int auxiliar;
    auxiliar=tama(auxiliar);
    int matriz[Vertices][Vertices];
    int arrayRuta1[(auxiliar+1)/2];
    int arrayRuta2[(auxiliar+1)/2];

    cout<<"Ingrese el origen de: "<<endl;
    for(int i=0; i<origenes.size(); i++)
    {
        cout<<i<<".-"<<origenes[i]<<endl;
    }
    cin>>oporigen;
    cout<<"Ingresa el destino de: "<<endl;
    for(int i=0; i<origenes.size(); i++)
    {
        cout<<i<<".-"<<origenes[i]<<endl;
    }
    cin>>opdestino;
    for(int i=0; i<auxiliar; i+=2)
    {
        arrayRuta1[i-pat] = arrayRuta[i];
        pat++;

    }
    for (int i=1; i<auxiliar; i+=2)
    {
        arrayRuta2[i-pat2] = arrayRuta[i];
        pat2++;
    }

    for(int i =0; i<auxiliar/2; i++)
    {
        for(int j =0; j<auxiliar/2; j++)
        {
           if(j==pos1[i])
           {
               matriz[i][j]=arrayRuta1[i];
           }
           else if(j==pos2[i])
           {
               matriz[i][j]=arrayRuta2[i];
           }
           else
           {
             matriz[i][j]=0;
           }

        }
    }

    for(int i =0; i<auxiliar/2; i++)
    {
        cout<<endl;
        for(int j =0; j<auxiliar/2; j++)
        {
         cout<<matriz[i][j];
        }
    }
    cout<<endl;
    cout<<"Oporigen"<<oporigen<<endl;
    //Se manda a la funcion dijkstra la matriz y el vertice origen
	dijkstra(matriz, oporigen);
	cout<<endl;
	destinos.clear();
    origenes.clear();
    despos.clear();
    orpos.clear();
    pos1.clear();
    pos2.clear();
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout<<"Tiempo de ejecucion: "<<time<<endl;
	return 0;
}


#endif // MATRIZADYACENCIA_H_INCLUDED
