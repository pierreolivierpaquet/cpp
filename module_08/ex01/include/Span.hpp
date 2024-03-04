/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:54:58 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/04 10:09:36 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SPAN_HPP_
# define	SPAN_HPP_

# include	<iostream>
# include	<list>
# include	<algorithm>
# include	<vector>

# include	<ctime> // gettime
# include	<cstdlib> // rand srand

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

		static bool	rand_seed;
		void	addNumber( u_int32_t number );
		u_int32_t	shortestSpan( void ) const;
		u_int32_t	longestSpan( void ) const;
		size_t	size( void ) const ;

		class NoSpan : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};

		class ExceedingNumber : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};

		template < typename T >
		void	addNumber( typename T::const_iterator it1, typename T::const_iterator it2 ) {
			std::list< long > buffer_list( it1, it2 );

			std::list< long >::iterator len; // iterator of the temporary list.
			u_int32_t add_N = 0; // counter of the nodes list.
			for (len = buffer_list.begin(); len != buffer_list.end(); len++) {
				if ((add_N + 1) + this->_list.size() > this->_N) {
					break;
				}
				add_N++;
			}
			if (add_N < buffer_list.size()) {
				this->_list.insert( this->_list.end(), buffer_list.begin(), len );
				throw( Span::ExceedingNumber() );
			} else if (this->_N != 0) {
				this->_list.insert( this->_list.end(), buffer_list.begin(), buffer_list.end() );
			}
			return ;
		}
		void	addNumber(u_int32_t N , u_int32_t max_value);
		void	print( void ) const;
};

#endif	/*	SPAN_HPP_	*/
