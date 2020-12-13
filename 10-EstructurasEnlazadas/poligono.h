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
    Punto* next;
};


struct Poligono{
    Punto primerPunto;
    Color color;
    Poligono* next;
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

bool InsertarPoligono(ofstream&, const Poligono&);//aca
bool InsertarColor(ofstream&, const Color&);
bool InsertarPuntos(ofstream&, const Poligono&);
bool ExtraerPoligonos(ifstream& , Poligono&);
bool ExtraerUnPoligono(ifstream& , Poligono&);
bool ExtraerColor(ifstream&, Color&);
bool ExtraerPuntos(ifstream&, Punto&);
void FiltrarPoligonosConPerimetroMayor(double, string, string);
