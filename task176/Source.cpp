/*
��ǲ-18�
������� �������� ��������
����� ����
�������� 176:
���� ���������� ����� n.
�'�������, �� ����� ����������� n
� ������ ������� ����� ��������� ����������� �����.*/

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

    cout << "����� ��ǲ-18�. ������� �������� ��������.\n";
    cout << "�������� 176:";
    cout << "\n���� ���������� ����� n.";
    cout << "\n�'�������, �� ����� ����������� n � ������ ������� ����� ��������� ����������� �����.";
    cout << "\n������ N: ";
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
        cout << "\n������� ����� N ����� ����������� � ������ ������� ��������� ����� ��������� ����������� �����:";
        cout << (F*S*T) << "=" << F << "*" << S << "*" << T;
    }
    else {
        cout << "\n����� N �� ����� ����������� � ������ ������� ��������� ����� ��������� ����������� �����";
    }
    return 0;
}

