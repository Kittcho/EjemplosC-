#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO 2.-
    Escribir un programa que permita calcular el descuento del cliente en su compra total en una
    tienda departamental.
    Si el cliente es empleado se le hace un 20% sobre la compra.
    Si el cliente no es empleado y tiene una antigüedad como menor a 10 años registrado como cliente tiene un 10% en su compra total.
    Si el cliente tiene una antigüedad como mayor a 10 años registrado como cliente tiene un descuento del 30% del total de su compra.
    De la compra que realiza todo cliente si su compra es al contado se le hace un 10% más en su compra.
    */
    setlocale(LC_ALL, "");

    #define DESCUENTO_EMPLEADO 0.2;
    #define DESCUENTO_MENOS_10_ANIOS 0.1;
    #define DESCUENTO_MAS_10_ANIOS 0.3;
    #define DESCUENTO_CONTADO 0.1;

    char esEmpleado;
    char esDeContado;
    float descuentoTotal;
    double compra = 0;
    int antiguedad = 0;

    cout << "Ingrese el monto de la compra: $";
    cin >> compra;

    bool continuar;
    do{
        cout << "¿El cliente es empleado? (S = si, N = no): ";
        cin >> esEmpleado;

        continuar = false;

        switch(esEmpleado)
        {
            case 's': case 'S':
                descuentoTotal = DESCUENTO_EMPLEADO;
            break;
            case 'n': case 'N':
                cout << "Cual es la antiguedad del cliente en años: ";
                cin >> antiguedad;
                if(antiguedad <= 10){
                    descuentoTotal = DESCUENTO_MENOS_10_ANIOS;
                }else{
                    descuentoTotal = DESCUENTO_MAS_10_ANIOS;
                }
            break;
            default:
                cout << "opción no valida, favor de intentar de nuevo.\n";
                continuar = true;
                break;

        }
    }while(continuar);

    do
    {
        continuar = false;

        cout << "¿La compra es a contado? (S = si, N = no): ";
        cin >> esDeContado;

        if(esDeContado == 's' || esDeContado == 'S'){
            descuentoTotal += DESCUENTO_CONTADO;
        }else if(esDeContado != 'n' && esDeContado != 'N'){
            cout << "opción no valida, favor de intentar de nuevo.\n";
            continuar = true;
        }

    }while(continuar);

    cout << "Sub-Total: " << compra << "\n";
    cout << "(-) descuento: " << descuentoTotal * 100 << "%\n";
    cout << "Total: " << compra - (compra * descuentoTotal)  << "\n";

    cin.get();
    cin.get();

    return 0;
}
