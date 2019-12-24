#include <iostream>
#include <math.h>

using namespace std;

double CalculaPagoMensual(double dinero, double interesMensual, int anios);

int main()
{
    /*
    EJERCICIO 10.-
    Un empleado está pensando en refinanciar su hipoteca y necesita ayuda con los cálculos. Realice
    un programa que realice los cálculos de manera automática. Los datos necesarios en este
    programa son la cantidad de dinero por ahorrar, el número de años para el préstamo y la tasa de
    interés. De estos tres valores, se puede calcular el pago mensual. A continuación apóyese en la
    siguiente formula
    Cantidad * (1 + Interés mensual)^número de pagos * Interés mensual / (1 + Interés mensual)^numero de pagos−1
    */
    setlocale(LC_ALL, "");

    double cantidadDinero = 0,
           tasaInteresMensual = 0;
    int numeroAnios = 0;

    cout << "Favor de ingresar la cantidad de dinero a solicitar: $";
    cin >> cantidadDinero;

    cout << "Favor de ingresar el número de años del crédito: ";
    cin >> numeroAnios;

    cout << "Favor de ingresar el interes mensual: ";
    cin >> tasaInteresMensual;

    cout << "El pago mensual es de: $" << CalculaPagoMensual(cantidadDinero, tasaInteresMensual, numeroAnios);

    return 0;
}

double CalculaPagoMensual(double dinero, double interesMensual, int anios){
    double pagoMensual = 0;
    int meses = anios * 12;

    pagoMensual = (dinero * pow(( 1 + interesMensual ),(double)meses) * interesMensual) / pow(( 1 + interesMensual),(double)meses - 1);

    return pagoMensual;

}
