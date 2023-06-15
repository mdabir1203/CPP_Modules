#ifndef HUMANB_H
# define HUMANB_H

#include <string>

class HumanB
{
    private:
        std::string name;
        bool weaponPresent;
    public:
        HumanB(const std::string& humanName);
        void setWeapon(const std::string& chooseWeapon);
        void attack();
};


#endif //CPP01_HUMANB_H
