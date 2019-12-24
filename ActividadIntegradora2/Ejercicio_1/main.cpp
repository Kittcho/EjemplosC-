#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO 1.-
    Escribir un programa, que permita calcular el precio de una entrada al cine de un grupo de
    personas, considerando lo siguiente:
    - Si la persona tiene menos de 18 años pagará 35 pesos.
    - Si la persona tiene de 18 a 50 años pagará 60 pesos.
    - Si la persona tiene más de 50 años pagará 50 pesos.
    Desplegar la salida del total a pagar
    */

    int total = 0;
    int edad = 0;
    int cantidadPersonas = 0;

    cout << "Favor de intruducir la cantidad de personas del grupo: ";
    cin >> cantidadPersonas;

    for(int i = 0; i < cantidadPersonas; i++){
        cout << "Favor de ingresar la edad de la persona #" << i + 1 << ": ";
        cin >> edad;

        if(edad < 18){
            total += 35;
        }else if(edad <= 50){
            total += 60;
        }else{
            total += 50;
        }
    }

    cout << "El total a pagar es por la cantidad de: $" << total;

    cin.get();
    cin.get();

    return 0;
}
