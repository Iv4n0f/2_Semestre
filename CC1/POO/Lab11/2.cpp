#include <iostream>

using namespace std;

class Rectangulo
{
private: // Atributos
    int largo, ancho;

public: // Métodos
    void setLargo(double);
    void setAncho(double);

    double getLargo();
    double getAncho();

    double area();
    double perimetro();
};

void Rectangulo::setLargo(double _largo)
{
    largo = _largo;
}

void Rectangulo::setAncho(double _ancho)
{
    ancho = _ancho;
}

double Rectangulo::getLargo()
{
    return largo;
}

double Rectangulo::getAncho()
{
    return ancho;
}

double Rectangulo::area()
{
    return largo * ancho;
}

double Rectangulo::perimetro()
{
    return 2 * (largo + ancho);
}

int main()
{
    Rectangulo r1;

    r1.setAncho(20);
    r1.setLargo(10);

    cout << "Largo de R1 = " << r1.getLargo() << endl;
    cout << "Ancho de R1 = " << r1.getAncho() << endl;

    cout << "Area de R1 = " << r1.area() << endl;
    cout << "Perimetro de R1 = " << r1.perimetro() << endl;
}