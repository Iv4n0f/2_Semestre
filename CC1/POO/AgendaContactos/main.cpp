#include <iostream>

using namespace std;

class Persona
{
private:
    string nombre;
    int edad;
    string telefono;

public:
    Persona(string, int, string);
    string getNombre();
    int getEdad();
    string getTelefono();
    void setNombre(string);
    void setEdad(int);
    void setTelefono(string);
    void mostrar();
};

Persona::Persona(string n, int e, string t)
{
    nombre = n;
    edad = e;
    telefono = t;
}

int Persona::getEdad()
{
    return edad;
}

string Persona::getNombre()
{
    return nombre;
}
string Persona::getTelefono()
{
    return telefono;
}

void Persona::setEdad(int e)
{
    edad = e;
}
void Persona::setNombre(string n)
{
    nombre = n;
}
void Persona::setTelefono(string t)
{
    telefono = t;
}

void Persona::mostrar()
{
    cout << " - ";
    cout << "Nombre: " << nombre << " - ";
    cout << "Edad: " << edad << " - ";
    cout << "Telefono: " << telefono << endl;
}

int main()
{
    Persona *Personas[100];
    int i = 0;
    int opc = 0;

    do
    {
        cout << "\n1. Agregar persona" << endl;
        cout << "2. Modificar persona" << endl;
        cout << "3. Mostrar personas" << endl;
        cout << "4. Buscar persona" << endl;
        cout << "5. Salir" << endl;

        cin >> opc;

        if(opc == 1){ //Agregar
            string Nombre,telefono;
            int edad;
            cout << "Ingrese nombre: ";
            cin >> Nombre;
            cout << "Ingrese edad: ";
            cin >> edad;
            cout << "Ingrese telefono: ";
            cin >> telefono;

            Personas[i] = new Persona(Nombre,edad,telefono);
            i++;
        }
        else if(opc == 2){ //Modificar
            int pos;
            cout << "Ingrese numero de persona a modificar: ";
            cin >> pos;
            pos--;
            cout << "Que dato desea modificar?" << endl;
            cout << "1. Nombre" << endl;
            cout << "2. Edad" << endl;
            cout << "3. Telefono" << endl;
            cout << "4. Todo"<<endl;
            int opc2;
            cin >> opc2;
            if(opc2 == 1){
                string Nombre;
                cout << "Ingrese nuevo nombre: ";
                cin >> Nombre;
                Personas[pos]->setNombre(Nombre);
                cout << "Nombre modificado" << endl;
                cout << endl;
            }
            else if(opc2 == 2){
                int edad;
                cout << "Ingrese nueva edad: ";
                cin >> edad;
                Personas[pos]->setEdad(edad);
                cout << "Edad modificada" << endl;
                cout << endl;
            }
            else if(opc2 == 3){
                string telefono;
                cout << "Ingrese nuevo telefono: ";
                cin >> telefono;
                Personas[pos]->setTelefono(telefono);
                cout << "Telefono modificado" << endl;
                cout << endl;
            }
            else if(opc2 == 4){
                string Nombre,telefono;
                int edad;
                cout << "Ingrese nuevo nombre: ";
                cin >> Nombre;
                cout << "Ingrese nuevo edad: ";
                cin >> edad;
                cout << "Ingrese nuevo telefono: ";
                cin >> telefono;
                Personas[pos]->setNombre(Nombre);
                Personas[pos]->setEdad(edad);
                Personas[pos]->setTelefono(telefono);
                cout << "Datos modificados" << endl;
                cout << endl;
            }
        }
        else if(opc == 3){ //Mostrar
            for(int j = 0; j < i; j++){
                cout << "Persona " << j+1;
                Personas[j]->mostrar();
            }
        }
        else if(opc == 4){ //Buscar
            string buscar;
            cout << "Ingrese nombre a buscar: ";
            cin >> buscar;
            bool encontrada = false;
            for(int j = 0; j < i; j++){
                if(buscar == Personas[j]->getNombre()){
                    cout << "Persona " << j+1;
                    Personas[j]->mostrar();
                    encontrada = true;
                    break;
                }
            }
            if(!encontrada)cout << "Persona no encontrada" << endl;
        }

    } while (opc != 5);
}
