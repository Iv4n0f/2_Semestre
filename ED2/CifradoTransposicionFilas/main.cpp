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
            matriz[i][j] = '-';
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

void llenarMatrizCifrado(char** matriz,int filas, int columnas, string mensaje){
    int contador = 0;
    for (int i = 0; i < columnas; i++){
        for (int j = 0; j < filas; j++){
            if (contador < mensaje.length()){
                matriz[j][i] = mensaje[contador];
                contador++;
            }
            else break;
        }
    }
}

void llenarMatrizDescifrado(char** matriz,int filas, int columnas, string mensajeCifrado){
    int contador = 0;
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            if (contador < mensajeCifrado.length()){
                matriz[i][j] = mensajeCifrado[contador];
                contador++;
            }
            else break;
        }
    }
}


int main(){

    //*CIFRADO POR FILAS
    string mensaje = leerArchivo("mensaje.txt");
    cout <<"Mensaje original: "<< mensaje << endl;
    int filas;
    cout << "Ingrese el numero de filas: ";
    cin >> filas;

    // Calcular numero de columnas
    int columnas;
    if (mensaje.length()%filas == 0){
        columnas = mensaje.length()/filas;
    }
    else {
        columnas = mensaje.length()/filas + 1;
    }

    // *CIFRADO
    char ** matriz = crearMatriz(filas,columnas);
    llenarMatrizCifrado(matriz,filas,columnas,mensaje);
    cout << "Matriz de cifrado" << endl;
    imprimirMatriz(matriz,filas,columnas);

    string mensajeCifrado;
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            mensajeCifrado += matriz[i][j];
        }
    }
    cout <<"Mensaje cifrado:"<< mensajeCifrado << endl << endl;

    //*DESCIFRADO
    char ** matriz2 = crearMatriz(filas,columnas);
    llenarMatrizDescifrado(matriz2,filas,columnas,mensajeCifrado);
    cout << "Matriz de descifrado" << endl;
    imprimirMatriz(matriz2,filas,columnas);

    string mensajeDescifrado;
    for (int i = 0; i < columnas; i++){
        for (int j = 0; j < filas; j++){
            if (matriz2[j][i] != '-')
            mensajeDescifrado += matriz2[j][i];
        }
    }
    cout <<"Mensaje descifrado:"<< mensajeDescifrado << endl;

    destruirMatriz(matriz,filas);
    destruirMatriz(matriz2,filas);
}