#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void llenarAristasAleatorias(int **M, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        M[i][i + 1] = 1;
        M[i + 1][i] = 1;
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int r = rand() % (n - 1) + 1;

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

void borrarMatriz(int **M, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] M[i];
    }
    delete[] M;
}

void graphVizz(int **M, int n, const char *nombreArchivo)
{
    ofstream archivoDOT(nombreArchivo);

    if (!archivoDOT.is_open())
    {
        cerr << "No se pudo abrir el archivo DOT." << endl;
        return;
    }

    archivoDOT << "graph GrafoNoDirigido {" << endl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i ; j < n; ++j)
        {
            if (M[i][j] == 1)
            {
                archivoDOT << "  " << i << " -- " << j << ";" << endl;
            }
        }
    }

    archivoDOT << "}" << endl;
    archivoDOT.close();

    cout << "El archivo DOT se ha generado correctamente: " << nombreArchivo << endl;

    string comando = "dot -Tpng " + string(nombreArchivo) + " -o " + string(nombreArchivo) + ".png";
    system(comando.c_str());
    comando = string(nombreArchivo) + ".png";
    system(comando.c_str());
}

void DFS(int **M, int n, int **M_DFS, int v, bool visitados[])
{
    for (int j = 0; j < n; j++)
    {
        if (M[v][j] != 0 && !visitados[j])
        {
            M_DFS[v][j] = 1;
            M_DFS[j][v] = 1;
            visitados[j] = true;
            DFS(M, n, M_DFS, j, visitados);
        }
    }
}

void iniciarDFS(int **M, int n, int **M_DFS)
{
    bool visitados[n];

    for (int i = 0; i < n; i++)
    {
        visitados[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visitados[i])
        {
            visitados[i] = true;
            DFS(M, n, M_DFS, i, visitados);
        }
    }
}

void BFS(int **M, int n, int **M_BFS, int v, bool visitados[])
{

}

void iniciarBFS(int **M, int n, int **M_BFS)
{

}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    int **M;

    crearMatriz(M, n);
    llenarAristasAleatorias(M, n);
    cout << "Matriz original: " << endl;
    mostrarMatriz(M, n);
    graphVizz(M, n, "grafo.dot");

    int ** M_DFS;
    crearMatriz(M_DFS, n);
    iniciarDFS(M, n, M_DFS);
    cout << "Matriz DFS: " << endl;
    mostrarMatriz(M_DFS, n);
    graphVizz(M_DFS, n, "grafo_DFS.dot");

    borrarMatriz(M_DFS, n);
    borrarMatriz(M, n);
}