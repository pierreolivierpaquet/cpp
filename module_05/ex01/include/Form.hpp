/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/06 19:16:34 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FORM_HPP_
# define	FORM_HPP_

# include	"Bureaucrat.hpp"
// Forward declaration.
class Bureaucrat;

# include	<iostream>

typedef enum form_signature_state {
	FORM_NOT_SIGNED,
	FORM_SIGNED
} f_state;

typedef short	grade_t;

# ifndef	DEFAULT_FORM_NAME
#  define	DEFAULT_FORM_NAME	"/* Nameless Form */"
# endif	/*	DEFAULT_FORM_NAME	*/

class	Form {
	private:
		const	std::string	_name;
		bool				_signed;
		const	grade_t		_gradeToExecute;
		const	grade_t		_gradeToSign;

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
		Form(	void );
		Form(	const Form &src );
		Form(	const std::string form_name );
		Form(	const grade_t to_execute,
				const grade_t to_sign );
		Form(	const std::string form_name,
				const grade_t to_execute,
				const grade_t to_sign );

//	DESTRUCTOR.S ---------------------------------------------------------------
		~Form( void );

//	OVERLOAD OPERAND.S ---------------------------------------------------------
		Form &operator=( const Form &rhs );

//	FUNCTION.S -----------------------------------------------------------------
		grade_t	checkGrade( const grade_t to_check ) const;

//	SETTER.S -------------------------------------------------------------------
		void	beSigned( const Bureaucrat &person );

//	GETTER.S -------------------------------------------------------------------
		const std::string	getName(	void ) const;
		bool				isSigned(	void ) const;
		grade_t		getGradeToExecute(	void ) const;
		grade_t		getGradeToSign(		void ) const;
	
};	//	Form

std::ostream &operator<<( std::ostream &output, const Form &data );

#endif	/*	FORM_HPP_	*/
