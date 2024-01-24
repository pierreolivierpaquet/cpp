/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:08:45 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 16:13:03 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DOG_HPP_
# define	DOG_HPP_

# include "Animal.hpp"
# include "../include/Brain.hpp"

class	Dog : public Animal {
	private:
		Brain	*_brain;

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
		void	setIdeas( const std::string idea );
		void	setIdeas( const std::string idea, const size_t index);
		const std::string getIdeas( const size_t index ) const;	

	/* Functions */
		void	makeSound( void ) const;

};	/*	Dog	*/

#endif	/*	DOG_HPP_	*/
