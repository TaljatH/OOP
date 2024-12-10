#pragma once

#include <string>
#include "Pokemon.h"

/*
* Klassen representerar Pokemon som har två typer istället för en.
* 
* Klassen ärver från Pokemon-klassen. Utöver det så ska det ha en const Type 
* som representerar dess andra typ.
*/

class DualTypePokemon : public Pokemon {
private:
protected:
public:

    // Klassens konstruktor. Den ska initiera klassen.
    DualTypePokemon(const std::string& name, const Type type1, const Type type2, const Move* move1, const Move* move2, const Move* move3, const Move* move4, const int health, const int attack, const int spAttack, const int defense, const int spDefense) 
    {}

    // Ska fungera på samma sätt som originalet, förutom att logiken ska vara 
    // Multiplier = Multiplier1 * Multiplier2, där Multiplier1 är "damage multiplier" 
    // för färsta typen och Multiplier2 är för den andra typen.
    // 
    //calculateDamageMultiplier();
};