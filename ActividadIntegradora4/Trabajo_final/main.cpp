#include <iostream>
#include <string>
#include <fstream>


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
    BaseDatos( int num_clientes );
    ~BaseDatos();
    Cliente* getClientes();
private:
    Cliente* clientes;
    ofstream escribir;
    void RegistraLog( string registro );
};

BaseDatos::BaseDatos( int num_clientes ){
    try{
        this->clientes = new Cliente[ num_clientes ];
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
    }catch(std::exception& e){
        string msj = "Ocurrio un error al intentar crear la base de datos de clientes.\nDetalles: " + (string)e.what() + "\n";
        cout << msj << endl;
        this->RegistraLog( msj );

    }
}

BaseDatos::~BaseDatos(){
    delete[] this->clientes;
}

Cliente* BaseDatos::getClientes(){
    return this->clientes;
}

void BaseDatos::RegistraLog(string registro){
    try{
        this->escribir.open("log_sistema_cajas.txt", std::ofstream::out | std::ofstream::app);
        escribir << registro << endl;
        escribir.close();
    }catch( std::exception& e ){
        cout << "Ocurrio un error al intentar escribir en el archivo log del sistema.\nDetalles: " << e.what() << endl;
    }
}

class Caja{
public:
    Caja();
    ~Caja();
    void SistemaPrincipal();
private:
    ofstream escribir;
    BaseDatos* bd;
    bool ExisteCliente( int num_cliente );
    string ConsultaNombre( int num_cliente );
    double ConsultarSaldo( int num_cliente );
    Cliente RegresaCliente( int num_cliente );
    double IngresarAbono( int num_cliente, double abono, double *descuento );
    void RegistraLog( string registro );
};

Caja::Caja(){
    this->bd = new BaseDatos( 10 );
}

Caja::~Caja(){
    delete[] this->bd;
}

 bool Caja::ExisteCliente( int num_cliente ){
    try{
        Cliente* clientes = this->bd->getClientes();
        for(int i = 0; i < 10; i++){
            if( num_cliente == clientes[i].getNumCliente() )
            {
                return true;
            }
        }
        return false;
    }catch(std::exception& e){
        string msj = "Ocurrio un error al intentar consultar si existe el cliente.\nDetalles: " + (string)e.what() + "\n";
        cout << msj << endl;
        this->RegistraLog( msj );
    }
 }

string Caja::ConsultaNombre( int num_cliente ){
    try{
        Cliente* clientes = this->bd->getClientes();
        for(int i = 0; i < 10; i++){
            if( num_cliente == clientes[i].getNumCliente() )
            {
                return clientes[i].getNomCliente();
            }
        }
        string resp = "No existe el número de cliente " + std::to_string(num_cliente);
        return resp;
    }catch(std::exception& e){
        string msj = "Ocurrio un error al intentar consultar el nombre del cliente.\nDetalles: " + (string)e.what() + "\n";
        cout << msj << endl;
        this->RegistraLog( msj );
    }
}

double Caja::ConsultarSaldo( int num_cliente ){
    try{
        Cliente* clientes = this->bd->getClientes();
        for(int i = 0; i < 10; i++){
            if( num_cliente == clientes[i].getNumCliente() )
            {
                return clientes[i].getDeuda();
            }
        }
        return -1;
    }catch(std::exception& e){
        string msj = "Ocurrio un error al intentar consultar el saldo.\nDetalles: " + (string)e.what() + "\n";
        cout << msj << endl;
        this->RegistraLog( msj );
    }
}

Cliente Caja::RegresaCliente( int num_cliente ){
    try{
        Cliente* clientes = this->bd->getClientes();
        Cliente cte;
        for(int i = 0; i < 10; i++){
            if( num_cliente == clientes[i].getNumCliente() )
            {
                return clientes[i];
            }
        }
        return cte;
    }catch(std::exception& e){
        string msj = "Ocurrio un error al intentar obtener el cliente.\nDetalles: " + (string)e.what() + "\n";
        cout << msj << endl;
        this->RegistraLog( msj );
    }
}

double Caja::IngresarAbono( int num_cliente, double abono, double *descuento ){
    try{
    Cliente* clientes = this->bd->getClientes();
    double saldo = this->ConsultarSaldo( num_cliente );
    double cambio = 0,
           des = 0;
    *descuento = des;

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
            for(int i = 0; i < 10; i++){
                if( num_cliente == clientes[i].getNumCliente() ){
                    *descuento = saldo * DESCUENTO_LIQUIDAR;
                    cambio = abono - ( saldo - *descuento);
                    clientes[i].setDeuda( saldo );
                    break;
                }
            }
        }
    }
    return cambio;
    }catch(std::exception& e){
        string msj = "Ocurrio un error al intentar ingresar el abono.\nDetalles: " + (string)e.what() + "\n";
        cout << msj << endl;
        this->RegistraLog( msj );
    }
}

