/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:17:00 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/12 12:12:15 by ppaquet          ###   ########.fr       */
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
	int	horde_size = 15;
	
	Zombie	*group = zombieHorde( horde_size, DEFAULT_ZOMBIE_NAME );
	
	for (int i = 0; i < horde_size; i++)
	{
		std::cout << "Zombie #" << (i + 1) << "\t->\t";
		group[i].announce();
	}
	delete[] group;
	
	return ( SUCCESS );	
};
