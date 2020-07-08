/*
��ǲ-18�
������� �������� ��������
�������� 318:
��� ��� �������� ����� � ������ ��������� � ������:
<�������>,<����� �����>,
<������ 1>,<������ 2>,<������ 3>
� ������ - �� ����� 12 ����, ����� �����-���� �����, ������-���� �����
(����� ������ - �� ������� � ����������, ����� - � �����, ����� - � �������������).
�������� ��������, ��� ������� �� ���������� � ����� �������� �����������.
318. ����� ��������, ���� ��� ��������� �������.*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;


struct Student {
    char name[12];
    unsigned int group_id;
    unsigned short mathMark;
    unsigned short historyMark;
    unsigned short programmingMark;
};

string subjects[3] = { "����������","������","�������������" };

string wosrtSubject(Student* student);
int minIndex(unsigned short* marks, int id_1, int id_2);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "��ǲ-18� ������� �������� �������� �������� 318:" << endl;
    cout << "��� ��� �������� ����� � ������ ��������� � ������: < ������� > ,\n <����� �����>, <������ 1>, <������ 2>, < ������ 3>" << endl;
    cout << "� ������ - �� ����� 12 ����, ����� �����-���� �����, ������-���� ����� \n (����� ������ - �� ������� � ����������, ����� - � �����, ����� - � �������������)." << endl;
    cout << "�������� ��������, ��� ������� �� ���������� � ����� �������� �����������.\n  318. ����� ��������, ���� ��� ��������� �������." << endl;

    Student* student = new Student();
    cout << "��`�: ";
    cin >> student->name;
    cout << "�����: ";
    cin >> student->group_id;
    cout << "������ � ����������: ";
    cin >> student->mathMark;
    cout << "������ � �����: ";
    cin >> student->historyMark;
    cout << "������ � �������������: ";
    cin >> student->programmingMark;

    cout << wosrtSubject(student) << endl;
    return 0;
}

string wosrtSubject(Student* student) {
    unsigned short subject_marks[3] = { student->mathMark, student->historyMark, student->programmingMark};
    return subjects[minIndex(subject_marks, 3, minIndex(subject_marks, 0, 1))];
}

int minIndex(unsigned short* marks, int id_1, int id_2) {
    if (marks[id_1] < marks[id_2]) {
        return id_1;
    }
    return id_2;
}


