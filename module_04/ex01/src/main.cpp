/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:21:08 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 21:02:02 by ppaquet          ###   ########.fr       */
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

void	mandatory_main( void ) {
	
	Animal *Herd[ HERD_SIZE ];
	for (size_t i = 0; i < HERD_SIZE * 0.5; i++) {
		Herd[ i ] = new Cat;
	}
	for (size_t i = HERD_SIZE * 0.5; i < HERD_SIZE; i++){
		Herd[ i ] = new Dog;
	}
	for (size_t i = 0; i < HERD_SIZE; i++){
		Herd[ i ]->makeSound();
	}
	for (size_t i = 0; i < HERD_SIZE; ++i) {
		delete Herd[ i ];
	}
}

int	main( int argc, char **argv ) {
	( void )argc;
	( void )argv;

	// mandatory_main();

	Cat *First = new Cat;
	First->setIdeas( "FIRST IDEA." );
	First->setIdeas( "SECOND IDEA." );
	First->setIdeas( "THIRD IDEA.");
	for (size_t i = 0; i < First->getiBrain(); i++){
		std::cout << First->getIdeas( i ) << std::endl;
	}
	Cat *Second = new Cat;
	*Second = *First;
	First->setIdeas( "CHANGED MY MIND!", 0 );
	for (size_t i = 0; i < Second->getiBrain(); i++){
		std::cout << Second->getIdeas( i ) << std::endl;
	}
	std::cout << "-----------------------------------------------" << std::endl;
	for (size_t i = 0; i < First->getiBrain(); i++){
		std::cout << First->getIdeas( i ) << std::endl;
	}
	
	delete First;
	delete Second;
	
	std::cout << "-----------------------------------------------" << std::endl;
	Cat	Chabichou;
	Chabichou.setIdeas( "YOOOOO!", 99 );
	Cat	Ref( Chabichou );
	std::cout << Chabichou.getIdeas( 99 ) << std::endl;
	Chabichou.setIdeas( "BYEE!", 99 );
	std::cout << Chabichou.getIdeas( 99 ) << std::endl;
	std::cout << Ref.getIdeas( 99 ) << std::endl;
	
	return ( EXIT_SUCCESS );
}
