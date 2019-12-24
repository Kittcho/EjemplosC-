#include <iostream>

using namespace std;

class Cuenta{
public:
    Cuenta(string,double);
    Cuenta(string);
    string getTitular();
    void setTitular(string);
    double getCantidad();
    void setCantidad(double);
    string toString();
    void Ingresar(double);
    void Retirar(double);
private:
    string titular;
    double cantidad;
    };

Cuenta::Cuenta(string titular, double cantidad){
    this->titular = titular;
    this->cantidad = cantidad;
}

Cuenta::Cuenta(string titular){
    this->titular = titular;
    this->cantidad = 0;
}

string Cuenta::getTitular(){
    return this->titular;
}

void Cuenta::setTitular(string titular){
    this->titular = titular;
}

double Cuenta::getCantidad(){
    return this->cantidad;
}

void Cuenta::setCantidad(double cantidad){
    this->cantidad = cantidad;
}

void Cuenta::Ingresar(double cantidad){
    if( cantidad > 0 ){
        this->cantidad+= cantidad;
        cout << "Se ingreso la cantidad de: $" << cantidad << endl;
    }
}

string Cuenta::toString(){
    cout << "Titular: " << getTitular() << endl;
    cout << "Saldo: $" << getCantidad() << endl;
}

void Cuenta::Retirar(double cantidad){
    if(this->cantidad >= cantidad){
        this->cantidad -= cantidad;
        cout << "Se a retirado la cantidad de: $" << cantidad << endl;
    }else{
        cout << "Se a retirado solo la cantidad de $" << this->cantidad << ", ya que es el saldo que tenia disponible." << endl;
        this->cantidad = 0;
    }
}

int main()
{
    /*
    EJERCICIO 3.-
    Crea una clase llamada Cuenta que tendrá los siguientes atributos: titular y cantidad (puede tener decimales).
    El titular será obligatorio y la cantidad es opcional.
    Crea dos constructores que cumpla lo anterior.
    Crea sus métodos get, set y toString.
    Tendrá dos métodos especiales:
    ingresar(double cantidad): se ingresa una cantidad a la cuenta, si la cantidad introducida es negativa, no se hará
    nada.
    retirar(double cantidad): se retira una cantidad a la cuenta, si restando la cantidad actual a la que nos pasan es
    negativa, la cantidad de la cuenta pasa a ser 0.
    */

    Cuenta cuenta1("Alberto",8000);

    cuenta1.toString();

    cout << endl;
    cuenta1.Ingresar(1000);
    cout << "Saldo: $" << cuenta1.getCantidad() << endl;

    cout << endl;
    cuenta1.Ingresar(-100000);
    cout << "Saldo: $" << cuenta1.getCantidad() << endl;

    cout << endl;
    cuenta1.Retirar(8500);
    cout << "Saldo: $" << cuenta1.getCantidad() << endl;

    cout << endl;
    cuenta1.Retirar(1000);
    cout << "Saldo: $" << cuenta1.getCantidad() << endl;

    cout << endl;
    cout << endl;

    Cuenta cuenta2("Eduardo");

    cuenta2.toString();

    cuenta2.setTitular("Eduardo Romero");

    cout << endl;
    cuenta2.toString();

    cout << endl;
    cuenta2.Ingresar(12345);
    cout << "Saldo: $" << cuenta2.getCantidad() << endl;

    cout << endl;
    cuenta2.Ingresar(-852);
    cout << "Saldo: $" << cuenta2.getCantidad() << endl;

    cout << endl;
    cuenta2.Retirar(12344);
    cout << "Saldo: $" << cuenta2.getCantidad() << endl;

    cout << endl;
    cuenta2.Retirar(800);
    cout << "Saldo: $" << cuenta2.getCantidad() << endl;

    return 0;
}
