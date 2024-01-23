#include <iostream>

using namespace std;

class Persona
{
private:
    string nombre;
    int edad;

public:
    Persona(string, int);

    void setNombre(string);
    void setEdad(int);
    string getNombre();
    int getEdad();

    void mostrar();
};

Persona::Persona(string n, int e)
{
    nombre = n;
    edad = e;
    cout << "Se ha creado una persona" << endl;
}

int Persona::getEdad()
{
    return edad;
}

string Persona::getNombre()
{
    return nombre;
}

void Persona::setEdad(int e)
{
    edad = e;
}
void Persona::setNombre(string n)
{
    nombre = n;
}

void Persona::mostrar()
{
    cout << " - ";
    cout << "Nombre: " << nombre << " - ";
    cout << "Edad: " << edad << " - ";
}

class Alumno : public Persona
{
protected:
    string carrera;

public:
    Alumno(string, int, string);
};

Alumno::Alumno(string n, int e, string c) : Persona(n, e)
{
    carrera = c;
    cout << "Construyendo alumno" << endl;
};

int main()
{
    Persona p1("Luis", 15);
    p1.mostrar();
    cout << endl;
    Alumno al1("Andree", 18, "Educacion");
    al1.mostrar();
};