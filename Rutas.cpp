#include <Rutas.h>

void Ruta::Ingresar()
{
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
