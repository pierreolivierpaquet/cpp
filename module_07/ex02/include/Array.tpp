/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:15:09 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/27 10:37:39 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/Array.hpp"

/// ---------------------------------------------------------- @section GETTER.S

template < typename T >

uint32_t	Array<T>::size( void ) const {
	return ( this->_size );
}

template < typename T >
	T	*Array<T>::getElement( void ) const {
	return ( this->_element );
}

/// ------------------------------ @section DEFAULT CONSTRUCTOR.S — DESTRUCTOR.S

/// @brief Instance with empty array is constructed.
template < typename T >
Array<T>::Array( void ) :
	_size( 0 ),
	_element( NULL ) {
	return ;
}

template < typename T >
Array<T>::~Array( void ) {
	if (this->_element != NULL){
		delete [] this->_element;
		this->_element = NULL;
	}
	std::memset( this, 0, sizeof( *this ) );
	return ;
}

/// --------------------------------------- @section PARAMETERIZED CONSTRUCTOR.S

template < typename T >
Array<T>::Array( uint32_t N ) : _size( N ) {
	if (this->_size == 0){
		this->_element = NULL;
		return ;
	}
	this->_element = new T [ N ];
	return ;
}

/// ----------------------------------------- @section CANONICAL FORM REQUISITES

template < typename T >
Array<T>::Array( const Array<T> &rhs ) : _size( rhs.size() ) {
	this->_element = new T [ this->_size ] ;
	*this = rhs;
	return ;
}

template < typename T >
Array<T> &Array<T>::operator=( const Array<T> &rhs ) {
	uint32_t	rhs_N = rhs.size();
	
	if (this == &rhs){
		return ( *this );
	}
	if (this->_element != NULL && this->_size < rhs_N ) {
		std::memset( this->_element, 0,
			( sizeof( *this->_element ) * this->_size ) );
		delete [] this->_element;
		this->_element = NULL;
	} else {
		std::memset( this->_element, 0,
			( sizeof( *this->_element ) * this->_size ) );
	}
	if (this->_element == NULL && rhs_N != 0) {
		this->_element = new T [ rhs_N ];
	}
	this->_size = rhs_N;
	for (uint32_t i = 0; i < this->_size; i++) {
		this->_element[ i ] = rhs.getElement()[ i ];
	}
	return ( *this );
}

template < typename T >
const char *Array<T>::BadArrayIndex::what( void ) const throw() {
	return ( "\033[1;31merror\033[0m: provided index is out of range" );
}

template < typename T >
T	&Array<T>::operator[]( const uint32_t index ) const {
	if (index >= this->_size){
		throw( Array::BadArrayIndex() );
	}
	return ( this->_element[ index ]);
}
