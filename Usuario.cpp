#include <Usuario.h>

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
