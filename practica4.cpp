#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    const int fil = 5;
    const int col = 5;
    int kernel[3] = {1, 2, 1};
    int **output = new int*[fil - 2]; //reserva memoria para el resultado
    for (int i = 0; i < fil - 2; i++) {
        output[i] = new int[col];
    }

    int **matriz = new int*[fil]; // reserva memoria para la matriz a crear con numeros aleatorios del 0 al 9    
    for (int i = 0; i < fil; i++) {
        matriz[i] = new int[col];
    }

    for (int i = 0; i < fil; i++) {         //
        for (int j = 0; j < col; j++) {     // Llena la matriz con numeros aleatorios del 0 al 9
            matriz[i][j] = rand() % 9;      //
        }
    }

    cout << "Matriz: " << endl;             //
    for (int i = 0; i < fil; i++) {         //  
        for (int j = 0; j < col; j++) {     //
            cout << matriz[i][j] << " ";    //
        }                                   //  imprime la matriz
        cout << endl;                       //  
    }                                       //
    cout << endl;                           //

    //convolucion y se almacena en la matriz "output"
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < fil - 2; i++) {
            output[i][j] = kernel[0] * matriz[i][j] + kernel[1] * matriz[i + 1][j] + kernel[2] * matriz[i + 2][j];
        }
    }

    cout << "Output: " << endl;             //
    for (int i = 0; i < fil - 2; i++) {     //
        for (int j = 0; j < col; j++) {     //
            cout << output[i][j] << " ";    //Imprime el resultado
        }                                   //
        cout << endl;                       //
    }                                       //


    //liberamos memoria
    for (int i = 0; i < fil; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    for (int i = 0; i < fil - 2; i++) {
        delete[] output[i];
    }
    delete[] output;

    return 0;
}
