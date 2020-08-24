/*
    Bisiesto
    snlopez
    20200610
*/

#include <iostream>
#include <assert.h>

using namespace std;

bool IsBisiesto(int);

int main (){

    int year;
    bool res;
/*
    cout << "Ingrese un año";
    cin >> year;
    
    res = IsBisiesto(year);
    cout << res;
*/

    //assert(IsBisiesto(1248));
    //assert(IsBisiesto(1583));
    assert(IsBisiesto(2020));
    assert(IsBisiesto(2016));
    assert(IsBisiesto(1980));

    system("pause");

    return 0;
}

bool IsBisiesto(int year){
    return (year%4 == 0 ) and ((year%100 != 0) or (year%400 == 0)) and year>1582;
}
