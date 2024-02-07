/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:12:58 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/06 18:58:54 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BUREAUCRAT_HPP_
# define	BUREAUCRAT_HPP_

# include	<iostream>

/******************************************************************************/

typedef short	grade_t;

# ifndef	DEFAULT_NAME
#  define	DEFAULT_NAME	"/* Nameless Bureaucrat */"
# endif	/*	DEFAULT_NAME	*/

/*	Minimum grade.	*/
#ifndef		DEFAULT_GRADE
# define	DEFAULT_GRADE	150
#endif	/*	DEFAULT_GRADE	*/

# ifndef	LOWEST_GRADE
#  define	LOWEST_GRADE	32767
# endif	/*	LOWEST_GRADE	*/

#define	RESET	"\033[0m"
#define	BOLD	"\033[1m"
#define	RED		"\033[91m"
#define	GREEN	"\033[32m"
#define	ORANGE	"\033[38;5;208m"

/******************************************************************************/

class	Bureaucrat {
	private:
		const std::string	_name;
		grade_t				_grade;

	public:
//	CONSTRUCTOR.S --------------------------------------------------------------
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &src );
		
		Bureaucrat( const std::string new_name );
		Bureaucrat( const grade_t new_grade );
		Bureaucrat( const std::string new_name, const grade_t new_grade );

//	DESTRUCTOR -----------------------------------------------------------------
		~Bureaucrat( void );

//	OVERLOAD OPERAND.S ---------------------------------------------------------
		Bureaucrat &operator=( const Bureaucrat &rhs );

//	FUNCTION.S -----------------------------------------------------------------
		void	incrementGrade	( void );
		void	incrementGrade	( grade_t amount );
		
		void	decrementGrade	( void );
		void	decrementGrade	( grade_t amount );

//	GETTER.S -------------------------------------------------------------------
		const std::string	getName	( void ) const;
		grade_t				getGrade( void ) const;

//	SETTER.S -------------------------------------------------------------------
		void	setGrade( grade_t new_grade );

//	NESTED CLASS.ES ------------------------------------------------------------
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};
		
};	//	Bureaucrat

std::ostream &operator<<( std::ostream &output, const Bureaucrat &data);

#endif	/*	BUREAUCRAT_HPP_	*/
