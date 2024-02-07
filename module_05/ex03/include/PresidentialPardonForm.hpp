/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:41:26 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/06 21:57:30 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PRESIDENTIALPARDONFORM_HPP_
# define	PRESIDENTIALPARDONFORM_HPP_

# include "../include/AForm.hpp"

# ifndef	PRESIDENTIAL_NAME
#  define	PRESIDENTIAL_NAME		"Presidential Pardon Form"
# endif	/*	PRESIDENTIAL_NAME	*/

# ifndef	PRESIDENTIAL_SIGN
#  define	PRESIDENTIAL_SIGN		25
# endif	/*	PRESIDENTIAL_SIGN	*/

# ifndef	PRESIDENTIAL_EXECUTE
#  define	PRESIDENTIAL_EXECUTE	5
# endif	/*	PRESIDENTIAL_EXECUTE	*/

class PresidentialPardonForm : public AForm {
	private:
		PresidentialPardonForm( void ); // Default.
		const std::string	_target;

	protected:

	public:
//	CONSTRUCTOR.S --------------------------------------------------------------
		PresidentialPardonForm(	const PresidentialPardonForm &src ); // Reference copy.
		PresidentialPardonForm(	const std::string target ); // Parameterized.

//	DESTRUCTOR -----------------------------------------------------------------
		~PresidentialPardonForm( void );

//	OVERLOAD OPERAND.S ---------------------------------------------------------
		PresidentialPardonForm &operator=( const PresidentialPardonForm &rhs );

//	NESTED CLASS ---------------------------------------------------------------

//	FUNCTION.S -----------------------------------------------------------------
		void	execute( const Bureaucrat &executor ) const;

//	SETTER.S -------------------------------------------------------------------

//	GETTER.S -------------------------------------------------------------------
		std::string	getTarget( void ) const;

};	//	PresidentialPardonForm

std::ostream &operator<<( std::ostream &output, const PresidentialPardonForm& data );

#endif	/*	PRESIDENTIALPARDONFORM_HPP_	*/
