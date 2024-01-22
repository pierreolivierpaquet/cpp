/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:28:19 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/22 10:11:28 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main( int argc, char **argv ) {
	( void )argc;
	( void )argv;
	
	ClapTrap	Robot( "Bolt" );
	Robot.takeDamage( 9 );
	Robot.beRepaired( 20 );
	Robot.takeDamage( 0 );
	Robot.attack( "ZOMBIE" );
	Robot.takeDamage( 10 );
	Robot.beRepaired( 5 );
	Robot.takeDamage( 100 );
	Robot.attack( "Test attack" );
	Robot.takeDamage( 1 );
	Robot.beRepaired( 900000 );

	ClapTrap	Copy( Robot );
	std::cout << Copy.getHitPoint() << std::endl;
	Copy.attack( "CopyTwo" );
	Copy.takeDamage( 1 );

	return ( EXIT_SUCCESS ); 
}
