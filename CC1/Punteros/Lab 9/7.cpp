#include <iostream>
using namespace std;

int sumarFila(int **M, int f, int c)
{
    int suma = 0;
    for (int i = 0; i < c; i++)
        suma += M[f][i];
    return suma;
}

int sumarColumna(int **M, int f, int c)
{
    int suma = 0;
    for (int i = 0; i < f; i++)
        suma += M[i][c];
    return suma;
}

bool esCuadradoMágico(int **M, int f, int c)
{
    if(f != c)
        return false;
    
    const int valor = sumarFila(M, 0, c);

    for (int i = 0; i < f; i++)
        if(sumarFila(M, i, c) != valor)
            return false;
    
    for (int i = 0; i < c; i++)
        if(sumarColumna(M, f, i) != valor)
            return false;

    return true;
}