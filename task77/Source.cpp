/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 77:
Нехай дано дві неспадаючі послідовності дійсних чисел
a0<=a1<=...<=an-1 i b0<=b1<=...<=bm-1. 
Слід знайти місця, на які потрібно вставити елементи
2-ї послідовності в 1-у послідовність так, щоб нова
послідовність залишалася неспадаючою.
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
    unsigned int m;
    unsigned int o;

    cout << "Група ІПЗІ-18к. Чернова Анастасія Євгенівна.\n";
    cout << "Завдання 77:";
    cout << "\nНехай дано дві неспадаючі послідовності дійсних чисел a0<=a1<=...<=an-1 i b0<=b1<=...<=bm-1.";
    cout << "\nСлід знайти місця, на які потрібно вставити елементи 2-ї послідовності в 1-у послідовність";
    cout << "\nтак, щоб нова послідовність залишалася неспадаючою.";
    cout << "\nВведіть n: ";
    cin >> n;
    cout << "\nВведіть m: ";
    cin >> m;
    o = n + m;

    double* massA = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "\nВведіть " << i + 1 << " елемент першого масиву: ";
        cin >> massA[i];
    }
    cout << "Введений вами перший масив:\n";
    for (int i = 0; i < n; i++) {
        cout << massA[i] << "  ";
    }

    double* massB = new double[m];
    for (int i = 0; i < m; i++) {
        cout << "\nВведіть " << i + 1 << " елемент другого масиву: ";
        cin >> massB[i];
    }
    cout << "\nВведений вами другий масив:\n";
    for (int i = 0; i < m; i++) {
        cout << massB[i] << "  ";
    }

    int i = 0;
    int j = 0;

    //Заповненя об'єднаного массиву елементами найменшого:
    double* massC = new double[o];
    while ((i != n) && (j !=m)) {
        if (massA[i] <= massB[j]) {
            massC[i + j] = massA[i];
            i++;
        }
        else {
            massC[i + j] = massB[j];
            j++;
        }
    }

    // Доповнення об'єднанного масиву залишившимися елементами:
    if (i == n) {
        for (j; j < m; j++) {
            massC[i + j] = massB[j];
        }
    }
    else {
        for (i; i < n; i++) {
            massC[i + j] = massA[i];
        }
    }

    cout << "\nОб'єднаний масив:\n";
    for (int i = 0; i < o; i++) {
        cout << massC[i] << "  ";
    }

    delete[] massA;
    delete[] massB;
    delete[] massC;
    return 0;

}

