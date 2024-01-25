/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:19:52 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 14:04:33 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WRONGANIMAL_HPP_
# define	WRONGANIMAL_HPP_

# include	<iostream>

class	WrongAnimal {
	protected:
		std::string	_type;
		
	public:
	/* Constructors */
		WrongAnimal( void ); // Default.
		WrongAnimal( std::string type ); // Parameterized.
		WrongAnimal( const WrongAnimal &rhs ); // Reference copy.
		
	/* Overload operands */
		WrongAnimal &operator=( const WrongAnimal &src ); // Assignation overload.
		
	/* Destructor */
		~WrongAnimal( void );

	/* Setter + Getter */
		std::string	getType( void ) const;

	/* Functions */
		void makeSound( void ) const;

};	/*	WrongAnimal	*/

#endif	/*	WRONGANIMAL_HPP_	*/
