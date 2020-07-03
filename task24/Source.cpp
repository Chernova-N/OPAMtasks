/*
��ǲ-18�
������� �������� ��������
����� ����
�������� 24:
������ ���� ����� �0, �1, ..., �n-1
����� ��� � ������ � ��'���.
������� ������ �����, �������� ���� �� ������
����� ������������� ����� (|ai|>max{�0, �1, ..., �n-1}).
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

    cout << "����� ��ǲ-18�. ������� �������� ��������.\n";
    cout << "�������� 24:";
    cout << "\n������ ���� ����� �0, �1, ..., �n-1.";
    cout << "\n������� ������ �����, �������� ���� �� ������";
    cout << "\n����� ������������� ����� (|ai|>max{�0, �1, ..., �n-1}).";
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

    //����������� ������������� ����� � �����:
    max = mass[0]; 
    for (int i = 0; i < n; i++) {
        if (max < mass[i]) {
            max = mass[i];
        }
    }

    //����� �� 0:
    for (int i = 0; i < n; i++) { 
        if (abs(mass[i]) > max) {
            mass[i] = 0;
        }
    }

    cout << "\n��������� �����:\n";
    for (int i = 0; i < n; i++) {
        cout << mass[i] << "  ";
    }
    delete[] mass;
    return 0;
}

