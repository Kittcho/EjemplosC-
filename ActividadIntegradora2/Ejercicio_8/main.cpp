#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO 8.-
    Escribir un programa que calcule cuantos a�os tarda en duplicarse un capital depositado al 5% de
    inter�s anual.
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

    cout << "La cantidad de a�os en duplicar la cantidad de $" << capital << " es de " << contadorAnios << " a�os y habr� ganado $"<< interesesGanados << " en intereses, teniendo un nuevo capital de $" << nuevoCapital;

    cin.get();
    cin.get();

    return 0;
}
