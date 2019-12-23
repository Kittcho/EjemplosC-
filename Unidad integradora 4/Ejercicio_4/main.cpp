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
    Un vagón de un tren tiene 40 asientos, cada uno de ellos puede estar ocupado o vacante.
    El vagón puede ser de primera o segunda clase.
    Cree una clase Carro para representar esta información.
    En el constructor se supondrá que todos los asientos inicialmente están vacantes.
    Escriba los métodos apropiados de acceso y actualización y un método que vaya ocupando los asientos de
    la siguiente forma:
        - si el vagón es de primera hay un 10% de probabilidad que los asientos sean ocupados;
        - si es de segunda clase hay un 40% de probabilidad que los asientos sean ocupados.
    Escriba una función main() que contenga un objeto Carro, llénelo aleatoriamente e imprima el estado de
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
