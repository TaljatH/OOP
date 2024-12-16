#include "Move.h"
#include "Pokemon.h"

void Move::perform(Pokemon* attacker, Pokemon* defender) const {
    if (attacker->getPokemonHp() <= 0) {
        std::cout << attacker->getPokemonName() << " has fainted and cannot attack!\n";
        return;
    }
    if (defender->getPokemonHp() <= 0) {
        std::cout << defender->getPokemonName() << " has fainted and cannot be attacked!\n";
        return;
    }

    std::cout << attacker->getPokemonName() << " used " << name << "!\n";
    
    execute(attacker, defender);

    if(defender->getPokemonHp() <= 0) {
        std::cout << defender->getPokemonName() << " has fainted!\n";
    }
}
