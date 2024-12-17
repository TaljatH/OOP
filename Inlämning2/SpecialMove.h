#pragma once

#include <string>
#include "Move.h"

#include "Pokemon.h"

class SpecialMove : public Move {
private:
    std::string name;
    int power;
    Type type;
protected:
public:

    SpecialMove(const std::string& name, const Type type, const int power);

   

    void execute(Pokemon* attacker,Pokemon* defender) const override;

};
