#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO3.-
    Escribir un programa que dé la entrada el precio de un producto y muestre en la salida estándar el
    precio del producto al a plicarle el IVA.
    */

    #define IVA 0.16
    float precio = 0;

    cout << "Favor de ingresar el precio del articulo: $";
    cin >> precio;

    cout << "Precio del producto mas IVA(16%): $" << (precio * IVA) + precio;

    cin.get();
    cin.get();

    return 0;
}
