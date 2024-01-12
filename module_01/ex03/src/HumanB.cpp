/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:47:41 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/12 12:31:46 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"HumanB.hpp"

std::string HumanB::getName( void ) const {
	return ( this->_name );
}

const std::string	HumanB::getWeaponType_( void ) const {
	if ( this->_Weapon ){
		return ( this->_Weapon->getType_() );
	}
	return ( DEFAULT_WEAPON );
}

void	HumanB::attack( void ) {
	std::cout	<< this->getName()
				<< ATTACK_ACTION << this->getWeaponType_() << std::endl;
}

void	HumanB::setWeapon( Weapon &new_weapon ) {
	this->_Weapon = &new_weapon;
	return ;
}

/// @brief Constructor.
HumanB::HumanB ( const std::string human_name ) : _name( human_name ) {
	this->_Weapon = NULL;
	return ;
}

/// @brief Destructor. 
HumanB::~HumanB ( void ) {}
