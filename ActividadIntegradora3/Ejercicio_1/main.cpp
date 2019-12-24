#include <iostream>

using namespace std;



int main()
{
    /*
    EJERCICIO 1.-
    Hacer un programa que calcule y muestre el total a pagar por la compra de pantalones, se debe
    pedir como entrada el valor del pantalón y la cantidad de pantalones comprados, además si se
    compra 5 pantalones o más se le aplica un descuento de 25% al monto total a pagar y si son
    menos de 5 pantalones el descuento es de 10% al monto total a pagar.
    */

    int cantidad = 0;
    double precio = 0,
           descuento = 0,
           subtotal = 0,
           total = 0;

    cout << "Favor de ingresar el precio por pantalon: $";
    cin >> precio;

    cout << "Favor de ingresar la cantidad de pantalones: ";
    cin >> cantidad;

    subtotal = precio * cantidad;

    if(cantidad < 5){
        descuento = subtotal * 0.10;
    }else{
        descuento = subtotal * 0.25;
    }

    total = subtotal - descuento;

    cout << "Sub-total: $" << subtotal << endl;
    cout << "(-) Descuento: $" << descuento << endl;
    cout << "Total: $" << total << endl;

    cin.get();
    cin.get();

    return 0;
}
