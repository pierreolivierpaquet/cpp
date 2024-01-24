/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:08:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 13:47:07 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CAT_HPP_
# define	CAT_HPP_

# include "Animal.hpp"

class	Cat : public Animal {
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

	/* Setter + Getter */
		std::string	getType( void ) const;

	/* Functions */
		void	makeSound( void ) const ;
		
};	/*	Cat	*/

#endif	/*	CAT_HPP_	*/
