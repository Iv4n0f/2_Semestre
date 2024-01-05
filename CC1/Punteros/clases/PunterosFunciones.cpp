#include <iostream>

using namespace std;

int suma(int a, int b)
{
    return a + b;
}

int resta(int a, int b)
{
    return a - b;
}

int multiplicacion(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    return a / b;
}

void imprimirMenu()
{   
    cout << "MENU" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout << "5. Salir" << endl;
}

int main()
{
    int (*f[4])(int, int) = {suma, resta, multiplicacion, division};
    
    while(true)
    {
    imprimirMenu();
    int opcion;
    int a, b, r;
    cout << "Ingrese a: ";
    cin >> a;
    cout << "Ingrese b: ";
    cin >> b;

    cout << "Ingrese una opcion: ";
    cin >> opcion;

    if(opcion == 5) break;

    while (opcion < 1 || opcion > 5)
    {
        cout << "Ingrese una opcion valida: ";
        cin >> opcion;
    }

    r = f[opcion - 1](a, b);

    cout << endl << "Resultado: " << r << endl << endl;
    }
}