#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Fecha{
public:
    bool ValidaFecha(int mes);
    bool ValidaFecha(string mes);
private:
    int anio,
        mes,
        dia,
        hora;
    string msjError;
};

bool Fecha::ValidaFecha(int mes){
    bool todoBien = true;
    this->msjError = "";
    int num_mes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(mes > 12 || mes < 1){
        this->msjError = "Formato de mes incorrecto.\n";
        todoBien = false;
    }

    if(this->hora > 24 || this->hora < 0){
        this->msjError += "Formato de hora incorrecto.\n";
        todoBien = false;
    }

    if(this->dia == 0 || this->dia < 0){
        this->msjError += "Formato de día incorrecto.\n";
        todoBien = false;
    }

    if(dias_mes[mes - 1] >= this->dia){
        if(mes == 2 && this->dia == 29 && this->anio % 4 == 0){

        }else{
            this->msjError += "Excede los días del mes.\n";
            todoBien = false;
        }
    }

}
/*
bool Fecha::ValidaFecha(string mes){
     bool todoBien = true;
    this->msjError = "";
    string num_mes[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int i = 0; i < sizeof(num_mes); i++){
        if(num_mes[i] == mes :: tolower)
    }

    if(mes > 12 || mes < 1){
        this->msjError = "Formato de mes incorrecto.\n";
        todoBien = false;
    }

    if(this->hora > 24 || this->hora < 0){
        this->msjError += "Formato de hora incorrecto.\n";
        todoBien = false;
    }

    if(this->dia == 0 || this->dia < 0){
        this->msjError += "Formato de día incorrecto.\n";
        todoBien = false;
    }

    if(dias_mes[mes - 1] >= this->dia){
        if(mes == 2 && this->dia == 29 && this->anio % 4 == 0){

        }else{
            this->msjError += "Excede los días del mes.\n";
            todoBien = false;
        }
    }
}
*/

class Cita{
public:
private:
    string nombre_1,
           nombre_2,
           lugarDeReunion;

};


class ClaseExterna{
public:
    Cita CreaCita();
private:

};

Cita ClaseExterna::CreaCita(){
    Cita nuevaCita()
}

int main()
{
    /*
    EJERCICIO 8.-
    Desarrolle una aplicación de Agenda de Citas y Compromisos que tiene las siguientes clases y funcionalidades:
        - Una clase "Cita" que tiene los siguientes miembros de clase:
            > Miembros para almacenar de manera individual los nombre de las dos personas que van a reunirse o citarse.
            > Un miembro de clase para almacenar el nombre del lugar donde van a reunirse.
            > Un miembro que es un objeto de una clase llamada "Fecha". Dicha clase "Fecha" cuenta con
                * miembros privados para el almacenamiento del año, el mes, el día y la hora, y
                * también un método para verificar que la fecha sea correcta, es decir, que no hayan más de 12 meses,
                * que la hora no sea superior a 24 horas ni inferior a 0 horas,
                * que el día no sea cero o menor a cero
                * y que respete el máximo de días de acuerdo con el mes,
                * y que verifique si el año es bisiesto para el caso del mes de febrero.
            > Esta clase tiene una sobrecarga adicional para ese método ya que
                * se debe permitir ingresar el mes en letras o en números.
        - Una clase externa "ClaseExterna" que permite
            > crear objetos de la clase "Cita" que tiene un método que permite crear una cita,
                * este método recibe como parámetros de entrada todos los datos para almacenar en los miembros del objeto cita.
                * Además este método debe ir agregando las citas que se van creando en una lista de citas (la lista puede guardar máximo 10 citas).
                * Dicha lista debe poder ser consultada a través de una función externa llamada "consultarCitas".
        - Agregue un pequeño menú de opciones que permita
            > crear citas e ir agregandolas a la lista de citas
            > y también visualizar las citas que ya se han agendado.
    */

    return 0;
}
