/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:47:41 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/09 17:55:20 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

std::string HumanB::_getName( void ) const {
	return (this->_name);
}

std::string	HumanB::_getWeaponType( void ) const {
	if (this->_Weapon){
		return (this->_Weapon->_getType());
	}
	return (DEFAULT_WEAPON);
}

void	HumanB::attack( void ) {
	std::cout	<< this->_getName()
				<< ATTACK_ACTION << this->_getWeaponType() << std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon) {
	this->_Weapon = &new_weapon;
	return ;
}

/// @brief Constructor.
HumanB::HumanB (const std::string human_name) : _name(human_name) {
	this->_Weapon = NULL;
	return ;
}

/// @brief Destructor. 
HumanB::~HumanB ( void ) {}
