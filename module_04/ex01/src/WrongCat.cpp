/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:19:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 14:03:50 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

std::string	WrongCat::getType( void ) const {
	return ( this->_type );
}

void	WrongCat::makeSound( void ) const {
	std::cout << "*Some WrongCat sound*" << std::endl;
}

/******************************************************************************/
/************************* CANONICAL FORM REQUISITES **************************/

WrongCat::WrongCat( const WrongCat &rhs ) : WrongAnimal() {
	*this = rhs;
	this->_type = "WrongCat";
	std::cout	<< "WrongCat (" << this->getType()
				<< ") Constructor called. [reference copy]" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=( const WrongCat &src ) {
	this->_type = src._type;
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

WrongCat::WrongCat() : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout	<< this->_type
				<< " Constructor called [default]" << std::endl;
	return ;
}

WrongCat::~WrongCat() {
	std::cout	<< "WrongCat (" << this->getType() << ") Destructor called."
				<< std::endl;
	return ;
}
