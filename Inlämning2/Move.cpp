#include "Move.h"
#include "Pokemon.h"

void Move::perform(Pokemon* attacker, Pokemon* defender) const {
    if (attacker->getPokemonHp() <= 0) {
        std::cout << attacker->getPokemonName() << " has fainted and cannot move!\n\n";
        return;
    }
    // Gengar cannot perform the move, Pikachu has already fainted.
    if (defender->getPokemonHp() <= 0) {
        std::cout<<attacker->getPokemonName()<<" cannot perform the move, " << defender->getPokemonName() << " has already fainted\n\n";
        return;
    }

    std::cout << attacker->getPokemonName() << " used " << name << "!\n";
    
    execute(attacker, defender);

    if(defender->getPokemonHp() <= 0) {
        std::cout << defender->getPokemonName() << " has fainted!\n";
    }

    std::cout <<std::endl;
}
