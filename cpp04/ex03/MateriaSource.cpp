/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:23:51 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/11 02:20:58 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (materias[i])
            delete materias[i];
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    *this = src;
}

MateriaSource& MateriaSource::operator=( MateriaSource const & rhs )
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
            materias[i] = rhs.materias[i];
    }
    return *this;
}

AMateria* MateriaSource::getMateria( std::string const & type )
{
    for (int i = 0; i < 4; i++)
        if (materias[i] && materias[i]->getType() == type)
            return materias[i];
    return NULL;
}

void    MateriaSource::learnMateria( AMateria* m )
{
    int i = 0;
    while (i < 4 && materias[i] != NULL)
        i++;
    
    for (int i = 0; i < 4; i++)
        if (materias[i] == NULL)
        {
            materias[i] = m;
            // std::cout << "MateriaSource learning " << m->getType() << std::endl;
            return;
        }
    // std::cout << "MateriaSource can't learn " << m->getType() << std::endl;
}

AMateria*   MateriaSource::createMateria( std::string const& type ) {
    for ( int i = 0; i < 4; i++ )
        if ( materias[i] && materias[i]->getType() == type )
            return materias[i]->clone();
    return NULL;
}