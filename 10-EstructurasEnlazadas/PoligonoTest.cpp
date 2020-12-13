#include "poligono.h"
#include <assert.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    ifstream inFile;
    ofstream outFile;
    
    FiltrarPoligonosConPerimetroMayor(10, "todosLosPoligonos.txt", "poligonosFiltrados.txt");

    system("pause");
    return 0;
}