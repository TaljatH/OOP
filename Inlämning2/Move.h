#pragma once


#include "Pokemon.h"

class Pokemon;  // Forward declaration



class Move{
private:
    std::string name;
    int power;
    Type typee;

protected:
  

    virtual void execute(Pokemon* attacker , Pokemon* defender) const = 0;


public:

    Move(const std::string& name, const Type type, const int power)
    :name(name),typee(type),power(power){}


    void perform(Pokemon* attacker , Pokemon* defender) const;



    virtual ~Move() {} //destructor

};
