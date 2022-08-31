#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>


class Weapon
{
    
    private:
        std::string  type;

    public:
        // const std::string& getType() const;
        const std::string& getType();

        void setType(const std::string &type_orig);
    
    Weapon(const std::string type);

    ~Weapon();
};



#endif