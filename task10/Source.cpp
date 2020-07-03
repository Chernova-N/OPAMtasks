/*
��ǲ-18�
������� �������� ��������
����� ����
�������� 10:
������ ���� ����� �0, �1, ..., �n-1
������� ������ ��������� � ��������� ��������.
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

    cout << "����� ��ǲ-18�. ������� �������� ��������.\n";
    cout << "�������� 10:";
    cout << "\n������ ���� ����� �0, �1, ..., �n-1.";
    cout << "\n������� ������ ��������� � ��������� ��������.";
    cout << "\n������ N: ";

    cin >> n;

    double* mass = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "������ " << i << " ������� ������: ";
        cin >> mass[i];
    }

    cout << "�������� ���� �����:\n";
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

    cout << "\n���������� �����:\n";
    for (int i = 0; i < n; i++) {
        cout << mass[i] << "  ";
    }

    delete[] mass;
    return 0;
}

