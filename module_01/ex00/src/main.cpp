/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:22:26 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/11 21:04:52 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

#ifndef		EMPTY
# define	EMPTY ""
#endif	/*	EMPTY	*/

#ifndef		SEPARATOR
# define	SEPARATOR "--------------------------------------------------------"
#endif	/*	SEPARATOR	*/

#ifndef		SUCCESS
# define	SUCCESS 0
#endif	/*	SUCCESS	*/

/******************************************************************************/

std::string	userInput( void ){
	std::string input = EMPTY;
	
	std::cout << "NEW ZOMBIE NAME > ";
	getline( std::cin, input );
	if (std::cin.eof()){
		std::cout << std::endl;
	}
	return (input);
};

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;
	Zombie *pointer;
	
	std::cout << SEPARATOR << std::endl;
	
	/*	Tests the basic functionality of the default constructor.
		Destructor will be called at the end of the current scope.	*/
	std::cout << "\t\t*** BASIC CONSTRUCTOR ***" << std::endl;
	Zombie basic( "ZOMBOY" );
	basic.announce();
	std::cout << SEPARATOR << std::endl;

	/*	Tests the randomChump function.
		Destructor will be called in this specific function scope, 	*/
	std::cout << "\t\t*** RANDOMCHUMP FUNCTION ***" << std::endl;
	randomChump( userInput() );
	std::cout << SEPARATOR << std::endl;
	
	/*	Tests the newZombie allocating function. A pointer to the Zombie
		instance is returned, so it's functionnalities can be used in current
		scope.	*/
	std::cout << "\t\t*** NEWZOMBIE FUNCTION ***" << std::endl;
	pointer = newZombie( userInput() );
	pointer->announce();
	delete pointer;
		
	return ( SUCCESS );
};
