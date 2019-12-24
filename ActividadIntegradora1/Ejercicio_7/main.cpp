#include <iostream>

using namespace std;

int main()
{
    //Ejercicio 7: Realice un programa de entrada de un valor númerico y muestra la salida de incremento y
	//				decremento del valor dado.


	int valor = 0;

	cout << "Favor de escribir el valor a decrementar e incrementar: ";
	cin >> valor;

	cout << "Decremento: " << valor - 1 << "\nIncremento: " << valor + 1;

	cin.get();
	cin.get();

    return 0;
}
