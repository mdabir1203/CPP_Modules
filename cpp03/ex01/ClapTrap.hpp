#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &source);
        ~ClapTrap();

        ClapTrap &operator=(const ClapTrap &source);

        void attack(std::string const &target, unsigned int amount);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
        std::string getName(void) const;    
        unsigned int getHitPoints(void) const;
        unsigned int getEnergyPoints(void) const;
        unsigned int getAttackDamage(void) const;

        void setName(std::string name);
        void setHitPoints(std::string name);
        void setEnergyPoints(std::string name);
        void setAttackDamage(std::string name);



};

std::ostream &operator<<(std::ostream &out, const ClapTrap &source);

#endif
