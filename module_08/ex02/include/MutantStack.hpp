/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:26:04 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/05 14:33:24 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MUTANTSTACK_HPP_
# define	MUTANTSTACK_HPP_

# include	<iostream>
# include	<stack>
# include	<vector>
# include	<list>

// std::deque = "double ended queue".
// T = type of element.
// Container = Underlying container where elements are stored.
template < typename T, typename Container = std::deque < T > >
class	MutantStack	: public std::stack< T > {
	private:

	public:
///	---------------------------------------- @class CONSTRUCTOR.S - DESTRUCTOR.S
		MutantStack( void );					// Default.
		MutantStack( const MutantStack &rhs );	// Reference copy.
		~MutantStack( void );					// Default.

///	----------------------------------------------------------- @class OPERAND.S

		MutantStack	&operator=( const MutantStack &rhs );	//	Assignation.

///	---------------------------------------------------------- @class FUNCTION.S

		typedef typename Container::iterator		iterator;
		typedef typename Container::const_iterator	const_iterator;

		typename Container::iterator		begin(	void );
		typename Container::const_iterator	begin( void ) const;
		typename Container::iterator		end(	void );
		typename Container::const_iterator	end(	void ) const;
		typename Container::iterator		rbegin(	void ); // reverse begin()
		typename Container::const_iterator	rbegin(	void ) const; // reverse begin()
		typename Container::iterator		rend(	void ); // reverse end()
		typename Container::const_iterator	rend(	void ) const; // reverse end()

};	/*	MutantStack	*/

# include "../include/MutantStack.tpp"

#endif	/*	MUTANTSTACK_HPP_	*/
