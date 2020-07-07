/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 201:
Дано А - масив чисел, записаних в Р-ічній системі числення.
Відсортувати його за спаданням. Відповідь видати в Р-ічній і десятковій
системах числення.*/

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

    cout << "Група ІПЗІ-18к. Чернова Анастасія Євгенівна.\n";
    cout << "Завдання 201";
    cout << "\nДано А - масив чисел, записаних в Р-ічній системі числення.";
    cout << "\nВідсортувати його за спаданням. Відповідь видати в Р-ічній і десятковій системах числення.";
    cout << "\nМасив чисел даний у 8-річній системі числення. Розмір масиву - 10.";
    cout << "\nА = [";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << A[i];
        if (i < ARRAY_SIZE - 1) {
            cout << ", ";
        }
    }
    cout << "]";
    
    bubbleSort(A);
    cout << "\nПісля сортування:";
    cout << "\nУ 8-річній системі  = [";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << A[i];
        if (i < ARRAY_SIZE - 1) {
            cout << ", ";
        }
    }
    cout << "]";
    cout << "\nУ 10-річній системі  = [";
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