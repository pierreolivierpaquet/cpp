/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:25 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/06 21:57:43 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		INTERN_HPP_
# define	INTERN_HPP_

# include	<iostream>

# include	"AForm.hpp"
# include	"ShrubberyCreationForm.hpp"
# include	"RobotomyRequestForm.hpp"
# include	"PresidentialPardonForm.hpp"

# ifndef	TASK_AMOUNT
#  define	TASK_AMOUNT	3
# endif	/*	TASK_AMOUNT	*/

enum e_tasks{
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENTIAL	
};

# ifndef	SHRUBBERY_ID
#  define	SHRUBBERY_ID	"shrubbery creation"
# endif	/*	SHRUBBERY_ID	*/

# ifndef	ROBOTOMY_ID
#  define	ROBOTOMY_ID		"robotomy request"
# endif	/*	ROBOTOMY_ID	*/

# ifndef	PRESIDENTIAL_ID
#  define	PRESIDENTIAL_ID	"presidential pardon"
# endif	/*	PRESIDENTIAL_ID	*/

class	Intern {
	private:
		static const int	_nTask;
	
		AForm	*_makeShrubbery		( const std::string target ) const;
		AForm	*_makeRobotomy		( const std::string target ) const;
		AForm	*_makePresidential	( const std::string target ) const;

		typedef AForm	*(Intern::*task)( const std::string target ) const;		
		task		_formList[ TASK_AMOUNT ];
		
		std::string	_formIdentifier[ TASK_AMOUNT ];

	protected:
		// N/A

	public:
//	CONSTRUCOR.S
		Intern( void );
		Intern( const Intern &src );
		
//	DESTRUCTOR.S
		~Intern( void );

//	OVERLOAD OPERAND.S
		Intern &operator=( const Intern &rhs );

//	FUNCTION.S
		AForm *makeForm( std::string form_name, std::string target ) const;
};	//	Intern

#endif	/*	INTERN_HPP_	*/