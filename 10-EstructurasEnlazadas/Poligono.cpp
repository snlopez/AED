#include "poligono.h"
#include <math.h>


bool PuntoIsIgual(Punto a, Punto b){
    if(a.x == b.x && a.y == b.y){
       return true; 
    }
    return false;
}

double GetDistanciaPuntos(Punto a, Punto b){
    double res;
    int parcial;
    parcial = (sqrt( pow( (a.x - b.x), 2) +  pow( (a.y - b.y), 2) ) * 100 + 0.5);
    res = parcial;
    res = res/100;
    return res;
}

double GetDistanciaAlOrigen(Punto a){
    double res;
    int parcial;
    parcial = (sqrt( pow( (a.x), 2) +  pow( (a.y), 2) ) * 100 + 0.5);
    res = parcial/100;
    return res;
}


void AddVertice(Poligono& pol, Punto& p){
    
    Punto* aux = new Punto;

    if(pol.primerPunto == NULL){// entonces no tengo ningun punto guardado
        pol.primerPunto->x = p.x;
        pol.primerPunto->y = p.y;
        pol.primerPunto->next = NULL;
    }else{
        aux->x = p.x;
        aux->y = p.y;
        aux->next = pol.primerPunto;
        pol.primerPunto = aux;//muevo el primer punto a la primer posicion de la pila
    }
}