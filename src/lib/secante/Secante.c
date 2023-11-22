#include <stdlib.h>
#include <math.h>
#include "tinyexpr.h"
#include "tinyexpr.c"
#include <stdio.h>

double f(double x)
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
        printf("Error al evaluar la función. %d\n", err);
    }	
}

const int ITERACIONES_MAXIMAS = 100;

int main (void)
{
    double x0, x1, temp, err, TOLERANCIA;
    
    FILE *xo; // Mínimo
    xo = fopen("a.txt", "r");
    fscanf(xo, "%lf", &x0);
    fclose(xo);
    
    FILE *xi; // Max
    xi = fopen("b.txt", "r");
    fscanf(xi, "%lf", &x1);
    fclose(xi);
    
    FILE *tol; // tolerancia
    tol = fopen("e.txt", "r");
    fscanf(tol, "%lf", &TOLERANCIA);
    fclose(tol);
    
        if (xo == NULL || xi == NULL || tol == NULL) {
        perror("Error al abrir los archivos de entrada");
        return 1;
    }
    int n = 1;
	
	FILE *tabla;
	tabla = fopen("tablaSecante.txt","w");

    do {
        err = fabs(x0-x1);
        fprintf (tabla,"%d,%g,%g,%g,%g,%lf\n", n, x0,f(x0),x1,f(x1),err);
        if (err!=0)
        {
            temp = x1;
            x1 = x1 - (x1 - x0) * f(x1) / (f(x1) - f(x0));
            x0 = temp;
        }
        n++;
    } while (err>TOLERANCIA && n<=ITERACIONES_MAXIMAS);
    putchar ('\n');
    
    fclose(tabla);
    
    FILE *resultado;
	resultado = fopen("resultado.txt","w");
	
    if (n<ITERACIONES_MAXIMAS)
    {
        fprintf (resultado,"La primera raíz encontrada está en %g", x1);
	}
        
    else {
   fprintf (resultado,"No se encontr\242 la ra\241z. Intenta cambiar las aproximaciones iniciales.");   
	}

    fclose(resultado);

    return EXIT_SUCCESS;
}