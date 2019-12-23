#include <iostream>

using namespace std;

class Empleado{
public:
    Empleado(string, int, double);
    string getNombre();
    void setNombre(string);
    int getEdad();
    void setEdad(int);
    double getSalario();
    void setSalario(double);
    virtual void Plus();
protected:
    string nombre;
    int edad;
    double salario;
    const double PLUS = 300;
};

Empleado::Empleado(string nombre, int edad, double salario){
    this->nombre = nombre;
    this->edad = edad;
    this->salario = salario;
}

class Repartidor : Empleado{
public:
    Repartidor(string, int, double, string);
    string getZona();
    void setZona(string);
private:
    string zona;
};

Repartidor::Repartidor(string nombre, int edad, double salario, string zona) : Empleado(nombre, edad, salario){
    this->zona = zona;
}

void Repartidor::plus(){
    if(this->edad < 25 && this->zona == "zona 3")
}

class Comercial : Empleado{
public:
    Comercial(string, int, double, double);
    double getComision();
    void setComision(double);
private:
    double comision;
};

Comercial::Comercial(string nombre, int edad, double salario, double zona) : Empleado(nombre, edad, salario){
    this->comision = comision;
}

void Comercial::plus(){
    if(this->edad > 30 && this->comision == 200)
}


int main()
{
    /*
    Nos piden hacer una un programa que gestione empleados.
    Los empleados se definen por tener:
    - Nombre
    - Edad
    - Salario
    También tendremos una constante llamada PLUS, que tendrá un valor de 300 pesos.
    Tenemos dos tipos de empleados:
     - repartidor y
     - comercial.
    El comercial, aparte de los atributos anteriores, tiene uno más llamado comisión (double).
    El repartidor, aparte de los atributos de empleado, tiene otro llamado zona (String).
    Crea sus constructores, getters and setters y toString (piensa como aprovechar la herencia).
    No se podrán crear objetos del tipo Empleado (la clase padre) pero si de sus hijas.
    Las clases tendrán un método llamado plus, que según en cada clase tendrá una implementación distinta.
    Este plus básicamente aumenta el salario del empleado.
    En comercial, si tiene más de 30 años y cobra una comisión de más de 200 pesos, se le aplicará el plus.

    En repartidor, si tiene menos de 25 y reparte en la “zona 3”, este recibirá el plus.
    Puedes hacer que devuelva un booleano o que no devuelva nada, lo dejo a tu elección.
    Crea una clase ejecutable donde crees distintos empleados y le apliques el plus para comprobar que funciona.
    */




    return 0;
}
