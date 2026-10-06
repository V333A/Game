#pragma once
#include"Types.h"






// ================== ЕТАП 1: CREATE + READ ПРОТОТИПИ ==================

void recruitHero(PartyList& party, Character newHero);
int findHeroIndex(const PartyList& party, const char* searchName);
Character getHeroByName(const PartyList& party, const char* searchName);
void printParty(const PartyList& party);


//  ================== ЕТАП 2: UPDATE ==================

      bool levelUp(PartyList& party, const char* searchName);
//  -   яка знаходить героя за іменем
//  -   збільшує level на 1, а hp - на 10.
//  -   Повертає false, якщо героя не знайдено.


      bool equipWeapon(PartyList& party, const char* searchName, Item newWeapon);
//  -   яка змінює ПОЛЕ weapon (вкладену структуру) героя на нову зброю (заміняє І назву, І power).
//  -   Повертає false, якщо героя не знайдено.
     bool damageHero(PartyList& party, const char* searchName, int amount);
//  -   яка зменшує hp героя на amount.
//  -   ВАЖЛИВО: hp не повинно ставати меншим за 0 (якщо amount більший за поточне hp - встановіть hp = 0).

      bool healHero(PartyList& party, const char* searchName, int amount);
//  -   яка збільшує hp героя на amount, але hp НЕ повинно перевищувати 100 (якщо після лікування вийшло би більше 100 - встановіть hp = 100).



      //  ================== ЕТАП 3: DELETE + аналітика ==================


     bool dismissHero(PartyList& party, const char* searchName);
//  яка видаляє героя з табору за іменем за принципом:
//  -   виділити новий масив на -1,
//  -   скопіювати всіх, окрім видаленого, звільнити старий масив.
//  -   Не забудьте про особливий випадок, коли герой останній у таборі!



     int totalPartyPower(const PartyList& party);
//  -   яка обчислює ЗАГАЛЬНУ силу всього табору - суму по всіх героях виразу (level * 10 + weapon.power) для кожного героя.


    int findStrongestHeroIndex(const PartyList& party);
//  -   яка повертає ІНДЕКС героя з найбільшим значенням (stats.strength + stats.agility + stats.intelligence).
//  -   Якщо табір порожній - поверніть -1.

    void sortByLevelDescending(PartyList& party);
//  -   яка сортує масив героїв за СПАДАННЯМ рівня (level), методом бульбашки


    bool savePartyToFile(
        const PartyList& party,
        const char* fileName
    );

    bool loadPartyFromFile(
        PartyList& party,
        const char* fileName
    );