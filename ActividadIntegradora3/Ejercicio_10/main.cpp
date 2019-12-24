#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*
    EJERCICIO 10.-
    Escriba un programa que lea desde un archivo los primeros 20 puntuaciones (calificaciones) y
    produzca la salida del promedio.
    Si el archivo contiene menos de 20 puntuaciones, el segmento
    debe producir a�n el promedio correcto.
    Si el archivo contiene m�s de 20 puntuaciones, los
    n�meros adicionales se deben ignorar.
    Aseg�rese de considerar lo que sucede si el archivo est�
    vac�o.
    */


    ifstream leer;
    float calificacion = 0,
          sumatoria = 0,
          promedio = 0;
    int contador = 0;

    leer.open("calificaciones.txt");

    if(!leer)
        cout << "No se pudo leer el archivo, favor de verificar";
    else{
        while(not leer.eof()){
            leer >> calificacion;
            contador++;
            sumatoria += calificacion;
            if(contador == 20){
                break;
            }
        }
        leer.close();
    }

    promedio = sumatoria / contador;

    if(contador == 1 && sumatoria == 0)
        cout << "El archivo esta vacio.";
    else
        cout << "El promedio es de: " << promedio;

    cin.get();
    cin.get();

    return 0;
}
