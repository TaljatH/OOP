#pragma once

#include <string>
#include "Move.h"

#include "Pokemon.h"

class SpecialMove : public Move {
private:
    std::string name;
    int power;
    Type type;
protected:
public:

    //x Klassens konstruktor. Den ska initiera klassen.
    SpecialMove(const std::string& name, const Type type, const int power)
    :name(name),type(type),power(power){}

    // x Exakt som i PhysicalMove, förutom att denna ska använda sig av 
    // x specialDefence och specialAttack istället för attack och defence.
    // 
    //x execute() override

    void execute(Pokemon* attacker,Pokemon* defender) const override{

        int spDamage =  (((power * attacker->getSpAtk() / defender->getSpDef()) / 50) + 2 * attacker->getDamageMultiplier(type));

        //Hp update
        float newHP = defender->reduceHealth(spDamage);

        
        if(attacker->getDamageMultiplier(type) == 0){std::cout<<"It dosen't affect "<<defender->getPokemonName()<<std::endl;}

        if(attacker->getDamageMultiplier(type) < 1 && attacker->getDamageMultiplier(type) > 0){std::cout<<"It's not very effective against "<<defender->getPokemonName()<<std::endl;}

        if(attacker->getDamageMultiplier(type) > 1){std::cout<<"It's very effective against "<<defender->getPokemonName()<<std::endl;}


    }

};
