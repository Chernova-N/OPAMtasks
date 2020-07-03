/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 55:
Задано цілочисельний масив розмірності N.
Чи є серед елементів масиву прості числа?
Якщо так, то вивести номери цих елементів.
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
    cout << "Завдання 55:";
    cout << "\nЗадано цілочисельний масив розмірності N.";
    cout << "\nЧи є серед елементів масиву прості числа?";
    cout << "\nЯкщо так, то вивести номери цих елементів.";
    cout << "\nВведіть N: ";
    cin >> n;

    int* mass = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Введіть " << i + 1 << " елемент масиву: ";
        cin >> mass[i];
    }

    cout << "Введений вами масив:\n";
    for (int i = 0; i < n; i++) {
        cout << mass[i] << "  ";
    }

    cout << "\nНомери елементів масиву, які є простими числами:\n";
    for (int i = 0; i < n; i++) {
        int j = 2;
        while ((mass[i] % j) != 0) {
            j++;
        }
        if (j == mass[i]){
            cout << i+1 << "  ";
        }
        j = 2;
    }

    delete[] mass;
    return 0;
}

