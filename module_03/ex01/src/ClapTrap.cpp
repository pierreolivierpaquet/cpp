/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:28:26 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/22 10:18:17 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

/******************************************************************************/
/******************************* SETTER+GETTER ********************************/

std::string	ClapTrap::getName( void ) const {
	if (this->_name.empty() == true){
		return ("*Without a name*");
	}
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

void	ClapTrap::setEnergyPoint( const int points ) {
	this->_energy_point = points;
	return ;
}

void	ClapTrap::setAttackDamage( const int points ) {
	this->_attack_damage = points;
}

/// @brief Substracts the <amount of points> to the instance's energy. 
void	ClapTrap::subEnergyPoint( const int points ) {
	this->_energy_point -= points;
	return ;
}

/// @brief Substracts the <amount of points> to the instance's Hit Points.
void	ClapTrap::subHitPoint( const int points ) {
	this->_hit_point -= points;
	return ;
}

/// @brief Adds the <amount of points> to the instance's Hit Points).
void	ClapTrap::addHitPoints( const int points ) {
	this->_hit_point += points;
	return ;
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

ClapTrap::ClapTrap( const std::string name ) :
	_name			( name ),
	_hit_point		( CT_DEFAULT_HIT ),
	_energy_point	( CT_DEFAULT_ENERGY ),
	_attack_damage	( CT_DEFAULT_ATTACK ) {
	std::cout	<< MSG_CLAPTRAP << this->getName()
				<< MSG_CONSTRUCTOR << " [parameterized]" << std::endl;
	return ;
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
	*this = source;
	std::cout	<< MSG_CLAPTRAP << this->_name
				<< MSG_CONSTRUCTOR << " [reference copy]" << std::endl;
	return ;
}

/******************************************************************************/
/********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ************************/

ClapTrap::ClapTrap( void ) :
	_name			( EMPTY_STR ),
	_hit_point		( CT_DEFAULT_HIT ),
	_energy_point	( CT_DEFAULT_ENERGY ),
	_attack_damage	( CT_DEFAULT_ATTACK ) {
	std::cout << "ClapTrap" << MSG_CONSTRUCTOR << " [default]" << std::endl;
	return ;
}

ClapTrap::~ClapTrap( void ) {
	std::cout	<< MSG_CLAPTRAP << this->getName()
				<< MSG_DESTRUCTOR << std::endl;
	return ;
}

/******************************************************************************/

void	ClapTrap::attack( const std::string &target ) {
	if (this->getHitPoint() <= 0){
		std::cout	<< MSG_CLAPTRAP << this->getName()
					<< " can't attack: It's dead." << std::endl;
	} else if (this->getEnergyPoint() <= 0) {
		std::cout	<< MSG_CLAPTRAP << this->getName()
					<< " can't attack: No energy left." << std::endl;
	} else {
		std::cout	<< MSG_CLAPTRAP << this->getName()
					<< MSG_ATTACKS << target << MSG_CAUSING
					<< this->getAttackDamage() << MSG_DAMAGE << std::endl;
		this->subEnergyPoint( COST_ATTACK );
	}
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (amount == 0 && this->getHitPoint() > 0) {
		std::cout	<< MSG_CLAPTRAP << this->getName()
					<< " took no hit damage: " << "Still has "
					<< this->getHitPoint() << " hit points." << std::endl;
		return ;
	} else if (this->getHitPoint() == 0) {
		std::cout	<< MSG_CLAPTRAP << this->getName()
					<< " is aldready dead: No damage inflicted."
					<< std::endl;
	} else {
		/*	ClapTrap takes the damage. */
		this->subHitPoint( amount );
		if (this->getHitPoint() < 0){
			this->setHitPoint( CT_DEAD );
		}
		std::cout	<< MSG_CLAPTRAP << this->getName()
					<< " took -" << amount << " of hit damage: It now has "
					<< this->getHitPoint() << " hit points." << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (amount == 0){
		return ;
	} else if (this->getEnergyPoint() <= 0){
		std::cout	<< MSG_CLAPTRAP << this->getName()
					<< " can't be repaired: Not enough energy." << std::endl;
	} else if (this->getHitPoint() <= 0) {
		std::cout	<< MSG_CLAPTRAP << this->getName()
					<< " can't be repaired: It's dead." << std::endl;
	} else {
		this->addHitPoints( amount );
		this->subEnergyPoint( COST_REPAIR );
		std::cout	<< MSG_CLAPTRAP << this->getName()
					<< " +" << amount << " repaired: It now has " 
					<< this->getHitPoint() << " hit points " << "and "
					<< this->getEnergyPoint() << " energy points." << std::endl;
	}
	return ;
}
