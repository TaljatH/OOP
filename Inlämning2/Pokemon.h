#pragma once

#include <iostream>
#include <string>
#include "Move.h"
#include "Type.h"

class Pokemon{
private:
    //Stats
    int Attack , Health , SpecialAttack , Defence , SpecialDefence;

    std::string Name;

   const Move* move1;
   const Move* move2;
   const Move* move3;
   const Move* move4;
protected:
    Type type;
public:


    
    Pokemon(const std::string& name, const Type type, const Move* move1, const Move* move2, const Move* move3, const Move* move4, const int health, const int attack, const int spAttack, const int defense, const int spDefense);
    

   
    void executeMove1(Pokemon* target);
    void executeMove2(Pokemon* target);
    void executeMove3(Pokemon* target);
    void executeMove4(Pokemon* target);

  

    int reduceHealth(int dmg);


    virtual float getDamageMultiplier(Type attackerType) const;


    //Getters
    std::string getPokemonName();
    int getPokemonDefence();
    int getAtk();
    int getSpAtk();
    int getSpDef();
    int getPokemonHp();
};