#include <iostream>
#include <ctime>
#include <limits>

using namespace std;

bool compare(string a, string b)
{
	if (a == b)
		return true;
	return false;
}
// PERSONA///////////////////////////////////////////////////////////////////
class Persona
{
protected:
	string nombre;
	string codigo;

public:
	void llenar_data();
	void mostrar_data();
	string getCodigo();
	string getNombre();
	virtual void gastarCredito(){};
	virtual void devolverCredito(){};
};
void Persona::llenar_data()
{
	cout << "Nombre: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, nombre);
	codigo = nombre.substr(0, 2) + to_string(nombre.length());
	cout << "Codigo: " << codigo << endl;
}
void Persona::mostrar_data()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Codigo: " << codigo << endl;
}

string Persona::getCodigo() { return codigo; }
string Persona::getNombre() { return nombre; }

// ALUMNO///////////////////////////////////////////////////////////////////
class Alumno : public Persona
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
	cout << "Creditos: " << creditos << endl;
	cout << "---------------------------------------------------------------------" << endl;
}
void Alumno::gastarCredito() { creditos--; }
void Alumno::devolverCredito() { creditos++; }
int Alumno::getCreditos() { return creditos; }

// PROFESOR///////////////////////////////////////////////////////////////////
class Profesor : public Persona
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
	cout << "Creditos: " << creditos << endl;
	cout << "---------------------------------------------------------------------" << endl;
}
void Profesor::gastarCredito() { creditos--; }
void Profesor::devolverCredito() { creditos++; }
int Profesor::getCreditos() { return creditos; }

// DOCUMENTO/////////////////////////////////////////////////////////////////////////////
class Documento
{
protected:
	string codigo;
	string titulo;

public:
	void llenar_data();
	void mostrar_data();
	string getCodigo();
	string getTitulo();
};
void Documento::llenar_data()
{
	cout << "Titulo: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, titulo);
	codigo = titulo.substr(0, 2) + to_string(titulo.length());
	cout << "Codigo: " << codigo << endl;
}
void Documento::mostrar_data()
{
	cout << "Titulo: " << titulo << endl;
	cout << "Codigo: " << codigo << endl;
}
string Documento::getCodigo() { return codigo; }
string Documento::getTitulo() { return titulo; }

