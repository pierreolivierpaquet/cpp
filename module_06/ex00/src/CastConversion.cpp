/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastConversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:35:33 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/14 15:08:28 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/CastConversion.hpp"

bool	Conversion::isError( std::string input ) const {
	if (input.empty() == true || \
		(input.find_first_of(".") != input.find_last_of(".")))
		return ( true );

//	Prevents flagging a single '-' or '+' as an error.
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
//	Catches "567.987d"
		input.find( "f" ) == NOT_FOUND || \
//	Catches "123f"
		input.find_first_of( POINT_CHAR ) == NOT_FOUND || \
//	Catches "-+.f"
		input.find_first_not_of( SIGN_CHARS ) == input.find(".f")) {
		return ( false );
//	Catches "123.45fd"
	} else if (	input.find_first_not_of( (static_cast<std::string>(FLOAT_CHAR)
				+ DIGIT_CHARS + POINT_CHAR + SIGN_CHARS) ) != NOT_FOUND) {
		return ( false );
//	Catches 123.45ff
	} else if ( input.find_first_of( FLOAT_CHAR ) != input.find_last_of( FLOAT_CHAR )) {
		return ( false );
	}
//	Catches "-0.43+f"
	if ( input.find( 'f' ) - 1 == input.find_last_of( SIGN_CHARS ) ) {
		return ( false );
	}
	return ( true );
}

/********************************* FUNCTION.S *********************************/

void	Conversion::_convertFromChar( void ) {
	this->_int_cast		= static_cast<int>(		this->_char_cast );
	this->_double_cast	= static_cast<double>(	this->_char_cast );
	this->_float_cast	= static_cast<float>(	this->_char_cast );
	return ;
}

void	Conversion::_convertFromInt( void ) {
	this->_char_cast	= static_cast<char>(	this->_int_cast );
	this->_double_cast	= static_cast<double>(	this->_int_cast );
	this->_float_cast	= static_cast<float>(	this->_int_cast );
	return ;
}

void	Conversion::_convertFromDouble( void ) {
	this->_char_cast	= static_cast<char>(	this->_double_cast );
	this->_int_cast		= static_cast<int>(		this->_double_cast );
	this->_float_cast	= static_cast<float>(	this->_double_cast );
	return ;
}

void	Conversion::_convertFromFloat( void ) {
	this->_char_cast	= static_cast<char>(	this->_float_cast );
	this->_int_cast		= static_cast<int>(		this->_float_cast );
	this->_double_cast	= static_cast<double>(	this->_float_cast );
	return ;
}

void	Conversion::_convert( void ) {
	for (int i = 0; i < C_UNDEFINED; i++){
		if ((this->*_type_id[ i ])( this->_program_input ) == true) {
			this->_conversion_type = static_cast<conv_type_t>( i );
			break;
		}
	}
	if (this->_conversion_type == C_UNDEFINED) {
		return ;
	}
	for (int i = C_CHAR; i < C_UNDEFINED; i++) {
		if (this->_conversion_type == static_cast<conv_type_t>( i )){
			( this->*_origin_type[	i % C_CHAR ] )();
			( this->*_from_type[ 	i % C_CHAR ] )();
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
	this->_float_cast = atof( this->_program_input.c_str() );
}

/********************************** GETTER.S **********************************/

Conversion::conv_type_t	Conversion::getConversionType( void ) const {
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

/// @brief	Constructor mapping util ( typeIdentifier array )
void	Conversion::_mapping_type_id( void ) {
	this->_type_id[ C_ERROR	] = &Conversion::isError;
	this->_type_id[ C_NAN	] = &Conversion::isNan;
	this->_type_id[ C_NANF	] = &Conversion::isNanf;
	this->_type_id[ C_INF	] = &Conversion::isInf;
	this->_type_id[ C_MINF	] = &Conversion::isMinf;
	this->_type_id[ C_INFF	] = &Conversion::isInff;
	this->_type_id[ C_MINFF	] = &Conversion::isMinff;
	this->_type_id[ C_CHAR	] = &Conversion::isChar;
	this->_type_id[ C_INT	] = &Conversion::isInt;
	this->_type_id[ C_DOUBLE] = &Conversion::isDouble;
	this->_type_id[ C_FLOAT	] = &Conversion::isFloat;
	return ;
}

/// @brief	Constructor mapping util ( setOriginType array )
void	Conversion::_mapping_origin_type( void ) {
	this->_origin_type[ 0 ] = &Conversion::_setChar;
	this->_origin_type[ 1 ] = &Conversion::_setInt;
	this->_origin_type[ 2 ] = &Conversion::_setDouble;
	this->_origin_type[ 3 ] = &Conversion::_setFloat;
	return ;
}

/// @brief	Constructor mapping util ( convertFromType array )
void	Conversion::_mapping_from_type( void ) {
	this->_from_type[ 0 ] = &Conversion::_convertFromChar;
	this->_from_type[ 1 ] = &Conversion::_convertFromInt;
	this->_from_type[ 2 ] = &Conversion::_convertFromDouble;
	this->_from_type[ 3 ] = &Conversion::_convertFromFloat;
	return ;
}

Conversion::Conversion( std::string program_input ) :
	_program_input( program_input ),
	_conversion_type( C_UNDEFINED ),
	_char_cast( 0 ),
	_int_cast( 0 ),
	_double_cast( 0 ),
	_float_cast( 0 ) {
	std::cout	<< this->_program_input
				<< " Constructor called [default/parameterized]" << std::endl;

//	Mapping of all function pointers arrays.
	this->_mapping_type_id();
	this->_mapping_origin_type();
	this->_mapping_from_type();

//	Main conversion method.
	this->_convert();
	return ;
}

Conversion::~Conversion( void ) {
	std::cout	<< this->_program_input
				<< " Destructor called. [default]" << std::endl;
	return ;
}
