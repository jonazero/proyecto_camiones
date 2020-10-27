#include <iostream>
#include <stdio.h>
#include "Usuarios.h"
#include "Rutas.h"
#include "Lista.h"
#include "ListaRutas.h"

#include "time.h"
#include "matrizAdyacencia.h"
#include "Grafo.h"
using namespace std;
typedef Usuario *pUsuario;

Usuario nuevo;
Lista l_usuarios;
Ruta nueva;
ListaRuta l_rutas;
Grafo dijk;
int main()
{
system("color B0");
l_usuarios.Inicializar();
l_rutas.Inicializar();
l_usuarios.Capturar20();
l_rutas.Capturar20rutas();
string aux, busqapelliddo;
int c;
do{
    cout<<"\t\t\tBIENVENIDO\t\t\t"<<endl;
    cout<<"1.-Agregar usuario"<<endl;
    cout<<"2.-Quitar usuario"<<endl;
    cout<<"3.-Actualizar usuario"<<endl;
    cout<<"4.-Ver usuario"<<endl;
    cout<<"5.-Agregar ruta"<<endl;
    cout<<"6.-Quitar ruta"<<endl;
    cout<<"7.-Actualizar ruta"<<endl;
    cout<<"8.-Ver ruta"<<endl;
    cout<<"9.-Ordenar usuarios"<<endl;
    cout<<"10.-Ordenar rutas"<<endl;
    cout<<"11.-Busqueda binaria usuarios"<<endl;
    cout<<"12.-Busqueda binaria rutas"<<endl;
    cout<<"13.-Prim"<<endl;
    cout<<"14.-Dijkstra"<<endl;
    cout<<"0.-Salir"<<endl;
    cin>>c;
switch(c){
case 1: l_usuarios.Insertar();
break;
case 2: cout<<"Escribe el id del usuario que desea eliminar"<<endl;
        fflush(stdin);
        getline(cin,aux);
        l_usuarios.Eliminar(aux);
        break;
case 3: cout<<"Escriba el id del usuario que desea actualizar"<<endl;
        fflush(stdin);
        getline(cin,aux);
        l_usuarios.Modificar(aux);
        break;
case 4: l_usuarios.Mostrar();
        break;
case 5: l_rutas.Insertar();
        break;
case 6: cout<<"Escribe el id de la ruta que desea eliminar"<<endl;
        fflush(stdin);
        getline(cin,aux);
        l_rutas.Eliminar(aux);
        break;
case 7: cout<<"Escriba el id de la ruta que desea actualizar"<<endl;
        fflush(stdin);
        getline(cin,aux);
        l_rutas.Modificar(aux);
        break;
case 8:
        l_rutas.Mostrar();
        break;
case 9: l_usuarios.Quicky(inicio, fin);
        break;
case 10: l_rutas.rutasquick(inicior,finr);
         break;
case 11: l_usuarios.Quicky(inicio,fin);
         l_usuarios.bb();
        break;
case 12: l_rutas.rutasquick(inicior,finr);
         l_rutas.bRutas();
         break;
case 13:
        posiciones();
        dijkFuncion();
         break;
case 14: posiciones();
         dijkFuncion();

default: break;
}
system("PAUSE");
system("CLS");
}while(c!=0);
return 0;
}
