#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<char>> crearMatriz(vector<char> V)
{
    int n = V.size();
    vector<vector<char>> matriz(n, vector<char>(n, ' '));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = V[(i + j) % n];
        }
    }
    return matriz;
}

void mostrarMatriz(vector<vector<char>> matriz)
{
    for (int i = 0; i < matriz.size(); i++)
    {
        for (int j = 0; j < matriz.size(); j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
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
        result += ' ';
    }
    file.close();
    return result;
}

string keystreamMaker(string mensaje, string key)
{
    string keystream;
    int i = 0;
    while (i < mensaje.size())
    {
        keystream += key[i % key.size()];
        i++;
    }
    return keystream;
}

int findIndex(char c, vector<char> V)
{
    for (int i = 0; i < V.size(); i++){
        if (V[i] == c)
        return i;
    }
}

string cifrarMensaje(string mensaje, string key, vector<vector<char>> matriz, vector<char> vector)
{
    string keystream = keystreamMaker(mensaje, key);
    string textoCifrado;

    for (int i = 0; i < mensaje.size(); i++){
        if (mensaje[i] != ' ')
        {
            int index_mensaje = findIndex(mensaje[i], vector);
            int index_clave = findIndex(keystream[i], vector);

            char cifrado = matriz[index_mensaje][index_clave];
            textoCifrado += cifrado;
        }
        else{
            textoCifrado += ' ';
        }
    }
    return textoCifrado;
}

string descifrarMensaje(string m_cifrado, string key, vector<vector<char>> matriz, vector<char> vector){
    string keystream = keystreamMaker(m_cifrado, key);
    string textoDescifrado;
    for (int i = 0; i < m_cifrado.size(); i++){
        if (m_cifrado[i] != ' '){
            int index = findIndex(m_cifrado[i], matriz[findIndex(keystream[i],vector)]);
            textoDescifrado += vector[index];
        }
        else{
            textoDescifrado += ' ';
        }
    }
    return textoDescifrado;
}

int main()
{
    vector<char> V = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<vector<char>> matriz = crearMatriz(V);
    mostrarMatriz(matriz);

    string mensaje = leerArchivo("texto.txt");
    string key;
    cout << "Ingrese la clave: ";
    cin >> key;

    cout << endl;
    cout << "Mensaje: " << mensaje << endl;
    cout << "Key: " << key << endl;
    cout << endl;

    string texto_cifrado = cifrarMensaje(mensaje, key, matriz, V);
    cout << "Texto Cifrado: " << texto_cifrado << endl;

    string texto_descifrado = descifrarMensaje(texto_cifrado, key, matriz, V);
    cout << "Texto Descifrado: " << texto_descifrado << endl;
}