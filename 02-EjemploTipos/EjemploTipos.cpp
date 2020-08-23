/*
    Ejemplo Tipos
    snlopez
    20200521

    Tipos de datos: bool, int, char, string, unsigned, double
*/

#include <iostream>
#include <assert.h> // assert(condicion) devuelve un error si la condicion no se cumple pero se frena el programa,
                    // no lo encuentro practico
using namespace std;

int main (void){

    //BOOL --> solo pueden valer 'true' o 'false'
    bool valor1=true, valor2=false;
    /*
    cout << "Booleanos, solo pueden tomar valores de verdadero (true) o falso (false)\n";
    cout << "valor1 = " << valor1 << ", valor2 = " << valor2 << "\n";
    if(valor1){
        cout << "valor1 es verdadero\n";
    }else{
        cout << "valor1 es falso\n";
    }
    if(valor2){
        cout << "valor2 es verdadero\n";
    }else{
        cout << "valor2 es falso\n";
    }
    */
    
    assert(valor1);
    //assert(valor2);

    
    //int --> puede tomar valores enteros
    int int1=50, int2=-25785, int3=15; 
    int resInt1=int1*int3, resInt2=int1/int3, resInt3=int2-int1, resInt4=int1 + int3;//resultados
    /*
    cout << "\n\nEnteros, solo pueden mostrar valores enteros, por lo que no se mostraran los decimales\n";
    cout << "valor1 = " << int1 << ", valor2 = " << int2 << ", valor3 = " << int3 << "\n";
    cout << "valor1 * valor3 = " << resInt1 << "\n";
    cout << "valor1 / valor3 = " << resInt2 << "\n";
    cout << "valor2 - valor2 = " << resInt3 << "\n";
    cout << "valor1 + valor3 = " << resInt4 << "\n";
    */

    assert(int1 * int2);
    //assert(int1 / int2);
    assert(int2 - int1);
    assert(int1 + int3);
    //assert(int1 == int2);


    //char --> representa los caracteres ascii
    char char1='A', char2=123, char3='@', resChar= char1 + char2;
    /*
    cout << "\n\nChar, representan los caracteres ascii\n";
    cout << "char1 = " << char1 << ", char2 = " << char2 << ", char3 = " << char3 << "\n";
    cout << "Al sumarsen se obtendra el caracter correspondiente al resultado de la suma de los enteros que representan --> char1 + char2 = " << char1 +char2 << " = " << resChar << "\n";
    */

    assert(char1 + char2);
    //assert(char1 == char2);


    //string --> representan cadenas de caracteres
    string string1= "Hola ", string2="Mundo!";
    /*cout << "\n\nString, representan cadenas de caracteres\n";
    cout << "Permiten realizar operaciones como concatenarlos o 'unirlos'\n";
    cout << "Si sumamos dos strings '" << string1 << "' y '" << string2 << "' obtendremos: '" << string1+string2 << "'\n";
    */

    //assert(string1 == string2);
    assert((string1 + string2) == "Hola Mundo!");


    //unsigned --> representan numeros naturales
    unsigned Uns1=200, Uns2=3000;
    unsigned resUns1=Uns1*Uns2, resUns2=Uns1/Uns2, resUns3=Uns1-Uns2, resUns4=Uns1 + Uns2;//resultados
    /*
    cout <<"\n\nUnsigned, representan numeros naturales, por lo que no podran representar valores negativos ni decimales\n";
    cout << "valor1 = " << Uns1 << ", valor2 = " << Uns2 <<  "\n";
    cout << "valor1 * valor2 = " << resUns1 << "\n";
    cout << "valor1 / valor2 = " << resUns2 << "\n";
    cout << "valor2 - valor1 = " << resUns3 << "\n";
    cout << "valor1 + valor2 = " << resUns4 << "\n";
    cout << "Como puede verse el tercer resultado da mal debido a que el mismo supera los limites de representacion y produce un Overflow\n";
    */

    assert(Uns1 * Uns2);
    //assert(Uns1 / Uns2);
    assert(Uns2 - Uns1);
    assert(Uns1 + Uns2);


    //double --> representan numeros decimales
    double dbl1=8.245, dbl2=3.487;
    double resdbl1=dbl1*dbl2, resdbl2=dbl1/dbl2, resdbl3=dbl2-dbl1, resdbl4=dbl1 + dbl2;//resultados
    /*
    cout <<"\n\nDouble, representan numeros decimales tanto positivos como negativos\n";
    cout << "valor1 = " << dbl1 << ", valor2 = " << dbl2 <<  "\n";
    cout << "valor1 * valor2 = " << resdbl1 << "\n";
    cout << "valor1 / valor2 = " << resdbl2 << "\n";
    cout << "valor2 - valor1 = " << resdbl3 << "\n";
    cout << "valor1 + valor2 = " << resdbl4 << "\n";
    */

    assert(dbl1 * dbl2);
    assert(dbl1 / dbl2);
    assert(dbl2 - dbl1);
    assert(dbl1 + dbl2);


    system("pause()");
    return 0;
}