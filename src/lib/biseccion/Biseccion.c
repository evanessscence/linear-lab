#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include "tinyexpr.h"
#include "tinyexpr.c"

float E;

// PARSEA LA FUNCIÓN
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
        printf("Error al evaluar la expresión. Asegúrate de haber escrito la función correctamente.%d\n", err);
    }	
}

void biseccion(double a, double b) {
    FILE *resultado = fopen("resultado.txt", "w");
    if (funcion(a) * funcion(b) > 0) {
       // printf("No es posible utilizar el método de bisección porque f(a)*f(b) > 0. Asegúrate de haber incluido intervalos cercanos a la raíz y que ambos límites tengan el mismo signo.\n");
        fprintf(resultado, "f(a)*f(b) = 0. Asegúrate de haber incluido intervalos cercanos a la raíz y que ambos límites tengan el mismo signo. Es posible que esta función no tenga raíces.\n");
        fclose(resultado);
        return;
    }

    double c = a;
    int convergencia = 0;

    FILE *file = fopen("tabla.txt", "w");

    while ((b - a) >= E && (convergencia < 100)) {
        convergencia++;
        fprintf(file, "%d,%f,%f,%f,%f,%f,%f\n", convergencia, a, b, funcion(a), funcion(b), c, funcion(c));

        // Encuentra el punto medio
        c = (a + b) / 2;
        // Verifica si el punto medio es la ra�z
        if (funcion(c) == 0.0) {
            printf("El punto medio no es la raíz (%f)\n", funcion(c));
            break;
        }

        // Decide el lado para repetir los pasos
        else if (funcion(c) * funcion(a) < 0)
            b = c;
        else
            a = c;
    }

    fclose(file);

    if (convergencia == 100) {
        printf("No se encontró la solución en %d iteraciones.\n", convergencia);
        fprintf(resultado, "No se encontró la solución en %d iteraciones.\n", convergencia);
        fclose(resultado);
        return;
    }

    printf("\n> La raíz es: %f\n", c);
    printf("> El método converge a %d iteraciones.\n", convergencia);
    fprintf(resultado, "\n> La raíz es: %f\n> El método converge a %d iteraciones.\n", c, convergencia);
    fclose(resultado);
}

int main() {
    FILE *at = fopen("a.txt", "r");
    FILE *bt = fopen("b.txt", "r");
    FILE *et = fopen("e.txt", "r");

    if (at == NULL || bt == NULL || et == NULL) {
        perror("Error al abrir los archivos de entrada");
        return 1;
    }

    float a, b;

    fscanf(at, "%f", &a);
    fscanf(bt, "%f", &b);
    fscanf(et, "%f", &E);

    fclose(at);
    fclose(bt);
    fclose(et);

    biseccion(a, b);
	getch();
    return 0;
}

