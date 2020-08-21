# Cpp Hello World

## Objetivo
_Demostrar con un programa simple, que se esta en capacidad de editar, compilar, y ejecutar un programa **C++**_

_Contar con las herramientas necesarias para abordar la resolución de los trabajos posteriores_

## Temas
* Sistema de control de versiones **GITHUB**
* Lenguaje de programacion **C++**
* Proceso de compilación
* Pruebas

## Resolucion
_Se creo un archivo **hello.cpp** el cual mostrara por una salida el mensaje **"Hello, World!"**_

## Herramientas empleadas
* Editor de tecto **Visual Studio Code**
* Compilador **MinGW**
* **CMD** de Windows

### Implementacion
_Desde el **CMD** posicionarse dentro de la carpeta del proyecto_

_Compilar el **hello.cpp** y crear como salida el ejecutable **hello.exe**_
```
g++ hello.cpp -o hello.exe
```

_Ejecutar **hello.exe** indicando la salida **output.txt**_
```
hello.exe > output.txt
```
_Si el archivo **output.txt** no existe, la linea anterior lo creará y guardará la salida de **hello.exe**_