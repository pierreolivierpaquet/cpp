/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:21:08 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/26 14:35:50 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

#include "WrongCat.hpp"

#ifndef		EXIT_SUCCESS
# define	EXIT_SUCCESS	0
#endif	/*	EXIT_SUCCESS	*/

#ifndef		HERD_SIZE
# define	HERD_SIZE	10
#endif	/*	HERD_SIZE	*/

#ifndef		SEPARATOR
# define	SEPARATOR	\
"------------------------------------------------------------------------------"
#endif	/*	SEPARATOR	*/

/******************************************************************************/

void	print_o( std::string to_print, bool nl ) {
	std::cout	<< to_print;
	if (nl == true){
		std::cout << std::endl;
	}
	return ;
}

void	mandatory_main( void ) {
	
	Animal *Herd[ HERD_SIZE ];
	
	print_o( "\n\033[32m\033[1mMANDATORY TEST\033[0m\n", true );
	for (size_t i = 0; i < HERD_SIZE * 0.5; i++) {
		print_o( std::string(SEPARATOR) + "[ NEW CAT ] ", false );
		std::cout << (i + 1) << std::endl;
		Herd[ i ] = new Cat;
	}
	for (size_t i = HERD_SIZE * 0.5; i < HERD_SIZE; i++){
		print_o( std::string(SEPARATOR) + "[ NEW DOG ] ", false );
		std::cout << (i + 1) << std::endl;
		Herd[ i ] = new Dog;
	}
	print_o( std::string(SEPARATOR) + "[ MAKESOUND ]", true );
	for (size_t i = 0; i < HERD_SIZE; i++){
		std::cout << (i + 1) << "\t ";
		print_o( "Animal getType: " + Herd[ i ]->getType() + " -> makeSound: ", false );
		Herd[ i ]->makeSound();
	}
	
	for (size_t i = 0; i < HERD_SIZE; ++i) {
		print_o( std::string(SEPARATOR) + "[ " + Herd[ i ]->getType() + " deletion ] ", false );
		std::cout << (i + 1) << std::endl;
		delete Herd[ i ];
	}
	return ;
}

void	additional( void ) {
	
	print_o( "\n\033[32m\033[1mADDITIONAL TEST\033[0m\n", true );
	
	print_o( std::string(SEPARATOR) + "[ NEW CAT <First> ]", true );
	Cat *First = new Cat;
	First->setIdeas( "FIRST IDEA." );
	First->setIdeas( "SECOND IDEA." );
	First->setIdeas( "THIRD IDEA.");
	First->setIdeas( "RANDOM IDEA AT INDEX 90", 90 );
	
	print_o( std::string(SEPARATOR) + "[ CAT <First> getIdeas ]", true );
	for (size_t i = 0; i < First->getiBrain(); i++){
		std::cout <<  "<First>'s idea at Brain index #" << i << ": ";
		print_o( First->getIdeas( i ), true );
	}
	print_o( "<First>'s random idea at Brain index #90: ", false );
	print_o( First->getIdeas( 90 ), true );
	
	print_o( std::string(SEPARATOR) + "[ NEW CAT <Second> ]", true );
	Cat *Second = new Cat;
	*Second = *First;
	
	print_o( std::string(SEPARATOR) + "[ CAT <Second> getIdeas ]", true );
	for (size_t i = 0; i < Second->getiBrain(); i++){
		std::cout <<  "<Second>'s idea at Brain index #" << i << ": ";
		std::cout << Second->getIdeas( i ) << std::endl;
	}
	print_o( "\t*** <First> CHANGING IDEAS ***", true );
	First->setIdeas( "CHANGED MY MIND!", 0 );
	First->setIdeas( "NOT SO RANDOM IDEA HERE ANYMORE.", 90 );
	print_o( "<Second>'s idea at index #0: ", false );
	print_o( Second->getIdeas( 0 ), true );
	print_o( "<Second>'s idea at Brain index #90: ", false );
	print_o( Second->getIdeas( 90 ), true );

	print_o( "<First>'s idea at index #0: ", false );
	print_o( First->getIdeas( 0 ), true );
	print_o( "<First>'s idea at Brain index #90: ", false );
	print_o( First->getIdeas( 90 ), true );

	print_o( std::string(SEPARATOR) + "[ CAT <First> deletion ]", true );
	delete First;
	print_o( std::string(SEPARATOR) + "[ CAT <Second> deletion ]", true );
	delete Second;
	
	print_o( "\n\033[32m\033[1mANOTHER TEST\033[0m\n", true );
		
	print_o( std::string(SEPARATOR) + "[ NEW CAT <Original> ]", true );
	Cat	Original;
	Original.setIdeas( "HELLO :) !", 99 );
	
	print_o( std::string(SEPARATOR) + "[ NEW CAT <Reference> ]", true );
	Cat	Reference( Original );
	
	print_o( "\t*** <Original> CHANGING IDEA ***", true );
	Original.setIdeas( "...CIAO :(", 99 );
	print_o( std::string(SEPARATOR) + "[ CAT getIdeas ]", true );
	

	print_o( "<Original>'s idea at Brain index #99: " + Original.getIdeas( 99 ), true );
	print_o( "<Reference>'s idea at Brain index #99: " + Reference.getIdeas( 99 ), true );
	print_o( std::string(SEPARATOR), true);
}

int	main( int argc, char **argv ) {
	( void )argc;
	( void )argv;

	mandatory_main();
	additional();

	return ( EXIT_SUCCESS );
}
