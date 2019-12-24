#include <iostream>

using namespace std;

int main()
{
    //Ejercicio 6: Realice un programa que pueda calcular un indice de masa corporal (IMC) tomando en cuenta que para
	//				realizar la operación los datos de entrada son el peso: IMC = peso / (estatura * estatura)

	double altura;
	float peso;

	cout << "Favor de escribir su peso: ";
	cin >> peso;

	cout << "Favor de escribir su altura: ";
	cin >> altura;

	cout << "Su indice de masa corporal (IMC) es de '" << (peso / (altura * altura)) << "'";

	cin.get();
	cin.get();

    return 0;
}
