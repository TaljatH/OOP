#pragma once

#include <string>
#include "Move.h"
#include "Type.h"

/*
 x Klassen ska ha 4 const Move pekare x   Fråga: en const Type samt ett icke-muterbart namn.

x Klassen ska även ha följande fält:

x attack, health, specialAttack, defence, specialDefence.

x De ska alla vara int. De får inte vara negativa eller 0, 
x då ska exception kastas under initiering.
*/

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


    // x Klassens konstruktor. Den ska initiera klassen.
    // x Ifall något av Pokemonens "stats" (ex health eller attack) är 0 eller negativt ska exception kastas.
    Pokemon(const std::string& name, const Type type, const Move* move1, const Move* move2, const Move* move3, const Move* move4, const int health, const int attack, const int spAttack, const int defense, const int spDefense);
    

    //Pokemon() {} //finns endast för kompilering, kan tas bort senare.

    // Funktionerna ska göra så att Pokemonen utför respektive Move på en Pokemon.
    void executeMove1(Pokemon* target);
    void executeMove2(Pokemon* target);
    void executeMove3(Pokemon* target);
    void executeMove4(Pokemon* target);

    // x Funktionen ska subtrahera Pokemonens hälsa med argumentet.
    // x Om detta skulle resultera i negative health ska health sättas till 0.
    // 
    //reduceHealth();

    int reduceHealth(int dmg);

    // x Funktionen ska räkna ut "damage multiplier" mot sig själv, baserat 
    // x på ett argument som bestämmer attackerande typ.
    // x Ex. en FIRE-attack på en WATER-Pokemon är 0.5 (hälften) så effektiv.
    // x Funktionen ska använda sig getDamageMultiplier() innanför Type.
    // 
    // x Funktionen ska vara virtuell men INTE rent virtuell, då 
    // dess beteende ska kunna överskrivas av DualTypePokemon.
    // 

    virtual float getDamageMultiplier(Type attackerType) const;


    //Getters
    std::string getPokemonName();
    int getPokemonDefence();
    int getAtk();
    int getSpAtk();
    int getSpDef();
    int getPokemonHp();
};