#include <iostream>

using namespace std;

int main()
{
    //Ejercicio 9: Cuando se realiza una compra al contado en una tienda departamental, al realizar el pago algunas veces
	//				el cliente no trae el pago exacto. Utiliza un programa para realizar el cambio que corresponde del pago
	//				realizado sobre la compra. Considerando que el cambio unicamente debe de ser monedas de 5, 10, 20 y 50
	//				que sea de la entrada estandar el importe de la compra y la cantidad de dindero con la que paga por la
	//				compra el comprador. Escriba en la salida estandar las monedas devueltas.

	int totalCompra;
	int pago;

	cout << "Ingrese el total del importe: $";
	cin >> totalCompra;

	cout << "Paga con: $";
	cin >> pago;

	int diferencia = totalCompra - pago;
	if (diferencia < 0)
	{
		diferencia = diferencia * -1;
	}
	int conta50 = 0, conta20 = 0, conta10 = 0, conta5 = 0;

	while (diferencia >= 5)
	{
		if (diferencia >= 50)
		{
			conta50++;
			diferencia = diferencia - 50;
		}
		else if (diferencia >= 20)
		{
			conta20++;
			diferencia = diferencia - 20;
		}
		else if (diferencia >= 10)
		{
			conta10++;
			diferencia = diferencia - 10;
		}
		else if (diferencia >= 5)
		{
			conta5++;
			diferencia = diferencia - 5;
		}
	}

	cout << "El cambio de la compra de $" << totalCompra << ", menos el pago de $" << pago << " es de:\n";
	cout << conta50 << " monedas de $50\n";
	cout << conta20 << " monedas de $20\n";
	cout << conta10 << " monedas de $10\n";
	cout << conta5 << " monedas de $5\n";
	cout << diferencia << " monedas de $1\n";

	cin.get();
	cin.get();

    return 0;
}
