/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Завдання 333:
Скласти програму для нарахування стипендії студентам за результатами екзаменаційної сесії.
Інформація про результати сесії містить:
- прізвище
- ім`я
- по батькові
- номер групи
- екзаменаційні оцінки
Кількість екз. оцінок не менше 3 и не більше 5. Стипендія нараховується студентам, що склали всі іспити в сесію
за такими правилами:
- студенти, що склали все іспити на відмінно отримують надбавку, що дорівнює 100%
- студенти, що склали іспити на добре и відмінно - 50%
- студенти, що склали іспити на добре - 25%
- стипендія не нараховуються студентам, що мають в сесію більше двох задовільних оцінок.
Вихідний список студентів кожної групи розмістити в окремому файлі структур.
Список студентів кожної групи, що отримали стипендію, вивести на екран, упорядкувавши за абеткою*/

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

    cout << "ІПЗІ-18к Чернова Анастасія Євгенівна Завдання 333:" << endl;
    cout << "Скласти програму для нарахування стипендії студентам за результатами екзаменаційної сесії. Інформація про результати сесії містить :" << endl;
    cout << "- прізвище" << endl;
    cout << "- ім`я" << endl;
    cout << "- по батькові" << endl;
    cout << "- номер групи" << endl;
    cout << "- екзаменаційні оцінки" << endl;

    cout << "Кількість екз. оцінок не менше 3 и не більше 5. Стипендія нараховується студентам, що склали всі іспити в сесію за такими правилами : " << endl;
    cout << "- студенти, що склали все іспити на відмінно отримують надбавку, що дорівнює 100%" << endl;
    cout << "- студенти, що склали іспити на добре и відмінно - 50%" << endl;
    cout << "- студенти, що склали іспити на добре - 25%" << endl;
    cout << "- стипендія не нараховуються студентам, що мають в сесію більше двох задовільних оцінок." << endl;

    cout << "Вихідний список студентів кожної групи розмістити в окремому файлі структур." << endl;
    cout << "Список студентів кожної групи, що отримали стипендію, вивести на екран, упорядкувавши за абеткою." << endl << endl;

    cout << " --------------------- " << endl;
    cout << "Студенти: " << endl;
    cout << " --------------------- " << endl;

    // --------------- CREATE STUDENTS --------------------
    vector<Student*> students;

    Student* first = new Student();
    first->fisrtName = "Олег";
    first->midleName = "Андрійович";
    first->secondName = "Кондрятюк";
    first->group_id = 421;
    first->marks.push_back(4);
    first->marks.push_back(5);
    first->marks.push_back(4);

    Student* second = new Student();
    second->fisrtName = "Андрій";
    second->midleName = "Володимирович";
    second->secondName = "Альфред";
    second->group_id = 431;
    second->marks.push_back(5);
    second->marks.push_back(5);
    second->marks.push_back(5);
    second->marks.push_back(5);

    Student* third = new Student();
    third->fisrtName = "Сергій";
    third->midleName = "Батькович";
    third->secondName = "Бутько";
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
    cout << "Студенти зі стипендією: " << endl;
    cout << " --------------------- " << endl;
    printStudents(studentsWithGrands);

    return 0;
}


void printStudents(vector<Student*> students) {
    for (int i = 0; i < students.size(); i++) {
        cout << "Студент: " << students[i]->secondName << " " << students[i]->midleName << " " << students[i]->fisrtName << endl;
        cout << "Група: " << students[i]->group_id << endl;
        cout << "Оцінки: [";
        for (int j = 0; j < students[i]->marks.size(); j++) {
            cout << students[i]->marks[j];
            if (j < students[i]->marks.size() - 1) {
                cout << ',';
            }
        }
        cout << "]"<<endl;
        if (students[i]->grandType.length() > 0) {
            cout << "Стипендія: " << students[i]->grandType << endl;
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

