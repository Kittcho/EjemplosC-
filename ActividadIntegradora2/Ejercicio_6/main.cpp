#include <iostream>

using namespace std;

void cambio(int cantidad, int &cien, int &cincuenta, int &veinte, int &diez, int &cinco, int &uno);

int main()
{
    /*
    EJERCICIO 6.-
    Escriba una función nombrada cambio() que tenga un parámetro en número entero y seis
    parámetros de referencia en número entero nombrados cien, cincuenta, veinte, diez, cinco y uno,
    respectivamente.
    La función tiene que considerar el valor entero transmitido como una cantidad en
    dólares y convertir el valor en el número menor de billetes equivalentes.
    */

    int cantidad = 0,
        cien = 0,
        cincuenta = 0,
        veinte = 0,
        diez = 0,
        cinco = 0,
        uno = 0;

    cout << "Favor de ingresar la cantidad a desglozar: $";
    cin >> cantidad;

    cambio(cantidad, cien, cincuenta, veinte, diez, cinco, uno);

    cout << "La cantidad de " << cantidad << " se desgloza de la siguiente manera: \n";
    cout << "Cien: " << cien << "\n";
    cout << "Cincuenta: " << cincuenta << "\n";
    cout << "Veinte: " << veinte << "\n";
    cout << "Diez: " << diez << "\n";
    cout << "Cinco: " << cinco << "\n";
    cout << "Uno: " << uno << "\n";

    cin.get();
    cin.get();

    return 0;
}

void cambio(int cantidad, int &cien, int &cincuenta, int &veinte, int &diez, int &cinco, int &uno){

    while(cantidad > 0){
        if(cantidad >= 100){
            cantidad -= 100;
            cien++;
        }else if(cantidad >= 50){
            cantidad -= 50;
            cincuenta++;
        }else if(cantidad >= 20){
            cantidad -= 20;
            veinte++;
        }else if(cantidad >= 10){
            cantidad -= 10;
            diez++;
        }else if(cantidad >= 5){
            cantidad -= 5;
            cinco++;
        }else{
            uno = cantidad;
            cantidad = 0;
        }
    }

}
