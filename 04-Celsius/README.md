# Celsius

## Objetivo
_Demostrar el manejo de funciones y valores punto flotante_

## Temas
* Funciones
* Tipo **double**
* División **entera y flotante**
* Pruebas con **assert**
* Argumentos con valor por defecto

## Problema
_Desarrollar una funcion que dada una magnitud en **Farehnheit**, calcule la equivalente en **Celsius**_

## Hipotesis
_Debe ser un año divisible por **4**_

_**NO** debe ser divisible por **100**, excepto por **400**_

_Debe ser posterior a **1582**_

## Restricciones
* Las pruebas deben realizarse con **assert**
* Los prototipos deben ser:
```
double Celsius(double);
bool AreNear(double, double, double = 0.001);
```

### Logica de la función
```
Celsius: R --> R / celsius(f) = 5/9 (f - 32)
```

## Resolucion
_Se creo un archivo **Celsius.cpp** en el cual se realizan varios pasajes de farehnheit a celsius mediante **assert**_

_Cada assert le pasará el año que se desea verifiar a la funcion **IsBisiesto()**_

_Se agregó un **system("pause()")** al final del programa para que al finalizar, este se detenga esperando que se presione una tecla cualquiera. De esta manera
sepodra visualizar mas facilmente si se produjo algun error (acusado por los assert) o si el programa finalizo correctamente_

## Herramientas empleadas
* Editor de texto **Visual Studio Code**
* Compilador **MinGW**
* **CMD** de Windows

### Implementacion
_Desde el **CMD** posicionarse dentro de la carpeta del proyecto_

_Compilar el **Celsius.cpp** y crear como salida el ejecutable **Celsius.exe**_
```
g++ Celsius.cpp -o Celsius.exe
```

_Ejecutar **Celsius.exe**_


### Modelo IPO

![imagen IPO](IPO.jpg)

### Arbol de expresión
![imagen arbol](arbol.jpg)