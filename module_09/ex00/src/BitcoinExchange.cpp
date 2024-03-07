/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:49:35 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/07 10:58:43 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/BitcoinExchange.hpp"

///	---------------------------------------------------------- @section GETTER.S

std::string	BitcoinExchange::getInfileName( void ) const {
	return ( this->_infile_name );
}

/// -------------------------------------- @section CONSTRUCTOR.S - DESTRUCTOR.S

BitcoinExchange::BitcoinExchange( void ) :
	_infile_name( EMPTY_STR ) {
	std::cout	<< this->_infile_name
				<< " Constructor called. [default]" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &rhs ) {
	*this = rhs;
	return ;
}

BitcoinExchange::~BitcoinExchange( void ) {
	if (this->_infile.is_open()){
		this->_infile.close();
	}
	this->_infile_name = EMPTY_STR;
	return ;
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &rhs ) {
	if (this == &rhs){
		return ( *this );
	} else {
		this->_infile_name = rhs.getInfileName();
	}
	return ( *this );
}