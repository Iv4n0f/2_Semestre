#include <iostream>
using namespace std;

class Complejo
{
private:
    int real;
    int imaginaria;

public:
    void setReal(int);
    void setImaginaria(int);
    int getReal();
    int getImaginaria();
    void mostrar();
    Complejo suma(Complejo);
    Complejo inverso();
    Complejo resta(Complejo);
};

int Complejo::getReal()
{
    return real;
}

int Complejo::getImaginaria()
{
    return imaginaria;
}

void Complejo::setImaginaria(int i)
{
    imaginaria = i;
}

void Complejo::setReal(int r)
{
    real = r;
}

void Complejo::mostrar()
{
    if (imaginaria >= 0)
        cout << real << "+" << imaginaria << "i";
    else
        cout << real << imaginaria << "i";
    cout << endl;
}

Complejo Complejo::suma(Complejo sumando)
{
    Complejo suma;
    suma.setReal(real + sumando.getReal());
    suma.setImaginaria(imaginaria + sumando.getImaginaria());
    return suma;
}

Complejo Complejo::inverso()
{
    Complejo inverso;
    inverso.setReal(-1 * real);
    inverso.setImaginaria(-1 * imaginaria);
    return inverso;
}

Complejo Complejo::resta(Complejo restando)
{
    Complejo resta;
    Complejo inverso = restando.inverso();
    return suma(inverso);
}

int main()
{
    Complejo c1, c2;
    c1.setReal(3);
    c1.setImaginaria(2);

    c2.setReal(7);
    c2.setImaginaria(5);

    cout << "c1 = ";
    c1.mostrar();
    cout << "c2 = ";
    c2.mostrar();

    cout << "Suma = ";
    c1.suma(c2).mostrar();

    cout <<"Resta = ";
    c1.resta(c2).mostrar();
}