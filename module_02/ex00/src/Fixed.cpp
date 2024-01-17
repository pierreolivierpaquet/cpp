/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:03:30 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/17 14:04:55 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/// Fractionnal part bit initialization.
const int	Fixed::_nbits = 8;

int	Fixed::getRawBits_( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return ( this->_fixed_point );
}

void	Fixed::setRawBits( int const raw ) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point = raw;
	return ;
}

/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

/// @brief Default constructor.
Fixed::Fixed( void ) : _fixed_point( 0 ) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

/// @brief Default destructor. 
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

/************************** CANONICAL FORM REQUISITE **************************/

/// @brief Copy constructor.
Fixed::Fixed( Fixed const &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

/// @brief Assignation operands / Update of current instance.
Fixed &Fixed::operator=( const Fixed &rhs ){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = rhs.getRawBits_();;
	return ( *this );
}
