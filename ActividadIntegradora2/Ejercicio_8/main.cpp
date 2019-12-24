#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO 8.-
    Escribir un programa que calcule cuantos años tarda en duplicarse un capital depositado al 5% de
    interés anual.
    */

    setlocale(LC_ALL, "");

    double capital = 1,
        nuevoCapital = capital,
        interesesGanados = 0;
    int contadorAnios = 0;


    while((capital * 2) > nuevoCapital){
        interesesGanados += nuevoCapital * 0.05;
        nuevoCapital += nuevoCapital * 0.05;
        contadorAnios++;
    }

    cout << "La cantidad de años en duplicar la cantidad de $" << capital << " es de " << contadorAnios << " años y habrá ganado $"<< interesesGanados << " en intereses, teniendo un nuevo capital de $" << nuevoCapital;

    cin.get();
    cin.get();

    return 0;
}
