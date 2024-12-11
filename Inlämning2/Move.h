#pragma once

#include <iostream>

#include <string>
#include "Type.h"

class Pokemon; //behövs för perform()

/*
* x Klassen ska innehålla ett namn, en Type och en power som är en int. 
* x Alla ska vara icke-muterbara. Om power är negativ ska ett exception kastas 
* x under initiering.
* 
* x omuterbart = const
*
* x Klassen är abstrakt.
*/


class Move{
private:
    std::string Name;
    std::string ntype;
    int Power;

protected:
    //vad? Ska vara rent virtuell, och därefter implementeras av PhysicalMove och SpecialMove.
    //execute()

    virtual void ExecuteMove() = 0;

public:

    // Klassens konstruktor. Den ska initiera klassen.
    // Om power är negativ ska exception kastas.
    Move(const std::string& name, const Type type, const int power){
        if(power < 0){
            throw "Your pokemon power is negative";
        }else{Power = power;}

        Name = name; 
        ntype = type;
    }

    Move() {} //finns endast för kompilering, kan tas bort senare.

    // x Funktionen ska ta 2 Pokemon-pekare som argument, en som är en 
    // x attackerare och en försvarare.                      
    // 
    // x Funktionen ska skriva ut till konsollen vilken Pokemon som använder vilken Move. 
    // 
    // Efter det ska den kalla på execute(). execute() ska dock endast kallas 
    // om antingen den attackerandes eller den försvarandes health inte är 0.
    // 
    // Ifall den inte körs, så ska ett meddelande skrivas ut som beskriver situationen.
    // (titta i main.cpp för utskrift).
    // 
    // Ifall den körs, och om försvararens health är 0, ska det skrivas ut att 
    // den har "fainted".
    // 
    //perform()

    void PokePoint(Pokemon* Attacker , DualTypePokemon* Defender){
        std::cout<<Attacker->GetPokemonName()<<" used: " << Name;
    }



    //Getters
    int GetPower(){return Power;}
};
