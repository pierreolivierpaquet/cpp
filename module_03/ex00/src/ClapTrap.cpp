/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:28:26 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/19 12:11:26 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

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

void	ClapTrap::setName( const std::string name ) {
	this->_name = name;
	return ;
}

void	ClapTrap::setHitPoint( const int points ) {
	this->_hit_point = points;
	return ;
}

void	ClapTrap::subEnergyPoint( const int points ) {
	this->_energy_point -= points;
	return ;
}

void	ClapTrap::subHitPoint( const int points ) {
	this->_hit_point -= points;
	return ;
}

void	ClapTrap::addHitPoints( const int points ) {
	this->_hit_point += points;
	return ;
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
	std::cout << MSG_CLAPTRAP << this->_name << "constructor called." << std::endl;
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
	if (this->getHitPoint() <= 0){
		std::cout << MSG_CLAPTRAP << this->getName() << " can't attack: It's dead." << std::endl;
	} else if (this->getEnergyPoint() <= 0) {
		std::cout << MSG_CLAPTRAP << this->getName() << " can't attack: No energy left." << std::endl;
	} else {
		std::cout << MSG_CLAPTRAP << this->getName() << MSG_ATTACKS << target << MSG_CAUSING << this->getAttackDamage() << MSG_DAMAGE << std::endl;
		this->subEnergyPoint( COST_ATTACK );
	}
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (amount == 0) {
		return ;
	} else {
		this->subHitPoint( amount );
		if (this->getHitPoint() < 0){
			this->setHitPoint( 0 );
		}
		std::cout << MSG_CLAPTRAP << this->getName() << " took " << amount << " of hit damage: It now has " << this->getHitPoint() << " hit points." << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (amount == 0){
		return ;
	} else if (this->getEnergyPoint() <= 0){
		std::cout << MSG_CLAPTRAP << this->getName() << " can't be repaired: Not enough energy." << std::endl;
	} else {
		this->addHitPoints( amount );
		this->subEnergyPoint( COST_REPAIR );
		std::cout << MSG_CLAPTRAP << this->getName() << " successfully repaired: It now has " << this->getHitPoint() << " hit points ";
		std::cout << "and " << this->getEnergyPoint() << " energy points." << std::endl;
	}
	return ;
}
