#include<iostream>
#include"Types.h"
using namespace std;



// ================== ЕТАП 1: CREATE + READ ФУНКЦІЇ ==================

// 1.1 CREATE
void recruitHero(PartyList& party, Character newHero)
{
    Character* newArr = new Character[party.size + 1];

    for (int i = 0; i < party.size; i++)
    {
        newArr[i] = party.heroes[i];
    }

    newArr[party.size] = newHero;

    delete[] party.heroes;
    party.heroes = newArr;
    party.size++;
}

// 1.2 READ (пошук індексу)
int findHeroIndex(const PartyList& party, const char* searchName)
{
    for (int i = 0; i < party.size; i++)
    {
        if (strcmp(party.heroes[i].name, searchName) == 0)
        {
            return i;
        }
    }
    return -1;
}

// 1.3 READ (копія за іменем)
Character getHeroByName(const PartyList& party, const char* searchName)
{
    Character empty{ "", "", -1, -1, {0, 0, 0}, {"", 0} };

    int index = findHeroIndex(party, searchName);
    if (index == -1)
    {
        return empty;
    }

    return party.heroes[index];
}

// 1.4 Вивід усіх героїв (з вкладеними полями)
void printParty(const PartyList& party)
{
    if (party.heroes == nullptr || party.size <= 0) return;

    for (int i = 0; i < party.size; i++)
    {
        cout << (i + 1) << ". " << party.heroes[i].name
            << " [" << party.heroes[i].classType << "] "
            << "Рівень: " << party.heroes[i].level
            << ", HP: " << party.heroes[i].hp << endl;

        cout << "   Характеристики: STR " << party.heroes[i].stats.strength
            << ", AGI " << party.heroes[i].stats.agility
            << ", INT " << party.heroes[i].stats.intelligence << endl;

        cout << "   Зброя: " << party.heroes[i].weapon.name
            << " (сила " << party.heroes[i].weapon.power << ")" << endl;
    }
    cout << endl;
}
