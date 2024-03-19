/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:28:04 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/19 12:12:00 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PMERGEME_HPP_
# define	PMERGEME_HPP_

# include	<iostream>
# include	<typeinfo>	// (https://cplusplus.com/reference/typeinfo/type_info/)
# include	<vector>
# include	<stack>
# include	<sstream>	// istringstream
# include	<limits>	// numeric_limits
# include	<cstdlib>	// u_int32_t
# include	<utility>	// swap
# include	<chrono>	// high_resolution_clock

///	----------------------------------------------- @section MACRO.S - TYPEDEF.S

# ifndef	EXIT_SUCCESS
#  define	EXIT_SUCCESS	0
# endif	/*	EXIT_SUCCESS	*/

# define	ERR_MSG			"\033[1;31merror\033[0m"
# define	ERR_OVERFLOW	": unsupported value detected: "
# define	ERR_BAD_INPUT	": non-numeric input detected."
# define	ERR_NO_INPUT	": missing value(s)."
# define	DIGIT_CHAR		"+-0123456789"

typedef enum {
	DEQUE,
	VECTOR,
	ERROR
}	e_type_info;

typedef std::deque< std::pair< int, int > >		deque_t;
typedef std::vector< std::pair< int, int > >	vector_t;

///	---------------------------------------------------------- @section CLASSE.S

template < typename Container = deque_t >
class	PmergeMe : public Container {
	private:
		PmergeMe( void );
		PmergeMe	&operator=( const PmergeMe &rhs );
		PmergeMe( const PmergeMe &rhs );

		const std::vector< u_int32_t >	_unsorted_vector;
		const std::deque< u_int32_t >	_unsorted_deque;
		e_type_info						_ti;
		const std::type_info			&_type_info;
		u_int32_t						_size;
		std::deque< int >				_sorted_deque;
		std::vector< int >				_sorted_vector;

		std::chrono::duration<double, std::milli>	_parsing_deque;
		std::chrono::duration<double, std::milli>	_parsing_vector;
		std::chrono::duration<double, std::milli>	_sorting;

		void	_pairing(	std::vector< u_int32_t >::const_iterator it );
		void	_pairing(	std::deque< u_int32_t >::const_iterator it );
		void	_pairSort( void );
		void	_mergeSort( Container &array );
		void	_merge( Container &lhs, Container &rhs, Container &array );
		void	_mainChain( void );
		void	_insertionSort( void );
		void	_insertStraggler( void );

		std::pair< int, int >	_straggler;

	public:
///	------------------------------------------------- @class SETTER.S - GETTER.S

		void		setType( void );
		std::string	getTypeInfo( void ) const;
		u_int32_t	getSize( void ) const;

///	---------------------------------------- @class CONSTRUCTOR.S - DESTRUCTOR.S

		PmergeMe( int ac, char **av );
		virtual ~PmergeMe(	void );

///	---------------------------------------------------------- @class FUNCTION.S

		void	algorithm( void );
		void	printUnsorted( void ) const;
		void	printSortedVector( void ) const;
		void	printSortedDeque( void ) const;
		void	printDuration( void ) const;

};	/*	PmergeMe	*/

template < typename C >
C input_check( int ac, char **av, std::chrono::duration<double, std::milli> &duration );

void	displayComparison( const PmergeMe< deque_t > &deque, const PmergeMe< vector_t > &vector );

# include "../include/PmergeMe.tpp"

#endif	/*	PMERGEME_HPP_	*/
