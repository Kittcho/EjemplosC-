#include <iostream>

using namespace std;

class Funcion{
public:
    Funcion(string, double);
    void CambiarNombre(string);
    void CambiarPrecio(double);
    string ObtenerNombre();
    double ObtenerPrecio();
private:
    string nombre;
    double precio;
};

class Teatro{
public:
    Teatro(string, string, Funcion, Funcion, Funcion, Funcion );
    void MuestraDatos();
    void CambiarNombre(string);
private:
    string nombre;
    string direccion;
    Funcion funcion1;
    Funcion funcion2;
    Funcion funcion3;
    Funcion funcion4;
};

Funcion::Funcion(string nombre, double precio){
    this->nombre = nombre;
    this->precio = precio;
}

Teatro::Teatro(string nombre, string direccion, Funcion funcion1, Funcion funcion2, Funcion funcion3, Funcion funcion4){
    this->nombre = nombre;
    this->direccion = direccion;
    this->funcion1 = funcion1;
}



string Funcion::ObtenerNombre(){
    return this->nombre;
}

double Funcion::ObtenerPrecio(){
    return this->precio;
}

void Teatro::MuestraDatos(){
    cout << "Teatro: " << this->nombre << endl;
    cout << "Dirección: " << this->direccion << endl;
    for(int i= 0; i < sizeof(this->funciones); i++){
        cout << "Función #" << i + 1 << ": " << endl;
        cout << "Nombre función: " << this->funcion1.ObtenerNombre() << endl;
        cout << "Precio función: $" << this->funcion2.ObtenerPrecio() << endl;
    }
}

int main()
{
    /*
    EJERCICIO 2.-
    Un teatro se caracteriza por su nombre y su dirección y en él se realizan 4 funciones al día. Cada
    función tiene un nombre y un precio. Realice el diseño de clases e indique qué métodos tendría
    cada clase, teniendo en cuenta que se pueda cambiar el nombre del teatro y el nombre y precio de
    la función. Implemente dichas clases.
    */
    Funcion funcion1;
    Teatro teatro("Pablo de villavicencio","Paseo Niños Heroes S/N, Primer Cuadro, 80000 Culiacán Rosales, Sin.")

    return 0;
}
