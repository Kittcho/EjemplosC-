#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*
    EJERCICIO 6.-
    El almacén de una empresa líder tiene una promoción que se aplica según el mes,
    en los meses de enero a julio todas las ventas mayores de 1000 tienen un descuento del 10% sobre el precio de venta
    y no se le cobrará el IVA,
    en los meses de julio a diciembre las ventas mayores a 5000 tienen un descuento del 10% y se les cobrará el IVA,
    las ventas mayores a 1000 tienen un descuento y se les cobra el IVA pero las ventas mayores a 2000 se les hace un descuento del 20%
    y no se les cobrará IVA.
    Determinar lo que el cliente debe pagar. (El IVA es del 16% y se calcula después de
    aplicarle el descuento a la venta).

    */

    int mes = 0;
    string meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    double ventas = 0, descuento = 0, subtotal = 0, total = 0, iva;
    bool seCobraIva = true;

    cout << "Favor de ingresar el mes en número(1 - 12): ";
    cin >> mes;

    cout << "Favor de ingresar las ventas de " << meses[mes - 1] << ": ";
    cin >> ventas;

    if(mes < 7){
        if(ventas > 1000){
            descuento = ventas * 0.10;
            seCobraIva = false;
        }
    }else{
        if(ventas > 1000 && ventas <= 2000 ){
            descuento = ventas * 0.10;
        }else if(ventas <= 5000){
            descuento = ventas * 0.20;
            seCobraIva = false;
        }else if(ventas > 5000){
            descuento = ventas * 0.10;
        }
    }

    subtotal = ventas - descuento;
    iva = seCobraIva ? subtotal * 0.16 : 0;
    total = subtotal + iva;

    cout << "Descuento: $" << descuento << endl;
    cout << "Sub-Total: $" << subtotal << endl;
    cout << "(+) IVA: $" << iva << endl;
    cout << "Total: $" << total << endl;

    cin.get();
    cin.get();

    return 0;
}
