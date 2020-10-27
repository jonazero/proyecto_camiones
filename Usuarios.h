#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Usuario{
public:
    string id, nombre, apellido, ruta;
    string arrayNombres[20]= {"Ana", "Roberto", "Juan", "Rodrigo", "Angel",
                            "Agustin", "Cristian", "Carlos", "Julian", "Belen",
                            "Jonathan", "Israel", "Jose", "Luis", "Miguel",
                            "Carla", "Ximena", "Linda", "Paulina", "Elisa"};
    string arrayId[20]={"1","2","3","4","5","6","7","8","9","10",
                          "11","12","13","14","15","16","17","18","19","20"};
    string arrayApellido[20]={"Gutierrez","Lozano","Elizalde","Ruvalcaba","Segoviano",
                                "Diaz","Lozano","Sanchez","Aguilar","Zarate",
                                "Gonzalez","Mendoza","Perez","Moreno", "Baez",
                                "Hernandez", "Pardo", "Zepeda", "Anguiano", "Acosta"};
    string arrayRuta[20]={"1","2","3","4","5","6","7","8","9","10",
                          "11","12","13","14","15","16","17","18","19","20"};

    void Ingresar();
    void Mostrar();
    void UsuarioArray(int jala);
    Usuario *siguiente, *anterior;
};

void firstUpper ( string& str ) {
  str[0] = ::toupper( str[0] );
  for ( string::iterator it = str.begin(); it != str.end(); it++ )
    if ( *it == ' ' )
      *( it+1 ) = ::toupper( *( it+1 ) );
}
void Usuario::Ingresar()
{
    cout<<"Ingrese el id: "<<endl;
    fflush(stdin);
    getline(cin, id);
    cout<<"Ingrese el nombre: "<<endl;
    fflush(stdin);
    getline(cin,nombre);
    firstUpper(nombre);
    cout<<"Ingrese el apellido: "<<endl;
    fflush(stdin);
    getline(cin, apellido);
    firstUpper(apellido);
    cout<<"Ingrese la ruta: "<<endl;
    fflush(stdin);
    getline(cin,ruta);
}

void Usuario::Mostrar()
{
    cout<<"El id es: "<<id<<endl;
    cout<<"El nombre es: "<<nombre<<endl;
    cout<<"El apellido es: "<<apellido<<endl;
    cout<<"La ruta es: "<<ruta<<endl;
    cout<<"|||||||||||||||||||||||||"<<endl;
}

void Usuario::UsuarioArray(int jala)
{
id=arrayId[jala];
nombre=arrayNombres[jala];
apellido=arrayApellido[jala];
ruta=arrayRuta[jala];
}

#endif // USUARIOS_H_INCLUDED
