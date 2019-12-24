#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO 9.-
    Realizaci�n de la operaci�n para calcular el precio de una venta de N art�culos en una tienda.
    Verifique y aplique el descuento si el art�culo se encuentra con descuento.
    */

    double precio = 0,
           totalVenta = 0;
    double porcentajeDescuento = 0;

    while(precio != -1){
        cout << "\nFavor de ingresar el precio del producto (para terminar ingrese -1): $";
        cin >> precio;

        if(precio != -1){
            cout << "Ingrese el porcentaje de descuento: ";
            cin >> porcentajeDescuento;

            totalVenta += precio - (precio * (porcentajeDescuento / 100));
        }
    }

    cout << "El total de la venta es de: $" << totalVenta;

    cin.get();
    cin.get();

    return 0;
}
