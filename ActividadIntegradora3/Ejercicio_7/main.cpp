#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    /*
    EJERCICIO 7.-
    Una empresa organiz� un curso de actualizaci�n el curso est� integrado por 8 alumnos que han
    realizado tres ex�menes y se requiere determinar el n�mero de:
    Alumnos que aprobaron todos los ex�menes.
    Alumnos que aprobaron al menos un examen.
    Alumnos que aprobaron �nicamente el �ltimo examen.
    Realice un programa que permita la lectura de los datos y el c�lculo de las estad�sticas
    */

    string alumnos[8][4];
    string alumnosAprobados = "",
           alumnosAprobadosUno = "",
           alumnosUltimoExamenApro = "";

    int contaAprobadas = 0,
        indice = 0;
    bool ultimoExamenApro = false;

    for(int i = 0; i < 8; i++){
            cout << "Favor de ingresar el nombre del alumno #" << i + 1 << ": ";
            cin.sync();
            getline(cin,alumnos[i][0]);
        for(int j = 0; j < 3; j++){
            cout << "Favor de ingresar la calificaci�n del examen #" << j + 1 << ": ";
            cin.sync();
            getline(cin,alumnos[i][j + 1]);

            float valor = atof(alumnos[i][j + 1].c_str());

            if( valor > 5 ){
                if( j == 2 && contaAprobadas == 0){
                    ultimoExamenApro = true;
                }else
                    contaAprobadas++;
            }
        }
        if(ultimoExamenApro){
            alumnosUltimoExamenApro += alumnos[i][0] + ", ";
        }else if(contaAprobadas > 0 && contaAprobadas < 3){
            alumnosAprobadosUno += alumnos[i][0] + ", ";
        }else{
            alumnosAprobados += alumnos[i][0] + ", ";
        }
        contaAprobadas = 0;
        ultimoExamenApro = false;
    }

    cout << "Alumnos que aprobaron todos los ex�menes: " << alumnosAprobados << endl;
    cout << "Alumnos que aprobaron al menos un examen: " << alumnosAprobadosUno << endl;
    cout << "Alumnos que aprobaron �nicamente el �ltimo examen: " << alumnosUltimoExamenApro << endl;

    cin.get();
    cin.get();

    return 0;
}