// TESIS/////////////////////////////////////////////////////////////////////////////
class Tesis : public Documento
{
	int anno;

public:
	void llenar_data();
	void mostrar_data();
	int getAnno();
};
void Tesis::llenar_data()
{
	Documento::llenar_data();
	cout << "Anno: ";
	cin >> anno;
}
void Tesis::mostrar_data()
{
	Documento::mostrar_data();
	cout << "Anno: " << anno << endl;
	cout << "---------------------------------------------------------------------" << endl;
}
int Tesis::getAnno() { return anno; }
// LIBRO/////////////////////////////////////////////////////////////////////////////
class Libro : public Documento
{
	string autor;

public:
	void llenar_data();
	void mostrar_data();
	string getAutor();
};
void Libro::llenar_data()
{
	Documento::llenar_data();
	cout << "Autor: ";
	getline(cin, autor);
}
void Libro::mostrar_data()
{
	Documento::mostrar_data();
	cout << "Autor: " << autor << endl;
	cout << "---------------------------------------------------------------------" << endl;
}
string Libro::getAutor() { return autor; }
// REVISTA/////////////////////////////////////////////////////////////////////////////
class Revista : public Documento
{
	string editor;

public:
	void llenar_data();
	void mostrar_data();
	string getEditor();
};
void Revista::llenar_data()
{
	Documento::llenar_data();
	cout << "Editor: ";
	getline(cin, editor);
}
void Revista::mostrar_data()
{
	Documento::mostrar_data();
	cout << "Editor: " << editor << endl;
	cout << "---------------------------------------------------------------------" << endl;
}
string Revista::getEditor() { return editor; }
// PRESTAMO/////////////////////////////////////////////////////////////////////////////
class Prestamo
{
	string codigo;
	string fecha;
	Persona *usuario;
	Documento *documento;

public:
	Prestamo() : codigo(""), fecha(""), usuario(nullptr), documento(nullptr) {}
	Prestamo(Persona *, Documento *);
	void mostrar_data();
	string getCodigo();
	string getFecha();
	Persona *getUsuario() { return usuario; }
	Documento *getDocumento() { return documento; }
};
Prestamo::Prestamo(Persona *usuario, Documento *documento) : usuario(usuario), documento(documento)
{
	codigo = usuario->getCodigo().substr(0, 2) + documento->getCodigo().substr(0, 2);
	time_t now = time(0);
	tm *ltm = localtime(&now);
	fecha = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
	cout << "Codigo: " << codigo << endl;
}
void Prestamo::mostrar_data()
{
	cout << "Codigo: " << codigo << endl;
	cout << "Fecha: " << fecha << endl;
	cout << "Usuario: " << usuario->getNombre() << endl;
	cout << "Documento: " << documento->getTitulo() << endl;
	cout << "---------------------------------------------------------------------" << endl;
}
string Prestamo::getCodigo() { return codigo; }
string Prestamo::getFecha() { return fecha; }
// SISTEMA/////////////////////////////////////////////////////////////////////////////
class Sistema
{
	Alumno *listaAlumno[100];
	Profesor *listaProfesor[100];
	Libro *listaLibros[100];
	Tesis *listaTesis[100];
	Revista *listaRevistas[100];
	Prestamo *listaPrestamos[100];
	int actualAlumno, actualProfesor, actualLibros, actualTesis, actualRevistas, actualprestamo;

public:
	Sistema();
	void ingresar(int);
	void listar(int);
	void buscar(int);
	void eliminar(int);
	void prestar();
	void devolver();
};
Sistema::Sistema()
{
	for (int i = 0; i < 100; i++)
	{
		listaAlumno[i] = new Alumno;
		listaProfesor[i] = new Profesor;
		listaLibros[i] = new Libro;
		listaTesis[i] = new Tesis;
		listaRevistas[i] = new Revista;
	}
	actualAlumno = actualProfesor = actualLibros = actualTesis = actualRevistas = actualprestamo = 0;
}
///////////////////////////// SISTEMA-ingresar /////////////////////////////////////////////
void Sistema::ingresar(int tipo)
{
	if (tipo == 1)
	{
		listaAlumno[actualAlumno]->llenar_data();
		actualAlumno++;
	}
	else if (tipo == 2)
	{
		listaProfesor[actualProfesor]->llenar_data();
		actualProfesor++;
	}
	else if (tipo == 3)
	{
		listaLibros[actualLibros]->llenar_data();
		actualLibros++;
	}
	else if (tipo == 4)
	{
		listaTesis[actualTesis]->llenar_data();
		actualTesis++;
	}
	else if (tipo == 5)
	{
		listaRevistas[actualRevistas]->llenar_data();
		actualRevistas++;
	}
	return;
}
//////////////////////////////////SISTEMA-listar/////////////////////////////////////////////////////
void Sistema::listar(int tipo)
{
	if (tipo == 1)
	{
		for (int i = 0; i < actualAlumno; i++)
		{
			listaAlumno[i]->mostrar_data();
		}
	}
	else if (tipo == 2)
	{
		for (int i = 0; i < actualProfesor; i++)
		{
			listaProfesor[i]->mostrar_data();
		}
	}
	else if (tipo == 3)
	{
		for (int i = 0; i < actualLibros; i++)
		{
			listaLibros[i]->mostrar_data();
		}
	}
	else if (tipo == 4)
	{
		for (int i = 0; i < actualTesis; i++)
		{
			listaTesis[i]->mostrar_data();
		}
	}
	else if (tipo == 5)
	{
		for (int i = 0; i < actualRevistas; i++)
		{
			listaRevistas[i]->mostrar_data();
		}
	}
	else if (tipo == 6)
	{
		for (int i = 0; i < actualprestamo; i++)
		{
			listaPrestamos[i]->mostrar_data();
		}
	}
	return;
}
///////////////////SISTEMA-buscar/////////////////////////////////////////////////////////////////
void Sistema::buscar(int tipo)
{
	if (tipo == 1)
	{
		string codigo;
		cout << "Codigo: ";
		cin >> codigo;
		for (int i = 0; i < actualAlumno; i++)
		{
			if (listaAlumno[i]->getCodigo() == codigo)
			{
				listaAlumno[i]->mostrar_data();
				return;
			}
		}
	}
	else if (tipo == 2)
	{
		string codigo;
		cout << "Codigo: ";
		cin >> codigo;
		for (int i = 0; i < actualProfesor; i++)
		{
			if (listaProfesor[i]->getCodigo() == codigo)
			{
				listaProfesor[i]->mostrar_data();
				return;
			}
		}
	}
	else if (tipo == 3)
	{
		string codigo;
		cout << "Codigo: ";
		cin >> codigo;
		for (int i = 0; i < actualLibros; i++)
		{
			if (listaLibros[i]->getCodigo() == codigo)
			{
				listaLibros[i]->mostrar_data();
				return;
			}
		}
	}
	else if (tipo == 4)
	{
		string codigo;
		cout << "Codigo: ";
		cin >> codigo;
		for (int i = 0; i < actualTesis; i++)
		{
			if (listaTesis[i]->getCodigo() == codigo)
			{
				listaTesis[i]->mostrar_data();
				return;
			}
		}
	}
	else if (tipo == 5)
	{
		string codigo;
		cout << "Codigo: ";
		cin >> codigo;
		for (int i = 0; i < actualRevistas; i++)
		{
			if (listaRevistas[i]->getCodigo() == codigo)
			{
				listaRevistas[i]->mostrar_data();
				return;
			}
		}
	}
	else if (tipo == 6)
	{
		string codigo;
		cout << "Codigo: ";
		cin >> codigo;
		for (int i = 0; i < actualprestamo; i++)
		{
			if (listaPrestamos[i]->getCodigo() == codigo)
			{
				listaPrestamos[i]->mostrar_data();
				return;
			}
		}
	}
	cout << "No se encontro" << endl;
	return;
}
///////////////////////SISTEMA-eliminar///////////////////////////////////////////////////////////
void Sistema::eliminar(int tipo)
{
	if (tipo == 1)
	{
		string codigo;
		cout << "Codigo: ";
		cin >> codigo;
		for (int i = 0; i < actualAlumno; i++)
		{
			if (listaAlumno[i]->getCodigo() == codigo)
			{
				for (int j = i; j < actualAlumno; j++)
				{
					listaAlumno[j] = listaAlumno[j + 1];
				}
				actualAlumno--;
				return;
			}
		}
	}
	else if (tipo == 2)
	{
		string codigo;
		cout << "Codigo: ";
		cin >> codigo;
		for (int i = 0; i < actualProfesor; i++)
		{
			if (listaProfesor[i]->getCodigo() == codigo)
			{
				for (int j = i; j < actualProfesor; j++)
				{
					listaProfesor[j] = listaProfesor[j + 1];
				}
				actualProfesor--;
				return;
			}
		}
	}
	else if (tipo == 3)
	{
		string codigo;
		cout << "Codigo: ";
		cin >> codigo;
		for (int i = 0; i < actualLibros; i++)
		{
			if (listaLibros[i]->getCodigo() == codigo)
			{
				for (int j = i; j < actualLibros; j++)
				{
					listaLibros[j] = listaLibros[j + 1];
				}
				actualLibros--;
				return;
			}
		}
	}
	else if (tipo == 4)
	{
		string codigo;
		cout << "Codigo: ";
		cin >> codigo;
		for (int i = 0; i < actualTesis; i++)
		{
			if (listaTesis[i]->getCodigo() == codigo)
			{
				for (int j = i; j < actualTesis; j++)
				{
					listaTesis[j] = listaTesis[j + 1];
				}
				actualTesis--;
				return;
			}
		}
	}
	else if (tipo == 5)
	{
		string codigo;
		cout << "Codigo: ";
		cin >> codigo;
		for (int i = 0; i < actualRevistas; i++)
		{
			if (listaRevistas[i]->getCodigo() == codigo)
			{
				for (int j = i; j < actualRevistas; j++)
				{
					listaRevistas[j] = listaRevistas[j + 1];
				}
				actualRevistas--;
				return;
			}
		}
	}
	return;
}
///////////////////////SISTEMA-prestar///////////////////////////////////////////////////////////
void Sistema::prestar()
{
	int tipo_usuario;
	int tipo_documento;
	string usuario;
	string documento;
	// Menu para usuario
	cout << "1. Alumno" << endl;
	cout << "2. Profesor" << endl;
	cin >> tipo_usuario;
	cout << endl;
	// Menu para documento
	cout << "1. Libro" << endl;
	cout << "2. Tesis" << endl;
	cout << "3. Revista" << endl;
	cin >> tipo_documento;

	if (tipo_usuario == 1)
	{
		usuario;
		cout << "Codigo de Usuario(Alumno): ";
		cin >> usuario;
		for (int i = 0; i < actualAlumno; i++)
		{
			if (listaAlumno[i]->getCodigo() == usuario)
			{
				if (listaAlumno[i]->getCreditos() <= 0)
				{
					cout << "No tiene creditos" << endl;
					return;
				}
				if (tipo_documento == 1)
				{
					cout << "Codigo de Libro: ";
					cin >> documento;
					for (int j = 0; j < actualLibros; j++)
					{
						if (listaLibros[j]->getCodigo() == documento)
						{
							listaPrestamos[i] = new Prestamo(listaAlumno[i], listaLibros[j]);
							actualprestamo++;
							listaAlumno[i]->gastarCredito();
						}
					}
				}
				else if (tipo_documento == 2)
				{
					cout << "Codigo de Tesis: ";
					cin >> documento;
					for (int j = 0; j < actualTesis; j++)
					{
						if (listaTesis[j]->getCodigo() == documento)
						{
							listaPrestamos[i] = new Prestamo(listaAlumno[i], listaTesis[j]);
							actualprestamo++;
							listaAlumno[i]->gastarCredito();
						}
					}
				}
				else if (tipo_documento == 3)
				{
					cout << "Codigo de Revista: ";
					cin >> documento;
					for (int j = 0; j < actualRevistas; j++)
					{
						if (listaRevistas[j]->getCodigo() == documento)
						{
							listaPrestamos[i] = new Prestamo(listaAlumno[i], listaRevistas[j]);
							actualprestamo++;
							listaAlumno[i]->gastarCredito();
						}
					}
				}

				return;
			}
		}
		cout << "Usuario no encontrado" << endl; return;
	}
	else if (tipo_usuario == 2)
	{
		usuario;
		cout << "Codigo de Usuario(Profesor): ";
		cin >> usuario;
		for (int i = 0; i < actualProfesor; i++)
		{
			if (listaProfesor[i]->getCodigo() == usuario)
			{
				if (listaProfesor[i]->getCreditos() <= 0)
				{
					cout << "No tiene creditos" << endl;
					return;
				}
				if (tipo_documento == 1)
				{
					cout << "Codigo de Libro: ";
					cin >> documento;
					for (int j = 0; j < actualLibros; j++)
					{
						if (listaLibros[j]->getCodigo() == documento)
						{
							listaPrestamos[i] = new Prestamo(listaProfesor[i], listaLibros[j]);
							actualprestamo++;
							listaProfesor[i]->gastarCredito();
						}
					}
				}
				else if (tipo_documento == 2)
				{
					cout << "Codigo de Tesis: ";
					cin >> documento;
					for (int j = 0; j < actualTesis; j++)
					{
						if (listaTesis[j]->getCodigo() == documento)
						{
							listaPrestamos[i] = new Prestamo(listaProfesor[i], listaTesis[j]);
							actualprestamo++;
							listaProfesor[i]->gastarCredito();
						}
					}
				}
				else if (tipo_documento == 3)
				{
					cout << "Codigo de Revista: ";
					cin >> documento;
					for (int j = 0; j < actualRevistas; j++)
					{
						if (listaRevistas[j]->getCodigo() == documento)
						{
							listaPrestamos[i] = new Prestamo(listaProfesor[i], listaRevistas[j]);
							actualprestamo++;
							listaProfesor[i]->gastarCredito();
						}
					}
				}

				return;
			}
		}
		cout << "Usuario no encontrado" << endl; return;
	}
	return;
}
///////////////////////SISTEMA-devolver///////////////////////////////////////////////////////////
void Sistema::devolver()
{
	string codigo;
	cout << "Codigo de prestamo: ";
	cin >> codigo;

	for (int i = 0; i < actualprestamo; i++)
	{
		if (listaPrestamos[i]->getCodigo() == codigo)
		{
			listaPrestamos[i]->getUsuario()->devolverCredito();
			for (int j = i; j < actualprestamo; j++)
			{
				listaPrestamos[j] = listaPrestamos[j + 1];
			}
			actualprestamo--;
			return;
		}
	}
	cout << "Prestamo no encontrado" << endl;
	return;
}

