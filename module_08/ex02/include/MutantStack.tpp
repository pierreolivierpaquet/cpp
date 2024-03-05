/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:26:02 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/05 12:54:00 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

///	-------------------------------------- @section CONSTRUCTOR.S - DESTRUCTOR.S

template < typename T, typename Container >
MutantStack< T, Container >::MutantStack( void ) {
	return ;
}

template < typename T, typename Container >
MutantStack< T, Container >::MutantStack( const MutantStack<T, Container> &rhs ) {
	*this = rhs;
	return ;
}

template < typename T, typename Container >
MutantStack< T, Container >::~MutantStack( void ) {
	return ;
}

template< typename T, typename Container >
MutantStack< T, Container > &MutantStack< T, Container >::operator=( const MutantStack<T, Container> &rhs ) {
	if (*this == rhs){
		return ( *this );
	}
	return ( *this );
}

template< typename T, typename Container >
typename Container::iterator	MutantStack< T, Container >::begin( void ) {
	typename Container::iterator	begin_it;
	begin_it = this->c.begin();
	return ( begin_it );
}

template < typename T, typename Container > 
typename Container::const_iterator MutantStack< T, Container >::begin ( void ) const {
	typename Container::const_iterator	const_begin_it;
	const_begin_it = this->c.begin();
	return ( const_begin_it );
}


template < typename T, typename Container >
typename Container::iterator	MutantStack< T, Container >::end( void ) {
	typename Container::iterator	end_it;
	end_it = this->c.end();
	return ( end_it );
}

template < typename T, typename Container >
typename Container::const_iterator	MutantStack< T, Container >::end( void ) const {
	typename Container::const_iterator	const_end_it;
	const_end_it = this->c.end();
}

template< typename T, typename Container >
typename Container::iterator	MutantStack< T, Container >::rbegin( void ) {
	typename Container::iterator	rbegin_it;
	rbegin_it = this->c.rbegin();
	return ( rbegin_it );
}

template< typename T, typename Container >
typename Container::const_iterator	MutantStack< T, Container >::rbegin( void ) const {
	typename Container::iterator	rbegin_it;
	rbegin_it = this->c.rbegin();
	return ( rbegin_it );
}

template< typename T, typename Container >
typename Container::iterator	MutantStack< T, Container >::rend( void ) {
	typename Container::iterator	rend_it;
	rend_it = this->c.rend();
	return ( rend_it );
}

template< typename T, typename Container >
typename Container::const_iterator	MutantStack< T, Container >::rend( void ) const {
	typename Container::iterator	rend_it;
	rend_it = this->c.rend();
	return ( rend_it );
}
