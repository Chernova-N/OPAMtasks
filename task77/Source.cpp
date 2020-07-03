/*
��ǲ-18�
������� �������� ��������
����� ����
�������� 77:
����� ���� �� ���������� ����������� ������ �����
a0<=a1<=...<=an-1 i b0<=b1<=...<=bm-1. 
��� ������ ����, �� �� ������� �������� ��������
2-� ����������� � 1-� ����������� ���, ��� ����
����������� ���������� �����������.
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

    cout << "����� ��ǲ-18�. ������� �������� ��������.\n";
    cout << "�������� 77:";
    cout << "\n����� ���� �� ���������� ����������� ������ ����� a0<=a1<=...<=an-1 i b0<=b1<=...<=bm-1.";
    cout << "\n��� ������ ����, �� �� ������� �������� �������� 2-� ����������� � 1-� �����������";
    cout << "\n���, ��� ���� ����������� ���������� �����������.";
    cout << "\n������ n: ";
    cin >> n;
    cout << "\n������ m: ";
    cin >> m;
    o = n + m;

    double* massA = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "\n������ " << i + 1 << " ������� ������� ������: ";
        cin >> massA[i];
    }
    cout << "�������� ���� ������ �����:\n";
    for (int i = 0; i < n; i++) {
        cout << massA[i] << "  ";
    }

    double* massB = new double[m];
    for (int i = 0; i < m; i++) {
        cout << "\n������ " << i + 1 << " ������� ������� ������: ";
        cin >> massB[i];
    }
    cout << "\n�������� ���� ������ �����:\n";
    for (int i = 0; i < m; i++) {
        cout << massB[i] << "  ";
    }

    int i = 0;
    int j = 0;

    //��������� ��'�������� ������� ���������� ����������:
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

    // ���������� ��'��������� ������ ������������� ����������:
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

    cout << "\n��'������� �����:\n";
    for (int i = 0; i < o; i++) {
        cout << massC[i] << "  ";
    }

    delete[] massA;
    delete[] massB;
    delete[] massC;
    return 0;

}

