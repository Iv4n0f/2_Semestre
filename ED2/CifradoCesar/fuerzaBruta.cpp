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

void mostrar(vector<string> v, vector<int> v2)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "------------------------------\n";
        cout << "K = " << v2[i] << endl;
        cout << v[i] << "\n";
        cout << "------------------------------\n";
    }
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

int contar_incidencias(vector<int> v, int valor)
{
    int incidencias = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] = valor)
            incidencias++;
    }
    return incidencias;
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

    for(int i = 0; i < 26; i++)
    {
        cout << "K = " << i << "\t";
        cout << (float)coincidencias[i]/(float)palabras_cifradas.size() * 100 << "%\n";
    }

    cout << "\n MEJOR RESULTADO :\n";

    int index_mayor_coincidencia = mayor(coincidencias);
    cout << "------------------------------\n";
    cout << textos_descifrados[index_mayor_coincidencia] << endl;

    /* //*Por si existiera mas de un resultado (altamente improbable)
    vector<int> factores_K;
    vector<string> result;
    for (int i = 0; i < coincidencias.size(); i++)
    {
        if (coincidencias[i] == mayor_coincidencias)
        {
            result.push_back(textos_descifrados[i]);
            factores_K.push_back(i);
        }
    }

    mostrar(result, factores_K);*/
    
    cout << "------------------------------\n";
    float porcentaje = (float)coincidencias[index_mayor_coincidencia] / (float)palabras_cifradas.size() * 100;
    cout << "Porcentaje de coincidencias: " << porcentaje << "%\n";
}