/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:39:45 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/13 10:10:41 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RPN_HPP_
# define	RPN_HPP_

# include	<iostream>
# include	<sstream>		// istringstream
# include	<stack>
# include	<vector>
# include	<cstdlib>		// u_int32_t

# ifndef	EXIT_SUCCESS
#  define	EXIT_SUCCESS	0
# endif	/*	EXIT_SUCCESS	*/

# define	C_B_RED			"\033[1;31m"
# define	C_RST			"\033[0m"

# define	DIGIT_CHAR		"01923456789"
# define	ARITMETIC_CHAR	"+-/*"
# define	to_digit( c )	(c - 48)

# define	ERR_MSG			"\033[1;31merror\033[0m"
typedef enum {
	NOT_ARITMETIC,
	MULTIPLY = 42,
	ADD,
	SUBSTRACT = 45,
	DIVIDE = 47
}	e_aritmetic;

class	RPN : public std::stack< long double, std::vector< long double > > {
	private:
		RPN( void );	// Default constructor.
		long double	_result;
		std::string	_input;	// Program parameter.
		void	convert( void );
		void	process_aritmetic( e_aritmetic type, RPN &tmp_stack );
		void	addition(		RPN &tmp_stack );
		void	substraction(	RPN &tmp_stack );
		void	multiplication(	RPN &tmp_stack );
		void	division(		RPN &tmp_stack );

		// TEST DELETE
		template < typename OP >
		void	arithmetic_operation( RPN &tmp_stack, OP operation );
		//

	public:
		RPN( std::string input );	// parameterized constructor.
		~RPN( void );

		void	calculate( void );
		void	displayResult( void ) const;

};	/*	RPN	*/

#endif	/*	RPN_HPP_	*/
