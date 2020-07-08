/*
��ǲ-18�
������� �������� ��������
����� ����
�������� 244:
������ ��� ����� � � �. ������� ��������, �� ��������, �� �����
� ����, �� ������� � �, ������� �(����� ����� ��������������� �� ����� ������ ����, ��� ����� ������������).
������., �: ��������; B: ����� - ������� �����; B: ���� - �� �����.*/

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

bool isCanCreateFromFirstToSecond(string& A, string& B);

int main()
{
    SetConsoleOutputCP(1251);
    string A, B;


    cout << "��ǲ-18� ������� �������� ��������" << endl;
    cout << "�������� 244" << endl;
    cout << "������ ��� ����� � � �. ������� ��������, �� ��������, �� �����" << endl;
    cout << "� ����, �� ������� � �, ������� �(����� ����� ��������������� �� ����� ������ ����, ��� ����� ������������)." << endl;
    cout << "������., �: ��������; B: ����� - ������� �����; B: ���� - �� �����." << endl;

    cout << "������ ����� �����: ";
    cin >> A;
    cout << "������ ����� �����: ";
    cin >> B;

    cout << (isCanCreateFromFirstToSecond(A, B) ? "�����" : "�������") << endl;
    return 0;
}

bool isCanCreateFromFirstToSecond(string& A, string& B) {
    bool isHasWord = false;
    if (B.size() <= A.size()) {
        for (int i = 0; i < B.size(); i++) {
            isHasWord = false;
            for (int j = 0; j < A.size(); j++) {
                if (A[j] == B[i]) {
                    isHasWord = true;
                    A[j] = '*';
                    break;
                }
            }
            if (!isHasWord)
                return false;
        }
        return true;
    }
    return false;
}
