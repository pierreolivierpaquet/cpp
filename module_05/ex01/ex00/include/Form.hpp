/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/01 14:50:38 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FORM_HPP_
# define	FORM_HPP_

# include <iostream>

# include "Bureaucrat.hpp"

# ifndef	DEFAULT_FORM_NAME
#  define	DEFAULT_FORM_NAME	"/* Nameless Form */"
# endif	/*	DEFAULT_NAME	*/

# ifndef	FORM_SIGNED
#  define	FORM_SIGNED		1
# endif	/*	FORM_SIGNED	*/

# ifndef	FORM_NOT_SIGNED
#  define	FORM_NOT_SIGNED	0
# endif	/*	FORM_NOT_SIGNED	*/

class	Form {
	private:
		const	std::string	_name;
		bool				_signed;
		const	grade_t		_gradeToExecute; // Requisite grade to execute.
		const	grade_t		_gradeToSign; // Requisite grade to be signed.
		
	protected:
	
	public:
//	NESTED CLASS
	class GradeTooHighException : public std::exception {
		virtual const char *what( void ) const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char *what( void ) const throw();
	};

//	CONSTRUCTOR.S
	Form(	void );
	Form(	const Form &src ); // Reference copy.
	Form(	const std::string form_name ); // Parameterized.
	Form(	const grade_t to_execute,
			const grade_t to_sign ); // Parameterized.
	Form(	const std::string form_name,
			const grade_t to_execute,
			const grade_t to_sign ); // Full parameterized.

//	DESTRUCTOR.S
	~Form( void );

//	OVERLOAD OPERAND.S
	Form &operator=( const Form &rhs ); // Assignation overload.

//	FUNCTION.S

//	SETTER.S
	void	beSigned( const Bureaucrat &person );

//	GETTER.S
	const std::string	getName( void ) const;
	bool				isSigned( void ) const;
	const grade_t		getGradeToExecute( void ) const;
	const grade_t		getGradeToSign( void ) const;
	
};	//	Form

std::ostream &operator<<( std::ostream &output, const Form &data );

#endif	/*	FORM_HPP_	*/
