#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO1.-
    Escriba las sentencias necesarias para solicitar e introducir tres valores de punto flotante y después producir su promedio.
    */

    float valor1 = 0,
          valor2 = 0,
          valor3 = 0,
          resultado = 0;

    cout << "Favor de introducir el valor #1: ";
    cin >> valor1;
    cout << "Favor de introducir el valor #2: ";
    cin >> valor2;
    cout << "Favor de introducir el valor #3: ";
    cin >> valor3;

    //operación

    resultado = (valor1 + valor2 + valor3) / 3;

    cout << "El promedio es de: " << resultado;

    cin.get();
    cin.get();

    return 0;
}
