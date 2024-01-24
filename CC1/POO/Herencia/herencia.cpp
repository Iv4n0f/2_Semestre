#include <iostream>
using namespace std;

class ClaseA
{
protected:
    int datoA;

public:
    ClaseA() : datoA(10) { cout << "Constructor de A " << endl; }
    int getA() { return datoA; }
};

class ClaseB : public ClaseA
{
protected:
    int datoB;

public:
    ClaseB() : datoB(20) { cout << "Constructor de B " << endl; }
    int getB() { return datoB; }
};


int main()
{
    ClaseB obj;
    cout << "Dato A: " << obj.getA() << endl;
    cout << "Dato B: " << obj.getB() << endl;
}