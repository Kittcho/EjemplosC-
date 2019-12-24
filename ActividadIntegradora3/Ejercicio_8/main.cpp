#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    /*
    EJERCICIO 8.-
    Escriba un programa que tome cada 4 horas la temperatura exterior, leyéndola durante un período
    de 24 horas. Es decir, debe leer 6 temperaturas. Calcule la temperatura media del día, la
    temperatura más alta y la más baja.
    */

    float temperaturas[6];

    for(int i = 1; i < 7; i++){
        printf("Favor de ingresar la temperatura de las %0d:00 horas: ", i * 4);
        scanf("%f", &temperaturas[i - 1]);
    }

    float temporal;

	for (int i = 0;i < 6; i++){
		for (int j = 0; j< 6-1; j++){
			if (temperaturas[j] < temperaturas[j+1]){
			temporal = temperaturas[j];
			temperaturas[j] = temperaturas[j+1];
			temperaturas[j+1] = temporal;
			}
		}
	}

    cout << "Temperatura mas alta: " << temperaturas[0] << endl;
    cout << "Temperatura mas media: " << temperaturas[3] << endl;
    cout << "Temperatura mas baja: " << temperaturas[5] << endl;

    cin.get();
    cin.get();

    return 0;
}
