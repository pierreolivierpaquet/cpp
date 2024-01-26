/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:21:08 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/26 12:49:11 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

#ifndef		EXIT_SUCCESS
# define	EXIT_SUCCESS	0
#endif	/*	EXIT_SUCCESS	*/

#ifndef		SEPARATOR
# define	SEPARATOR	\
"------------------------------------------------------------------------------"
#endif	/*	SEPARATOR	*/

/******************************************************************************/

/// @brief Prints the string(s) passed as parameters.
void	print_o( std::string to_print, bool nl) {
	std::cout << to_print;
	if (nl){
		std::cout << std::endl;
	}
	return ;
}

void	animal( void ) {
	print_o("\033[32m\033[1m[ ANIMAL TESTS ]\033[0m", true );
	print_o( std::string(SEPARATOR) + "[ ANIMAL <meta> ]", true) ;
	const Animal* meta = new Animal;
	print_o( std::string(SEPARATOR) + "[ DOG <j> / through Animal ]", true) ;
	const Animal* j = new Dog;
	print_o( std::string(SEPARATOR) + "[ CAT <i> / through Animal ]", true) ;
	const Animal* i = new Cat;
	
	print_o( SEPARATOR, true );

	print_o( "<j> getType: " + j->getType(), true );
	print_o( "<i> getType: " + i->getType() + "\n" + SEPARATOR, true );
	print_o( "<j> makeSound: ", false);
	j->makeSound(); // Will output the Dog sound ("Wouf Wouf.")
	print_o( "<i> makeSound: ", false);
	i->makeSound(); // Will output the cat sound ("Meow meow.")
	print_o( "<meta> makeSound: ", false);
	meta->makeSound();

	print_o( std::string(SEPARATOR) + "[ ANIMAL <meta> deletion ]", true );
	delete meta;
	print_o( std::string(SEPARATOR) + "[ DOG <j> deletion ]", true );
	delete j;
	print_o( std::string(SEPARATOR) + "[ CAT <i> deletion ]", true );
	delete i;
}

void	wrong_animal( void ) {
	print_o( std::string("\n") + "\033[31m\033[1m[ WRONG TESTS ]\033[0m" "\n", true );
	
	const WrongAnimal	*Metal = NULL;
	const WrongAnimal	*Hi = NULL;

	print_o( std::string(SEPARATOR) + "[ WRONGCAT <Hi> / through WRONGANIMAL]", true );
	Hi = new WrongCat;
	print_o( std::string(SEPARATOR) + "[ WRONGANIMAL <Metal> ]", true );
	Metal = new WrongAnimal;

	print_o( std::string(SEPARATOR), true );
	print_o( "<Metal> getType: " + Metal->getType(), true );
	print_o( "<Metal> makeSound: ", false);
	Metal->makeSound();
	print_o( "<Hi> getType: " + Hi->getType(), true );
	print_o( "<Hi> makeSound: ", false);
	Hi->makeSound();

	print_o( std::string(SEPARATOR) + "[ WRONGANIMAL <Metal> deletion ]", true );
	delete Metal;
	print_o( std::string(SEPARATOR) + "[ WRONGCAT <Hi> deletion ]", true );
	delete Hi;
	print_o( "", true );

	return ;
}

int	main( int argc, char **argv ) {
	( void )argc;
	( void )argv;

	animal();
	wrong_animal();

	return ( EXIT_SUCCESS );
}
