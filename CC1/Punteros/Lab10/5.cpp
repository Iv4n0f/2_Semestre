#include <iostream>
#include <cstdlib>
#include <ctime>

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
    {
        for (int j = 0; j < c; j++)
        {
            *(*(M + i) + j) = rand() % 5 + 1; //Valores pequeños para evitar usar long
        }
    }
}

void sumaAcumulativa(int &suma_actual, int sumando)
{
    suma_actual += sumando;
}

void productoAcumulativo(int &producto_actual, int multiplicador)
{
    producto_actual *= multiplicador;
}

void mostrarMatriz(int **M, int n)
{
    cout << "  ";
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
        for (int j = 0; j < n; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void mostrarMatriz(int **M, int f, int c)
{
    cout << "  ";
    for (int i = 0; i < c; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < f; i++)
    {
        cout << i << " ";
        for (int j = 0; j < c; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int **M;
    int f, c;

    cout << "f: ";
    cin >> f;
    cout << "c: ";
    cin >> c;
    crearMatriz(M, f, c);
    llenarMatrizRandom(M, f, c);
    mostrarMatriz(M, f, c);
    // * Array de punteros a funciones
    void (*funciones[2])(int &, int) = {sumaAcumulativa, productoAcumulativo};

    int x, y;

    cout << "Sumar fila x (0-" << f << ")";
    cin >> x;

    int sum = 0;
    for (int i = 0; i < c; i++)
    {
        funciones[0](sum, M[x][i]);
    }
    cout << "Suma fila " << x << " = " << sum << endl;

    cout << "Producto columna y (0 - " << c << ")";
    cin >> y;

    int pro = M[0][y]; // Initialize pro with the first element of the column
    for (int i = 1; i < f; i++)
    {
        funciones[1](pro, M[i][y]);
    }
    cout << "Producto columna " << y << " = " << pro << endl;
}