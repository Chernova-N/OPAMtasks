/*
��ǲ-18�
������� �������� ��������
�������� 333:
������� �������� ��� ����������� ������䳿 ��������� �� ������������ ������������� ���.
���������� ��� ���������� ��� ������:
- �������
- ��`�
- �� �������
- ����� �����
- ������������ ������
ʳ������ ���. ������ �� ����� 3 � �� ����� 5. �������� ������������ ���������, �� ������ �� ������ � ����
�� ������ ���������:
- ��������, �� ������ ��� ������ �� ������ ��������� ��������, �� ������� 100%
- ��������, �� ������ ������ �� ����� � ������ - 50%
- ��������, �� ������ ������ �� ����� - 25%
- �������� �� ������������� ���������, �� ����� � ���� ����� ���� ���������� ������.
�������� ������ �������� ����� ����� ��������� � �������� ���� ��������.
������ �������� ����� �����, �� �������� ��������, ������� �� �����, ������������� �� �������*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

    
struct Student {
    string fisrtName;
    string midleName;
    string secondName;
    unsigned short group_id;
    vector<int> marks;
    string grandType;
};

void printStudents(vector<Student*> students);
vector<Student*> checkingGrandsForStudents(vector<Student*> students);

void sortingStudents(vector<Student*>& students);
bool sortedStudent(string& firstLastName, string& secondLastName);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "��ǲ-18� ������� �������� �������� �������� 333:" << endl;
    cout << "������� �������� ��� ����������� ������䳿 ��������� �� ������������ ������������� ���. ���������� ��� ���������� ��� ������ :" << endl;
    cout << "- �������" << endl;
    cout << "- ��`�" << endl;
    cout << "- �� �������" << endl;
    cout << "- ����� �����" << endl;
    cout << "- ������������ ������" << endl;

    cout << "ʳ������ ���. ������ �� ����� 3 � �� ����� 5. �������� ������������ ���������, �� ������ �� ������ � ���� �� ������ ��������� : " << endl;
    cout << "- ��������, �� ������ ��� ������ �� ������ ��������� ��������, �� ������� 100%" << endl;
    cout << "- ��������, �� ������ ������ �� ����� � ������ - 50%" << endl;
    cout << "- ��������, �� ������ ������ �� ����� - 25%" << endl;
    cout << "- �������� �� ������������� ���������, �� ����� � ���� ����� ���� ���������� ������." << endl;

    cout << "�������� ������ �������� ����� ����� ��������� � �������� ���� ��������." << endl;
    cout << "������ �������� ����� �����, �� �������� ��������, ������� �� �����, ������������� �� �������." << endl << endl;

    cout << " --------------------- " << endl;
    cout << "��������: " << endl;
    cout << " --------------------- " << endl;

    // --------------- CREATE STUDENTS --------------------
    vector<Student*> students;

    Student* first = new Student();
    first->fisrtName = "����";
    first->midleName = "���������";
    first->secondName = "���������";
    first->group_id = 421;
    first->marks.push_back(4);
    first->marks.push_back(5);
    first->marks.push_back(4);

    Student* second = new Student();
    second->fisrtName = "�����";
    second->midleName = "�������������";
    second->secondName = "�������";
    second->group_id = 431;
    second->marks.push_back(5);
    second->marks.push_back(5);
    second->marks.push_back(5);
    second->marks.push_back(5);

    Student* third = new Student();
    third->fisrtName = "�����";
    third->midleName = "���������";
    third->secondName = "������";
    third->group_id = 411;
    third->marks.push_back(3);
    third->marks.push_back(3);
    third->marks.push_back(3);


    students.push_back(first);
    students.push_back(second);
    students.push_back(third);

    // ----------------------------------------------------

    printStudents(students);
    vector<Student*> studentsWithGrands = checkingGrandsForStudents(students);
    
    sortingStudents(studentsWithGrands);
    cout << " --------------------- " << endl;
    cout << "�������� � ������䳺�: " << endl;
    cout << " --------------------- " << endl;
    printStudents(studentsWithGrands);

    return 0;
}


void printStudents(vector<Student*> students) {
    for (int i = 0; i < students.size(); i++) {
        cout << "�������: " << students[i]->secondName << " " << students[i]->midleName << " " << students[i]->fisrtName << endl;
        cout << "�����: " << students[i]->group_id << endl;
        cout << "������: [";
        for (int j = 0; j < students[i]->marks.size(); j++) {
            cout << students[i]->marks[j];
            if (j < students[i]->marks.size() - 1) {
                cout << ',';
            }
        }
        cout << "]"<<endl;
        if (students[i]->grandType.length() > 0) {
            cout << "��������: " << students[i]->grandType << endl;
        }
        cout << endl;
    }
}

vector<Student*> checkingGrandsForStudents(vector<Student*> students) {
    vector<Student*> studentsWithGrand;
    
    int excellentMarks;
    int goodMarks;
    int satisfactorilyMarks;

    int currentMark;

    for (int i = 0; i < students.size(); i++) {
        excellentMarks = 0;
        goodMarks = 0;
        satisfactorilyMarks = 0;
        for (int j = 0; j < students[i]->marks.size(); j++) {
            currentMark = students[i]->marks[j];
            if (currentMark == 5) {
                excellentMarks++;
            }
            else if (currentMark == 4) {
                goodMarks++;
            }
            else {
                satisfactorilyMarks++;
            }
        }
        if (goodMarks == 0 && satisfactorilyMarks == 0) {
            students[i]->grandType = "100%";
            studentsWithGrand.push_back(students[i]);
        }
        else if (excellentMarks > 0 && satisfactorilyMarks == 0) {
            students[i]->grandType = "50%";
            studentsWithGrand.push_back(students[i]);
        }
        else if (satisfactorilyMarks <= 2) {
            students[i]->grandType = "25%";
            studentsWithGrand.push_back(students[i]);
        }
    }
    return studentsWithGrand;
}


void sortingStudents(vector<Student*>& students) {
    for (int i = 0; i < students.size(); i++) {
        for (int j = i + 1; j < students.size(); j++) {
            if (sortedStudent(students[j]->secondName, students[i]->secondName)) {
                Student* temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

bool sortedStudent(string& firstLastName, string& secondLastName){
    bool isFirstly = false;
    int pointer = 0;
    while (pointer < firstLastName.length() && pointer < secondLastName.length()) {
        if (int(firstLastName[pointer]) < int(secondLastName[pointer])) {
            isFirstly = true;
            break;
        }
        else if (int(firstLastName[pointer]) > int(secondLastName[pointer])) {
            break;
        }
        pointer++;
    }
    pointer = 0;
    return isFirstly;
}

