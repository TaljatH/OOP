#pragma once

#include <string>
#include "Move.h"

class SpecialMove : public Move {
private:
    std::string name;
    int power;
    Type type;
protected:
public:

    //x Klassens konstruktor. Den ska initiera klassen.
    SpecialMove(const std::string& name, const Type type, const int power)
    :name(name),type(type),power(power){}

    // x Exakt som i PhysicalMove, förutom att denna ska använda sig av 
    // x specialDefence och specialAttack istället för attack och defence.
    // 
    //x execute() override

    void execute(Pokemon* attacker,DualTypePokemon* defender) override{

        int spDamage =  (((power * attacker->getSpAtk() / defender->getSpDualDef()) / 50) + 2);

        
    }

};
