/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:36:27 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/21 12:49:13 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ScavTrap::attack( const std::string& target ) {
	if (this->getHitPoint() <= 0){
		std::cout	<< MSG_SCAVTRAP << this->getName()
					<< " can't attack: It's dead." << std::endl;
	} else if (this->getEnergyPoint() <= 0) {
		std::cout	<< MSG_SCAVTRAP << this->getName()
					<< " can't attack: No energy left." << std::endl;
	} else {
		std::cout	<< MSG_SCAVTRAP << this->getName()
					<< MSG_ATTACKS << target << MSG_CAUSING
					<< this->getAttackDamage() << MSG_DAMAGE << std::endl;
		this->subEnergyPoint( COST_ATTACK );
	}
	return ;
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {
	this->setHitPoint( ST_DEFAULT_HIT );
	this->setEnergyPoint( ST_DEFAULT_ENERGY );
	this->setAttackDamage( ST_DEFAULT_ATTACK );
	std::cout	<< MSG_SCAVTRAP << this->getName()
				<< MSG_CONSTRUCTOR << " [parameterized]" << std::endl;
	return ;
}

/******************************************************************************/
/**************************** CANONICAL REQUISITE *****************************/

ScavTrap &ScavTrap::operator=( const ScavTrap &rhs ) {
	this->setName( rhs.getName() );
	this->setHitPoint( rhs.getHitPoint() );
	this->setEnergyPoint( rhs.getEnergyPoint() );
	this->setAttackDamage( rhs.getAttackDamage() );
	return (*this);
}

ScavTrap::ScavTrap( const ScavTrap &src ) : ClapTrap() {
	*this = src;
	std::cout	<< MSG_SCAVTRAP << this->getName()
				<< MSG_CONSTRUCTOR << " [reference]" << std::endl;
	return ;
}

/******************************************************************************/
/********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ************************/

ScavTrap::ScavTrap( void ) : ClapTrap() {
	this->setHitPoint( ST_DEFAULT_HIT );
	this->setEnergyPoint( ST_DEFAULT_ENERGY );
	this->setAttackDamage( ST_DEFAULT_ATTACK );
	std::cout << "ScavTrap" << MSG_CONSTRUCTOR << " [default]" << std::endl;
	return ;
}

ScavTrap::~ScavTrap( void ) {
	std::cout	<< MSG_SCAVTRAP << this->getName()
				<< MSG_DESTRUCTOR << std::endl;
	return ;
}
