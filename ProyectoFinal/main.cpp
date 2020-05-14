#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <locale.h>

using namespace std;

class Domicilio {
public:
    string nom_colonia;
    string nom_calle;
    int num_exterior;
    int num_interior;
    string des_entrecalles;
    string des_observaciones; /*Indicaciones que ayudan a localizar el domicilio*/
    string num_celular;
    string num_telefono;
};

class Trabajo {
public:
    string nom_trabajo;
    string nom_puesto;
    Domicilio des_domicilio;
    double num_sueldo;
    int anio_ingreso;
};

class Persona {
public:
    string nom_persona;
    string ape_paterno;
    string ape_materno;
    string des_curp;
    int edad;
    int anio_nacimiento;
    int mes_nacimiento;
    int dia_nacimiento;
    Domicilio des_domicilio;
};

class Solicitud {
public:
    Solicitud(int);
    virtual void ObtieneDatos();
    virtual void ImprimeDatos();

protected:
    int fol_solicitud;
    Persona des_cliente;
};

Solicitud::Solicitud(int fol_solicitud) {
    this->fol_solicitud = fol_solicitud;
}

void Solicitud::ImprimeDatos(){
    cout << fol_solicitud << endl;
}

void Solicitud::ObtieneDatos(){
    cout << "" << endl;
}

//////////////////////////////////////////////////////////////////////////////////////

class SolicitudCoppel: public Solicitud {
public:
    SolicitudCoppel(int);
    void ObtieneDatos();
    void ImprimeDatos();
private:
    Trabajo des_trabajo;
    Persona des_referencia;
};

SolicitudCoppel::SolicitudCoppel(int fol_solicitud_coppel) : Solicitud(fol_solicitud_coppel){

}

