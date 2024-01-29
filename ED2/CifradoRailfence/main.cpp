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

char** crearMatriz(int filas,int columnas){
    char** matriz = new char*[filas];
    for (int i = 0; i < filas; i++){
        matriz[i] = new char[columnas];
        for (int j = 0; j < columnas; j++){
            matriz[i][j] = ' ';
        }
    }
    return matriz;
}

void destruirMatriz(char** matriz, int filas){
    for (int i = 0; i < filas; i++){
        delete[] matriz[i];
        matriz[i] = nullptr;
    }
    delete[] matriz;
    matriz = nullptr;
}

void imprimirMatriz(char** matriz, int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void llenarMatriz(char** matriz, int filas, int columnas, string cadena){
    bool baja;
    int i = 0;

    for (int j = 0; j < columnas; j++){
        if (i == 0) baja = true;
        if (i == filas - 1) baja = false;
        
        matriz[i][j] = cadena[j];
        if (baja) i++;
        else i--;
    }
}

string leerMatriz(char** matriz, int filas, int columnas){
    string cadena;
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            if (matriz[i][j] != ' ')
                cadena += matriz[i][j];
        }
    }
    return cadena;
}


int main()
{   
    string mensaje = leerArchivo("mensaje.txt");
    cout << "Mensaje: " << mensaje << endl;
    int filas;
    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    int columnas = mensaje.length();
    char** matriz = crearMatriz(filas, columnas);
    llenarMatriz(matriz, filas, columnas, mensaje);
    imprimirMatriz(matriz, filas, columnas);
    cout << "Mensaje cifrado: " << leerMatriz(matriz, filas, columnas) << endl;
    destruirMatriz(matriz, filas);
}