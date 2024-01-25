/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:40:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 21:17:45 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

std::string	Animal::getType( void ) const {
	return ( this->_type );
}

void	Animal::makeSound( void ) const {
	std::cout << "*Some kind of sound*" << std::endl;
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

Animal::Animal( std::string type ) : _type( type ) {
	std::cout	<< "Animal (" << this->_type
				<< ") Constructor called. [parameterized]" << std::endl;
	return ;
}

/******************************************************************************/
/************************** CANOCICAL FORM REQUISITES *************************/

Animal::Animal( const Animal &rhs ) {
	*this = rhs;
	std::cout	<< "Animal (" << this->getType()
				<< ") Constructor called. [reference copy]" << std::endl;
	return ;
}

Animal &Animal::operator=( const Animal &src ) {
	this->_type = src._type;
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

Animal::Animal( void ) {
	this->_type = "*Type not specified*";
	std::cout	<< "Animal (" << this->_type
				<< ") Constructor called [default]" << std::endl;
	return ;
}

Animal::~Animal() {
	std::cout	<< "Animal (" << this->getType() << ") Destructor called."
				<< std::endl;
	return ;
}
