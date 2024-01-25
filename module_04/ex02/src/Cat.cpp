/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:47:34 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 21:34:27 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

std::string	Cat::getType( void ) const {
	return ( this->_type );
}

void	Cat::makeSound( void ) const {
	std::cout << "Meow meow." << std::endl;
	return ;
}

void	Cat::setIdeas( const std::string idea ) {
	this->_brain->setIdeas( idea );
	return ;
}

void	Cat::setIdeas( const std::string idea, const size_t index ) {
	this->_brain->setIdeas( idea, index );
	return ;
}

const std::string Cat::getIdeas( const size_t index ) const {
	return ( this->_brain->getIdeas( index ) );
}

size_t	Cat::getiBrain( void ) const {
	return ( this->_brain->getiBrain() );
}

/******************************************************************************/
/************************* CANONICAL FORM REQUISITES **************************/

Cat::Cat( const Cat &src ) : Animal(), _brain( NULL ) {
	this->_brain = new Brain;
	*this = src;
	std::cout	<< this->_type << " Constructor called. [reference copy]"
				<< std::endl;
	return ;
}

Cat	&Cat::operator=( const Cat &rhs ) {
	this->_type = rhs._type;
	*this->_brain = *rhs._brain; // Deep copy; assignation overload of Brain.
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

Cat::Cat( void ) : Animal(), _brain( NULL ) {
	this->_type = "Cat";
	this->_brain = new Brain;
	std::cout	<< this->_type << " Constructor called. [default]" << std::endl;
	return ;
}

Cat::~Cat( void ) {
	if (this->_brain != NULL){
		delete this->_brain;
	}
	std::cout << this->_type << " Destructor called." << std::endl;
	return ;
}
