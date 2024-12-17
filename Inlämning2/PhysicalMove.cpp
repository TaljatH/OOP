#include "PhysicalMove.h"
#include <iostream>

PhysicalMove::PhysicalMove(const std::string& name, const Type type, const int power)
    : name(name), type(type), power(power) {}

void PhysicalMove::execute(Pokemon* attacker, Pokemon* defender) const {
    float phyDamage = (((power * attacker->getAtk() / defender->getPokemonDefence()) / 50) + 2 * attacker->getDamageMultiplier(type));

    // Hp update
    float newHP = defender->reduceHealth(phyDamage);

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
