#include <iostream>

using namespace std;

class Socio{
public:
    Socio(string nombre, int antiguedad);
    string getNombre();
    int getAntiguedad();
private:
    string nombre;
    int antiguedad;
};

Socio::Socio(string nombre, int antiguedad){
    this->nombre = nombre;
    this->antiguedad = antiguedad;
}

string Socio::getNombre(){
    return this->nombre;
}

int Socio::getAntiguedad(){
    return this->antiguedad;
}

class Club{
public:
    Club();
    void ImprimeSocioMayorAnt();
    void ImprimeSocios();
private:
    Socio socio_1,
          socio_2,
          socio_3;
};

Club::Club() : socio_1("Saul", 2), socio_2("Mariano", 8), socio_3("Paola", 7){

}

void Club::ImprimeSocioMayorAnt(){
    string respuesta;
    if( this->socio_1.getAntiguedad() > this->socio_2.getAntiguedad() && this->socio_1.getAntiguedad() > this->socio_3.getAntiguedad()){
        cout << "El socio con mayor antiguedad es " << this->socio_1.getNombre() << " con una antiguedad de " << this->socio_1.getAntiguedad() << " años.";
    }else if(this->socio_2.getAntiguedad() > this->socio_3.getAntiguedad()){
        cout << "El socio con mayor antiguedad es " << this->socio_2.getNombre() << " con una antiguedad de " << this->socio_2.getAntiguedad() << " años.";
    }else{
        cout << "El socio con mayor antiguedad es " << this->socio_3.getNombre() << " con una antiguedad de " << this->socio_3.getAntiguedad() << " años.";
    }
}

void Club::ImprimeSocios(){
    cout << "Socio #1: " << socio_1.getNombre() << ", Antiguedad: " << socio_1.getAntiguedad() << endl;
    cout << "Socio #2: " << socio_2.getNombre() << ", Antiguedad: " << socio_2.getAntiguedad() << endl;
    cout << "Socio #3: " << socio_3.getNombre() << ", Antiguedad: " << socio_3.getAntiguedad() << endl;
    cout << endl;
}

int main()
{
    /*
    EJERCICIO 7.-
    Plantear una clase Club y otra clase Socio.
    La clase Socio debe tener los siguientes atributos
        - privados: nombre y la antigüedad en el club (en años).
        - En el constructor pedir la carga del nombre y su antigüedad.
    La clase Club debe tener como atributos
        - 3 objetos de la clase Socio.
        - Definir una responsabilidad para imprimir el nombre del socio con mayor antigüedad en el club.
    */
    setlocale(LC_ALL, "");

    Club club;

    club.ImprimeSocios();
    club.ImprimeSocioMayorAnt();

    cin.get();
    cin.get();

    return 0;
}
