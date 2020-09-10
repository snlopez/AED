#include "header.h"
#include <assert.h>




int main(){
    Punto p1 = {0,3}, p2 = {2,8}, p3 = {4,0}, p4 = {2,8};
    float buffer;
    assert(false == PuntoIsIgual(p1, p2));
    assert(PuntoIsIgual(p2, p4));
        
    assert( 0 == GetDistanciaPuntos(p2, p2) );
    assert( (float)5.39 == GetDistanciaPuntos(p1, p2) );

    assert( 3 == GetDistanciaAlOrigen(p1) );
    assert( (float)8.25 == GetDistanciaAlOrigen(p2) );

    system("pause");
    return 0;
}

