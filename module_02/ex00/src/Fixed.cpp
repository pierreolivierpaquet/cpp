/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:03:30 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/17 10:38:51 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::getRawBits_( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_value);
}

void	Fixed::setRawBits( int const raw ) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_value = raw;
	return ;
}

/******************************************************************************/

/// Fractionnal part bit initialization.
const int	Fixed::_nbits = 8;

/// @brief Default constructor.
Fixed::Fixed( void ) : _fixed_value( 0 ) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

/// @brief Copy constructor.
Fixed::Fixed( Fixed const &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

/// @brief Assignation operands / Update of current instance.
Fixed &Fixed::operator=( const Fixed &rhs ){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_value = rhs.getRawBits_();;
	return ( *this );
}

/// @brief Default destructor. 
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}
