#include <iostream>

using namespace std;

int main()
{
    //Ejercicio 8: Realice un programa de la entrada de un valor correspondiente a una distancia en millas y las visualice
	//				expresada en metros. Sabiendo que una milla marina equivale a 1852 metros.

	double millas;
	const int unaMillaAMetro = 1852;
	cout << "Ingresa el valor de las millas a convertir: ";
	cin >> millas;

	cout << "Conversión a kilometros: " << (millas * unaMillaAMetro) / 1000 << " kilometros";

	cin.get();
	cin.get();

    return 0;
}
