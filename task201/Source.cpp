/*
��ǲ-18�
������� �������� ��������
����� ����
�������� 201:
���� � - ����� �����, ��������� � �-���� ������ ��������.
³���������� ���� �� ���������. ³������ ������ � �-���� � ���������
�������� ��������.*/

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <cmath>
#include<string>
#include <stdlib.h> 

using namespace std;


void bubbleSort(int *mass); 
int convertToTen(int num);

int main()
{
    SetConsoleOutputCP(1251);

    const unsigned int ARRAY_SIZE = 10;
    int A[ARRAY_SIZE] = {24,3,11,54,0,144,15,310,1604,2};

    cout << "����� ��ǲ-18�. ������� �������� ��������.\n";
    cout << "�������� 201";
    cout << "\n���� � - ����� �����, ��������� � �-���� ������ ��������.";
    cout << "\n³���������� ���� �� ���������. ³������ ������ � �-���� � ��������� �������� ��������.";
    cout << "\n����� ����� ����� � 8-���� ������ ��������. ����� ������ - 10.";
    cout << "\n� = [";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << A[i];
        if (i < ARRAY_SIZE - 1) {
            cout << ", ";
        }
    }
    cout << "]";
    
    bubbleSort(A);
    cout << "\nϳ��� ����������:";
    cout << "\n� 8-���� ������  = [";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << A[i];
        if (i < ARRAY_SIZE - 1) {
            cout << ", ";
        }
    }
    cout << "]";
    cout << "\n� 10-���� ������  = [";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << convertToTen(A[i]);
        if (i < ARRAY_SIZE - 1) {
            cout << ", ";
        }
    }
    cout << "]";
    system("pause");


    return 0;
}

void bubbleSort(int *mass) {
    int temp = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++)
        {
            if (mass[j] > mass[i]) {
                temp = mass[i];
                mass[i] = mass[j];
                mass[j] = temp;
            }
        }
    }
}

int convertToTen(int num) {
    string _num = to_string(num);
    int size = _num.length();
    int converted_num = 0;
    int current_num = 0;
    for (int i = 0; i < size; i++) {
        current_num = (int)_num[i] - 48;
        converted_num += current_num * pow(8, size - i - 1);
    }
    return converted_num;
}