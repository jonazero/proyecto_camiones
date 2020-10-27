#ifndef RUTAS_H_INCLUDED
#define RUTAS_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
extern int arrayRuta[20]={11,5,9,18,15,8,4,2,6,10,16,13,7,17,20,19,12,14,1,3};
extern string arrayOrigen[20]={"Guadalajara","Guadalajara","Zapotlanejo","Zapotlanejo","Tequila",
                              "Tequila","Tlajomulco","Tlajomulco","Jamay","Jamay",
                              "Arandas","Arandas","Puerto Vallarta", "Puerto Vallarta", "Yahualica",
                              "Yahualica","San Sebastian del Oeste","San Sebastian del Oeste", "Zapopan", "Zapopan"};

extern string arrayDestino[20]={"Zapopan", "Tlajomulco", "Puerto Vallarta", "Arandas", "Guadalajara",
                               "Zapotlanejo","Tequila","San Sebastian del Oeste", "Zapopan", "Yahualica",
                               "Tequila","Jamay","Guadalajara","Tlajomulco", "Zapotlanejo",
                               "Arandas","Yahualica","Jamay","San Sebastian del Oeste","Puerto Vallarta"};

class Ruta{
public:

    string id,origen, destino;
    int ruta;
    string arrayId[20]={"1","2","3","4","5","6","7","8","9","10",
                          "11","12","13","14","15","16","17","18","19","20"};
    int arrayRuta[20]={11,5,9,18,15,8,4,2,10,6,16,13,7,17,20,19,14,12,3,1};
    string arrayOrigen[20]={"Guadalajara","Guadalajara","Zapotlanejo","Zapotlanejo","Tequila",
                              "Tequila","Tlajomulco","Tlajomulco","Jamay","Jamay",
                              "Arandas","Arandas","Puerto Vallarta", "Puerto Vallarta", "Yahualica",
                              "Yahualica","San Sebastian del Oeste","San Sebastian del Oeste", "Zapopan", "Zapopan"};

    string arrayDestino[20]={"Zapopan", "Tlajomulco", "Puerto Vallarta", "Arandas", "Guadalajara",
                               "Zapotlanejo","Tequila","San Sebastian del Oeste", "Zapopan", "Yahualica",
                               "Tequila","Jamay","Guadalajara","Tlajomulco", "Zapotlanejo",
                               "Arandas","Yahualica","Jamay","San Sebastian del Oeste","Puerto Vallarta"};

    void Ingresar();
    void Mostrar();
    void rutaArray(int jala);
    Ruta *siguiente, *anterior;
};

void Ruta::Ingresar(){
cout<<"Ingrese el id"<<endl;
fflush(stdin);
getline(cin,id);
cout<<"Ingrese la ruta"<<endl;
cin>>ruta;
cout<<"Ingrese el origen"<<endl;
fflush(stdin);
getline(cin,origen);
cout<<"Ingrese el destino"<<endl;
fflush(stdin);
getline(cin,destino);


}
void Ruta::rutaArray(int jala)
{
    id=arrayId[jala];
    ruta=arrayRuta[jala];
    origen=arrayOrigen[jala];
    destino=arrayDestino[jala];
}
void Ruta::Mostrar(){
cout<<"El id es: "<<id<<endl;
cout<<"La ruta es: "<<ruta<<endl;
cout<<"El origen es: "<<origen<<endl;
cout<<"El destino es "<<destino<<endl;
}
#endif // RUTAS_H_INCLUDED
