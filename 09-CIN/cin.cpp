#include <iostream>

using namespace std;

int main(){
    string continuar = "no";
    int valor = 0, res = 0;

    do{
        cout << "Ingrese el valor a sumar: ";
        cin >> valor;

        res += valor;
        cout << "Valor actual: " << res;

        cout << "\n\nDesea ingresar un nuevo valor? (si/no): ";
        cin >> continuar;
        cout << "\n\n\n";
    }while(continuar == "si");

system("pause");
    return 0;
}