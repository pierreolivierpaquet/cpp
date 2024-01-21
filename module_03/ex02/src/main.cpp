/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:36:09 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/21 14:17:39 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;

	FragTrap	Hero( "Eleven" );
	Hero.attack( "Vecna" );
	Hero.highFivesGuys();
	Hero.takeDamage( 99 );

	// FragTrap	Demon( Hero );
	// Demon.beRepaired( 99 );
	
	return ( 0 );
}
