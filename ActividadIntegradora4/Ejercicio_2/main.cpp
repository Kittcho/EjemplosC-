#include <iostream>

using namespace std;

class Funcion{
public:
    void CambiarNombre(string);
    void CambiarPrecio(double);
    string getNombre();
    void setNombre( string nombre );
    double getPrecio();
    void setPrecio( double precio );
private:
    string nombre;
    double precio;
};

string Funcion::getNombre(){
    return this->nombre;
}

void Funcion::setNombre( string nombre ){
    this->nombre = nombre;
}

double Funcion::getPrecio(){
    return this->precio;
}

void Funcion::setPrecio( double precio ){
    this->precio = precio;
}



class Teatro{
public:
    Teatro( string nombre, string direccion, Funcion funcion1, Funcion funcion2, Funcion funcion3, Funcion funcion4 );
    void CambiarNombre(string);
    void MostrarDatos();
private:
    string nombre;
    string direccion;
    Funcion funcion1;
    Funcion funcion2;
    Funcion funcion3;
    Funcion funcion4;
};

Teatro::Teatro(string nombre, string direccion, Funcion funcion1, Funcion funcion2, Funcion funcion3, Funcion funcion4)
{
    this->nombre = nombre;
    this->direccion = direccion;
    this->funcion1 = funcion1;
    this->funcion2 = funcion2;
    this->funcion3 = funcion3;
    this->funcion4 = funcion4;
}

void Teatro::MostrarDatos(){
    cout << "Teatro: " << this->nombre << endl;
    cout << "Domicilio: " << this->direccion << endl;
    cout << "Las funciones son: " << endl;
    cout << "- " << this->funcion1.getNombre() << " = $" << this->funcion1.getPrecio() << endl;
    cout << "- " << this->funcion2.getNombre() << " = $" << this->funcion2.getPrecio() << endl;
    cout << "- " << this->funcion3.getNombre() << " = $" << this->funcion3.getPrecio() << endl;
    cout << "- " << this->funcion4.getNombre() << " = $" << this->funcion4.getPrecio() << endl;
}

int main()
{
    /*
    EJERCICIO 2.-
    Un teatro se caracteriza por su nombre y su dirección y en él se realizan 4 funciones al día.
    Cada función tiene un nombre y un precio.
    Realice el diseño de clases e indique qué métodos tendría cada clase, teniendo en cuenta que se pueda cambiar
    el nombre del teatro y el nombre y precio de la función. Implemente dichas clases.
    */
    setlocale(LC_ALL, "");

    Funcion fun1;
    fun1.setNombre( "Romeo y Julieta" );
    fun1.setPrecio( 200 );

    Funcion fun2;
    fun2.setNombre( "Hamlet" );
    fun2.setPrecio( 250 );

    Funcion fun3;
    fun3.setNombre( "La Celestina" );
    fun3.setPrecio( 150 );

    Funcion fun4;
    fun4.setNombre( "Don Juan Tenorio" );
    fun4.setPrecio( 400 );

    Teatro teatro("Pablo de villavicencio","Paseo Niños Heroes S/N, Primer Cuadro, 80000 Culiacán Rosales, Sin.", fun1, fun2, fun3, fun4);
    teatro.MostrarDatos();

    cin.get();
    cin.get();

    return 0;
}
