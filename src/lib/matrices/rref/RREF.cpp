#include <iostream>
#include<conio.h>
#include<windows.h>
#include<vector>
#include<fstream>
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
    ofstream file(nombreArchivo,ios::app);
    int filas = matriz.size();
    int columnas = matriz[0].size();
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            file << matriz[i][j] << " ";
        }
        file << endl << endl;
    }
}

int obtenerRREF(vector<vector<double>>& matrizAumentada) {
  int filas = matrizAumentada.size();
    int columnas = matrizAumentada[0].size();
    int numPivotes = 0;
	ofstream archivo("resultado.txt",ios::app);
    for (int i = 0; i < filas; i++) {
        // Encontrar la fila con el valor máximo en la columna actual
        int filaMax = i;
        for (int k = i + 1; k < filas; k++) {
            if (abs(matrizAumentada[k][i]) > abs(matrizAumentada[filaMax][i])) {
                filaMax = k;
            }
            
            archivo << "- Encontrar la fila con el valor máximo en la columna actual. La fila es F"<<filaMax<<" y el valor es " << matrizAumentada[i][i] << " "<<endl<<endl;
            guardarArchivo(matrizAumentada,"resultado.txt");
        }
		  
        // Intercambiar filas para tener el valor máximo en la fila actual
        if (filaMax != i) {
            swap(matrizAumentada[i], matrizAumentada[filaMax]);
            archivo << "- Intercambiar filas para tener el valor máximo en la fila actual. F"<<i<<"-> F"<<filaMax<<endl<<endl;
            guardarArchivo(matrizAumentada,"resultado.txt");
        }
		
        // Verificar si el elemento diagonal principal es un pivote
        if (matrizAumentada[i][i] != 0) {
            numPivotes++;
             archivo << "- Verificar si el elemento diagonal principal es distinto a 0 para ser un pivote. ("<<matrizAumentada[i][i]<<")"<<endl<<endl;
       guardarArchivo(matrizAumentada,"resultado.txt"); }
	
        // Hacer que el elemento diagonal principal sea igual a 1
        double pivot = matrizAumentada[i][i];
        if (pivot != 0) {
            for (int j = i; j < columnas; j++) {
                matrizAumentada[i][j] /= pivot;
                archivo << "- Hacer que el elemento diagonal principal de la columna " << j << " sea igual a 1 ("<<matrizAumentada[i][j]<<"/"<<pivot<<")"<<endl<<endl;
            }
            guardarArchivo(matrizAumentada,"resultado.txt");
        }

        // Eliminación hacia abajo
        for (int k = 0; k < filas; k++) {
            if (k != i) {
            	
                double factor = matrizAumentada[k][i];
                for (int j = i; j < columnas; j++) {
                    matrizAumentada[k][j] -= factor * matrizAumentada[i][j];
                    archivo << "- Eliminación hacia abajo ("<<matrizAumentada[k][j]<<"-"<<factor<<"*"<<matrizAumentada[i][j]<<")"<<endl;
                     guardarArchivo(matrizAumentada,"resultado.txt"); 
                    }
                   
                }
        }
        
    }

    return numPivotes;
    
}

int main() {
    int filas, columnas;
    SetConsoleOutputCP(CP_UTF8);
    ofstream abrir("resultado.txt"); abrir << "";
    abrirDimensiones(filas, columnas);
 	vector<vector<double>> matriz(filas, vector<double>(columnas));
    leerMatriz(matriz);

    obtenerRREF(matriz);

    
    int k = obtenerRREF(matriz);


    return 0; }
    
