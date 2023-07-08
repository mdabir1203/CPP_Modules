#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << name << " is created." << std::endl;
}


std::cout << "ScavTrap " << getName() << " is copied." << std::endl;


ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source)
{
    std::cout << "ScavTrap " << name << " is copied." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " is destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &source)
{
    ClapTrap::operator=(source);
    return *this;
}

void ScavTrap::attack(std::string const &target, unsigned int amount)
{
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is in Gatekeeper mode." << std::endl;
}