void SolicitudCoppel::ObtieneDatos(){
    cout << "=================================================" << endl;
    cout << "======== S O L I C I T U D  C O P P E L =========" << endl;
    cout << "=================================================" << endl;
    cout << endl;

    //Datos personales
    cout << "Ingrese el nombre(s) del solicitante: ";
    cin >> this->des_cliente.nom_persona;
    cin.sync();

    cout << "Ingrese el apellido paterno del solicitante: ";
    cin >> this->des_cliente.ape_paterno;
    cin.sync();

    cout << "Ingrese el apellido materno del solicitante: ";
    cin >> this->des_cliente.ape_materno;
    cin.sync();

    cout << "Edad (número de años): ";
    cin >> this->des_cliente.edad;
    cin.sync();

    cout << "Año de nacimiento (número a cuatro dígitos): ";
    cin >> this->des_cliente.anio_nacimiento;
    cin.sync();

    cout << "Mes de nacimiento (número a dos dígitos): ";
    cin >> this->des_cliente.mes_nacimiento;
    cin.sync();

    cout << "Día de nacimiento (número a dos dígitos): ";
    cin >> this->des_cliente.dia_nacimiento;
    cin.sync();

    cout << "Favor de ingresar su CURP: ";
    cin >> this->des_cliente.des_curp;
    cin.sync();

    // Datos del domicilio
    cout << endl;
    cout << "====== D O M I L I C I L I O ======" << endl;
    cout << "Colonia: ";
    cin >> this->des_cliente.des_domicilio.nom_colonia;
    cin.sync();

    cout << "Calle: ";
    cin >> this->des_cliente.des_domicilio.nom_calle;
    cin.sync();

    cout << "Número interior: ";
    cin >> this->des_cliente.des_domicilio.num_interior;
    cin.sync();

    cout << "Número Exterior: ";
    cin >> this->des_cliente.des_domicilio.num_exterior;
    cin.sync();

    cout << "Entre calles: ";
    cin >> this->des_cliente.des_domicilio.des_entrecalles;
    cin.sync();

    cout << "Observaciones que ayuden a localizar el domicilio: ";
    cin >> this->des_cliente.des_domicilio.des_observaciones;
    cin.sync();

    cout << "Teléfono de casa: ";
    cin >> this->des_cliente.des_domicilio.num_telefono;
    cin.sync();

    cout << "Celular: ";
    cin >> this->des_cliente.des_domicilio.num_celular;
    cin.sync();

    //Datos del trabajo
    cout << endl;
    cout << "====== T R A B A J O ======" << endl;
    cout << "Nombre del trabajo: ";
    cin >> this->des_trabajo.nom_trabajo;
    cin.sync();

    cout << "Puesto que desempeña / ocupación: ";
    cin >> this->des_trabajo.nom_puesto;
    cin.sync();

    cout << "Colonia: ";
    cin >> this->des_trabajo.des_domicilio.nom_colonia;
    cin.sync();

    cout << "Calle: ";
    cin >> this->des_trabajo.des_domicilio.nom_calle;
    cin.sync();

    cout << "Número interior: ";
    cin >> this->des_trabajo.des_domicilio.num_interior;
    cin.sync();

    cout << "Número Exterior: ";
    cin >> this->des_trabajo.des_domicilio.num_exterior;
    cin.sync();

    cout << "Entre calles: ";
    cin >> this->des_trabajo.des_domicilio.des_entrecalles;
    cin.sync();

    cout << "Observaciones que ayuden a localizar el domicilio: ";
    cin >> this->des_trabajo.des_domicilio.des_observaciones;
    cin.sync();

    cout << "Teléfono de casa: ";
    cin >> this->des_trabajo.des_domicilio.num_telefono;
    cin.sync();

    cout << "Celular: ";
    cin >> this->des_trabajo.des_domicilio.num_celular;
    cin.sync();

    cout << "Año de ingreso: ";
    cin >> this->des_trabajo.anio_ingreso;
    cin.sync();

    cout << "Sueldo mensual: ";
    cin >> this->des_trabajo.num_sueldo;
    cin.sync();

    // Datos referencia
    cout << endl;
    cout << "====== D A T O S  R E F E R E N C I A ======" << endl;
    cout << "Ingrese el nombre(s) de la referencia: ";
    cin >> this->des_referencia.nom_persona;
    cin.sync();

    cout << "Ingrese el apellido paterno de la referencia: ";
    cin >> this->des_referencia.ape_paterno;
    cin.sync();

    cout << "Ingrese el apellido materno de la referencia: ";
    cin >> this->des_referencia.ape_materno;
    cin.sync();

    cout << "Edad: ";
    cin >> this->des_referencia.edad;
    cin.sync();

    cout << "Año de nacimiento: ";
    cin >> this->des_referencia.anio_nacimiento;
    cin.sync();

    cout << "Mes de nacimiento: ";
    cin >> this->des_referencia.mes_nacimiento;
    cin.sync();

    cout << "Día de nacimiento: ";
    cin >> this->des_referencia.dia_nacimiento;
    cin.sync();

    // Datos del domicilio
    cout << endl;
    cout << "====== D O M I L I C I L I O  R E F E R E N C I A ======" << endl;
    cout << "Colonia: ";
    cin >> this->des_referencia.des_domicilio.nom_colonia;
    cin.sync();

    cout << "Calle: ";
    cin >> this->des_referencia.des_domicilio.nom_calle;
    cin.sync();

    cout << "Número interior: ";
    cin >> this->des_referencia.des_domicilio.num_interior;
    cin.sync();

    cout << "Número Exterior: ";
    cin >> this->des_referencia.des_domicilio.num_exterior;
    cin.sync();

    cout << "Entre calles: ";
    cin >> this->des_referencia.des_domicilio.des_entrecalles;
    cin.sync();

    cout << "Observaciones que ayuden a localizar el domicilio: ";
    cin >> this->des_referencia.des_domicilio.des_observaciones;
    cin.sync();

    cout << "Teléfono de casa: ";
    cin >> this->des_referencia.des_domicilio.num_telefono;
    cin.sync();

    cout << "Celular: ";
    cin >> this->des_referencia.des_domicilio.num_celular;
    cin.sync();
}

