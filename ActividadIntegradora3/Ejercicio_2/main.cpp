#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO 2.-
    Un vendedor recibe un sueldo base, m�s 12% extra por comisiones de sus ventas, el vendedor
    desea saber cu�nto dinero cobrar� por concepto de comisiones realizadas en las ventas que
    realizadas en el mes y el sueldo total que recibir� en el mes.
    */
    setlocale(LC_ALL, "");

    #define PORCENTAJE_COMISION 0.12;

    double sueldoBase = 0,
           cantidadVentas = 0,
           comision = 0,
           sueldoTotal = 0;

    cout << "Favor de ingresar su sueldo base: $";
    cin >> sueldoBase;

    cout << "Favor de ingresar las ventas en pesos del mes: $";
    cin >> cantidadVentas;

    comision = cantidadVentas * PORCENTAJE_COMISION;
    sueldoTotal = comision + sueldoBase;

    cout << "La comisi�n ganada es de: $" << comision << endl;
    cout << "El sueldo m�s comisi�n es de: $" << sueldoTotal;

    cin.get();
    cin.get();

    return 0;
}
