#include <iostream>
using namespace std;

int main() {
    const int f = 3; // Number of rows
    const int c = 4; // Number of columns

    // Dynamically allocate memory for the matrix using a double pointer
    double **M2 = new double*[f];
    for (int i = 0; i < f; i++) {
        M2[i] = new double[c];
    }

    // Initialize the matrix values
    double count = 1.0;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            M2[i][j] = count++;
        }
    }

    // Use a pointer to iterate through the matrix
    double *p = &M2[0][0];

    for (int i = 0; i < f * c; i++) {
        cout << *(p + i) << " ";
    }

    // Properly free the allocated memory
    for (int i = 0; i < f; i++) {
        delete[] M2[i];
    }
    delete[] M2;

    return 0;
}
