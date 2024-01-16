#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string leerArchivo(string file_name)
{
    ifstream file(file_name);
    string line;
    string result;
    while (getline(file, line))
    {
        result += line;
        result += ' ';
    }
    file.close();
    return result;
}

vector <string> split(string str, char delimiter)
{
    string palabra;
    vector <string> result;
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] != delimiter)
        {
            palabra += str[i];
        }
        else
        {
            result.push_back(palabra);
            palabra = "";
        }
    }
    return result;
}

void mostrar(vector <string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "-";
    }
}

int posicion(char c, char alfabeto[])
{
    for (int i = 0; i < 26; i++)
    {
        if(c == alfabeto[i])
            return i;
    }
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

int main()
{
    string palabrasComunes = leerArchivo("palabrasComunes.txt");
    vector <string> palabras_comunes = split(palabrasComunes, ' ');

    string texto = leerArchivo("mensajeCifrado.txt");
    vector <string> palabras_cifradas = split(texto, ' ');

    // Fuerza bruta
    vector <string> result;
    for (int i = 0; i < 26; i++)
    {   
        vector <string> palabras_descifradas;
        string posible_resultado;
        for (string palabra : palabras_cifradas)
        {

        }
    }

    mostrar(palabras_comunes);
}

