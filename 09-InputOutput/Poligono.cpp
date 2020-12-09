#include "poligono.h"
#include <math.h>
#include <iostream>

using namespace std;

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


bool AddVertice(Poligono& pol, Punto& p){
    int i, emptyPoss = pol.puntos.max_size();
    for(i=0; i< pol.puntos.max_size(); i++){
        if(not(pol.puntos[i].empty)){
            if( PuntoIsIgual(pol.puntos[i], p) ){
                return false;//si encuentro un punto que coincida no lo guardo y devuelvo false
            }
        }else{
            emptyPoss = i;
        }
    }
    if(emptyPoss != pol.puntos.max_size()){//si el punto no esta repetido y hay una posicion vacia la guardo ahi
        pol.puntos[emptyPoss].empty = false;
        pol.puntos[emptyPoss].x = p.x;
        pol.puntos[emptyPoss].y = p.y;
        return true;
    }else{
        return false;    
    }
}

Punto GetVertice(Poligono& pol, int n){
    Punto aux;
    if(n < pol.puntos.max_size() && not(pol.puntos[n].empty) ){
        return pol.puntos[n];
    }else{
        return aux;
    }   
}

bool SetVertice(Poligono& pol, int n, Punto& p){
    if(n < pol.puntos.max_size()){
        pol.puntos[n].x = p.x;
        pol.puntos[n].y = p.y;
        pol.puntos[n].empty = false;
        return true;
    }else{
        return false;
    }
}

bool RemoveVertice(Poligono& pol, int n){
    if(n < pol.puntos.max_size()){
        pol.puntos[n].empty = true;
        return true;
    }else{
        return false;
    }
}

int GetCantidadLados(Poligono& pol){
    int i, lados=0;
    for(i=0; i< pol.puntos.max_size(); i++){
        if(not(pol.puntos[i].empty) ){
            lados++;
        }
    }
    return lados;
}

double GetPerimetro(Poligono& pol){
    int i, lastNoEmpty = -1, firstNoEmpty = -1;
    double dist = 0;
    
    for(i=0; i< pol.puntos.max_size(); i++){
        if(not(pol.puntos[i].empty) ){
            lastNoEmpty = i;
            firstNoEmpty = i;
            i = pol.puntos.max_size();
        }
    }

    if(firstNoEmpty != (-1) ){//si encuentro alguno no vacio, calculo las distancias
        for(i=lastNoEmpty; i< (pol.puntos.max_size() - 1); i++){
            if( not(pol.puntos[(i + 1)].empty) ){
                dist += GetDistanciaPuntos(pol.puntos[lastNoEmpty], pol.puntos[i+1]);
                lastNoEmpty = i + 1;
            }
        }

        dist += GetDistanciaPuntos(pol.puntos[firstNoEmpty], pol.puntos[lastNoEmpty]);    
    }
    
    return dist;
}

bool InsertarPoligonos(ofstream& out, const Poligono& pol){
    InsertarColor(out, pol.color);
    InsertarPuntos(out, pol);
    
    return true;
}

bool InsertarColor(ofstream& out, const Color& c){
    out << static_cast <int> (c.r) << " " << static_cast <int> (c.g) << " " << static_cast <int> (c.b) << " ";
    return true;
}

bool InsertarPuntos(ofstream& out, const Poligono& p){
    int i = 0;

    for(i=0; i <  p.puntos.max_size(); i++){
        if( not(p.puntos[i].empty) ){
            out << "(" << p.puntos[i].x << "," << p.puntos[i].y << ") ";
        }
    }
    out << "\n";
    return true;
}

bool ExtraerPoligonos(ifstream& in, std::array<Poligono,4>& polArray){
    int i = 0;
    for(i; i< polArray.max_size(); i++){
        ExtraerUnPoligono(in, polArray[i]);
    }
    return true;
}
bool ExtraerUnPoligono(ifstream& in, Poligono& pol){
    
    return true;
}