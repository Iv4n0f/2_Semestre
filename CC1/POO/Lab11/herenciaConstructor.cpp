#include <iostream>
using namespace std;

class ClaseA
{
protected:
    int datoA;

public:
    ClaseA(int _a) { 
        datoA = _a;
        cout << "Constructor de A " << endl; }
    int getA() { return datoA; }
};

class ClaseB : public ClaseA
{
protected:
    int datoB;

public:
    ClaseB(int _a, int _b) : ClaseA (_a){
        datoB = _b;
        cout << "Constructor de B " << endl; }
    int getB() { return datoB; }
};


int main()
{
    ClaseB obj(10,20);
    cout << "Dato A: " << obj.getA() << endl;
    cout << "Dato B: " << obj.getB() << endl;
}