int main()
{
	Sistema s;
	int menu = -1;
	int submenu = -1;
	while (menu != 7)
	{

		cout << "(1) Ingresar datos " << endl;
		cout << "(2) Mostrar  Datos " << endl;
		cout << "(3) Buscar  datos " << endl;
		cout << "(4) Eliminar datos " << endl;
		cout << "(5) Prestar " << endl;
		cout << "(6) Devolver " << endl;
		cout << "(7) Salir " << endl;
		cout << "Opcion : ";
		cin >> menu;
		cout << "\n \n";
		switch (menu)
		{
		case 1:
			cout << "\t(1) Ingresar Alumno " << endl;
			cout << "\t(2) Ingresar Profesor " << endl;
			cout << "\t(3) Ingresar Libro " << endl;
			cout << "\t(4) Ingresar Tesis " << endl;
			cout << "\t(5) Ingresar Revista " << endl;
			cout << "\t(7) Regresar " << endl;
			cout << "\tOpcion : ";
			cin >> submenu;
			s.ingresar(submenu);
			submenu = -1;
			cout << "\n";
			break;
		case 2:
			cout << "\t(1) Mostrar Alumno " << endl;
			cout << "\t(2) Mostrar Profesor " << endl;
			cout << "\t(3) Mostrar Libro " << endl;
			cout << "\t(4) Mostrar Tesis " << endl;
			cout << "\t(5) Mostrar Revista " << endl;
			cout << "\t(6) Mostrar Prestamos " << endl;
			cout << "\t(7) Regresar " << endl;
			cout << "\tOpcion : ";
			cin >> submenu;
			s.listar(submenu);
			submenu = -1;
			cout << "\n";
			break;
		case 3:
			cout << "\t(1) Buscar Alumno " << endl;
			cout << "\t(2) Buscar Profesor " << endl;
			cout << "\t(3) Buscar Libro " << endl;
			cout << "\t(4) Buscar Tesis " << endl;
			cout << "\t(5) Buscar Revista " << endl;
			cout << "\t(6) Buscar Prestamo " << endl;
			cout << "\t(7) Regresar " << endl;
			cout << "\tOpcion : ";
			cin >> submenu;
			s.buscar(submenu);
			submenu = -1;
			cout << "\n";
			break;
		case 4:
			cout << "\t(1) Eliminar Alumno " << endl;
			cout << "\t(2) Eliminar Profesor " << endl;
			cout << "\t(3) Eliminar Libro " << endl;
			cout << "\t(4) Eliminar Tesis " << endl;
			cout << "\t(5) Eliminar Revista " << endl;
			cout << "\t(6) Regresar " << endl;
			cout << "\tOpcion : ";
			cin >> submenu;
			s.eliminar(submenu);
			submenu = -1;
			cout << "\n";
			break;
		case 5:
			s.prestar();
			break;
		case 6:
			s.devolver();
			break;
		case 7:
			cout << "Gracias por usar el Sistema" << endl;
			return 0;
		default:
			cout << "Opcion no valida, Saliendo del programa..." << endl;
			return 0;
		}
	}
}