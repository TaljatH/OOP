#include "SpecialMove.h"
#include <iostream>

SpecialMove::SpecialMove(const std::string& name, const Type type, const int power)
    : Move(name, type, power){}

void SpecialMove::execute(Pokemon* attacker, Pokemon* defender) const {
    float spDamage = (((power * attacker->getSpAtk() / defender->getSpDef()) / 50) 
                     + 2 * attacker->getDamageMultiplier(type));

    float newHP = defender->reduceHealth(spDamage);

    if (attacker->getDamageMultiplier(type) == 0) {
        std::cout << "It doesn't affect " << defender->getPokemonName() << std::endl;
    }

    if (attacker->getDamageMultiplier(type) > 0 && attacker->getDamageMultiplier(type) < 1) {
        std::cout << "It's not very effective against " << defender->getPokemonName() << std::endl;
    }

    if (attacker->getDamageMultiplier(type) > 1) {
        std::cout << "It's very effective against " << defender->getPokemonName() << std::endl;
    }
}
