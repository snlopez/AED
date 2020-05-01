/*
    Adicion
    snlopez
    20200430
*/

#include <iostream>

using namespace std;

void sumar(void);

int main(){
    int valorInvalido = 0;
    char repetir = 1;

    cout << "Ingrese dos numeros para sumarlos \n";
    
    sumar();

    while(repetir == 1 && valorInvalido < 3){
        cout << "Desea hacer otra suma? (s/n): ";
        cin >> repetir;

        switch(repetir){
            case 's': 
                sumar();
                valorInvalido = 0;
                repetir = 1;
                break;
            case 'S':
                sumar();
                valorInvalido = 0;
                repetir = 1;
                break;
            case 'n':
                repetir = 0;
                break;
            case 'N':
                repetir = 0;
                break;
            default:
                valorInvalido ++;
                repetir = 1;
                cout << "Valor ingresado invalido!\n";
        }
        
        if(valorInvalido == 3)
        {
            cout << "Ingreso un valor incorrecto demasiadas veces, adios!\n\n";
        }

    }

    return 0;
}

void sumar(void){
    float a = 0, b = 0;
    
    cout << "Primer valor: ";
    cin >> a;

    cout << "Segundo valor: ";
    cin >> b;

    cout << "El resultado es: " << a << " + " << b << " = " << a + b << "\n";
}
