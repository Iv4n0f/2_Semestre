#include <iostream>
using namespace std;

bool compare(string a, string b)
{
    if (a == b) return true;
    return false;
}

class Persona
{
protected:
    string nombre;
    string codigo;
public:
    void llenar_data();
    void mostrar_data();
    string getCod();
    string getNombre();
};
void Persona::llenar_data()
{
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Codigo: ";
    cin >> codigo;
}
void Persona::mostrar_data()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Codigo: " << codigo << endl;
}

string Persona::getCod(){return codigo;}
string Persona::getNombre(){return nombre;}

//ALUMNO///////////////////////////////////////////////////////////////////
class Alumno:public Persona
{
	int creditos;
public:
	void llenar_data();
	void mostrar_data();
    void gastarCredito();
    void devolverCredito();
    int getCreditos();
};
void Alumno::llenar_data()
{
	Persona::llenar_data();
    creditos = 2;
}
void Alumno::mostrar_data()
{
	Persona::mostrar_data();
	cout<<"Creditos: "<<creditos<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
}
void Alumno::gastarCredito(){creditos--;}
void Alumno::devolverCredito(){creditos++;}
int Alumno::getCreditos(){return creditos;}

//PROFESOR///////////////////////////////////////////////////////////////////
class Profesor:public Persona
{
	int creditos;
public:
	void llenar_data();
	void mostrar_data();
    void gastarCredito();
    void devolverCredito();
    int getCreditos();
};
void Profesor::llenar_data()
{
	Persona::llenar_data();
    creditos = 3;
}
void Profesor::mostrar_data()
{
	Persona::mostrar_data();
	cout<<"Creditos: "<<creditos<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
}
void Profesor::gastarCredito(){creditos--;}
void Profesor::devolverCredito(){creditos++;}
int Profesor::getCreditos(){return creditos;}

class Documento
{
protected:
    string codigo;
    string titulo;
    string autor;
public:
    void llenar_data();
    void mostrar_data();
    string getCod();
    string getTitulo();
    string getAutor();
};

void Documento::llenar_data()

// PRESTAMO/////////////////////////////////////////////////////////////////
class Prestamo{


};

//Sistema/////////////////////////////////////////////////////////////////////////////
class Sistema
{
	Alumno *listaAlumno[100];
	Profesor *listaProfesor[100];
	Libros *listaLibros[100];
	Tesis *listaTesis[100];
	Revistas *listaRevistas[100];
	Prestamo *listaPrestamos[100];
	int actualAlumno,actualProfesor,actualLibros,actualTesis,actualRevistas,actualprestamo;
public:
	Sistema();
	void ingresar(int);
	void listar(int);
	void buscar(int);
	void eliminar(int);
};
Sistema::Sistema()
{
	for (int i=0;i<100;i++)
	{
		listaAlumno[i]= new Alumno;
		listaProfesor[i]= new Profesor;
		listaLibros[i]=new Libros;
	        listaTesis[i]=new tesis;
        	listaRevistas[i]=new revistas;
		listaPrestamos[i]=new Prestamo;
	}
	actualAlumno=actualProfesor=actualLibros=actualTesis=actualRevistas=actualprestamo=0;
}
/////////////////////////////SISTEMA-ingresar/////////////////////////////////////////////77777777777777777
void Sistema::ingresar(int tipo)
{
	if (tipo==1)
	{
		listaAlumno[actualAlumno]->llenar_data();
		actualAlumno++;
	}
	else if (tipo==2)
	{
		listaProfesor[actualProfesor++]->llenar_data();
	}
	else if (tipo==3)
	{
        	listaLibros[actualLibros++]->llenar_data();
	}
    	else if (tipo==4)
    	{
        	listaTesis[actualTesis++]->llenar_data();
	}
	else if (tipo==5)
	{
        	listaRevistas[actualRevistas++]->llenar_data();
	}
	
	// Completar el registro de un préstamo


}
//////////////////////////////////SISTEMA-listar/////////////////////////////////////////////////////
void Sistema::listar(int tipo)
{

}
///////////////////SISTEMA-buscar/////////////////////////////////////////////////////////////////
void Sistema::buscar(int tipo)
{

}
///////////////////////SISTEMA-eliminar///////////////////////////////////////////////////////////
void Sistema::eliminar(int tipo)
{

}

int main()
{
    Sistema s;
    int menu;
    for ( ; ; )
    {

        	cout<<"\t(1) Ingresar datos "<<endl;
	        cout<<"\t(2) Mostrar  Datos "<<endl;
	        cout<<"\t(3) Buscar  datos "<<endl;
	        cout<<"\t(4) Eliminar datos "<<endl;
	        cout<<"\t(5) Salir "<<endl;
	        cout<<"Opcion : ";
	        cin>>menu;
	        cout<<"\n \n";
	        switch (menu)
	        {
	        case 1:
	            cout<<"(1) Ingresar Alumno "<<endl;
	            cout<<"(2) Ingresar Profesor "<<endl;
	            cout<<"(3) Ingresar Libro "<<endl;
	            cout<<"(4) Ingresar Tesis "<<endl;
	            cout<<"(5) Ingresar Revista "<<endl;
	            cout<<"(6) Realizar Prestamo "<<endl;
				cout<<"(7) Regresar "<<endl;
	            cout<<"Opcion : ";
	            cin>>menu;
	            s.ingresar(menu);
	            cout<<"\n";
	            break;
	        case 2:
	            cout<<"(1) Mostrar Alumno "<<endl;
	            cout<<"(2) Mostrar Profesor "<<endl;
	            cout<<"(3) Mostrar Libro "<<endl;
	            cout<<"(4) Mostrar Tesis "<<endl;;
	            cout<<"(5) Mostrar Revista "<<endl;
				cout<<"(6) Mostrar Prestamos "<<endl;
	            cout<<"(7) Regresar "<<endl;
	            cout<<"Opcion : ";
	            cin>>menu;
	            s.listar(menu);
	            break;
	            cout<<"\n";
	        case 3:
	            cout<<"(1) Buscar Alumno "<<endl;
	            cout<<"(2) Buscar Profesor "<<endl;
	            cout<<"(3) Buscar Libro "<<endl;
	            cout<<"(4) Buscar Tesis "<<endl;
	            cout<<"(5) Buscar Revista "<<endl;
				cout<<"(6) Buscar Prestamo "<<endl;
	            cout<<"(7) Regresar "<<endl;
	            cout<<"Opcion : ";
	            cin>>menu;
	            s.buscar(menu);
	            break;
	            cout<<"\n";
	        case 4:
	            cout<<"(1) Eliminar Alumno "<<endl;
	            cout<<"(2) Eliminar Profesor "<<endl;
	            cout<<"(3) Eliminar Libro "<<endl;
	            cout<<"(4) Eliminar Tesis "<<endl;
	            cout<<"(5) Eliminar Revista "<<endl;
	            cout<<"(6) Regresar "<<endl;
	            cout<<"Opcion : ";
	            cin>>menu;
	            s.eliminar(menu);
	            break;
	            cout<<"\n";
	        case 5:
	            cout<<"Gracias por usar el Sistema"<<endl;
	            return 0;
	        }
    }
}