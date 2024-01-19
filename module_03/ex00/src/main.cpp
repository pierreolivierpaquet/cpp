/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:28:19 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/19 12:09:20 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main( int argc, char **argv ) {
	( void )argc;
	( void )argv;
	
	ClapTrap	Sorcerer( "Harry Potter" );

	Sorcerer.attack( "Voldemort" );
	Sorcerer.attack( "Rusard" );
	Sorcerer.attack( "Lil Wayne" );
	Sorcerer.takeDamage( 6 );
	Sorcerer.beRepaired( 2 );
	Sorcerer.beRepaired( 2 );
	Sorcerer.takeDamage( 8 );
	Sorcerer.beRepaired( 1 );
	Sorcerer.beRepaired( 1 );
	Sorcerer.beRepaired( 1 );
	Sorcerer.beRepaired( 1 );
	Sorcerer.beRepaired( 1 );
	Sorcerer.beRepaired( 100 );
	Sorcerer.beRepaired( 1 );
	
	return ( EXIT_SUCCESS ); 
}
