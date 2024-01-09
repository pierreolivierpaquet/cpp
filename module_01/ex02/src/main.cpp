/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:23:58 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/09 13:39:16 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef SUCCESS
# define SUCCESS 0
#endif /* SUCCESS */

#ifndef GREET
# define GREET "HI THIS IS BRAIN"
# endif /* GREET */

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
	std::string	brain = GREET;
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;
	
	( void )argc;
	( void )argv;
	std::cout << BOLD << "ADDRESSES" << RESET << std::endl;
	std::cout << "\t\tbrain     : " << &brain << std::endl;
	std::cout << "\t\tstringPTR : " << stringPTR << std::endl;
	std::cout << "\t\tstringREF : " << &stringREF << std::endl;
	std::cout << SEPARATOR << std::endl;
	std::cout << BOLD << "VALUES" << RESET << std::endl;
	std::cout << "\t\tbrain     : " << brain << std::endl;
	std::cout << "\t\tstringPTR : " << *stringPTR << std::endl;
	std::cout << "\t\tstringREF : " << stringREF << std::endl;
	return (SUCCESS);
};