//PREGUNTA 1

#include <iostream>
using namespace std;

class Cola{
    int *vCola;
    int tam,top,cont=0;
public:
    Cola(int);
    void push(int);
    void pop();
    void mostrar();
};
Cola::Cola(int x){
    top=0;
    vCola = new int[x];
    tam = x;
}
void Cola::push(int x){
    if(top == 0){
        top = x;
    }
    vCola[cont]= x;
    cont++;
}
void Cola::pop(){
    for(int i=0;i<cont-1;i++){
        vCola[i] = vCola[i+1];
    }
    cont--;
}
void Cola::mostrar(){
    cout<<"\n";
    for(int i=0;i<cont;i++){
        cout<<vCola[i]<<"-";
    }
}

int main(){
    Cola numeros(5);

    numeros.push(3);
    numeros.push(4);
    numeros.push(5);
    numeros.push(6);
    numeros.mostrar();
    numeros.pop();
    numeros.pop();
    numeros.mostrar();


}



//PREGUNTA 2
#include <iostream>
using namespace std;

class Persona
{
protected:
    int DNI;
    string nombre;
    int num_prestamos = 0;
public:
    void llenar_data();
    void mostrar_data();
    int getDNI();
    string getNombre();
};
int Persona::getDNI()
{
    return DNI;
}
string Persona::getNombre()
{
    return nombre;
}
void Persona::llenar_data()
{
	cout<<"Nombre :  ";
	cin>>nombre;
	cout<<"DNI :  ";
	cin>>DNI;
}
void Persona::mostrar_data()
{
	cout<<"Nombre : "<<nombre<<endl;
	cout<<"DNI : "<<DNI<<endl;
}

//ALUMNO///////////////////////////////////////////////////////////////////
class Alumno:public Persona
{
	string carrera;
public:
	void llenar_data2();
	void mostrar_data2();
	string getCarrera();
};
string Alumno::getCarrera()
{
    return carrera;
}
void Alumno::llenar_data2()
{
	Persona::llenar_data();
	cout<<"Carrera: ";
	cin>>carrera;
}
void Alumno::mostrar_data2()
{
	Persona::mostrar_data();
	cout<<"Carrera: "<<carrera<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
}
//PROFESOR///////////////////////////////////////////////////////////////////
class Profesor:public Persona
{
	string area;
public:
	void llenar_data2();
	void mostrar_data2();
	string getArea();
};
string Profesor::getArea()
{
    return area;
}
void Profesor::llenar_data2()
{
	Persona::llenar_data();
	cout<<"Area: ";
	cin>>area;
}
void Profesor::mostrar_data2()
{
	Persona::mostrar_data();
	cout<<"Area: "<<area<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
}
//DOCUMENTO///////////////////////////////////////////////////////////////////
class Documento
{
protected:
    string codigo;
    int cantidad;
    string nombre;
public:
    void llenar_data();
    void mostrar_data();
    int getCantidad();
    string getNombre();
    void quitar();
    void sumar();
};
int Documento::getCantidad()
{
    return cantidad;
}
string Documento::getNombre()
{
    return nombre;
}
void Documento::llenar_data()
{
	cout<<"Nombre :  ";
	cin>>nombre;
	cout<<"Cantidad :  ";
	cin>>cantidad;
}
void Documento::mostrar_data()
{
	cout<<"Nombre : "<<nombre<<endl;
	cout<<"Cantidad : "<<cantidad<<endl;
}
void Documento::quitar()
{
    if(cantidad > 0)
        cantidad--;
    else
        cout<<"no hay stock"<<endl;
}
void Documento::sumar()
{
    cantidad++;
}
//TESIS///////////////////////////////////////////////////////////////////
class Tesis:public Documento
{
	string categoria;
public:
	void llenar_data2();
	void mostrar_data2();
	string getCategoria();
};
string Tesis::getCategoria()
{
    return categoria;
}
void Tesis::llenar_data2()
{
	Documento::llenar_data();
	cout<<"Categoria: ";
	cin>>categoria;
}
void Tesis::mostrar_data2()
{
	Documento::mostrar_data();
	cout<<"Categoria: "<<categoria<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
}
//REVISTA///////////////////////////////////////////////////////////////////
class Revista:public Documento
{
	string tema;
public:
	void llenar_data2();
	void mostrar_data2();
	string getTema();
};
string Revista::getTema()
{
    return tema;
}
void Revista::llenar_data2()
{
	Documento::llenar_data();
	cout<<"Tema: ";
	cin>>tema;
}
void Revista::mostrar_data2()
{
	Documento::mostrar_data();
	cout<<"Tema: "<<tema<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
}
//LIBRO///////////////////////////////////////////////////////////////////
class Libro:public Documento
{
	string autor;
public:
	void llenar_data2();
	void mostrar_data2();
	string getAutor();
};
string Libro::getAutor()
{
    return autor;
}
void Libro::llenar_data2()
{
	Documento::llenar_data();
	cout<<"Titulo: ";
	cin>>autor;
}
void Libro::mostrar_data2()
{
	Documento::mostrar_data();
	cout<<"Autor: "<<autor<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
}

