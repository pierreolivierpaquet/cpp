/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:40:45 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/25 11:42:28 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		AANIMAL_HPP_
# define	AANIMAL_HPP_

# include <iostream>

class	Animal {
	protected:
		std::string	_type;
		Animal( void ); // Default.
		Animal( std::string type ); // Parameterized.

	public:
	/* Constructors */
		Animal( const Animal &rhs ); // Reference copy.

	/* Overload operands */
		Animal &operator=( const Animal &src ); // Assignation overload.
		
	/* Destructor */
		/// @note	Virtual keywords used to make sure that the proper
		///			destructor member is called (through a pointer).
		virtual ~Animal( void );

	/* Setter + Getter */
		std::string	getType( void ) const;

	/* Functions */
		virtual void	makeSound( void ) const = 0;
};	/*	Animal	*/

#endif	/*	AANIMAL_HPP_	*/
