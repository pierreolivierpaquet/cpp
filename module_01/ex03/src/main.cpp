/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:47:42 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/09 17:56:56 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

#ifndef SUCCESS
# define SUCCESS 0
#endif /* SUCCESS */

#ifndef SEPARATOR
# define SEPARATOR "-----------------------------------------------------------"
#endif /* SEPARATOR */

#ifndef BOLD
# define BOLD "\033[1m"
#endif /* BOLD */

#ifndef RESET
# define RESET "\033[0m"
#endif /* RESET */

/******************************************************************************/

int	main(int argc, char **argv){
	( void )argc;
	( void )argv;
	
	{
		std::cout << BOLD << "BOB" << RESET << std::endl;
		Weapon club("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << SEPARATOR << std::endl;
	{
		std::cout << BOLD << "JIM" << RESET << std::endl;
		Weapon club("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("other type of club");
		jim.attack();
	}
	return (SUCCESS);
}