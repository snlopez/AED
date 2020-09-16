#include <assert.h>
#include <iostream>
#include "color.h"

int main(){
    Color   color1 = {63,0,191},
            color2 = {255,255,0},
            color3 = {25, 83, 125};
    
    assert( color1.r == MezclarColor(red,blue, 25).r);
    assert( color1.g == MezclarColor(red,blue, 25).g);
    assert( color1.b == MezclarColor(red,blue, 25).b);

    assert( color2.r == SumarColor(red, green).r );
    assert( color2.g == SumarColor(red, green).g );
    assert( color2.b == SumarColor(red, green).b );

    assert( cyan.r == RestarColor(white, red).r );
    assert( cyan.g == RestarColor(white, red).g );
    assert( cyan.b == RestarColor(white, red).b );
    
    assert(cyan.r == GetComplementarioRGB(red).r);
    assert(cyan.g == GetComplementarioRGB(red).g);
    assert(cyan.b == GetComplementarioRGB(red).b);


    assert("#FF0000" == GetHtmlHexRGB(red));
    assert("#19537D" == GetHtmlHexRGB(color3));
    

    system("pause");
    return 0;
    
}