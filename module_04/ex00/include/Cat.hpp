/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:08:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/23 17:29:44 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : public Animal {
	private:

	public:
	/* Constructors */
		Cat( void ); // Default.
		// Cat(  ); // Parameterized.
		Cat( const Cat &src ); // Reference copy.

	/* Overload operands */
		Cat &operator=( const Cat &rhs ); // Assignation overload.
		
	/* Destructor */
		~Cat( void );

	/* Functions */
		void	makeSound( void ) const ;
		
}; /* Cat */
