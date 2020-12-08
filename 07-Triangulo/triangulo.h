#include <iostream>
#include <cstdint>
#include <math.h>

using namespace std;

/********************************************************************************************************/
/*****************************************  ESTRUCTURAS  ************************************************/
/********************************************************************************************************/

struct Color{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct Punto{
    double x;
    double y;
};

struct Triangulo{
    Punto a;
    Punto b;
    Punto c;
    Color color;
};


/********************************************************************************************************/
/*****************************************  PROTOTIPOS  *************************************************/
/********************************************************************************************************/

bool PuntoIsIgual(Punto, Punto);
double GetDistanciaPuntos(Punto, Punto);
double GetDistanciaAlOrigen(Punto);

double GetPerimetro (Triangulo);
double GetArea (Triangulo);
bool IsEscaleno (Triangulo);
bool IsEquilatero (Triangulo);
bool IsIsosceles (Triangulo);
string GetTipo (Triangulo);
Punto GetCentro (Triangulo);

