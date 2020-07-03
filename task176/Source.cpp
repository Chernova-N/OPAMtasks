/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 176:
Дано натуральне чилос n.
З'ясувати, чи можна представити n
у вигляді добутку трьох послідовно натуральних чисел.*/

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    unsigned int N;
    unsigned int F;
    unsigned int S;
    unsigned int T;
    bool cond = false;

    cout << "Група ІПЗІ-18к. Чернова Анастасія Євгенівна.\n";
    cout << "Завдання 176:";
    cout << "\nДано натуральне чилос n.";
    cout << "\nЗ'ясувати, чи можна представити n у вигляді добутку трьох послідовно натуральних чисел.";
    cout << "\nВведіть N: ";
    cin >> N;
    T = 2;

    while ((N % T) != 0) {
        T++;
    }
    N = N / T;
    if (N > T) {
        F = T;
        T++;
        while ((N % T) != 0) {
           T++;
        }
        N = N / T;
        if (N > T) {
            S = T;
            T = N;
            cond = true;   
        }
    }

    if (cond == true) {
        cout << "\nВведене число N можна представити у вигляді добутку наступних трьох послідовно натуральних чисел:";
        cout << (F*S*T) << "=" << F << "*" << S << "*" << T;
    }
    else {
        cout << "\nЧисло N не можна представити у вигляді добутку наступних трьох послідовно натуральних чисел";
    }
    return 0;
}

