/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:11:18 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/14 14:45:51 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

template < typename Container >
void	PmergeMe< Container >::setInput( std::string input ) {
	this->_input = input;
	return ;
}

template < typename Container >
PmergeMe< Container >::PmergeMe( void ) :
	_type_info( typeid( Container ) ) {
	if ( this->_type_info == typeid( deque_t ) ) {
		this->_ti = DEQUE;
	} else if ( this->_type_info == typeid( vector_t ) ) {
		this->_ti = VECTOR;
	} else {
		this->_ti = ERROR;
	}
	return ;
}

template < typename Container >
PmergeMe< Container >::~PmergeMe() {
	return ;
}

template < typename Container >
std::string PmergeMe< Container >::getTypeInfo( void ) const {
	if (this->_ti == DEQUE) {
		return ( "std::deque< int >" );
	} else if ( this->_ti == VECTOR ) {
		return ( "std::vector< int >" );
	}
	return ( "" ) ;
}
