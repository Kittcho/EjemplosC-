#include <iostream>

using namespace std;

void InsertarRegistro(int &indice, string nombre, string apellidos, string telefono);

int main()
{
    /*
    EJERCICIO 5.-
    Hacer un programa que guarde los n�meros telef�nicos que muestre un men� con las siguientes opciones:
    Crear (nombre, apellidos, tel�fono)
    Agregar m�s contactos (nombre, apellidos, tel�fono)
    Visualizar contactos existentes
    */

    setlocale(LC_ALL, "");

    string libreta[50][3];

    cout << "----------------------------" << endl;
    cout << "--       M  E  N  �       --" << endl;
    cout << "----------------------------" << endl;
    cout << "Opciones: " << endl;
    cout << "1 = Crear contacto." << endl;
    cout << "2 = Agregar m�s contactos." << endl;
    cout << "3 = Visualizar contacto." << endl;

    char opcion = 0;
    int indice = 0;
    bool salir = false;

    while(not salir){

        cout << "\nFavor de seleccionar una opci�n: ";
        cin >> opcion;

        switch(opcion){
        case '1': case '2':
            cout << "Ingrese el nombre de la persona: ";
            cin.sync();
            getline(cin, libreta[indice][0]);

            cout << "Ingrese los apellidos de la persona: ";
            cin.sync();
            getline(cin, libreta[indice][1]);

            cout << "Ingrese el tel�fono de la persona: ";
            cin.sync();
            getline(cin, libreta[indice][2]);

            indice++;

            cout << "Contacto guardado." << endl;
            break;

        case '3':
            salir = true;
            break;
        default:
            cout << "Opci�n no valida." << endl;
        }

    }

    cout << "Libreta de direcciones: " << endl;

    for(int i = 0; i < indice; i++){
        cout << "Nombre: " << libreta[i][0] << ", Apellidos: " << libreta[i][1] << ", Tel�fono: " << libreta[i][2] << endl;
    }

    cin.get();
    cin.get();

    return 0;
}
