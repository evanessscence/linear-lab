#include <stdio.h>
#include <math.h>
#include "tinyexpr.h"
#include "tinyexpr.c"
#include <stdlib.h>

double epsilon;

// Definición de la función
double funcion(double x)
{
	/* Store variable names and pointers. */
    te_variable vars[] = {{"x", &x}};
    char expresion[100];
    FILE *fp;
    fp = fopen("funcion.txt", "r");
    fgets(expresion, 100, fp);
    fclose(fp);
    int err;
    /* Compile the expression with variables. */
    te_expr *expr = te_compile(expresion, vars, 1, &err);

    if (expr) {
        const double h1 = te_eval(expr); /* Returns 5. */
        te_free(expr);
    } else {
        printf("Error al evaluar la función > %d\n", err);
    }	
}

// Función para aproximar la derivada utilizando diferencias finitas hacia adelante
double aproximarDerivada(double (*funcion)(double), double x, double h) {
    return (funcion(x + h) - funcion(x)) / h;
}

int iter;

// Método de Newton-Raphson utilizando la aproximación de la derivada
double newtonRaphson(double x0, double epsilon, int maxIter) {
	FILE *archivo;
    double x = x0;
    iter = 0;

   // printf("\n%10s%15s%15s%15s%15s\n", "i", "x", "f(x)", "f'(x)","Error");
	archivo = fopen("tablaNewton.txt", "w");
    while (fabs(funcion(x)) > epsilon && iter < maxIter) {
        double derivada = aproximarDerivada(funcion, x, epsilon);
        double margenError = fabs(funcion(x)) - epsilon;

   //     printf("%10d%15lf%15lf%15lf%15lf\n", iter, x,funcion(x), derivada,  margenError);
	 	fprintf(archivo,"%d,%lf,%lf,%lf,%lf\n",iter,x,funcion(x),derivada,margenError);
    	
        x = x - funcion(x) / derivada;
        iter++;
    }
	fclose(archivo);
    return x;
}

int main() {

    
    FILE *a; // Mínimo
    double x0;
    a = fopen("a.txt", "r");
    fscanf(a, "%lf", &x0);
    fclose(a);
    
    FILE *e;
    e = fopen("e.txt", "r");
    fscanf(e, "%lf", &epsilon); // Tolerancia
    fclose(a);

    int maxIter = 100; // Número máximo de iteraciones

    double resultado = newtonRaphson(x0, epsilon, maxIter);
    
	FILE *result;
	result = fopen("resultado.txt", "w");
    if (fabs(funcion(resultado)) < epsilon) {
        fprintf(result, "\nLa solución aproximada es: %lf dada en %d iteraciones.\n", resultado, iter);
    } else {
        fprintf(result, "No se alcanzó la convergencia en %d iteraciones.\n", maxIter);
    }

    // Cerrar el archivo
    fclose(result);

    return 0;
}
