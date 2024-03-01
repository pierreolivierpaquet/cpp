/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:55:05 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/01 16:08:10 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/Span.hpp"

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

// template < typename T >
// void	Span::addNumber( typename T::const_iterator it1, typename T::const_iterator it2 ) {
// 	std::list< int > buffer_list( it1, it2 );

// 	this->_list.insert( this->_list.end(), buffer_list.begin(), buffer_list.end() );
// }

size_t	Span::size( void ) const {
	return ( this->_list.size() );
}

u_int32_t	Span::shortestSpan( void ) const {
	u_int32_t								shortest_span = UINT32_MAX;
	std::list<u_int32_t>::const_iterator	it;
	std::list<u_int32_t>::const_iterator	it_end;
	std::list<u_int32_t>::const_iterator	it_compare;
	u_int32_t								temp_span = 0;

	if (this->_list.size() == 0) {
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

	if (this->_list.size() == 0) {
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
	return ("error: no calculation possible.");
}
