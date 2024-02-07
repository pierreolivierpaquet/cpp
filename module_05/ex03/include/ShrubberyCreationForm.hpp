/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:41:22 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/06 21:57:15 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SHRUBBERYCREATIONFORM_HPP_
# define	SHRUBBERYCREATIONFORM_HPP_

# include "../include/AForm.hpp"

# ifndef	SHRUBBERY_NAME
#  define	SHRUBBERY_NAME		"Shrubbery Creation Form"
# endif	/*	SHRUBBERY_NAME	*/

# ifndef	SHRUBBERY_EXT
#  define	SHRUBBERY_EXT		"_shrubbery"
# endif	/*	SHRUBBERY_EXT	*/

# ifndef	SHRUBBERY_SIGN
#  define	SHRUBBERY_SIGN		145
# endif	/*	SHRUBBERY_SIGN	*/

# ifndef	SHRUBBERY_EXECUTE
#  define	SHRUBBERY_EXECUTE	137
# endif	/*	SHRUBBERY_EXECUTE	*/

# ifndef	TREE_AMOUNT
#  define	TREE_AMOUNT	3
# endif	/*	TREE_AMOUNT	*/

class ShrubberyCreationForm : public AForm {
	private:
		ShrubberyCreationForm( void ); // Default.
		const std::string	_target;

	protected:

	public:
//	CONSTRUCTOR.S --------------------------------------------------------------
		ShrubberyCreationForm(	const ShrubberyCreationForm &src );
		ShrubberyCreationForm(	const std::string target );

//	DESTRUCTOR -----------------------------------------------------------------
		~ShrubberyCreationForm( void );

//	OVERLOAD OPERAND.S ---------------------------------------------------------
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &rhs );

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

};	//	ShrubberyCreationForm

std::ostream &operator<<( std::ostream &output, const ShrubberyCreationForm& data );

#endif	/*	SHRUBBERYCREATIONFORM_HPP_	*/
