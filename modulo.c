/*
 *       Archivo: modulo.c
 *       Autor: Nicolas Cifuentes Barriga <nicolas.cifuentes01@correo.usa.edu.co>
 *			   Santiago Gutierrez Orjuela <santiago.gutierrez02@correo.usa.edu.co>
 *			   Daniel Siachoque Peralta <daniel.siachoque01@correo.usa.edu.co>
 *			   Guillermo Torres Delgado <juan.torres01@correo.usa.edu.co>
 *       Ultima modificación: Marzo 13, 2021
 *       Sesión: Multiplicación de matrices clásica y transpuesta
 *-----------------------------------------------------------------------------------------------
 *
 *      RESUMEN:
 *      =======
 *      Este fichero de la aplicación (principal.c) presenta la vinculación con la interfaz
 *	    (interfaz.h) presentando las funciones completamente desarrolladas para su implementación
 *	    en los procesos presentes en la aplicación.
 *
 *      NOTA: Al seguir la estructura de programación modular, el funcionamiento de las funciones
 *      los encontrara en el fichero interfaz.h y el llamado de las mismas en principal.c
 */

#include "interfaz.h"
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <sys/time.h>

struct timeval start, end; //Structura para la toma de tiempo

void sample_start(){
	gettimeofday(&start,NULL); //Toma el tiempo de inicio de ejecución
}
void sample_stop(){
	gettimeofday(&end,NULL); //Toma el tiempo de final de ejecución
}
void sample_end(){ //Se presenta el calculo en microsegundos
	printf("Tiempo de ejecución: %ld microseg\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
}

void initMatriz(int N,double *A,double *B,double *C){
    int i,j; //Variables de iterazión
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            A[j+i*N] = 3.1*(j-i); //Genera dato en la matriz A
            B[j+i*N] = 4.1*(j+i); //Genera dato en la matriz B
            C[j+i*N] = 5.1;       //Genera dato en la matriz C los cuales seran alterados en la multiplicación
        }
    }
}

void initTranspose(int N,double *B,double *T){
    int i,j; //Variables de iterazión
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            T[j+i*N] = B[i+j*N]; //Genera la transpuesta de la matriz B
        }
    }
}

void impresion(int N, double *matriz){
    int i,j; //Variables de iterazión
    for (i = 0;i<N;i++){
        for (j = 0;j<N;j++){
            printf("%f \t",matriz[j+i*N]); //Imprime el valor en la casilla
        }
        printf("\n");
    }
}
