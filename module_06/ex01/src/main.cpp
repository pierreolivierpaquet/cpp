/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:00:46 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 08:14:20 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"

/******************************************************************************/

int	main( int argc, char **argv ) {
	( void )argc;
	( void )argv;

	Data Foo = { "Foo", 42, 1000 };
	Data *FooTwo = NULL;
	uintptr_t	Bar = 0;

	std::cout << "Foo.name = " << Foo.name << std::endl;
	std::cout << "Foo.age = " << Foo.age << std::endl;
	std::cout << "Foo.money = " << Foo.money << std::endl << std::endl;
	
	std::cout << "[ uintptr_t 'Bar' (unsigned long to store pointer adress) ]" << std::endl;
	std::cout << "'Bar' BEFORE 'Foo' SERIALIZATION: " << Bar << std::endl;
	Bar = ser::serialize( &Foo );
	std::cout << "'Bar' AFTER 'Foo' SERIALIZATION: " << Bar << std::endl;
	
	std::cout << "'FooTwo' (pointer to a 'Data' object) BEFORE DESERIALIZATION: " << FooTwo << std::endl;
	FooTwo = ser::deserialize( Bar );

//	Apply changes to origin Data instance
	// Foo.age = 43;
	// Foo.name = "Koo";
	// Foo.money = -5000;

	std::cout << "'FooTwo' AFTER DESERIALIZATION: " << FooTwo << std::endl << std::endl;
	std::cout << "FooTwo->name = " << FooTwo->name << std::endl;
	std::cout << "FooTwo->age = " << FooTwo->age << std::endl;
	std::cout << "FooTwo->money = " << FooTwo->money << std::endl;

	return ( EXIT_SUCCESS );
}
