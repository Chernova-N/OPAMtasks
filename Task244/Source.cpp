/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 244:
Задано два рядки А і В. Складіть програму, що перевіряє, чи можно
з букв, які входять в А, скласти В(літери можно використовувати не більше одного разу, але можна переставляти).
Наприм., А: ІНТЕГРАЛ; B: АГЕНТ - скласти можна; B: ГРАФ - не можна.*/

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


    cout << "ІПЗІ-18к Чернова Анастасія Євгенівна" << endl;
    cout << "Завдання 244" << endl;
    cout << "Задано два рядки А і В. Складіть програму, що перевіряє, чи можно" << endl;
    cout << "з букв, які входять в А, скласти В(літери можно використовувати не більше одного разу, але можна переставляти)." << endl;
    cout << "Наприм., А: ІНТЕГРАЛ; B: АГЕНТ - скласти можна; B: ГРАФ - не можна." << endl;

    cout << "Введіть перше слово: ";
    cin >> A;
    cout << "Введіть перше слово: ";
    cin >> B;

    cout << (isCanCreateFromFirstToSecond(A, B) ? "Можна" : "Неможна") << endl;
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
