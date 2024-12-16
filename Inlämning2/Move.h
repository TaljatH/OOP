#pragma once

#include <iostream>

#include <string>
#include "Type.h"

#include "Pokemon.h"

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
    std::string name;
    int power;
    Type type;

protected:
    //x Ska vara rent virtuell, och därefter implementeras av PhysicalMove och SpecialMove.
    //x execute()

    virtual void execute(Pokemon* attacker , Pokemon* defender) const = 0;

public:

    //x Klassens konstruktor. Den ska initiera klassen.
    //x Om power är negativ ska exception kastas.
    Move(const std::string& name, const Type type, const int power)
    :name(name),type(type),power(power)
    {}

    // x Funktionen ska ta 2 Pokemon-pekare som argument, en som är en 
    // x attackerare och en försvarare.                      
    // 
    // x Funktionen ska skriva ut till konsollen vilken Pokemon som använder vilken Move. 
    // 
    // x Efter det ska den kalla på execute(). execute() ska dock endast kallas 
    // x om antingen den attackerandes eller den försvarandes health inte är 0.
    // 
    // x Ifall den inte körs, så ska ett meddelande skrivas ut som beskriver situationen.
    // x (titta i main.cpp för utskrift).
    // 
    // x Ifall den körs, och om försvararens health är 0, ska det skrivas ut att 
    // x den har "fainted".
    // 
    // x perform() const

    void perform(Pokemon* attacker , Pokemon* defender) const;


    Type GetType() const { return type; }

};
