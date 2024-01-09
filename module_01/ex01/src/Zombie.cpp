/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:17:27 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/09 12:03:17 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ){};

Zombie::~Zombie( void ){
	std::cout << this->_getName() << " destroyed." << std::endl;
};

std::string Zombie::_getName( void ) const {
	return (this->name);
};

void	Zombie::setName(std::string const zombie_name){
	this->name = zombie_name;
	return ;
};

void Zombie::announce( void ) {
	std::cout << this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
