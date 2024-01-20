/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:28:19 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/19 21:11:05 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main( int argc, char **argv ) {
	( void )argc;
	( void )argv;
	
	ClapTrap	Robot( "Bolt" );
	Robot.takeDamage( 9 );
	Robot.beRepaired( 20 );
	Robot.attack( "ZOMBIE" );
	Robot.takeDamage( 10 );
	Robot.beRepaired( 5 );
	Robot.takeDamage( 100 );
	Robot.attack( "Test attack" );
	Robot.beRepaired( 900000 );

	return ( EXIT_SUCCESS ); 
}
