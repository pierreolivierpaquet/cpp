/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:55:05 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/04 18:32:02 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/Span.hpp"

bool	Span::_rand_seed = false;

///	-------------------------------------------------------- @section FUNCTION.S

Span::Span( void) : _N( 0 ){
	return ;
}

void	Span::addNumber( int number ) {
	if (this->size() < this->_N){
		this->_list.push_back( number );
	} else {
		throw( Span::ExceedingNumber() );
	}
	return ;
}

void	Span::addNumber( u_int32_t N, int max_value ) {
	int	*arr = NULL;
	if (N == 0) {
		return ;
	}
	arr = new int[ N ];
	if (this->_rand_seed == false) {
		srand( time( NULL ) );
		this->_rand_seed = true;
	}
	if (max_value == std::numeric_limits< int >::max()) {
		max_value--;
	}
	for (size_t i = 0; i < N; i++){
		arr[ i ] = rand() % (max_value + 1);
	}
	std::list< int > lst(arr, arr + N);
	this->addNumber< std::list< int > >( lst.begin(), lst.end() );
	delete [] arr;
	arr = NULL;
	return ;
}

int	Span::shortestSpan( void ) const {
	if (this->_list.size() <= 1) {
		throw( Span::NoSpan() );
	}
	std::list< int >sorted( this->_list.begin(), this->_list.end() );
	sorted.sort();
	std::list< int >::const_iterator it1;
	std::list< int >::const_iterator it2;
	u_int32_t	shortest_span = std::numeric_limits< int >::max();
	u_int32_t	temp;
	it1 = sorted.begin();
	for ( it2 = sorted.begin(); ++it2 != sorted.end(); it1++){
		temp = std::abs( static_cast< int >(*it1 - *it2) );
		if (temp < shortest_span){
			shortest_span = temp;
		}
	}
	return ( shortest_span );
}

int	Span::longestSpan( void ) const {
	if (this->_list.size() <= 1) {
		throw( Span::NoSpan() );
	}
	std::list< u_int32_t >sorted( this->_list.begin(), this->_list.end() );
	sorted.sort();
	std::list< u_int32_t >::const_iterator it1;
	std::list< u_int32_t >::const_iterator it2;
	u_int32_t	longest_span = std::numeric_limits< int >::min();
	
	it1 = sorted.begin();
	it2 = sorted.end();
	--it2;
	longest_span = std::abs( static_cast< int >(*it1 - *it2) );
	return ( longest_span );
}

void	Span::print( void ) const {
	std::list< int >::const_iterator it;

	it = this->_list.begin();
	std::cout	<< "----------------------------------------[ \033[1mPRINT START\033[0m ]" << std::endl;
	for (it = this->_list.begin(); it != this->_list.end() ; it++){
		std::cout	<< *it << std::endl;
	}
	std::cout	<< "----------------------------------------[ \033[1mPRINT END\033[0m ]" << std::endl;
	return ;
}

void	Span::print( std::string fname ) const {
	std::ofstream outfile;

	outfile.open( fname.c_str(), std::fstream::trunc );
	if (outfile.is_open() == true)
	{
		std::list< int >::const_iterator it;

		it = this->_list.begin();
		outfile	<< "----------------------------------------[ PRINT START ]" << std::endl;
		for (it = this->_list.begin(); it != this->_list.end() ; it++){
			outfile	<< *it << ", " << std::endl;
		}
		outfile	<< "----------------------------------------[ PRINT END ]" << std::endl;
		outfile.close();
	}
	return ;
}

///	---------------------------------------------------------- @section GETTER.S

size_t	Span::size( void ) const {
	return ( this->_list.size() );
}

std::list< int >	Span::getList( void ) const {
	return ( this->_list );
}

u_int32_t	Span::getN( void ) const {
	return ( this->_N );
}

///	-------------------------------------- @section CONSTRUCTOR.S - DESTRUCTOR.S

Span::Span( u_int32_t N_int ) : _N( N_int ){
	return ;
}

Span::~Span( void ) {
	return ;
}

///	---------------------------------------- @section CANONICAL FORM REQUISITE.S

Span::Span( const Span &rhs ) {
	*this = rhs;
	return ;
}

Span &Span::operator=( const Span &rhs ) {
	this->_N = rhs.getN();
	this->_list.clear();
	this->_list = rhs.getList();
	return ( *this );
}

///	--------------------------------------------------- @section NESTED CLASS.ES

const char *Span::NoSpan::what( void ) const throw() {
	return ("\033[1;31merror\033[0m: no calculation possible.");
}

const char *Span::ExceedingNumber::what( void ) const throw() {
	return ("\033[1;31merror\033[0m: exceeding amount of number.");
}

///	------------------------------------------------------- @section ALTERNATIVE

// u_int32_t	Span::shortestSpan( void ) const {
// 	u_int32_t								shortest_span = std::numeric_limits< u_int32_t >::max();
// 	std::list<u_int32_t>::const_iterator	it;
// 	std::list<u_int32_t>::const_iterator	it_end;
// 	std::list<u_int32_t>::const_iterator	it_compare;
// 	u_int32_t								temp_span = std::numeric_limits< u_int32_t >::min();

// 	if (this->_list.size() <= 1) {
// 		throw( Span::NoSpan() );
// 	}
// 	it_end = this->_list.end();
// 	for (it = this->_list.begin(); it != it_end; it++) {
// 		it_compare = it;
// 		for (++it_compare; it_compare != it_end; it_compare++) {
// 			temp_span = static_cast< u_int32_t >(std::abs( static_cast< int >(*it - *it_compare)) );
// 			if (temp_span < shortest_span) {
// 				shortest_span = temp_span;
// 			}
// 		}
// 	}
// 	return ( shortest_span );
// }

// u_int32_t	Span::longestSpan( void ) const {
// 	u_int32_t								longest_span = std::numeric_limits< u_int32_t >::min();
// 	std::list<u_int32_t>::const_iterator	it;
// 	std::list<u_int32_t>::const_iterator	it_end;
// 	std::list<u_int32_t>::const_iterator	it_compare;
// 	u_int32_t								temp_span = std::numeric_limits< u_int32_t >::max();

// 	if (this->_list.size() <= 1) {
// 		throw( Span::NoSpan() );
// 	}
// 	it_end = this->_list.end();
// 	for (it = this->_list.begin(); it != it_end; it++) {
// 		it_compare = it;
// 		for (++it_compare; it_compare != it_end; it_compare++) {
// 			temp_span = static_cast< u_int32_t >(std::abs( static_cast< int >(*it - *it_compare)) );
// 			if (temp_span > longest_span) {
// 				longest_span = temp_span;
// 			}
// 		}
// 	}
// 	return ( longest_span );
// }
