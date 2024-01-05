#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void caminoBase(int **M, int n)
{
    
}

void llenarAristasAleatorias(int **M, int n) //!FALTA HACER CAMINO BASE
{
    caminoBase(M, n);

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int r = (rand() % n) - 2;

        for (int k = 0; k < r; k++)
        {
            int j = rand() % n;
            while (j == i)
            {
                j = rand() % n;
            }
            M[i][j] = 1;
            M[j][i] = 1;
        }
    }
}

void grafoConexo(int **M, int n)
{
    int cont = 0;
}

void crearMatriz(int **&M, int n)
{
    M = new int *[n];
    for (int i = 0; i < n; i++)
    {
        M[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            M[i][j] = 0;
    }
}

void mostrarMatriz(int **M, int n)
{
    cout << endl;
    cout << "Matriz: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << M[i][j] << "\t";
        }
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
    int n;
    cout << "n = ";
    cin >> n;
    int **M;

    crearMatriz(M, n);
    llenarAristasAleatorias(M, n);
    mostrarMatriz(M, n);

    borrarMatriz(M, n);
}