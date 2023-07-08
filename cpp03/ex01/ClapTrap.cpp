#include "ClapTrap.hpp"

std::string ClapTrap::getName() const 
{
  return name;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source) : name(source.name), hitPoints(source.hitPoints), energyPoints(source.energyPoints), attackDamage(source.attackDamage)
{
    std::cout << "ClapTrap " << name << " is copied." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " is destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &source)
{
    if (this != &source)
    {
        name = source.name;
        hitPoints = source.hitPoints;
        energyPoints = source.energyPoints;
        attackDamage = source.attackDamage;
    }
    return *this;
}

void ClapTrap::attack(std::string const &target, unsigned int amount)
{
    if (energyPoints < amount)
    {
        std::cout << "ClapTrap " << name << " has no energy to attack." << std::endl;
        return;
    }
    energyPoints -= amount;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints < amount)
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " is out of hit points." << std::endl;
        return;
    }
    hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints < amount)
    {
        std::cout << "ClapTrap " << name << " has no energy to repair." << std::endl;
        return;
    }
    energyPoints -= amount;
    hitPoints = (hitPoints + amount > 10) ? 10 : hitPoints + amount;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " points." << std::endl;
}

std::string ClapTrap::getName(void) const
{
    return name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
    return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return attackDamage;
}

void ClapTrap::setName(std::string name)
{
    this->name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
    this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
    this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    this->attackDamage = attackDamage;
}

std::ostream & operator<<(std::ostream &out, ClapTrap const & source)
{
    out << "ClapTrap " << source.getName() << " has " << source.getHitPoints() << " hit points, " << source.getEnergyPoints() << " energy points and " << source.getAttackDamage() << " attack damage." << std::endl;
    return out;
}