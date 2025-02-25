#pragma once

#include <string>
#include "Move.h"
#include "Pokemon.h"

class PhysicalMove : public Move{
private:
    std::string name;
    int power;
    Type type;

protected:
public:

    PhysicalMove(const std::string& name, const Type type, const int power)
    :Move(name, type, power) {}

   

    void execute(Pokemon* attacker,Pokemon* defender) const override{

        float phyDamage = (((power * attacker->getAtk() / defender->getPokemonDefence()) / 50) + 2);
         phyDamage *= attacker->getDamageMultiplier(type);
        //Hp update
        float newHP = defender->reduceHealth(phyDamage);

        if(attacker->getDamageMultiplier(type) == 0){std::cout<<"It dosen't affect "<<defender->getPokemonName()<<std::endl;}

        if(attacker->getDamageMultiplier(type) > 0 && attacker->getDamageMultiplier(type) < 1){std::cout<<"It's not very effective against "<<defender->getPokemonName()<<std::endl;}

        if(attacker->getDamageMultiplier(type) > 1){std::cout<<"It's very effective against "<<defender->getPokemonName()<<std::endl;}
        
    }

};