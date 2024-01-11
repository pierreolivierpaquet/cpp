/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:39:17 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/11 13:17:12 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# ifndef COMMENT_AMOUNT
#  define COMMENT_AMOUNT 4
# endif /* COMMENT_AMOUNT */

# ifndef DEBUG
#  define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !"
# endif /* DEBUG */

# ifndef DEBUG_FLAG
#  define DEBUG_FLAG "DEBUG"
# endif /* DEBUG_FLAG */

# ifndef INFO
#  define INFO "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !"
# endif /* INFO */

# ifndef INFO_FLAG
#  define INFO_FLAG "INFO"
# endif /*  */

# ifndef WARNING
#  define WARNING "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
# endif /* WARNING */

# ifndef WARNING_FLAG
#  define WARNING_FLAG "WARNING"
# endif /* WARNING_FLAG */

# ifndef ERROR
#  define ERROR "This is unacceptable ! I want to speak to the manager now."
# endif /* ERROR */

# ifndef ERROR_FLAG
#  define ERROR_FLAG "ERROR"
# endif /* ERROR_FLAG */

/******************************************************************************/

class Harl {
	private:
		void	debug	( void );
		void	info	( void );
		void	warning	( void );
		void	error	( void );

		typedef	void (Harl::*comment)( void );
		comment displayComplain	[ COMMENT_AMOUNT ];

		std::string	commentFlag	[ COMMENT_AMOUNT ];

	public:
		Harl	( void );
		~Harl	( void );

		void complain( std::string level );
};

#endif /* HARL_HPP */