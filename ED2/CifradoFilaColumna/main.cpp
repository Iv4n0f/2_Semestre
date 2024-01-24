#include <iostream>
#include <fstream>
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

