#include "tinyexpr.h"
#include "tinyexpr.c"
#include <stdio.h>
#include <stdlib.h>

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
        printf("R:%f\n", h1);
        te_free(expr);
    } else {
        printf("Parse error at %d\n", err);
    }

	
}

int main(int argc, char *argv[])
{

	funcion(2);
    return 0;
}
