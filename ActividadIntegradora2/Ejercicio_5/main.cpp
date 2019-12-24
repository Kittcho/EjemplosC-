#include <iostream>

using namespace std;

int main()
{
    /*
    EJERCICIO 5.-
    Hacer un programa que ayude a una empresa a incrementar los salarios de los trabajadores de la
    siguiente manera:
    Tipo de salario %
    De 0 a $9 000 20%
    De $9 000 a $15 000 10%
    De $15 000 a $20 000 5%
    Más de $20 000 3%
    */

    double salario = 0,
           nuevoSalario = 0;

    while(true){

    cout << "Favor de ingresar el salario: $";
    cin >> salario;

    if(salario <= 9000){
        nuevoSalario = salario * 1.2;
    }else if(salario <= 15000){
        nuevoSalario = salario * 1.1;
    }else if(salario <= 20000){
        nuevoSalario = salario * 1.05;
    }else
    {
        nuevoSalario = salario * 1.3;
    }

    cout << "El nuevo salario es de: $" << nuevoSalario << "\n";
    }

    cin.get();
    cin.get();

    return 0;
}
