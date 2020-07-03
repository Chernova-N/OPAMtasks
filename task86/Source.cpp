/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 86:
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
    unsigned int n;

    cout << "Група ІПЗІ-18к. Чернова Анастасія Євгенівна.\n";
    cout << "Завдання 86:";
    cout << "\nСформувати квадратну матрицю порядку n за заданим зарзком.";
    cout << "\nВведіть N: ";
    cin >> n;

    // Створення двовимірного масиву
    int** mass;
    mass = new int* [n]; 
    for (int i = 0; i < n; i++) {
        mass[i] = new int[n];
    }

    //Обробка елементів масиву
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                mass[i][j] = (i + 1) * (j + 2);
            }
            else {
                mass[i][j] = 0;
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

