/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:47:29 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 13:50:10 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

std::string	Dog::getType( void ) const {
	return ( this->_type );
}

void	Dog::makeSound( void ) const {
	std::cout << "Wouf wouf." << std::endl;
	return ;
}

/******************************************************************************/
/************************* CANONICAL FORM REQUISITES **************************/

Dog::Dog( const Dog &src ) : Animal() {
	*this = src;
	std::cout	<< this->_type << " Constructor called. [reference copy]"
				<< std::endl;
	return ;
}

Dog	&Dog::operator=( const Dog &rhs ) {
	this->_type = rhs._type;
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

Dog::Dog( void ) : Animal() {
	this->_type = "Dog";
	std::cout << this->getType() << " Constructor called. [default]" << std::endl;
	return ;
}

Dog::~Dog( void ) {
	std::cout << this->_type << " Destructor called." << std::endl;
	return ;
}
