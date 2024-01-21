/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:20:39 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/20 22:18:49 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;

	ScavTrap Destroid("Pendulum");
	Destroid.attack( "KickDrum" );
	Destroid.takeDamage( 50 );
	Destroid.beRepaired( 25 );
	
	ClapTrap Soundwave( "PicoHertz" );
	Soundwave.attack( "SubWoofer" );
	Soundwave.takeDamage( 5 );

	return ( 0 );
}
