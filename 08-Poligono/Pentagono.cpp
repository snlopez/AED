#include "header.h"
#include <assert.h>

struct Poligono{
    Punto p1;
    Punto p2;
    Punto p3;
    Punto p4;
    Punto p5;
    Color color;
    bool AddVertice(Punto a){
        if(a.x == 0 && a.y == 0){
            return true;
        }
        if(p1.x == 0 && p1.y == 0){
            p1 = a;
            return true;
        }
        if(p2.x == 0 && p2.y == 0){
            p2 = a;
            return true;
        }
        if(p3.x == 0 && p3.y == 0){
            p3 = a;
            return true;
        }
        if(p4.x == 0 && p4.y == 0){
            p4 = a;
            return true;
        }
        if(p5.x == 0 && p5.y == 0){
            p5 = a;
            return true;
        }
        return false;
    };
    Punto GetVertice(int vertice){
        switch(vertice){
            case 1:
                return p1;
            case 2:
                return p2;
            case 3:
                return p3;
            case 4:
                return p4;
            case 5:
                return p5;
        }
    };
    bool SetVertice(Punto p, int posicion){
        switch(posicion){
            case 1:
                p1 = p;
                return true;
            case 2:
                p2 = p;
                return true;
            case 3:
                p3 = p;
                return true;
            case 4:
                p4 = p;
                return true;
            case 5:
                p5 = p;
                return true;
        }
        return false;
    };
    bool RemoveVertice(int posicion){
        switch(posicion){
            case 1:
                p1 = {0,0};
                return true;
            case 2:
                p2 = {0,0};
                return true;
            case 3:
                p3 = {0,0};
                return true;
            case 4:
                p4 = {0,0};
                return true;
            case 5:
                p5 = {0,0};
                return true;
        }
        return false;
    };
    int GetCantidadLados(){
        int res=0;
        if(GetDistanciaPuntos(p1,p2) > 0){
            res ++;
        }
        if(GetDistanciaPuntos(p2,p3) > 0){
            res ++;
        }
        if(GetDistanciaPuntos(p3,p4) > 0){
            res ++;
        }
        if(GetDistanciaPuntos(p4,p5) > 0){
            res ++;
        }
        if(GetDistanciaPuntos(p5,p1) > 0){
            res ++;
        }
        return res;
    };
    float GetPerimetro(){
        float l1, l2, l3, l4, l5, res;
        l1 = GetDistanciaPuntos(p1,p2);
        l2 = GetDistanciaPuntos(p2,p3);
        l3 = GetDistanciaPuntos(p3,p4);
        l4 = GetDistanciaPuntos(p4,p5);
        l5 = GetDistanciaPuntos(p5,p1);
        res = (int) ( ( l1 + l2 + l3 + l4 + l5 ) * 100 + 0.5 );

        return res/100;
    };
};

int main(){
    Punto p1 = {0,0}, p2 = {0,1}, p3 = {1,3}, p4 = {1,0}, p5 = {3,2};
    Poligono pol1{p1, p2, p3, p4, p5, {102,205,18} };

    
    
    system("pause");
    return 0;
}