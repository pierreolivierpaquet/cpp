/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:37:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/22 10:19:20 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	FragTrap::attack( const std::string& target ) {
	if (this->getHitPoint() <= 0){
		std::cout	<< MSG_FRAGTRAP << this->getName()
					<< " can't attack: It's dead." << std::endl;
	} else if (this->getEnergyPoint() <= 0) {
		std::cout	<< MSG_FRAGTRAP << this->getName()
					<< " can't attack: No energy left." << std::endl;
	} else {
		std::cout	<< MSG_FRAGTRAP << this->getName()
					<< MSG_ATTACKS << target << MSG_CAUSING
					<< this->getAttackDamage() << MSG_DAMAGE << std::endl;
		this->subEnergyPoint( COST_ATTACK );
	}
	return ;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout	<< MSG_FRAGTRAP << this->getName()
				<< " is shouting: CAN I GET AN HIGH FIIIIIIVES!" << std::endl;
	return ;
}

/******************************************************************************/
/************************** CANONICAL FORM REQUISITE **************************/

FragTrap	&FragTrap::operator=( const FragTrap &rhs ) {
	this->setName( rhs.getName() );
	this->_hit_point = rhs.getHitPoint();
	this->_energy_point = rhs.getEnergyPoint();
	this->_attack_damage = rhs.getAttackDamage();
	return (*this);
}

FragTrap::FragTrap( const FragTrap &src ) : ClapTrap() {
	*this = src;
	std::cout	<< MSG_FRAGTRAP << this->getName()
				<< MSG_CONSTRUCTOR << " [reference copy]" << std::endl;
	return ;
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

FragTrap::FragTrap( std::string name ) : ClapTrap( name ){
	this->_hit_point = FT_DEFAULT_HIT;
	this->_energy_point = FT_DEFAULT_ENERGY;
	this->_attack_damage = FT_DEFAULT_ATTACK;
	std::cout	<< MSG_FRAGTRAP << this->getName()
				<< MSG_CONSTRUCTOR << " [parameterized]" << std::endl;
	return ;
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

FragTrap::FragTrap( void ) : ClapTrap() {
	this->_hit_point = FT_DEFAULT_HIT;
	this->_energy_point = FT_DEFAULT_ENERGY;
	this->_attack_damage = FT_DEFAULT_ATTACK;
	std::cout << "FragTrap" << MSG_CONSTRUCTOR << " [default]" << std::endl;
	return ;
}

FragTrap::~FragTrap( void ) {
	std::cout	<< MSG_FRAGTRAP << this->getName()
				<< MSG_DESTRUCTOR << std::endl;
}