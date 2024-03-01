/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:55:02 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/01 16:24:50 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int	main( int argc, char **argv ) {
	static_cast<void>( argc );
	static_cast<void>( argv );

	u_int32_t	arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };
	std::vector<u_int32_t> range_test( arr, arr + sizeof(arr) / sizeof(int) );
	int	size = range_test.size();
	Span	test( size );
	std::vector<u_int32_t>::const_iterator it1 = range_test.begin();
	std::vector<u_int32_t>::const_iterator it2 = range_test.end();
	test.addNumber< std::vector<u_int32_t> >( it1, it2 );
	// test.addNumber( 6 );
	// test.addNumber( 6 );
	// test.addNumber( 6 );
	// test.addNumber( 6 );
	// test.addNumber( 7 );
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;

	return ( EXIT_SUCCESS );
}
