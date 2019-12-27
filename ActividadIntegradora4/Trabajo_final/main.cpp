#include <iostream>

using namespace std;

#define DESCUENTO_LIQUIDAR 0.15;

class Cliente{
public:
    void InicializaDatos(int num_cliente, string nom_cliente, double cant_deuda);
    int getNumCliente();
    string getNomCliente();
    double getDeuda();
    void setDeuda( double abono );
private:
    int num_cliente;
    string nom_cliente;
    double cant_deuda;

};

void Cliente::InicializaDatos(int num_cliente, string nom_cliente, double cant_deuda){
    this->num_cliente = num_cliente;
    this->nom_cliente = nom_cliente;
    this->cant_deuda = cant_deuda;
}

int Cliente::getNumCliente(){
    return this->num_cliente;
}

 string Cliente::getNomCliente(){
     return this->nom_cliente;
 }

double Cliente::getDeuda(){
    return this->cant_deuda;
}

void Cliente::setDeuda( double abono ){
    this->cant_deuda -= abono;
}

class BaseDatos{
public:
    BaseDatos();
    Cliente* getClientes();
private:
    Cliente clientes[10];
};

BaseDatos::BaseDatos(){
    this->clientes[0].InicializaDatos(1, "Eduardo", 5000);
    this->clientes[1].InicializaDatos(2, "Raul", 400);
    this->clientes[2].InicializaDatos(3, "Alberto", 10000);
    this->clientes[3].InicializaDatos(4, "Maria", 750);
    this->clientes[4].InicializaDatos(5, "Emma", 8520);
    this->clientes[5].InicializaDatos(6, "Yareli", 1254);
    this->clientes[6].InicializaDatos(7, "Karen", 25896);
    this->clientes[7].InicializaDatos(8, "Juan", 8521);
    this->clientes[8].InicializaDatos(9, "Manuel", 3164);
    this->clientes[9].InicializaDatos(10, "Pedro", 7531);
}

Cliente* BaseDatos::getClientes(){
    return this->clientes;
}

class Caja{
public:
    Caja();
    string ConsultaNombre( int num_cliente );
    double ConsultarSaldo( int num_cliente );
    Cliente RegresaCliente( int num_cliente );
    void IngresarAbono( int num_cliente, double abono );
private:
    BaseDatos* bd;
};

Caja::Caja(){
    this->bd = new BaseDatos();
}

string Caja::ConsultaNombre( int num_cliente ){
    Cliente* clientes = this->bd->getClientes();
    for(int i = 0; i < 10; i++){
        if( num_cliente == clientes[i].getNumCliente() )
        {
            return clientes[i].getNomCliente();
        }
    }
    return "No existe el número de cliente " + num_cliente;
}

double Caja::ConsultarSaldo( int num_cliente ){
    Cliente* clientes = this->bd->getClientes();
    for(int i = 0; i < 10; i++){
        if( num_cliente == clientes[i].getNumCliente() )
        {
            return clientes[i].getDeuda();
        }
    }
    return -1;
}

Cliente Caja::RegresaCliente( int num_cliente ){
    Cliente* clientes = this->bd->getClientes();
    Cliente cte;
    for(int i = 0; i < 10; i++){
        if( num_cliente == clientes[i].getNumCliente() )
        {
            return clientes[i];
        }
    }
    return cte;
}

void Caja::IngresarAbono( int num_cliente, double abono ){
    Cliente* clientes = this->bd->getClientes();
    double saldo = this->ConsultarSaldo( num_cliente );
    double cambio = 0;

    if(saldo != -1){
        if( saldo >= abono )
        {
            for(int i = 0; i < 10; i++){
                if( num_cliente == clientes[i].getNumCliente() ){
                    clientes[i].setDeuda( abono );
                    break;
                }
            }
        }else if( saldo < abono ){

        }
    }
}

int main()
{
    /*
    Realizar una funcionalidad que reduzca el tiempo de atención en cajas de abonos en cualquiera
    de las operaciones que se realizan en esta, aplicando los conocimientos adquiridos en esta
    materia en base a codificar en C++ la funcionalidad en cuestión.

    Deberás entregar el código fuente y los objetos binarios resultantes de la compilación de un
    programa que cumpla con los siguientes requisitos técnicos que resuelven la funcionalidad
    elegida:

    * Es imperativa la utilización de apuntadores y la asignación de memoria de manera dinámica, así
    como su respectiva liberación.
    * Deberás implementar el uso de funciones que utilicen parámetros de entrada por valor y
    referencia.
    * Debes considerar el manejo de excepciones en todo momento.
    * Contener mínimamente 2 Clases declaradas e implementadas, que a su vez deberán hacer uso
    de variables y constantes con las cuales se realicen operaciones aritméticas.
    * Deben implementarse casteos de conversión explícita entre variables con distintos tipos de
    datos que sean compatibles entre sí.
    * Es necesario que en tus operaciones hagas uso de los distintos tipos de estructuras de control,
    tanto selectiva como repetitiva, y en esta última debes considerar los arreglos de dimensión
    múltiple.
    * El resultado de las operaciones aritméticas, así como los mensajes de salida y las excepciones
    deberán quedar registradas en un archivo log que deberá ser guardado de manera local en la
    máquina donde sea ejecutado el programa.

    */

    Caja caja01;
    int num_cliente = 0;

    Cliente cte = caja01.RegresaCliente( 6 );

    cte.setDeuda( 1000 );

    cout << "Favor de ingresar el número de cliente a buscar: ";
    cin >> num_cliente;

    cout << "Cliente: " << caja01.ConsultaNombre( num_cliente ) << endl;
    cout << "Su saldo deudor es de: $" << caja01.ConsultarSaldo( num_cliente ) << endl;

    return 0;
}
