#ifndef GRAFORUTAS_H_INCLUDED
#define GRAFORUTAS_H_INCLUDED
#include <iostream>
using namespace std;

class Vertice
{
    public:
    Vertice *siguiente;
    Arista *ady;
    string nombre;
    friend class Grafo;
};

class Arista
{
    public:
    Arista *siguiente;
    Vertice *ady;
    int peso;
    friend class Grafo;
};

class gRutas
{
    Vertice*h;
public:
    void Inicializa();
    bool Vacio();
    int Tamano();
    Vertice *GetVertice(string nombre);
    void InsertaArista(Vertice *origen, 
                       Vertice *destino, 
                       int peso);
    void InsertaVertice(string nombre);
    void ListaAdyacencia();
    void EliminarArista(Vertice *origen, 
                        Vertice *destino);
    void Anular();
};


#endif // GRAFORUTAS_H_INCLUDED
