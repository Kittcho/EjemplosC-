#include <iostream>

using namespace std;

class Fecha{
public:
    Fecha( int anio, int mes, int dia, int hora );
    Fecha( int anio, string mes, int dia, int hora );
    bool ValidaFechaInt();
    bool ValidaFechaStr();
    string getMensajeError();
    bool hayError;
    int getAnio();
    int getMes();
    string getSMes();
    int getDia();
    int getHora();
    string RegresaFechaCompleta();
private:
    int anio,
        mes,
        dia,
        hora;
    string sMes;
    string msjError;
};

Fecha::Fecha( int anio, int mes, int dia, int hora ){

    this->anio = anio;
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;

    this->hayError = !this->ValidaFechaInt();

    if( this->hayError ){
        this->anio = 0;
        this->mes = 0;
        this->dia = 0;
        this->hora = 0;
    }
}

Fecha::Fecha( int anio, string sMes, int dia, int hora ){

    this->anio = anio;
    this->sMes = sMes;
    this->dia = dia;
    this->hora = hora;

    this->hayError = !this->ValidaFechaStr();

    if( this->hayError ){
        this->anio = 0;
        this->sMes = "";
        this->dia = 0;
        this->hora = 0;
    }
}

string Fecha::getMensajeError(){
    return this->msjError;
}

int Fecha::getAnio(){
    return this->anio;
}

int Fecha::getMes(){
    return this->mes;
}

string Fecha::getSMes(){
    return this->sMes;
}

int Fecha::getDia(){
    return this->dia;
}

int Fecha::getHora(){
    return this->hora;
}

bool Fecha::ValidaFechaInt(){
    bool todoBien = true;
    this->msjError = "";
    int num_mes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(this->mes > 12 || this->mes < 1){
        this->msjError = "Formato de mes incorrecto.\n";
        todoBien = false;
    }

    if(this->hora > 24 || this->hora < 0){
        this->msjError += "Formato de hora incorrecto.\n";
        todoBien = false;
    }

    if(this->dia == 0 || this->dia < 0){
        this->msjError += "Formato de día incorrecto.\n";
        todoBien = false;
    }

    if(dias_mes[mes - 1] < this->dia){
        if(this->mes == 2 && this->dia == 29 && this->anio % 4 == 0){

        }else{
            this->msjError += "Excede los días del mes.\n";
            todoBien = false;
        }
    }
    return todoBien;
}

