/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:54:58 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/04 18:21:28 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SPAN_HPP_
# define	SPAN_HPP_

# include	<iostream>
# include	<list>		// list container
# include	<vector>	// vector container
# include	<algorithm>	// ::abs, sort()
# include	<limits>	// ::numeric_limits

# include	<ctime>		// time()
# include	<cstdlib>	// rand(), srand()
# include	<fstream>	// .open()

class	Span {
	private:
		Span( void );				// Default constructor.
		u_int32_t			_N;
		std::list< int >	_list;
		static bool			_rand_seed;

	public:
///	------------------------------------------------------- @class CONSTRUCTOR.S

		Span(	u_int32_t N_int );	// Parameterized.
		Span(	const Span &rhs );	// Reference copy.

///	-------------------------------------------------------- @class DESTRUCTOR.S

		~Span(	void );	// Default.

///	----------------------------------------------------------- @class OPERAND.S

		Span &operator=( const Span &rhs );	// Assignation overload.

///	----------------------------------------------------- @class NESTED CLASS.ES

		class	NoSpan : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};	/*	NoSpan	*/

		class	ExceedingNumber : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};	/*	ExceedingNumber	*/

///	---------------------------------------------------------- @class TEMPLATE.S

		template < typename T >
		void	addNumber(	typename T::const_iterator it1,
							typename T::const_iterator it2 ) {
			std::list< int > buffer_list( it1, it2 );

			std::list< int >::iterator len;	// iterator of the temporary list.
			u_int32_t add_N = 0;			// counter of the nodes list.
			for (len = buffer_list.begin(); len != buffer_list.end(); len++) {
				if ((add_N + 1) + this->_list.size() > this->_N) {
					break;
				}
				add_N++;
			}
			if (add_N < buffer_list.size()) {
				this->_list.insert(	this->_list.end(),
									buffer_list.begin(), len );
				throw( Span::ExceedingNumber() );
			} else if (this->_N != 0) {
				this->_list.insert( this->_list.end(), buffer_list.begin(),
									buffer_list.end() );
			}
			return ;
		}

///	------------------------------------------------------------ @class GETTER.S

		size_t				size(	 void ) const ;
		std::list< int >	getList( void ) const;
		u_int32_t			getN(	 void ) const;

///	---------------------------------------------------------- @class FUNCTION.S

		void	addNumber(	int number );
		void	addNumber(	u_int32_t N , int max_value );

		int		shortestSpan(	void ) const;
		int		longestSpan(	void ) const;

		void	print(	void ) const;
		void	print(	std::string fname ) const ;
};

#endif	/*	SPAN_HPP_	*/
