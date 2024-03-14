/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:28:02 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/14 14:10:14 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int	main( int argc, char **argv ) {

	PmergeMe< vector_t >	test;

	std::pair< int, int > pair;
	std::istringstream	tmp;
	int	number = 0;
	for (int i = 1; i < argc; i++) {
		tmp.str( argv[ i ] );
		tmp >> number;
		if (i % 2 && i < argc - 1) {
			pair.first = number;
		} else {
			pair.second = number;
		}
		if (i % 2 == 0) {
			test.push_back( pair );
			pair = std::make_pair( 0, 0 );
		} else if ( i == argc - 1) {
			test.push_back( pair );
		}
		number = 0;
		tmp.clear();
	}
	return ( EXIT_SUCCESS );
}

/**
 * # -- 1.	Take string input, turn it into a stack of int (deque).
 * # -- 2.	
*/
