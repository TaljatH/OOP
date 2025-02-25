#pragma once

#include <string>
#include "Type.h"
#include "Move.h"



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


   
    Pokemon(const std::string& name, const Type type, const Move* move1, const Move* move2, const Move* move3, const Move* move4, const int health, const int attack, const int spAttack, const int defense, const int spDefense)
    :move1(move1), move2(move2), move3(move3), move4(move4),type(type), Name(name)
    {
        if(health <= 0){
            throw "Pokemons health is 0";
        }else{Health = health;}

        if(attack <= 0){
            throw "Pokemons attack is 0";
        }else{Attack = attack;}

        if(spAttack <= 0){
            throw "Pokemons spAttack is 0";
        }else{SpecialAttack = spAttack;}

        if(spDefense <= 0){
            throw "Pokemons spDefense is 0";
        }else{SpecialDefence = spDefense;}

        if(defense <= 0){
            throw "Pokemon has no defense";
        }else{Defence = defense;}

    }

    
    void executeMove1(Pokemon* target) {
        move1->perform(this, target);
    }
    void executeMove2(Pokemon* target) {
        move2->perform(this, target);
    }
    void executeMove3(Pokemon* target) {
        move3->perform(this, target);
    }
    void executeMove4(Pokemon* target) {
        move4->perform(this, target);
    }

    void faint() {
        std::cout << Name << " has fainted!\n";
        Health = 0; // Ensure health is 0
    }

    

    int reduceHealth(int dmg){
        Health -= dmg;

        if(Health <= 0){
            faint();
        }

        return Health;
    }

  

    virtual float getDamageMultiplier(Type attackerType) const{
        return TypeChart::getDamageMultiplier(attackerType,type);
    }


    //Getters
    std::string getPokemonName(){return Name;}
    int getPokemonDefence(){return Defence;}
    int getAtk(){return Attack;}
    int getSpAtk(){return SpecialAttack;}
    int getSpDef(){return SpecialDefence;}
    int getPokemonHp(){return Health;}

    
};