/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:39:50 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/13 09:36:15 by ppaquet          ###   ########.fr       */
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

void RPN::multiplication( RPN &tmp_stack ) {
	long double tmp = 0;
	if (tmp_stack.size() > 1) {
		tmp = tmp_stack.top();
		tmp_stack.pop();
		tmp *= tmp_stack.top();
		tmp_stack.pop();
		tmp_stack.push( tmp );
	}
	return ;
}

void RPN::division( RPN &tmp_stack ) {
	long double tmp = 0;
	if (tmp_stack.size() > 1) {
		tmp = tmp_stack.top();
		tmp_stack.pop();
		tmp /= tmp_stack.top();
		tmp_stack.pop();
		tmp_stack.push( tmp );
	}
	return ;
}

void RPN::substraction( RPN &tmp_stack ) {
	long double tmp = 0;
	if (tmp_stack.size() > 1) {
		tmp = tmp_stack.top();
		tmp_stack.pop();
		tmp = tmp_stack.top() - tmp;
		tmp_stack.pop();
		tmp_stack.push( tmp );
	}
	return ;
}

void RPN::addition( RPN &tmp_stack ) {
	long double tmp = 0;
	if (tmp_stack.size() > 1) {
		tmp = tmp_stack.top();
		tmp_stack.pop();
		tmp += tmp_stack.top();
		tmp_stack.pop();
		tmp_stack.push( tmp );
	}
	return ;
}

void	RPN::process_aritmetic( e_aritmetic type, RPN &tmp_stack ) {
	switch(type) {
		case( ADD ): this->addition( tmp_stack );
			break ;
		case( SUBSTRACT ): this->substraction( tmp_stack );
			break ;
		case( MULTIPLY ): this->multiplication( tmp_stack );
			break ;
		case( DIVIDE ): this->division( tmp_stack );
			break ;
		default:
			break ;
	}
	return ;
}

static e_aritmetic	is_aritmetic( u_int32_t	n ) {
	if (n == MULTIPLY	|| n == DIVIDE ||
		n == ADD		|| n == SUBSTRACT ) {
		return ( static_cast< e_aritmetic >( n ) );
	}
	return ( NOT_ARITMETIC );
}

void	RPN::calculate( void ) {
	RPN tmp_stack;
	this->convert();
	while (this->empty() == false) {
		if (is_aritmetic(this->top()) == NOT_ARITMETIC) {
			tmp_stack.push( this->top() );
			this->pop();
		} else {
			process_aritmetic( static_cast< e_aritmetic >(this->top()), tmp_stack );
			this->pop();
		}
	}
	this->_result = tmp_stack.top();
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
