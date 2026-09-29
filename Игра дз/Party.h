#pragma once
#include"Types.h"






// ================== ЕТАП 1: CREATE + READ ПРОТОТИПИ ==================

void recruitHero(PartyList& party, Character newHero);
int findHeroIndex(const PartyList& party, const char* searchName);
Character getHeroByName(const PartyList& party, const char* searchName);
void printParty(const PartyList& party);