void Caja::RegistraLog(string registro){
    try{
        this->escribir.open("log_sistema_cajas.txt", std::ofstream::out | std::ofstream::app);
        escribir << registro << endl;
        escribir.close();
    }catch( std::exception& e ){
        cout << "Ocurrio un error al intentar escribir en el archivo log del sistema.\nDetalles: " << e.what() << endl;
    }
}

void Caja::SistemaPrincipal(){

    string log = "==============================\n========  M  E  N  Ú  ========\n==============================\n";
    log += "Opciones:\n1 = Consultar saldo de cliente.\n2 = Realizar abono.\n9 = Salir.\n";

    cout << "==============================" << endl;
    cout << "========  M  E  N  Ú  ========" << endl;
    cout << "==============================" << endl;

    cout << "Opciones:" << endl;
    cout << "1 = Consultar saldo de cliente." << endl;
    cout << "2 = Realizar abono." << endl;
    cout << "9 = Salir." << endl;
    cout << endl;

    int respuesta = 0;
    do
    {
        cout << "Favor de ingresar la opción deseada: ";
        cin >> respuesta;

        log += "Favor de ingresar la opción deseada: " + std::to_string(respuesta) + "\n";

        if(respuesta != 9){
            string nom_cliente = "";
            int num_cliente = 0;
            double saldo = 0,
                   abono = 0,
                   descuento = 0,
                   cambio = 0;
            cout << endl;

            switch(respuesta){
                case 1:
                    log += "\n<===============  C O N S U L T A   D E   S A L D O ===============>\n";
                    cout << "\n<===============  C O N S U L T A   D E   S A L D O ===============>" << endl;

                    cout << "Favor de ingresar el número de cliente a buscar: ";
                    cin >> num_cliente;
                    cout << endl;

                    log += "Favor de ingresar el número de cliente a buscar: " + std::to_string(num_cliente) + "\n";

                    nom_cliente = this->ConsultaNombre( num_cliente );
                    cout << "Cliente: " << nom_cliente << endl;
                    saldo =  this->ConsultarSaldo( num_cliente );
                    cout << "Su saldo deudor es de: $" << saldo << endl;

                    log += "Cliente: " + nom_cliente + "\nSu saldo deudor es de: $" + std::to_string(saldo) + "\n";
                break;
                case 2:
                    log += "\n<===============  R E A L I Z A R   A B O N O ===============>\n";

                    cout << "\n<===============  R E A L I Z A R   A B O N O ===============>" << endl;
                    cout << endl;

                    cout << "Favor de ingresar el número de cliente a buscar: ";
                    cin >> num_cliente;

                    log += "Favor de ingresar el número de cliente a buscar: " + std::to_string(num_cliente) + "\n";

                    if(!ExisteCliente( num_cliente )){
                        cout << "\nEl cliente " << num_cliente << " no existe, favor de verificar." << endl;
                        log += "\nEl cliente " + std::to_string(num_cliente) + " no existe, favor de verificar.\n";
                        break;
                    }

                    cout << "Favor de ingresar su abono: $";
                    cin >> abono;

                    log += "Favor de ingresar su abono: $" + std::to_string(abono) + "\n";

                    cambio = this->IngresarAbono(num_cliente, abono, &descuento);

                    log += "\n======= Recibo de pago =======\nNúmero de cliente: " + std::to_string(num_cliente) + "\n";
                    log += "Nombre del cliente: " + this->ConsultaNombre( num_cliente ) + "\n";
                    log += "Saldo pendiente anterior: $" + std::to_string(saldo) + "\n";
                    log += "(-) abonos: $" + std::to_string(abono) + "\n";

                    cout << "\n======= Recibo de pago =======\n";
                    cout << "Número de cliente: " << num_cliente << endl;
                    cout << "Nombre del cliente: " << this->ConsultaNombre( num_cliente ) << endl;
                    cout << "Saldo pendiente anterior: $" << saldo << endl;
                    cout << "(-) abonos: $" << abono << endl;
                    if(descuento > 0){
                        cout << "(-) Descuento: $" << descuento << endl;
                        log += "(-) Descuento: $" + std::to_string(descuento) + "\n";
                    }
                    cout << "Saldo pendiente actual: $" << this->ConsultarSaldo( num_cliente ) << endl;
                    cout << "Cambio: $" << cambio << endl;

                    log += "Saldo pendiente actual: $" + std::to_string(this->ConsultarSaldo( num_cliente )) + "\n";
                    log += "Cambio: $" + std::to_string(cambio) + "\n";
                break;
                default:
                    cout << "Opción invalida, favor de revisar." << endl;
                    log += "Opción invalida, favor de revisar.\n";
                    break;

            }
            this->RegistraLog( log );
            log = "";
            cout << endl;
        }
    }while(respuesta != 9);

    cout << endl;
    cout << "Has salido del sistema.";
    this->RegistraLog( "Has salido del sistema.\n" );
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

    setlocale(LC_ALL, "");

    Caja caja01;
    caja01.SistemaPrincipal();

    return 0;
}
