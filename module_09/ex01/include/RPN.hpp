/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:39:45 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/14 09:17:43 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RPN_HPP_
# define	RPN_HPP_

# include	<iostream>
# include	<sstream>		// istringstream
# include	<stack>
// # include	<vector>
# include	<list>
# include	<cstdlib>		// u_int32_t

///	----------------------------------------------- @section MACRO.S - TYPEDEF.S

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
}	e_arithmetic;

typedef long double l_dbl_t;

///	---------------------------------------------------------- @section CLASSE.S

class	RPN : public std::stack< l_dbl_t, std::list< l_dbl_t > > {
	private:
		RPN( void );
		l_dbl_t		_result;
		std::string	_input;

		void		convert( void );
		void		process_arithmetic( e_arithmetic type, RPN &tmp_stack );

		template	< typename OP >
		void		arithmetic_operation( RPN &tmp_stack, OP operation );

	public:
///	------------------------------------------------- @class SETTER.S - GETTER.S

		void		setInput( std::string input );

		std::string	getInput( void ) const;
		l_dbl_t		getResult( void ) const;

///	---------------------------------------- @class CONSTRUCTOR.S - DESTRUCTOR.S

		RPN(	const RPN &rhs );
		RPN(	std::string input );
		~RPN(	void );

///	------------------------------------------------- @class OPERATOR.S OVERLOAD

		RPN		&operator=( const RPN &rhs );

///	---------------------------------------------------------- @class FUNCTION.S

		void	calculate(		void );
		void	displayResult(	void ) const;

};	/*	RPN	*/

#endif	/*	RPN_HPP_	*/
