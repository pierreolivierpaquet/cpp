/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:41:24 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/05 14:55:13 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ROBOTOMYREQUEST_HPP_
# define	ROBOTOMYREQUEST_HPP_

# include	"../include/AForm.hpp"

# ifndef	ROBOTOMY_NAME
#  define	ROBOTOMY_NAME		"Robotomy Request Form"
# endif	/*	ROBOTOMY_NAME	*/

# ifndef	ROBOTOMY_SIGN
#  define	ROBOTOMY_SIGN		72
# endif	/*	ROBOTOMY_SIGN	*/

# ifndef	ROBOTOMY_EXECUTE
#  define	ROBOTOMY_EXECUTE	45
# endif	/*	ROBOTOMY_EXECUTE	*/



class RobotomyRequestForm : public AForm {
	private:
		RobotomyRequestForm( void ); // Default.
		const std::string	_target;
		static bool			_robotomized;

	protected:

	public:
//	CONSTRUCTOR.S --------------------------------------------------------------
		RobotomyRequestForm(	const RobotomyRequestForm &src ); // Reference copy.
		RobotomyRequestForm(	const std::string target ); // Parameterized.

//	DESTRUCTOR -----------------------------------------------------------------
		~RobotomyRequestForm( void );

//	OVERLOAD OPERAND.S ---------------------------------------------------------
		RobotomyRequestForm &operator=( const RobotomyRequestForm &rhs );

//	NESTED CLASS ---------------------------------------------------------------
		class FailedExecution : public std::exception {
			public:
				const char *what( void ) const throw();
		};

//	FUNCTION.S -----------------------------------------------------------------
		void	execute( const Bureaucrat &executor ) const;

//	SETTER.S -------------------------------------------------------------------

//	GETTER.S -------------------------------------------------------------------
		std::string	getTarget( void ) const;

};	/*	RobotomyRequestForm	*/

std::ostream &operator<<( std::ostream &output, const RobotomyRequestForm& data );

#endif	/*	ROBOTOMYREQUEST_HPP_	*/