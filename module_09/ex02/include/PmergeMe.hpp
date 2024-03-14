/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:28:04 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/14 14:44:56 by ppaquet          ###   ########.fr       */
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


///	----------------------------------------------- @section MACRO.S - TYPEDEF.S

# ifndef	EXIT_SUCCESS
#  define	EXIT_SUCCESS	0
# endif	/*	EXIT_SUCCESS	*/

typedef enum {
	DEQUE,
	VECTOR,
	ERROR
}	e_type_info;

typedef std::deque< std::pair< int, int > >		deque_t;
typedef std::vector< std::pair< int, int > >	vector_t;

///	------------------------------------------------------------------- @section

template < typename Container = std::deque< std::pair< int, int > > >
class	PmergeMe : public Container {
	private:
		e_type_info				_ti;
		const std::type_info	&_type_info;
		std::string				_input;

	public:
		PmergeMe(	void );
		virtual ~PmergeMe(	void );
		std::string	getTypeInfo( void ) const;

		void	setInput( std::string input );

};	/*	PmergeMe	*/

# include "../include/PmergeMe.tpp"

#endif	/*	PMERGEME_HPP_	*/
