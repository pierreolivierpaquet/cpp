/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:35:17 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/17 12:47:08 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

/// Fractionnal part bit initialization.
const int Fixed::_nbits = 8;

/// @brief Output stream overload.
std::ostream &operator<<( std::ostream &output, const Fixed &rhs){
	output << rhs.toFloat_();
	return (output);
}

/******************************* SETTER+GETTER ********************************/

void	Fixed::setRawBits( const int raw){
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_value = raw;
	return ;
}

int	Fixed::getRawBits_( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
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

/************************** CANONICAL FORM REQUISITE **************************/


/// @brief Constructor by reference copy. 
Fixed::Fixed( const Fixed &src ){
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

/// @brief Assignation overload.
Fixed &Fixed::operator=( Fixed const &rhs ){
	this->_fixed_value = rhs.getRawBits_();
	// std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

/*************************** PARAMETRIC CONSTRUCTOR ***************************/

/// @brief Parametric constructor (from constant integer value).
Fixed::Fixed( const int integer_number) {
	// std::cout << "Int constructor called" << std::endl;
	this->_fixed_value = integer_number << this->_nbits;
	return ;
}

/// @brief Parametric constructor (from constant float value).
Fixed::Fixed( const float float_number ) {
	float	result;
	
	// std::cout << "Float constructor called" << std::endl;
	result = roundf(float_number * (1 << this->_nbits));
	this->_fixed_value = (int)result;
	return ;
}

/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

/// @brief Default constructor. 
Fixed::Fixed( void ) : _fixed_value( 0 ) {
	// std::cout << "Default constructor called" << std::endl;
}

/// @brief Default destructor. 
Fixed::~Fixed ( void ) {
	// std::cout << "Destructor called" << std::endl;
}

/********************************* COMPARISON *********************************/

bool	Fixed::operator>( const Fixed &rhs ) const {
	return ( this->_fixed_value > rhs.getRawBits_() );
}

bool	Fixed::operator>=( const Fixed &rhs ) const {
	return (this->_fixed_value >= rhs.getRawBits_());
}

bool	Fixed::operator<( const Fixed &rhs ) const {
	return ( this->_fixed_value < rhs.getRawBits_() );
}

bool	Fixed::operator<=( const Fixed &rhs ) const {
	return ( this->_fixed_value <= rhs.getRawBits_() );
}

bool	Fixed::operator==( const Fixed &rhs ) const {
	return ( this->_fixed_value == rhs.getRawBits_() );
}

bool	Fixed::operator!=( const Fixed &rhs ) const {
	return ( this->_fixed_value != rhs.getRawBits_() );
}

/*********************** INCREMENTATION+DECREMENTATION ************************/

/// @return Reference to the currect modified instance, used in more complex
///			expressions. Example: <class> <Name> = ++b;
/// Pre-incrementation.
Fixed	&Fixed::operator++( void ) {
	this->_fixed_value++;
	return ( *this );
}

/// Pre-decrementation.
Fixed	&Fixed::operator--( void ) {
	this->_fixed_value--;
	return ( *this );
}

/// @brief Post-incrementation.
Fixed	Fixed::operator++( int ) {
	Fixed	pre_incrementation_state = *this;	

	this->_fixed_value++;
	return ( pre_incrementation_state );
}

/// @brief Post-decrementation.
Fixed	Fixed::operator--( int ) {
	Fixed	pre_decrementation_state = *this;	

	this->_fixed_value--;
	return ( pre_decrementation_state );
}

/********************************** MIN/MAX ***********************************/

const Fixed	&Fixed::min_( const Fixed &first, const Fixed &second ) {
	const Fixed &result = ( first < second ) ? first : second;
	return ( result );
}

const Fixed	&Fixed::max_( const Fixed &first, const Fixed &second ) {
	const Fixed &result = ( first > second ) ? first : second;
	return ( result );
}

Fixed	&Fixed::min_( Fixed &first, Fixed &second ) {
	Fixed &result = ( first < second ) ? first : second;
	return ( result );
}

Fixed	&Fixed::max_( Fixed &first, Fixed &second ) {
	Fixed &result = ( first > second ) ? first : second;
	return ( result );
}

/********************************* ARITHMETIC *********************************/

Fixed Fixed::operator*( const Fixed &rhs ) const {
	Fixed	result;
	int		multiplied;

	multiplied = (this->_fixed_value * rhs.getRawBits_()) >> this->_nbits;
	result.setRawBits( multiplied );
	return ( result );
}

Fixed Fixed::operator/( const Fixed &rhs ) const {
	Fixed	result;
	int		divided;

	divided = (this->_fixed_value)/ (rhs.getRawBits_()) << Fixed::_nbits;
	result.setRawBits( divided );
	return ( result );
}

Fixed Fixed::operator+( const Fixed &rhs ) const {
	Fixed	result;
	int		added;

	added = this->_fixed_value + rhs.getRawBits_();
	result.setRawBits( added );
	return ( result );
}

Fixed Fixed::operator-( const Fixed &rhs ) const {
	Fixed	result;
	int		subtracted;

	subtracted = this->_fixed_value - rhs.getRawBits_();
	result.setRawBits( subtracted );
	return ( result );
}
