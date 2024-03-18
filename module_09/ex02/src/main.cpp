/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:28:02 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/18 12:48:17 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int	main( int argc, char **argv ) {
	try {
		PmergeMe< deque_t >	test( argc, argv );
		PmergeMe< vector_t > foo( argc, argv );
		test.algorithm();
		foo.algorithm();
		displayComparison(test, foo);
	} catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
	return ( EXIT_SUCCESS );
}
