#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    //Ejercicio 5: Dada la entrada del nombre de una persona y el día, mes y año de nacimiento, escriba un
	//				programa que determine su edad y de salida el nombre de la persona y edad

    setlocale(LC_ALL, "");

    char nombre[50];
	int edad = 0;
	int diaNacimiento = 0;
	int mesNacimiento = 0;
	int anioNacimiento = 0;


    cout << "Ingrese el nombre de la persona: ";
	cin >> nombre;

	cout << "Ingrese el año de nacimiento, ejemplo (2011): ";
	cin >> anioNacimiento;

	cout << "Ingrese el mes de nacimiento, ejemplo (02): ";
	cin >> mesNacimiento;

	cout << "Ingrese el día de nacimiento, ejemplo (05): ";
	cin >> diaNacimiento;

    //Obtengo la fecha actual
	time_t t = std::time(0);
	tm* now = std::localtime(&t);

	int anioActual = now->tm_year + 1900;
	int mesActual = now->tm_mon + 1;
	int diaActual = now->tm_mday;

	//Calculamos su edad.
	if (mesNacimiento > mesActual || mesNacimiento == mesActual && diaNacimiento > diaActual)
	{
		edad = anioActual - anioNacimiento - 1;
	}
	else
	{
		edad = anioActual - anioNacimiento;
	}

	cout << "\n" << nombre << " tiene una edad de " << edad << " años.";

    cin.get();
    cin.get();

    return 0;
}
