//SPANISH - ESPAÑOL

#ifndef STLIB_H__
#define STLIB_H__
#include <stdio.h>
#include <stdlib.h>
#endif

/*Colección de funciones IO con frases para interfaz, para cambiar fácilmente el lenguaje, modifique las siquientes funciones*/

void lInDim(int * fil, int * col);	
/*Introdución de filas y columnas de una matriz, en caso de solo querer introducir una de las variables, utilizar NULL.
 *Ejemplo : lInDim(&fil,NULL);
 * */

