/*
ІПЗІ-18к
Чернова Анастасія Євгенівна
Завдання 329:
Дані описані на псевдокоді.
type
    Масть=(піка, треф, бубна, черво);
    Варстість=(шість, сім, вісім, девять, десять, валет, дама, туз);
    
    struct карта
    {
        Масть m;
        вартість в;
    };
    Описати дані на мові C++. Описати логічну функцію б`є(К1, К2, КМ), яка
    перевіряє, чи б`є картка К1 картку К2 з урахуванням того, що масть КМ є козирною.*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

enum class Suit {P, T, B, CH};
enum class Cost {SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, ACE};

struct Card {
    Suit s;
    Cost c;
};

bool firstCardBeatsSecond(Card* card1, Card* card2, Suit trump);
string cardSuit(Suit card);
string cardCost(Cost card);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "ІПЗІ-18к Чернова Анастасія Євгенівна Завдання 329:" << endl;
    cout << "Дані описані на псевдокоді. type  Масть=(піка, треф, бубна, черво);\nВарстість = (шість, сім, вісім, девять, десять, валет, дама, туз); " << endl;
    cout << "struct карта { Масть m; вартість в;}; " << endl;
    cout << "Описати дані на мові C++. Описати логічну функцію б`є(К1, К2, КМ), яка\nперевіряє, чи б`є картка К1 картку К2 з урахуванням того, що масть КМ є козирною." << endl << endl;
    
    Card* card1 = new Card();
    card1->c = Cost::SIX;
    card1->s = Suit::P;

    Card* card2 = new Card();
    card2->c = Cost::JACK;
    card2->s = Suit::CH;    

    Suit trump = Suit::P;

    cout << "Карта 1 : " << cardSuit(card1->s) << " - " << cardCost(card1->c) << endl;
    cout << "Карта 2 : " << cardSuit(card2->s) << " - " << cardCost(card2->c) << endl;
    cout << "Козир : " << cardSuit(trump) << endl;

    cout << "Карта 1 "<<(firstCardBeatsSecond(card1, card2, trump) ? "Б`є" : "Неб`є") << " Карту 2" << endl;
    return 0;
}

bool firstCardBeatsSecond(Card* card1, Card* card2, Suit trump) {
    bool isBeat = false;
    if (card1->s == card2->s) {
        if (card1->c > card2->c) {
            isBeat = true;
        }
    }
    else if (card1->s == trump) {
        isBeat = true;
    }
    return isBeat;
}

string cardSuit(Suit suit) {
    string _suit;
    switch (suit) {
        case Suit::P:
            _suit = "PIKA";
            break;
        case Suit::T:
            _suit = "TREF";
            break;
        case Suit::CH:
            _suit = "CHIRVA";
            break;
        case Suit::B:
            _suit = "BUBNA";
            break;
    }

    return _suit;
}
string cardCost(Cost cost) {
    string _cost;
    switch (cost) {
        case Cost::SIX:
            _cost = "SIX";
            break;
        case Cost::SEVEN:
            _cost = "SEVEN";
            break;
        case Cost::EIGHT:
            _cost = "EIGHT";
            break;
        case Cost::NINE:
            _cost = "NINE";
            break;
        case Cost::TEN:
            _cost = "TEN";
            break;
        case Cost::JACK:
            _cost = "JACK";
            break;
        case Cost::QUEEN:
            _cost = "QUEEN";
            break;
        case Cost::ACE:
            _cost = "ACE";
            break;
    }

    return _cost;
}
