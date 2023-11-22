#include <iostream>
#include<vector>
#include<conio.h>
#include <fstream>
#include<windows.h>
using namespace std;

void abrirDimensiones(int &fil, int &col){
    ifstream filas("filas.txt");
    ifstream columnas("columnas.txt");
    filas >> fil;
    columnas >> col;
}

void leerMatriz(vector<vector<double>> &matriz) {
    ifstream file("matriz.txt");
    int filas = matriz.size();
    int columnas = matriz[0].size();
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            file >> matriz[i][j];
           
        }
    }
}

void guardarArchivo(vector<vector<double>> &matriz, string nombreArchivo) {
    ofstream file(nombreArchivo);
    int filas = matriz.size();
    int columnas = matriz[0].size();
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            file << matriz[i][j] << " ";
        }
        file << endl;
    }
}
// Función para calcular la determinante de una matriz 2x2
double calcularDeterminante2x2(const vector<vector<double>>& matriz) {
    return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
}

// Función para calcular la determinante de una matriz utilizando el método de cofactores
double calcularDeterminante(vector<vector<double>>& matriz) {
    int n = matriz.size();

    // Caso base: Matriz 1x1
    if (n == 1) {
        return matriz[0][0];
    }

    double determinante = 0.0;
    vector<vector<double>> submatriz(n - 1, vector<double>(n - 1));

    // Iterar a través de la primera fila para calcular el cofactor
    for (int i = 0; i < n; ++i) {
        // Construir la submatriz excluyendo la primera fila y la columna i
        for (int j = 1; j < n; ++j) {
            int col = 0;
            for (int k = 0; k < n; ++k) {
                if (k != i) {
                    submatriz[j - 1][col] = matriz[j][k];
                    col++;
                }
            }
        }

        // Calcular el cofactor y alternar el signo
        double cofactor = matriz[0][i] * calcularDeterminante(submatriz);
        if (i % 2 == 1) {
            cofactor = -cofactor;
        }

        determinante += cofactor;
    }

    return determinante;
}

int main() {
	
	FreeConsole();
    int n;
    abrirDimensiones(n,n);


    vector<vector<double>> matriz(n, vector<double>(n));
    leerMatriz(matriz);
    
	if (n==2)
	{
	calcularDeterminante2x2(matriz);
	}

    double determinante = calcularDeterminante(matriz);

    // Guardar determinante en un archivo .txt
    ofstream determinantearch("resultado.txt");
    
    if (n < 1) {
        determinantearch << "El tamaño de la matriz debe ser al menos 1x1." << endl;
        return 1;
    }
    
    determinantearch << "La determinante de la matriz es " << determinante;
    determinantearch.close();
    
    return 0;
}
