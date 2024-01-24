/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:08:45 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 13:48:55 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DOG_HPP_
# define	DOG_HPP_

# include "Animal.hpp"

class	Dog : public Animal {
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

	/* Setter + Getter */
		std::string	getType( void ) const;

	/* Functions */
		void	makeSound( void ) const;
};	/*	Dog	*/

#endif	/*	DOG_HPP_	*/