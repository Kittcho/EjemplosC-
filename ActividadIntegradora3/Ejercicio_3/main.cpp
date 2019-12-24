#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    /*EJERCICIO 3.-
    Hacer un programa que permita manejar la información de habitantes de un complejo habitacional.
    El mismo posee 7 torres; a su vez cada torre posee 20 pisos y cada piso 6 departamentos. Se desea saber:
    Cantidad total de habitantes del complejo.
    Cantidad promedio de habitantes por piso de cada torre.
    Cantidad promedio de habitantes por torre*/

    int torre[7][20][6];
    int promedioPisoTorre[7][20];
    int promedioTorre[7];
    int cantidadTotal = 0;

    srand((unsigned)time(NULL));

    //inicializando matrices
    for(int i = 0; i < 7 ; i++){
        for(int j = 0; j < 20 ; j++){
            for(int k = 0; k < 6 ; k++){
                torre[i][j][k] = 0;
            }
            promedioPisoTorre[i][j] = 0;
        }
        promedioTorre[i] = 0;
    }

    //Torre
    for(int i = 0; i < 7 ; i++){
        for(int j = 0; j < 20 ; j++){
            for(int k = 0; k < 6 ; k++){
                torre[i][j][k] = rand()%6+1;
                cantidadTotal += torre[i][j][k];
                //conteo por piso
                promedioPisoTorre[i][j] += torre[i][j][k];
                cout << "Torre: " << i + 1 << ", Piso: " << j + 1 << ", Departamento: " << k + 1 << ", personas: " << torre[i][j][k] << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << "Cantidad total de habitantes: " << cantidadTotal << endl;
    cout << "Cantidad promedio de habitantes por piso de cada torre: " << endl;

    for(int i = 0; i < 7 ; i++){
            cout << "Torre #" << i + 1 << ": " << endl;
        for(int j = 0; j < 20 ; j++){
            cout << "Promedio piso #" << j + 1 << ": " << promedioPisoTorre[i][j] / 6 << endl;
            promedioTorre[i] += promedioPisoTorre[i][j];
        }
    }

    cout << endl;
    for(int i = 0; i < 7 ; i++){
            cout << "Promedio Torre #" << i + 1 << ": " << promedioTorre[i] / 20 << endl;
    }

    cin.get();
    cin.get();

    return 0;
}
