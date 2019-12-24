#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO 3.-
    La universidad ofrece una beca de 30% para los estudiantes que cumplan ciertos requisitos, luego de haber culminado el
    primer ciclo de su carrera. Los requisitos son los siguientes:
     Tener un promedio ponderado mayor o igual a 15.
     No tener ninguna falta.
    Con esta información elabore un programa que determine el otorgamiento de una beca. Los datos que debe ingresar son la
    nota y la cantidad de faltas
    */

    int nota = 0,
        cantidadFaltas = -1;

    cout << "Ingrese la nota del alumno: ";
    cin >> nota;

    cout << "Ingrese la cantidad de faltas: ";
    cin >> cantidadFaltas;

    if(nota >= 15 && cantidadFaltas == 0){
        cout << "El alumno es candidato para la beca del 30%.";
    }else{
        cout << "Lo sentimos, el alumno no es candidato para la beca del 30%.";
    }

    cin.get();
    cin.get();

    return 0;
}
