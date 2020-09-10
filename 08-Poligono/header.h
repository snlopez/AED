#include <iostream>
#include <cstdint>
#include <math.h>

using namespace std;

struct Color{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct Punto{
    float x;
    float y;
};

Color MezclarColor(Color color1, Color color2, int porcentajeColor1){
    Color res;
    res.r = ((color1.r * porcentajeColor1) + color2.r * (100 - porcentajeColor1))/100;
    res.g = ((color1.g * porcentajeColor1) + color2.g * (100 - porcentajeColor1))/100;
    res.b = ((color1.b * porcentajeColor1) + color2.b * (100 - porcentajeColor1))/100;
    return res;
}

Color SumarColor(Color color1, Color color2){
    Color res = {255,255,255};
    if(color1.r + color2.r <= 255){
        res.r = color1.r + color2.r;
    }
    if(color1.g + color2.g <= 255){
        res.g = color1.g + color2.g;
    }
    if(color1.b + color2.b <= 255){
        res.b = color1.b + color2.b;
    }
    return res;
}

Color RestarColor(Color color1, Color color2){
    Color res = {0,0,0};
    if(color1.r - color2.r >= 0){
        res.r = color1.r - color2.r;
    }
    if(color1.g - color2.g >= 0){
        res.g = color1.g - color2.g;
    }
    if(color1.b - color2.b >= 0){
        res.b = color1.b - color2.b;
    }

    return res;
}

Color GetComplementarioRGB(Color color){
    return {(uint8_t)~color.r, (uint8_t)~color.g, (uint8_t)~color.b};
}

string GetHtmlHexRGB(Color color){
    char res[7];
    
    sprintf(res, "#%02X%02X%02X", color.r, color.g, color.b);
    
    return  res;
}

const struct Color red = {255,0,0}, blue = {0,0,255}, green = {0,255,0}, cyan = SumarColor(blue, green), magenta = SumarColor(red, blue),
                yellow = SumarColor(red, green), black = RestarColor(red, yellow), white = SumarColor(red, cyan);

bool PuntoIsIgual(Punto a, Punto b){
    if(a.x == b.x && a.y == b.y){
       return true; 
    }
    return false;
};

float GetDistanciaPuntos(Punto a, Punto b){
    float res;
    res = (int) (sqrt( pow( (a.x - b.x), 2) +  pow( (a.y - b.y), 2) ) * 100 + 0.5);
    res = res/100;
    return res;
};

float GetDistanciaAlOrigen(Punto a){
    float res;
    res = (int) (sqrt( pow( (a.x), 2) +  pow( (a.y), 2) ) * 100 + 0.5);
    res = res/100;
    return res;
};

struct Triangulo{
    Punto p1;
    Punto p2;
    Punto p3;
    Color color;
    float base = p3.x - p1.x;
    float altura = p2.y - p1.y;
    float GetPerimetroTriangulo(){
        float p1p2, p1p3, p2p3, res;
        p1p2 = GetDistanciaPuntos(p1, p2);
        p1p3 = GetDistanciaPuntos(p1, p3);
        p2p3 = GetDistanciaPuntos(p2, p3);
        res = (int)( (p1p2 + p1p3 + p2p3) * 100 + 0.5 );

        return res/100;
    };
    float GetAreaTriangulo(){
        float base, h, res;
        Punto m;
        
        base = GetDistanciaPuntos(p1, p3);
        m.x = (p1.x + p3.x) / 2;
        m.y = (p1.y + p3.y) / 2;
        h = GetDistanciaPuntos(p2, m);
        res = (int) ( ((base * h) /2 ) * 100 + 0.5);
        
        return res /100;
    };
};

struct Poligono{
    vector<Punto> p;
    Color color;
    void AddVertice(Punto a){
        p.push_back(a);
    };
    Punto GetVertice(int posicion){
        if(posicion < p.size()){
            return p[posicion];
        }
        return {0.000001,0.000001};
    };
    bool SetVertice(Punto a, int posicion){
        if(posicion < p.size()){
            p[posicion] = a;
            return true;
        }
        return false;
    };
    bool RemoveVertice(int posicion){
        if(posicion < p.size()){
            p.erase(p.begin()+ posicion );
            return true;
        }
        return false;
    };
    int GetCantidadLados(){
        return p.size();
    };
    float GetPerimetro(){
        float res = 0;
        int i;

        if(p.size() > 0){
            res = GetDistanciaPuntos(p[0], p.back());
        
            for(i=0; i< (p.size() -1 ); i++){
                res += GetDistanciaPuntos(p[i], p[(i+1)]);
            }
        }
        return res;
    };
};




