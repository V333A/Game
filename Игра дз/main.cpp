#include <iostream>
#include <cstring>
#include <windows.h>
#include"Types.h"
#include"Party.h"
using namespace std;





int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    PartyList party;

    recruitHero(party, { "Аргос", "Воїн", 1, 100, {15, 8, 4}, {"Меч", 20} });
    recruitHero(party, { "Мілена", "Маг", 1, 80, {5, 6, 18}, {"Посох", 25} });
    recruitHero(party, { "Фалкон", "Лучник", 2, 90, {8, 16, 7}, {"Лук", 18} });

    cout << "--- Табір після набору героїв ---" << endl;
    printParty(party);

    cout << "--- Читання героя за іменем ---" << endl;
    Character found = getHeroByName(party, "Мілена");
    cout << "Знайдено: " << found.name << ", клас " << found.classType << endl << endl;

    delete[] party.heroes;
    party.heroes = nullptr;
    party.size = 0;

    return 0;
}

