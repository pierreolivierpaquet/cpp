/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:39:45 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/12 14:45:08 by ppaquet          ###   ########.fr       */
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

class	RPN : public std::stack< u_int32_t, std::vector< u_int32_t > > {
	private:
		RPN( void );	// Default constructor.
		long double	_result;
		std::string	_input;	// Program parameter.
		void	convert( void );

	public:
		RPN( std::string input );	// parameterized constructor.
		~RPN( void );

		void	calculate( void );

};	/*	RPN	*/

#endif	/*	RPN_HPP_	*/
