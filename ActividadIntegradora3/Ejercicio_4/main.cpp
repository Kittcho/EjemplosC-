#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO 4.-
    Rellenar un array de 10 n�meros, posteriormente utilizando punteros indicar cuales son n�meros pares y su posici�n
    en memoria.
    */
    setlocale(LC_ALL, "");

    int arreglo[10],
        *puntero;

    for(int i = 0; i < 10; i++){
        arreglo[i] = i + 1;
    }

    puntero = arreglo;

    for(int i = 0; i < 10; i++){
        if(puntero[i] % 2 == 0){
            cout << "El n�mero " << puntero[i] << " es un n�mero par" << endl;
            cout << "Su posici�n es memoria es: " << &puntero << endl;
        }
    }

    cin.get();
    cin.get();

    return 0;
}
