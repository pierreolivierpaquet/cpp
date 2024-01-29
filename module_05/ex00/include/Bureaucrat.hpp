/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:12:58 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/29 10:32:47 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BUREAUCRAT_HPP_
# define	BUREAUCRAT_HPP_

# include <iostream>

class	Bureaucrat {
	private:
		std::string _name;
		int8_t		_grade;

	public:
	/* Constructors */
		Bureaucrat( void ); // Default.
		Bureaucrat( const Bureaucrat &src ); // Reference copy.
		Bureaucrat( const std::string name ); // Parameterized.

	/* Destructor */
		~Bureaucrat( void ); // Destructor.

		Bureaucrat &operator=( const Bureaucrat &rhs ); // Assignation overload.
	
	/* Function(s) */
		void	getName( void ) const;
		
};	/*	Bureaucrat	*/

#endif	/*	BUREAUCRAT_HPP_	*/
