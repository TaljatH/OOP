#pragma once

#include <string>
#include "Move.h"

class PhysicalMove : public Move{
private:
    std::string name;
    int power;
    Type type;

protected:
public:
    PhysicalMove(const std::string& name, const Type type, const int power);

  

    void execute(Pokemon* attacker,Pokemon* defender) const override;

       

};