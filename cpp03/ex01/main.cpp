#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Clap");
    ScavTrap scav("Scav");

    clap.attack("target", 5);
    clap.takeDamage(3);
    clap.beRepaired(2);

    scav.attack("target", 5);
    scav.guardGate();

    return 0;
}
