#pragma once

#include <string>
#include "Pokemon.h"



class DualTypePokemon : public Pokemon {
private:
    Type type2;
    
protected:
public:

   


    DualTypePokemon(const std::string& name, const Type type1, const Type type2, const Move* move1, const Move* move2, const Move* move3, const Move* move4, const int health, const int attack, const int spAttack, const int defense, const int spDefense) 
    :Pokemon(name,type1,move1,move2,move3,move4,health,attack,spAttack,defense,spDefense)
    ,type2(type2)
    {}  

    
    float getDamageMultiplier(Type attackerType) const override {
        float m1 = TypeChart::getDamageMultiplier(attackerType, type);
        float m2 = TypeChart::getDamageMultiplier(attackerType, type2);
    
        
    
        return m1 * m2;
    }

   
};