//  ------------------------------------- Prestamos
class Prestamo{
    int codigo;
    string nombre;
    string cargo;
    string documento;
    string nombre_documento;
public:
    void nuevo_pretamo(string,int,string,string,string);
    void mostrar_data2();
    int getCodigo();
    string getDocumento();
    string getNombre_documento();
};
int Prestamo::getCodigo()
{
    return codigo;
}
string Prestamo::getDocumento()
{
    return documento;
}
string Prestamo::getNombre_documento()
{
    return nombre_documento;
}
void Prestamo::nuevo_pretamo(string nombre_,int DNI,string cargo_,string documento_,string nombre_documento_)
{
    codigo = DNI;
    nombre = nombre_;
    cargo = cargo_;
    documento = documento_;
    nombre_documento = nombre_documento_;
}
void Prestamo::mostrar_data2()
{
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Codigo: "<<codigo<<endl;
	cout<<"Cargo: "<<cargo<<endl;
	cout<<"Documento: "<<documento<<endl;
	cout<<"Nombre del documento: "<<nombre_documento<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
}

//Sistema/////////////////////////////////////////////////////////////////////////////
class Sistema
{
	Alumno *listaAlumno[100];
	Profesor *listaProfesor[100];
	Libro *listaLibros[100];
	Tesis *listaTesis[100];
	Revista *listaRevistas[100];
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
		listaLibros[i]=new Libro;
        listaTesis[i]=new Tesis;
        listaRevistas[i]=new Revista;
		listaPrestamos[i]=new Prestamo;
	}
	actualAlumno=actualProfesor=actualLibros=actualTesis=actualRevistas=actualprestamo=0;
}
/////////////////////////////SISTEMA-ingresar/////////////////////////////////////////////77777777777777777
void Sistema::ingresar(int tipo)
{
	if (tipo==1)
	{
		listaAlumno[actualAlumno]->llenar_data2();
		actualAlumno++;
	}
	else if (tipo==2)
	{
		listaProfesor[actualProfesor++]->llenar_data2();
	}
	else if (tipo==3)
	{
        	listaLibros[actualLibros++]->llenar_data2();
	}
    	else if (tipo==4)
    	{
        	listaTesis[actualTesis++]->llenar_data2();
	}
	else if (tipo==5)
	{
        	listaRevistas[actualRevistas++]->llenar_data2();
	}
	else if (tipo==6)
	{
        string aux,aux2;
        cout<<"Nombre: ";
        cin>>aux;
        cout<<"Cargo: ";
        cin>>aux2;

        if(aux2 == "profesor")
        {
            string aux3,aux4;
            cout<<"Documento: ";
            cin>>aux3;
            cout<<"Nombre del documento: ";
            cin>>aux4;
            if (aux3 == "libro")
            {
                for(int i = 0; i < actualProfesor; i++)
                {
                    if (aux == listaProfesor[i]->getNombre())
                            listaPrestamos[actualprestamo++]->nuevo_pretamo(aux,listaProfesor[i]->getDNI(),aux2,aux3,aux4);
                }
                for(int i = 0; i < actualLibros; i++)
                {
                    if (aux4 == listaLibros[i]->getNombre())
                        listaLibros[i]->quitar();
                }
            }
            else if(aux3 == "tesis")
            {
                for(int i = 0; i < actualProfesor; i++)
                {
                    if (aux == listaProfesor[i]->getNombre())
                            listaPrestamos[actualprestamo++]->nuevo_pretamo(aux,listaProfesor[i]->getDNI(),aux2,aux3,aux4);
                }
                for(int i = 0; i < actualTesis; i++)
                {
                    if (aux4 == listaTesis[i]->getNombre())
                        listaTesis[i]->quitar();
                }
            }
            else if (aux3 == "revista")
            {
                for(int i = 0; i < actualProfesor; i++)
                {
                    if (aux == listaProfesor[i]->getNombre())
                            listaPrestamos[actualprestamo++]->nuevo_pretamo(aux,listaProfesor[i]->getDNI(),aux2,aux3,aux4);
                }
                for(int i = 0; i < actualRevistas; i++)
                {
                    if (aux4 == listaRevistas[i]->getNombre())
                        listaRevistas[i]->quitar();
                }
            }
        }
        else if(aux2 == "alumno")
        {
            string aux3,aux4;
            cout<<"Documento: ";
            cin>>aux3;
            cout<<"Nombre del documento: ";
            cin>>aux4;
            if (aux3 == "libro")
            {
                for(int i = 0; i < actualAlumno; i++)
                {
                    if (aux == listaAlumno[i]->getNombre())
                            listaPrestamos[actualprestamo++]->nuevo_pretamo(aux,listaAlumno[i]->getDNI(),aux2,aux3,aux4);
                }
                for(int i = 0; i < actualLibros; i++)
                {
                    if (aux4 == listaLibros[i]->getNombre())
                        listaLibros[i]->quitar();
                }
            }
            else if(aux3 == "tesis")
            {
                for(int i = 0; i < actualAlumno; i++)
                {
                    if (aux == listaAlumno[i]->getNombre())
                            listaPrestamos[actualprestamo++]->nuevo_pretamo(aux,listaAlumno[i]->getDNI(),aux2,aux3,aux4);
                }
                for(int i = 0; i < actualTesis; i++)
                {
                    if (aux4 == listaTesis[i]->getNombre())
                        listaTesis[i]->quitar();
                }
            }
            else if (aux3 == "revista")
            {
                for(int i = 0; i < actualAlumno; i++)
                {
                    if (aux == listaAlumno[i]->getNombre())
                            listaPrestamos[actualprestamo++]->nuevo_pretamo(aux,listaAlumno[i]->getDNI(),aux2,aux3,aux4);
                }
                for(int i = 0; i < actualRevistas; i++)
                {
                    if (aux4 == listaRevistas[i]->getNombre())
                        listaRevistas[i]->quitar();
                }
            }
        }
	}

	// Completar el registro de un préstamo


}
//////////////////////////////////SISTEMA-listar/////////////////////////////////////////////////////
void Sistema::listar(int tipo)
{
    if(tipo == 1)
    {
        for(int i = 0; i < actualAlumno; i++)
            listaAlumno[i]->mostrar_data2();
    }
    else if (tipo == 2)
    {
        for(int i = 0; i < actualProfesor; i++)
            listaAlumno[i]->mostrar_data2();
    }
    else if (tipo == 3)
    {
        for(int i = 0; i < actualLibros; i++)
            listaLibros[i]->mostrar_data2();
    }
    else if (tipo == 4)
    {
        for(int i = 0; i < actualTesis; i++)
            listaTesis[i]->mostrar_data2();
    }
    else if (tipo == 5)
    {
        for(int i = 0; i < actualRevistas; i++)
            listaRevistas[i]->mostrar_data2();
    }
    else if (tipo == 6)
    {
        for(int i = 0; i < actualprestamo; i++)
            listaPrestamos[i]->mostrar_data2();
    }
}
///////////////////SISTEMA-buscar/////////////////////////////////////////////////////////////////
void Sistema::buscar(int tipo)
{
    if(tipo == 1)
    {
        string aux;
        cout<<"Nombre: ";
        cin>>aux;
        for(int i = 0; i < actualAlumno; i++)
        {
            if(aux == listaAlumno[i]->getNombre())
                listaAlumno[i]->mostrar_data2();
        }
    }
    else if (tipo == 2)
    {
        string aux;
        cout<<"Nombre: ";
        cin>>aux;
        for(int i = 0; i < actualProfesor; i++)
        {
            if(aux == listaProfesor[i]->getNombre())
                listaProfesor[i]->mostrar_data2();
        }
    }
    else if (tipo == 3)
    {
        string aux;
        cout<<"Nombre: ";
        cin>>aux;
        for(int i = 0; i < actualLibros; i++)
        {
            if(aux == listaLibros[i]->getNombre())
                listaLibros[i]->mostrar_data2();
        }
    }
    else if (tipo == 4)
    {
        string aux;
        cout<<"Nombre: ";
        cin>>aux;
        for(int i = 0; i < actualTesis; i++)
        {
            if(aux == listaTesis[i]->getNombre())
                listaTesis[i]->mostrar_data2();
        }
    }
    else if (tipo == 5)
    {
        string aux;
        cout<<"Nombre: ";
        cin>>aux;
        for(int i = 0; i < actualRevistas; i++)
        {
            if(aux == listaRevistas[i]->getNombre())
                listaRevistas[i]->mostrar_data2();
        }
    }
    else if (tipo == 6)
    {
        int aux;
        cout<<"Codigo: ";
        cin>>aux;
        for(int i = 0; i < actualprestamo; i++)
        {
            if(aux == listaPrestamos[i]->getCodigo())
                listaPrestamos[i]->mostrar_data2();
        }
    }
}
///////////////////////SISTEMA-eliminar///////////////////////////////////////////////////////////
void Sistema::eliminar(int tipo)
{
    if (tipo==1)
	{
        string aux;
        cout<<"Nombre: ";
        cin>> aux;
        int aux2;
        for(int i = 0;i < actualAlumno; i++)
        {
            if (aux == listaAlumno[i]->getNombre())
                aux2 =  i;
        }
        for(int i = aux2;i < actualAlumno-1; i++)
            listaAlumno[i] = listaAlumno[i+1];

        actualAlumno--;
	}
    else if (tipo==2)
	{
        string aux;
        cout<<"Nombre: ";
        cin>> aux;
        int aux2;
        for(int i = 0;i < actualProfesor; i++)
        {
            if (aux == listaProfesor[i]->getNombre())
                aux2 =  i;
        }
        for(int i = aux2;i < actualProfesor-1; i++)
            listaProfesor[i] = listaProfesor[i+1];

        actualProfesor--;
	}
    else if (tipo==3)
	{
        string aux;
        cout<<"Nombre: ";
        cin>> aux;
        int aux2;
        for(int i = 0;i < actualLibros; i++)
        {
            if (aux == listaLibros[i]->getNombre())
                aux2 =  i;
        }
        for(int i = aux2;i < actualLibros-1; i++)
            listaLibros[i] = listaLibros[i+1];

        actualLibros--;
	}
    else if (tipo==4)
	{
        string aux;
        cout<<"Nombre: ";
        cin>> aux;
        int aux2;
        for(int i = 0;i < actualTesis; i++)
        {
            if (aux == listaTesis[i]->getNombre())
                aux2 =  i;
        }
        for(int i = aux2;i < actualTesis-1; i++)
            listaTesis[i] = listaTesis[i+1];

        actualTesis--;
	}
    else if (tipo==5)
	{
        string aux;
        cout<<"Nombre: ";
        cin>> aux;
        int aux2;
        for(int i = 0;i < actualRevistas; i++)
        {
            if (aux == listaRevistas[i]->getNombre())
                aux2 =  i;
        }
        for(int i = aux2;i < actualRevistas-1; i++)
            listaRevistas[i] = listaRevistas[i+1];

        actualRevistas--;
	}
    else if (tipo==6)
	{
        int aux;
        cout<<"Codigo: ";
        cin>> aux;
        for(int i = 0;i < actualprestamo; i++)
        {
            if (aux == listaPrestamos[i]->getCodigo())
                aux =  i;
        }
        if(listaPrestamos[aux]->getDocumento() == "libro")
        {
            for(int i = 0;i < actualLibros; i++)
            {
                if (listaPrestamos[aux]->getNombre_documento() == listaLibros[i]->getNombre())
                    listaLibros[i]->sumar();
            }
        }
        if(listaPrestamos[aux]->getDocumento() == "tesis")
        {
            for(int i = 0;i < actualTesis; i++)
            {
                if (listaPrestamos[aux]->getNombre_documento() == listaTesis[i]->getNombre())
                    listaTesis[i]->sumar();
            }
        }
        if(listaPrestamos[aux]->getDocumento() == "revista")
        {
            for(int i = 0;i < actualRevistas; i++)
            {
                if (listaPrestamos[aux]->getNombre_documento() == listaRevistas[i]->getNombre())
                    listaRevistas[i]->sumar();
            }
        }
        for(int i = aux;i < actualprestamo-1; i++)
            listaPrestamos[i] = listaPrestamos[i+1];

        actualprestamo--;
	}
}

int main()
{
    Sistema s;
    int menu;
    while(true)
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
	            cout<<"(6) Eliminar Prestamo "<<endl;
	            cout<<"(7) Regresar "<<endl;
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
