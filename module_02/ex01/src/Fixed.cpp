/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:35:17 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/17 14:04:39 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/// Fractionnal part bit initialization.
const int Fixed::_nbits = 8;

/// @brief Output stream overload.
std::ostream &operator<<( std::ostream &output, const Fixed &rhs){
	output << rhs.toFloat_();
	return ( output );
}

/******************************* GETTER+SETTER ********************************/

void	Fixed::setRawBits( const int raw){
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point = raw;
	return ;
}

int	Fixed::getRawBits_( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point);
}

float Fixed::toFloat_( void ) const {
	float	result;

	result = (float)this->_fixed_point / ( 1 << this->_nbits);
	return (result);
}

int Fixed::toInt_( void ) const {
	return ( this->_fixed_point >> this->_nbits );
}

/************************** CANONICAL FORM REQUISITE **************************/

/// @brief Constructor by reference copy. 
Fixed::Fixed( const Fixed &src ){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

/// @brief Assignation overload.
Fixed &Fixed::operator=( Fixed const &rhs ){
	this->_fixed_point = rhs.getRawBits_();
	std::cout << "Copy assignment operator called" << std::endl;
	return ( *this );
}

/*************************** PARAMETRIC CONSTRUCTOR ***************************/

/// @brief Parametric constructor (from constant integer value).
Fixed::Fixed( const int integer_number) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = integer_number << this->_nbits;
	return ;
}

/// @brief Parametric constructor (from constant float value).
Fixed::Fixed( const float float_number ) {
	float	result;
	
	std::cout << "Float constructor called" << std::endl;
	result = roundf(float_number * (1 << this->_nbits));
	this->_fixed_point = (int)result;
	return ;
}

/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

/// @brief Default constructor. 
Fixed::Fixed( void ) : _fixed_point( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

/// @brief Default destructor. 
Fixed::~Fixed ( void ) {
	std::cout << "Destructor called" << std::endl;
}
