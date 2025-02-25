#pragma once

#include <string>
#include "Move.h"
#include "Pokemon.h"

class PhysicalMove : public Move{
private:

protected:
public:

    PhysicalMove(const std::string& name, const Type type, const int power)
    :Move(name, type, power) {}

   

    void execute(Pokemon* attacker,Pokemon* defender) const override{

        float phyDamage = (((power * attacker->getAtk() / defender->getPokemonDefence()) / 40) + 2);
         phyDamage *= defender->getDamageMultiplier(type);
        //Hp update
        float newHP = defender->reduceHealth(phyDamage);

        if(defender->getDamageMultiplier(type) == 0){std::cout<<"It doesn't affect "<<defender->getPokemonName()<<std::endl;}

        if(defender->getDamageMultiplier(type) > 0 && defender->getDamageMultiplier(type) < 1){std::cout<<"It's not very effective against "<<defender->getPokemonName()<<std::endl;}

        if(defender->getDamageMultiplier(type) > 1){std::cout<<"It's super effective against "<<defender->getPokemonName()<<std::endl;}
        
    }

};