/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:19:54 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/29 13:43:16 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WRONGCAT_HPP_
# define	WRONGCAT_HPP_

# include	"WrongAnimal.hpp"
# include <iostream>

class	WrongCat : public WrongAnimal {
	public:
	/* Constructors */
		WrongCat( void ); // Default.
		// WrongCat(  ); // Parameterized.
		WrongCat( const WrongCat &rhs ); // Reference copy.
		
	/* Overload operands */
		WrongCat &operator=( const WrongCat &src ); // Assignation overload.
		
	/* Destructor */
		~WrongCat( void );

	/* Setter + Getter */
		std::string	getType( void ) const;

	/* Functions */
		void makeSound( void ) const;

};	/*	WrongCat	*/

#endif	/*	WRONGCAT_HPP_	*/
