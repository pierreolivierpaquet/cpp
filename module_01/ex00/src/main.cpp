/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:22:26 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/08 15:47:03 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#ifndef EMPTY
# define EMPTY ""
#endif /* EMPTY */

#ifndef SEPARATOR
# define SEPARATOR "-----------------------------------------------------------"
#endif /* SEPARATOR */

std::string	userInput( void ){
	std::string input = EMPTY;
	
	std::cout << "NEW ZOMBIE NAME > " << std::endl;
	getline(std::cin, input);
	if (std::cin.eof()){
		std::cout << std::endl;
	}
	return (input);
};

int	main(int argc, char **argv){
	(void)argc;
	(void)argv;
	Zombie *smurf;
	std::cout << "*** BASIC CONSTRUCTOR ***" << std::endl;
	Zombie basic("ZOMBOY");
	basic.annonce();
	std::cout << SEPARATOR << std::endl;
	std::cout << "*** RANDOMCHUMP FUNCTION ***" << std::endl;
	randomChump(userInput());
	std::cout << SEPARATOR << std::endl;
	std::cout << "*** NEWZOMBIE FUNCTION ***" << std::endl;
	smurf = newZombie(userInput());
	smurf->annonce();
	delete smurf;
	return (0);
};