void SolicitudCoppel::ImprimeDatos(){
    cout << endl;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==D A T O S   D E   L A   S O L I C I T U D ==" << endl;
    cout << "==============================================" << endl;
    cout << endl;
    cout << "Folio solicitud Coppel: " << this->fol_solicitud << endl;
    cout << "====== Datos del solicitante ======" << endl;
    cout << "Nombre solicitante: " << this->des_cliente.nom_persona << " " << this->des_cliente.ape_paterno << " " << this->des_cliente.ape_materno << "." << endl;
    cout << "Fecha de nacimiento: " << this->des_cliente.dia_nacimiento << "/" << this->des_cliente.mes_nacimiento << "/" << this->des_cliente.anio_nacimiento << endl;
    cout << "Edad: " << this->des_cliente.edad << endl;
    cout << "CURP: " << this->des_cliente.des_curp << endl;

    cout << endl;
    cout << "====== Domicilio del solicitante ======" << endl;
    cout << endl;
    cout << "Colonia: " << this->des_cliente.des_domicilio.nom_colonia << endl;
    cout << "Calle: " << this->des_cliente.des_domicilio.nom_calle << endl;
    cout << "Número interior: " << this->des_cliente.des_domicilio.num_interior << endl;
    cout << "Número Exterior: " << this->des_cliente.des_domicilio.num_exterior << endl;
    cout << "Entre calles: " << this->des_cliente.des_domicilio.des_entrecalles << endl;
    cout << "Observaciones que ayuden a localizar el domicilio: " << this->des_cliente.des_domicilio.des_observaciones << endl;
    cout << "Teléfono de casa: " << this->des_cliente.des_domicilio.num_telefono << endl;
    cout << "Celular: " << this->des_cliente.des_domicilio.num_celular << endl;

    cout << endl;
    cout << "====== Datos del trabajo del solicitante ======" << endl;
    cout << endl;
    cout << "Nombre del trabajo: " << this->des_trabajo.nom_trabajo << endl;
    cout << "Puesto que desempeña / ocupación: "<< this->des_trabajo.nom_puesto << endl;
    cout << "Colonia: " << this->des_trabajo.des_domicilio.nom_colonia << endl;
    cout << "Calle: " << this->des_trabajo.des_domicilio.nom_calle << endl;
    cout << "Número interior: " << this->des_trabajo.des_domicilio.num_interior << endl;
    cout << "Número Exterior: " << this->des_trabajo.des_domicilio.num_exterior << endl;
    cout << "Entre calles: " << this->des_trabajo.des_domicilio.des_entrecalles << endl;
    cout << "Observaciones que ayuden a localizar el domicilio: " << this->des_trabajo.des_domicilio.des_observaciones << endl;
    cout << "Teléfono de casa: " << this->des_trabajo.des_domicilio.num_telefono << endl;
    cout << "Celular: " << this->des_trabajo.des_domicilio.num_celular << endl;
    cout << "Año de ingreso: " << this->des_trabajo.anio_ingreso << endl;
    cout << "Sueldo mensual: " << this->des_trabajo.num_sueldo << endl;

    cout << endl;
    cout << "====== Datos de la referencia del solicitante ======" << endl;
    cout << endl;
    cout << "Nombre referencia: " << this->des_referencia.nom_persona << " " << this->des_referencia.ape_paterno << " " << this->des_referencia.ape_materno << endl;
    cout << "Edad: " << this->des_referencia.edad << endl;
    cout << "Fecha de nacimiento: " << this->des_referencia.dia_nacimiento << "/" << this->des_referencia.mes_nacimiento << "/" << this->des_referencia.anio_nacimiento << endl;

    cout << endl;
    cout << "====== Domicilio de la referencia ======" << endl;
    cout << endl;
    cout << "Colonia: " << this->des_referencia.des_domicilio.nom_colonia << endl;
    cout << "Calle: " << this->des_referencia.des_domicilio.nom_calle << endl;
    cout << "Número interior: " << this->des_referencia.des_domicilio.num_interior << endl;
    cout << "Número Exterior: " << this->des_referencia.des_domicilio.num_exterior << endl;
    cout << "Entre calles: " << this->des_referencia.des_domicilio.des_entrecalles << endl;
    cout << "Observaciones que ayuden a localizar el domicilio: " << this->des_referencia.des_domicilio.des_observaciones << endl;
    cout << "Teléfono de casa: " << this->des_referencia.des_domicilio.num_telefono << endl;
    cout << "Celular: " << this->des_referencia.des_domicilio.num_celular << endl;

}

//////////////////////////////////////////////////////////////////////////////////////
class DatosTrabajador: public Trabajo {
public:
    string num_nss;
    string des_rfc;
};

class SolicitudAfore: public Solicitud {
public:
    SolicitudAfore(int);
    void ObtieneDatos();
    void ImprimeDatos();
private:
    DatosTrabajador des_trabajo;
};

SolicitudAfore::SolicitudAfore(int fol_solicitud_afore) : Solicitud(fol_solicitud_afore){

}


