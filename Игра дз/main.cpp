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

    Character hero1{
        "Arthas",
        "Warrior",
        5,
        100,
        {15, 8, 5},
        {"Sword", 25}
    };

    Character hero2{
        "Jaina",
        "Mage",
        7,
        80,
        {5, 10, 20},
        {"Staff", 30}
    };

    Character hero3{
        "Thrall",
        "Shaman",
        6,
        95,
        {12, 11, 15},
        {"Hammer", 28}
    };

    Character hero4{
        "Valeera",
        "Rogue",
        4,
        90,
        {8, 20, 7},
        {"Daggers", 22}
    };

    // 1. Добавляем героев
    recruitHero(party, hero1);
    recruitHero(party, hero2);
    recruitHero(party, hero3);
    recruitHero(party, hero4);

    // 2. Выводим лагерь
    cout << "\n--- PARTY ---\n";
    printParty(party);

    // 3. Ищем героя
    Character foundHero = getHeroByName(party, "Jaina");

    cout << "\n--- FOUND HERO ---\n";

    if (foundHero.level != -1)
    {
        cout << "Name: " << foundHero.name << endl;
        cout << "Class: " << foundHero.classType << endl;
        cout << "Level: " << foundHero.level << endl;
        cout << "HP: " << foundHero.hp << endl;
        cout << "Weapon: " << foundHero.weapon.name << endl;
    }

    // 4. Повышаем уровень
    levelUp(party, "Arthas");

    // 5. Даём новое оружие
    Item newWeapon{
        "Frostmourne",
        60
    };

    equipWeapon(party, "Arthas", newWeapon);

    // 6. Бой
    damageHero(party, "Thrall", 40);
    healHero(party, "Thrall", 20);

    // 7. Общая сила
    cout << "\nTotal party power: "
        << totalPartyPower(party)
        << endl;

    // 8. Самый сильный герой
    int strongestIndex = findStrongestHeroIndex(party);

    if (strongestIndex != -1)
    {
        cout << "Strongest hero: "
            << party.heroes[strongestIndex].name
            << endl;
    }

    // Используем ещё и сортировку
    sortByLevelDescending(party);

    cout << "\n--- SORTED PARTY ---\n";
    printParty(party);

    // 9. Удаляем героя
    dismissHero(party, "Jaina");

    // 10. Выводим лагерь снова
    cout << "\n--- FINAL PARTY ---\n";
    printParty(party);

    // 11. Освобождаем память
    delete[] party.heroes;
    party.heroes = nullptr;
    party.size = 0;

    return 0;
}

