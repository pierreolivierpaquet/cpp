/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastConversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:35:33 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/12 15:04:24 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/CastConversion.hpp"

typedef std::string::const_iterator const_iterator_t;

/********************************* FUNCTION.S *********************************/

void	Conversion::_setType( void ) {
	if (this->_conversion_type != C_UNDEFINED){
		return ;
	}
	// CHAR

	// DOUBLE

	// FLOAT (lenght > 1) && ()
	if (this->_program_input.length() > 1 && \
		this->getProgramInput().find_first_not_of(NUM_INCL)) {
		this->_conversion_type = C_FLOAT;
	}
	// INT
	return ;
}

/********************************** SETTER.S **********************************/



/********************************** GETTER.S **********************************/

Conversion::conv_type_t	Conversion::getConversionType( void ) const{
	return ( this->_conversion_type );
}

std::string	Conversion::getProgramInput( void ) const {
	return ( this->_program_input );
}

char Conversion::getChar( void ) const {
	return ( this->_char_cast );
}

double Conversion::getDouble( void ) const {
	return ( this->_double_cast );
}

float Conversion::getFloat( void ) const {
	return ( this->_float_cast );
}

int Conversion::getInt( void ) const {
	return ( this->_int_cast );
}

/************************** CANONICAL FORM REQUISITE **************************/

Conversion::Conversion( const Conversion &rhs ) :
	_program_input( rhs.getProgramInput()) {
	*this = rhs;
	return ;
}

Conversion &Conversion::operator=( const Conversion &rhs ) {
	this->_conversion_type	=	rhs.getConversionType();
	this->_int_cast			=	rhs.getInt();
	this->_float_cast		=	rhs.getFloat();
	this->_double_cast		=	rhs.getDouble();
	this->_char_cast		=	rhs.getChar();
	return ( *this );
}

/********************* DEFAULT CONSTRUCTOR && DESTRUCTOR **********************/

Conversion::Conversion( std::string program_input ) :
	_program_input( program_input ) {
	std::cout	<< this->_program_input
				<< " Constructor called [default/parameterized]" << std::endl;
	this->_setType();
	return ;
}

Conversion::~Conversion( void ) {
	std::cout	<< this->_program_input
				<< "Destructor called. [default]" << std::endl;
	return ;
}

