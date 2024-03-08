/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:49:40 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/08 13:23:46 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/BitcoinExchange.hpp"

#ifndef		EXIT_SUCCESS
# define	EXIT_SUCCESS	0
#endif	/*	EXIT_SUCCESS	*/

#define		C_RST	"\033[0m"
#define		C_BLD	"\033[1m"
#define		C_RED	"\033[31m"
#define		C_B_RED	"\033[1;31m"
#define		C_GRN	"\033[32m"
#define		C_B_GRN	"\033[1;32m"
#define		C_ORN	"\033[38;5;208m"
#define		C_B_ORN	"\033[1;38;5;208m"

/******************************************************************************/

bool	check_program_parameter( int ac ) {
	if (ac < 2) {
		std::cerr	<< C_B_RED << "error" << C_RST
					<< ": expected input file." << std::endl;
		return ( false );
	} else if (ac > 2) {
		std::cerr	<< C_B_RED << "error" << C_RST
					<< ": too many arguments: " << ac - 1
					<< " provided: expected 1." << std::endl;
		return ( false );
	}
	return ( true );
}

void	bitcoin_exchange( char *f_name ) {
	BitcoinExchange	btc( f_name );
	btc.display();
	return ;
}

/******************************************************************************/

int	main( int argc, char **argv ) {
	static_cast< void >(argc);
	static_cast< void >(argv);

	if (check_program_parameter( argc ) == true) {
		bitcoin_exchange( argv[ 1 ] );
	}

	return ( EXIT_SUCCESS );
}

// The program takes "input.txt" as an argument
//		Check if we can open the file
//		Be able to getline from this file to upload information
//		Check the format of each line (*** | ***)
//		Check valid date format (****-**-**)
//		Check valid value format (float or int from 0 - 1000)
// 