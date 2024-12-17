#pragma once

#include <string>
#include "Pokemon.h"


class DualTypePokemon : public Pokemon {
private:
    Type type2;
    
protected:
public:

   

    DualTypePokemon(const std::string& name, const Type type1, const Type type2, const Move* move1, const Move* move2, const Move* move3, const Move* move4, const int health, const int attack, const int spAttack, const int defense, const int spDefense); 
 

    float getDamageMultiplier(Type attackerType) const override;
    
    


   
};