/*
��ǲ-18�
������� �������� ��������
����� ����
�������� 55:
������ ������������� ����� ��������� N.
�� � ����� �������� ������ ����� �����?
���� ���, �� ������� ������ ��� ��������.
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

    cout << "����� ��ǲ-18�. ������� �������� ��������.\n";
    cout << "�������� 55:";
    cout << "\n������ ������������� ����� ��������� N.";
    cout << "\n�� � ����� �������� ������ ����� �����?";
    cout << "\n���� ���, �� ������� ������ ��� ��������.";
    cout << "\n������ N: ";
    cin >> n;

    int* mass = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "������ " << i + 1 << " ������� ������: ";
        cin >> mass[i];
    }

    cout << "�������� ���� �����:\n";
    for (int i = 0; i < n; i++) {
        cout << mass[i] << "  ";
    }

    cout << "\n������ �������� ������, �� � �������� �������:\n";
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

