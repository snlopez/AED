#include <iostream>
#include <cstdint>

using namespace std;

/********************************************************************************************************/
/*****************************************  ESTRUCTURAS  ************************************************/
/********************************************************************************************************/

struct Color{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};


/********************************************************************************************************/
/*****************************************  PROTOTIPOS  *************************************************/
/********************************************************************************************************/

/*
Color MezclarColor(Color, Color, int);

Color SumarColor(Color, Color);

Color RestarColor(Color, Color);

Color GetComplementarioRGB(Color);

string GetHtmlHexRGB(Color);
*/

/********************************************************************************************************/
/******************************************  FUNCIONES  *************************************************/
/********************************************************************************************************/

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


/********************************************************************************************************/
/***************************************  VRIABLES GLOBALES  ********************************************/
/********************************************************************************************************/

const struct Color red = {255,0,0}, blue = {0,0,255}, green = {0,255,0}, cyan = SumarColor(blue, green), magenta = SumarColor(red, blue);
const struct Color yellow = SumarColor(red, green), black = RestarColor(red, yellow), white = SumarColor(red, cyan);


