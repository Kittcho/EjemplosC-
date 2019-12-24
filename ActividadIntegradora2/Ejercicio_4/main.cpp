#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO 4.-
    El nivel de avance de un alumno dentro de una universidad se determina, según el número de créditos cumplidos hasta la
    fecha en la siguiente tabla:
    Créditos Año académico
    --------------------------------------
    Menos que 32 Primer año
    32 a 63 Segundo año
    64 a 95 Tercer año
    96 o más Cuarto año
    -------------------------------------
    Usando esta información, escribir un programa que acepte el número de créditos que ha acumulado un estudiante y determine
    en qué año académico se encuentra, mostrando los resultados por pantalla.
    */
    setlocale(LC_ALL, "");

    int numeroCreditos = 0;

    cout << "Favor de ingresar el número de créditos: ";
    cin >> numeroCreditos;

    if(numeroCreditos < 32){
        cout << "El alumno se encuentra en primer año.";
    }else if(numeroCreditos < 64){
        cout << "El alumno se encuentra en segundo año.";
    }else if(numeroCreditos < 96){
        cout << "El alumno se encuentra en tercero año.";
    }else{
        cout << "El alumno se encuentra en cuarto año.";
    }

    cin.get();
    cin.get();

    return 0;
}
