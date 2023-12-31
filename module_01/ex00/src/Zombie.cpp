/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:22:36 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/09 09:09:27 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::setName(std::string const zombie_name) {
	this->name = zombie_name;
	return ;
};

std::string Zombie::_getName( void ) const {
	return (this->name);
};


void Zombie::announce( void ) {
	std::cout << this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

/// @brief Basic constructor 
Zombie::Zombie (std::string zombie_name){
	this->setName(zombie_name);
	return ;
};

/// @brief Destructor 
Zombie::~Zombie( void ){
	std::cout << this->_getName() << " destroyed." << std::endl;
};