/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:49:35 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/12 09:06:00 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/BitcoinExchange.hpp"

///	------------------------------------------------------------ @section UTIL.S

tm	*get_local_time( void ) {
	static time_t current;
	static tm *local_time;

	if (current == 0){
		current = time( NULL );
	}
	if (local_time == NULL) {
		local_time = localtime( &current );
	}
	return ( local_time );
}

u_int32_t	current_time( e_current_time get_option ) {
	tm	*date = NULL;

	date = get_local_time();
	if (date == NULL) {
		return ( std::numeric_limits<u_int32_t>::max() );
	} else {
		switch (get_option)
		{
			case ( DAY ):	return ( date->tm_mday );
			case ( MONTH ):	return ( date->tm_mon + 1 );
			case ( YEAR ):	return ( date->tm_year + 1900 );
			default:	break;
		}
	}
	return ( std::numeric_limits<u_int32_t>::max() );
}

const std::string BitcoinExchange::_csv_name = CSV_FILENAME;

static void	convert_map( ifMap &ref_map) {
	std::istringstream buffer( EMPTY_STR );
	std::string	tmp;
	for (size_t i = 0; i < ref_map.size() ; i++) {
		buffer.str( ref_map[ i ].origin_data.first) ; // sets the stream

		std::getline( buffer, tmp, '-');
		ref_map[ i ].year = static_cast<u_int32_t>(std::atoi( tmp.c_str() ));
		std::getline( buffer, tmp, '-' );
		ref_map[ i ].month = static_cast<u_int32_t>(std::atoi( tmp.c_str() ));
		std::getline( buffer, tmp, '-' );
		ref_map[ i ].day = static_cast<u_int32_t>(std::atoi( tmp.c_str() ));
		buffer.clear();
		buffer.str( ref_map[ i ].origin_data.second );
		std::getline( buffer, tmp );
		ref_map[ i ].value = std::strtof( tmp.c_str(), NULL);
		buffer.clear();
	}
//	Deletes the first line if it contains <COLUMN><TITLE> elements.
	if (ref_map[ 0 ].origin_data.first.find_first_not_of( INPUT_CHAR ) != std::string::npos ||
		ref_map[ 0 ].origin_data.second.find_first_not_of( INPUT_CHAR ) != std::string::npos) {
		ref_map.erase( ref_map.begin() );
	}
	return ;
}

static void	upload_file( std::ifstream &infile, ifMap &ref_map, char delimiter ) {
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
		if (line.empty() != true) {
			ref_map.insert( ifPair( n++, tmp ) );
		}
		line.clear();
		if (infile.eof() == true) {
			break;
		}
	}
	return ;
}

static ifMap::const_iterator locate( const t_data &lhs, const ifMap &csv_map ) {
	ifMap::const_iterator it = csv_map.begin();
	ifMap::const_iterator ite = csv_map.end();
	while (it != ite){
		if (lhs == (*it).second){
			return ( it );
		}
		if ((*it).second < lhs) {
			++it;
		} else {
			return ( --it );
		}
	}
	return ( --it );
}

static bool leap_check ( u_int32_t year ) {
	if (year % 4 == 0 && year % 100 != 0) {
		return ( true );
	} else if ( year % 400 == 0 ) {
		return ( true );
	}
	return ( false );
}

static bool	valid_date( ifMap::const_iterator it ) {
	if ((*it).second.month > 12 || ((*it).second.year <= 2009 &&
									(*it).second.month <= 1 &&
									(*it).second.day < 2)) {
		return ( false );
	}
	switch ((*it).second.month) {
	case( 1 ): case( 3 ): case( 5 ): case( 7 ): case( 8 ): case( 10 ): case( 12 ):
		if ((*it).second.day > 31) {
			return ( false );
		}
		break ;
	case( 2 ):
		if (leap_check( (*it).second.year ) == false && (*it).second.day > 28) {
			return ( false );
		} else if (leap_check(	(*it).second.year ) == true && (*it).second.day > 29) {
			return ( false );
		}
		break ;
	case( 4 ): case( 6 ): case( 9 ): case( 11 ):
		if ( (*it).second.day > 30 ) {
			return ( false );
		}
		break ;
	default:
		break ;
	}
	return ( true );
}

