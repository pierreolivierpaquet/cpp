/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:47:29 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 18:24:05 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

std::string	Dog::getType( void ) const {
	return ( this->_type );
}

void	Dog::makeSound( void ) const {
	std::cout << "Wouf wouf." << std::endl;
	return ;
}

void	Dog::setIdeas( const std::string idea ) {
	this->_brain->setIdeas( idea );
	return ;
}

void	Dog::setIdeas( const std::string idea, const size_t index ) {
	this->_brain->setIdeas( idea, index );
	return ;
}

const std::string Dog::getIdeas( const size_t index ) const {
	return ( this->_brain->getIdeas( index ) );
}

/******************************************************************************/
/************************* CANONICAL FORM REQUISITES **************************/

Dog::Dog( const Dog &src ) : Animal(), _brain( NULL ) {
	this->_brain = new Brain;
	*this = src;
	std::cout	<< this->_type << " Constructor called. [reference copy]"
				<< std::endl;
	return ;
}

Dog	&Dog::operator=( const Dog &rhs ) {
	this->_type = rhs._type;
	*this->_brain = *rhs._brain; // Deep copy; assignation overload of Brain.
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

Dog::Dog( void ) : Animal(), _brain( NULL ) {
	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout << this->getType() << " Constructor called. [default]" << std::endl;
	return ;
}

Dog::~Dog( void ) {
	if (this->_brain != NULL){
		delete this->_brain;
	}
	std::cout << this->_type << " Destructor called." << std::endl;
	return ;
}
