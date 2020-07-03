/*
��ǲ-18�
������� �������� ��������
����� ����
�������� 86:
���������� ��������� ������� ������� n �� ������� �������.
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
    cout << "�������� 86:";
    cout << "\n���������� ��������� ������� ������� n �� ������� �������.";
    cout << "\n������ N: ";
    cin >> n;

    // ��������� ����������� ������
    int** mass;
    mass = new int* [n]; 
    for (int i = 0; i < n; i++) {
        mass[i] = new int[n];
    }

    //������� �������� ������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                mass[i][j] = (i + 1) * (j + 2);
            }
            else {
                mass[i][j] = 0;
            }
        }
    }
    
    cout << "\n�������� �������:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mass[i][j] << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] mass[i];
    }
    delete[] mass;
    return 0;
}

