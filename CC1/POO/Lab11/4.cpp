#include <iostream>

using namespace std;

class Entero
{
private:
    int valor;

public:
    void setValor(int);
    int getValor();
    Entero suma(Entero);
    Entero inverso();
    Entero resta(Entero);
};

void Entero::setValor(int _valor)
{
    valor = _valor;
}

int Entero::getValor()
{
    return valor;
}

Entero Entero::suma(Entero sumando)
{
    Entero suma;
    suma.setValor(sumando.getValor() + valor);
    return suma;
}

Entero Entero::inverso()
{
    Entero inverso;
    inverso.setValor(-1 * valor);
    return inverso;
}

Entero Entero::resta(Entero restador)
{
    restador = restador.inverso();
    return suma(restador);
}

int main()
{
    Entero e1, e2;

    e1.setValor(3);
    e2.setValor(4);

    cout << "Resta: " << e1.resta(e2).getValor() << endl;
    cout << "Suma: " << e1.suma(e2).getValor();
}