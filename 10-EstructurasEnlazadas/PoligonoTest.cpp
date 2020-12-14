#include "poligono.h"
#include <assert.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    Punto   p1 = {0,0},
            p2 = {0,1},
            p3 = {1,3},
            p4 = {1,0},
            p5 = {3,2},
            p6 = {1,2},
            p7 = {2,1},
            p8 = {3,1},
            p9 = {2,3},
            p10 = {1,1},
            aux = {2,4};
    Poligono pol1, pol2, pol3, pol4;
    
    ifstream inFile;
    ofstream outFile;
    
    pol1.color = {12,25,35};
    pol1.next = &pol2;
    pol2.color = {0,255,235};
    pol2.next = &pol3;
    pol3.color = {122,125,135};
    pol3.next = &pol4;
    pol4.color = {142,245,5};
    pol4.next = NULL;

    assert(AddVertice(pol1, p1));
    assert(AddVertice(pol1, p2));
    assert(AddVertice(pol1, p3));
    assert(AddVertice(pol1, p4));
    assert(AddVertice(pol1, p5));
    assert(AddVertice(pol1, p6));
    assert(AddVertice(pol1, p7));
    assert(AddVertice(pol1, p8));
    assert(AddVertice(pol1, p9));
    assert(AddVertice(pol1, p10));
    
    assert(not( AddVertice(pol1, p7) ) );

    assert( p8.x == GetVertice(pol1, 2).x );//los vertices se guardan de atras hacia adelante como una pila
    assert( p8.y == GetVertice(pol1, 2).y );

    assert( SetVertice(pol1, 2, aux) );
    assert( not( SetVertice(pol1, 10, aux) ) );

    assert( p8.x != GetVertice(pol1, 2).x );//los vertices se guardan de atras hacia adelante como una pila
    assert( p8.y != GetVertice(pol1, 2).y );
    assert( aux.x == GetVertice(pol1, 2).x );//los vertices se guardan de atras hacia adelante como una pila
    assert( aux.y == GetVertice(pol1, 2).y );

    assert( 10 == GetCantidadLados(pol1));

    assert( RemoveVertice(pol1, 2));

    assert( 9 == GetCantidadLados(pol1));

    assert( 18.13 == GetPerimetro(pol1) );
    assert( RemoveVertice(pol1, 0));
    assert( 18.09 == GetPerimetro(pol1) );//ultimo perimetro de POL1

    assert(AddVertice(pol2, p9));
    assert(AddVertice(pol2, p3));
    assert(AddVertice(pol2, p4));
    assert(AddVertice(pol2, p6));

    assert(AddVertice(pol3, p1));
    assert(AddVertice(pol3, p2));
    assert(AddVertice(pol3, p3));

    assert(AddVertice(pol4, p3));
    assert(AddVertice(pol4, p4));
    assert(AddVertice(pol4, p5));
    assert(AddVertice(pol4, p6));
    assert(AddVertice(pol4, p9));

    assert( 7.41 == GetPerimetro(pol2) );
    assert( 6.4 == GetPerimetro(pol3) );
    assert( 10.24 == GetPerimetro(pol4) );

    outFile.open("todosLosPoligonos.txt");
    assert( InsertarPoligono( outFile, pol1) );
    assert( InsertarPoligono( outFile, pol2) );
    assert( InsertarPoligono( outFile, pol3) );
    assert( InsertarPoligono( outFile, pol4) );
    outFile.close();
    
    FiltrarPoligonosConPerimetroMayor(10, "todosLosPoligonos.txt", "poligonosFiltrados.txt");

    system("pause");
    return 0;
}