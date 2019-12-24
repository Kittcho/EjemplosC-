#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO 4.-
    El nivel de avance de un alumno dentro de una universidad se determina, seg�n el n�mero de cr�ditos cumplidos hasta la
    fecha en la siguiente tabla:
    Cr�ditos A�o acad�mico
    --------------------------------------
    Menos que 32 Primer a�o
    32 a 63 Segundo a�o
    64 a 95 Tercer a�o
    96 o m�s Cuarto a�o
    -------------------------------------
    Usando esta informaci�n, escribir un programa que acepte el n�mero de cr�ditos que ha acumulado un estudiante y determine
    en qu� a�o acad�mico se encuentra, mostrando los resultados por pantalla.
    */
    setlocale(LC_ALL, "");

    int numeroCreditos = 0;

    cout << "Favor de ingresar el n�mero de cr�ditos: ";
    cin >> numeroCreditos;

    if(numeroCreditos < 32){
        cout << "El alumno se encuentra en primer a�o.";
    }else if(numeroCreditos < 64){
        cout << "El alumno se encuentra en segundo a�o.";
    }else if(numeroCreditos < 96){
        cout << "El alumno se encuentra en tercero a�o.";
    }else{
        cout << "El alumno se encuentra en cuarto a�o.";
    }

    cin.get();
    cin.get();

    return 0;
}
