#include <iostream>

using namespace std;

class Cuenta
{
private:
    int numero, saldo;

public:
    Cuenta(int, int);
    void depositar(int);
    int consultar();
    bool girar(int);
};