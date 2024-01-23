/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:47:29 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/23 18:17:47 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

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
