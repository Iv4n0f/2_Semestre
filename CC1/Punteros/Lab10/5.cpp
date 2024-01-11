#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void llenarVector(int *V, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        V[i] = rand() % 10 +1;
    }
}

void suma(int &a, int b)
{
    a = a + b;
}

void producto(int &a, int b)
{
    a = a * b;
}

int main()
{
    int *V;
    int n;
    cout << "n de V?";
    cin >> n;
    V = new int[n];
    llenarVector(V, n);

    void (*f[2])(int &, int) = {suma, producto};

    int sum = 0, pro = 1;

    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % 2 == 0)
            f[0](sum, V[i]);
        if ((i + 1) % 2 == 1)
            f[1](pro, V[i]);
        cout << V[i] << " ";
    }
    cout << endl;

    cout << "Suma = " << sum << endl;
    cout << "Producto = " << pro;
}