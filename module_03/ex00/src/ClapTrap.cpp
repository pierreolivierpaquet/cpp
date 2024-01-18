/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:28:26 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/18 17:23:35 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/******************************************************************************/
/******************************* SETTER+GETTER ********************************/

std::string	ClapTrap::getName( void ) const {
	return ( this->_name );
}

int	ClapTrap::getHitPoint( void ) const {
	return( this->_hit_point );
}

int	ClapTrap::getEnergyPoint( void ) const {
	return ( this->_energy_point );
}

int	ClapTrap::getAttackDamage( void ) const {
	return ( this->_attack_damage );
}

/******************************************************************************/
/*************************** PARAMETRIC CONSTRUCTOR ***************************/

ClapTrap::ClapTrap( const std::string name ) :
	_name			( name ),
	_hit_point		( DEFAULT_HIT ),
	_energy_point	( DEFAULT_ENERGY ),
	_attack_damage	( DEFAULT_ATTACK ) {
		std::cout << "[ PARAMETRIC ] Constructor called." << std::endl;
	}

/******************************************************************************/
/**************************** CANONICAL REQUISITE *****************************/

/// @returns Reference to the updated current instance. 
ClapTrap	&ClapTrap::operator=( const ClapTrap &rhs ) {
	this->_name				=	rhs.getName();
	this->_hit_point		=	rhs.getHitPoint();
	this->_energy_point		=	rhs.getEnergyPoint();
	this->_attack_damage	=	rhs.getAttackDamage();
	return ( *this );
}

/// @brief Instance contructor based on another instance reference.
ClapTrap::ClapTrap( const ClapTrap &source ) {
	std::cout << "[ COPY ] Constructor called." << std::endl;
	*this = source;
	return ;
}

/******************************************************************************/
/********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ************************/

ClapTrap::ClapTrap( void ) :
	_name			( EMPTY_STR ),
	_hit_point		( DEFAULT_HIT ),
	_energy_point	( DEFAULT_ENERGY ),
	_attack_damage	( DEFAULT_ATTACK ) {}

ClapTrap::~ClapTrap( void ) {
	std::cout << "[ DEFAULT ] Destructor called." << std::endl;
}

/******************************************************************************/

void	ClapTrap::attack( const std::string &target ) {
	std::cout << MSG_CLAPTRAP << this->getName() << MSG_ATTACKS << target << MSG_CAUSING << this->getAttackDamage() << MSG_DAMAGE << std::endl;
	return ;
}
