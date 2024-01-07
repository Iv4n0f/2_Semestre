#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

struct nodo
{
    char letra;
    int cantidad;
    struct nodo *sig;

    struct nodo *izq, *der;
};

nodo *crearNodoNumerico(int cantidad)
{
    nodo *nuevoNodo = new nodo;
    nuevoNodo->letra = '\0';
    nuevoNodo->cantidad = cantidad;
    nuevoNodo->izq = nuevoNodo->der = nullptr;
    nuevoNodo->sig = nullptr;

    return nuevoNodo;
}

void ordenarLista(nodo *&head)
{
    bool intercambio;
    struct nodo *temp;

    do
    {
        intercambio = false;
        struct nodo *actual = head;
        struct nodo *previo = nullptr;

        while (actual != nullptr && actual->sig != nullptr)
        {
            if (actual->cantidad > actual->sig->cantidad)
            {
                temp = actual->sig;
                actual->sig = temp->sig;
                temp->sig = actual;
                if (previo != nullptr)
                {
                    previo->sig = temp;
                }
                else
                {
                    head = temp;
                }

                intercambio = true;
            }

            previo = actual;
            actual = actual->sig;
        }
    } while (intercambio);
}

void crearArbolBinario(nodo *&head)
{
    while (head->sig != nullptr)
    {
        nodo *primero = head;
        nodo *segundo = head->sig;

        nodo *raiz = crearNodoNumerico(primero->cantidad + segundo->cantidad);
        raiz->izq = primero;
        raiz->der = segundo;

        raiz->sig = segundo->sig;

        primero->sig = nullptr;
        segundo->sig = nullptr;

        head = raiz;
        ordenarLista(head);
    }
}

void asignarCodigos(nodo *raiz, string codigo, map<char, string> &codificaciones)
{
    if (raiz != nullptr)
    {
        if (raiz->letra != '\0') // Nodo hoja
        {
            codificaciones[raiz->letra] = codigo;
        }

        asignarCodigos(raiz->izq, codigo + "0", codificaciones);
        asignarCodigos(raiz->der, codigo + "1", codificaciones);
    }
}

string decodificar(nodo *raiz, const string &codigo)
{
    string mensajeDecodificado = "";
    nodo *actual = raiz;

    for (char bit : codigo)
    {
        if (bit == '0')
        {
            actual = actual->izq;
        }
        else if (bit == '1')
        {
            actual = actual->der;
        }

        if (actual->izq == nullptr && actual->der == nullptr) //Hoja
        {
            mensajeDecodificado += actual->letra;
            actual = raiz;
        }
    }

    return mensajeDecodificado;
}

void insertar(nodo *&head, char letra, int cantidad)
{
    nodo *nuevoNodo = new nodo;
    nuevoNodo->letra = letra;
    nuevoNodo->cantidad = cantidad;
    nuevoNodo->izq = nuevoNodo->der = nullptr;

    if (head == nullptr)
    {
        head = nuevoNodo;
        nuevoNodo->sig = nullptr;
    }
    else
    {
        nuevoNodo->sig = head;
        head = nuevoNodo;
    }
}

void imprimirLista(nodo *head)
{
    nodo *actual = head;
    while (actual != nullptr)
    {
        cout << "Letra: " << actual->letra << ", Cantidad: " << actual->cantidad << endl;
        actual = actual->sig;
    }
}

void generarDot(nodo *&head, ofstream &archivoDot)
{
    if (head != nullptr)
    {
        if (head->izq == nullptr && head->der == nullptr) // Nodo hoja
        {
            archivoDot << head->cantidad << " [label=\"" << head->letra << "\\n"
                       << head->cantidad << "\"];\n";
        }
        else
        {
            archivoDot << head->cantidad << " [label=\"" << head->cantidad << "\"];\n";
        }

        if (head->izq != nullptr)
        {
            archivoDot << head->cantidad << " -> " << head->izq->cantidad << " [label=\"0\"];\n";
            generarDot(head->izq, archivoDot);
        }

        if (head->der != nullptr)
        {
            archivoDot << head->cantidad << " -> " << head->der->cantidad << " [label=\"1\"];\n";
            generarDot(head->der, archivoDot);
        }
    }
}

void generarGrafo(nodo *&head, const string &nombreArchivoDot)
{
    ofstream archivoDot(nombreArchivoDot);

    archivoDot << "digraph Huffman {\n";
    generarDot(head, archivoDot);
    archivoDot << "}\n";

    archivoDot.close();
}

int main()
{
    ifstream archivo("letras.txt");

    if (!archivo.is_open())
    {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    nodo *head = nullptr;

    char caracter;
    while (archivo.get(caracter))
    {
        if (caracter == '\n' || caracter == '\r' || caracter == '\t' || caracter == '\v' || caracter == '\f' || caracter == '\a' || caracter == '\b' || caracter == '\0' || caracter == '\x1b')
        {
            continue;
        }

        struct nodo *actual = head;
        while (actual != nullptr)
        {
            if (actual->letra == caracter)
            {
                actual->cantidad++;
                break;
            }
            actual = actual->sig;
        }

        if (actual == nullptr)
        {
            insertar(head, caracter, 1);
        }
    }

    archivo.close();

    ofstream archivoDot("huffman.dot");

    ordenarLista(head);
    imprimirLista(head);
    cout << endl;

    crearArbolBinario(head);

    generarGrafo(head, "huffman.dot");
    system("dot -Tpng huffman.dot -o huffman.png");
    system("open huffman.png");

    // Codificacion - Codigos
    map<char, string> codificaciones;
    asignarCodigos(head, "", codificaciones);

    cout << "Códigos asignados:" << endl;
    for (const auto &pair : codificaciones)
    {
        cout << "Letra: " << pair.first << ", Código: " << pair.second << endl;
    }
    cout << endl;

    // Ejemplo de codificación de un mensaje
    
    string mensaje = "eaeaaceace";
    cout << "Mensaje original: " << mensaje << endl;
    string mensajeCodificado = "";
    for (char c : mensaje)
    {
        mensajeCodificado += codificaciones[c];
    }
    cout << "Mensaje Codificado: " << mensajeCodificado << endl;

    string mensajeDecodificado = decodificar(head, mensajeCodificado);
    cout << "Mensaje Decodificaco: " << mensajeDecodificado << endl;


    /*
    cout <<"Codigo 000 = "; 
    string decod = decodificar(head, "000");
    cout << decod << endl;

    cout <<"Codigo 100011001101 = ";
    decod = decodificar(head, "100011001101");
    cout << decod << endl;
    
    cout << "Codigo 110001001101 = ";
    decod = decodificar(head, "110001001101");
    cout << decod << endl;
    */

    return 0;
}
