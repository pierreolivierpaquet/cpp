/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:17:27 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/12 12:13:57 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

std::string Zombie::getName_( void ) const {
	return (this->_name);
};

void	Zombie::setName( std::string const zombie_name ){
	this->_name = zombie_name;
	return ;
};

void Zombie::announce( void ) {
	std::cout << this->getName_() << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

Zombie::Zombie( void ){};

Zombie::~Zombie( void ){
	std::cout << this->getName_() << " destroyed." << std::endl;
};
