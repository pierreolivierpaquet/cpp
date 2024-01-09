/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:47:39 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/09 17:54:42 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

std::string HumanA::_getName( void ) const {
	return (this->_name);
}

std::string HumanA::_getWeaponType() const {
	return (this->_Weapon._getType());
}

void	HumanA::attack( void ) {
	std::cout	<< this->_getName()
				<< ATTACK_ACTION << this->_getWeaponType() << std::endl;
	return ;
}

/// @brief Constructor.
HumanA::HumanA(const std::string human_name, Weapon &weaponRef) :
	_name(human_name),
	_Weapon(weaponRef) {}

/// @brief Destructor. 
HumanA::~HumanA( void ) {}