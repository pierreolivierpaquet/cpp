/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:12:58 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/30 17:08:16 by ppaquet          ###   ########.fr       */
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
				const char *what( void ) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what( void ) const throw();
		};
		
};	/*	Bureaucrat	*/

std::ostream &operator<<( std::ostream &output, const Bureaucrat &data);

#endif	/*	BUREAUCRAT_HPP_	*/
