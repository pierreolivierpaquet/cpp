/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:21:08 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/26 14:47:17 by ppaquet          ###   ########.fr       */
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

#ifndef		SEPARATOR
# define	SEPARATOR	\
"------------------------------------------------------------------------------"
#endif	/*	SEPARATOR	*/

int	main( int argc, char **argv ) {
	( void )argc;
	( void )argv;
	
	/// @note	Default constructor is protected: No Animal can be instanciated.
	///			+ makeSound() is a pure virtual function.
	// Animal Impossible;

	std::cout << SEPARATOR << " [ NEW DOG / through Animal ]" << std::endl;
	Animal *Test = new Dog;
	std::cout << "<Test> getType: "<< Test->getType() << std::endl;
	std::cout << "<Test> makeSound: ";
	Test->makeSound();

	std::cout << SEPARATOR << " [ <Test> deletion ]" << std::endl;
	delete Test;

	std::cout << SEPARATOR << " [ NEW CAT <Another> / through Animal ]" << std::endl;
	Animal *Another = NULL;
	Another = new Cat;
	
	std::cout << "<Another> getType: "<< Another->getType() << std::endl;
	std::cout << "<Another> makeSound: ";
	Another->makeSound();

	std::cout << SEPARATOR << " [ <Another> deletion ]" << std::endl;
	delete Another;
	return ( EXIT_SUCCESS );
}
