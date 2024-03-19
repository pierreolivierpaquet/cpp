/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:11:18 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/19 12:08:56 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

///	------------------------------------------------------------ @section UTIL.S

template < typename C >
C input_check( int ac, char **av, std::chrono::duration<double, std::milli> &duration ) {
	C unsorted;
	u_int32_t	tmp = 0;

	static std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	if (ac == 1) {
		throw( std::runtime_error( static_cast< std::string >( ERR_MSG )
									+ ERR_NO_INPUT ) );
	}
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
	static std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
	duration = stop - start;
	return ( unsorted );
}

///	-------------------------------------------------------- @section FUNCTION.S

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
	while (it != ite) {
		if ((*it).first > (*it).second) {
			std::swap( (*it).first, (*it).second );
		}
		++it;
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
void	PmergeMe< Container >::_merge( Container &lhs, Container &rhs, Container &array ) {
	size_t	l = lhs.size();
	size_t	r = rhs.size();
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

template < typename Container >
void	PmergeMe< Container >::_mainChain( void ) {
	typename Container::const_iterator	ite = this->end();

	for (typename Container::const_iterator it = this->begin(); it != ite; it++ ) {
		if (this->_ti == DEQUE) {
			this->_sorted_deque.push_back( (*it).first );
		} else {
			this->_sorted_vector.push_back( (*it).first );
		}
	}
	return ;
}

template < typename Container >
void	PmergeMe< Container >::_insertionSort( void ) {
	typename Container::const_iterator	ite = this->end();

	for (typename Container::const_iterator it = this->begin(); it != ite; it++) {
		if (this->_ti == DEQUE) {
			std::deque< int >::reverse_iterator	deq_itre = this->_sorted_deque.rend();
			for (std::deque< int >::reverse_iterator deq_itr = this->_sorted_deque.rbegin(); deq_itr != deq_itre; deq_itr++) {
				if ((*it).second >= *deq_itr) {
					this->_sorted_deque.insert( deq_itr.base(), (*it).second );
					break ;
				}
			}
		} else {
			std::vector< int >::reverse_iterator	vec_itre = this->_sorted_vector.rend();
			for (std::vector< int >::reverse_iterator	vec_itr = this->_sorted_vector.rbegin(); vec_itr != vec_itre; vec_itr++) {
				if ((*it).second >= *vec_itr) {
					this->_sorted_vector.insert( vec_itr.base(), (*it).second );
					break ;
				}
			}
		}
	}
	return ;
}

template < typename Container >
void	PmergeMe< Container >::_insertStraggler( void ) {
	if ( this->_size % 2 == 0 ) {
		return ;
	}
	if (this->_ti == DEQUE) {
		std::deque< int >::reverse_iterator deq_itre = this->_sorted_deque.rend();
		if (this->_size == 1) {
			this->_sorted_deque.insert( this->_sorted_deque.rbegin().base(), this->_straggler.second);
		return ;
		}
		std::deque< int >::reverse_iterator deq_itr = this->_sorted_deque.rbegin();
		for (; deq_itr != deq_itre; deq_itr++) {
			if (this->_straggler.second >= *deq_itr) {
				this->_sorted_deque.insert( deq_itr.base(), this->_straggler.second );
				this->_straggler.second = -1;
				break ;
			}
		} if ( this->_straggler.second != -1 ) {
			this->_sorted_deque.insert( deq_itr.base(), this->_straggler.second );
		}
	} else {
		std::vector< int >::reverse_iterator vec_itre = this->_sorted_vector.rend();
		if (this->_size == 1) {
			this->_sorted_vector.insert( this->_sorted_vector.rbegin().base(), this->_straggler.second );
			return ;
		}
		std::vector< int >::reverse_iterator vec_itr = this->_sorted_vector.rbegin();
		for (; vec_itr != vec_itre; vec_itr++) {
			if (this->_straggler.second >= *vec_itr) {
				this->_sorted_vector.insert( vec_itr.base(), this->_straggler.second );
				this->_straggler.second = -1;
				break ;
			}
		} if ( this->_straggler.second != -1 ) {
			this->_sorted_vector.insert( vec_itr.base(), this->_straggler.second );
		}
	}
	return ;
}

///	------------------------------------------------------------------------ ///

template < typename Container >
void	PmergeMe< Container >::algorithm( void ) {
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	this->_pairSort();
	this->_mergeSort( *this );
	this->_mainChain();
	this->_insertionSort();
	this->_insertStraggler();

	std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
	this->_sorting = stop - start;
	this->clear();
	return ;
}

template < typename Container >
void	PmergeMe< Container >::printUnsorted() const {
	std::deque< u_int32_t >::const_iterator ite = this->_unsorted_deque.end();
	std::deque< u_int32_t >::const_iterator it = this->_unsorted_deque.begin();
	while (it != ite) {
		std::cout << *it;
		if (++it != ite) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return ;
}

template < typename Container >
void	PmergeMe< Container >::printSortedVector ( void ) const {
	std::vector< int >::const_iterator	ite = this->_sorted_vector.end();
	for (std::vector< int >::const_iterator it = this->_sorted_vector.begin(); it != ite; it++) {
		std::cout << *it << " " << std::endl;
	}
	return ;
}

template < typename Container >
void	PmergeMe< Container >::printSortedDeque ( void ) const {
	std::deque< int >::const_iterator	ite = this->_sorted_deque.end();
	std::deque< int >::const_iterator	it = this->_sorted_deque.begin();

	while (it != ite) {
		std::cout << *it;
		if (++it != ite) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return ;
}

template < typename Container >
void	PmergeMe< Container >::printDuration( void ) const {
	std::chrono::duration<double, std::milli> total;

	if (this->_ti == DEQUE) {
		total = this->_parsing_deque + this->_sorting;
	} else {
		total = this->_parsing_vector + this->_sorting;
	}
	std::cout <<  total.count() << " ms" << std::endl;
	return ;
}

///	----------------------------------------------- @section GETTER.S - SETTER.S

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
std::string PmergeMe< Container >::getTypeInfo( void ) const {
	if (this->_ti == DEQUE) {
		return ( "std::deque< int >" );
	} else if ( this->_ti == VECTOR ) {
		return ( "std::vector< int >" );
	}
	return ( "" ) ;
}

template < typename Container >
u_int32_t	PmergeMe< Container >::getSize( void ) const {
	return ( this->_size );
}

///	-------------------------------------- @section CONSTRUCTOR.S - DESTRUCTOR.S

template < typename Container >
PmergeMe<Container>::PmergeMe( int ac, char **av ) :
	_unsorted_vector( input_check<std::vector< u_int32_t > >( ac, av, this->_parsing_vector ) ),
	_unsorted_deque( input_check<std::deque< u_int32_t > >( ac, av, this->_parsing_deque ) ),
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
PmergeMe< Container >::~PmergeMe( void ) {
	return ;
}

template < typename Container >
PmergeMe< Container >::PmergeMe( const PmergeMe< Container > &rhs ) {
	if (this == &rhs) {
		return ;
	}
	*this = rhs;
	return ;
}

///	----------------------------------------------- @section OPERATOR.S OVERLOAD

template < typename Container >
PmergeMe< Container > &PmergeMe< Container >::operator=( const PmergeMe< Container > &rhs ) {
	static_cast< void >( rhs );
	return ( *this );
}
