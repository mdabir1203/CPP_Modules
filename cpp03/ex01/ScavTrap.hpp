#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &source);
        ~ScavTrap();

        ScavTrap &operator=(const ScavTrap &source);

        void attack(std::string const &target, unsigned int amount);
        void guardGate();
};

#endif
