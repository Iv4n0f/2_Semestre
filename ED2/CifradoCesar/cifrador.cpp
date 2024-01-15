#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int posicion(char c, char alfabeto[])
{
    for (int i = 0; i < 26; i++)
    {
        if(c == alfabeto[i])
            return i;
    }
}

string leerArchivo(string file_name)
{
    ifstream file(file_name);
    string line;
    string result;
    while (getline(file, line))
    {
        result += line;
        result += "\n";
    }
    file.close();
    return result;
}

string textoMinusculasSinTildes(const string &texto)
{
    string resultado;

    for (char c : texto)
    {
        resultado += tolower(static_cast<unsigned char>(c));
    }
    return resultado;
}

string cifrar(string texto, int k)
{
    const int letras = 26;
    string result;

    char alfabeto[letras] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                             'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (char c : texto)
    {   
        if(isalpha(c) == false)
        {
            result += c;
            continue;
        }
        int pos = posicion(c, alfabeto);
        pos = (pos + k) % letras;
        result += alfabeto[pos];
    }

    return result;
}

string descifrar(string texto, int k)
{
    const int letras = 26;
    string result;

    char alfabeto[letras] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                             'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (char c : texto)
    {   
        if(isalpha(c) == false)
        {
            result += c;
            continue;
        }
        int pos = posicion(c, alfabeto);
        pos = (pos - k) % letras;
        result += alfabeto[pos];
    }

    return result;
}

void escribirArchivo(string file_name, string text)
{
    ofstream file(file_name);
    file << text;
    file.close();
}

int main()
{
    int k;
    cout << "Ingrese el factor K: ";
    cin >> k;
    cout << endl;
    
    string texto = leerArchivo("mensaje.txt");
    cout << "Texto original:\n"
         << texto << endl;
    texto = textoMinusculasSinTildes(texto);

    string textoCifrado = cifrar(texto, k);
    cout << "Texto cifrado:\n"
         << textoCifrado << endl;

    string textoDescifrado = descifrar(textoCifrado, k);
    cout << "Texto descifrado:\n"
         << textoDescifrado << endl;

    escribirArchivo("mensajeCifrado.txt", textoCifrado);
}
