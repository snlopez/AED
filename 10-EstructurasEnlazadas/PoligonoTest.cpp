#include "poligono.h"
#include <assert.h>


using namespace std;

int main(){
    Punto   p1 = {0,0},
            p2 = {0,1},
            p3 = {1,3.523},
            p4 = {1,0},
            p5 = {3,2};
    Poligono pol;
    
    AddVertice(pol, p1);
    AddVertice(pol, p2);
    AddVertice(pol, p3);
    AddVertice(pol, p4);
    AddVertice(pol, p5);

    //assert(true == 1);

    /*
    pol.AddVertice(p1);
    pol.AddVertice(p2);
    pol.AddVertice(p3);
    pol.AddVertice(p4);
    pol.AddVertice(p5);

    assert( 5 == pol.GetCantidadLados());
    assert( 13.67 == pol.GetPerimetro());

    pol.RemoveVertice(4);

    assert( 4 == pol.GetCantidadLados());
    assert( 8.23 == pol.GetPerimetro());

    pol.AddVertice({3,2});

    assert( 5 == pol.GetCantidadLados());
    assert( 13.67 == pol.GetPerimetro());

    pol.SetVertice({0,0}, 4);

    assert( 5 == pol.GetCantidadLados());
    assert( 8.23 == pol.GetPerimetro());

    */
    system("pause");
    return 0;
}