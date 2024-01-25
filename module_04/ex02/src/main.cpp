/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:21:08 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 21:44:52 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

#include "WrongCat.hpp"

#ifndef		EXIT_SUCCESS
# define	EXIT_SUCCESS	0
#endif	/*	EXIT_SUCCESS	*/

#ifndef		HERD_SIZE
# define	HERD_SIZE	2
#endif	/*	HERD_SIZE	*/

int	main( int argc, char **argv ) {
	( void )argc;
	( void )argv;
	
	/// @note	Default constructor is protected: No Animal can be instanciated.
	///			+ makeSound() is a pure virtual function.
	// Animal Impossible;
	Animal *Test = new Dog;
	std::cout << Test->getType() << std::endl;
	Test->makeSound();

	delete Test;

	Animal *Chabichou;
	Chabichou = new Cat;
	std::cout << Chabichou->getType() << std::endl;
	Chabichou->makeSound();

	delete Chabichou;
	return ( EXIT_SUCCESS );
}
