#include <iostream>
using namespace std;

class Circulo
{
private:
    const double PI = 3.141592;
    double radio;

public:
    void setRadio(double);
    double getRadio();
    double area();
    double perimetro();
};

void Circulo::setRadio(double _radio)
{
    radio = _radio;
}

double Circulo::getRadio()
{
    return radio;
}

double Circulo::area()
{
    return PI * (radio * radio);
}

double Circulo::perimetro()
{
    return PI * (2 * radio);
}

int main()
{
    Circulo c1;
    c1.setRadio(2);

    cout << "Area de C1 =" << c1.area() << endl;
}
