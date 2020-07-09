/*
��ǲ-18�
������� �������� ��������
����� ����
�������� 207:
������� ������� �(m,n), �� 0<=m<=n, ��� ���������� ����������� ����������� �(m,n) �� ����� ��������:
C(0,n)=C(n,n)=1; C(m,n)=C(m,n-1)+C(m-1,n-1) ��� 0<m<n*/

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

    cout << "��ǲ-18� ������� �������� ��������" << endl;
    cout << "�������� 207" << endl;
    cout << "������� ������� �(m,n), �� 0<=m<=n, ��� ���������� ����������� ����������� �(m,n) �� ����� ��������: \nC(0, n) = C(n, n) = 1;\nC(m, n) = C(m, n - 1) + C(m - 1, n - 1) \n��� 0 < m < n " << endl;

    cout << "������ m:";
    cin >> m;
    cout << "������ n:";
    cin >> n;

    cout << "³������: " << C(m, n);

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