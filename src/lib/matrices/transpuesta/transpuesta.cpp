#include<iostream>
#include<windows.h>
#include<conio.h>
#include"archivo.h"
#include <fstream>

using namespace std;

int filas, tam;

void transpuestaMatriz()
{
	SetConsoleOutputCP(CP_UTF8);
	
	abrirDimensiones(filas,tam);
	float matriz[filas][tam];
	fstream archivo("matriz.txt");

	for (int i=0;i<filas;i++)
	{
		for (int j=0;j<tam;j++)
		{
			archivo >> matriz[i][j];
		}
	}
	
	cout << "> MATRIZ INGRESADA" << endl;
	for (int p=0;p<filas;p++)
	{
	for (int s=0;s<tam;s++)
	{
		cout <<matriz[p][s]<<"	";
	}
	cout << "\n\n";
	}
	  
   cout << "> MATRIZ TRANSPUESTA: " << endl;
   
   ofstream file("transpuesta.txt");

   for (int d=0;d<filas;d++)
  {
  	for (int m=0; m<tam; m++)
  	{
  	cout << matriz[m][d] << "	";
  	file << matriz[m][d] << " ";
	  }
	cout << endl;
   }
}

int main()
{
	transpuestaMatriz();
	return 0;
}
