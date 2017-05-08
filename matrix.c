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

#ifndef MATRIX_H__
#define MATRIX_H__
#include "matrix.h"
#endif


//BADMATRIX CODE:
//---------------------------------------------------------------------------------------------------------------------------------------

BadMatrixRef initBadMatrix
(void){
	/*initBadMatrix devuelve la dirección de memoria de un struct BadMatrix reservado dinámicamente. Además solicita el tamaño de la matriz a generar, construye dinámicamente un vector y guarda su dirección en el BadMatrix. Por lo tanto se tiene una referencia a un BadMatrix que contiene información de la matriz y una dirección al primer elemento de ésta.
	 En caso de error al reservar la matriz, la función libera el BadMatrix y devuelve una dirección a NULL*/
	
	
	BadMatrixRef root = NULL;
	
	//Se reserva en memoria BadMatrix
	if((root = malloc(sizeof(BadMatrix)))== NULL){
#ifdef DEBUG
		fprintf(stderr,"Error en reserva de memoria\n");
#endif
		return(NULL);
	}
	
	//Se almacena dimensiones de la matriz en BadMatrix
	
	lInDim(&(root->fil),&(root->col));
	
	//En caso de número negativo, se asume con positividad
	if(root->fil < 1)
		root->fil *= -1;
	if(root->col < 1)
		root->col *= -1;
	
	//Se reserva memoria de la matriz
	if(((root->pointer) = calloc((root->fil)*(root->col),sizeof(Data))) == NULL){
#ifdef DEBUG
		fprintf(stderr,"Error en reserva de memoria\n");
		free(root);
		return(NULL);
#endif
	}
	else{
		return(root);
	}
}

void RdBadMatrix
(BadMatrixRef ref){
	/*Generación de números random en la BadMatrix pasada por referencia*/
	
	int i, j;
	
	for(i = 0; i < (ref->fil); i++){
		for(j = 0; j < (ref->col); j++){
			ref->pointer[i* (ref->col) +j] = (rand() % 10); 
		}
	}
}

void PrBadMatrix
(BadMatrixRef ref){
	/*Impresión por pantalla de la BadMatrix pasada por referencia*/
	int i, j;
	
	for(i = 0; i < (ref->fil); i++){
		for(j = 0; j < (ref->col); j++){
			printf("%d\t",ref->pointer[i* (ref->col) +j]); 
		}
		puts("");
	}
}

BadMatrixRef AddBadMatrix
(BadMatrixRef a, BadMatrixRef b){
	/*Función que genera una nueva c BadMatrix resultado de la suma de las dos que recibe por referencia, en caso de error, se libera c y devuelve dirección NULL*/
	
	//A+B = C
	int i,j;
	
	BadMatrixRef c;
	
	//Se reserva Memoria para C
	
	if((c = malloc(sizeof(BadMatrix)))== NULL){
#ifdef DEBUG
		fprintf(stderr,"Error en reserva de memoria\n");
#endif
		return(NULL);
	}
	
	//Se comprueba que la suma pueda realizarse
	if(a->fil != b->fil || a->col != b->col){
		printf("Suma inoperable, distintas dimensiones\n");
		free(c);
		return(NULL);
	}
	
	//Se almacena dimensiones de la matriz en C
	
	c->fil = a->fil;
	c->col = a->col;
	
	//Se reserva memoria de la matriz
	if(((c->pointer) = calloc((c->fil)*(c->col),sizeof(Data))) == NULL){
#ifdef DEBUG
		fprintf(stderr,"Error en reserva de memoria\n");
#endif
		free(c);
		return (NULL);
	}
	else{
		//Se rellena la matriz con la suma de A+B
		for(i = 0; i < (c->fil); i++){
			for(j = 0; j < (c->col); j++){
				c->pointer[i* (c->col) +j] = a->pointer[i* (a->col) +j] + b->pointer[i* (b->col) +j];
			}
		}
	
		return(c);
	}
}

