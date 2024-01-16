#include<iostream>

using namespace std;

class Punto
{
    private:
        int x,y,z;
    
    public:
        Punto(int,int,int);
        int getX();
        int getY();
        int getZ();
};
Punto::Punto(int _x,int _y, int _z)
{
    x = _x;
    y = _y;
    z = _z;
}

int Punto::getX()
{
    return x;
}

int Punto::getY()
{
    return y;
}

int Punto::getZ()
{   
    return z;
}
