/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 127:
Задано матрицю з дійсними елементами розміром NxM, всі елементи якої різні.
В кожному рядку вибрати елемент із найменшим значенням,
а серед цих чисел вибрати найбільше.
Вказати індекси елемента зі знайденим значенням.*/

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    int n;
    int m;
    int maxIndexI = -1;
    int maxIndexJ = -1;
    int tempIndexI;
    int tempIndexJ;

    cout << "Група ІПЗІ-18к. Чернова Анастасія Євгенівна.\n";
    cout << "Завдання 127:";
    cout << "\nЗадано матрицю з дійсними елементами розміром NxM, всі елементи якої різні.";
    cout << "\nВ кожному рядку вибрати елемент із найменшим значенням, а серед цих чисел вибрати найбільше.";
    cout << "\nВказати індекси елемента зі знайденим значенням.";
    cout << "\nВведіть N: ";
    cin >> n;
    cout << "Введіть M: ";
    cin >> m;

    // Створення двовимірного масиву
    double** mass;
    mass = new double* [n];
    for (int i = 0; i < n; i++) {
        mass[i] = new double[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Введіть елемент масиву а" << i << j << ":";
            cin >> mass[i][j];     
        }
    }
    
    cout << "\nВведена матриця:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mass[i][j] << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        tempIndexI = i;
        tempIndexJ = 0;
        for (int j = 0; j < m; j++) {
            if (mass[i][j] < mass[tempIndexI][tempIndexJ]) {           
                tempIndexI = i;
                tempIndexJ = j;
            }
        }
        if (maxIndexI == -1) {
            maxIndexI = tempIndexI;
            maxIndexJ = tempIndexJ;
        }
        if (mass[maxIndexI][maxIndexJ] < mass[tempIndexI][tempIndexJ]) {
            maxIndexI = tempIndexI;
            maxIndexJ = tempIndexJ;
        }
    }
    cout << "\nВибраний елемент - а" << maxIndexI << maxIndexJ;


    for (int i = 0; i < n; i++) {
        delete[] mass[i];
    }
    delete[] mass;
    return 0;
}