BadMatrixRef SubBadMatrix
(BadMatrixRef a, BadMatrixRef b){
	/*Función idéntica a AddBadMatrix pero con operación diferencia. Genera una nueva c BadMatrix resultado de la diferencia de las dos que recibe por referencia, en caso de error, se libera c y devuelve dirección NULL*/
	//A-B = C
	int i,j;
	
	BadMatrixRef c;
	
	//Se reserva Memoria para C
	
	if((c = malloc(sizeof(BadMatrix)))== NULL){
#ifdef DEBUG
		fprintf(stderr,"Error en reserva de memoria\n");
#endif
		return(NULL);
	}
	
	//Se comprueba que la resta pueda realizarse
	if(a->fil != b->fil || a->col != b->col){
		printf("Suma inoperable, distintas dimensiones\n");
		free(c);
		return(NULL);
	}
	
	//Se almacena dimensiones de la matriz en C
	
	c->fil = a->fil;
	c->col = a->col;
	
	//Se reserva memoria de la matriz
	if(((c->pointer) = calloc((c->fil)*(c->col),sizeof(Data))) == NULL){
#ifdef DEBUG
		fprintf(stderr,"Error en reserva de memoria\n");
#endif
		free(c);
		return(NULL);
		
	}
	else{
		//Se rellena la matriz con la resta de A-B
		for(i = 0; i < (c->fil); i++){
			for(j = 0; j < (c->col); j++){
				c->pointer[i* (c->col) +j] = a->pointer[i* (a->col) +j] - b->pointer[i* (b->col) +j];
			}
		}
	
		return(c);
	}
}

void FrBadMatrix
(BadMatrixRef ref){
	free(ref->pointer);
	free(ref);
}

//UGLYMATRIX CODE
//------------------------------------------------------------------------------------------------------------------------------------------

UglyMatrixRef initUglyMatrix 
(void){
	/*initUglyMatrix devuelve la dirección de memoria de un struct BadMatrix reservado dinámicamente. Además solicita el tamaño de la matriz a generar, construye dinámicamente un vector y guarda su dirección en el BadMatrix. Por lo tanto se tiene una referencia a un BadMatrix que contiene información de la matriz y una dirección al primer elemento de ésta.
	 En caso de error al reservar la matriz, la función libera el BadMatrix y devuelve una dirección a NULL*/
	
	UglyMatrixRef root = NULL;
	
	//Se reserva en memoria BadMatrix
	if((root = malloc(sizeof(UglyMatrix))) == NULL){
#ifdef DEBUG
		fprintf(stderr,"Error en reserva de memoria\n");
#endif
		return (NULL);
	}
	
	//Se almacena dimensiones de la matriz en BadMatrix
	
	
	lInDim(&(root->fil),NULL);
	//En caso de número negativo, se asume con positividad
	if(root->fil < 1){
		root->fil *= -1;
	}
	do{
		lInDim(NULL,&(root->col));
		//En caso de número negativo, se asume con positividad
		if(root->col < 1)
			root->col *= -1;
		if((root->col) > COL)
			printf("La matriz no puede tener más columnas que :%d\n",COL);
	}while((root->col) > COL);
	
	//Se reserva memoria de la matriz
	if (NULL == (root->pointer = malloc (root->fil * sizeof(Data[COL])))){
		/*Nótese que se reserva memoria para todo un vector de vectores [COL], pero el algoritmo ha de ser 
		 *inteligente y obviar las celdas de memoria inutilizadas COL-col*/
#ifdef DEBUG
		fprintf(stderr,"Error en reserva de memoria\n");
#endif
		free(root);
		return(NULL);
	}
	else{
		return(root);
	}
}

void RdUglyMatrix
(UglyMatrixRef ref){
	/*Generación de números random en la UglyMatrix pasada por referencia*/
	int i, j;
	
	for(i = 0; i < (ref->fil); i++){
		for(j = 0; j < (ref->col); j++){
			ref->pointer[i][j] = (rand() % 10); 
		}
	}
}

void PrUglyMatrix
(UglyMatrixRef ref){
	/*Impresión por pantalla de números en la BadMatrix pasada por referencia*/
	int i, j;
	
	for(i = 0; i < (ref->fil); i++){
		for(j = 0; j < (ref->col); j++){
			printf("%d\t",ref->pointer[i][j]); 
		}
		puts("");
	}
}

UglyMatrixRef AddUglyMatrix 
(UglyMatrixRef a, UglyMatrixRef b){
	/*Función que genera una nueva c BadMatrix resultado de la suma de las dos que recibe por referencia, 
	 *en caso de error, se libera c y devuelve dirección NULL*/
	
	UglyMatrixRef c; //C = A+B
	int i,j;
	
	//Se reserva Memoria para C
	
	if((c = malloc(sizeof(UglyMatrix))) == NULL){
#ifdef DEBUG
		fprintf(stderr,"Error en reserva de memoria\n");
#endif
		return(NULL);
	}
	
	//Se comprueba que la suma pueda realizarse
	if(a->fil != b->fil || a->col != b->col){
		printf("Suma inoperable, distintas dimensiones\n");
		free(c);
		return(NULL);
	}
	/*En caso de que la suma sea inoperable, queda a cargo del padre detener los posibles procesos posteriores (detectar NULL)*/
	
	//Se almacena dimensiones de la matriz en C
	
	c->fil = a->fil;
	c->col = a->col;
	
	//Se reserva mamoria para la matriz C
	
	if(NULL == (c->pointer = malloc ((c->fil)*sizeof(Data[COL])))){
#ifdef DEBUG
		fprintf(stderr,"Error en la asignaciń de memoria\n");
#endif
		free(c);
		return (NULL);
	}
	
	else{
		for(i=0; i< (c->fil);i++){
			for(j=0; j< (c->col); j++){
				c->pointer[i][j] = a->pointer[i][j] + b->pointer[i][j];
			}
		}
		return(c);
	}
	
}

