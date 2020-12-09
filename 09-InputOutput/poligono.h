#include <cstdint>
#include <array>
#include <fstream>

using namespace std;

#define puntosMax 10
#define poligonosMax 4

struct Color{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
};

struct Punto{
    double x;
    double y;
    bool empty = true;
};


struct Poligono{
    std::array <Punto, puntosMax> puntos;
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

bool InsertarPoligonos(ofstream&, const Poligono&);
bool InsertarColor(ofstream&, const Color&);
bool InsertarPuntos(ofstream&, const Poligono&);
bool ExtraerPoligonos(ifstream& , std::array<Poligono,poligonosMax>&);
bool ExtraerUnPoligono(ifstream& , Poligono&);
bool ExtraerPuntos(ofstream&, std::array<Punto,puntosMax>&);
bool ExtraerUnPunto(ofstream&, Punto&);
bool ExtraerColor(ofstream&, Color&);