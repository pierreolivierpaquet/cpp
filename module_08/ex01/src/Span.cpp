/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:55:05 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/04 09:57:05 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/Span.hpp"

bool Span::rand_seed = false;

Span::Span( void) : _N( 0 ){
	return ;
}

Span::Span( u_int32_t N_int ) : _N( N_int ){
	return ;
}

Span::~Span( void ) {
	return ;
}

void	Span::addNumber( u_int32_t number ) {
	if (this->size() < this->_N){
		this->_list.push_back( number );
	}
	return ;
}

size_t	Span::size( void ) const {
	return ( this->_list.size() );
}

u_int32_t	Span::shortestSpan( void ) const {
	u_int32_t								shortest_span = UINT32_MAX;
	std::list<u_int32_t>::const_iterator	it;
	std::list<u_int32_t>::const_iterator	it_end;
	std::list<u_int32_t>::const_iterator	it_compare;
	u_int32_t								temp_span = 0;

	if (this->_list.size() <= 1) {
		throw( Span::NoSpan() );
	}
	it_end = this->_list.end();
	for (it = this->_list.begin(); it != it_end; it++) {
		it_compare = it;
		for (++it_compare; it_compare != it_end; it_compare++) {
			temp_span = static_cast< u_int32_t >(std::abs( static_cast< int >(*it - *it_compare)) );
			if (temp_span < shortest_span) {
				shortest_span = temp_span;
			}
		}
	}
	return ( shortest_span );
}

u_int32_t	Span::longestSpan( void ) const {
	u_int32_t								longest_span = 0;
	std::list<u_int32_t>::const_iterator	it;
	std::list<u_int32_t>::const_iterator	it_end;
	std::list<u_int32_t>::const_iterator	it_compare;
	u_int32_t								temp_span = UINT32_MAX;

	if (this->_list.size() <= 1) {
		throw( Span::NoSpan() );
	}
	it_end = this->_list.end();
	for (it = this->_list.begin(); it != it_end; it++) {
		it_compare = it;
		for (++it_compare; it_compare != it_end; it_compare++) {
			temp_span = static_cast< u_int32_t >(std::abs( static_cast< int >(*it - *it_compare)) );
			if (temp_span > longest_span) {
				longest_span = temp_span;
			}
		}
	}
	return ( longest_span );
}

const char *Span::NoSpan::what( void ) const throw() {
	return ("\033[1;31merror\033[0m: no calculation possible.");
}

const char *Span::ExceedingNumber::what( void ) const throw() {
	return ("\033[1;31merror\033[0m: exceeding amount of number.");
}

void	Span::print( void ) const {
	std::list< u_int32_t >::const_iterator it;

	it = this->_list.begin();
	for (it = this->_list.begin(); it != this->_list.end() ; it++){
		std::cout	<< *it << std::endl;
	}
	return ;
}

void	Span::addNumber( u_int32_t N, u_int32_t max_value ) {
	// if (N == 0){
	// 	return ;
	// }
	// u_int32_t	arr[ N ];

	// if (Span::rand_seed == false){
	// 	srand( time( NULL ) );
	// 	Span::rand_seed = true;
	// } else if () {
		
	// }
	
	return ;
}
