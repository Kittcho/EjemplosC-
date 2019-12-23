#include <iostream>

using namespace std;

class Vagon{
public:
    Vagon(int);
private:
    int tipoClase;
    string asientos[40];
};

Vagon::Vagon(int tipoClase){
    for(int i = 0; i < sizeof(this->asientos); i++){
        asientos[i] = "vacante";
    }
    this->tipoClase = tipoClase;
}

class Carro{
public:
    Carro();
    void AgregarVagon(Vagon &);
    Vagon* getVagones();
private:
    Vagon vagones[];
    Vagon *p_vagon;
};

Carro::Carro(){
    this->p_vagon = this->vagones;
}

void Carro::AgregarVagon(Vagon &vagon){
    this->p_vagon = &vagon;
    this->p_vagon++;
}

Vagon* Carro::getVagones(){
    return this->vagones;
}

int main()
{
    /*
    EJERCICIO 4.-
    Un vag�n de un tren tiene 40 asientos, cada uno de ellos puede estar ocupado o vacante.
    El vag�n puede ser de primera o segunda clase.
    Cree una clase Carro para representar esta informaci�n.
    En el constructor se supondr� que todos los asientos inicialmente est�n vacantes.
    Escriba los m�todos apropiados de acceso y actualizaci�n y un m�todo que vaya ocupando los asientos de
    la siguiente forma:
        - si el vag�n es de primera hay un 10% de probabilidad que los asientos sean ocupados;
        - si es de segunda clase hay un 40% de probabilidad que los asientos sean ocupados.
    Escriba una funci�n main() que contenga un objeto Carro, ll�nelo aleatoriamente e imprima el estado de
    cada asiento.
    */

    Vagon vagon1(1);
    Carro carro();

    carro.AgregarVagon(&vagon1);

    Vagon vagones[] = carro.getVagones();

    for(int i = 0; i < sizeof(vagones)){

    }


    return 0;
}
