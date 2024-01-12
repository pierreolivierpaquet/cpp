/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:17:27 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/11 21:05:46 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

std::string Zombie::getName( void ) const {
	return (this->_name);
};

void	Zombie::setName( std::string const zombie_name ){
	this->_name = zombie_name;
	return ;
};

void Zombie::announce( void ) {
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

Zombie::Zombie( void ){};

Zombie::~Zombie( void ){
	std::cout << this->getName() << " destroyed." << std::endl;
};
