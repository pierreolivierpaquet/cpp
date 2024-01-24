/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:08:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 16:14:36 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CAT_HPP_
# define	CAT_HPP_

# include "Animal.hpp"
# include "../include/Brain.hpp"

class	Cat : public Animal {
	private:
		Brain *_brain;

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
		void	setIdeas( const std::string idea );
		void	setIdeas( const std::string idea, const size_t index);
		const std::string getIdeas( const size_t index ) const;	

	/* Functions */
		void	makeSound( void ) const ;
		
};	/*	Cat	*/

#endif	/*	CAT_HPP_	*/
