#include<vector>
#include<fstream>

using namespace std;
void abrirDimensiones(int &filas, int &columnas);
void leerMatriz(std::vector<std::vector<double>> &matriz);
void guardarArchivo(std::vector<vector<double>> &matriz, std::string nombreArchivo);
