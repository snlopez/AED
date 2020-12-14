#include "poligono.h"
#include <math.h>
#include <iostream>
#include <sstream> // me permite utilizar extraer una linea del fichero y manejarla como un buffer en lugar de un string

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
    if(lados > 0 && lados <=2){
        return 1;
    }
    if(lados > 2){
        return lados;
    }
    return 0;
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

bool InsertarPoligono(ofstream& out, const Poligono& pol){
    InsertarColor(out, pol.color);
    InsertarPuntos(out, pol);
    return true;
}

bool InsertarColor(ofstream& out, const Color& c){
    out << static_cast <int> (c.r) << " " << static_cast <int> (c.g) << " " << static_cast <int> (c.b) ;
    return true;
}

bool InsertarPuntos(ofstream& out, const Poligono& p){
    int i = 0;

    for(i=0; i <  p.puntos.max_size(); i++){
        if( not(p.puntos[i].empty) ){
            out << " " << static_cast <int> (p.puntos[i].x * 100) << " " << static_cast <int> (p.puntos[i].y * 100) ;
        }
    }
    out << "/\n";
    return true;
}

bool ExtraerPoligonos(ifstream& in, std::array<Poligono,poligonosMax>& polArray){
    int i=0;
    if(in.good()){
        while ( not(in.eof()) && i < polArray.max_size()){
            ExtraerUnPoligono(in, polArray[i]);
            i++;
        }
        return true;
    }else{
        return false;   
    }
    
}

bool ExtraerUnPoligono(ifstream& in, Poligono& pol){
    
    ExtraerColor(in, pol.color);
    ExtraerPuntos(in, pol.puntos);
    return true;
}

bool ExtraerColor(ifstream& in, Color& c){
    int aux;
    if(in.good()){
        in >> aux;
        c.r = aux;
        in >> aux;
        c.g = aux;
        in >> aux;
        c.b = aux;
        return true;
    }else
    {
        return false;
    }
}

bool ExtraerPuntos(ifstream& in, std::array<Punto,puntosMax>& puntos){
    char aux;
    int i=0, num;
    
    do{
        in.get(aux);
        if( aux != '/' ){//leo todos los puntos restantes de la linea
            in >> num;
            puntos[i].x = num/100;
            
            in >> num;
            puntos[i].y = num/100;
            puntos[i].empty = false;

            i++;
        }
    }while(aux != '/' && i< puntos.max_size());
    return true;
}

void FiltrarPoligonosConPerimetroMayor(double perimetroMax, string fileIN, string fileOUT){
    array <Poligono, poligonosMax> pol;
    ifstream in;
    ofstream out;
    int i=0;

    in.open(fileIN);
    ExtraerPoligonos(in, pol);
    in.close();

    out.open(fileOUT);
    for(i=0; i< pol.max_size(); i++){
        if( GetPerimetro(pol[i]) > perimetroMax){
            InsertarPoligono(out, pol[i]);
        }
    }
    out.close();

}