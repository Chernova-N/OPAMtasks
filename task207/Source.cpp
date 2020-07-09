/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 207:
Описати функцію С(m,n), де 0<=m<=n, для обчислення біноміального коефіцієнта С(m,n) за такою формулою:
C(0,n)=C(n,n)=1; C(m,n)=C(m,n-1)+C(m-1,n-1) при 0<m<n*/

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

long C(int m, int n);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int m, n;

    cout << "ІПЗІ-18к Чернова Анастасія Євгенівна" << endl;
    cout << "Завдання 207" << endl;
    cout << "Описати функцію С(m,n), де 0<=m<=n, для обчислення біноміального коефіцієнта С(m,n) за такою формулою: \nC(0, n) = C(n, n) = 1;\nC(m, n) = C(m, n - 1) + C(m - 1, n - 1) \nпри 0 < m < n " << endl;

    cout << "Введіть m:";
    cin >> m;
    cout << "Введіть n:";
    cin >> n;

    cout << "Відповідь: " << C(m, n);

    return 0;
}

long C(int m, int n)
{
    if (m < 0 || n < 0 && n < m)
    {
        return 0;
    }
    if (m == 0 || m == n)
    {
        return 1;
    }
    return C(m, n - 1) + C(m - 1, n - 1);
}