bool Fecha::ValidaFechaStr(){
    bool todoBien = true;
    this->msjError = "";
    int num_mes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    string nom_mes[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int conta = 0,
        numMes = 0;

    for(int i = 0; i < 12 ; i++){
        if( this->sMes == nom_mes[i] )
        {
            conta++;
            numMes = i;
            this->mes = conta;
            break;
        }
    }

    // validamos que exista el mes
    if( conta == 0 ){
        this->msjError = "El mes " + this->sMes + ", es incorrecto, favor de validar.\n";
        todoBien = false;
    }

    if(this->hora > 24 || this->hora < 0){
        this->msjError += "Formato de hora incorrecto.\n";
        todoBien = false;
    }

    if(this->dia == 0 || this->dia < 0){
        this->msjError += "Formato de día incorrecto.\n";
        todoBien = false;
    }

    if(dias_mes[ numMes ] < this->dia){
        if(this->sMes == "febrero" && this->dia == 29 && this->anio % 4 == 0){

        }else{
            this->msjError += "Excede los días del mes.\n";
            todoBien = false;
        }
    }
    return todoBien;
}

string Fecha::RegresaFechaCompleta(){
    return std::to_string( this->getAnio() ) + "-" + std::to_string( this->getMes() ) + "-" + std::to_string( this->getDia() ) + ", " + std::to_string( this->getHora() ) + " horas.";
}

class Cita{
public:
    void setNombre_1( string nombre_1 );
    string getNombre_1();
    void setNombre_2( string nombre_2 );
    string getNombre_2();
    void setLugarDeReunion( string lugarDeReunion );
    string getLugarDeReunion();
    void setFechaCita( Fecha* fecha );
    Fecha* getFechaCita();
private:
    string nombre_1,
           nombre_2,
           lugarDeReunion;
    Fecha* fecha_cita;

};

void Cita::setNombre_1( string nombre_1 ){
    this->nombre_1 = nombre_1;
}

string Cita::getNombre_1(){
    return this->nombre_1;
}

void Cita::setNombre_2( string nombre_2 ){
    this->nombre_2 = nombre_2;
}

string Cita::getNombre_2(){
    return this->nombre_2;
}

void Cita::setLugarDeReunion( string lugarDeReunion ){
    this->lugarDeReunion = lugarDeReunion;
}

string Cita::getLugarDeReunion(){
    return this->lugarDeReunion;
}

void Cita::setFechaCita( Fecha* fecha ){
    this->fecha_cita = fecha;
}

Fecha* Cita::getFechaCita(){
    return this->fecha_cita;
}

class ClaseExterna{
public:
    ClaseExterna();
    bool CrearCita( string nombre_1, string nombre_2, string lugarDeReunion, int anio, int mes, int dia, int hora );
    bool CrearCita( string nombre_1, string nombre_2, string lugarDeReunion, int anio, string sMes, int dia, int hora  );
    void ConsultarCitas();
private:
    Cita* citas;
    int indice;
};

ClaseExterna::ClaseExterna(){
    this->citas = new Cita[10];
    this->indice = 0;
}

bool ClaseExterna::CrearCita( string nombre_1, string nombre_2, string lugarDeReunion, int anio, int mes, int dia, int hora  ){
    bool resp = true;
    if( this->indice < 10 ){
        this->citas[ this->indice ].setNombre_1( nombre_1 );
        this->citas[ this->indice ].setNombre_2( nombre_2 );
        this->citas[ this->indice ].setLugarDeReunion( lugarDeReunion );
        this->citas[ this->indice ].setFechaCita( new Fecha( anio, mes, dia, hora ));

        if( this->citas[ this->indice ].getFechaCita()->hayError ){
            resp = false;
            this->citas[ this->indice ].setNombre_1( "" );
            this->citas[ this->indice ].setNombre_2( "" );
            this->citas[ this->indice ].setLugarDeReunion( "" );
            cout << "\nNo se registro la cita por error en la fecha" << endl;
        }else
        {
            cout << "\nSe registro correctamente la cita" << endl;
            this->indice++;
        }
    }else{
        cout << "\nNo se puede registrar la cita debio a que se alcanzo el maximo de citas a registrar." << endl;
        resp = false;
    }
    return resp;
}

bool ClaseExterna::CrearCita( string nombre_1, string nombre_2, string lugarDeReunion, int anio, string sMes, int dia, int hora  ){
    bool resp = true;
    if( this->indice < 10 ){
        this->citas[ this->indice ].setNombre_1( nombre_1 );
        this->citas[ this->indice ].setNombre_2( nombre_2 );
        this->citas[ this->indice ].setLugarDeReunion( lugarDeReunion );
        this->citas[ this->indice ].setFechaCita( new Fecha( anio, sMes, dia, hora ));

        if( this->citas[ this->indice ].getFechaCita()->hayError ){
            resp = false;
            this->citas[ this->indice ].setNombre_1( "" );
            this->citas[ this->indice ].setNombre_2( "" );
            this->citas[ this->indice ].setLugarDeReunion( "" );
            cout << "\nNo se registro la cita por error en la fecha" << endl;
        }else
        {
            cout << "\nSe registro correctamente la cita" << endl;
            this->indice++;
        }
    }else{
        cout << "\nNo se puede registrar la cita debio a que se alcanzo el maximo de citas a registrar." << endl;
        resp = false;
    }
    return resp;
}

void ClaseExterna::ConsultarCitas(){
    cout << endl;
    cout << "=====================================" << endl;
    cout << "= C I T A S   R E G I S T R A D A S =" << endl;
    cout << "=====================================" << endl;
    cout << endl;
    for(int i = 0; i < this->indice; i++){
        cout << "Cita #: " << i + 1 << endl;
        cout << "- Persona 01: " << this->citas[i].getNombre_1() << endl;
        cout << "- Persona 02: " << this->citas[i].getNombre_2() << endl;
        cout << "- Lugar de la reunión: " << this->citas[i].getLugarDeReunion() << endl;
        cout << "> Fecha: " << this->citas[i].getFechaCita()->RegresaFechaCompleta() << endl;
        cout << endl;
    }
}

int main()
{
    /*
    EJERCICIO 8.-
    Desarrolle una aplicación de Agenda de Citas y Compromisos que tiene las siguientes clases y funcionalidades:
        - Una clase "Cita" que tiene los siguientes miembros de clase:
            > Miembros para almacenar de manera individual los nombre de las dos personas que van a reunirse o citarse.
            > Un miembro de clase para almacenar el nombre del lugar donde van a reunirse.
            > Un miembro que es un objeto de una clase llamada "Fecha". Dicha clase "Fecha" cuenta con
                * miembros privados para el almacenamiento del año, el mes, el día y la hora, y
                * también un método para verificar que la fecha sea correcta, es decir, que no hayan más de 12 meses,
                * que la hora no sea superior a 24 horas ni inferior a 0 horas,
                * que el día no sea cero o menor a cero
                * y que respete el máximo de días de acuerdo con el mes,
                * y que verifique si el año es bisiesto para el caso del mes de febrero.
            > Esta clase tiene una sobrecarga adicional para ese método ya que
                * se debe permitir ingresar el mes en letras o en números.
        - Una clase externa "ClaseExterna" que permite
            > crear objetos de la clase "Cita" que tiene un método que permite crear una cita,
                * este método recibe como parámetros de entrada todos los datos para almacenar en los miembros del objeto cita.
                * Además este método debe ir agregando las citas que se van creando en una lista de citas (la lista puede guardar máximo 10 citas).
                * Dicha lista debe poder ser consultada a través de una función externa llamada "consultarCitas".
        - Agregue un pequeño menú de opciones que permita
            > crear citas e ir agregandolas a la lista de citas
            > y también visualizar las citas que ya se han agendado.
    */

    setlocale(LC_ALL, "");

    ClaseExterna ce;
    int opcion = 0,
        opcionMes = 0;
    string nom_persona1 = "",
           nom_persona2 = "",
           lugarCita = "",
           sMes = "";
    int anio = 0,
        mes = 0,
        dia = 0,
        hora = 0;
    bool opcionCorrecta = true;

    cout << "" << endl;

    cout << "===================================" << endl;
    cout << "======= M E N Ú   C I T A S =======" << endl;
    cout << "===================================" << endl;
    cout << endl;

    cout << "Opciones:" << endl;
    cout << "1 = Agregar cita." << endl;
    cout << "2 = Visualizar las citas agendadas." << endl;

    do{
        cout << endl;
        cout << "Favor de introducir la opción deseada: ";
        cin >> opcion;

        switch( opcion ){
            case 1:
                cout << "Favor de ingresa el nombre de la primera persona: ";
                cin >> nom_persona1;

                cout << "Favor de ingresa el nombre de la segunda persona: ";
                cin >> nom_persona2;

                cout << "Favor de ingresar el lugar de la cita: ";
                cin >> lugarCita;

                cout << "*** Datos de la fecha ***" << endl;

                cout << "> Favor de ingresar el año: ";
                cin >> anio;

                do
                {
                    cin.sync();
                    cout << "** El mes se puede introducir por número o letra (en minusculas)\nPara número pulse 1, para letra pulse 2: ";
                    cin >> opcionMes;

                    opcionCorrecta = true;

                    if( opcionMes == 1 ){
                        cout << "> Favor de ingresar el mes (Número): ";
                        cin >> mes;
                    }else if( opcionMes == 2 ){
                        cout << "> Favor de ingresar el mes (Letra): ";
                        cin >> sMes;
                    }else{
                        opcionCorrecta = false;
                        cout << "Opción incorrecta, favor de intentar de nuevo." << endl;
                    }
                }while(not opcionCorrecta);


                cout << "> Favor de ingresar el dia: ";
                cin >> dia;

                cout << "> Favor de ingresar el la hora (24 hrs): ";
                cin >> hora;

                if( opcionMes == 1 ){
                    ce.CrearCita( nom_persona1, nom_persona2, lugarCita, anio, mes, dia, hora );
                }else{
                    ce.CrearCita( nom_persona1, nom_persona2, lugarCita, anio, sMes, dia, hora );
                }

            break;
            case 2:
                ce.ConsultarCitas();
            break;
            default:
                cout << "Opción invalida, favor de verificar." << endl;
            break;
        }

    }while( true );


    /*ce.CrearCita("Alberto", "Denisse", "Forum", 2020, 2, 29, 14);
    ce.CrearCita("Mario", "Cruz Ernesto", "La Primavera", 2019, 12, 28, 12);
    ce.CrearCita("Yolanda", "Jesus Alberto", "Sala B-2", 2019, "diciembre", 31, 11);
    ce.ConsultarCitas();*/


    return 0;
}
