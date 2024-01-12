/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:22:36 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/12 11:55:41 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

void	Zombie::setName(std::string const zombie_name) {
	this->_name = zombie_name;
	return ;
};

std::string Zombie::getName_( void ) const {
	return (this->_name);
};

void Zombie::announce( void ) {
	std::cout << this->getName_() << ANNOUNCE_MESSAGE << std::endl;
};

/******************************************************************************/

/// @brief Default constructor.
Zombie::Zombie( std::string zombie_name ){
	this->setName( zombie_name );
	return ;
};

/// @brief Destructor.
Zombie::~Zombie( void ){
	std::cout << this->getName_() << " destroyed." << std::endl;
};
