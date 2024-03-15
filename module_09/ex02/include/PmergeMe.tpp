/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:11:18 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/15 14:13:25 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

template < typename C >
C input_check( int ac, char **av ) {
	C unsorted;
	u_int32_t	tmp = 0;

	for (int i = 1; i < ac; i++) {
		tmp = std::atoi( av[ i ] );
		if (std::string(av[ i ]).length() > 10 ||
			tmp > static_cast< u_int32_t >(std::numeric_limits< int >::max())) {
			throw( std::runtime_error( static_cast< std::string >( ERR_MSG )
										+ ERR_OVERFLOW + av[ i ]) );
		} else if ( std::string( av[ i ] ).find_first_not_of( DIGIT_CHAR )
					!= std::string::npos ) {
			throw( std::runtime_error( static_cast< std::string >( ERR_MSG )
										+ ERR_BAD_INPUT ) );
		} else {
			unsorted.push_back( tmp );
		}
	}
	return ( unsorted );
}

template < typename Container >
void	PmergeMe< Container >::_pairing( std::vector< u_int32_t >::const_iterator it ) {
	std::pair< int, int > pair( 0, 0 );
	for (size_t i = 1 ; i <= this->_size; i++) {
		if (i % 2 && i < this->_size) {
			pair.first = *it;
		} else {
			pair.second = *it;
		}
		if (i % 2 == 0) {
			this->push_back( pair );
			pair = std::make_pair( 0, 0 );
		} else if ( i == this->_size ) {
			this->push_back( pair );
		}
		it++;
	}
	return ;
}

template < typename Container >
void	PmergeMe< Container >::_pairing( std::deque< u_int32_t >::const_iterator it ) {
	std::pair< int, int > pair( 0, 0 );
	for (size_t i = 1 ; i <= this->_size; i++) {
		if (i % 2 && i < this->_size) {
			pair.first = *it;
		} else {
			pair.second = *it;
		}
		if (i % 2 == 0) {
			this->push_back( pair );
			pair = std::make_pair( 0, 0 );
		} else if ( i == this->_size ) {
			this->push_back( pair );
		}
		it++;
	}
	return ;
}

///	-------------------------------------------------------- @section FUNCTION.S

template < typename Container >
void	PmergeMe< Container >::_pairSort( void ) {
	if (this->_ti == DEQUE){
		this->_pairing(	this->_unsorted_deque.begin() );
	} else {
		this->_pairing(	this->_unsorted_vector.begin() );
	}
	if ( this->_size % 2 ) {
		this->_straggler = this->back();
		this->pop_back();
	}
	typename Container::iterator it = this->begin();
	typename Container::iterator ite = this->end();
	int	tmp = 0;
	while (it != ite) {
		if ((*it).first > (*it).second) {
			std::swap( (*it).first, (*it).second );
		}
		++it;
	}
	return ;
}

template < typename Container >
void	PmergeMe< Container >::_merge( Container &lhs, Container &rhs, Container &array ) {
	size_t	l = lhs.size();
	size_t	r = rhs.size();
	size_t	total = array.size();
	size_t	i( 0 ), j( 0 ), k( 0 );

	while (j < l && k < r) {
		if (lhs[ j ].first < rhs[ k ].first) {
			array[ i++ ] = lhs[ j++ ];
		} else {
			array[ i++ ] = rhs[ k++ ];
		}
	}
	while (j < l) {
		array[ i++ ] = lhs[ j++ ];
	}
	while (k < r) {
		array[ i++ ] = rhs[ k++ ];
	}
	return ;
}

/// @note This function slices the base class.
template < typename Container >
void	PmergeMe< Container >::_mergeSort( Container &array) {
	size_t	lenght = array.size();
	size_t	middle = lenght * 0.5;
	if (lenght < 2) {
		return ;
	}
	Container	left;
	Container	right;
	for (size_t i = 0; i < middle; i++) {
		left.push_back( array[ i ] );
	}
	for (size_t i = middle; i < lenght; i++) {
		right.push_back( array[ i ] );
	}
	this->_mergeSort( left );
	this->_mergeSort( right );
	this->_merge( left, right, array );
	return ;
}

template < typename Container >
void	PmergeMe< Container >::algorithm( void ) {
	//	START TIMER HERE =======================================================

	this->_pairSort();
	this->_mergeSort( *this );

	// STOP TIMER HERE =========================================================
	return ;
}

///	-------------------------------------- @section CONSTRUCTOR.S - DESTRUCTOR.S

template < typename Container >
void	PmergeMe< Container >::setType( void ) {
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
PmergeMe<Container>::PmergeMe( int ac, char **av ) :
	_unsorted_vector( input_check<std::vector< u_int32_t > >( ac, av ) ),
	_unsorted_deque( input_check<std::deque< u_int32_t > >( ac, av ) ),
	_type_info( typeid( Container ) ),
	_size( ac - 1 ),
	_straggler( -1, -1 ) {
	this->setType();
	return ;
}

template < typename Container >
PmergeMe< Container >::PmergeMe( void ) :
	_type_info( typeid( Container ) ) {
	this->setType();
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
