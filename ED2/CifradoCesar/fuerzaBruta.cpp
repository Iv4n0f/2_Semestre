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

vector<string> split(string str, char delimiter)
{
    string palabra;
    vector<string> result;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != delimiter)
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

int posicion(char c, char alfabeto[])
{
    for (int i = 0; i < 26; i++)
    {
        if (c == alfabeto[i])
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
        if (isalpha(c) == false)
        {
            result += c;
            continue;
        }
        int pos = posicion(c, alfabeto);
        pos = (pos - k) % letras;
        pos = (pos + letras) % letras;
        result += alfabeto[pos];
    }

    return result;
}

string vectorToString(vector<string> v)
{
    string result;
    for (string s : v)
    {
        result += s;
        result += ' ';
    }
    return result;
}

int mayor(vector<int> v)
{
    int mayor = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > mayor)
            mayor = i;
    }
    return mayor;
}

int main()
{
    string palabrasComunes = leerArchivo("palabrasComunes.txt");
    vector<string> palabras_comunes = split(palabrasComunes, ' ');

    string texto = leerArchivo("mensajeCifrado.txt");
    vector<string> palabras_cifradas = split(texto, ' ');

    // *Fuerza bruta
    vector<string> textos_descifrados;
    vector<int> coincidencias;
    for (int i = 0; i < 26; i++)
    {
        int coincidencia = 0;
        vector<string> palabras_descifradas;

        for (string palabra : palabras_cifradas)
        {
            palabras_descifradas.push_back(descifrar(palabra, i));
        }

        for (string palabra : palabras_descifradas)
        {
            for (string palabra_comun : palabras_comunes)
            {
                if (palabra == palabra_comun)
                {
                    coincidencia++;
                    break;
                }
            }
        }
        coincidencias.push_back(coincidencia);
        textos_descifrados.push_back(vectorToString(palabras_descifradas));
    }


    // *Escribir en el archivo de salida
    ofstream archivo("fuerzaBruta.txt");

    if (archivo.is_open())
    {
        for (int i = 0; i < 26; i++)
        {
            archivo << "K = " << i << "\t";
            archivo << (float)coincidencias[i] / (float)palabras_cifradas.size() * 100 << "%\n";
        }

        archivo << "\n MEJOR RESULTADO :\n";

        int index_mayor_coincidencia = mayor(coincidencias);
        archivo << "------------------------------\n";

        archivo << textos_descifrados[index_mayor_coincidencia] << endl;

        archivo << "------------------------------\n";
        float porcentaje = (float)coincidencias[index_mayor_coincidencia] / (float)palabras_cifradas.size() * 100;
        archivo << "Porcentaje de coincidencias: " << porcentaje << "%\n";

        archivo.close();
    }
}