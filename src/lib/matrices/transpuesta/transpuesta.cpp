#include<iostream>
#include<windows.h>
#include<conio.h>
#include <fstream>
#include<vector>
using namespace std;

int filas, tam;

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

void transpuestaMatriz()
{
	
    FreeConsole();
    ofstream abrir("resultado.txt"); abrir << " ";
	ofstream file("resultado.txt",std::ios::app);
	file << "Una matriz se transpone cuando se intercambian sus filas por sus columnas.\n\n";
    int filas, tam;
    abrirDimensiones(filas, tam);
    
    vector<vector<double>> matriz(filas, vector<double>(tam));
    leerMatriz(matriz);

    file << "> MATRIZ INGRESADA" << endl;
    for (int p = 0; p < filas; p++)
    {
        for (int s = 0; s < tam; s++)
        {
            file << matriz[p][s] << "    ";
        }
        file << "\n\n";
    }

    file << "> MATRIZ TRANSPUESTA: " << endl;

    
	for (int d=0;d<filas;d++)
  {
  	for (int m=0; m<tam; m++)
  	{
  	file << matriz[m][d] << "	";
  	file << matriz[m][d] << " ";
	  }
	file << endl;
   }
}


int main()
{
	transpuestaMatriz();
	return 0;
}
