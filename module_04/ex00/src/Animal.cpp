/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:40:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/23 18:17:51 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string	Animal::getType( void ) const {
	return ( this->_type );
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

Animal::Animal( std::string type ) : _type( type ) {
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
	this->_type = "";
	return ;
}

Animal::~Animal() {
	std::cout << "Animal (" << this->getType() << ") Destructor called." << std::endl;
}
