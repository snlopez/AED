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
    std::array <Poligono, poligonosMax> pol, polIN;
    
    ifstream inFile;
    ofstream outFile;
    
    assert(AddVertice(pol[0], p1));
    assert(AddVertice(pol[0], p2));
    assert(AddVertice(pol[0], p3));
    assert(AddVertice(pol[0], p4));
    assert(AddVertice(pol[0], p5));
    assert(AddVertice(pol[0], p6));
    assert(AddVertice(pol[0], p7));
    assert(AddVertice(pol[0], p8));
    assert(AddVertice(pol[0], p9));
    assert(AddVertice(pol[0], p10));
    
    assert(not( AddVertice(pol[0], p7) ) );

    assert( p8.x == GetVertice(pol[0], 2).x );//los vertices se guardan de atras hacia adelante como una pila
    assert( p8.y == GetVertice(pol[0], 2).y );

    assert( SetVertice(pol[0], 2, aux) );
    assert( not( SetVertice(pol[0], 10, aux) ) );

    assert( p8.x != GetVertice(pol[0], 2).x );//los vertices se guardan de atras hacia adelante como una pila
    assert( p8.y != GetVertice(pol[0], 2).y );
    assert( aux.x == GetVertice(pol[0], 2).x );//los vertices se guardan de atras hacia adelante como una pila
    assert( aux.y == GetVertice(pol[0], 2).y );

    assert( 10 == GetCantidadLados(pol[0]));

    assert( RemoveVertice(pol[0], 2));

    assert( 9 == GetCantidadLados(pol[0]));

    assert( 18.13 == GetPerimetro(pol[0]) );
    assert( RemoveVertice(pol[0], 0));
    assert( 18.09 == GetPerimetro(pol[0]) );//ultimo perimetro de POL

    assert(AddVertice(pol[1], p9));
    assert(AddVertice(pol[1], p3));
    assert(AddVertice(pol[1], p4));
    assert(AddVertice(pol[1], p6));

    assert(AddVertice(pol[2], p1));
    assert(AddVertice(pol[2], p2));
    assert(AddVertice(pol[2], p3));

    assert(AddVertice(pol[3], p3));
    assert(AddVertice(pol[3], p4));
    assert(AddVertice(pol[3], p5));
    assert(AddVertice(pol[3], p6));
    assert(AddVertice(pol[3], p9));

    assert( 7.41 == GetPerimetro(pol[1]) );
    assert( 6.4 == GetPerimetro(pol[2]) );
    assert( 10.24 == GetPerimetro(pol[3]) );

    outFile.open("todosLosPoligonos.txt");
    assert( InsertarPoligonos( outFile, pol[0]) );
    assert( InsertarPoligonos( outFile, pol[1]) );
    assert( InsertarPoligonos( outFile, pol[2]) );
    assert( InsertarPoligonos( outFile, pol[3]) );
    outFile.close();

    inFile.open("todosLosPoligonos.txt");

    assert(ExtraerPoligonos(inFile, polIN));

    system("pause");
    return 0;
}