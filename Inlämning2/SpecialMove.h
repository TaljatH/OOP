#pragma once

#include <string>
#include "Move.h"
#include "Pokemon.h"

class SpecialMove : public Move {
private:
    
protected:
public:

    SpecialMove(const std::string& name, const Type type, const int power)
    :Move(name, type, power){}

    void execute(Pokemon* attacker,Pokemon* defender) const override{

        float mult = defender->getDamageMultiplier(type);

        float spDamage =  (((power * attacker->getSpAtk() / defender->getSpDef()) / 40) + 2 * mult);
        
        //Hp update
        float newHP = defender->reduceHealth(spDamage);
    

        if(mult == 0){std::cout<<"It doesn't affect "<<defender->getPokemonName()<<std::endl;}

        if (mult > 0 && mult < 1) {
            std::cout << "It's not very effective against " << defender->getPokemonName() << std::endl;
        }
        
        if(mult > 1){std::cout<<"It's super effective against "<<defender->getPokemonName()<<std::endl;}


    }

};
