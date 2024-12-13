#pragma once

#include <string>
#include "Move.h"

class PhysicalMove : public Move{
private:
    std::string name;
    int power;
    Type type;

protected:
public:

    //Klassens konstruktor. Den ska initiera klassen.
    PhysicalMove(const std::string& name, const Type type, const int power)
    :name(name),type(type),power(power){}

    /*x execute() ska räkna ut hur mycket skada denna Move ska
    x göra på försvarande Pokemon. Du bestämmer själv exakt vilken formel
    x funktionen ska använda sig av, så länge du kan motivera din design
    x och så länge följande variabler används (men samma formel för SpecialMove):

    x power, attackersAttack, defendersDefence, multiplier

    x PhysicalMove-klassen ska använda sig utav attack och defence,
    x medans SpecialMove ska använda sig av specialAttack och
    x specialDefence. 
    x Funktionen ska skriva ut:

    x "It doesn't affect {försvarandePokemon}."
    x om multiplier är 0,

    x "It's not very effective..."
    x om multiplier är under 1 men inte 0,

    x "It's super effective!"
    x om multiplier är över 1.*/
    //x execute() override


    void execute(Pokemon* attacker,Pokemon* defender) const override{

        float phyDamage = (((power * attacker->getAtk() / defender->getPokemonDefence()) / 50) + 2 * attacker->getDamageMultiplier(type));

        //Hp update
        float newHP = defender->reduceHealth(phyDamage);

        if(attacker->getDamageMultiplier(type) == 0){std::cout<<"It dosen't affect "<<defender->getPokemonName()<<std::endl;}

        if(attacker->getDamageMultiplier(type) > 1 && attacker->getDamageMultiplier(type) < 0){std::cout<<"It's not very effective against "<<defender->getPokemonName()<<std::endl;}

        if(attacker->getDamageMultiplier(type) > 1){std::cout<<"It's very effective against "<<defender->getPokemonName()<<std::endl;}
        
    }

};