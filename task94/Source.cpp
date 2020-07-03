/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 94:
Сформувати квадратну матрицю порядку n за заданим зарзком.
*/

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    int n;
    int secn;

    cout << "Група ІПЗІ-18к. Чернова Анастасія Євгенівна.\n";
    cout << "Завдання 94:";
    cout << "\nСформувати квадратну матрицю порядку n за заданим зарзком.";
    cout << "\nВведіть N: ";
    cin >> n;

    // Створення двовимірного масиву
    int** mass;
    mass = new int* [n];
    for (int i = 0; i < n; i++) {
        mass[i] = new int[n];
    }
    secn = n - (n / 2);

    //Обробка елементів масиву
    for (int i = 0; i < secn; i++) {
        for (int j = 0; j < n; j++) {
            if ((j < i) || (j>=(n-i))) {
                mass[i][j] = 0;
            }
            else {
                mass[i][j] = 1;
            }
        }
    }
    for (secn; secn < n; secn++) {
        for (int j = 0; j < n; j++) {
            if ((secn - j) < 0) {
                mass[secn][j] = 0;
            }
            else {
                mass[secn][j] = n - secn + j;
            }
        }
    }

    cout << "\nОтримана матриця:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mass[i][j] << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] mass[i];
    }
    delete[] mass;
    return 0;
}

