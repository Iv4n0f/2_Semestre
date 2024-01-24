#include <iostream>
#include <fstream>
using namespace std;

string leerArchivo(string file_name)
{
    ifstream file(file_name);
    string line;
    string result;
    while (getline(file, line))
    {
        result += line;
    }
    file.close();
    return result;
}

void escribirArchivo(string file_name, string text)
{
    ofstream file(file_name);
    file << text;
    file.close();
}

string cifrarPrimeroPares(string text)
{
    string result_pares;
    string result_impares;

    for (int i = 0; i < text.size(); i++)
    {
        if (i % 2 == 0)
        {
            result_pares += text[i];
        }
        if (i % 2 == 1)
        {
            result_impares += text[i];
        }
    }
    string result = result_pares + result_impares;
    return result;
}

string cifrarPrimeroImpares(string text)
{
    string result_pares;
    string result_impares;

    for (int i = 0; i < text.size(); i++)
    {
        if (i % 2 == 0)
        {
            result_pares += text[i];
        }
        if (i % 2 == 1)
        {
            result_impares += text[i];
        }
    }
    string result = result_impares + result_pares;
    return result;
}

string descifrarPrimeroPares(string text)
{
    string result = text;
    int quiebre;
    if (text.size() % 2 == 0){
        quiebre = text.size() / 2;
    }
    if (text.size() % 2 == 1){
        quiebre = (text.size() / 2) + 1;
    }

    int i = 0;
    int j = 1;
    for (int k = 0; k < quiebre; k++)
    {
        result[i] = text[k];
        if (i + 2 < text.size())
        {
            i += 2;
        }
    }

    for (int k = quiebre; k < text.size(); k++)
    {
        result[j] = text[k];
        if (j + 2 < text.size())
        {
            j += 2;
        }
    }

    return result;
}

string descifrarPrimeroImpares(string text)
{
    string result = text;
    int quiebre;
    if (text.size() % 2 == 0){
        quiebre = text.size() / 2 + 1;
    }
    if (text.size() % 2 == 1){
        quiebre = (text.size() / 2);
    }

    int i = 1;
    int j = 0;
    for (int k = 0; k < quiebre; k++)
    {
        result[i] = text[k];
        if (i + 2 < text.size())
        {
            i += 2;
        }
    }

    for (int k = quiebre; k < text.size(); k++)
    {
        result[j] = text[k];
        if (j + 2 < text.size())
        {
            j += 2;
        }
    }

    return result;
}

int main()
{
    string texto = leerArchivo("texto.txt");

    string texto_cifrado_pares = cifrarPrimeroPares(texto);
    string texto_cifrado_impares = cifrarPrimeroImpares(texto);
    string texto_descifrado_pares = descifrarPrimeroPares(leerArchivo("texto_cifrado_pares.txt"));
    string texto_descifrado_impares = descifrarPrimeroImpares(leerArchivo("texto_cifrado_impares.txt"));

    escribirArchivo("texto_cifrado_pares.txt", texto_cifrado_pares);
    escribirArchivo("texto_cifrado_impares.txt", texto_cifrado_impares);
    escribirArchivo("texto_descifrado_pares.txt", texto_descifrado_pares);
    escribirArchivo("texto_descifrado_impares.txt", texto_descifrado_impares);

    cout << "Texto original: " << texto << endl;
    cout << "Texto cifrado con el primer par: " << texto_cifrado_pares << endl;
    cout << "Texto cifrado con el primer impar: " << texto_cifrado_impares << endl;
    cout << "Texto descifrado con el primer par: " << descifrarPrimeroPares(texto_cifrado_pares) << endl;
    cout << "Texto descifrado con el primer impar: " << descifrarPrimeroImpares(texto_cifrado_impares) << endl;
}