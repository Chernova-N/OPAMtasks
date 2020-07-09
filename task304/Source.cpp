/*
��ǲ-18�
������� �������� ��������
�������� 304:
������ ��������� ��������������� ������, ����� �������, �������� ������ �� 100�� ����� �� ����. ��������.
����� �������� ������ ���������� ��� ������ ��������.
�� � �������� ���� ����� � ����������*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

struct Car {
    string name;
    string engine;
    float per100km;
    float speed;
};

void printCars(Car* cars, int count);
bool isHasDuplicateCar(Car* cars, int count);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "��ǲ-18� ������� �������� �������� �������� 304:" << endl;
    cout << "������ ��������� ��������������� ������, ����� �������, �������� ������ �� 100�� ����� �� ����. ��������." << endl;
    cout << "����� �������� ������ ���������� ��� ������ ��������. �� � �������� ���� ����� � ����������" << endl << endl;

    int count = 5;
    Car* cars = new Car[count];

    Car* car1 = new Car();
    car1->name = "Porshe";
    car1->engine = "SimpleEngine";
    car1->per100km = 4.2;
    car1->speed = 300;

    Car* car2 = new Car();
    car2->name = "Nissan";
    car2->engine = "Engine";
    car2->per100km = 3.2;
    car2->speed = 380;

    Car* car3 = new Car();
    car3->name = "BMW";
    car3->engine = "Engine-Classic";
    car3->per100km = 5;
    car3->speed = 320;

    Car* car4 = new Car();
    car4->name = "TAVRIA";
    car4->engine = "Engine-UA";
    car4->per100km = 2;
    car4->speed = 220;

    Car* car5 = new Car();
    car5->name = "Porshe";
    car5->engine = "SimpleEngine";
    car5->per100km = 4.2;
    car5->speed = 300;

    cars[0] = *car1;
    cars[1] = *car2;
    cars[2] = *car3;
    cars[3] = *car4;
    cars[4] = *car5;

    printCars(cars, count);

    cout << "� ��������� " << (isHasDuplicateCar(cars, count) ? "� ���� �������" : "���� ������ ���������") << endl;

    return 0;
}

void printCars(Car* cars, int count){
    cout << "�������� : " << endl;
    for (int i = 0; i < count; i++) {
        cout << "---------------------------" << endl;
        cout << "�����: " << cars[i].name <<endl;
        cout << "������ : " << cars[i].engine << endl;
        cout << "�� 100 ��/������: " << cars[i].per100km << endl;
        cout << "����. ��������: " << cars[i].speed << endl ;
        cout << "---------------------------" << endl;
    }
}

bool isHasDuplicateCar(Car* cars, int count) {
    int pointer = 0;
    while (pointer < count) {
        for (int i = 0; i < count; i++) {
            if (pointer != i) {
                if (cars[i].name == cars[pointer].name &&
                    cars[i].engine == cars[pointer].engine &&
                    cars[i].per100km == cars[pointer].per100km &&
                    cars[i].speed == cars[pointer].speed) {
                    return true;
                }
            }
        }
        pointer++;
    }
    return false;
}