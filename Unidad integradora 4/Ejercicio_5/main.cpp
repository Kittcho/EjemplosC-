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
    double total;
    const double PLUS = 300;
};

Empleado::Empleado(string nombre, int edad, double salario){
    this->nombre = nombre;
    this->edad = edad;
    this->salario = salario;
}

string Empleado::getNombre(){
    return this->nombre;
}

void Empleado::setNombre(string nombre){
    this->nombre = nombre;
}

int Empleado::getEdad(){
    return this->edad;
}

void Empleado::setEdad(int edad){
    this->edad = edad;
}

 double Empleado::getSalario(){
    return this->salario;
 }

 void Empleado::setSalario(double salario){
    this->salario = salario;
 }

void Empleado::Plus(){
    cout << "Plus del empleado";
}

class Repartidor : public Empleado{
public:
    Repartidor(string, int, double, string);
    string getZona();
    void setZona(string);
    void Plus();
private:
    string zona;
};

string Repartidor::getZona(){
    return this->zona;
}

void Repartidor::setZona(string zona){
    this->zona = zona;
}

Repartidor::Repartidor(string nombre, int edad, double salario, string zona) : Empleado(nombre, edad, salario){
    this->zona = zona;
}

void Repartidor::Plus(){
    if(this->edad < 25 && this->zona == "zona 3"){
        this->total = this->salario + this->PLUS;
    }
}

class Comercial : Empleado{
public:
    Comercial(string, int, double, double);
    double getComision();
    void setComision(double);
    void Plus();
private:
    double comision;
};

Comercial::Comercial(string nombre, int edad, double salario, double zona) : Empleado(nombre, edad, salario){
    this->comision = comision;
}

void Comercial::Plus(){
    if(this->edad > 30 && this->comision == 200){
        this->total = this->salario + this->PLUS;
    }
}


int main()
{
    /*
    Nos piden hacer una un programa que gestione empleados.
    Los empleados se definen por tener:
    - Nombre
    - Edad
    - Salario
    Tambi�n tendremos una constante llamada PLUS, que tendr� un valor de 300 pesos.
    Tenemos dos tipos de empleados:
     - repartidor y
     - comercial.
    El comercial, aparte de los atributos anteriores, tiene uno m�s llamado comisi�n (double).
    El repartidor, aparte de los atributos de empleado, tiene otro llamado zona (String).
    Crea sus constructores, getters and setters y toString (piensa como aprovechar la herencia).
    No se podr�n crear objetos del tipo Empleado (la clase padre) pero si de sus hijas.
    Las clases tendr�n un m�todo llamado plus, que seg�n en cada clase tendr� una implementaci�n distinta.
    Este plus b�sicamente aumenta el salario del empleado.
    En comercial, si tiene m�s de 30 a�os y cobra una comisi�n de m�s de 200 pesos, se le aplicar� el plus.

    En repartidor, si tiene menos de 25 y reparte en la �zona 3�, este recibir� el plus.
    Puedes hacer que devuelva un booleano o que no devuelva nada, lo dejo a tu elecci�n.
    Crea una clase ejecutable donde crees distintos empleados y le apliques el plus para comprobar que funciona.
    */

    Repartidor repartidor1("Alberto", 32, 1000, "zona 1");
    Repartidor repartidor2("Jose", 25, 900, "zona 3");

    cout << "Nombre repartidor #1:" << repartidor1.getNombre() << endl;
    cout << "Edad repartidor #1:" << repartidor1.getEdad() << endl;
    cout << "Salario repartidor #1:" << repartidor1.getSalario() << endl;
    cout << "Zona repartidor #1:" << repartidor1.getZona() << endl;
    cout << "Nombre repartidor #2:" << repartidor2.getNombre() << endl;
    cout << "Edad repartidor #2:" << repartidor2.getEdad() << endl;
    cout << "Salario repartidor #2:" << repartidor2.getSalario() << endl;
    cout << "Zona repartidor #2:" << repartidor2.getZona() << endl;


    return 0;
}
