#include <iostream>

using namespace std;

void InsertarRegistro(int &indice, string nombre, string apellidos, string telefono);

int main()
{
    /*
    EJERCICIO 5.-
    Hacer un programa que guarde los números telefónicos que muestre un menú con las siguientes opciones:
    Crear (nombre, apellidos, teléfono)
    Agregar más contactos (nombre, apellidos, teléfono)
    Visualizar contactos existentes
    */

    setlocale(LC_ALL, "");

    string libreta[50][3];

    cout << "----------------------------" << endl;
    cout << "--       M  E  N  Ú       --" << endl;
    cout << "----------------------------" << endl;
    cout << "Opciones: " << endl;
    cout << "1 = Crear contacto." << endl;
    cout << "2 = Agregar más contactos." << endl;
    cout << "3 = Visualizar contacto." << endl;

    char opcion = 0;
    int indice = 0;
    bool salir = false;

    while(not salir){

        cout << "\nFavor de seleccionar una opción: ";
        cin >> opcion;

        switch(opcion){
        case '1': case '2':
            cout << "Ingrese el nombre de la persona: ";
            cin.sync();
            getline(cin, libreta[indice][0]);

            cout << "Ingrese los apellidos de la persona: ";
            cin.sync();
            getline(cin, libreta[indice][1]);

            cout << "Ingrese el teléfono de la persona: ";
            cin.sync();
            getline(cin, libreta[indice][2]);

            indice++;

            cout << "Contacto guardado." << endl;
            break;

        case '3':
            salir = true;
            break;
        default:
            cout << "Opción no valida." << endl;
        }

    }

    cout << "Libreta de direcciones: " << endl;

    for(int i = 0; i < indice; i++){
        cout << "Nombre: " << libreta[i][0] << ", Apellidos: " << libreta[i][1] << ", Teléfono: " << libreta[i][2] << endl;
    }

    cin.get();
    cin.get();

    return 0;
}
