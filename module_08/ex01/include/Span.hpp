/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:54:58 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/01 16:08:30 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SPAN_HPP_
# define	SPAN_HPP_

# include	<iostream>
# include	<list>
# include	<algorithm>
# include	<vector>

# ifndef	UINT32_MAX
#  define	UINT32_MAX	4294967295
# endif	/*	UINT32_MAX	*/

class	Span{
	private:
		Span( void );
		u_int32_t				_N;
		std::list< u_int32_t >	_list;

	public:
		Span( u_int32_t N_int );
		~Span( void );

		void	addNumber( u_int32_t number );
		u_int32_t	shortestSpan( void ) const;
		u_int32_t	longestSpan( void ) const;
		size_t	size( void ) const ;

		class NoSpan : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};

		template < typename T >
		void	addNumber( typename T::const_iterator it1, typename T::const_iterator it2 ){
	std::list< int > buffer_list( it1, it2 );

	this->_list.insert( this->_list.end(), buffer_list.begin(), buffer_list.end() );
	}
};

#endif	/*	SPAN_HPP_	*/
