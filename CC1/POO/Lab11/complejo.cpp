#include <iostream>
using namespace std;

class Complejo
{
private:
    int real;
    int imaginaria;

public:
    Complejo();
    Complejo(int, int);
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

Complejo::Complejo()
{
    real = 0;
    imaginaria = 0;
}

Complejo::Complejo(int r, int i)
{
    real = r;
    imaginaria = i;
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
    Complejo suma(real + sumando.getReal(), imaginaria + sumando.getImaginaria());
    return suma;
}

Complejo Complejo::inverso()
{
    Complejo inverso(real * -1, imaginaria * -1);
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
    Complejo c1(3,9), c2(5,7);

    cout << "c1 = ";
    c1.mostrar();
    cout << "c2 = ";
    c2.mostrar();

    //Metodos
    cout << "Suma = ";
    c1.suma(c2).mostrar();

    cout <<"Resta = ";
    c1.resta(c2).mostrar();

    //Lista complejos
    Complejo listaComplejos[10];
    listaComplejos[0] = c1;
    listaComplejos[1] = c2;

    for (int i = 0; i < 2; i++)
        listaComplejos[i].mostrar(); //Metodo en lista

    //Vector con punteros

    Complejo *listaComplejosPunteros[10];
    listaComplejosPunteros[0] = new Complejo();
    listaComplejosPunteros[1] = new Complejo(3,8);

    for (int i = 0; i < 2; i++){
        cout << "Complejo " << i << " = ";
        listaComplejosPunteros[i]->mostrar(); //Metodo con punteros
    }


}