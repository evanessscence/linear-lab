#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Función para leer una matriz desde un archivo
std::vector<std::vector<int>> leerMatriz(const char* nombreArchivo, int filas, int columnas) {
    std::ifstream archivo(nombreArchivo);
    std::vector<std::vector<int>> matriz(filas, std::vector<int>(columnas, 0));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            archivo >> matriz[i][j];
        }
    }

    return matriz;
}

// Función para escribir una matriz en un archivo
void escribirMatriz(const char* nombreArchivo, const std::vector<std::vector<int>>& matriz) {
    std::ofstream archivo(nombreArchivo);

    for (const auto& fila : matriz) {
        for (int valor : fila) {
            archivo << valor << ' ';
        }
        archivo << '\n';
    }
}

// Función para realizar la suma de dos matrices
std::vector<std::vector<int>> sumaMatrices(const std::vector<std::vector<int>>& matrizA, const std::vector<std::vector<int>>& matrizB) {
    int filas = matrizA.size();
    int columnas = matrizA[0].size();
    std::vector<std::vector<int>> resultado(filas, std::vector<int>(columnas, 0));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    return resultado;
}

// Función para realizar la resta de dos matrices
std::vector<std::vector<int>> restaMatrices(const std::vector<std::vector<int>>& matrizA, const std::vector<std::vector<int>>& matrizB) {
    int filas = matrizA.size();
    int columnas = matrizA[0].size();
    std::vector<std::vector<int>> resultado(filas, std::vector<int>(columnas, 0));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }

    return resultado;
}

// Función para realizar la multiplicación de dos matrices
std::vector<std::vector<int>> multiplicacionMatrices(const std::vector<std::vector<int>>& matrizA, const std::vector<std::vector<int>>& matrizB) {
    int filasA = matrizA.size();
    int columnasA = matrizA[0].size();
    int columnasB = matrizB[0].size();
    std::vector<std::vector<int>> resultado(filasA, std::vector<int>(columnasB, 0));

    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            for (int k = 0; k < columnasA; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    return resultado;
}

// Función para realizar el producto cartesiano de dos matrices
std::vector<std::vector<int>> productoCartesiano(const std::vector<std::vector<int>>& matrizA, const std::vector<std::vector<int>>& matrizB) {
    int filasA = matrizA.size();
    int columnasA = matrizA[0].size();
    int filasB = matrizB.size();
    int columnasB = matrizB[0].size();
    std::vector<std::vector<int>> resultado(filasA * filasB, std::vector<int>(columnasA + columnasB, 0));

    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < filasB; ++j) {
            for (int k = 0; k < columnasA; ++k) {
                resultado[i * filasB + j][k] = matrizA[i][k];
            }
            for (int k = 0; k < columnasB; ++k) {
                resultado[i * filasB + j][columnasA + k] = matrizB[j][k];
            }
        }
    }

    return resultado;
}

int main() {
    // Leer las dimensiones de las matrices desde archivos
    int filasA, columnasA, filasB, columnasB;
    ofstream error("resultado.txt");
    std::ifstream filasArchivo("filas.txt");
    std::ifstream columnasArchivo("columnas.txt");

    filasArchivo >> filasA;
    columnasArchivo >> columnasA;
    filasArchivo >> filasB;
    columnasArchivo >> columnasB;

    // Leer el valor de eleccion.txt
    int eleccion;
    std::ifstream eleccionArchivo("eleccion.txt");
    eleccionArchivo >> eleccion;

    // Leer las matrices desde archivos
    auto matrizA = leerMatriz("matriza.txt", filasA, columnasA);
    auto matrizB = leerMatriz("matrizb.txt", filasB, columnasB);

    // Realizar operaciones en base a la elección
    switch (eleccion) {
        case 1: {
            // Suma de matrices
            auto resultado = sumaMatrices(matrizA, matrizB);
            escribirMatriz("resultado.txt", resultado);
            break;
        }
        case 2: {
            // Resta de matrices
            auto resultado = restaMatrices(matrizA, matrizB);
            escribirMatriz("resultado.txt", resultado);
            break;
        }
        case 3: {
            // Multiplicación de matrices
            if (columnasA != filasB) {
                error << "Error: Las matrices no son compatibles para la multiplicación." << std::endl;
                return 1;
            }
            auto resultado = multiplicacionMatrices(matrizA, matrizB);
            escribirMatriz("resultado.txt", resultado);
            break;
        }
        case 4: {
            // Producto cartesiano de matrices
            auto resultado = productoCartesiano(matrizA, matrizB);
            escribirMatriz("resultado.txt", resultado);
            break;
        }
        default:
            return 1;
    }

    return 0;
}
