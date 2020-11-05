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
#endif // GRAFO_H_INCLUDED
