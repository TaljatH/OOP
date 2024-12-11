#pragma once

#include <string>
#include "Type.h"
#include "Move.h"

/*
Klassen ska ha 4 const Move pekare, en const Type samt ett icke-muterbart namn.

Klassen ska även ha följande fält:

attack, health, specialAttack, defence, specialDefence.

De ska alla vara int. De får inte vara negativa eller 0, 
då ska exception kastas under initiering.
*/

class Pokemon{
private:
protected:
public:

    // Klassens konstruktor. Den ska initiera klassen.
    // Ifall något av Pokemonens "stats" (ex health eller attack) är 0 eller negativt ska exception kastas.
    Pokemon(const std::string& name, const Type type, const Move* move1, const Move* move2, const Move* move3, const Move* move4, const int health, const int attack, const int spAttack, const int defense, const int spDefense)
    {
    }

    Pokemon() {} //finns endast för kompilering, kan tas bort senare.

    // Funktionerna ska göra så att Pokemonen utför respektive Move på en Pokemon.
    void executeMove1(Pokemon* target) {

    }
    void executeMove2(Pokemon* target) {

    }
    void executeMove3(Pokemon* target) {

    }
    void executeMove4(Pokemon* target) {

    }

    // Funktionen ska subtrahera Pokemonens hälsa med argumentet.
    // Om detta skulle resultera i negative health ska health sättas till 0.
    // 
    //reduceHealth();

    // Funktionen ska räkna ut "damage multiplier" mot sig själv, baserat 
    // på ett argument som bestämmer attackerande typ.
    // Ex. en FIRE-attack på en WATER-Pokemon är 0.5 (hälften) så effektiv.
    // Funktionen ska använda sig getDamageMultiplier() innanför Type.
    // 
    // Funktionen ska vara virtuell men INTE rent virtuell, då 
    // dess beteende ska kunna överskrivas av DualTypePokemon.
    // 
    //calculateDamageMultiplier();
};