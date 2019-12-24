#include <iostream>
#include <stdio.h>

using namespace std;

class Tiempo{
public:
    Tiempo(int,int,int);
    Tiempo(int);
    void MuestraHora();
private:
    int horas;
    int minutos;
    int segundos;
};

Tiempo::Tiempo(int horas, int minutos, int segundos){
    this->horas = horas;
    this->minutos = minutos;
    this->segundos = segundos;
}

Tiempo::Tiempo(int segundos){
    this->minutos = 0;
    this->horas = 0;
    this->segundos = 0;

    while(segundos > 0){
        if(segundos >= 60){
            this->minutos++;
            segundos = segundos - 60;
        }else{
            this->segundos = segundos;
            segundos = 0;
        }
    }

    while(this->minutos >= 60){
        this->horas++;
        this->minutos = this->minutos - 60;
    }
}

void Tiempo::MuestraHora(){
    printf("%0.2d:%0.2d:%0.2d\n", this->horas, this->minutos, this->segundos);
}

int main()
{
    /*
    EJERCICIO 1.-
    Construya una clase Tiempo que contenga los siguientes atributos enteros: horas, minutos y
    segundos. Haga que la clase contenga 2 constructores, el primero debe tener 3 parámetros
    Tiempo(int,int,int) y el segundo sólo tendrá un campo que serán los segundos y desensamble el
    número entero largo en horas, minutos y segundos
    */

    Tiempo t(12,5,6);
    Tiempo t2(50489);

    t.MuestraHora();
    t2.MuestraHora();

    cin.get();
    cin.get();

    return 0;
}
