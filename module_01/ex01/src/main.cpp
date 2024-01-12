/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:17:00 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/11 21:05:43 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

#ifndef		SUCCESS
# define	SUCCESS 0
#endif	/*	SUCCESS	*/

/******************************************************************************/

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;
	Zombie	*group = zombieHorde( 15, DEFAULT_ZOMBIE_NAME );
	
	delete[] group;
	
	return ( SUCCESS );	
};
