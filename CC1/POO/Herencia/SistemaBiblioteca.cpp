#include <iostream>
#include <string>
using namespace std;

class Sistema()
{
private:
    Estudiante *estudiantes[100];
    Profesor *profesores[100];
    Administrador *administradores[100];
    Libro *libros[100];
    int cantidadEstudiantes;
    int cantidadProfesores;
    int cantidadAdministradores;
    int cantidadLibros;
    int cantidadPrestamos;

public:
    Sistema(){
        Estudiante *estudiantes[100];
        Libro *libros[100];
        int cantidadEstudiantes = 0;
        int cantidadLibros = 0;
    }
    void agregarEstudiante(Estudiante *estudiante){
        estudiantes[cantidadEstudiantes] = estudiante;
        cantidadEstudiantes++;
        cout << "Estudiante agregado" << endl;
    }
    void agregarLibro(Libro *libro){
        libros[cantidadLibros] = libro;
        cantidadLibros++;
        cout << "Libro agregado" << endl;
    }
    void tomarPrestado(Estudiante &estudiante, Libro &libro){
        if(!libro->estaPrestado()){
            libro->prestar();
            estudiante->tomarPrestado(libro);
            
        }                        
        else{
            cout << "El libro ya esta prestado" << endl;
        }
    }

    void devolverPrestamo(Estudiante &estudiante, Libro &libro){
        if(estudiante->getLibroPrestado() = libro){
            libro->devolver();
            estudiante->devolverPrestamo();
            cout << "Prestamo devuelto" << endl;
        }
    }
}