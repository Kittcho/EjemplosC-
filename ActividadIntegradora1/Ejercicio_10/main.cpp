#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO10.-
    Suponiendo que el recibo de la luz sube un 3% cada a�o, realice un programa que solicite una factura de este a�o y una cantidad de
    a�os y muestre en la salida est�ndar cuanto valdr�a la factura dentro del n�mero de a�os introducidos.
    */
    setlocale(LC_ALL, "");

    #define PORCENTAJE_ANUAL 0.03
    double cantidadFactura = 0;
    int cantidadAnios = 0;

    cout << "Ingrese la cantidad de la factura: $";
    cin >> cantidadFactura;

    cout << "Ingrese la cantidad de a�os a calcular: ";
    cin >> cantidadAnios;

    cout << "El valor de la factuta [$"<< cantidadFactura << "] a " << cantidadAnios << " a�os, tendr� un valor de: $" << ((cantidadFactura * PORCENTAJE_ANUAL) * cantidadAnios) + cantidadFactura << " pesos.";

    cin.get();
	cin.get();

    return 0;
}