void SolicitudAfore::ObtieneDatos(){
    cout << "=================================================" << endl;
    cout << "======== S O L I C I T U D  A F O R E   =========" << endl;
    cout << "=================================================" << endl;
    cout << endl;

    //Datos personales
    cout << "Ingrese el nombre(s) del solicitante: ";
    cin >> this->des_cliente.nom_persona;
    cin.sync();

    cout << "Ingrese el apellido paterno del solicitante: ";
    cin >> this->des_cliente.ape_paterno;
    cin.sync();

    cout << "Ingrese el apellido materno del solicitante: ";
    cin >> this->des_cliente.ape_materno;
    cin.sync();

    cout << "Edad (número de años): ";
    cin >> this->des_cliente.edad;
    cin.sync();

    cout << "Año de nacimiento (número a cuatro dígitos): ";
    cin >> this->des_cliente.anio_nacimiento;
    cin.sync();

    cout << "Mes de nacimiento (número a dos dígitos): ";
    cin >> this->des_cliente.mes_nacimiento;
    cin.sync();

    cout << "Día de nacimiento (número a dos dígitos): ";
    cin >> this->des_cliente.dia_nacimiento;
    cin.sync();

    cout << "Favor de ingresar su CURP: ";
    cin >> this->des_cliente.des_curp;
    cin.sync();

    // Datos del domicilio
    cout << endl;
    cout << "====== D O M I L I C I L I O ======" << endl;
    cout << "Colonia: ";
    cin >> this->des_cliente.des_domicilio.nom_colonia;
    cin.sync();

    cout << "Calle: ";
    cin >> this->des_cliente.des_domicilio.nom_calle;
    cin.sync();

    cout << "Número interior: ";
    cin >> this->des_cliente.des_domicilio.num_interior;
    cin.sync();

    cout << "Número Exterior: ";
    cin >> this->des_cliente.des_domicilio.num_exterior;
    cin.sync();

    cout << "Entre calles: ";
    cin >> this->des_cliente.des_domicilio.des_entrecalles;
    cin.sync();

    cout << "Observaciones que ayuden a localizar el domicilio: ";
    cin >> this->des_cliente.des_domicilio.des_observaciones;
    cin.sync();

    cout << "Teléfono de casa: ";
    cin >> this->des_cliente.des_domicilio.num_telefono;
    cin.sync();

    cout << "Celular: ";
    cin >> this->des_cliente.des_domicilio.num_celular;
    cin.sync();

    //Datos del trabajo
    cout << endl;
    cout << "====== T R A B A J O ======" << endl;
    cout << "Nombre del trabajo: ";
    cin >> this->des_trabajo.nom_trabajo;
    cin.sync();

    cout << "Puesto que desempeña / ocupación: ";
    cin >> this->des_trabajo.nom_puesto;
    cin.sync();

    cout << "Número de seguro social: ";
    cin >> this->des_trabajo.num_nss;
    cin.sync();

    cout << "Favor de ingresar su RFC: ";
    cin >> this->des_trabajo.des_rfc;
    cin.sync();

    cout << "Colonia: ";
    cin >> this->des_trabajo.des_domicilio.nom_colonia;
    cin.sync();

    cout << "Calle: ";
    cin >> this->des_trabajo.des_domicilio.nom_calle;
    cin.sync();

    cout << "Número interior: ";
    cin >> this->des_trabajo.des_domicilio.num_interior;
    cin.sync();

    cout << "Número Exterior: ";
    cin >> this->des_trabajo.des_domicilio.num_exterior;
    cin.sync();

    cout << "Entre calles: ";
    cin >> this->des_trabajo.des_domicilio.des_entrecalles;
    cin.sync();

    cout << "Observaciones que ayuden a localizar el domicilio: ";
    cin >> this->des_trabajo.des_domicilio.des_observaciones;
    cin.sync();

    cout << "Teléfono de casa: ";
    cin >> this->des_trabajo.des_domicilio.num_telefono;
    cin.sync();

    cout << "Celular: ";
    cin >> this->des_trabajo.des_domicilio.num_celular;
    cin.sync();

    cout << "Año de ingreso: ";
    cin >> this->des_trabajo.anio_ingreso;
    cin.sync();

    cout << "Sueldo mensual: ";
    cin >> this->des_trabajo.num_sueldo;
    cin.sync();
}

void SolicitudAfore::ImprimeDatos(){
    cout << endl;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==D A T O S   D E   L A   S O L I C I T U D ==" << endl;
    cout << "==============================================" << endl;
    cout << endl;
    cout << "Folio solicitud Afore: " << this->fol_solicitud << endl;
    cout << endl;
    cout << "====== Datos del solicitante ======" << endl;
    cout << "Nombre solicitante: " << this->des_cliente.nom_persona << " " << this->des_cliente.ape_paterno << " " << this->des_cliente.ape_materno << "." << endl;
    cout << "Fecha de nacimiento: " << this->des_cliente.dia_nacimiento << "/" << this->des_cliente.mes_nacimiento << "/" << this->des_cliente.anio_nacimiento << endl;
    cout << "Edad: " << this->des_cliente.edad << endl;
    cout << "CURP: " << this->des_cliente.des_curp << endl;

    cout << endl;
    cout << "====== Domicilio del solicitante ======" << endl;
    cout << endl;
    cout << "Colonia: " << this->des_cliente.des_domicilio.nom_colonia << endl;
    cout << "Calle: " << this->des_cliente.des_domicilio.nom_calle << endl;
    cout << "Número interior: " << this->des_cliente.des_domicilio.num_interior << endl;
    cout << "Número Exterior: " << this->des_cliente.des_domicilio.num_exterior << endl;
    cout << "Entre calles: " << this->des_cliente.des_domicilio.des_entrecalles << endl;
    cout << "Observaciones que ayuden a localizar el domicilio: " << this->des_cliente.des_domicilio.des_observaciones << endl;
    cout << "Teléfono de casa: " << this->des_cliente.des_domicilio.num_telefono << endl;
    cout << "Celular: " << this->des_cliente.des_domicilio.num_celular << endl;

    cout << endl;
    cout << "====== Datos del trabajo del solicitante ======" << endl;
    cout << endl;
    cout << "NSS: " << this->des_trabajo.num_nss << endl;
    cout << "RFC: " << this->des_trabajo.des_rfc << endl;
    cout << "Nombre del trabajo: " << this->des_trabajo.nom_trabajo << endl;
    cout << "Puesto que desempeña / ocupación: "<< this->des_trabajo.nom_puesto << endl;
    cout << "Colonia: " << this->des_trabajo.des_domicilio.nom_colonia << endl;
    cout << "Calle: " << this->des_trabajo.des_domicilio.nom_calle << endl;
    cout << "Número interior: " << this->des_trabajo.des_domicilio.num_interior << endl;
    cout << "Número Exterior: " << this->des_trabajo.des_domicilio.num_exterior << endl;
    cout << "Entre calles: " << this->des_trabajo.des_domicilio.des_entrecalles << endl;
    cout << "Observaciones que ayuden a localizar el domicilio: " << this->des_trabajo.des_domicilio.des_observaciones << endl;
    cout << "Teléfono de casa: " << this->des_trabajo.des_domicilio.num_telefono << endl;
    cout << "Celular: " << this->des_trabajo.des_domicilio.num_celular << endl;
    cout << "Año de ingreso: " << this->des_trabajo.anio_ingreso << endl;
    cout << "Sueldo mensual: " << this->des_trabajo.num_sueldo << endl;
}

