#include "triangulo.h"
#include <assert.h>


double GetDistanciaPuntos(Punto a, Punto b){
    double res;
    res = (int) (sqrt( pow( (a.x - b.x), 2) +  pow( (a.y - b.y), 2) ) * 100 + 0.5);
    res = res/100;
    return res;
};

double GetPerimetro (Triangulo t){
    double ab, ac, bc, res;
    ab = GetDistanciaPuntos(t.a, t.b);
    ac = GetDistanciaPuntos(t.a, t.c);
    bc = GetDistanciaPuntos(t.b, t.c);
    res = ab + ac + bc;

    return res;
}

double GetArea (Triangulo t){
    double ab, ac, bc, s, res;
    
    ab = GetDistanciaPuntos(t.a, t.b);
    ac = GetDistanciaPuntos(t.a, t.c);
    bc = GetDistanciaPuntos(t.b, t.c);
    s = (ab + ac + bc) / 2;
    res = (int)( sqrt(s * (s-ab) * (s-ac) * (s-bc) ) * 100 + 0.5);
    
    return res / 100;
};

bool IsEscaleno (Triangulo t){
    double ab, ac, bc;
    
    ab = GetDistanciaPuntos(t.a, t.b);
    ac = GetDistanciaPuntos(t.a, t.c);
    bc = GetDistanciaPuntos(t.b, t.c);
    if(ab != ac && ab != bc && ac != bc){
        return true;
    }
    return false;
}

bool IsEquilatero (Triangulo t){
    double ab, ac, bc;
    
    ab = GetDistanciaPuntos(t.a, t.b);
    ac = GetDistanciaPuntos(t.a, t.c);
    bc = GetDistanciaPuntos(t.b, t.c);

    if(ab == ac && ab == bc && ac == bc){
        return true;
    }
    return false;
}

bool IsIsosceles (Triangulo t){
    double ab, ac, bc;
    
    ab = GetDistanciaPuntos(t.a, t.b);
    ac = GetDistanciaPuntos(t.a, t.c);
    bc = GetDistanciaPuntos(t.b, t.c);
    
    if((ab == ac && ab != bc) || (ab == bc && ab != ac) || (ac == bc && ac != ab) ){
        return true;
    }
    return false;
}

string GetTipo (Triangulo t){
    if(IsEquilatero(t)){
        return "Equilatero";
    }
    if(IsEscaleno(t)){
        return "Escaleno";
    }
    if(IsIsosceles(t)){
        return "Isosceles";
    }
    return "error";
}

Punto GetCentro (Triangulo t){
    Punto c;
    c.x = (int)( ( (t.a.x + t.b.x + t.c.x) /3 ) * 100 + 0.5);
    c.y = (int)( ( (t.a.y + t.b.y + t.c.y) /3 ) * 100 + 0.5);

    c.x = c.x /100;
    c.y = c.y /100;

    return c;
}