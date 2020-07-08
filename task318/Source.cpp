/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Завдання 318:
Дані про студента задані у вигляді структури з полями:
<призвіще>,<номер групи>,
<оцінка 1>,<оцінка 2>,<оцінка 3>
В прізвіще - не більше 12 літер, номер групи-ціле число, оцінка-ціле число
(перша оцінка - за екзамен з математики, друга - з історії, третя - з программуваня).
Написати програму, яка вводить цю інформацію і друкує наступне повідомлення.
318. Назву предмета, який був складений найгірше.*/

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

string subjects[3] = { "Математика","Історія","Програмування" };

string wosrtSubject(Student* student);
int minIndex(unsigned short* marks, int id_1, int id_2);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "ІПЗІ-18к Чернова Анастасія Євгенівна Завдання 318:" << endl;
    cout << "Дані про студента задані у вигляді структури з полями: < призвіще > ,\n <номер групи>, <оцінка 1>, <оцінка 2>, < оцінка 3>" << endl;
    cout << "В прізвіще - не більше 12 літер, номер групи-ціле число, оцінка-ціле число \n (перша оцінка - за екзамен з математики, друга - з історії, третя - з программуваня)." << endl;
    cout << "Написати програму, яка вводить цю інформацію і друкує наступне повідомлення.\n  318. Назву предмета, який був складений найгірше." << endl;

    Student* student = new Student();
    cout << "Ім`я: ";
    cin >> student->name;
    cout << "Група: ";
    cin >> student->group_id;
    cout << "Оцінка з математики: ";
    cin >> student->mathMark;
    cout << "Оцінка з історії: ";
    cin >> student->historyMark;
    cout << "Оцінка з програмування: ";
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


