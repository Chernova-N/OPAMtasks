/*
��ǲ-18�
������� �������� ��������
����� ����
�������� 159:
�������� ������� ��� ����������� ���������� ������������ ������� k(k!=1), ����-����� ������������ ����� n.*/

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

    cout << "����� ��ǲ-18�. ������� �������� ��������.\n";
    cout << "�������� 159:";
    cout << "\n�������� ������� ��� ����������� ���������� ������������ ������� k(k!=1), ����-����� ������������ ����� N.";
    cout << "\n������ N: ";
    cin >> N;
    K = Func(N);
    cout << "\n��������� ������: " << K;
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