///////////////////////////////////////////////////////////////////////////////////////

class SolicitudBancoppel: public Solicitud {
public:
    SolicitudBancoppel(int);
    void ObtieneDatos();
    void ImprimeDatos();
private:
    DatosTrabajador des_trabajo;
    Persona des_referencia_1;
    Persona des_referencia_2;
};

SolicitudBancoppel::SolicitudBancoppel(int fol_solicitud_banco) : Solicitud(fol_solicitud_banco){

}


void SolicitudBancoppel::ObtieneDatos(){
    cout << "=================================================" << endl;
    cout << "===== S O L I C I T U D  B A N C O P P E L   ====" << endl;
    cout << "=================================================" << endl;
    cout << endl;
    //Datos personales
    cout << "Ingrese el nombre(s) del solicitante: ";
    cin >> this->des_cliente.nom_persona;
    cin.sync();

    cout << "Ingrese el apellido paterno del solicitante: ";
    cin >> this->des_cliente.ape_paterno;
    cin.sync();

    cout << "Ingrese el apellido materno del solicitante: ";
    cin >> this->des_cliente.ape_materno;
    cin.sync();

    cout << "Edad (número de años): ";
    cin >> this->des_cliente.edad;
    cin.sync();

    cout << "Año de nacimiento (número a cuatro dígitos): ";
    cin >> this->des_cliente.anio_nacimiento;
    cin.sync();

    cout << "Mes de nacimiento (número a dos dígitos): ";
    cin >> this->des_cliente.mes_nacimiento;
    cin.sync();

    cout << "Día de nacimiento (número a dos dígitos): ";
    cin >> this->des_cliente.dia_nacimiento;
    cin.sync();

    cout << "Favor de ingresar su CURP: ";
    cin >> this->des_cliente.des_curp;
    cin.sync();

    // Datos del domicilio
    cout << endl;
    cout << "====== D O M I L I C I L I O ======" << endl;
    cout << "Colonia: ";
    cin >> this->des_cliente.des_domicilio.nom_colonia;
    cin.sync();

    cout << "Calle: ";
    cin >> this->des_cliente.des_domicilio.nom_calle;
    cin.sync();

    cout << "Número interior: ";
    cin >> this->des_cliente.des_domicilio.num_interior;
    cin.sync();

    cout << "Número Exterior: ";
    cin >> this->des_cliente.des_domicilio.num_exterior;
    cin.sync();

    cout << "Entre calles: ";
    cin >> this->des_cliente.des_domicilio.des_entrecalles;
    cin.sync();

    cout << "Observaciones que ayuden a localizar el domicilio: ";
    cin >> this->des_cliente.des_domicilio.des_observaciones;
    cin.sync();

    cout << "Teléfono de casa: ";
    cin >> this->des_cliente.des_domicilio.num_telefono;
    cin.sync();

    cout << "Celular: ";
    cin >> this->des_cliente.des_domicilio.num_celular;
    cin.sync();

    //Datos del trabajo
    cout << endl;
    cout << "====== T R A B A J O ======" << endl;
    cout << "Nombre del trabajo: ";
    cin >> this->des_trabajo.nom_trabajo;
    cin.sync();

    cout << "Puesto que desempeña / ocupación: ";
    cin >> this->des_trabajo.nom_puesto;
    cin.sync();

    cout << "Número de seguro social: ";
    cin >> this->des_trabajo.num_nss;
    cin.sync();

    cout << "Favor de ingresar su RFC: ";
    cin >> this->des_trabajo.des_rfc;
    cin.sync();

    cout << "Colonia: ";
    cin >> this->des_trabajo.des_domicilio.nom_colonia;
    cin.sync();

    cout << "Calle: ";
    cin >> this->des_trabajo.des_domicilio.nom_calle;
    cin.sync();

    cout << "Número interior: ";
    cin >> this->des_trabajo.des_domicilio.num_interior;
    cin.sync();

    cout << "Número Exterior: ";
    cin >> this->des_trabajo.des_domicilio.num_exterior;
    cin.sync();

    cout << "Entre calles: ";
    cin >> this->des_trabajo.des_domicilio.des_entrecalles;
    cin.sync();

    cout << "Observaciones que ayuden a localizar el domicilio: ";
    cin >> this->des_trabajo.des_domicilio.des_observaciones;
    cin.sync();

    cout << "Teléfono de casa: ";
    cin >> this->des_trabajo.des_domicilio.num_telefono;
    cin.sync();

    cout << "Celular: ";
    cin >> this->des_trabajo.des_domicilio.num_celular;
    cin.sync();

    cout << "Año de ingreso: ";
    cin >> this->des_trabajo.anio_ingreso;
    cin.sync();

    cout << "Sueldo mensual: ";
    cin >> this->des_trabajo.num_sueldo;
    cin.sync();

    // Datos referencia
    cout << endl;
    cout << "====== D A T O S  R E F E R E N C I A  #1 ======" << endl;
    cout << "Ingrese el nombre(s) de la referencia #1: ";
    cin >> this->des_referencia_1.nom_persona;
    cin.sync();

    cout << "Ingrese el apellido paterno de la referencia: ";
    cin >> this->des_referencia_1.ape_paterno;
    cin.sync();

    cout << "Ingrese el apellido materno de la referencia: ";
    cin >> this->des_referencia_1.ape_materno;
    cin.sync();

    cout << "Edad: ";
    cin >> this->des_referencia_1.edad;
    cin.sync();

    cout << "Año de nacimiento: ";
    cin >> this->des_referencia_1.anio_nacimiento;
    cin.sync();

    cout << "Mes de nacimiento: ";
    cin >> this->des_referencia_1.mes_nacimiento;
    cin.sync();

    cout << "Día de nacimiento: ";
    cin >> this->des_referencia_1.dia_nacimiento;
    cin.sync();

    // Datos del domicilio
    cout << endl;
    cout << "====== D O M I L I C I L I O  R E F E R E N C I A  #1 ======" << endl;
    cout << "Colonia: ";
    cin >> this->des_referencia_1.des_domicilio.nom_colonia;
    cin.sync();

    cout << "Calle: ";
    cin >> this->des_referencia_1.des_domicilio.nom_calle;
    cin.sync();

    cout << "Número interior: ";
    cin >> this->des_referencia_1.des_domicilio.num_interior;
    cin.sync();

    cout << "Número Exterior: ";
    cin >> this->des_referencia_1.des_domicilio.num_exterior;
    cin.sync();

    cout << "Entre calles: ";
    cin >> this->des_referencia_1.des_domicilio.des_entrecalles;
    cin.sync();

    cout << "Observaciones que ayuden a localizar el domicilio: ";
    cin >> this->des_referencia_1.des_domicilio.des_observaciones;
    cin.sync();

    cout << "Teléfono de casa: ";
    cin >> this->des_referencia_1.des_domicilio.num_telefono;
    cin.sync();

    cout << "Celular: ";
    cin >> this->des_referencia_1.des_domicilio.num_celular;
    cin.sync();

    cout << endl;
    cout << "====== D A T O S  R E F E R E N C I A  #2 ======" << endl;
    cout << "Ingrese el nombre(s) de la referencia #2: ";
    cin >> this->des_referencia_2.nom_persona;
    cin.sync();

    cout << "Ingrese el apellido paterno de la referencia: ";
    cin >> this->des_referencia_2.ape_paterno;
    cin.sync();

    cout << "Ingrese el apellido materno de la referencia: ";
    cin >> this->des_referencia_2.ape_materno;
    cin.sync();

    cout << "Edad: ";
    cin >> this->des_referencia_2.edad;
    cin.sync();

    cout << "Año de nacimiento: ";
    cin >> this->des_referencia_2.anio_nacimiento;
    cin.sync();

    cout << "Mes de nacimiento: ";
    cin >> this->des_referencia_2.mes_nacimiento;
    cin.sync();

    cout << "Día de nacimiento: ";
    cin >> this->des_referencia_2.dia_nacimiento;
    cin.sync();

    // Datos del domicilio
    cout << endl;
    cout << "====== D O M I L I C I L I O  R E F E R E N C I A  #1 ======" << endl;
    cout << "Colonia: ";
    cin >> this->des_referencia_2.des_domicilio.nom_colonia;
    cin.sync();

    cout << "Calle: ";
    cin >> this->des_referencia_2.des_domicilio.nom_calle;
    cin.sync();

    cout << "Número interior: ";
    cin >> this->des_referencia_2.des_domicilio.num_interior;
    cin.sync();

    cout << "Número Exterior: ";
    cin >> this->des_referencia_2.des_domicilio.num_exterior;
    cin.sync();

    cout << "Entre calles: ";
    cin >> this->des_referencia_2.des_domicilio.des_entrecalles;
    cin.sync();

    cout << "Observaciones que ayuden a localizar el domicilio: ";
    cin >> this->des_referencia_2.des_domicilio.des_observaciones;
    cin.sync();

    cout << "Teléfono de casa: ";
    cin >> this->des_referencia_2.des_domicilio.num_telefono;
    cin.sync();

    cout << "Celular: ";
    cin >> this->des_referencia_2.des_domicilio.num_celular;
    cin.sync();
}

