/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:47:34 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/23 18:17:43 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void	Cat::makeSound( void ) const {
	std::cout << "Meow meow." << std::endl;
	return ;
}

/******************************************************************************/
/************************* CANONICAL FORM REQUISITES **************************/

Cat::Cat( const Cat &src ) : Animal() {
	*this = src;
	this->_type = "Cat";
	std::cout	<< this->_type << " Constructor called. [reference copy]"
				<< std::endl;
	return ;
}

Cat	&Cat::operator=( const Cat &rhs ) {
	this->_type = rhs._type;
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

Cat::Cat( void ) : Animal() {
	this->_type = "Cat";
	std::cout	<< this->_type << " Constructor called. [default]" << std::endl;
	return ;
}

Cat::~Cat( void ) {
	std::cout << this->_type << " Destructor called." << std::endl;
}
