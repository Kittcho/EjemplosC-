#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*
    EJERCICIO 9.-
    Realice un programa que permita al usuario introducir datos de tipo int y los vaya guardando en un
    Archivo separados por el carácter punto y coma.
    */

    int dato = 0;
    ofstream escribir;
    escribir.open("archivo.txt", std::ofstream::out | std::ofstream::app);

    while(dato != -1){
        cout << "Ingrese el dato a guardar (para salir teclee -1): ";
        cin >> dato;
        if(dato != -1)
            escribir << dato << ";";
    }
    escribir.close();

    cout << "Salio de la escritura.";

    cin.get();
    cin.get();

    return 0;
}
