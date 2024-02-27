/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:39:16 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/27 09:57:36 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ARRAY_HPP_
# define	ARRAY_HPP_

# ifndef	EXIT_SUCCESS
#  define	EXIT_SUCCESS	0
# endif	/*	EXIT_SUCCESS	*/

# include	<iostream>

/// --------------------------------------------------------------- @class ARRAY
template < typename T >
class	Array {
	private:
		uint32_t	_size;		//	Total amount of T element(s).
		T			*_element;	//	Array of T element(s).

	public:
		Array(	void );		//	Creates en empty array
		Array(	uint32_t N );	//	Creates an array of size N
		Array(	const Array &rhs );	//	Coplien form.
		Array	&operator=(		const Array &rhs );	//	Coplien form
		T		&operator[](	const uint32_t index ) const; // operand overload
		~Array(	void );

//	GETTER.S -------------------------------------------------------------------

		uint32_t	size(	void ) const;
		T			*getElement(	void ) const;
	
//	NESTED CLASS.ES ------------------------------------------------------------

		class BadArrayIndex : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};

};	/*	Array	*/

# include "Array.tpp"

#endif	/*	ARRAY_HPP_	*/
