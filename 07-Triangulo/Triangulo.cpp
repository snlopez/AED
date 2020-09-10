#include <iostream>

using namespace std;

struct punto{
    unsigned x;
    unsigned y;
};

struct Triangulo{
    punto a;
    punto b;
    punto c;
    unsigned base = c.x - a.x;
    unsigned altura = b.y - a.y;
    unsigned GetPerimetro(){
        return;
    };
};




int main(){

}