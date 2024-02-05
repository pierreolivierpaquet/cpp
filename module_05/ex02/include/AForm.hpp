/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/05 12:29:13 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		AFORM_HPP_
# define	AFORM_HPP_
// # pragma once
typedef short	grade_t;

# include "Bureaucrat.hpp"
class Bureaucrat;

# include <iostream>
# include <fstream>

typedef enum form_signature_state {
	AFORM_NOT_SIGNED,
	AFORM_SIGNED
} f_state;

# ifndef	DEFAULT_AFORM_NAME
#  define	DEFAULT_AFORM_NAME	"/* Nameless AForm */"
# endif	/*	DEFAULT_AFORM_NAME	*/

// # ifndef	ROBOTOMY_REQUEST_NAME
// #  define	ROBOTOMY_REQUEST_NAME	"Robotomy Request Form"
// # endif	/*	ROBOTOMY_REQUEST_NAME	*/

// # ifndef	PRESIDENTIAL_PARDON_NAME
// #  define	PRESIDENTIAL_PARDON_NAME	"Presidential Pardon Form"
// # endif	/*	PRESIDENTIAL_PARDON_NAME	*/

class	AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const grade_t		_gradeToExecute; // Requisite grade to execute.
		const grade_t		_gradeToSign; // Requisite grade to be signed.
	
	protected:
	
	public:
//	NESTED CLASS ---------------------------------------------------------------
	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what( void ) const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what( void ) const throw();
	};
	class AlreadySigned : public std::exception {
		public:
			virtual const char *what( void ) const throw();
	};
	class NotSigned : public std::exception {
		public:
			virtual const char *what( void ) const throw();
	};

//	CONSTRUCTOR.S --------------------------------------------------------------
		AForm(	void );
		AForm(	const AForm &src ); // Reference copy.
		AForm(	const std::string form_name ); // Parameterized.
		AForm(	const grade_t to_execute,
				const grade_t to_sign ); // Parameterized.
		AForm(	const std::string form_name,
				const grade_t to_execute,
				const grade_t to_sign ); // Full parameterized.

//	DESTRUCTOR.S ---------------------------------------------------------------
		virtual ~AForm( void );

//	OVERLOAD OPERAND.S ---------------------------------------------------------
		AForm &operator=( const AForm &rhs ); // Assignation overload.

//	FUNCTION.S -----------------------------------------------------------------
		virtual grade_t	checkGrade( const grade_t to_check ) const;
		virtual void	execute( const Bureaucrat &executor ) const = 0; // Abstract function.

//	SETTER.S -------------------------------------------------------------------
		virtual void	beSigned( const Bureaucrat &person );

//	GETTER.S -------------------------------------------------------------------
		const std::string	getName( void ) const;
		bool				isSigned( void ) const;
		grade_t		getGradeToExecute( void ) const;
		grade_t		getGradeToSign( void ) const;

};	//	AForm

std::ostream &operator<<( std::ostream &output, const AForm &data );

#endif	/*	AFORM_HPP_	*/
