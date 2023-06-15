#ifndef HUMANA_H
# define HUMANA_H

#include <string>


class HumanA {
    private:
        std::string name;
        std::string weapon;
    public:
        HumanA(const std::string& humanName, const std::string& weaponType);
        void attack() const;
};


#endif
