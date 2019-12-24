#include <iostream>

using namespace std;

class Cliente{
public:
    Cliente(string nombre, double monto);
    void Depositar(double monto);
    void Extraer(double monto);
    double RetornaMonto();
    string nombre;
    double monto;
};

Cliente::Cliente(string nombre, double monto){
    this->nombre = nombre;
    this->monto = monto;
}

void Cliente::Depositar(double monto){
    this->monto += monto;
    cout << "Se depositó la cantidad de $" << monto << endl;
}

void Cliente::Extraer(double monto){
    if(this->monto > monto){
        this->monto -= monto;
        cout << "Se retiró la cantidad de $" << monto << endl;
    }else{
        cout << "Se retiró solo la cantidad de $" << this->monto << " ya que no habia saldo suficiente." << endl;
        this->monto = 0;
    }
}

double Cliente::RetornaMonto(){
    return this->monto;
}

class Banco{
public:
    Banco();
    void Operar();
    double DepositosTotales();
private:
    Cliente cte1,
            cte2,
            cte3;
};

Banco::Banco() : cte1("Eduardo", 5000), cte2("Mauricio", 4500), cte3("Yareli", 8000){

}

double Banco::DepositosTotales(){
    return this->cte1.RetornaMonto() + this->cte2.RetornaMonto() + this->cte3.RetornaMonto();
}

void Banco::Operar(){

    cout << "<---------------- cliente 1 ---------------->\n";
    cout << "El saldo inicial del cliente 1 [" << this->cte1.nombre <<"] es de $" <<  this->cte1.RetornaMonto() << endl;
    this->cte1.Depositar(1000);
    this->cte1.Extraer(100);
    cout << "El saldo del cliente 1 [" << this->cte1.nombre <<"] es de $" <<  this->cte1.RetornaMonto() << endl;
    cout << endl;

    cout << "<---------------- cliente 2 ---------------->\n";
    cout << "El saldo inicial del cliente 2 [" << this->cte2.nombre <<"] es de $" <<  this->cte2.RetornaMonto() << endl;
    this->cte2.Depositar(800);
    this->cte2.Extraer(900);
    cout << "El saldo del cliente 2 [" << this->cte2.nombre <<"] es de $" <<  this->cte2.RetornaMonto() << endl;
    cout << endl;

    cout << "<---------------- cliente 3 ---------------->\n";
    cout << "El saldo inicial del cliente 3 [" << this->cte3.nombre <<"] es de $" <<  this->cte3.RetornaMonto() << endl;
    this->cte3.Depositar(700);
    this->cte3.Extraer(10000);
    cout << "El saldo del cliente 3 [" << this->cte3.nombre <<"] es de $" <<  this->cte3.RetornaMonto() << endl;
    cout << endl;

    cout << "<----------------- Banco ----------------->\n";
    cout << "Monto total  del banco es de $" << this->DepositosTotales() << endl;
}

int main()
{
    /*
    EJERCICIO 6.-
    Un banco tiene 3 clientes que pueden hacer depósitos y extracciones.
    También el banco requiere que al final del día calcule la cantidad de dinero que hay depositada.
    La Solución tendrá el siguiente esquema:
    - Debemos definir los atributos y los métodos de cada clase:
        > La clase Cliente contiene los atributos(nombre, monto),
          métodos(constructor, Depositar, Extraer, RetornarMonto).
        > La clase Banco contiene los atributos 3 Cliente (3 objetos de la clase Cliente),
          métodos(constructor, Operar, DepositosTotales)

    */
    setlocale(LC_ALL, "");

    Banco banco;
    banco.Operar();

    cin.get();
    cin.get();

    return 0;
}
