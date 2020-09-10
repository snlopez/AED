# Color
## Objetivo
_Demostrar capacidad de construccion de tipos compuestos basados en tipos existentes atomicos_

## Temas
* Tipos
* Definicion de conjunto de valores con **struct**
* Tipos enteros de ancho fijo
* Variables externas
* Variables **const**

## Problema
Diseñar un tipo Color basado en el modelo RGB, con tres canales de 8 bits.
Todo color está compuesto por tres componentes: intensidad de red (rojo), de green (verde), y de blue (azul). Cada intensidad está en el rango [0, 255].
Definir los valores para rojo, azul, verde, cyan, magenta, amarillo, negro, y blanco. Dos colores se pueden mezclar, lo cual produce un nuevo color que tiene el promedio de intensidad para cada componente.

## Hipotesis
Se declarará un tipo **Color** compuesto por variables del tipo **uint8_t**,importando la libreria cstdint para su implementacion

Las variables se podrán mezclar mediante la funcion **Mezclar**. La misma recibirá los dos colores a mezclar y el porcentaje del primer color que se desea utilizar, por si no se desea que las proporciones sean iguales, y devolvera una variable del tipo **Color** con el color ya mezclado.

Cada uno de los canales del RGB deberan tener valores en el rango de [0, 255]

## Restricciones
* Las operaciones de proyeccion para red, green, y blue se implementan con acceso directo a los componentes, no es necesariodefinir getters especiales.
Por la misma razón, los setters no son necesarios.

* Utilizar el tipo **uint8_t** de **cstdint**, si no es posible, usar **unsigned char**

* Los colores primarios, secundarios, negro y blanco deben implementarse como ocho variables declaradas fuera del **main** y de tida funcin, con el calificador **const** para que no puedan modificarse

* Implementar IsIgual que retorna **true** si un color es igual a otro, si no, **false**.

## Creditos extra
* La operacion **Mezclar** mezcla en partes iguales: desarrollar una variante de la operacion que permita indicar las proporciones de las partes
* Desarrollar las operaciones **Sumar** y **Restar** que dados dos colores suma o resta la intensidad de cada canal, siempre dando resultados del rango [0, 255]. Utilizar estas operaciones para inicializar los colores secundarios, blanco y negro
* Desarrollar la operacion **GetComplementario** que dado un color obtiene el complementario u opuesto. Por ejemplo, el complementario del rojo es cyan.
* Desarrollar la operacion **GetHtmlHex** que genera un string con la representacion hexadecimal para HTML de un color. Por ejemplo, **assert("#0000ff" == GetHtmlHex(azul));
* Desarrollar la operacion **GetHtmlRgb** que genera un string con la representacion rgb para HTML de un color. Por ejemplo, **assert( "rgb(0, 0, 255)" == GetHtmlRbg(azul));
* Codificar la funcion **CrearSvgConTextoEscritoEnAltoContraste** que dado un nombre de archivo sin extension, un texto, y un color de letra genera un archivo SVG con el texto en un color y fondo en su complementario
* Responder en **readme.md** porque se debe usar **uint8_t** e indicar porque, si no es posible usar **uint8_t**, es correcto usar **unsigned char** y no **char**

```
Una de las condiciones del problema a resolver es que los colores se basan en en modelo RGB, con tres canales de **8 bits**.
Para poder cumplir esto, no se puede hacer con **int** ya que el mismo ocupa 16 bits, tampoco se puede hacer con **char**, ya que ocupa solo 4 bits.
Por eso lo correcto es usar el tipo de variable **uint8_t** ya que el mismo ocupa 8 bits. Si este ultimo no se pudiese usar por la version del compilador u otro factor, se podria reemplazar por **unsigned char**, el cual tambien ocupa 8 bits.
```