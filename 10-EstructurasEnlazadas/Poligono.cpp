#include "poligono.h"
#include <math.h>
#include <iostream>
#include <sstream> // me permite utilizar extraer una linea del fichero y manejarla como un buffer en lugar de un string
#include <assert.h>

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

bool AddVertice(Poligono& pol, Punto& p){
    Punto* aux = NULL;

    if( pol.empty ){
        pol.primerPunto = p;
        pol.primerPunto.next = aux;
        pol.empty = false;
    }else{
        aux = &pol.primerPunto;
        while(aux != NULL){
            if(aux->x == p.x && aux->y == p.y){
                return false;//ya existe el punto
            }else{
                aux = aux->next;
            }
        }
        aux = new Punto;
        //si llego aca es porque no hay un punto igual cargado
        aux->x = pol.primerPunto.x;
        aux->y = pol.primerPunto.y;
        aux->next = pol.primerPunto.next;
        pol.primerPunto = p;
        pol.primerPunto.next = aux;
    }
    return true;
}

Punto GetVertice(Poligono& pol, int n){
    Punto* aux = &pol.primerPunto;
    Punto vacio;
    int i = 0;

    while(aux != NULL && i <= n){
        if(i == n){
            return *aux;
        }
        i++;
        aux = aux->next;
    }
    assert(false);
}

bool SetVertice(Poligono& pol, int n, Punto& p){
    int i = 0;
    Punto* aux = &pol.primerPunto;
    while(aux != NULL && i <= n){
        if(i == n){
            aux->x = p.x;
            aux->y = p.y;
            return true;
        }
        aux = aux->next;
        i++;
    }
    return false;
    
}

bool RemoveVertice(Poligono& pol, int n){
    Punto* aux = &pol.primerPunto;
    Punto* rmv;
    int i = 0;

    if(n == 0){
        pol.primerPunto = *pol.primerPunto.next;
        return true;
    }else{
        while(aux != NULL && i < n){
            if( (i + 1) == n){
                rmv = aux->next;
                aux->next = aux->next->next;
                delete rmv;
                return true;
            }
            aux = aux->next;
            i++;
        }
    }
    return false;
}

int GetCantidadLados(Poligono& pol){
    int lados=0;
    Punto* aux = &pol.primerPunto;
    
    while(aux != NULL){
        aux = aux->next;
        lados++;
    }
    if(lados > 2){
        return lados;
    }else{
        return 0;
    }
    
}

void FiltrarPoligonosConPerimetroMayor(double perimetroMax, string fileIN, string fileOUT){
    Poligono pol;
    Poligono* aux = &pol;
    ifstream in;
    ofstream out;
    
    in.open(fileIN);
    ExtraerPoligonos(in, pol);
    in.close();

    /*
    while(aux != NULL){
        cout << "Leo un poligono\n";
        cout << aux->color.r << "\n";
        aux = aux->next;
    }*/

    aux = &pol;

    out.open(fileOUT);
    while(aux != NULL){
        if( GetPerimetro(*aux) > perimetroMax){
            InsertarPoligono(out, *aux);
        }
        aux = aux->next;
    }
    out.close();
}

bool ExtraerPoligonos(ifstream& in, Poligono& pol){
    Poligono* aux;
    Poligono* auxPOL = NULL;
    char c;

    if(in.good()){
        while ( not(in.eof()) ){
            aux = new Poligono;
            ExtraerUnPoligono(in, *aux);
            aux->next = auxPOL;
            auxPOL = aux;
            in.get(c);//tomo el \n para quedar en el oef
        }
        pol = *auxPOL;
        return true;
    }else{
        return false;
    }
}

bool ExtraerUnPoligono(ifstream& in, Poligono& pol){
    ExtraerColor(in, pol.color);
    ExtraerPuntos(in, pol.primerPunto);
    if(in.good()){
        return true;
    }
    return false;
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
    }else{
        return false;
    }
}

bool ExtraerPuntos(ifstream& in, Punto& primerP){
    char c;
    int num;
    Punto* p;
    Punto* aux = NULL;
    
    do{
        in.get(c);
        if( c != '/' && not(in.eof()) ){//leo todos los puntos restantes de la linea
            p = new Punto;
            in >> num;
            p->x = num/100;
            
            in >> num;
            p->y = num/100;
            p->next = aux;
            aux = p;
            
        }
    }while(c != '/' && not(in.eof()) );
    primerP = *p;
    if(in.good()){
        return true;
    }
    return false;
}

bool InsertarPoligono(ofstream& out, const Poligono& pol){
    InsertarColor(out, pol.color);
    InsertarPuntos(out, pol);
    out << "/";
    if(out.good()){
        return true;
    }
    return false;
}

bool InsertarColor(ofstream& out, const Color& c){
    out << "\n" << static_cast <int> (c.r) << " " << static_cast <int> (c.g) << " " << static_cast <int> (c.b) ;
    if(out.good()){
        return true;
    }
    return false;
}

bool InsertarPuntos(ofstream& out, const Poligono& p){
    Punto primerP = p.primerPunto;
    Punto* aux = &primerP;

    while(aux != NULL){
        out << " " << static_cast <int> (aux->x * 100) << " " << static_cast <int> (aux->y * 100) ;
        aux = aux->next;
    }
    if(out.good()){
        return true;
    }
    return false;
}

double GetPerimetro(Poligono& pol){
    double dist = 0;
    Punto* aux = &pol.primerPunto;
    
    while(aux != NULL){
        if(aux->next != NULL){
            dist += GetDistanciaPuntos(*aux, *(aux->next) );
        }else
        {
            dist += GetDistanciaPuntos(*aux, pol.primerPunto );
        }
        aux = aux->next;
    }
    return dist;
}