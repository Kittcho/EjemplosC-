#include <iostream>

using namespace std;

#define PROBABILIDAD_PRIMERA 0.10
#define PROBABILIDAD_SEGUNDA 0.40

class Vagon{
public:
    Vagon();
    string getTipoVagon();
    void setTipoVagon( string tipoVagon );
private:
    int asientos[40];
    string tipoVagon;
};

Vagon::Vagon(){
    for(int i = 0; i < 40; i++){
        this->asientos[i] = 0;
    }
}

string Vagon::getTipoVagon(){
    return this->tipoVagon;
}

void Vagon::setTipoVagon( string tipoVagon ){
    this->tipoVagon = tipoVagon;
}


class Carro{
public:
    Carro( int numeroVagones );
    void AgregarVagon();
    Vagon* getVagones();
    int getNumeroVagones();
    void AsignarValoresVagon( int vagon, string tipoVagon );
    void LlenarAsientos();
private:
    Vagon* vagones;
    int numeroVagones;
};

Carro::Carro( int numeroVagones ){
    this->vagones = new Vagon[ numeroVagones ];
}

Vagon* Carro::getVagones(){
    return this->vagones;
}

int Carro::getNumeroVagones(){
    return this->numeroVagones;
}

void Carro::AsignarValoresVagon( int vagon, string tipoVagon ){
    this->vagones[ vagon - 1 ].setTipoVagon( tipoVagon );
}

void Carro::LlenarAsientos(){
    for(int i=0; i < this->numeroVagones; i++){
        if(this->vagones[i].getTipoVagon() == "Primera"){

        }

    }
}

/*
int* a = NULL;   // Pointer to int, initialize to nothing.
int n;           // Size needed for array
cin >> n;        // Read in the size
a = new int[n];  // Allocate n ints and save ptr in a.
for (int i=0; i<n; i++) {
    a[i] = 0;    // Initialize all elements to zero.
}
. . .  // Use a as a normal array
delete [] a;  // When done, free memory pointed to by a.
a = NULL;     // Clear a to prevent using invalid memory reference.

*/


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

    Vagon vagon1;
    Vagon vagon2;
    Vagon vagon3;

    Carro tren(2);

    tren.AsignarValoresVagon( 1, "Primera");
    tren.AsignarValoresVagon( 2, "Segunda");



    for(int i=0; i < tren.getNumeroVagones(); i++){
        cout << tren.getVagones()[i].getTipoVagon() << endl;

    }


    return 0;
}
