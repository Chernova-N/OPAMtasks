/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 24:
Задано дійсні числа а0, а1, ..., аn-1
Серед них є додатні і від'ємні.
Замінити нулями числа, величина яких по модулю
більше максимального числа (|ai|>max{а0, а1, ..., аn-1}).
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
    double max;

    cout << "Група ІПЗІ-18к. Чернова Анастасія Євгенівна.\n";
    cout << "Завдання 24:";
    cout << "\nЗадано дійсні числа а0, а1, ..., аn-1.";
    cout << "\nЗамінити нулями числа, величина яких по модулю";
    cout << "\nбільше максимального числа (|ai|>max{а0, а1, ..., аn-1}).";
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

    //Знаходження макисмального числа в масиві:
    max = mass[0]; 
    for (int i = 0; i < n; i++) {
        if (max < mass[i]) {
            max = mass[i];
        }
    }

    //Заміна на 0:
    for (int i = 0; i < n; i++) { 
        if (abs(mass[i]) > max) {
            mass[i] = 0;
        }
    }

    cout << "\nОтриманий масив:\n";
    for (int i = 0; i < n; i++) {
        cout << mass[i] << "  ";
    }
    delete[] mass;
    return 0;
}

