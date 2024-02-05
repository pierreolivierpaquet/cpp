/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:12:58 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/01 10:23:43 by ppaquet          ###   ########.fr       */
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

/*	Lowest grade.	*/
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
	/* Constructors */
		Bureaucrat( void ); // Default.
		Bureaucrat( const Bureaucrat &src ); // Reference copy.
		
		Bureaucrat( const std::string new_name ); // Parameterized.
		Bureaucrat( const grade_t new_grade );
		Bureaucrat( const std::string new_name, const grade_t new_grade ); // Full parameterized.

	/* Destructor */
		~Bureaucrat( void ); // Destructor.

		Bureaucrat &operator=( const Bureaucrat &rhs ); // Assignation overload.

	/* Function(s) */
		const std::string	getName	( void ) const;
		grade_t				getGrade( void ) const;

		void	setGrade		( grade_t new_grade );
		void	incrementGrade	( void );
		void	incrementGrade	( grade_t amount ); // Substracts <amount>.
		void	decrementGrade	( void );
		void	decrementGrade	( grade_t amount ); // Adds <amount>.

	/* Exceptions */
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};
		
};	/*	Bureaucrat	*/

std::ostream &operator<<( std::ostream &output, const Bureaucrat &data);

#endif	/*	BUREAUCRAT_HPP_	*/