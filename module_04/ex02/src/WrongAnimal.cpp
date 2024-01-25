/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:18:56 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 12:06:15 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

std::string	WrongAnimal::getType( void ) const {
	return ( this->_type );
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "*Some random WrongAnimal sound*" << std::endl;
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

WrongAnimal::WrongAnimal( std::string type ) : _type( type ) {
	std::cout	<< "WrongAnimal (" << this->_type
				<< ") Constructor called. [parameterized]" << std::endl;
	return ;
}

/******************************************************************************/
/************************* CANONICAL FORM REQUISITES **************************/

WrongAnimal::WrongAnimal( const WrongAnimal &rhs ) {
	*this = rhs;
	std::cout	<< "WrongAnimal (" << this->getType()
				<< ") Constructor called. [reference copy]" << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &src ) {
	this->_type = src._type;
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

WrongAnimal::WrongAnimal() {
	this->_type = "*Type not specified*";
	std::cout	<< "WrongAnimal (" << this->_type
				<< ") Constructor called [default]" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(){
	std::cout	<< "WrongAnimal (" << this->getType() << ") Destructor called."
				<< std::endl;
	return ;
}
