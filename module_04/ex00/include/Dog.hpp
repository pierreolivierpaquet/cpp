/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:08:45 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/23 17:46:03 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : public Animal {
	private:

	public:
	/* Constructors */
		Dog( void ); // Default.
		// Dog(  ); // Parameterized.
		Dog( const Dog &rhs ); // Reference copy.

	/* Overload operands */
		Dog &operator=( const Dog &src ); // Assignation overload.
		
	/* Destructor */
		~Dog( void );

	/* Functions */
		void	makeSound( void ) const;
}; /* Dog */
