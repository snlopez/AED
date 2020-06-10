/*
    Bisiesto
    snlopez
    20200610
*/

#include <iostream>

using namespace std;

bool IsBisiesto(int);

int main (void){

int year;
    cout << "Ingrese un año";
    cin >> year;

    cout << IsBisiesto(year);

    return 0;
}

bool Isbisiesto(int year){
    return (year%4 == 0 ) and ((year%100 !=0) or (year%400 ==0)) and year>1582;
}