UglyMatrixRef SubUglyMatrix 
(UglyMatrixRef a, UglyMatrixRef b){
	/*Función que genera una nueva c BadMatrix resultado de la diferencia de las dos que recibe por referencia, 
	 *en caso de error, se libera c y devuelve dirección NULL*/
	
	UglyMatrixRef c; //C = A+B
	int i,j;
	
	//Se reserva Memoria para C
	
	if((c = malloc(sizeof(UglyMatrix))) == NULL){
#ifdef DEBUG
		fprintf(stderr,"Error en reserva de memoria\n");
#endif
		return(NULL);
	}
	
	//Se comprueba que la suma pueda realizarse
	if(a->fil != b->fil || a->col != b->col){
		printf("Suma inoperable, distintas dimensiones\n");
		free(c);
		return(NULL);
	}
	/*En caso de que la suma sea inoperable, queda a cargo del padre detener los posibles procesos posteriores (detectar NULL)*/
	
	//Se almacena dimensiones de la matriz en C
	
	c->fil = a->fil;
	c->col = a->col;
	
	//Se reserva mamoria para la matriz C
	
	if(NULL == (c->pointer = malloc ((c->fil)*sizeof(Data[COL])))){
#ifdef DEBUG
		fprintf(stderr,"Error en la asignaciń de memoria\n");
#endif
		free(c);
		return (NULL);
	}
	
	else{
		for(i=0; i< (c->fil);i++){
			for(j=0; j< (c->col); j++){
				c->pointer[i][j] = a->pointer[i][j] - b->pointer[i][j];
			}
		}
		return(c);
	}
	
}

void FrUglyMatrix 
(UglyMatrixRef ref){
	free(ref->pointer);
	free(ref);
}

//GOODMATRIX CODE:
//----------------------------------------------------------------------------------------------------------------------------------------

GoodMatrixRef initGoodMatrix (void){
	/*initUglyMatrix devuelve la dirección de memoria de un struct BadMatrix reservado dinámicamente. Además solicita el tamaño de la matriz a generar, construye     dinámicamente un vector y guarda su dirección en el BadMatrix. Por lo tanto se tiene una referencia a un BadMatrix que contiene información de la matriz y una  dirección al primer elemento de ésta.
	 *En caso de error al reservar la matriz, la función libera el BadMatrix y devuelve una dirección a NULL*/
	
	GoodMatrixRef root;
	
	int i;
	
	//Se reserva memoria para GoodMatrix
	
	if(NULL == (root = malloc (sizeof(GoodMatrix)))){
#ifdef DEBUG
		fprintf(stderr,"Error en la asignación de memoria\n");
#endif
		return(NULL);
	}
	
	//Se leen las dimensiones de la matriz
	lInDim(&(root->fil),&(root->col));
	
	//Si las dimensiones son negativas, se asumen con positividad
	if((root->fil) < 1)
		root->fil *= -1;
	if((root->col) < 1)
		root->col *= -1;
	
	//Se reserva memoria para el vector de punteros
	if(NULL == (root->pointer = malloc(sizeof(Data*)*(root->fil)))){
#ifdef DEBUG
			fprintf(stderr,"Error en la asignación de memoria\n");
#endif
			free(root);
			return(NULL);
	
	}
	//Se reserva memoria para cada fila, del tamaño de col
	
	for(i = 0; i< (root->fil); i++){
		if(NULL == (root->pointer[i] = malloc(sizeof(Data)*(root->col)))){
#ifdef DEBUG
			fprintf(stderr,"Error en la asignación de memoria\n");
#endif
			FrGoodMatrix(root);
			return(NULL);
		}
	}
	
	
	return(root);
	
}

void RdGoodMatrix
(GoodMatrixRef ref){
	/*Generación de números random en la UglyMatrix pasada por referencia*/
	int i, j;
	
	for(i = 0; i < (ref->fil); i++){
		for(j = 0; j < (ref->col); j++){
			ref->pointer[i][j] = (rand() % 10); 
		}
	}
}

