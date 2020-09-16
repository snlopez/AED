#include "poligono.h"
#include <math.h>


bool PuntoIsIgual(Punto a, Punto b){
    if(a.x == b.x && a.y == b.y){
       return true; 
    }
    return false;
};

double GetDistanciaPuntos(Punto a, Punto b){
    double res;
    int parcial;
    parcial = (sqrt( pow( (a.x - b.x), 2) +  pow( (a.y - b.y), 2) ) * 100 + 0.5);
    res = parcial;
    res = res/100;
    return res;
};

double GetDistanciaAlOrigen(Punto a){
    double res;
    int parcial;
    parcial = (sqrt( pow( (a.x), 2) +  pow( (a.y), 2) ) * 100 + 0.5);
    res = parcial/100;
    return res;
};