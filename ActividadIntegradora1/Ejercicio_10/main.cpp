#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO10.-
    Suponiendo que el recibo de la luz sube un 3% cada año, realice un programa que solicite una factura de este año y una cantidad de
    años y muestre en la salida estándar cuanto valdría la factura dentro del número de años introducidos.
    */
    setlocale(LC_ALL, "");

    #define PORCENTAJE_ANUAL 0.03
    double cantidadFactura = 0;
    int cantidadAnios = 0;

    cout << "Ingrese la cantidad de la factura: $";
    cin >> cantidadFactura;

    cout << "Ingrese la cantidad de años a calcular: ";
    cin >> cantidadAnios;

    cout << "El valor de la factuta [$"<< cantidadFactura << "] a " << cantidadAnios << " años, tendrá un valor de: $" << ((cantidadFactura * PORCENTAJE_ANUAL) * cantidadAnios) + cantidadFactura << " pesos.";

    cin.get();
	cin.get();

    return 0;
}
