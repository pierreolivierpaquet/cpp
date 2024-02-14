/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastConversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:35:33 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/14 11:00:22 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/CastConversion.hpp"

// static std::size_t	skipSigns( std::string input ) {
// 	std::size_t	index = 0;
// 	for (std::string::iterator it = input.begin(); it != input.end(); it++) {
// 		if (*it != '+' && *it != '-'){
// 			return ( index );
// 		}
// 		index++;
// 	}
// 	return ( index );
// }

// typedef std::string::const_iterator const_iterator_t;

bool	Conversion::isError( std::string input ) const {
	if (input.empty() == true || \
		(input.find_first_of(".") != input.find_last_of(".")))
		return ( true );
	if (input.length() > 1 && \
		input.find_last_of( SIGN_CHARS ) == (input.length() - 1)){
		return( true );
	}
	return ( false );
}

bool	Conversion::isNan( std::string input ) const {
	if (input.compare("nan") == 0){
		return ( true );
	}
	return ( false );
}

bool	Conversion::isNanf( std::string input ) const {
	if (input.compare("nanf") != 0){
		return ( false );
	}
	return ( true );
}

bool	Conversion::isInf( std::string input ) const {
	if (input.compare("+inf") != 0){
		return ( false );
	}
	return ( true );
}

bool	Conversion::isInff( std::string input ) const {
	if (input.compare("+inff") != 0){
		return ( false );
	}
	return ( true );
}

bool	Conversion::isMinf( std::string input ) const {
	if (input.compare("-inf") != 0){
		return ( false );
	}
	return ( true );
}

bool	Conversion::isMinff( std::string input ) const {
	if (input.compare("-inff") != 0){
		return ( false );
	}
	return ( true );
}

bool	Conversion::isChar( std::string input ) const {
	if (input.length() > 1) {
		return ( false );
	} else if (input.find_first_of( DIGIT_CHARS ) != NOT_FOUND) {
		return ( false );
	}
	return ( true );
}

bool	Conversion::isInt( std::string input ) const {
	if (input.find_first_not_of( static_cast<std::string>(SIGN_CHARS) + DIGIT_CHARS ) == NOT_FOUND) {
		return ( true );
	}
	return ( false );
}

bool	Conversion::isDouble( std::string input ) const {
	if (input.length() < 2)
		return ( false );
	if (input.find_first_not_of( (static_cast<std::string>(DIGIT_CHARS)
				+ POINT_CHAR + SIGN_CHARS) ) != NOT_FOUND)
		return ( false );
	return ( true );
}

bool	Conversion::isFloat( std::string input ) const {
	if (input.length() < 2 || \
		input.find("f") == NOT_FOUND || \
		input.find_first_not_of( SIGN_CHARS ) == input.find(".f")) {
		return ( false );
	} else if (	input.find_first_not_of( (static_cast<std::string>(FLOAT_CHAR)
				+ DIGIT_CHARS + POINT_CHAR + SIGN_CHARS) ) != NOT_FOUND) {
		return ( false );
	} else if ( input.find_first_of( FLOAT_CHAR ) != input.find_last_of( FLOAT_CHAR )) {
		return ( false );
	}
	if ( input.find( 'f' ) - 1 == input.find_last_of( SIGN_CHARS ) ) {
		return ( false );
	}
	return ( true );
}

/********************************* FUNCTION.S *********************************/

void	Conversion::_setType( void ) {
	for (int i = 0; i < C_UNDEFINED; i++){
		if ((this->*_type_id[ i ])( this->_program_input ) == true) {
			this->_conversion_type = static_cast<conv_type_t>( i );
			break;
		}
	}
	void (Conversion::*TEST[ 4 ])(void) = {
		&Conversion::_setChar,
		&Conversion::_setInt,
		&Conversion::_setDouble,
		&Conversion::_setFloat };
	for (int i = C_CHAR; i < C_UNDEFINED; i++){
		if (this->_conversion_type == static_cast<conv_type_t>( i )){
			(this->*TEST[i % C_CHAR])();
			break ;
		}
	}
	return ;
}

/********************************** SETTER.S **********************************/

void	Conversion::_setChar( void ) {
	char	temp_char = 0;
	temp_char = this->_program_input.at( 0 );
	this->_char_cast = temp_char;
}

void	Conversion::_setInt( void ) {
	std::istringstream temp_int( this->_program_input );
	int converted = 0;
	temp_int	>> converted;
	this->_int_cast = converted;
}

void	Conversion::_setDouble( void ) {
	std::istringstream	temp_double( this->_program_input );
	double	converted = 0;
	temp_double	>> converted;
	this->_double_cast = converted;
}

void	Conversion::_setFloat( void ) {
	this->_float_cast = atof( this->_program_input.c_str() ); // test
}

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
	_program_input( program_input ),
	_conversion_type( C_UNDEFINED ),
	_char_cast( 0 ), _int_cast( 0 ), _double_cast( 0 ), _float_cast( 0 ) {
	std::cout	<< this->_program_input
				<< " Constructor called [default/parameterized]" << std::endl;
	_type_id[ C_ERROR	] = &Conversion::isError;
	_type_id[ C_NAN		] = &Conversion::isNan;
	_type_id[ C_NANF	] = &Conversion::isNanf;
	_type_id[ C_INF		] = &Conversion::isInf;
	_type_id[ C_MINF	] = &Conversion::isMinf;
	_type_id[ C_INFF	] = &Conversion::isInff;
	_type_id[ C_MINFF	] = &Conversion::isMinff;
	_type_id[ C_CHAR	] = &Conversion::isChar;
	_type_id[ C_INT		] = &Conversion::isInt;
	_type_id[ C_DOUBLE	] = &Conversion::isDouble;
	_type_id[ C_FLOAT	] = &Conversion::isFloat;
	
	this->_setType();
	return ;
}

Conversion::~Conversion( void ) {
	std::cout	<< this->_program_input
				<< "Destructor called. [default]" << std::endl;
	return ;
}
