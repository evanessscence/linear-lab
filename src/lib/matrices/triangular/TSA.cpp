#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include<conio.h>
#include "archivo.h"
using namespace std;

const double epsilon = 1e-10;  // Pequeño valor para comparación con cero

void make_upper_triangular(vector<vector<double> >& matrix) {
    int fils = matrix.size();
    int cols = matrix[0].size() - 1;  // Excluimos la última columna

    // Realiza eliminación gaussiana para convertir en triangular superior
    for (int i = 0; i < fils - 1; ++i) {
        for (int k = i + 1; k < fils; ++k) {
            // Calcula el factor necesario para hacer cero la entrada debajo de la diagonal
            double factor = -matrix[k][i] / matrix[i][i];

            // Muestra las operaciones para hacer cero la entrada
            cout << "\n\nOperaciones para hacer la fila " << k + 1 << " cero en la columna " << i + 1 << ":" << endl;
            for (int j = i; j < cols; ++j) {
                // Calcula y muestra la operación
                cout << "   Fila " << k + 1 << "[" << j + 1 << "] = Fila " << k + 1 << "[" << j + 1 << "] + ("
                     << factor << ") * Fila " << i + 1 << "[" << j + 1 << "]" << endl;
                // Actualiza el valor de la celda en la matriz
                matrix[k][j] += factor * matrix[i][j];
            }
            cout << endl;
        }
    }
}


int main() {
	
    int fils, cols;
    abrirDimensiones(fils,cols);

    // Crea la matriz aumentada
    vector<vector<double> > matrix(fils, vector<double>(cols));
    leerMatriz(matrix);

    // Llama a la función para convertir en triangular superior
    make_upper_triangular(matrix);

    // Muestra la matriz aumentada triangular superior resultante
    cout << "\nMatriz aumentada triangular superior resultante:" << endl;
    for (int i = 0; i < fils; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
        // Mostrar el sistema de ecuaciones lineales y las soluciones
    cout << "\n\nSistema de ecuaciones lineales resultante:" << endl;
    for (int i = 0; i < fils; ++i) {
        bool allZero = true;
        bool hasSolution = true;
        for (int j = 0; j < cols - 1; ++j) {
            if (abs(matrix[i][j]) > epsilon) {
                allZero = false;
                if (hasSolution) {
                    cout << "x" << j+1 << " = " << matrix[i][cols - 1]/matrix[i][j];
                    hasSolution = false;
                } else {
                    cout << " = " << matrix[i][cols - 1]/matrix[i][j] << " - " << "x" << j + 1;
                }
            }
           
        }

        // Manejo de la última columna
        if ((abs(matrix[i][cols - 1]) > epsilon) && (allZero)) { // Si todas las entradas son 0 y la última columna es mayor a 0, entonces
        cout << "\nEl sistema es inconsistente." << endl;  // es una ariable sin solución
        exit(0);
        }
        
        if (abs(matrix[i][cols - 1]) < epsilon) { // Si todas las entradas son 0 y la última columna es 0, entonces
            if (allZero) {
                cout << "x" << i+1 <<" es libre";  // Variable libre
            } 
            }
        
        cout << endl;
    }
    guardarArchivo(matrix, "resultado.txt");
    getch();
    return 0;
}

