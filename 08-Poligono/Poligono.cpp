#include "header.h"
#include <assert.h>
#include <vector>


int main(){
    Punto p1 = {0,0}, p2 = {0,1}, p3 = {1,3.523}, p4 = {1,0}, p5 = {3,2};
    Poligono pol;
    pol.p = {p1, p2, p3, p4, p5};
    
    assert( 5 == pol.GetCantidadLados());
    assert( (float) 13.67 == pol.GetPerimetro());

    pol.RemoveVertice(4);

    assert( 4 == pol.GetCantidadLados());
    assert( (float) 8.23 == pol.GetPerimetro());

    pol.AddVertice({3,2});

    assert( 5 == pol.GetCantidadLados());
    assert( (float) 13.67 == pol.GetPerimetro());

    pol.SetVertice({0,0}, 4);

    assert( 5 == pol.GetCantidadLados());
    assert( (float) 8.23 == pol.GetPerimetro());

    
    system("pause");
    return 0;
}