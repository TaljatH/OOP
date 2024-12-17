#include "Pokemon.h"
#include "Type.h"

Pokemon::Pokemon(const std::string& name, const Type type, const Move* move1, const Move* move2, const Move* move3, const Move* move4, const int health, const int attack, const int spAttack, const int defense, const int spDefense)
    : move1(move1), move2(move2), move3(move3), move4(move4), type(type), Name(name) {

    if (health <= 0) {
        throw "Pokemon's health is 0";
    } else {
        Health = health;
    }

    if (attack <= 0) {
        throw "Pokemon's attack is 0";
    } else {
        Attack = attack;
    }

    if (spAttack <= 0) {
        throw "Pokemon's special attack is 0";
    } else {
        SpecialAttack = spAttack;
    }

    if (spDefense <= 0) {
        throw "Pokemon's special defense is 0";
    } else {
        SpecialDefence = spDefense;
    }

    if (defense <= 0) {
        throw "Pokemon has no defense";
    } else {
        Defence = defense;
    }
}

void Pokemon::executeMove1(Pokemon* target) {
    move1->perform(this, target);
}

void Pokemon::executeMove2(Pokemon* target) {
    move2->perform(this, target);
}

void Pokemon::executeMove3(Pokemon* target) {
    move3->perform(this, target);
}

void Pokemon::executeMove4(Pokemon* target) {
    move4->perform(this, target);
}

int Pokemon::reduceHealth(int dmg) {
    Health -= dmg;

    if (Health <= 0) {
        Health = 0;
    }

    return Health;
}

float Pokemon::getDamageMultiplier(Type attackerType) const {
    return TypeChart::getDamageMultiplier(attackerType, type);
}

std::string Pokemon::getPokemonName() {
    return Name;
}

int Pokemon::getPokemonDefence() {
    return Defence;
}

int Pokemon::getAtk() {
    return Attack;
}

int Pokemon::getSpAtk() {
    return SpecialAttack;
}

int Pokemon::getSpDef() {
    return SpecialDefence;
}

int Pokemon::getPokemonHp() {
    return Health;
}
