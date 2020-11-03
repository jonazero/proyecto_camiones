#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <Rutas.h>
#include <ListaRutas.h>
#include <iomanip>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
const int vertices = 10;

class Grafo
{
public:

    vector<string>origenes;
    vector<string>destinos;
    vector<int>pos1;
    vector<int>pos2;
    vector<int>orpos;
    vector<int>despos;
    int oporigen, opdestino;
    int tama(int auxiliar);
    void posiciones();
    int distanciaMinima(int dist[],
			bool sptSet[]);
    void Imprimircamino(int auxiliar[],
			int j);
    int ImprimirSolucion(int dist[],
			 int n,
			 int auxiliar[]);
    void DijkstraFuncion();
    void Dijkstra(int Grafo[Vertices][Vertices],
		  int src);
};

int Grafo::tama(int auxiliar)
{
    auxiliar=0;
    pRutas aux = inicior;
    while(aux!=finr)
    {
        auxiliar++;
	aux=aux->siguiente;
    }
    auxiliar++;
    return auxiliar;
}

void Grafo::posiciones()
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
	    cout<<despos[j]<<endl;
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

    for(int i=0; i<tamano; i++)
    {
        cout<<endl;
        for(int j=0; j<2; j++)
        {
            cout<<chacha[i][j];
        }
    }
    cout<<endl;
	
    cout<<"Borrado\n\n"<<endl;
    auto last = unique(origenes.begin(), origenes.end());
    origenes.erase(last, origenes.end());
    for(int i=0; i<origenes.size(); i++)
    {
        cout<<origenes[i]<<" "<<endl;
    }

    cout<<"\n\n\n";

    auto last1 = unique(destinos.begin(), destinos.end());
    destinos.erase(last1, destinos.end());
    for (const auto& i : destinos)
    {
	cout << i <<endl;
    }


    cout<<"\n\n";
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

     for(int i=0; i<despos.size(); i++)
     {
         cout<<despos[i]<<endl;
     }

     cout<<"Arreglo\n\n"<<endl;

     for(int i=0; i<despos.size()/2; i++)
     {
        pos1.push_back(despos[i+pat]);
        cout<<pos1[i]<<endl;
        pat++;
     }

     cout<<"Arreglo2\n\n"<<endl;
     for(int i=0; i<despos.size()/2; i++)
     {
         pos2.push_back(despos[i+pat2]);
         cout<<pos2[i]<<endl;
         pat2++;
     }
origenes.clear();
}
int Grafo::distanciaMinima(int dist[], 
			   bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++)
    {
	if (sptSet[v] == false && dist[v] <= min)
	{
	    min = dist[v], min_index = v;
	}
    }
    return min_index;
}
void Grafo::Imprimircamino(int auxiliar[], 
			   int j)
{
    if (auxiliar[j] == -1)
    {
	return;
    }
    Imprimircamino(auxiliar, auxiliar[j]);
    cout<<"-> "<<origenes[j];
}
int Grafo::ImprimirSolucion(int dist[], 
			    int n, 
			    int auxiliar[])
{
    int src = 0;
    cout<<"\n"<<origenes[oporigen]<<" -> "<<origenes[opdestino]<<"\tDistancia: "
	    <<dist[opdestino]<<"\tCamino:"<<origenes[oporigen];
    Imprimircamino(auxiliar, opdestino);
    return 0;
}
void Grafo::Dijkstra(int Grafo[vertices][vertices], 
		     int src)
{
	int dist[vertices]; //dist guarda la distancia mas corta de entre dos vertices
	bool sptSet[vertices];
	int parent[vertices];
	for (int i = 0; i < vertices; i++)
	{
	    parent[src] = -1;
	    dist[i] = INT_MAX;
	    sptSet[i] = false;
	}
	dist[src] = 0;

	for (int count = 0; count < vertices - 1; count++)
	{
	    int u = distanciaMinima(dist, sptSet);
	    sptSet[u] = true;
	    for (int v = 0; v < vertices; v++)
	    {
		if (!sptSet[v] && Grafo[u][v] && dist[u] + Grafo[u][v] < dist[v])
		{
		    parent[v] = u;
		    dist[v] = dist[u] + Grafo[u][v];
		}
	}
	ImprimirSolucion(dist, vertices, parent);
}
void Grafo::DijkstraFuncion()
{
    int pat =0;
    int pat2 = 1;
    int inicio; 
    int fin;
    int medio;
    int auxiliar;
    auxiliar=tama(auxiliar);
    int matriz[vertices][vertices];
    int arrayRuta1[(auxiliar+1)/2];
    int arrayRuta2[(auxiliar+1)/2];
    posiciones();
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
}
#endif // GRAFO_H_INCLUDED
