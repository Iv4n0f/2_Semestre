#include <iostream>
using namespace std;

int **crearMatriz(int f, int c)
{
    int **matriz = new int *[f];
    for (int i = 0; i < f; i++)
        matriz[i] = new int[c];
    return matriz;
}

void mostrarMatriz(int **M, int f, int c)
{
    cout << endl;
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

void borrarMatriz(int **M, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] M[i];
    }
    delete[] M;
}

int main()
{
    int f, c;
    cout << "Filas?: ";
    cin >> f;
    cout << "Columnas?: ";
    cin >> c;
    
    int **M = crearMatriz(f, c);

    // Procedimiento para llenar matriz
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            M[i][j] = (i + j) % c;
        }
    }

    mostrarMatriz(M, f, c);
    borrarMatriz(M, f);
}
