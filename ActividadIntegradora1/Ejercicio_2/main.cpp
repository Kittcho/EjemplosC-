#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO2.-
    Realice un programa que lea la entrada de dos n�meros y muestre en la salida est�ndar su suma, resta, multiplicaci�n y divisi�n.
    */

    int valor1 = 0,
        valor2 = 0;

    cout << "Ingrese el valor #1: ";
    cin >> valor1;

    cout << "Ingrese el valor #2: ";
    cin >> valor2;

    cout << "\nResultados: \n";
    cout << "Suma = " << valor1 + valor2 << "\n";
    cout << "Resta = " << valor1 - valor2 << "\n";
    cout << "Multiplicacion = " << valor1 * valor2 << "\n";
    cout << "Divicion = " << float(valor1) / (float)valor2 << "\n";

    cin.get();
    cin.get();

    return 0;
}
