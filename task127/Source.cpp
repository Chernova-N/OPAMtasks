/*
��ǲ-18�
������� �������� ��������
����� ����
�������� 127:
������ ������� � ������� ���������� ������� NxM, �� �������� ��� ���.
� ������� ����� ������� ������� �� ��������� ���������,
� ����� ��� ����� ������� ��������.
������� ������� �������� � ��������� ���������.*/

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    int n;
    int m;
    int maxIndexI = -1;
    int maxIndexJ = -1;
    int tempIndexI;
    int tempIndexJ;

    cout << "����� ��ǲ-18�. ������� �������� ��������.\n";
    cout << "�������� 127:";
    cout << "\n������ ������� � ������� ���������� ������� NxM, �� �������� ��� ���.";
    cout << "\n� ������� ����� ������� ������� �� ��������� ���������, � ����� ��� ����� ������� ��������.";
    cout << "\n������� ������� �������� � ��������� ���������.";
    cout << "\n������ N: ";
    cin >> n;
    cout << "������ M: ";
    cin >> m;

    // ��������� ����������� ������
    double** mass;
    mass = new double* [n];
    for (int i = 0; i < n; i++) {
        mass[i] = new double[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "������ ������� ������ �" << i << j << ":";
            cin >> mass[i][j];     
        }
    }
    
    cout << "\n������� �������:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mass[i][j] << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        tempIndexI = i;
        tempIndexJ = 0;
        for (int j = 0; j < m; j++) {
            if (mass[i][j] < mass[tempIndexI][tempIndexJ]) {           
                tempIndexI = i;
                tempIndexJ = j;
            }
        }
        if (maxIndexI == -1) {
            maxIndexI = tempIndexI;
            maxIndexJ = tempIndexJ;
        }
        if (mass[maxIndexI][maxIndexJ] < mass[tempIndexI][tempIndexJ]) {
            maxIndexI = tempIndexI;
            maxIndexJ = tempIndexJ;
        }
    }
    cout << "\n�������� ������� - �" << maxIndexI << maxIndexJ;


    for (int i = 0; i < n; i++) {
        delete[] mass[i];
    }
    delete[] mass;
    return 0;
}

