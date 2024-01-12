/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:39:22 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/11 21:56:54 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Harl.hpp"

#ifndef		SEPARATOR
# define	SEPARATOR "--------------------------------------------------------"
#endif	/*	SEPARATOR	*/

#ifndef		BOLD
# define	BOLD "\033[1m"
#endif	/*	BOLD	*/

#ifndef		RESET
# define	RESET "\033[0m"
#endif	/*	RESET	*/

/// ---
/// @brief 
///
int	main( int argc, char **argv ){
	Harl	mega_karen;

	( void )argc;
	( void )argv;
	std::cout << SEPARATOR << SEPARATOR << SEPARATOR << std::endl;
	std::cout << BOLD << "COMPLAINING" << RESET << std::endl << "\t";
	mega_karen.complain( "DEBUG" );
	std::cout << "\t";
	mega_karen.complain( "INFO" );
	std::cout << "\t";
	mega_karen.complain( "WARNING" );
	std::cout << "\t";
	mega_karen.complain( "ERROR" );
	
	std::cout << SEPARATOR << SEPARATOR << SEPARATOR << std::endl;
	std::cout << BOLD << "SILENT" << RESET << std::endl;
	mega_karen.complain( "DDEBUG" );
	mega_karen.complain( "" );
	mega_karen.complain( "ERROR " );
	mega_karen.complain( " WARNING " );
	std::cout << SEPARATOR << SEPARATOR << SEPARATOR << std::endl;
	
	return ( 0 );
}
