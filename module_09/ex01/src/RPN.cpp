/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:39:50 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/19 09:16:03 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

///	------------------------------------------------------------ @section UTIL.S

static void	reverse_rpn( RPN &from, RPN &to ) {
	while (from.empty() == false) {
		to.push( from.top() );
		from.pop();
	}
	return ;
}

static e_arithmetic	is_aritmetic( u_int32_t	n ) {
	if (n == MULTIPLY	|| n == DIVIDE ||
		n == ADD		|| n == SUBSTRACT ) {
		return ( static_cast< e_arithmetic >( n ) );
	}
	return ( NOT_ARITMETIC );
}

///	-------------------------------------------------------- @section FUNCTION.S

void	RPN::convert( void ) {
	RPN temp;
	std::istringstream	line;
	std::string	tmp;
	u_int32_t	add = 0;

	line.str( this->_input );
	while (line.eof() == false) {
		line >> tmp;

		if ( tmp.empty() == true ) {
			break ;
		} else if (tmp.length() != 1 ||
			tmp.find_first_not_of(	static_cast< std::string >(DIGIT_CHAR) +
									ARITMETIC_CHAR ) != std::string::npos) {
			throw( std::runtime_error(	static_cast< std::string >( ERR_MSG ) +
										": invalid token, or character.") );
		} else if (tmp.find_first_of( ARITMETIC_CHAR ) != std::string::npos) {
			add = tmp.at( 0 );
		} else if ( tmp.find_first_not_of( DIGIT_CHAR ) == std::string::npos ) {
			add = to_digit( tmp.at( 0 ) );
		}
		tmp.clear();
		temp.push( add );
	}
	reverse_rpn( temp, *this );
	return ;
}

void	RPN::process_arithmetic( e_arithmetic type, RPN &tmp_stack ) {
	switch(type) {
		case( ADD ):
			this->arithmetic_operation( tmp_stack, std::plus< l_dbl_t >());
			break ;
		case( SUBSTRACT ):
			this->arithmetic_operation( tmp_stack, std::minus< l_dbl_t >());
			break ;
		case( MULTIPLY ):
			this->arithmetic_operation( tmp_stack, std::multiplies< l_dbl_t >());
			break ;
		case( DIVIDE ):
			this->arithmetic_operation( tmp_stack, std::divides< l_dbl_t >());
			break ;
		default:
			break ;
	}
	return ;
}

template< typename OP >
void RPN::arithmetic_operation( RPN &tmp_stack, OP operation ) {
    l_dbl_t tmp = 0;
    if (tmp_stack.size() > 1) {
        tmp = tmp_stack.top();
        tmp_stack.pop();
        tmp = operation( tmp_stack.top(), tmp );
        tmp_stack.pop();
        tmp_stack.push( tmp );
    } else {
		throw( std::runtime_error(	static_cast< std::string >(ERR_MSG) +
									": check synthax." ) );
	}
	return ;
}

void	RPN::calculate( void ) {
	RPN tmp_stack;
	this->convert();
	while (this->empty() == false) {
		if (is_aritmetic(this->top()) == NOT_ARITMETIC) {
			tmp_stack.push( this->top() );
			this->pop();
		} else {
			if (this->top() == DIVIDE && tmp_stack.top() == 0){
				throw( std::runtime_error(	static_cast< std::string >(ERR_MSG) +
											": division by 0 is prohibited." ) );
			}
			process_arithmetic( static_cast< e_arithmetic >(this->top()), tmp_stack );
			this->pop();
		}
	}
	if (tmp_stack.size() > 1) {
		throw( std::runtime_error(	static_cast< std::string >(ERR_MSG) +
									": missing operator suspected." ) );
	}
	this->_result = tmp_stack.top();
	return ;
}


void	RPN::displayResult( void ) const {
	std::cout	<< this->_result << std::endl;
	return ;
}

///	----------------------------------------------- @section SETTER.S - GETTER.S

void	RPN::setInput( std::string input ) {
	this->_result = std::numeric_limits< l_dbl_t >::quiet_NaN();
	this->_input = input;
	return ;
}

std::string	RPN::getInput( void ) const {
	return ( this->_input );
}

l_dbl_t	RPN::getResult() const {
	return ( this->_result );
}


///	----------------------------------------------- @section OPERATOR.S OVERLOAD

RPN	&RPN::operator=( const RPN &rhs ) {
	this->_input = rhs.getInput();
	this->_result = rhs.getResult();
	return ( *this );
}

///	-------------------------------------- @section CONSTRUCTOR.S - DESTRUCTOR.S

RPN::RPN( void ) {
	return ;
}

RPN::RPN( std::string input ) :
	_result( std::numeric_limits< l_dbl_t >::quiet_NaN() ),
	_input( input ) {
	return ;
}

RPN::RPN( const RPN &rhs ) {
	if (this == &rhs) {
		return ;
	}
	*this = rhs;
	return ;
}

RPN::~RPN( void ) {
	return ;
}
