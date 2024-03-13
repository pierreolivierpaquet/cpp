/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:39:47 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/13 09:50:16 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

bool	check_program_parameter(int ac ) {
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

void	reverse_polish_notation( std::string av ) {
	RPN reverse_polish( av );
	reverse_polish.calculate();
	reverse_polish.displayResult();
	return ;
}

int	main( int argc, char **argv ) {
	
	if (check_program_parameter( argc )) {
		try {
			reverse_polish_notation( argv[ 1 ] );
		} catch( std::exception &e ) {
			std::cout << e.what() << std::endl;
		}
	}
	return ( EXIT_SUCCESS );
}

/* // -----------------------------------------------------------------------///
	* 1. Input line in a stream 
	* 2. Add gradually into a stack
	* 3. Reverse it
	* 4. Calculate using the stack
*/ // -----------------------------------------------------------------------///
