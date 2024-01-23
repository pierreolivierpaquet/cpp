/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:40:45 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/23 16:45:28 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ANIMAL_HPP_
# define	ANIMAL_HPP_

#include <iostream>

class Animal {
	protected:
		std::string	_type;

	public:
	/* Constructors */
		Animal( void ); // Default.
		Animal( std::string type ); // Parameterized.
		Animal( const Animal &rhs ); // Reference copy.

	/* Overload operands */
		Animal &operator=( const Animal &src ); // Assignation overload.
		
	/* Destructor */
		~Animal( void );

	/* SETTER+GETTER */
		std::string	getType( void ) const;

	/* Functions */
		virtual void	makeSound( void ) const;
}; /* Animal */

#endif	/*	ANIMAL_HPP_	*/
