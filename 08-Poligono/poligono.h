#include <cstdint>
#include <array>

struct Color{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct Punto{
    double x;
    double y;
    bool empty = true;
};


struct Poligono{
    std::array <Punto, 10> puntos;
    Color color;
};


/********************************************************************************************************/
/*****************************************  PROTOTIPOS  *************************************************/
/********************************************************************************************************/

bool PuntoIsIgual(Punto, Punto);
double GetDistanciaPuntos(Punto, Punto);

bool AddVertice(Poligono&, Punto&);

Punto GetVertice(Poligono&, int);
bool SetVertice(Poligono&, int, Punto&);
bool RemoveVertice(Poligono&, int);
int GetCantidadLados(Poligono&);
double GetPerimetro(Poligono&);

