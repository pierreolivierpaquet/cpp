/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:05:24 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/09 16:14:25 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/// @brief Weapon type setter.
void	Weapon::setType(const std::string weapon_type) {
	this->_type = weapon_type;
	return ;
}

/// @brief Weapon type getter. 
const std::string	&Weapon::_getType( void ) const {
	const std::string &weaponReference = this->_type;
	return (weaponReference);
}

/// @brief Constructor.
Weapon::Weapon (const std::string weapon_type) : _type(weapon_type) {}

/// @brief Destructor.
Weapon::~Weapon ( void ) {}
