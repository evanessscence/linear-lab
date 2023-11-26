#include <iostream>
#include <vector>
#include <fstream>

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
    ofstream file(nombreArchivo,std::ios::app);
    int filas = matriz.size();
    int columnas = matriz[0].size();
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            file << matriz[i][j] << " ";
        }
        file << endl;
    }
}
// Función para imprimir una matriz
void imprimirMatriz(vector<vector<double>>& matriz) {
	ofstream file("resultado.txt",std::ios::app);
    int filas = matriz.size();
    int columnas = matriz[0].size();

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            file << matriz[i][j] << " ";
        }
        file << endl;
        
    }
}

// Función para realizar la eliminación Gaussiana y obtener la RREF de la matriz aumentada
int obtenerRREF(vector<vector<double>>& matrizAumentada) {
ofstream archivo("resultado.txt",std::ios::app);
  int filas = matrizAumentada.size();
    int columnas = matrizAumentada[0].size();
    int numPivotes = 0;

	archivo << "Realizar la eliminación Gaussiana para obtener la matriz identidad.";
     for (int i = 0; i < filas; i++) {
        // Encontrar la fila con el valor máximo en la columna actual
        int filaMax = i;
        for (int k = i + 1; k < filas; k++) {
            if (abs(matrizAumentada[k][i]) > abs(matrizAumentada[filaMax][i])) {
                filaMax = k;
            }
            archivo << "- Encontrar la fila con el valor máximo en la columna actual. La fila encontrada es F"<<filaMax<<endl<<matrizAumentada[i][i] << " "<<endl<<endl;
        }
		  
        // Intercambiar filas para tener el valor máximo en la fila actual
        if (filaMax != i) {
            swap(matrizAumentada[i], matrizAumentada[filaMax]);
            archivo << "- Intercambiar filas para tener el valor máximo en la fila actual. F"<<i<<"-> F"<<filaMax<<endl<<matrizAumentada[i][i] << " "<<endl<<endl;
        }

        // Verificar si el elemento diagonal principal es un pivote
        if (matrizAumentada[i][i] != 0) {
            numPivotes++;
             archivo << "- Verificar si el elemento diagonal principal es distinto a 0 para ser un pivote. ("<<matrizAumentada[i][i]<<")"<<endl<<matrizAumentada[i][i] << " "<<endl<<endl;
        }

        // Hacer que el elemento diagonal principal sea igual a 1
        double pivot = matrizAumentada[i][i];
        if (pivot != 0) {
            for (int j = i; j < columnas; j++) {
                matrizAumentada[i][j] /= pivot;
                 archivo << "- Hacer que el elemento diagonal principal sea igual a 1 ("<<matrizAumentada[i][j]<<"/"<<pivot<<")"<<endl<<matrizAumentada[i][i] << " "<<endl<<endl;
            }
        }

        // Eliminación hacia abajo
        for (int k = 0; k < filas; k++) {
            if (k != i) {
                double factor = matrizAumentada[k][i];
                for (int j = i; j < columnas; j++) {
                    matrizAumentada[k][j] -= factor * matrizAumentada[i][j];
                    archivo << "- Eliminación hacia abajo ("<<matrizAumentada[k][j]<<"-"<<factor<<"*"<<matrizAumentada[i][j]<<")"<<endl<<matrizAumentada[i][i] << " "<<endl<<endl;
                }
            }
        }
    }

    return numPivotes;
    
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

    int n;
    abrirDimensiones(n,n);
	ofstream abrir("resultado.txt"); abrir << " ";
	
    vector<vector<double>> matrizAumentada(n, vector<double>(2 * n));
    leerMatriz(matrizAumentada);

    double determinante = calcularDeterminante(matrizAumentada);
    ofstream inversaarch("resultado.txt",std::ios::app);
    
    if (determinante==0) {
	inversaarch << "Esta matriz no es invertible porque su determinante es 0 y/o tiene menos pivotes que entradas." << endl;
    exit(0);
	}
    // Inicializar la matriz identidad en la matriz aumentada
    
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            if (i == j - n) {
                matrizAumentada[i][j] = 1.0;
            } else {
                matrizAumentada[i][j] = 0.0;
            }
        }
    }

    // Calcular la RREF de la matriz aumentada y contar los pivotes

    int numPivotes = obtenerRREF(matrizAumentada);	

    guardarArchivo(matrizAumentada, "resultado.txt");
    inversaarch << "La matriz inversa es:" << endl;
 
    return 0;
}

