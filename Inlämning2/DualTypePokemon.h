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
    Type type1;
    Type type2;

    const Move* move1;
    const Move* move2;
    const Move* move3;
    const Move* move4;
    
protected:
public:

   

    // Klassens konstruktor. Den ska initiera klassen.
    DualTypePokemon(const std::string& name, const Type type1, const Type type2, const Move* move1, const Move* move2, const Move* move3, const Move* move4, const int health, const int attack, const int spAttack, const int defense, const int spDefense) 
    :move1(move1),move2(move2),move3(move3),move4(move4),type1(type1),type2(type2)
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
    }

    // x Ska fungera på samma sätt som originalet, förutom att logiken ska vara 
    // x Multiplier = Multiplier1 * Multiplier2, där Multiplier1 är "damage multiplier" 
    // x för första typen och Multiplier2 är för den andra typen.
    // 
    int calculateDamageMultiplier(Pokemon& target, Move& power){
       int damage = (((power.GetPower() * Attack /  target.getPokemonDefence()) / 50) + 2) * type1 * type2;
    }


    //Getter
    int getDualTypeDef(){return Defence;}
    int getDualAtk(){return Attack;}
    int getSpDualAk(){return SpecialAttack;}
    int getSpDualDef(){return SpecialDefence;}
};