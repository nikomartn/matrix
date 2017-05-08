//Copyright (2017) Nicolás G Martín

 /*This file is part of Matrix library.

    Matrix library is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Matrix library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Matrix library.  If not, see <http://www.gnu.org/licenses/>.
    */
 
#ifndef COL__
#define COL__
#define COL 4
#endif

#ifndef STLIB_H__
#define STLIB_H__
#include <stdio.h>
#include <stdlib.h>
#endif

#ifndef LOCAL_H__
#define LOCAL_H__
#include "local.h"
#endif

typedef int Data;

//Primera estrategia

typedef struct BadMatrix{
	Data * pointer;
	int fil;
	int col;
}BadMatrix;
typedef BadMatrix * BadMatrixRef;


//Segunda estrategia
typedef struct UglyMatrix{
	Data (*pointer)[COL];
	int fil;
	int col;
}UglyMatrix;
typedef UglyMatrix * UglyMatrixRef;

//Tercera estrategia
typedef struct GoodMatrix{
	Data **pointer;
	int fil;
	int col;
}GoodMatrix;
typedef GoodMatrix * GoodMatrixRef;

//==========================================================================
//Explicación de la primera estrategia

/*se declara un puntero BadMatrixRef, que apuntará al struct BadMatrix. La matriz estará compuesta por un vector de Data, el cual tiene una dirección de referencia en BadMatrixRef->pointer al primer elemento. Las fil y col de la matriz se encuentran en el struct BadMatrix (Es lógico que si referencia a toda la matriz, sea éste el que contiene la información sobre esta.).*/

BadMatrixRef initBadMatrix (void);
void RdBadMatrix (BadMatrixRef m);
void PrBadMatrix (BadMatrixRef m);
void FrBadMatrix (BadMatrixRef m);
BadMatrixRef AddBadMatrix (BadMatrixRef A, BadMatrixRef B);
BadMatrixRef SubBadMatrix (BadMatrixRef A, BadMatrixRef B);
BadMatrixRef MulBadMatrix (BadMatrixRef A, BadMatrixRef B);

//==========================================================================
//Expliación de la seguna estrategia

/*Se declara un puntero UglyMatrixRef, que apuntará a UglyMatrix.
 * La matriz estará compuesta por vectores Data[COL]. El acceso puede realizarse de la misma forma que con las matrices estáticas. UglyMatrixRef->pointer[i][j]; Es obligatorio comprobar que col <= *COL ya que es imposible cambiar la constante en tiempo de ejecución
 */

UglyMatrixRef initUglyMatrix (void);
void RdUglyMatrix (UglyMatrixRef m);
void PrUglyMatrix (UglyMatrixRef m);
void FrUglyMatrix (UglyMatrixRef m);
UglyMatrixRef AddUglyMatrix (UglyMatrixRef A, UglyMatrixRef B);
UglyMatrixRef SubUglyMatrix (UglyMatrixRef A, UglyMatrixRef B);

//==========================================================================
//Explicación de a Tercera estrategia

/*Se declara un puntero GoodMatrixRef, que apuntará al struct GoodMatrix
 *GoodMatrix contiene, además de las dimensiones de la matriz, un puntero a un vector de punteros tipo Data, que apuntan a los vectores fila de la matriz. El acceso puede realizarse del mismo modo que con las matrices estáticas, GoodMatrixRef->pointer[i][j];
 */

GoodMatrixRef initGoodMatrix (void);
void RdGoodMatrix (GoodMatrixRef m);
void PrGoodMatrix (GoodMatrixRef m);
void FrGoodMatrix (GoodMatrixRef m);
GoodMatrixRef AddGoodMatrix (GoodMatrixRef a, GoodMatrixRef b);
GoodMatrixRef SubGoodMatrix (GoodMatrixRef a, GoodMatrixRef b);
