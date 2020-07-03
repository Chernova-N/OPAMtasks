/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 10:
Задано дійсні числа а0, а1, ..., аn-1
Поміняти місцями найбільший і найменший елементи.
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
    unsigned int maxIndex = 0;
    unsigned int minIndex = 0;
    double tempValue;

    cout << "Група ІПЗІ-18к. Чернова Анастасія Євгенівна.\n";
    cout << "Завдання 10:";
    cout << "\nЗадано дійсні числа а0, а1, ..., аn-1.";
    cout << "\nПоміняти місцями найбільший і найменший елементи.";
    cout << "\nВведіть N: ";

    cin >> n;

    double* mass = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Введіть " << i << " елемент масиву: ";
        cin >> mass[i];
    }

    cout << "Введений вами масив:\n";
    for (int i = 0; i < n; i++) {
        cout << mass[i] << "  ";
    }

    for (int i = 0; i < n; i++) {
        if (mass[maxIndex] < mass[i]) {
            maxIndex = i;
        }
        if (mass[minIndex] > mass[i]) {
            minIndex = i;
        }
    }

    tempValue = mass[minIndex];
    mass[minIndex] = mass[maxIndex];
    mass[maxIndex] = tempValue;

    cout << "\nОброблений масив:\n";
    for (int i = 0; i < n; i++) {
        cout << mass[i] << "  ";
    }

    delete[] mass;
    return 0;
}

