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
    std::string Name;
    int Attack, Defence, Health, SpecialDefence, SpecialAttack;

    const Move* Move1;
    const Move* Move2;
    const Move* Move3;
    const Move* Move4;
    
protected:
public:

   

    // Klassens konstruktor. Den ska initiera klassen.
    DualTypePokemon(const std::string& name, const Type type1, const Type type2, const Move* move1, const Move* move2, const Move* move3, const Move* move4, const int health, const int attack, const int spAttack, const int defense, const int spDefense) 
    {

        if(health <= 0){
            throw "Pokemons health is 0";
        }else{Health = health;}

        if(attack <= 0){
            throw "Pokemons attack is 0";
        }else{Attack = attack;}

        if(spAttack <= 0){
            throw "Pokemons spAttack is 0";
        }else{SpecialAttack = spAttack;}

        if(spDefense <= 0){
            throw "Pokemons spDefense is 0";
        }else{SpecialDefence = spDefense;}

        if(defense <= 0){
            throw "Pokemon has no defense";
        }else{Defence = defense;}

        Name = name;
        Move1 = move1;
        Move2 = move2;
        Move3 = move3;
        Move4 = move4;

    }

    // Ska fungera på samma sätt som originalet, förutom att logiken ska vara 
    // Multiplier = Multiplier1 * Multiplier2, där Multiplier1 är "damage multiplier" 
    // för färsta typen och Multiplier2 är för den andra typen.
    // 
    //calculateDamageMultiplier();
};