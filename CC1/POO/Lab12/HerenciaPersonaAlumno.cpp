#include <iostream>
#include <string>

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
    cout << "Nombre: " << nombre << " - ";
    cout << "Edad: " << edad << " - ";
}

class Alumno : public Persona
{
protected:
    string carrera;

public:
    Alumno(string, int, string);

    void setCarrera(string c){carrera=c;}
    string getCarrera(){return carrera;}

    void mostrar();
};

Alumno::Alumno(string n, int e, string c) : Persona(n, e)
{
    carrera = c;
};

void Alumno::mostrar()
{
    Persona::mostrar();
    cout << "Carrera: " << carrera << endl;
}

class Profesor : public Persona
{
protected:
    string grado_acad;

public:
    Profesor(string, int, string);

    void setGrado(string g){grado_acad = g;}
    string getGrado(){return grado_acad;}

    void mostrar();
};

Profesor::Profesor(string n, int e, string g) : Persona(n, e)
{
    grado_acad = g;
}

void Profesor::mostrar()
{
    Persona::mostrar();
    cout << "Grado_Academico: " << grado_acad << endl;
}

class Admin : public Persona
{
protected:
    string codigo;

public:
    Admin(string, int, string);

    void setCodigo(string c){codigo = c;}
    string getCodigo(){return codigo;}

    void mostrar();
};

Admin::Admin(string n, int e, string c) : Persona(n,e)
{
    codigo = c;
}

void Admin::mostrar()
{
    Persona::mostrar();
    cout<<"Codigo Aministrativo: "<<codigo<<endl;
}

int main()
{
    Alumno* l_alumnos[100];
    int n_alumnos = 0;

    Profesor* l_profesores[100];
    int n_profesores = 0;

    Admin* l_admins[100];
    int n_admins = 0;

    string nombre, carrera, grado_acad, codigo;
    int edad;

    int opc = -1;

    do{
        //Menu
        cout << "1. Agregar\n";
        cout << "2. Modificar\n";
        cout << "3. Mostrar\n";
        cout << "4. Salir\n";

        cin >> opc;

        switch(opc){
            case 1:
                cout << "1. Alumno\n";
                cout << "2. Profesor\n";
                cout << "3. Administrador\n";
                cout << "4. Volver\n";
                int opc2;
                cin >> opc2;
                switch(opc2){
                    case 1:
                        cout << "Nombre: ";
                        cin >> nombre;
                        cout << "Edad: ";
                        cin >> edad;
                        cout << "Carrera: ";
                        cin >> carrera;
                        l_alumnos[n_alumnos] = new Alumno(nombre, edad, carrera);
                        n_alumnos++;
                        break;
                    case 2:
                        cout << "Nombre: ";
                        cin >> nombre;
                        cout << "Edad: ";
                        cin >> edad;
                        cout << "Grado Academico: ";
                        cin >> grado_acad;
                        l_profesores[n_profesores] = new Profesor(nombre, edad, grado_acad);
                        n_profesores++;
                        break;
                    case 3:
                        cout << "Nombre: ";
                        cin >> nombre;
                        cout << "Edad: ";
                        cin >> edad;
                        cout << "Codigo Administrativo: ";
                        cin >> codigo;
                        l_admins[n_admins] = new Admin(nombre, edad, codigo);
                        n_admins++;
                        break;
                    case 4:
                        break;
                    default:
                        break;
                }
            case 2:
                cout << "1. Alumno\n";
                cout << "2. Profesor\n";
                cout << "3. Administrador\n";
                cout << "4. Volver\n";
                int opc3;
                cin >> opc3;

                switch(opc3){
                    case 1:
                        cout << "Nombre: ";
                        cin >> nombre;
                        cout << "Edad: ";
                        cin >> edad;
                        cout << "Carrera: ";
                        cin >> carrera;
                        cout << "Numero de alumno: ";
                        int num;
                        cin >> num;
                        num--;
                        if(num < n_alumnos){
                            l_alumnos[num]->setNombre(nombre);
                            l_alumnos[num]->setEdad(edad);
                            l_alumnos[num]->setCarrera(carrera);
                            cout << "Modificado" << endl;
                        }
                        else{
                            cout << "No existe ese alumno" << endl;
                        }
                        break;
                    case 2:
                        cout << "Nombre: ";
                        cin >> nombre;
                        cout << "Edad: ";
                        cin >> edad;
                        cout << "Grado Academico: ";
                        cin >> grado_acad;
                        cout << "Numero de profesor: ";
                        int num2;
                        cin >> num2;
                        num2--;
                        if(num2 < n_profesores){
                            l_profesores[num2]->setNombre(nombre);
                            l_profesores[num2]->setEdad(edad);
                            l_profesores[num2]->setGrado(grado_acad);
                        }
                        else{
                            cout << "No existe ese profesor" << endl;
                        }
                        break;
                    case 3:
                        cout << "Nombre: ";
                        cin >> nombre;
                        cout << "Edad: ";
                        cin >> edad;
                        cout << "Codigo Administrativo: ";
                        cin >> codigo;
                        int num3;
                        cin >> num3;
                        num3--;
                        if(num3 < n_admins){
                            l_admins[num3]->setNombre(nombre);
                            l_admins[num3]->setEdad(edad);
                            l_admins[num3]->setCodigo(codigo);
                            cout << "Modificado" << endl;
                        }
                        else{
                            cout << "No existe ese administrador" << endl;
                        }
                        break;
                    case 4:
                        break;
                    default:
                        break;
                }
            case 3:
                cout << "ALUMNOS: " <<endl;
                for (int i = 0; i < n_alumnos; i++){
                    cout << "Alumno " << i+1 << ": ";
                    l_alumnos[i]->mostrar();
                }
                cout << endl;

                cout << "PROFESORES: " <<endl;
                for (int i = 0; i < n_profesores; i++){
                    cout << "Profesor " << i+1 << ": ";
                    l_profesores[i]->mostrar();
                }
                cout << endl;

                cout << "ADMINISTRADORES: " <<endl;
                for (int i = 0; i < n_admins; i++){
                    cout << "Administrador " << i+1 << ": ";
                    l_admins[i]->mostrar();
                }
                cout << endl;
                break;
            case 4:
                break;
        }
    }
    while(opc != 4);
}