/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:41:22 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/02 12:48:38 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SHRUBBERYCREATIONFORM_HPP_
# define	SHRUBBERYCREATIONFORM_HPP_

# include "../include/AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		ShrubberyCreationForm( void ); // Default.
		const std::string	target;

	protected:

	public:
//	CONSTRUCTOR.S
		ShrubberyCreationForm(	const ShrubberyCreationForm &src ); // Reference copy.
		ShrubberyCreationForm(	const std::string target ); // Parameterized.								const grade_t to_sign); // Fully parameterized.

//	DESTRUCTOR
		~ShrubberyCreationForm( void );

//	NESTED CLASS

//	FUNCTION.S

//	SETTER.S

//	GETTER.S

}

#endif	/*	SHRUBBERYCREATIONFORM_HPP_	*/