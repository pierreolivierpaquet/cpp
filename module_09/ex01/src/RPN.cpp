/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:39:50 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/12 14:54:04 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

static void	reverse_rpn( RPN &from, RPN &to ) {
	while (from.empty() == false) {
		to.push( from.top() );
		from.pop();
	}
	return ;
}

void	RPN::convert( void ) {
	RPN temp;
	std::istringstream	line;
	std::string	tmp;
	u_int32_t	add = 0;

	line.str( this->_input );
	while (line.eof() == false) {
		line >> tmp;
		if (tmp.length() != 1 ||
			tmp.find_first_not_of( static_cast< std::string >(DIGIT_CHAR) + ARITMETIC_CHAR ) != std::string::npos) {
			throw( std::runtime_error( ERR_MSG ) );
		} else if (tmp.find_first_of( ARITMETIC_CHAR ) != std::string::npos) {
			add = tmp.at( 0 );
		} else if ( tmp.find_first_not_of( DIGIT_CHAR ) == std::string::npos ) {
			add = to_digit( tmp.at( 0 ) );
		}
		temp.push( add );
	}
	reverse_rpn( temp, *this );
	return ;
}

void	RPN::calculate( void ) {
	this->convert();
	return ;
}

RPN::RPN( void ) {
	return ;
}

RPN::RPN( std::string input ) :
	_input( input ) {
	return ;
}

RPN::~RPN( void ) {
	return ;
}
