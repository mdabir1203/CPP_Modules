#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>


class Weapon
{
    private:
        std::string type;

    public:
        const std::string get_type() const;
        void set_type(std::string& chosenType);
};

/** Usage of base class-> ->
    * Polymorphism and inheritance
    * Common Interface
    * Code Organization and maintainability
    * Abstraction and Encapsulation
    * Polymorphic Functionality
    * Flexibility and Extensibility
    * Code modularity
   Here I use abstract base clas ->
        Compile-Time Error detection
        Dependency Inversion
        Design Flexibility
        Enforcing Contacts
 */


#endif
