/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:28:19 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/18 17:23:09 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( int argc, char **argv ) {
	( void )argc;
	( void )argv;
	
	ClapTrap	Chamo( "torride" );

	Chamo.attack( "Hermayonnaise" );
	
	return ( EXIT_SUCCESS ); 
}
