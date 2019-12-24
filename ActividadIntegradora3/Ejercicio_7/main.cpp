#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
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
    string alumnosAprobados[8],
           alumnosReprobados[8],
           alumnosUltimoExamenRepro[8],
           *p_aprovados,
           *p_reprovados,
           *p_ultimo;

   p_aprovados = alumnosAprobados;
   p_reprovados = alumnosReprobados;
   p_ultimo = alumnosUltimoExamenRepro;


    int contaReprobadas = 0,
        indice = 0;
    bool ultimoExamenRepro = false;

    for(int i = 0; i < 8; i++){
            cout << "Favor de ingresar el nombre del alumno #" << i + 1 << ": ";
            cin.sync();
            getline(cin,alumnos[i][0]);
        for(int j = 0; j < 3; j++){
            cout << "Favor de ingresar la calificaci�n del examen #" << j + 1 << ": ";
            cin.sync();
            getline(cin,alumnos[i][j + 1]);

            float valor = atof(alumnos[i][j + 1].c_str());

            if( valor < 6 ){
                if( j == 2 && contaReprobadas == 0){
                    ultimoExamenRepro = true;
                }else
                    contaReprobadas++;
            }
        }
        if(ultimoExamenRepro){
            string valor = alumnos[i][0];
            p_ultimo = valor;
            p_ultimo++;
        }else if(contaReprobadas > 0){
            p_reprovados = alumnos[i][0];
            p_reprovados++;
        }else{
            p_aprovados = alumnos[i][0];
            p_aprovados++;
        }
    }

    return 0;
}