static void	valid_check(ifMap::const_iterator it ) {
	if ( (*it).second.origin_data.first.find_first_of('-') == std::string::npos ||
//		Protects YYYY-MM-DD from extra/missing character.
		(*it).second.origin_data.first.length() != 11 ||
		((*it).second.origin_data.first.find_first_of('-') ==
		(*it).second.origin_data.first.find_last_of('-')) ) {
		throw( BitcoinExchange::BadInput() );
//				Protects againts impossible date.
	} else if ( (*it).second.year	==	0 ||
				(*it).second.month	==	0 ||
				(*it).second.day	==	0) {
		throw( BitcoinExchange::BadInput() );
//				Protects against futuristic dates.
	} else if ( (*it).second.year	>=	current_time( YEAR ) &&
				(*it).second.month	>=	current_time( MONTH ) &&
				(*it).second.day	>	current_time( DAY ) ) {
		throw( BitcoinExchange::BadInput() );
	} else if ( valid_date( it ) == false) {
		throw( BitcoinExchange::BadInput() );
	} else if ( (*it).second.value > 1000 ) {
		throw( BitcoinExchange::ValueTooLarge() );
	} else if ( (*it).second.value < 0) {
		throw( BitcoinExchange::ValueNegative() );
	}
	return ;
}

static void	display_results( ifMap::const_iterator it_csv, ifMap::const_iterator it_infile ) {
	std::cout	<< (*it_infile).second.origin_data.first
				<< (*it_infile).second.value << ARROW
				<< ( (*it_csv).second.value * (*it_infile).second.value )
				<< std::endl;
	return ;
}

static void	match( ifMap &infile_map, ifMap &csv_map ) {
	ifMap::const_iterator	it_infile;
	ifMap::const_iterator	ite = infile_map.end();
	ifMap::const_iterator	it_csv;
	for (it_infile = infile_map.begin(); it_infile != ite; it_infile++){
		try {
			valid_check( it_infile );
			it_csv = locate( (*it_infile).second, csv_map );
			display_results( it_csv, it_infile );
		} catch ( BitcoinExchange::BadInput &e ) {
			std::cerr	<< e.what()
						<< ARROW << (*it_infile).second.origin_data.first << std::endl;
		} catch ( BitcoinExchange::ValueTooLarge &e ) {
			std::cerr	<< e.what() << std::endl;
		} catch ( BitcoinExchange::ValueNegative &e ) {
			std::cerr	<< e.what() << std::endl;
		}
	}
	return ;
}

///	------------------------------------------------------------ @section STRUCT

bool	t_data::operator==( const struct s_data &comp ) const {
	if (this->year != comp.year ||
		this->month != comp.month ||
		this->day != comp.day) {
		return ( false );
	}
	return ( true );
}

bool	t_data::operator<(const struct s_data &comp) const {
	if (this->year >= comp.year &&
		this->month >= comp.month &&
		this->day > comp.day) {
		return ( false );
	}
	return ( true );
}

///	-------------------------------------------------------- @section FUNCTION.S

void	BitcoinExchange::display( void ) {
	upload_file( this->_infile, this->_infile_map, INPUT_DELIMITER[ 0 ]);
	convert_map( this->_infile_map );
	upload_file( this->_csv, this->_csv_map, CSV_DELIMITER[ 0 ] );
	convert_map( this->_csv_map );
	match ( this->_infile_map, this->_csv_map );
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
	if (this->_infile.fail() == true || this->_csv.fail() == true) {
		throw( std::runtime_error( ERR_FILE ) );
	}
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
	std::cout	<< this->_infile_name
				<< " Destructor called. [default]" << std::endl;
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
	if (this->_infile.fail() || this->_csv.fail()) {
		throw( std::runtime_error( ERR_FILE ) );
	}
	return ( *this );
}

///	--------------------------------------------------- @section NESTED CLASS.ES

const char *BitcoinExchange::BadInput::what( void ) const throw() {
	return ( ERR_BAD_INPUT );
}

const char *BitcoinExchange::ValueTooLarge::what( void ) const throw() {
	return ( ERR_LARGE_NUM );
}

const char *BitcoinExchange::ValueNegative::what( void ) const throw() {
	return ( ERR_NEG_NUM );
}
