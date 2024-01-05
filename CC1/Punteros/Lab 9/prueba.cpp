#include <iostream>
using namespace std;

int main() {
    const int f = 3; // Number of rows
    const int c = 4; // Number of columns

    // Declare a 2D array
    double M2[f][c];

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

    return 0;
}
