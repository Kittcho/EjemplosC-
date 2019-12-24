#include <iostream>

using namespace std;

double CalculaZonaCentro(int kilowatts);
double CalculaZonaRural(int kilowatts);

int main()
{
    /*
    EJERCICIO 7.-
    El administrador de una cadena de tiendas, desea contar con un programa que le permita calcular
    el monto a pagar por sus clientes, considerando como dato la cantidad de kilowatts consumidos al
    mes y la zona donde se ubica. Existen dos tipos:
    Si la zona es Centro se cobra una tarifa fija de 50 pesos, luego por los primeros 100 kilowatts se les
    cobra 0.75 pesos y por cada kilowatt por encima de los 100 se le cobra 0.9 pesos.
    Si la zona es Rural, se cobra una tarifa fija de 25 pesos, luego por los primeros 100 kilowatts se les
    cobra 0.30 pesos y por cada kilowatt por encima de los 100 se les cobra 0.7 pesos
    */

    int kilowatts = 0,
        tipoZona = 0;
    double cantidadTotal = 0;
    bool todoBien = true;

    cout << "Favor de ingresar los kilowatts consumidos: ";
    cin >> kilowatts;

    cout << "Favor de ingresar 1 para zona centro o 2 para zona rural: ";
    cin >>  tipoZona;

    switch(tipoZona){
    case 1:
        cantidadTotal = CalculaZonaCentro(kilowatts);
        break;
    case 2:
        cantidadTotal = CalculaZonaRural(kilowatts);
        break;
    default:
        cout << "Tipo de zona invalida.";
        todoBien = false;
        break;
    }

    if(todoBien){
        cout << "La cantidad a pagar por los kilowatts consumidos son: $" << cantidadTotal;
    }

    cin.get();
    cin.get();

    return 0;
}

double CalculaZonaCentro(int kilowatts){
    #define TARIFA_FIJA 50
    double total = TARIFA_FIJA;

    if(kilowatts >= 100 ){
        total += ((kilowatts - 100) * 0.9) + 0.75;
    }

    return total;
}

double CalculaZonaRural(int kilowatts){
    #define TARIFA_FIJA 25
    double total = TARIFA_FIJA;

    if(kilowatts >= 100 ){
        total += ((kilowatts - 100) * 0.7) + 0.30;
    }

    return total;
}
