#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Usuario{
public:
    string id;
    string nombre; 
    string apellido
    string ruta;
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

#endif // USUARIOS_H_INCLUDED
