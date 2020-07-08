/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Номер теми
Завдання 257:
Задано рядок, що містить текст українською мовою. 
З`ясувати, чи входить в цей текст задане слово, і якщо так, то скільки разів.*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

int countTextContainsWord(string& text, string& word);
char convertWord(char word);

const int MIN_SMALL_WORD_INDEX = -32;
const int MAX_SMALL_WORD_INDEX = -1;

const int MIN_BIG_WORD_INDEX = -64;
const int MAX_BIG_WORD_INDEX = -33;

const byte WORDS_COUNT = 32;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string sentence, word;

    cout << "ІПЗІ-18к Чернова Анастасія Євгенівна" << endl;
    cout << "Завдання 257" << endl;
    cout << "Задано рядок, що містить текст українською мовою. З`ясувати, чи входить в цей текст задане слово, і якщо так, то скільки разів." << endl;
    
    cout << "Введіть текст: ";
    getline(cin, sentence);
    cout << "Введіть слово: ";
    cin >> word;

    int count = countTextContainsWord(sentence, word);

    cout << (count > 0 ? "Текст містить в собі слово " + to_string(count) + " разів." : "Текст не містить в собі слово.") << endl;
    return 0;
}

int countTextContainsWord(string& text, string& word) {
    int indexInText = 0;
    int countContains = 0;

    while (indexInText < text.size() && text.size() - indexInText >= word.size())
    {
        if (text[indexInText] == word[0] || text[indexInText] == convertWord(word[0])){
            bool contains = true;
            indexInText+=1;
            for (int i = 1; i < word.size(); i++) {
                int temp_index = indexInText++;
                if (text[temp_index] != word[i] && text[temp_index] != convertWord(word[i])){
                    contains = false;
                    break;
                }
            }
            if (contains) {
                countContains++;
            }
        }
        else {
            indexInText++;
        }
    }

    return countContains;
}

char convertWord(char word) {
    int charIndex = (int) word;
    if (charIndex <= MAX_SMALL_WORD_INDEX && charIndex >= MIN_SMALL_WORD_INDEX) {
        charIndex -= WORDS_COUNT;
    }
    else if (charIndex <= MAX_BIG_WORD_INDEX && charIndex >= MIN_BIG_WORD_INDEX) {
        charIndex += WORDS_COUNT;
    }
    return char(charIndex);
}