void PrGoodMatrix
(GoodMatrixRef ref){
	/*Impresión por pantalla de números de la GoodMatrix pasada por referencia*/
	int i, j;
	
	for(i = 0; i < (ref->fil); i++){
		for(j = 0; j < (ref->col); j++){
			printf("%d\t",ref->pointer[i][j]); 
		}
		puts("");
	}
}

GoodMatrixRef AddGoodMatrix 
(GoodMatrixRef a, GoodMatrixRef b){
	/*Función que genera una nueva c BadMatrix resultado de la suma de las dos que recibe por referencia, 
	 *en caso de error, se libera c y devuelve dirección NULL*/
	GoodMatrixRef c; //C = A+B
	int i,j;
	
	//Se reserva Memoria para C
	
	if((c = malloc(sizeof(GoodMatrix))) == NULL){
#ifdef DEBUG
		fprintf(stderr,"Error en reserva de memoria\n");
#endif
		exit(-1);
	}
	
	//Se comprueba que la suma pueda realizarse
	if(a->fil != b->fil || a->col != b->col){
		printf("Suma inoperable, distintas dimensiones\n");
		free(c);
		return(NULL);
	}
	/*En caso de que la suma sea inoperable, queda a cargo del padre detener los posibles procesos posteriores (detectar C->pointer == NULL)*/
	
	//Se almacena dimensiones de la matriz en C
	
	c->fil = a->fil;
	c->col = a->col;
	
	//Se reserva memoria para el vector C
	
	if(NULL == (c->pointer = malloc(sizeof(Data*)*(c->fil)))){
#ifdef DEBUG
			fprintf(stderr,"Error en la asignación de memoria\n");
#endif
			free(c);
			return(NULL);
	
	}
	//Se reserva memoria para cada fila, del tamaño de col
	
	for(i = 0; i< (c->fil); i++){
		if(NULL == (c->pointer[i] = malloc(sizeof(Data)*(c->col)))){
#ifdef DEBUG
			fprintf(stderr,"Error en la asignación de memoria\n");
#endif
			FrGoodMatrix(c);
			exit(-1);
		}
	}
	
	for(i=0; i< (c->fil);i++){
		for(j=0; j< (c->col); j++){
			c->pointer[i][j] = (a->pointer[i][j]) + (b->pointer[i][j]);
		}
	}
		return(c);
	
	
}

GoodMatrixRef SubGoodMatrix 
(GoodMatrixRef a, GoodMatrixRef b){
	/*Función que genera una nueva c BadMatrix resultado de la diferencia de las dos que recibe por referencia, 
	 *en caso de error, se libera c y devuelve dirección NULL*/
	GoodMatrixRef c; //C = A+B
	int i,j;
	
	//Se reserva Memoria para C
	
	if((c = malloc(sizeof(GoodMatrix))) == NULL){
#ifdef DEBUG
		fprintf(stderr,"Error en reserva de memoria\n");
#endif
		exit(-1);
	}
	
	//Se comprueba que la suma pueda realizarse
	if(a->fil != b->fil || a->col != b->col){
		printf("Suma inoperable, distintas dimensiones\n");
		free(c);
		return(NULL);
	}
	/*En caso de que la suma sea inoperable, queda a cargo del padre detener los posibles procesos posteriores (detectar C->pointer == NULL)*/
	
	//Se almacena dimensiones de la matriz en C
	
	c->fil = a->fil;
	c->col = a->col;
	
	//Se reserva memoria para el vector C
	
	if(NULL == (c->pointer = malloc(sizeof(Data*)*(c->fil)))){
#ifdef DEBUG
			fprintf(stderr,"Error en la asignación de memoria\n");
#endif
			free(c);
			return(NULL);
	
	}
	//Se reserva memoria para cada fila, del tamaño de col
	
	for(i = 0; i< (c->fil); i++){
		if(NULL == (c->pointer[i] = malloc(sizeof(Data)*(c->col)))){
#ifdef DEBUG
			fprintf(stderr,"Error en la asignación de memoria\n");
#endif
			FrGoodMatrix(c);
			exit(-1);
		}
	}
	
	for(i=0; i< (c->fil);i++){
		for(j=0; j< (c->col); j++){
			c->pointer[i][j] = (a->pointer[i][j]) - (b->pointer[i][j]);
		}
	}
		return(c);
	
	
}

void FrGoodMatrix (GoodMatrixRef ref){
	int i;
	
	for (i=0; i<(ref->fil); i++){
		free(ref->pointer[i]);
		free(ref->pointer);
		free(ref);
	}
}
