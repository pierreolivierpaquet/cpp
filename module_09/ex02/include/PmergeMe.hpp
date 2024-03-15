/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:28:04 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/15 13:19:24 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PMERGEME_HPP_
# define	PMERGEME_HPP_

# include	<iostream>
# include	<typeinfo>	// (https://cplusplus.com/reference/typeinfo/type_info/)
# include	<vector>
# include	<list> // test
# include	<stack>
# include	<sstream>	// istringstream
# include	<limits>	// numeric_limits
# include	<cstdlib>	// u_int32_t
# include	<utility>	// swap

///	----------------------------------------------- @section MACRO.S - TYPEDEF.S

# ifndef	EXIT_SUCCESS
#  define	EXIT_SUCCESS	0
# endif	/*	EXIT_SUCCESS	*/

# define	ERR_MSG			"\033[1;31merror\033[0m"
# define	ERR_OVERFLOW	": unsupported value detected: "
# define	ERR_BAD_INPUT	": non-numeric input detected."
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
		const std::vector< u_int32_t >	_unsorted_vector;
		const std::deque< u_int32_t >	_unsorted_deque;
		e_type_info						_ti;
		const std::type_info			&_type_info;
		u_int32_t						_size;

		void	_pairSort( void ); // first sorting step.
		void	_mergeSort( Container &array );
		void	_merge( Container &lhs, Container &rhs, Container &array );
		void	_pairing(	std::vector< u_int32_t >::const_iterator it );
		void	_pairing(	std::deque< u_int32_t >::const_iterator it );

		std::pair< int, int >	_straggler;

	public:
///	------------------------------------------------- @class SETTER.S - GETTER.S

		void		setType( void );
		std::string	getTypeInfo( void ) const;

///	------------------------------------------------------- @class CONSTRUCTOR.S

		PmergeMe( int ac, char **av );

///	-------------------------------------------------------- @class DESTRUCTOR.S

		virtual ~PmergeMe(	void );

///	------------------------------------------------- @class OPERATOR.S OVERLOAD



///	---------------------------------------------------------- @class FUNCTION.S

	void	algorithm( void );

};	/*	PmergeMe	*/

// std::vector< u_int32_t > input_check( int ac, char **av );
template < typename C >
C input_check( int ac, char **av );

# include "../include/PmergeMe.tpp"

#endif	/*	PMERGEME_HPP_	*/
