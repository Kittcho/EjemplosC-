#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO4.-
    Realice un programa que lea la entrada de los siguientes datos de una persona:
    Edad: dato de tipo entero.
    Sexo: dato de tipo carácter.
    Altura en metros: dato de tipo real.
    tras leer los datos, el programa debe mostrar la salida en una sola línea.
    */

    int edad = 0;
    char sexo;
    float altura;

    cout << "Favor de ingresar su edad: ";
    cin >> edad;

    cout << "Favor de ingresar su sexo (M = Masculino, F = Femenino): ";
    cin >> sexo;

    cout << "Favor de ingresar su altura: ";
    cin >> altura;

    cout << "Usted tiene una edad de " << edad << " años, su sexo es '" << sexo << "' y mide " << altura << " metros.";

    cin.get();
    cin.get();

    return 0;
}
