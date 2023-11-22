#include<iostream>
#include<conio.h>
using namespace std;
 int filas, tam;
void sumarMatriz()
{

  cout << "> Ingrese el número de filas de la matriz: "; cin >> filas;
cout << "> Ingrese el número de columnas de la matriz: "; cin >> tam;
  
  float MatrizSuma[filas][tam];
  float matriz[filas][tam];
  float matriz1[filas][tam];
  
   cout << "> Ingrese los valores de la matriz 1: " << endl;
  for (int b=0;b<filas;b++)
  {
    for (int c=0;c<tam;c++)
    {
    cout << "(" << b <<", "<< c << "): ";
    cin >> matriz[b][c];
    cout << endl;
	}
   }
   
    cout << "> Ingrese los valores de la matriz 2: " << endl;
  for (int b=0;b<filas;b++)
  {
    for (int c=0;c<tam;c++)
    {
    cout << "(" << b <<", "<< c << "): ";
    cin >> matriz1[b][c];
    MatrizSuma[b][c] = matriz[b][c]+matriz1[b][c];
    cout << endl;
	}
   }
	
	cout << "\n> Matriz sumada: " << endl;
   
   for (int d=0;d<filas;d++)
  {
  	for (int c=0;c<tam;c++)
    {
	cout << "  " << MatrizSuma[d][c] << "	";
	cout << endl;
   } }
}

int main()
{
	sumarMatriz();
  getch();
}