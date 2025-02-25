#pragma once

#include <iostream>

#include <string>
#include "Type.h"

class Pokemon; 


class Move{
private:
    std::string name;
    int power;
    Type type;

protected:
    
    virtual void execute(Pokemon* attacker , Pokemon* defender) const = 0;

public:

   
    Move(const std::string& name, const Type type, const int power)
    :name(name),type(type),power(power)
    {}

    void perform(Pokemon* attacker , Pokemon* defender) const;


    Type GetType() const { return type; }

};
