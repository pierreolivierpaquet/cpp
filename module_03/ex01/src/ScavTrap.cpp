/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:36:27 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/22 10:18:35 by ppaquet          ###   ########.fr       */
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

void	ScavTrap::guardGate( void ) {
	std::cout	<< MSG_SCAVTRAP << this->getName()
				<< " has turned into GATEKEEPER mode!" << std::endl;
	return ;
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {
	this->_hit_point = ST_DEFAULT_HIT;
	this->_energy_point = ST_DEFAULT_ENERGY;
	this->_attack_damage = ST_DEFAULT_ATTACK;
	// this->setHitPoint( ST_DEFAULT_HIT );
	// this->setEnergyPoint( ST_DEFAULT_ENERGY );
	// this->setAttackDamage( ST_DEFAULT_ATTACK );
	std::cout	<< MSG_SCAVTRAP << this->getName()
				<< MSG_CONSTRUCTOR << " [parameterized]" << std::endl;
	return ;
}

/******************************************************************************/
/**************************** CANONICAL REQUISITE *****************************/

ScavTrap &ScavTrap::operator=( const ScavTrap &rhs ) {
	this->setName( rhs.getName() );
	this->_hit_point = rhs.getHitPoint();
	this->_energy_point = rhs.getEnergyPoint();
	this->_attack_damage = rhs.getAttackDamage();
	// this->setHitPoint( rhs.getHitPoint() );
	// this->setEnergyPoint( rhs.getEnergyPoint() );
	// this->setAttackDamage( rhs.getAttackDamage() );
	return (*this);
}

ScavTrap::ScavTrap( const ScavTrap &src ) : ClapTrap() {
	*this = src;
	std::cout	<< MSG_SCAVTRAP << this->getName()
				<< MSG_CONSTRUCTOR << " [reference copy]" << std::endl;
	return ;
}

/******************************************************************************/
/********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ************************/

ScavTrap::ScavTrap( void ) : ClapTrap() {
	this->_hit_point = ST_DEFAULT_HIT;
	this->_energy_point = ST_DEFAULT_ENERGY;
	this->_attack_damage = ST_DEFAULT_ATTACK;
	// this->setHitPoint( ST_DEFAULT_HIT );
	// this->setEnergyPoint( ST_DEFAULT_ENERGY );
	// this->setAttackDamage( ST_DEFAULT_ATTACK );
	std::cout << "ScavTrap" << MSG_CONSTRUCTOR << " [default]" << std::endl;
	return ;
}

ScavTrap::~ScavTrap( void ) {
	std::cout	<< MSG_SCAVTRAP << this->getName()
				<< MSG_DESTRUCTOR << std::endl;
	return ;
}
