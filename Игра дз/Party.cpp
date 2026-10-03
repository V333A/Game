#include<iostream>
#include"Types.h"
#include "Party.h"
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



//  ================== ЕТАП 2: UPDATE ==================


bool levelUp(PartyList& party, const char* searchName)
{
    int index = findHeroIndex(party, searchName);
    if (index == -1)
    {
        return false;
    }

    party.heroes[index].level++;
    party.heroes[index].hp += 10;
    return true;
}

bool equipWeapon(PartyList& party, const char* searchName, Item newWeapon)
{
    int index = findHeroIndex(party, searchName);
    if (index == -1)
    {
        return false;
    }

    party.heroes[index].weapon = newWeapon;
    return true;
}

bool damageHero(PartyList& party, const char* searchName, int amount)
{
	int index = findHeroIndex(party, searchName);
	if (index == -1)
	{
		return false;
	}
	party.heroes[index].hp -= amount;
	if (party.heroes[index].hp < 0)
	{
		party.heroes[index].hp = 0;
	}
	return true;
    
}

bool healHero(PartyList& party, const char* searchName, int amount)
{
    int index = findHeroIndex(party, searchName);
    if (index == -1)
    {
        return false;
    }

    party.heroes[index].hp += amount;
    if (party.heroes[index].hp > 100)
    {
        party.heroes[index].hp = 100;
    }
    return true;
}




//  ================== ЕТАП 3: DELETE + аналітика ==================


bool dismissHero(PartyList& party, const char* searchName)
{
    if (party.size <= 0 || party.heroes == nullptr)
    {
        return false;
    }

    int index = findHeroIndex(party, searchName);

    if (index == -1)
    {
        return false;
    }

    if (party.size == 1)
    {
        delete[] party.heroes;
        party.heroes = nullptr;
        party.size = 0;

        return true;
    }

    Character* newArr = new Character[party.size - 1];

    for (int i = 0, j = 0; i < party.size; i++)
    {
        if (i != index)
        {
            newArr[j] = party.heroes[i];
            j++;
        }
    }

    delete[] party.heroes;

    party.heroes = newArr;
    party.size--;

    return true;
}

int totalPartyPower(const PartyList& party)
{
	int totalPower = 0;
	for (int i = 0; i < party.size; i++)
	{
		totalPower += (party.heroes[i].level * 10 + party.heroes[i].weapon.power);
	}
    return totalPower;
}

int findStrongestHeroIndex(const PartyList& party)
{
    if (party.size <= 0 || party.heroes == nullptr)
    {
        return -1;
    }

    int strongestIndex = 0;

    for (int i = 1; i < party.size; i++)
    {
        int currentPower =
            party.heroes[i].stats.strength +
            party.heroes[i].stats.agility +
            party.heroes[i].stats.intelligence;

        int strongestPower =
            party.heroes[strongestIndex].stats.strength +
            party.heroes[strongestIndex].stats.agility +
            party.heroes[strongestIndex].stats.intelligence;

        if (currentPower > strongestPower)
        {
            strongestIndex = i;
        }
    }

    return strongestIndex;
}

void sortByLevelDescending(PartyList& party)
{
	for (int i = 0; i < party.size - 1; i++)
	{
		for (int j = 0; j < party.size - i - 1; j++)
		{
			if (party.heroes[j].level < party.heroes[j + 1].level)
			{
				Character temp = party.heroes[j];
				party.heroes[j] = party.heroes[j + 1];
				party.heroes[j + 1] = temp;
			}
		}
	}
}


