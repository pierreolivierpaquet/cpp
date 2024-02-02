/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/02 12:18:52 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		AFORM_HPP_
# define	AFORM_HPP_

# include "Bureaucrat.hpp"
class Bureaucrat;

# include <iostream>

typedef enum form_signature_state {
	FORM_NOT_SIGNED,
	FORM_SIGNED
} f_state;

typedef short	grade_t;

# ifndef	DEFAULT_FORM_NAME
#  define	DEFAULT_FORM_NAME	"/* Nameless Form */"
# endif	/*	DEFAULT_NAME	*/

class	AForm {
	private:
		const	std::string	_name;
		bool				_signed;
		const	grade_t		_gradeToExecute; // Requisite grade to execute.
		const	grade_t		_gradeToSign; // Requisite grade to be signed.
		
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

//	CONSTRUCTOR.S --------------------------------------------------------------
		AForm(	void );
		AForm(	const Form &src ); // Reference copy.
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
