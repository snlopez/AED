/*
    Bisiesto
    snlopez
    20200610
*/

#include <iostream>

using namespace std;

bool IsBisiesto(int);

int main (){

    int year;
    bool res;

    cout << "Ingrese un año";
    cin >> year;
    
    res = IsBisiesto(year);
    cout << res;

    system("pause");

    return 0;
}

bool Isbisiesto(int year){
    return (year%4 == 0 ) and ((year%100 !=0) or (year%400 ==0)) and year>1582;
}
