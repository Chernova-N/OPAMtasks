/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Завдання 262:
Задано рядок, що містить текст українською мовою.
Скласти в алфавітному порядку список слів, що зустрічаються в цьому тексті.*/

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <list>
#include <stdlib.h> 
#include <string>

using namespace std;

const int MIN_BIG_WORD_INDEX = -64;
const int MAX_BIG_WORD_INDEX = -33;

const byte WORDS_COUNT = 32;

void convertToSmallWords(string& text);
void getWordsFromText(string& text, list<string>& words);
string* sortingWords(list<string>& words);
bool comparison(string& word1, string& word2);


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string text;
    list<string> words;

    cout << "ІПЗІ-18к Чернова Анастасія Євгенівна" << endl;
    cout << "Завдання 262" << endl;
    cout << "Задано рядок, що містить текст українською мовою. Скласти в алфавітному порядку список слів, що зустрічаються в цьому тексті." << endl;

    cout << "Введіть текст: ";
    getline(cin, text);

    convertToSmallWords(text);
    getWordsFromText(text, words);
    string* sortedWords = sortingWords(words);

    cout << "[";
    for (int i = 0; i < words.size(); i++) {
        cout << sortedWords[i];
        if (i + 1 < words.size()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

void convertToSmallWords(string& text) {
    int indexWord;
    for (int i = 0; i < text.size(); i++) {
        indexWord = (int)text[i];
        if (indexWord <= MAX_BIG_WORD_INDEX && indexWord >= MIN_BIG_WORD_INDEX) {
            text[i] = char(indexWord + WORDS_COUNT);
        }
    }
}

void getWordsFromText(string& text, list<string>& words) {
    int pointer = 0;
    while (pointer < text.size()) {
        if (text[pointer] != ' ' && text[pointer] != '.' && text[pointer] != '!' && text[pointer] != '?' && text[pointer] != ',' && text[pointer] != '-') {
            string word;
            while (pointer < text.size()) {
                int temp_pointer = pointer++;
                if (text[temp_pointer] != ' ' && text[temp_pointer] != '.' && text[temp_pointer] != '!' && text[temp_pointer] != '?' && text[temp_pointer] != ',') {
                    word += text[temp_pointer];
                }
                else {
                    break;
                }
            }
            words.push_back(word);
        }
        else {
            pointer++;
        }
    }
}

string* sortingWords(list<string>& words) {
    string* words_ = new string[words.size()];
    list<string>::iterator it;

    int index = 0;
    string temp;

    for (it = words.begin(); it != words.end(); it++)
    {
        words_[index] = *it;
        index++;
    }

    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++)
        {
            if (comparison(words_[j], words_[i])) {
                temp = words_[i];
                words_[i] = words_[j];
                words_[j] = temp;
            }
        }
    }
    return words_;
}

bool comparison(string& word1, string& word2) {
    bool isFirstly = false;
    int pointer = 0;
    while (pointer < word1.length() && pointer < word2.length()){
        if (int(word1[pointer]) < int(word2[pointer])){
            isFirstly = true;
            break;
        }
        else if (int(word1[pointer]) > int(word2[pointer])) {
            break;
        }
        pointer++;
    }
    pointer = 0;
    return isFirstly;
}
