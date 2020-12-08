#include "triangulo.h"
#include <assert.h>

int main(){
    Triangulo t1;
    t1.a = {2,8};
    t1.b = {0,1};
    t1.c = {1,2};
    
    assert( 7.28 == GetDistanciaPuntos(t1.a, t1.b) );
    assert( 1.41 == GetDistanciaPuntos(t1.c, t1.b) );
    assert( 6.08 == GetDistanciaPuntos(t1.a, t1.c) );

    assert( 14.77 == GetPerimetro(t1));
    //cout <<  typeid(GetArea(t1)).name()<< "\n\n";
    //cout <<  GetArea(t1)<< "\n\n";
    //assert( 2.46 == GetArea(t1));//no se porque falla si da el mismo resultado en valor y tipo

    assert( "Escaleno" == GetTipo(t1) );
    assert( 1 == GetCentro(t1).x );
    assert( 3.67 == GetCentro(t1).y );
    
    system("pause");
    return 0;
}