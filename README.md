#Estrategias para la creación de matrices bidimensionales

OBJETIVOS:

	Para las 3 estrategias funciones:
	
	-> Generador de números aleatorios
	-> Reserva de memoria para crear una matriz
	-> Suma de matrices
	-> Resta de matrices
	-> Producto de matrices
	-> Liberación de matrices
	
	
Para ello:
	
	-> Estructura para cada elemento de la matriz 	/DONE
	
	-> Cronómetro para saber qué estrategia es mejor
	
	-> Crear biblioteca matrix.h/c					/DONE
	
#PRIMERA ESTRATEGIA
	
	TIPOBASE *PT
	
	typedef struct ? {
		? *data;
		int fil;
		int col;
	}?;
	
	A->m[(i*(A->col))+j];
	
	Se trata de un vector del cual, se han de establecer algoritmos para desplazarse por columnas virtuales. 
	
	//Se quiere acceder al elemento 4,2 por ejemplo. (columnas 8)
	
		A->m[2*8+4];
		
	-> Generador de números aleatorios 			\DONE
	-> Reserva de memoria para crear una matriz \DONE
	-> Suma de matrices							\DONE
	-> Resta de matrices						\DONE
	-> Liberación de matrices 					\DONE
		
#SEGUNDA ESTRATEGIA

	tipobase (*m)[COL];
	
	typedef struct ? {
		? *data[COL];
		int fil;
		int col;
	}?;
	
	Se trata de un vector de vectores, permite utilizar las expresiones habituales de matrices, 
	la desventaja es que el número de columnas es
	fijo.
	
	-> Generador de números aleatorios 			\DONE
	-> Reserva de memoria para crear una matriz \DONE
	-> Suma de matrices							\DONE
	-> Resta de matrices						\DONE
	-> Liberación de matrices 					\DONE
	
#TERCERA ESTRATEGIA

	tipobase **;
	
	Vector de punteros que apuntan a vectores
	
	typedef struct ?{
		? **data;
		int fil;
		int col;
	}?;
	
	acceso mediante ?->data[i][j]
	
	-> Generador de números aleatorios 			\DONE
	-> Reserva de memoria para crear una matriz \DONE
	-> Suma de matrices							\DONE
	-> Resta de matrices						\DONE
	-> Liberación de matrices 					\DONE
	
#Ideas posteriores para el proyecto:

	El algoritmo de las bibliotecas podría mejorarse con lo siguiente:
	
		Utilización de flags en compilación mediante definiciones para:
			Cronometrar o no el código y saber que matriz es más adecuada para cada programa
			Función que testee automáticamente cada caso, para decidir qué estratégia es mejor
		Mejora de la documentación de la biblioteca
				Bad								\DONE
				Ugly							\DONE
				Good							\DONE
		Inclusión de una biblioteca paralela con lenguaje para interfaz
												
				Bad								\DONE
				Ugly							\DONE
				Good							\DONE
