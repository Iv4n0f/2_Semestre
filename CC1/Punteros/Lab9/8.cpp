#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void crearMatriz(int **&M, int f, int c)
{
    M = new int *[f];
    for (int i = 0; i < f; i++)
        M[i] = new int[c];
}

void llenarMatrizRandom(int **M, int f, int c)
{
    srand(time(NULL));
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            *(*(M + i) + j) = rand() % 10;
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

void borrarMatriz(int **&M, int f)
{
    for (int i = 0; i < f; i++)
        delete[] M[i];
    delete[] M;
}

int main()
{
    // Matriz inicial
    int m = 4, n = 6;
    cout << "Matriz inicial; Filas = " << m << ", Columnas = " << n << endl;
    int **M1;
    crearMatriz(M1, m, n);
    llenarMatrizRandom(M1, m, n);
    mostrarMatriz(M1, m, n);

    int f,c;
    while(true){
        cout << "Ingrese el numero de filas: ";
        cin >> f;
        cout << "Ingrese el numero de columnas: ";
        cin >> c;
        if(f*c == m*n) break;
        cout << "El numero de elementos es incorrecto" << endl;
    }

    // Matriz final
    int **M2;
    crearMatriz(M2, f, c);

    // Al trabajar con matrices dinámicas las dM
    // no son necesariamente continuas
    for (int i = 0; i < m * n; i++)
    {
        *(*(M2 + (i / c)) + i % c) = *(*(M1 + (i / n)) + i % n); // i / c = fila, i % c = columna
    }

    mostrarMatriz(M2, f, c);

    borrarMatriz(M1, m);
    borrarMatriz(M2, f);
}