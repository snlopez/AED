#include "poligono.h"
#include <assert.h>
#include <iostream>


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
    Poligono pol;
    
    assert(AddVertice(pol, p1));
    assert(AddVertice(pol, p2));
    assert(AddVertice(pol, p3));
    assert(AddVertice(pol, p4));
    assert(AddVertice(pol, p5));
    assert(AddVertice(pol, p6));
    assert(AddVertice(pol, p7));
    assert(AddVertice(pol, p8));
    assert(AddVertice(pol, p9));
    assert(AddVertice(pol, p10));
    
    assert(not( AddVertice(pol, p7) ) );

    assert( p8.x == GetVertice(pol, 2).x );//los vertices se guardan de atras hacia adelante como una pila
    assert( p8.y == GetVertice(pol, 2).y );

    assert( SetVertice(pol, 2, aux) );
    assert( not( SetVertice(pol, 10, aux) ) );

    assert( p8.x != GetVertice(pol, 2).x );//los vertices se guardan de atras hacia adelante como una pila
    assert( p8.y != GetVertice(pol, 2).y );
    assert( aux.x == GetVertice(pol, 2).x );//los vertices se guardan de atras hacia adelante como una pila
    assert( aux.y == GetVertice(pol, 2).y );

    assert( 10 == GetCantidadLados(pol));

    assert( RemoveVertice(pol, 2));

    assert( 9 == GetCantidadLados(pol));

    assert( 18.13 == GetPerimetro(pol) );
    assert( RemoveVertice(pol, 0));
    assert( 18.09 == GetPerimetro(pol) );

    system("pause");
    return 0;
}