/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:47:39 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/11 21:25:45 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"HumanA.hpp"

std::string HumanA::getName( void ) const {
	return ( this->_name );
}

std::string HumanA::getWeaponType() const {
	return ( this->_Weapon.getType() );
}

void	HumanA::attack( void ) {
	std::cout	<< this->getName()
				<< ATTACK_ACTION << this->getWeaponType() << std::endl;
	return ;
}

/// @brief Constructor.
HumanA::HumanA(const std::string human_name, Weapon &weaponRef) :
	_name( human_name ),
	_Weapon( weaponRef ) {}

/// @brief Destructor. 
HumanA::~HumanA( void ) {}