void SolicitudBancoppel::ImprimeDatos(){
    cout << endl;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==D A T O S   D E   L A   S O L I C I T U D ==" << endl;
    cout << "==============================================" << endl;
    cout << endl;
    cout << "Folio solicitud Afore: " << this->fol_solicitud << endl;
    cout << endl;
    cout << "====== Datos del solicitante ======" << endl;
    cout << "Nombre solicitante: " << this->des_cliente.nom_persona << " " << this->des_cliente.ape_paterno << " " << this->des_cliente.ape_materno << "." << endl;
    cout << "Fecha de nacimiento: " << this->des_cliente.dia_nacimiento << "/" << this->des_cliente.mes_nacimiento << "/" << this->des_cliente.anio_nacimiento << endl;
    cout << "Edad: " << this->des_cliente.edad << endl;
    cout << "CURP: " << this->des_cliente.des_curp << endl;

    cout << endl;
    cout << "====== Domicilio del solicitante ======" << endl;
    cout << endl;
    cout << "Colonia: " << this->des_cliente.des_domicilio.nom_colonia << endl;
    cout << "Calle: " << this->des_cliente.des_domicilio.nom_calle << endl;
    cout << "Número interior: " << this->des_cliente.des_domicilio.num_interior << endl;
    cout << "Número Exterior: " << this->des_cliente.des_domicilio.num_exterior << endl;
    cout << "Entre calles: " << this->des_cliente.des_domicilio.des_entrecalles << endl;
    cout << "Observaciones que ayuden a localizar el domicilio: " << this->des_cliente.des_domicilio.des_observaciones << endl;
    cout << "Teléfono de casa: " << this->des_cliente.des_domicilio.num_telefono << endl;
    cout << "Celular: " << this->des_cliente.des_domicilio.num_celular << endl;

    cout << endl;
    cout << "====== Datos del trabajo del solicitante ======" << endl;
    cout << endl;
    cout << "NSS: " << this->des_trabajo.num_nss << endl;
    cout << "RFC: " << this->des_trabajo.des_rfc << endl;
    cout << "Nombre del trabajo: " << this->des_trabajo.nom_trabajo << endl;
    cout << "Puesto que desempeña / ocupación: "<< this->des_trabajo.nom_puesto << endl;
    cout << "Colonia: " << this->des_trabajo.des_domicilio.nom_colonia << endl;
    cout << "Calle: " << this->des_trabajo.des_domicilio.nom_calle << endl;
    cout << "Número interior: " << this->des_trabajo.des_domicilio.num_interior << endl;
    cout << "Número Exterior: " << this->des_trabajo.des_domicilio.num_exterior << endl;
    cout << "Entre calles: " << this->des_trabajo.des_domicilio.des_entrecalles << endl;
    cout << "Observaciones que ayuden a localizar el domicilio: " << this->des_trabajo.des_domicilio.des_observaciones << endl;
    cout << "Teléfono de casa: " << this->des_trabajo.des_domicilio.num_telefono << endl;
    cout << "Celular: " << this->des_trabajo.des_domicilio.num_celular << endl;
    cout << "Año de ingreso: " << this->des_trabajo.anio_ingreso << endl;
    cout << "Sueldo mensual: " << this->des_trabajo.num_sueldo << endl;

    cout << endl;
    cout << "====== Datos de la referencia del solicitante #1 ======" << endl;
    cout << endl;
    cout << "Nombre referencia: " << this->des_referencia_1.nom_persona << " " << this->des_referencia_1.ape_paterno << " " << this->des_referencia_1.ape_materno << endl;
    cout << "Edad: " << this->des_referencia_1.edad << endl;
    cout << "Fecha de nacimiento: " << this->des_referencia_1.dia_nacimiento << "/" << this->des_referencia_1.mes_nacimiento << "/" << this->des_referencia_1.anio_nacimiento << endl;

    cout << endl;
    cout << "====== Domicilio de la referencia #1 ======" << endl;
    cout << endl;
    cout << "Colonia: " << this->des_referencia_1.des_domicilio.nom_colonia << endl;
    cout << "Calle: " << this->des_referencia_1.des_domicilio.nom_calle << endl;
    cout << "Número interior: " << this->des_referencia_1.des_domicilio.num_interior << endl;
    cout << "Número Exterior: " << this->des_referencia_1.des_domicilio.num_exterior << endl;
    cout << "Entre calles: " << this->des_referencia_1.des_domicilio.des_entrecalles << endl;
    cout << "Observaciones que ayuden a localizar el domicilio: " << this->des_referencia_1.des_domicilio.des_observaciones << endl;
    cout << "Teléfono de casa: " << this->des_referencia_1.des_domicilio.num_telefono << endl;
    cout << "Celular: " << this->des_referencia_1.des_domicilio.num_celular << endl;

    cout << endl;
    cout << "====== Datos de la referencia del solicitante #2 ======" << endl;
    cout << endl;
    cout << "Nombre referencia: " << this->des_referencia_2.nom_persona << " " << this->des_referencia_2.ape_paterno << " " << this->des_referencia_2.ape_materno << endl;
    cout << "Edad: " << this->des_referencia_2.edad << endl;
    cout << "Fecha de nacimiento: " << this->des_referencia_2.dia_nacimiento << "/" << this->des_referencia_2.mes_nacimiento << "/" << this->des_referencia_2.anio_nacimiento << endl;

    cout << endl;
    cout << "====== Domicilio de la referencia #2 ======" << endl;
    cout << endl;
    cout << "Colonia: " << this->des_referencia_2.des_domicilio.nom_colonia << endl;
    cout << "Calle: " << this->des_referencia_2.des_domicilio.nom_calle << endl;
    cout << "Número interior: " << this->des_referencia_2.des_domicilio.num_interior << endl;
    cout << "Número Exterior: " << this->des_referencia_2.des_domicilio.num_exterior << endl;
    cout << "Entre calles: " << this->des_referencia_2.des_domicilio.des_entrecalles << endl;
    cout << "Observaciones que ayuden a localizar el domicilio: " << this->des_referencia_2.des_domicilio.des_observaciones << endl;
    cout << "Teléfono de casa: " << this->des_referencia_2.des_domicilio.num_telefono << endl;
    cout << "Celular: " << this->des_referencia_2.des_domicilio.num_celular << endl;
}




