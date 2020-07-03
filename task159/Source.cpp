/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 159:
Написати функцію для знаходження найменшого натурального дільника k(k!=1), будь-якого натурального числа n.*/

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

int Func(unsigned int n);

int main()
{
    SetConsoleOutputCP(1251);
    unsigned int N;
    unsigned int K;

    cout << "Група ІПЗІ-18к. Чернова Анастасія Євгенівна.\n";
    cout << "Завдання 159:";
    cout << "\nНаписати функцію для знаходження найменшого натурального дільника k(k!=1), будь-якого натурального числа N.";
    cout << "\nВведіть N: ";
    cin >> N;
    K = Func(N);
    cout << "\nНайменший дільник: " << K;
    return 0;
}

int Func(unsigned int n){
    int k = 2;
    if ((n % k) != 0) {
        k++;
        while ((n % k) != 0) {
            k = k + 2;
        }
    }
    return k;
}

