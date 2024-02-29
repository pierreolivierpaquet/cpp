/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:13:59 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/29 13:45:22 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main( int argc, char **argv ) {
	static_cast<void>( argc );
	static_cast<void>( argv );
	
	// std::list<int> test;

	// test.push_back( 10 );
	// test.push_back( 11 );
	// test.push_back( 12 );
	// test.push_back( 13 );
	// test.push_back( 14 );
	// test.push_back( 15 );
	
	// easyfind(test, 42);

	std::vector<int> vec;
	vec.push_back(2);
	vec.push_back(12);
	vec.push_back(22);
	vec.push_back(32);
	vec.push_back(42);
	vec.push_back(52);

	std::vector<int>::const_iterator test;
	try {
		test = easyfind( vec, 23 );
	} catch ( ElementNotFound &ex ) {
		std::cout << ex.what() << std::endl;
		};
	return ( EXIT_SUCCESS );
}
