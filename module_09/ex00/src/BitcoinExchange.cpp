/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:49:35 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/08 12:52:02 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/BitcoinExchange.hpp"

const std::string BitcoinExchange::_csv_name = CSV_FILENAME;

static void	convert_map( ifMap &infile_map ) {
	std::istringstream buffer( EMPTY_STR );
	std::string	tmp;
	for (size_t i = 0; i < infile_map.size() ; i++) {
		buffer.str( infile_map[ i ].origin_data.first) ; // sets the stream

		std::getline( buffer, tmp, '-');
		infile_map[ i ].year = static_cast<u_int32_t>(std::atoi( tmp.c_str() ));
		std::getline( buffer, tmp, '-' );
		infile_map[ i ].month = static_cast<u_int32_t>(std::atoi( tmp.c_str() ));
		std::getline( buffer, tmp, '-' );
		infile_map[ i ].day = static_cast<u_int32_t>(std::atoi( tmp.c_str() ));
		buffer.clear();
		buffer.str( infile_map[ i ].origin_data.second );
		std::getline( buffer, tmp );
		infile_map[ i ].value = std::strtof( tmp.c_str(), NULL);
		buffer.clear();
	}
	return ;
}

static void	upload_file( std::ifstream &infile, ifMap &infile_map, char delimiter ) {
	std::string line( EMPTY_STR );
	tokenPair key_val;
	t_data tmp;
	size_t	n = 0;
	while ( true ) {
		std::getline( infile, line );
		if (line.find(delimiter) != std::string::npos)
		{
			key_val.first = line.substr( 0, line.find_first_of(delimiter) );
			key_val.second = line.substr( line.find_first_of(delimiter) + 1);
		} else {
			key_val.first = line;
			key_val.second = EMPTY_STR;
		}
		tmp.origin_data = key_val;
		tmp.day = 0;
		tmp.month = 0;
		tmp.year = 0;
		tmp.value = 0;
		infile_map.insert( ifPair( n++, tmp ) );
		line.clear();
		if (infile.eof() == true) {
			break;
		}
	}
	return ;
}

///	-------------------------------------------------------- @section FUNCTION.S


void	BitcoinExchange::display( void ) {
	upload_file( this->_infile, this->_infile_map, INPUT_DELIMITER[ 0 ]);
	convert_map( this->_infile_map );
	upload_file( this->_csv, this->_csv_map, CSV_DELIMITER[ 0 ] );
	convert_map( this->_csv_map );
	return ;
}

///	---------------------------------------------------------- @section GETTER.S

std::string	BitcoinExchange::getInfileName( void ) const {
	return ( this->_infile_name );
}

///	---------------------------------------------------------- @section SETTER.S

void	BitcoinExchange::setInfileName( std::string name ) {
	this->_infile_name = name;
	return ;
}

/// -------------------------------------- @section CONSTRUCTOR.S - DESTRUCTOR.S

BitcoinExchange::BitcoinExchange( void ) :
	_infile_name( EMPTY_STR ) {
	std::cout	<< this->_infile_name
				<< " Constructor called. [default]" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange( std::string f_name ) :
	_infile_name( f_name ) {

	this->_infile.open( this->_infile_name.c_str() );
	this->_csv.open( this->_csv_name.c_str() );
	std::cout	<< this->_infile_name
				<< " Constructor called. [parameterized]" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &rhs ) {
	*this = rhs;
	return ;
}

BitcoinExchange::~BitcoinExchange( void ) {
	if (this->_infile.is_open()) {
		this->_infile.close();
	}
	if (this->_csv.is_open()) {
		this->_csv.close();
	}
	this->_infile_name = EMPTY_STR;
	return ;
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &rhs ) {
	if (this == &rhs){
		return ( *this );
	}
	this->_infile_name = rhs.getInfileName();
	if (this->_infile.is_open() == true) {
		if (this->_infile_name.compare( rhs.getInfileName() ) != 0) {
			this->_infile.close();
			this->_infile.open( rhs.getInfileName().c_str() );
		}
	} else {
		this->_infile.open( rhs.getInfileName().c_str() );
	}
	return ( *this );
}
