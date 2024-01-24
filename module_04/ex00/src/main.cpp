/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:21:08 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 12:29:28 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

#ifndef		EXIT_SUCCESS
# define	EXIT_SUCCESS	0
#endif	/*	EXIT_SUCCESS	*/

int	main( int argc, char **argv ) {
	( void )argc;
	( void )argv;

	const Animal* meta = new Animal;
	const Animal* j = new Dog;
	const Animal* i = new Cat;
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "-----------------------------------------------" << std::endl;
	
	const WrongAnimal	*Metal = NULL;
	const WrongAnimal	*Hi = NULL;

	Metal = new WrongAnimal;
	Hi = new WrongCat;

	std::cout << "WrongAnimal Metal Type > " << Metal->getType() << std::endl;
	std::cout << "Do you hear Metal? > ";
	Metal->makeSound();
	std::cout << "WrongAnimal Hi Type > " << Hi->getType() << std::endl;
	std::cout << "Do you hear Hi? > ";
	Hi->makeSound();

	delete Metal;
	delete Hi;

	return ( EXIT_SUCCESS );
}
