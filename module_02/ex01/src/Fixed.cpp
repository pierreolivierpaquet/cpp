/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:35:17 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/15 16:21:40 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbits = 8;

void	Fixed::setRawBits( const int raw){
	this->_fixed_value = raw;
	return ;
}

int	Fixed::getRawBits_( void ) const {
	return (this->_fixed_value);
}

float Fixed::toFloat_( void ) const {
	float	result;

	result = (float)this->_fixed_value / ( 1 << this->_nbits);
	return (result);
}

int Fixed::toInt_( void ) const {
	return (this->_fixed_value >> this->_nbits);
}

/******************************************************************************/

/// @brief Copy constructor by reference. 
Fixed::Fixed( const Fixed &src ){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed &Fixed::operator=( Fixed const &rhs ){
	this->_fixed_value = rhs.getRawBits_();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::Fixed( const int integer_number) {
	this->_fixed_value = integer_number << this->_nbits;
	return ;
}

Fixed::Fixed( const float float_number ) {
	float	result;
	
	result = roundf(float_number * (1 << this->_nbits));
	this->_fixed_value = (int)result;
	return ;
}

std::ostream &operator<<( std::ostream &output, const Fixed &rhs){
	output << rhs.toFloat_();
	return (output);
}

/// @brief Default constructor. 
Fixed::Fixed( void ) : _fixed_value( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

/// @brief Default destructor. 
Fixed::~Fixed ( void ) {
	std::cout << "Destructor called" << std::endl;
}