class SistemaSolicitud {
public:
    SistemaSolicitud(Solicitud*);
    void IniciarProceso();
private:
    Solicitud *pSol;
};

SistemaSolicitud::SistemaSolicitud(Solicitud *pSolicitud){
    this->pSol = pSolicitud;
}

void SistemaSolicitud::IniciarProceso(){
    this->pSol->ObtieneDatos();
    cout << endl;
    cout << "-> Procesando información espere un momento.";
    cout << endl;
    this_thread::sleep_for (chrono::seconds(2));
    cout << endl;

    cout << "-> Mostrando datos capturados...." << endl;;
    this_thread::sleep_for (chrono::seconds(1));
    cout << endl;


    this->pSol->ImprimeDatos();
}

int main()
{
    setlocale(LC_ALL, "");

    int num_opcion = 0;
    Solicitud *pSolicitud;

    int folioCoppel = 0;
    int folioAfore = 0;
    int folioBanco = 0;

    SolicitudCoppel *solCoppel;
    SolicitudAfore *solAfore;
    SolicitudBancoppel *solBanco;

    do{
            cout << "==========================================" << endl;
            cout << "=============== M  E  N  Ú ===============" << endl;
            cout << "==========================================" << endl;
            cout << endl;
            cout << "Opción 1: Solicitud Coppel" << endl;
            cout << "Opción 2: Solicitud Afore" << endl;
            cout << "Opción 3: Solicitud Bancoppel" << endl;
            cout << "Opción 4: Para Salir" << endl;
            cout << endl;
            cout << "Favor de seleccionar la opción deceada: ";
            cin >> num_opcion;

        switch(num_opcion)
        {
            case 1:
                folioCoppel++;
                solCoppel = new SolicitudCoppel(folioCoppel);
                pSolicitud = solCoppel;
                break;
            case 2:
                folioAfore++;
                solAfore = new SolicitudAfore(folioAfore);
                pSolicitud = solAfore;
                break;
            case 3:
                folioBanco++;
                solBanco = new SolicitudBancoppel(folioBanco);
                pSolicitud = solBanco;
                break;
        }

        if(num_opcion > 0 && num_opcion < 4){
            SistemaSolicitud pagina_web(pSolicitud);
            pagina_web.IniciarProceso();
        }

        cout << endl;
        cout << endl;

    }while(num_opcion != 4);

    return 0;
}
