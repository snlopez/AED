#include <iostream>



int main(void){

}

struct Punto{
    double x;
    double y;
    char* prev;
    char* next;
};

struct Poligono{
    unsigned completos = 0;
    int length = sizeof(p) / sizeof(p[0]);
    void AddVertice(Punto a){
        //p.push_back(a);
        if(completos < length){
            p[completos] = a;
            completos = completos + 1;
        }
    };
    Punto GetVertice(int posicion){
        if(posicion < length){
            return p[posicion];
        }
        return {0.000001,0.000001};
    };
    bool SetVertice(Punto a, int posicion){
        if(posicion < length){
            p[posicion] = a;
            return true;
        }
        return false;
    };
    bool RemoveVertice(int posicion){
        int i = posicion;
        if(posicion < length){
            for(i; i < (length -1) ; i++){
                p[i] = p[(i+1)];
            }
            completos --;
            return true;
        }
        return false;
    };
    unsigned GetCantidadLados(){
        if(completos > 2){
            return completos;
        }
        return 1;
    };
    double GetPerimetro(){
        double res = 0;
        int i;

        if(completos > 2){
            res = GetDistanciaPuntos(p[0], p[(completos - 1)]);
        
            for(i=0; i< (completos -1 ); i++){
                res += GetDistanciaPuntos(p[i], p[(i+1)]);
            }
            
            return res;
        }

        return 0;
        
    };
};